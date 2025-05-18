//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#include "console/console.h"
#include "console/consoleTypes.h"
#include "core/stringTable.h"
#include "core/color.h"
#include "console/simBase.h"
#include "dgl/gTexManager.h"

//////////////////////////////////////////////////////////////////////////
// TypeString
//////////////////////////////////////////////////////////////////////////
ConsoleType( string, TypeString, sizeof(const char*) )

ConsoleGetType( TypeString )
{
   return *((const char **)(dptr));
}

ConsoleSetType( TypeString )
{
   if(val.isList())
      Con::printf("(TypeString) Cannot save list to a single string.");
   else
      *((const char **) dptr) = StringTable->insert(val.toString());
}

//////////////////////////////////////////////////////////////////////////
// TypeCaseString
//////////////////////////////////////////////////////////////////////////
ConsoleType( caseString, TypeCaseString, sizeof(const char*) )

ConsoleSetType( TypeCaseString )
{
   if(val.isList())
      Con::printf("(TypeCaseString) Cannot set multiple args to a single string.");
   else
      *((const char **) dptr) = StringTable->insert(val.toString(), true);
}

ConsoleGetType( TypeCaseString )
{
   return *((const char **)(dptr));
}

//////////////////////////////////////////////////////////////////////////
// TypeFileName
//////////////////////////////////////////////////////////////////////////
ConsoleType( filename, TypeFilename, sizeof( const char* ) )

ConsoleSetType( TypeFilename )
{
   if(!val.isList())
   {
      char buffer[1024];
      if (Con::expandScriptFilename(buffer, 1024, val.toString()))
         *((const char **) dptr) = StringTable->insert(buffer);
      else
         Con::warnf("(TypeFilename) illegal filename detected: %s", val.getStringU());
   }
   else
      Con::printf("(TypeFilename) Cannot set multiple args to a single filename.");
}

ConsoleGetType( TypeFilename )
{
   return *((const char **)(dptr));
}

//////////////////////////////////////////////////////////////////////////
// TypeBitmapFileName
//////////////////////////////////////////////////////////////////////////
ConsoleType( bitmapFilename, TypeBitmapFilename, sizeof(TextureHandle) )

ConsoleSetType( TypeBitmapFilename )
{
    if (!val.isList())
    {
        char buffer[1024];
        if (Con::expandScriptFilename(buffer, 1024, val.toString())) {
            *((TextureHandle*)dptr) = TextureHandle(buffer, BitmapTexture);
        }
        else
            Con::warnf("(TypeFilename) illegal texture filename detected: %s", val.getStringU());
    }
    else
        Con::printf("(TypeFilename) Cannot set multiple args to a texture filename.");
}

ConsoleGetType( TypeBitmapFilename )
{
    // should be a StringTableEntry.
    return ((TextureHandle*)(dptr))->getName();
}

//////////////////////////////////////////////////////////////////////////
// TypeTextureFileName
//////////////////////////////////////////////////////////////////////////
ConsoleType( textureFilename, TypeTextureFilename, sizeof(TextureHandle) )

ConsoleSetType( TypeTextureFilename )
{
    if (!val.isList())
    {
        char buffer[1024];
        if (Con::expandScriptFilename(buffer, 1024, val.toString())) {
            *((TextureHandle*)dptr) = TextureHandle(buffer, MeshTexture);
        }
        else
            Con::warnf("(TypeFilename) illegal texture filename detected: %s", val.getStringU());
    }
    else
        Con::printf("(TypeFilename) Cannot set multiple args to a texture filename.");
}

ConsoleGetType( TypeTextureFilename )
{
    // should be a StringTableEntry.
    return ((TextureHandle*)(dptr))->getName();
}

//////////////////////////////////////////////////////////////////////////
// TypeS8
//////////////////////////////////////////////////////////////////////////
ConsoleType( char, TypeS8, sizeof(U8) )

ConsoleGetType( TypeS8 )
{
   S64 value = *((U8*)dptr);
   return value;
}

ConsoleSetType( TypeS8 )
{
   if(val.isList())
      Con::printf("(TypeU8) Cannot set list to a single S32.");
   else
      *((U8 *) dptr) = val.getInt();
}

//////////////////////////////////////////////////////////////////////////
// TypeS32
//////////////////////////////////////////////////////////////////////////
ConsoleType( int, TypeS32, sizeof(S32) )

ConsoleGetType( TypeS32 )
{
   S64 value = *((S32*)dptr);
   return value;
}

ConsoleSetType( TypeS32 )
{
   *((S32 *) dptr) = val.getInt();
}

//////////////////////////////////////////////////////////////////////////
// TypeS32Vector
//////////////////////////////////////////////////////////////////////////
ConsoleType( intList, TypeS32Vector, sizeof(Vector<S32>) )

ConsoleGetType( TypeS32Vector )
{
   Vector<S32> *vec = (Vector<S32> *)dptr;
   auto* vl = new ConsoleValueList;
   for (Vector<S32>::iterator itr = vec->begin(); itr != vec->end(); itr++)
       vl->push_back((S64)*itr);
   return vl;
}

ConsoleSetType( TypeS32Vector )
{
   Vector<S32> *vec = (Vector<S32> *)dptr;
   // we assume the vector should be cleared first (not just appending)
   vec->clear();
   if(!val.isList()) // slower compatibility behavior
   {
      const char *values = val.toString();
      const char *endValues = values + dStrlen(values);
      S32 value;
      // advance through the string, pulling off S32's and advancing the pointer
      while (values < endValues && dSscanf(values, "%d", &value) != 0)
      {
         vec->push_back(value);
         const char *nextValues = dStrchr(values, ' ');
         if (nextValues != 0 && nextValues < endValues)
            values = nextValues + 1;
         else
            break;
      }
   }
   else {
      for (S32 i = 0; i < val.getListSizeU(); i++)
         vec->push_back(val.getListValueU(i).getInt());
   }
   // Con::printf("Vector<S32> must be set as { a, b, c, ... } or \"a b c ...\"");
}

//////////////////////////////////////////////////////////////////////////
// TypeF32
//////////////////////////////////////////////////////////////////////////
ConsoleType( float, TypeF32, sizeof(F32) )

ConsoleGetType( TypeF32 )
{
   F64 value = *((F32*)dptr);
   return value;
}
ConsoleSetType( TypeF32 )
{
   *((F32 *) dptr) = val.getNumber();
}

//////////////////////////////////////////////////////////////////////////
// TypeF32Vector
//////////////////////////////////////////////////////////////////////////
ConsoleType( floatList, TypeF32Vector, sizeof(Vector<F32>) )

ConsoleGetType( TypeF32Vector )
{
   Vector<F32> *vec = (Vector<F32> *)dptr;
   auto* vl = new ConsoleValueList;
   for (Vector<F32>::iterator itr = vec->begin(); itr != vec->end(); itr++)
      vl->push_back((F64)*itr);
   return vl;
}

ConsoleSetType( TypeF32Vector )
{
   Vector<F32> *vec = (Vector<F32> *)dptr;
   // we assume the vector should be cleared first (not just appending)
   vec->clear();
   if(!val.isList()) // slower compatibility behavior
   {
      const char *values = val.toString();
      const char *endValues = values + dStrlen(values);
      F32 value;
      // advance through the string, pulling off F32's and advancing the pointer
      while (values < endValues && dSscanf(values, "%g", &value) != 0)
      {
         vec->push_back(value);
         const char *nextValues = dStrchr(values, ' ');
         if (nextValues != 0 && nextValues < endValues)
            values = nextValues + 1;
         else
            break;
      }
   }
   else {
      for (S32 i = 0; i < val.getListSizeU(); i++)
         vec->push_back(val.getListValueU(i).getNumber());
   }
   // Con::printf("Vector<F32> must be set as { a, b, c, ... } or \"a b c ...\"");
}

//////////////////////////////////////////////////////////////////////////
// TypeBool
//////////////////////////////////////////////////////////////////////////
ConsoleType( bool, TypeBool, sizeof(bool) )

ConsoleGetType( TypeBool )
{
   return *((bool *) dptr) ? 1LL : 0LL;
}

ConsoleSetType( TypeBool )
{
   if(val.isList())
      Con::printf("(TypeBool) Cannot set list to a single bool.");
   else
      *((bool *) dptr) = val.getInt();
}


//////////////////////////////////////////////////////////////////////////
// TypeBoolVector
//////////////////////////////////////////////////////////////////////////
ConsoleType( boolList, TypeBoolVector, sizeof(Vector<bool>) )

ConsoleGetType( TypeBoolVector )
{
   Vector<bool> *vec = (Vector<bool>*)dptr;
   auto* vl = new ConsoleValueList;
   for (Vector<bool>::iterator itr = vec->begin(); itr < vec->end(); itr++)
       vl->push_back((S64)*itr);
   return(vl);
}

ConsoleSetType( TypeBoolVector )
{
   Vector<bool> *vec = (Vector<bool>*)dptr;
   // we assume the vector should be cleared first (not just appending)
   vec->clear();
   if (!val.isList()) // slower compatibility behavior
   {
      const char *values = val.toString();
      const char *endValues = values + dStrlen(values);
      S32 value;
      // advance through the string, pulling off bool's and advancing the pointer
      while (values < endValues && dSscanf(values, "%d", &value) != 0)
      {
         vec->push_back(value == 0 ? false : true);
         const char *nextValues = dStrchr(values, ' ');
         if (nextValues != 0 && nextValues < endValues)
            values = nextValues + 1;
         else
            break;
      }
   }
   else {
      for (S32 i = 0; i < val.getListSizeU(); i++)
         vec->push_back(val.getListValueU(i).getInt());
   }
   // Con::printf("Vector<bool> must be set as { a, b, c, ... } or \"a b c ...\"");
}

//////////////////////////////////////////////////////////////////////////
// TypeEnum
//////////////////////////////////////////////////////////////////////////
ConsoleType( enumval, TypeEnum, sizeof(S32) )

ConsoleGetType( TypeEnum )
{
   AssertFatal(tbl, "Null enum table passed to getDataTypeEnum()");
   S32 dptrVal = *(S32*)dptr;
   for (S32 i = 0; i < tbl->size; i++)
      if (dptrVal == tbl->table[i].index)
         return tbl->table[i].label;

   //not found (return convalue null string)
   return "";
}

ConsoleSetType( TypeEnum )
{
   AssertFatal(tbl, "Null enum table passed to setDataTypeEnum()");
   if (val.isList()) return;

   if (val.getType() == ConsoleValue::TypeInt) {
       for (S32 i = 0; i < tbl->size; i++)
           if (tbl->table[i].index == val.getIntU())
               *((S32*)dptr) = val.getIntU();
   }
   else {
       char const* str = val.toString();
       S32 val = 0;
       for (S32 i = 0; i < tbl->size; i++)
       {
          if (! dStricmp(str, tbl->table[i].label))
          {
             val = tbl->table[i].index;
             break;
          }
       }
       *((S32 *) dptr) = val;
   }
}

//////////////////////////////////////////////////////////////////////////
// TypeColorF
//////////////////////////////////////////////////////////////////////////
ConsoleType( ColorF, TypeColorF, sizeof(ColorF) )

ConsoleGetType( TypeColorF )
{
   ColorF * color = (ColorF*)dptr;
   auto* vl = new ConsoleValueList;
   vl->push_back((F64)color->red);
   vl->push_back((F64)color->green);
   vl->push_back((F64)color->blue);
   vl->push_back((F64)color->alpha);
   return vl;
}

ConsoleSetType( TypeColorF )
{
   ColorF *tmpColor = (ColorF *) dptr;
   if(!val.isList()) // compatibility behavior
   {
      tmpColor->set(0, 0, 0, 1);
      F32 r,g,b,a;
      S32 args = dSscanf(val.toString(), "%g %g %g %g", &r, &g, &b, &a);
      tmpColor->red = r;
      tmpColor->green = g;
      tmpColor->blue = b;
      if (args == 4)
         tmpColor->alpha = a;
   }
   else if(val.getListSizeU() == 3)
   {
      tmpColor->red    = val.getListValueU(0).getNumber();
      tmpColor->green  = val.getListValueU(1).getNumber();
      tmpColor->blue   = val.getListValueU(2).getNumber();
      tmpColor->alpha  = 1.f;
   }
   else if(val.getListSizeU() == 4)
   {
      tmpColor->red    = val.getListValueU(0).getNumber();
      tmpColor->green  = val.getListValueU(1).getNumber();
      tmpColor->blue   = val.getListValueU(2).getNumber();
      tmpColor->alpha  = val.getListValueU(3).getNumber();
   }
   else
      Con::printf("ColorF must be set as { r, g, b [,a] }");
}

//////////////////////////////////////////////////////////////////////////
// TypeColorI
//////////////////////////////////////////////////////////////////////////
ConsoleType( ColorI, TypeColorI, sizeof(ColorI) )

ConsoleGetType( TypeColorI )
{
   ColorI* color = (ColorI*)dptr;
   auto* vl = new ConsoleValueList;
   vl->push_back((S64)color->red);
   vl->push_back((S64)color->green);
   vl->push_back((S64)color->blue);
   vl->push_back((S64)color->alpha);
   return vl;
}

ConsoleSetType( TypeColorI )
{
   ColorI *tmpColor = (ColorI *) dptr;
   if(!val.isList()) // compatibility behavior
   {
      tmpColor->set(0, 0, 0, 255);
      S32 r,g,b,a;
      S32 args = dSscanf(val.toString(), "%d %d %d %d", &r, &g, &b, &a);
      tmpColor->red = r;
      tmpColor->green = g;
      tmpColor->blue = b;
      if (args == 4)
         tmpColor->alpha = a;
   }
   else if(val.getListSizeU() == 3)
   {
      tmpColor->red    = val.getListValueU(0).getInt();
      tmpColor->green  = val.getListValueU(1).getInt();
      tmpColor->blue   = val.getListValueU(2).getInt();
      tmpColor->alpha  = 255;
   }
   else if(val.getListSizeU() == 4)
   {
      tmpColor->red    = val.getListValueU(0).getInt();
      tmpColor->green  = val.getListValueU(1).getInt();
      tmpColor->blue   = val.getListValueU(2).getInt();
      tmpColor->alpha  = val.getListValueU(3).getInt();
   }
   else
      Con::printf("ColorI must be set as { r, g, b [,a] }");
}

//////////////////////////////////////////////////////////////////////////
// TypeSimObjectPtr
//////////////////////////////////////////////////////////////////////////
ConsoleType( SimObjectPtr, TypeSimObjectPtr, sizeof(SimObject*) )

ConsoleSetType( TypeSimObjectPtr )
{
   if(!val.isList())
   {
      SimObject **obj = (SimObject **)dptr;
      *obj = Sim::findObject(val.getInt());
   }
   else
      Con::printf("(TypeSimObjectPtr) Cannot set list to a single object id.");
}

ConsoleGetType( TypeSimObjectPtr )
{
   SimObject **obj = (SimObject**)dptr;
   return *obj ? (*obj)->getName() : "";
}
