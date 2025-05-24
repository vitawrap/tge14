//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#include "platform/platform.h"
#include "console/console.h"
#include "platform/event.h"

#include "console/ast.h"
#include "core/tAlgorithm.h"
#include "core/resManager.h"

#include "core/findMatch.h"
#include "console/consoleInternal.h"
#include "core/fileStream.h"
#include "console/compiler.h"

#include "console/simBase.h"

namespace Compiler
{

   F64 consoleStringToNumber(const char *str, StringTableEntry file, U32 line)
   {
      F64 val = dAtof(str);
      if(val != 0)
         return val;
      else if(!dStricmp(str, "true"))
         return 1;
      else if(!dStricmp(str, "false"))
         return 0;
      else if(file)
      {
         Con::warnf(ConsoleLogEntry::General, "%s (%d): string always evaluates to 0.", file, line);
         return 0;
      }
      return 0;
   }

   bool consoleStringIsNumber(const char* str) {
       if (!str || !str[0]) return false;
       char* pEnd;
       (void) dStrtod(str, &pEnd);
       return (*pEnd == 0) || (pEnd[dStrspn(pEnd, " \t")] == 0);
   }

   bool consoleStringMatchesConstant(const char* str) {
       return !dStricmp(str, "true") || !dStricmp(str, "false");
   }

   //------------------------------------------------------------

   CompilerStringTable *gCurrentStringTable, gGlobalStringTable, gFunctionStringTable;
   DataChunker          gConsoleAllocator;
   CompilerIdentTable   gIdentTable;
   CodeBlock           *gCurBreakBlock;

   //------------------------------------------------------------


   CodeBlock *getBreakCodeBlock()         { return gCurBreakBlock; }
   void setBreakCodeBlock(CodeBlock *cb)  { gCurBreakBlock = cb;   }

   //------------------------------------------------------------

   U64 evalSTEtoU64(StringTableEntry ste, U64)
   {
      return *((U64 *) &ste);
   }

   U64 compileSTEtoU64(StringTableEntry ste, U64 ip)
   {
      if(ste)
         getIdentTable().add(ste, ip);
      return 0;
   }

   U64 (*STEtoU64)(StringTableEntry ste, U64 ip) = evalSTEtoU64;

   //------------------------------------------------------------

   bool gSyntaxError = false;

   //------------------------------------------------------------

   CompilerStringTable *getCurrentStringTable()  { return gCurrentStringTable;  }
   CompilerStringTable &getGlobalStringTable()   { return gGlobalStringTable;   }
   CompilerStringTable &getFunctionStringTable() { return gFunctionStringTable; }

   void setCurrentStringTable (CompilerStringTable* cst) { gCurrentStringTable  = cst; }

   CompilerIdentTable &getIdentTable() { return gIdentTable; }

   void precompileIdent(StringTableEntry ident)
   {
      if(ident)
         gGlobalStringTable.add(ident);
   }

   void resetTables()
   {
      setCurrentStringTable(&gGlobalStringTable);
      getGlobalStringTable().reset();
      getFunctionStringTable().reset();
      getIdentTable().reset();
   }

   void *consoleAlloc(U32 size) { return gConsoleAllocator.alloc(size);  }
   void consoleAllocReset()     { gConsoleAllocator.freeBlocks(); }

}

//-------------------------------------------------------------------------

using namespace Compiler;

//-------------------------------------------------------------------------


U32 CompilerStringTable::add(const char *str, bool caseSens, bool tag)
{
   // Is it already in?
   Entry **walk;
   for(walk = &list; *walk; walk = &((*walk)->next))
   {
      if((*walk)->tag != tag)
         continue;

      if(caseSens)
      {
         if(!dStrcmp((*walk)->string, str))
            return (*walk)->start;
      }
      else
      {
         if(!dStricmp((*walk)->string, str))
            return (*walk)->start;
      }
   }

   // Write it out.
   Entry *newStr = (Entry *) consoleAlloc(sizeof(Entry));
   *walk = newStr;
   newStr->next = NULL;
   newStr->start = totalLen;
   U32 len = dStrlen(str) + 1;
   if(tag && len < 7) // alloc space for the numeric tag 1 for tag, 5 for # and 1 for nul
      len = 7;
   totalLen += len;
   newStr->string = (char *) consoleAlloc(len);
   newStr->len = len;
   newStr->tag = tag;
   dStrcpy(newStr->string, str);
   return newStr->start;
}

U32 CompilerStringTable::addIntString(U32 value)
{
   dSprintf(buf, sizeof(buf), "%d", value);
   return add(buf);
}

U32 CompilerStringTable::addFloatString(F64 value)
{
   dSprintf(buf, sizeof(buf), "%g", value);
   return add(buf);
}
void CompilerStringTable::reset()
{
   list = NULL;
   totalLen = 0;
}
char *CompilerStringTable::build()
{
   char *ret = new char[totalLen];
   for(Entry *walk = list; walk; walk = walk->next)
      dStrcpy(ret + walk->start, walk->string);
   return ret;
}

void CompilerStringTable::write(Stream &st)
{
   st.write(totalLen);
   for(Entry *walk = list; walk; walk = walk->next)
      st.write(walk->len, walk->string);
}

//------------------------------------------------------------

void CompilerIdentTable::reset()
{
   list = NULL;
}

void CompilerIdentTable::add(StringTableEntry ste, U32 ip)
{
   U32 index = gGlobalStringTable.add(ste, false);
   Entry *newEntry = (Entry *) consoleAlloc(sizeof(Entry));
   newEntry->offset = index;
   newEntry->ip = ip;
   for(Entry *walk = list; walk; walk = walk->next)
   {
      if(walk->offset == index)
      {
         newEntry->nextIdent = walk->nextIdent;
         walk->nextIdent = newEntry;
         return;
      }
   }
   newEntry->next = list;
   list = newEntry;
   newEntry->nextIdent = NULL;
}

void CompilerIdentTable::write(Stream &st)
{
   U32 count = 0;
   Entry * walk;
   for(walk = list; walk; walk = walk->next)
      count++;
   st.write(count);
   for(walk = list; walk; walk = walk->next)
   {
      U32 ec = 0;
      Entry * el;
      for(el = walk; el; el = el->nextIdent)
         ec++;
      st.write(walk->offset);
      st.write(ec);
      for(el = walk; el; el = el->nextIdent)
         st.write(el->ip);
   }
}

int QSORT_CALLBACK alphabeticalSort(const void* a, const void* b)
{
    return dStricmp((const char*) a, (const char*) b);
}
