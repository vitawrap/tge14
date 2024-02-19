//-----------------------------------------------------------------------------
// Torque Game Engine 
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#ifndef _PLATFORMFONT_H_
#include "platform/platformFont.h"
#include "platform/platform.h"
#endif

#ifndef _X86UNIXFONT_H_
#define _X86UNIXFONT_H_
// Needed by createFont
#include <ft2build.h>
#include <freetype/freetype.h>

class x86UNIXFont : public PlatformFont
{
	private:
		int baseline;
		int height;
		StringTableEntry  mFontName;
		int	mFontSize;
	public:
		x86UNIXFont();
		virtual ~x86UNIXFont();
    
    	// PlatformFont virtual methods
		virtual bool isValidChar(const UTF16 ch) const;
		virtual bool isValidChar(const UTF8 *str) const;

		inline U32 getFontHeight() const
		{
			return height;
		}
		
		inline U32 getFontBaseLine() const
		{
			return baseline;
		}

		virtual PlatformFont::CharInfo &getCharInfo(const UTF16 ch) const;
		virtual PlatformFont::CharInfo &getCharInfo(const UTF8 *str) const;

		virtual bool create(const char *name, U32 size, U32 charset = TGE_ANSI_CHARSET);
};

#endif
