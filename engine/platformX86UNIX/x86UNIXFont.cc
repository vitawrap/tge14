//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#include "dgl/gFont.h"
#include "dgl/gBitmap.h"
#include "math/mRect.h"
#include "console/console.h"
#include "core/unicode.h"
#include "platformX86UNIX/platformX86UNIX.h"
#include "platformX86UNIX/x86UNIXFont.h"

// Needed by createFont
// https://stackoverflow.com/questions/62374506/how-do-i-align-glyphs-along-the-baseline-with-freetype
#include <freetype/ftmodapi.h>
#include <fontconfig/fontconfig.h>
#include <fontconfig/fcfreetype.h>

// Needed for getenv in createFont
#include <stdlib.h>

static FT_MemoryRec_ memRec = {
  NULL,
  [](FT_Memory, long size) -> void* { return dMalloc(size); },
  [](FT_Memory, void* ptr) -> void { return dFree(ptr); },
  [](FT_Memory, long csize, long nsize, void* block) -> void* { return dRealloc(block, nsize); }
};
static FT_Library gFT = NULL;
static FcConfig* gFc = NULL;

S32 mapSize(char const*fontname, S32 size)
{
  // warning!  hacking ahead
  S32 newSize = size;
  char* fname = const_cast<char*>(fontname);

  // if the size is >= 12, do a size - 2 adjustment
  // (except for courier.)
  // fonts seem to be too big otherwise, but this might be
  // system/font specific
  if (newSize >= 12 && !stristr(fname, "courier"))
    newSize = newSize - 2;

  // adobe helvetica and courier look like crap at 22
  // (probably scaled bitmap problem)
  if (newSize == 22 &&
      (stristr(fname, "helvetica") == 0 ||
       stristr(fname, "courier") == 0))
    newSize = 24;

  return newSize;
}

// We use fontconfig to abstract away the path differences between linux distros...
FT_Face findFont(char const* fontname, char *foundFontName, int bufSize)
{
  // configure the search pattern
  FcPattern* pat = FcNameParse((const FcChar8*)fontname);
  FcConfigSubstitute(gFc, pat, FcMatchPattern);
  FcDefaultSubstitute(pat);

  // find the font
  FT_Face face = NULL;
  FcResult res;
  FcPattern* font = FcFontMatch(gFc, pat, &res);
  if (font)
  {
    FcChar8* file = NULL;
    if (FcPatternGetString(font, FC_FILE, 0, &file) == FcResultMatch)
    {
      dStrncpy(foundFontName, (const char*)file, bufSize);
      FT_New_Face(gFT, foundFontName, 0, &face);
    }
    FcPatternDestroy(font);
  }
  FcPatternDestroy(pat);
  return face;
}

FT_Face loadFont(const char *name, S32& size, char *pickedFontName, int pickedFontNameSize)
{
  // This is a fancier strategy than the old Xft system.
  // Basically findFont goes into fontconfig to get a best match for a fontface
  // given a name. If a match is made (should always happen) pickedFontName is written to here.
  // This also means we're no longer potentially failing on a Microsoft font and calling for
  // a completely random replacement (which may not even exist either).
  char const* fontname = name;

  int newSize = mapSize(fontname, size);
  FT_Face fontInfo = findFont(fontname, pickedFontName, pickedFontNameSize);
  FT_Error sizeRet;
  if (fontInfo)
    sizeRet = FT_Set_Pixel_Sizes(fontInfo, 0, newSize);

  size = newSize;
  return fontInfo;
}

bool registerFontFile(char const* fname)
{
  // TODO: Register the font in FcConfig
	return false;
}

GOldFont *createFont(const char *name, size_t size, U32 charset)
{
  // load the font
  const int pickedFontNameSize = 512;
  char pickedFontName[pickedFontNameSize];

  S32 fsize = size;
  FT_Face face = loadFont(name, fsize, pickedFontName, pickedFontNameSize);
  if (!face)
    AssertFatal(false, "createFont: cannot load font");

  Con::printf("CreateFont: request for %s %d, using %s", name, size, pickedFontName);

  // We need to draw white glyphs on a black background.
  FT_GlyphSlot slot = face->glyph;

  // The font.
  GOldFont *retFont = new GOldFont;
  U8 scratchPad[65536] {0};
  int x, y;

  // insert bitmaps into the font for each character
  for (U16 i = 32; i < 256; i++)
  {
    U32 glyph = FT_Get_Char_Index(face, i);
    if (FT_Load_Glyph(face, glyph, FT_LOAD_RENDER) != FT_Err_Ok)
    {
      retFont->insertBitmap(i, scratchPad, 0, 0, 0, 0, 0, face->max_advance_width);
      continue;
    }

    // Get the glyph and its extents.
    FT_Glyph_Metrics extent = slot->metrics;
    FT_Bitmap bitmap = slot->bitmap;

    // As it turns out, Freetype already creates a grayscale U8 alpha bitmap.
    retFont->insertBitmap(i, // index
                          bitmap.buffer, // src
                          bitmap.pitch, // stride
                          bitmap.width, // width
                          face->height, // height
                          0, // xOrigin
                          face->ascender, // yOrigin
                          extent.width); // xIncrement
  }

  retFont->pack(face->height, face->ascender);
  FT_Done_Face(face);
  return retFont;
}

// XA: New class for the unix unicode font
PlatformFont *createPlatformFont(const char *name, U32 size, U32 charset /* = TGE_ANSI_CHARSET */)
{
  PlatformFont *retFont = new x86UNIXFont;

  if (retFont->create(name, size, charset))
    return retFont;

  delete retFont;
  return NULL;
}

x86UNIXFont::x86UNIXFont()
{
  if (! gFT)
  {
    gFc = FcInitLoadConfigAndFonts();
    FT_New_Library(&memRec, &gFT);
    FT_Add_Default_Modules(gFT);
  }
  FT_Reference_Library(gFT);
  mFontSize = 12;
}

x86UNIXFont::~x86UNIXFont()
{
  FT_Done_Library(gFT);
}

bool x86UNIXFont::create(const char *name, U32 size, U32 charset)
{
  const int pickedFontNameSize = 512;
  char pickedFontName[pickedFontNameSize];

  mFontSize = size;
  FT_Face face = loadFont(name, mFontSize, pickedFontName, pickedFontNameSize);

  if (!face)
  {
    Con::errorf("Error: Could not load font -%s-", name);
    return false;
  }

  // store some info about the font
  float fontSize = mFontSize * face->units_per_EM / 72.f;
  float ascenderPx = ((face->ascender >> 5) * fontSize) / face->units_per_EM;
  float descenderPx = ((face->descender >> 5) * fontSize) / face->units_per_EM;

  baseline = ascenderPx;
  height = ascenderPx - descenderPx;

  mFontName = StringTable->insert(pickedFontName);
  FT_Done_Face(face);

  return true;
}

bool x86UNIXFont::isValidChar(const UTF16 str) const
{
  // 0x20  == 32
  // 0x100 == 256
  if (str < 0x20 || str > 0x100)
    return false;

  return true;
}

bool x86UNIXFont::isValidChar(const UTF8 *str) const
{
  return isValidChar(oneUTF32toUTF16(oneUTF8toUTF32(str, NULL)));
}

PlatformFont::CharInfo &x86UNIXFont::getCharInfo(const UTF16 ch) const
{
  static PlatformFont::CharInfo c;
  dMemset(&c, 0, sizeof(c));

  c.bitmapIndex = 0;
  c.xOffset = 0;
  c.yOffset = 0;

  // By now mFontFace should point to a path that we retrieved from Fontconfig.
  FT_Face face = NULL;
  FT_Error ret = FT_New_Face(gFT, mFontName, 0, &face);
  if (ret != FT_Err_Ok) AssertFatal(false, "createFont: cannot load font");

  ret = FT_Set_Pixel_Sizes(face, 0, mFontSize);
  if (ret != FT_Err_Ok) AssertFatal(false, "createFont: cannot load size");

  U32 glyph = FT_Get_Char_Index(face, ch);
  ret = FT_Load_Glyph(face, glyph, FT_LOAD_DEFAULT);
  if (ret != FT_Err_Ok) AssertFatal(false, "createFont: cannot load glyph");

  ret = FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL);
  if (ret != FT_Err_Ok) AssertFatal(false, "createFont: cannot render glyph");

  // Another round of getting a glyph grayscale bitmap
  FT_Glyph_Metrics metrics = face->glyph->metrics;
  FT_GlyphSlot slot = face->glyph;
  FT_Bitmap bitmap = slot->bitmap;

  c.height = (metrics.height + 63) >> 6;
  c.xOrigin = metrics.horiBearingX >> 6;
  c.yOrigin = metrics.horiBearingY >> 6;
  c.xIncrement = (metrics.horiAdvance + 63) >> 6;
  c.width = (metrics.width + 63) >> 6;

  // kick out early if the character is undrawable
  if (c.width == 0 || c.height == 0)
    return c;

  // allocate a greyscale bitmap and clear it.
  int bitmapDataSize = bitmap.rows * bitmap.pitch;
  c.bitmapData = new U8[bitmapDataSize];
  dMemset(c.bitmapData, 0, bitmapDataSize);

  int x, y;
  // grab each pixel and store it in the scratchPad
  for (y = 0; y < bitmap.rows; y++)
  {
    for (x = 0; x < bitmap.width; x++)
      c.bitmapData[y * c.width + x] = static_cast<U8>(bitmap.buffer[y * bitmap.width + x]);
  }

  FT_Done_Face(face);
  return c;
}

PlatformFont::CharInfo &x86UNIXFont::getCharInfo(const UTF8 *str) const
{
  return getCharInfo(oneUTF32toUTF16(oneUTF8toUTF32(str, NULL)));
}
