//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#include "platform/platform.h"
#include "console/console.h"
#include "console/consoleInternal.h"
#include "console/ast.h"
#include "core/resManager.h"
#include "core/fileStream.h"
#include "console/compiler.h"
#include "platform/event.h"
#include "platform/gameInterface.h"
#include "platform/platformInput.h"

// This is a temporary hack to get tools using the library to
// link in this module which contains no other references.
bool LinkConsoleFunctions = false;

// Buffer for expanding script filenames.
static char scriptFilenameBuffer[1024];

//----------------------------------------------------------------

ConsoleFunction(expandFilename, const char*, 2, 2, "(string filename)")
{
   argc;
   char expandBuffer[1024];
   Con::expandScriptFilename(expandBuffer, 1024, argv[1].toString());
   return expandBuffer;
}

ConsoleFunctionGroupBegin(StringFunctions, "General string manipulation functions.");

ConsoleFunction(strcmp, S32, 3, 3, "(string one, string two)"
                "Case sensitive string compare.")
{
   argc;
   return argv[1].compare(argv[2], true);
}

ConsoleFunction(stricmp, S32, 3, 3, "(string one, string two)"
                "Case insensitive string compare.")
{
   argc;
   return argv[1].compare(argv[2], false);
}

ConsoleFunction(strlen, S32, 2, 2, "(string str)"
               "Calculate the length of a string in characters.")
{
   argc;
   return argv[1].getStrlen();
}

ConsoleFunction(strstr, S32 , 3, 3, "(string one, string two) "
                "Returns the start of the sub string two in one or"
                " -1 if not found.")
{
   argc;
   // returns the start of the sub string argv[2] in argv[1]
   // or -1 if not found.
   char const* a = argv[1].toString();
   char const* b = argv[2].toString();

   const char *retpos = dStrstr(a, b);
   if(!retpos)
      return -1;
   return retpos - a;
}

ConsoleFunction(strpos, S32, 3, 4, "(string hay, string needle, int offset=0) "
                "Find needle in hay, starting offset bytes in.")
{
   S32 ret = -1;
   S32 start = 0;
   if(argc == 4)
      start = argv[3].getInt();
   U32 sublen = argv[2].getStrlen();
   U32 strlen = argv[1].getStrlen();
   if(start < 0)
      return -1;
   if(sublen + start > strlen)
      return -1;
   char const* hay    = argv[1].getStringU();
   char const* needle = argv[2].getStringU();
   for(; start + sublen <= strlen; start++)
      if(!dStrncmp(hay + start, needle, sublen))
         return start;
   return -1;
}

ConsoleFunction(ltrim, const char *,2,2,"(string value)")
{
   argc;
   const char *ret = argv[1].toString();
   while(*ret == ' ' || *ret == '\n' || *ret == '\t')
      ret++;
   return ret;
}

ConsoleFunction(rtrim, const char *,2,2,"(string value)")
{
   argc;
   S32 firstWhitespace = 0;
   S32 pos = 0;
   const char *str = argv[1].toString();
   while(str[pos])
   {
      if(str[pos] != ' ' && str[pos] != '\n' && str[pos] != '\t')
         firstWhitespace = pos + 1;
      pos++;
   }
   ConsoleValue ret;
   ret.concatStringU(str, firstWhitespace);
   return ret;
}

ConsoleFunction(trim, const char *,2,2,"(string)")
{
   argc;
   const char *ptr = argv[1].toString();
   while(*ptr == ' ' || *ptr == '\n' || *ptr == '\t')
      ptr++;
   S32 firstWhitespace = 0;
   S32 pos = 0;
   const char *str = ptr;
   while(str[pos])
   {
      if(str[pos] != ' ' && str[pos] != '\n' && str[pos] != '\t')
         firstWhitespace = pos + 1;
      pos++;
   }
   ConsoleValue ret;
   ret.concatStringU(ptr, firstWhitespace);
   return ret;
}

ConsoleFunction(stripChars, const char*, 3, 3, "(string value, string chars) "
                "Remove all the characters in chars from value." )
{
   argc;
   char const* value = argv[1].toString();
   char const* set = argv[2].toString();
   ReturnBuffer ret(dStrlen(value) + 1);
   dStrcpy( *ret, value );
   U32 pos = dStrcspn( *ret, set );
   while ( pos < dStrlen( *ret ) )
   {
      dStrcpy( *ret + pos, *ret + pos + 1 );
      pos = dStrcspn( *ret, set );
   }
   return( ret );
}

ConsoleFunction(stripColorCodes, const char*, 2,2,  "(stringtoStrip) - "
                "remove TorqueML color codes from the string.")
{
   char const* str = argv[1].toString();
   ReturnBuffer ret( dStrlen( str ) + 1 );
   dStrcpy(*ret, str);
   Con::stripColorChars(*ret);
   return ret;
}

ConsoleFunction(strlwr,const char *,2,2,"(string) "
                "Convert string to lower case.")
{
   argc;
   char const* str = argv[1].toString();
   ReturnBuffer ret(dStrlen(str) + 1);
   dStrcpy(*ret, str);
   return dStrlwr(*ret);
}

ConsoleFunction(strupr,const char *,2,2,"(string) "
                "Convert string to upper case.")
{
    argc;
    char const* str = argv[1].toString();
    ReturnBuffer ret(dStrlen(str) + 1);
    dStrcpy(*ret, str);
    return dStrupr(*ret);
}

ConsoleFunction(strchr,const char *,3,3,"(string,char)")
{
   argc;
   const char *ret = dStrchr(argv[1].toString(), argv[2].toString()[0]);
   return ret ? ret : "";
}

ConsoleFunction(startsWith,bool,3,3,"(string,sequence)")
{
   argc;
   return dStrnicmp(argv[1].toString(), argv[2].toString(), argv[2].getStrlen()) == 0;
}

ConsoleFunction(strreplace, const char *, 4, 4, "(string source, string from, string to)")
{
   char const* source = argv[1].toString();
   char const* from = argv[2].toString();
   char const* to = argv[3].toString();

   argc;
   S32 fromLen = dStrlen(from);
   if(!fromLen)
      return source;

   S32 toLen = dStrlen(to);
   S32 count = 0;
   const char *scan = source;
   while(scan)
   {
      scan = dStrstr(scan, from);
      if(scan)
      {
         scan += fromLen;
         count++;
      }
   }
   ReturnBuffer ret(dStrlen(source) + 1 + (toLen - fromLen) * count);
   U32 scanp = 0;
   U32 dstp = 0;
   for(;;)
   {
      const char *scan = dStrstr(source + scanp, from);
      if(!scan)
      {
         dStrcpy(*ret + dstp, source + scanp);
         return ret;
      }
      U32 len = scan - (source + scanp);
      dStrncpy(*ret + dstp, source + scanp, len);
      dstp += len;
      dStrcpy(*ret + dstp, to);
      dstp += toLen;
      scanp += len + fromLen;
   }
   return ret;
}

ConsoleFunction(getSubStr, const char *, 4, 4, "getSubStr(string str, int start, int numChars) "
                "Returns the substring of str, starting at start, and continuing "
                "to either the end of the string, or numChars characters, whichever "
                "comes first.")
{
   argc;
   // Returns the substring of argv[1], starting at argv[2], and continuing
   //  to either the end of the string, or argv[3] characters, whichever
   //  comes first.
   //
   S32 startPos   = argv[2].getInt();
   S32 desiredLen = argv[3].getInt();
   if (startPos < 0 || desiredLen < 0) {
      Con::errorf(ConsoleLogEntry::Script, "getSubStr(...): error, starting position and desired length must be >= 0: (%d, %d)", startPos, desiredLen);
      return "";
   }

   S32 baseLen = argv[1].getStrlen();
   if (baseLen < startPos)
      return "";

   U32 actualLen = desiredLen;
   if (startPos + desiredLen > baseLen)
      actualLen = baseLen - startPos;

   ConsoleValue ret;
   ret.concatStringU(argv[1].toString() + startPos, actualLen);
   return ret;
}

// Used?
ConsoleFunction( stripTrailingSpaces, const char*, 2, 2, "stripTrailingSpaces( string )" )
{
   argc;
   S32 temp = S32(argv[1].getStrlen());
   if ( temp )
   {
      char const* string = argv[1].getStringU();
      while ( ( string[temp - 1] == ' ' || string[temp - 1] == '_' ) && temp >= 1 )
         temp--;

      if ( temp )
      {
         ConsoleValue ret;
         ret.concatStringU( string, temp );
         return( ret );
      }
   }

   return( "" );	
}

ConsoleFunctionGroupEnd(StringFunctions);

//--------------------------------------

struct UnitPair {
    char const* start;
    U32 length;
};

static UnitPair getUnit(const char *string, U32 index, const char *set)
{
   U32 sz;
   while(index--)
   {
      if(!*string)
          return { NULL, 0 };
      sz = dStrcspn(string, set);
      if (string[sz] == 0)
          return { NULL, 0 };
      string += (sz + 1);
   }
   sz = dStrcspn(string, set);
   if (sz == 0)
       return { NULL, 0 };
   return { string, sz };
}

static UnitPair getUnits(const char *string, S32 startIndex, S32 endIndex, const char *set)
{
   S32 sz;
   S32 index = startIndex;
   while(index--)
   {
      if(!*string)
         return { NULL, 0 };
      sz = dStrcspn(string, set);
      if (string[sz] == 0)
         return { NULL, 0 };
      string += (sz + 1);
   }
   const char *startString = string;
   while(startIndex <= endIndex--)
   {
      sz = dStrcspn(string, set);
      string += sz;
      if (*string == 0)
         break;
      string++;
   }
   if(!*string)
      string++;
   U32 totalSize = (U32(string - startString));
   return { startString, totalSize - 1 };
}

static U32 getUnitCount(const char *string, const char *set)
{
   U32 count = 0;
   U8 last = 0;
   while(*string)
   {
      last = *string++;

      for(U32 i =0; set[i]; i++)
      {
         if(last == set[i])
         {
            count++;
            last = 0;
            break;
         }
      }
   }
   if(last)
      count++;
   return count;
}


static ConsoleValue setUnit(const char *string, U32 index, const char *replace, const char *set)
{
   U32 sz;
   const char *start = string;
   ConsoleValue ret;
   U32 padCount = 0;

   while(index--)
   {
      sz = dStrcspn(string, set);
      if(string[sz] == 0)
      {
         string += sz;
         padCount = index + 1;
         break;
      }
      else
         string += (sz + 1);
   }
   // copy first chunk
   sz = string-start;
   ret.concatStringU(start, sz);
   for(U32 i = 0; i < padCount; i++)
      ret.concatStringU(set, 1);

   // replace this unit
   ret.concatStringU(replace, dStrlen(replace));

   // copy remaining chunks
   sz = dStrcspn(string, set);         // skip chunk we're replacing
   if(!sz && !string[sz])
      return ret;

   string += sz;
   ret.concatStringU(string, dStrlen(string));
   return ret;
}

// FIXME: Test this function thoroughly (trailing delimiter logic is fragile now.)
static ConsoleValue removeUnit(const char *string, U32 index, const char *set)
{
   U32 sz;
   const char *start = string;
   ConsoleValue ret;

   while(index--)
   {
      sz = dStrcspn(string, set); // length until char in set
      // if there was no unit out there... return the original string
      if(string[sz] == 0)
         return start;
      else
         string += (sz + 1);
   }
   // copy first chunk
   sz = string-start;
   ret.concatStringU(start, sz);

   // copy remaining chunks
   S32 remn = dStrcspn(string, set);   // skip chunk we're removing

   if(string[remn] == 0) {             // if that was the last...
      // then kill any trailing delimiter
      ret.concatStringU(string, sz + remn - (string != start));
      return ret;                      // and bail
   }

   string += remn + 1; // skip the extra field delimiter
   ret.concatStringU(string, dStrlen(string));
   return ret;
}


//--------------------------------------
ConsoleFunctionGroupBegin( FieldManipulators, "Functions to manipulate data returned in the form of \"x y z\".");

ConsoleFunction(getWord, const char *, 3, 3, "(string text, int index)")
{
   argc;
   auto pair = getUnit(argv[1].toString(), argv[2].getInt(), " \t\n");
   ConsoleValue ret;
   if (pair.start)
       ret.concatStringU(pair.start, pair.length);
   return ret;
}

ConsoleFunction(getWords, const char *, 3, 4, "(string text, int index, int endIndex=INF)")
{
   U32 endIndex;
   if(argc==3)
      endIndex = 1000000;
   else
      endIndex = argv[3].getInt();
   auto pair = getUnits(argv[1].toString(), argv[2].getInt(), endIndex, " \t\n");
   ConsoleValue ret;
   if (pair.start)
       ret.concatStringU(pair.start, pair.length);
   return ret;
}

ConsoleFunction(setWord, const char *, 4, 4, "newText = setWord(text, index, replace)")
{
   argc;
   return setUnit(argv[1].toString(), argv[2].getInt(), argv[3].toString(), " \t\n");
}

ConsoleFunction(removeWord, const char *, 3, 3, "newText = removeWord(text, index)")
{
   argc;
   return removeUnit(argv[1].toString(), argv[2].getInt(), " \t\n");
}

ConsoleFunction(getWordCount, S32, 2, 2, "getWordCount(text)")
{
   argc;
   return (S64) getUnitCount(argv[1].toString(), " \t\n");
}

//--------------------------------------
ConsoleFunction(getField, const char *, 3, 3, "getField(text, index)")
{
   argc;
   auto pair = getUnit(argv[1].toString(), argv[2].getInt(), "\t\n");
   ConsoleValue ret;
   if (pair.start)
       ret.concatStringU(pair.start, pair.length);
   return ret;
}

ConsoleFunction(getFields, const char *, 3, 4, "getFields(text, index [,endIndex])")
{
   U32 endIndex;
   if(argc==3)
      endIndex = 1000000;
   else
      endIndex = argv[3].getInt();
   auto pair = getUnits(argv[1].toString(), argv[2].getInt(), endIndex, "\t\n");
   ConsoleValue ret;
   if (pair.start)
       ret.concatStringU(pair.start, pair.length);
   return ret;
}

ConsoleFunction(setField, const char *, 4, 4, "newText = setField(text, index, replace)")
{
   argc;
   return setUnit(argv[1].toString(), argv[2].getInt(), argv[3].toString(), "\t\n");
}

ConsoleFunction(removeField, const char *, 3, 3, "newText = removeField(text, index)" )
{
   argc;
   return removeUnit(argv[1].toString(), argv[2].getInt(), "\t\n");
}

ConsoleFunction(getFieldCount, S32, 2, 2, "getFieldCount(text)")
{
   argc;
   return (S64) getUnitCount(argv[1].toString(), "\t\n");
}

//--------------------------------------
ConsoleFunction(getRecord, const char *, 3, 3, "getRecord(text, index)")
{
   argc;
   auto pair = getUnit(argv[1].toString(), argv[2].getInt(), "\n");
   ConsoleValue ret;
   if (pair.start)
       ret.concatStringU(pair.start, pair.length);
   return ret;
}

ConsoleFunction(getRecords, const char *, 3, 4, "getRecords(text, index [,endIndex])")
{
   U32 endIndex;
   if(argc==3)
      endIndex = 1000000;
   else
      endIndex = argv[3].getInt();
   auto pair = getUnits(argv[1].toString(), argv[2].getInt(), endIndex, "\n");
   ConsoleValue ret;
   if (pair.start)
       ret.concatStringU(pair.start, pair.length);
   return ret;
}

ConsoleFunction(setRecord, const char *, 4, 4, "newText = setRecord(text, index, replace)")
{
   argc;
   return setUnit(argv[1].toString(), argv[2].getInt(), argv[3].toString(), "\n");
}

ConsoleFunction(removeRecord, const char *, 3, 3, "newText = removeRecord(text, index)" )
{
   argc;
   return removeUnit(argv[1].toString(), argv[2].getInt(), "\n");
}

ConsoleFunction(getRecordCount, S32, 2, 2, "getRecordCount(text)")
{
   argc;
   return (S64) getUnitCount(argv[1].toString(), "\n");
}
//--------------------------------------
ConsoleFunction(firstWord, const char *, 2, 2, "firstWord(text)")
{
   argc;
   const char* string = argv[1].toString();
   const char* word = dStrchr(string, ' ');
   U32 len;
   if(word == NULL)
      len = argv[1].getStrlen();
   else
      len = word - string;
   ConsoleValue ret;
   ret.concatStringU(string, len);
   return ret;
}

ConsoleFunction(restWords, const char *, 2, 2, "restWords(text)")
{
   argc;
   const char *word = dStrchr(argv[1].toString(), ' ');
   if(word == NULL)
      return "";
   return word + 1;
}

static bool isInSet(char c, const char *set)
{
   if (set)
      while (*set)
         if (c == *set++)
            return true;

   return false;
}

ConsoleFunction(NextToken,const char *,4,4,"nextToken(str,token,delim)")
{
   argc;
   if (!argv[1].castTo(ConsoleValue::TypeString))
       return "";

   char *str = const_cast<char*>(argv[1].getStringU());
   const char *token = argv[2].toString();
   const char *delim = argv[3].toString();

   if (str)
   {
      // skip over any characters that are a member of delim
      // no need for special '\0' check since it can never be in delim
      while (isInSet(*str, delim))
         str++;

      // skip over any characters that are NOT a member of delim
      const char *tmp = str;

      while (*str && !isInSet(*str, delim))
         str++;

      // terminate the token
      if (*str)
         *str++ = 0;

      // set local variable if inside a function
      if (gEvalState.stack.size() && 
         gEvalState.stack.last().scopeName)
         Con::setLocalVariable(token,tmp);
      else
         Con::setVariable(token,tmp);

      // advance str past the 'delim space'
      while (isInSet(*str, delim))
         str++;
   }

   return str;
}

ConsoleFunctionGroupEnd( FieldManipulators )
//----------------------------------------------------------------

ConsoleFunctionGroupBegin( TaggedStrings, "Functions dealing with tagging/detagging strings.");

ConsoleFunction(detag, const char *, 2, 2, "detag(textTagString)")
{
   argc;
   if(argv[1].castTo(ConsoleValue::TypeString) && (argv[1].getStringU()[0] == StringTagPrefixByte))
   {
      const char *word = dStrchr(argv[1].getStringU(), ' ');
      if(word == NULL)
         return "";
      return word + 1;
   }
   else
      return argv[1];
}

ConsoleFunction(getTag, const char *, 2, 2, "getTag(textTagString)")
{
   argc;
   if(argv[1].castTo(ConsoleValue::TypeString) && (argv[1].getStringU()[0] == StringTagPrefixByte))
   {
      const char * string = argv[1].getStringU();
      const char * space = dStrchr(string, ' ');

      U32 len;
      if(space)
         len = space - string;
      else
         len = dStrlen(string) + 1;

      ConsoleValue ret;
      ret.concatStringU(string + 1, len - 1);
      return ret;
   }
   else
      return(argv[1]);
}

ConsoleFunctionGroupEnd( TaggedStrings );

//----------------------------------------------------------------

ConsoleFunctionGroupBegin( Output, "Functions to output to the console." );

ConsoleFunction(echo, void, 2, 0, "echo(text [, ... ])")
{
   ConsoleValue ret;
   for (S64 i = 1; i < argc; i++)
       ret.concatU(argv[i]);

   Con::printf("%s", ret);
}

ConsoleFunction(warn, void, 2, 0, "warn(text [, ... ])")
{
   ConsoleValue ret;
   for (S64 i = 1; i < argc; i++)
       ret.concatU(argv[i]);

   Con::warnf(ConsoleLogEntry::General, "%s", ret);
}

ConsoleFunction(error, void, 2, 0, "error(text [, ... ])")
{
   ConsoleValue ret;
   for (S64 i = 1; i < argc; i++)
       ret.concatU(argv[i]);

   Con::errorf(ConsoleLogEntry::General, "%s", ret);
}

ConsoleFunction(expandEscape, const char *, 2, 2, "expandEscape(text)")
{
   argc;
   ReturnBuffer ret((argv[1].getStrlen() * 2) + 1);  // worst case situation
   expandEscape( *ret, argv[1].toString() );
   return ret;
}

ConsoleFunction(collapseEscape, const char *, 2, 2, "collapseEscape(text)")
{
   argc;
   ReturnBuffer ret((argv[1].getStrlen()) + 1);  // worst case situation
   dStrcpy( *ret, argv[1].toString() );
   collapseEscape( *ret );
   return ret;
}

ConsoleFunction(setLogMode, void, 2, 2, "setLogMode(mode);")
{
   argc;
   Con::setLogMode(argv[1].getInt());
}

ConsoleFunction(setEchoFileLoads, void, 2, 2, "setEchoFileLoads(bool);")
{
   argc;
   ResourceManager->setFileNameEcho(argv[1].getInt());
}

ConsoleFunctionGroupEnd( Output );

//----------------------------------------------------------------

ConsoleFunction(quit, void, 1, 1, "quit() End execution of Torque.")
{
   argc; argv;
   Platform::postQuitMessage(0);
}

ConsoleFunction(quitWithErrorMessage, void, 2, 2, "quitWithErrorMessage(msg)"
                " - Quit, showing the provided error message. This is equivalent"
                " to an AssertISV.")
{
   AssertISV(false, argv[1].toString());
}

//----------------------------------------------------------------

ConsoleFunction( gotoWebPage, void, 2, 2, "( address ) - Open a web page in the user's favorite web browser." )
{
   argc;
   Platform::openWebBrowser( argv[1].toString() );
}

//----------------------------------------------------------------

ConsoleFunctionGroupBegin(MetaScripting, "Functions that let you manipulate the scripting engine programmatically.");

ConsoleFunction(isFunction, bool, 2, 3, "isFunction([namespace,] funcName)")
{
    if (argc == 2)
        return Con::isFunction( argv[1].toString() );
    else
    {
        char const* nsStr = argv[1].toString();
        Namespace* ns = Con::lookupNamespace( nsStr[0]? nsStr : NULL );
        if (ns)
        {
            StringTableEntry ste = StringTable->lookup( argv[2].toString() );
            return ste ? static_cast<bool>(ns->lookup(ste)) : false;
        }
        return false;
    }
}

ConsoleFunction(call, const char *, 2, 0, "call(funcName [,args ...])")
{
   return Con::execute(argc - 1, argv + 1);
}

static U32 execDepth = 0;
static U32 journalDepth = 1;

ConsoleFunction(compile, bool, 2, 2, "compile(fileName)")
{
   argc;
   char nameBuffer[512];
   char* script = NULL;
   U32 scriptSize = 0;

   Stream *compiledStream = NULL;
   FileTime comModifyTime, scrModifyTime;

   Con::expandScriptFilename(scriptFilenameBuffer, sizeof(scriptFilenameBuffer), argv[1].toString());

   dSprintf(nameBuffer, sizeof(nameBuffer), "%s.dso", scriptFilenameBuffer);
   ResourceObject *rScr = ResourceManager->find(scriptFilenameBuffer);
   ResourceObject *rCom = ResourceManager->find(nameBuffer);

   if(rCom)
      rCom->getFileTimes(NULL, &comModifyTime);
   if(rScr)
      rScr->getFileTimes(NULL, &scrModifyTime);

   Stream *s = ResourceManager->openStream(scriptFilenameBuffer);
   if(s)
   {
      scriptSize = ResourceManager->getSize(scriptFilenameBuffer);
      script = new char [scriptSize+1];
      s->read(scriptSize, script);
      ResourceManager->closeStream(s);
      script[scriptSize] = 0;
   }

   if (!scriptSize || !script)
   {
      delete [] script;
      Con::errorf(ConsoleLogEntry::Script, "compile: invalid script file %s.", scriptFilenameBuffer);
      return false;
   }
   // compile this baddie.
   Con::printf("Compiling %s...", scriptFilenameBuffer);
   CodeBlock *code = new CodeBlock();
   code->compile(nameBuffer, scriptFilenameBuffer, script);
   delete code;
   code = NULL;

   delete[] script;
   return true;
}

ConsoleFunction(exec, bool, 2, 4, "exec(fileName [, nocalls [,journalScript]])")
{
   bool journal = false;

   execDepth++;
   if(journalDepth >= execDepth)
      journalDepth = execDepth + 1;
   else
      journal = true;

   bool noCalls = false;
   bool ret = false;

   if(argc >= 3 && argv[2].getInt())
      noCalls = true;

   if(argc >= 4 && argv[3].getInt() && !journal)
   {
      journal = true;
      journalDepth = execDepth;
   }

   // Determine the filename we actually want...
   Con::expandScriptFilename(scriptFilenameBuffer, sizeof(scriptFilenameBuffer), argv[1].toString());

   const char *ext = dStrrchr(scriptFilenameBuffer, '.');

   if(!ext)
   {
      // We need an extension!
      Con::errorf(ConsoleLogEntry::Script, "exec: invalid script file name %s.", scriptFilenameBuffer);
      execDepth--;
      return false;
   }

   StringTableEntry scriptFileName = StringTable->insert(scriptFilenameBuffer);

   // Is this a file we should compile?
   bool compiled = dStricmp(ext, ".mis") && !journal && !Con::getBoolVariable("Pref::ignoreDSOs");

   // If we're in a journalling mode, then we will read the script
   // from the journal file.
   if(journal && Game->isJournalReading())
   {
      char fileNameBuf[256];
      bool fileRead;
      U32 fileSize;

      Game->getJournalStream()->readString(fileNameBuf);
      Game->getJournalStream()->read(&fileRead);
      if(!fileRead)
      {
         Con::errorf(ConsoleLogEntry::Script, "Journal script read (failed) for %s", fileNameBuf);
         execDepth--;
         return false;
      }
      Game->journalRead(&fileSize);
      char *script = new char[fileSize + 1];
      Game->journalRead(fileSize, script);
      script[fileSize] = 0;
      Con::printf("Executing (journal-read) %s.", scriptFileName);
      CodeBlock *newCodeBlock = new CodeBlock();
      newCodeBlock->compileExec(scriptFileName, script, noCalls);
      delete [] script;

      execDepth--;
      return true;
   }

   // Ok, we let's try to load and compile the script.
   ResourceObject *rScr = ResourceManager->find(scriptFileName);
   ResourceObject *rCom = NULL;

   char nameBuffer[512];
   char* script = NULL;
   U32 scriptSize = 0;
   U32 version;

   Stream *compiledStream = NULL;
   FileTime comModifyTime, scrModifyTime;

   // If we're supposed to be compiling this file, check to see if there's a DSO
   if(compiled)
   {
      dStrcpyl(nameBuffer, sizeof(nameBuffer), scriptFileName, ".dso", NULL);
      rCom = ResourceManager->find(nameBuffer);

      if(rCom)
         rCom->getFileTimes(NULL, &comModifyTime);
      if(rScr)
         rScr->getFileTimes(NULL, &scrModifyTime);
   }

   // Let's do a sanity check to complain about DSOs in the future.
   if(compiled && rCom && rScr && Platform::compareFileTimes(comModifyTime, scrModifyTime) < 0)
   {
      Con::warnf("exec: Warning! Found a DSO from the future! (%s)", nameBuffer);
   }

   // If we had a DSO, let's check to see if we should be reading from it.
   if(compiled && rCom && (!rScr || Platform::compareFileTimes(comModifyTime, scrModifyTime) >= 0))
   {
      compiledStream = ResourceManager->openStream(nameBuffer);

      // Check the version!
      compiledStream->read(&version);
      if(version != Con::DSOVersion)
      {
         Con::warnf("exec: Found an old DSO (%s, ver %d < %d), ignoring.", nameBuffer, version, Con::DSOVersion);
         ResourceManager->closeStream(compiledStream);
         compiledStream = NULL;
      }
   }

   // If we're journalling, let's write some info out.
   if(journal && Game->isJournalWriting())
      Game->getJournalStream()->writeString(scriptFileName);

   if(rScr && !compiledStream)
   {
      // If we have source but no compiled version, then we need to compile
      // (and journal as we do so, if that's required).

      Stream *s = ResourceManager->openStream(scriptFileName);
      if(journal && Game->isJournalWriting())
         Game->getJournalStream()->write(bool(s != NULL));

      if(s)
      {
         scriptSize = ResourceManager->getSize(scriptFileName);
         script = new char [scriptSize+1];
         s->read(scriptSize, script);

         if(journal && Game->isJournalWriting())
         {
            Game->journalWrite(scriptSize);
            Game->journalWrite(scriptSize, script);
         }
         ResourceManager->closeStream(s);
         script[scriptSize] = 0;
      }

      if (!scriptSize || !script)
      {
         delete [] script;
         Con::errorf(ConsoleLogEntry::Script, "exec: invalid script file %s.", scriptFileName);
         execDepth--;
         return false;
      }

      if(compiled)
      {
         // compile this baddie.
         Con::printf("Compiling %s...", scriptFileName);
         CodeBlock *code = new CodeBlock();
         code->compile(nameBuffer, scriptFileName, script);
         delete code;
         code = NULL;

         compiledStream = ResourceManager->openStream(nameBuffer);
         if(compiledStream)
         {
            compiledStream->read(&version);
         }
         else
         {
            // We have to exit out here, as otherwise we get double error reports.
            delete [] script;
            execDepth--;
            return false;
         }
      }
   }
   else
   {
      if(journal && Game->isJournalWriting())
         Game->getJournalStream()->write(bool(false));
   }

   if(compiledStream)
   {
      // Delete the script object first to limit memory used
      // during recursive execs.
      delete [] script;
      script = 0;

      // We're all compiled, so let's run it.
      Con::printf("Loading compiled script %s.", scriptFileName);
      CodeBlock *code = new CodeBlock;
      code->read(scriptFileName, *compiledStream);
      ResourceManager->closeStream(compiledStream);
      code->exec(0, scriptFileName, NULL, 0, NULL, noCalls, NULL);
      ret = true;
   }
   else
      if(rScr)
      {
         // No compiled script,  let's just try executing it
         // directly... this is either a mission file, or maybe
         // we're on a readonly volume.
         Con::printf("Executing %s.", scriptFileName);
         CodeBlock *newCodeBlock = new CodeBlock();
         StringTableEntry name = StringTable->insert(scriptFileName);

         newCodeBlock->compileExec(name, script, noCalls);
         ret = true;
      }
      else
      {
         // Don't have anything.
         Con::warnf(ConsoleLogEntry::Script, "Missing file: %s!", scriptFileName);
         ret = false;
      }

   delete [] script;
   execDepth--;
   return ret;
}

ConsoleFunction(eval, const char *, 2, 2, "eval(consoleString)")
{
   argc;
   return Con::evaluate(argv[1].toString(), false, NULL);
}

//----------------------------------------------------------------

ConsoleFunction(export, void, 2, 4, "export(searchString [, fileName [,append]])")
{
   const char *filename = NULL;
   bool append = (argc == 4) ? argv[3].getInt() : false;

   if (argc >= 3)
      if (Con::expandScriptFilename(scriptFilenameBuffer, sizeof(scriptFilenameBuffer), argv[2].toString()))
         filename = scriptFilenameBuffer;

   gEvalState.globalVars.exportVariables(argv[1].toString(), filename, append);
}

ConsoleFunction(exportList, void, 3, 4, "exportList(searchString, fileName [,append]) - formatted *.list export")
{
    // A more sane and approachable format for named value lists than a literal executable script file.
    char filename[1024] = {};
    bool append = (argc == 4) ? argv[3].getInt() : false;

    if (Con::expandScriptFilename(scriptFilenameBuffer, sizeof(scriptFilenameBuffer), argv[2].toString()))
        dStrncpy(filename, scriptFilenameBuffer, 1023);
    else
    {
        Con::errorf("exportList: Could not export variable list to %s", filename);
        return;
    }

    gEvalState.globalVars.exportVariables(argv[1].toString(), filename, append, false);
}

ConsoleFunction(importList, void, 2, 2, "importList(fileName) - formatted *.list import")
{
    const char* filename = NULL;
    if (Con::expandScriptFilename(scriptFilenameBuffer, sizeof(scriptFilenameBuffer), argv[1].toString()))
        filename = scriptFilenameBuffer;
    else
    {
        Con::errorf("importList: Could not import variable list from %s", argv[2]);
        return;
    }

    U32 line = 1;
    FileStream fs;
    if (fs.open(filename, FileStream::AccessMode::Read))
    {
        do {
            char linebuf[512]{};
            fs.readLine((U8*)linebuf, 512);

            char varbuf[128]{}; varbuf[0] = '$';
            char valbuf[256]{};
            if (dSscanf(linebuf, " %126s %255[^\n]\n", &varbuf[1], valbuf) >= 1)
                // Technically, this can add variables that are unreachable from TS, but that's interesting.
                gEvalState.globalVars.setVariable(StringTable->insert(varbuf), ConsoleValue(valbuf));
            else
            {
                Con::warnf("importList: Read %u lines in file %s", line, filename);
                break;
            }
            ++line;
        } while (fs.getStatus() != FileStream::EOS);
        fs.close();
    }
    else
    {
        Con::warnf("importList: Could not open list file associated with %s", filename);
        return;
    }
}

ConsoleFunction(deleteVariables, void, 2, 2, "deleteVariables(wildCard)")
{
   argc;
   gEvalState.globalVars.deleteVariables(argv[1].toString());
}

//----------------------------------------------------------------

ConsoleFunction(trace, void, 2, 2, "trace(bool)")
{
   argc;
   gEvalState.traceOn = argv[1].getInt();
   Con::printf("Console trace is %s", gEvalState.traceOn ? "on." : "off.");
}

//----------------------------------------------------------------

#if defined(TORQUE_DEBUG) || defined(INTERNAL_RELEASE)
ConsoleFunction(debug, void, 1, 1, "debug()")
{
   argv; argc;
   Platform::debugBreak();
}
#endif

ConsoleFunctionGroupEnd( MetaScripting );

//----------------------------------------------------------------

ConsoleFunctionGroupBegin( InputManagement, "Functions that let you deal with input from scripts" );

ConsoleFunction( deactivateDirectInput, void, 1, 1, "Deactivate input. (ie, ungrab the mouse so the user can do other things." )
{
   argc; argv;
   if ( Input::isActive() )
      Input::deactivate();
}

//--------------------------------------------------------------------------
ConsoleFunction( activateDirectInput, void, 1, 1, "Activate input. (ie, grab the mouse again so the user can play our game." )
{
   argc; argv;
   if ( !Input::isActive() )
      Input::activate();
}

ConsoleFunctionGroupEnd( InputManagement );

//----------------------------------------------------------------

ConsoleFunctionGroupBegin( FileSystem, "Functions allowing you to search for files, read them, write them, and access their properties.");

static ResourceObject *firstMatch = NULL;

ConsoleFunction(findFirstFile, const char *, 2, 2, "(string pattern) Returns the first file in the directory system matching the given pattern.")
{
   argc;
   const char *fn;
   firstMatch = NULL;
   if(Con::expandScriptFilename(scriptFilenameBuffer, sizeof(scriptFilenameBuffer), argv[1].toString()))
      firstMatch = ResourceManager->findMatch(scriptFilenameBuffer, &fn, NULL);
   if(firstMatch)
      return fn;
   else
      return "";
}

ConsoleFunction(findNextFile, const char *, 2, 2, "(string pattern) Returns the next file matching a search begun in findFirstFile.")
{
   argc;
   const char *fn;
   if(Con::expandScriptFilename(scriptFilenameBuffer, sizeof(scriptFilenameBuffer), argv[1].toString()))
      firstMatch = ResourceManager->findMatch(scriptFilenameBuffer, &fn, firstMatch);
   else
      firstMatch = NULL;
   if(firstMatch)
      return fn;
   else
      return "";
}

ConsoleFunction(getFileCount, S32, 2, 2, "(string pattern)returns the number of files in the directory tree that match the given pattern")
{
   argc;
   const char* fn;
   U32 count = 0;
   firstMatch = ResourceManager->findMatch(argv[1].toString(), &fn, NULL);
   if ( firstMatch )
   {
      count++;
      while ( 1 )
      {
         firstMatch = ResourceManager->findMatch(argv[1].toString(), &fn, firstMatch);
         if ( firstMatch )
            count++;
         else
            break;
      }
   }

   return S64( count );
}

ConsoleFunction(getFileCRC, S32, 2, 2, "getFileCRC(filename)")
{
   argc;
   U32 crcVal;
   Con::expandScriptFilename(scriptFilenameBuffer, sizeof(scriptFilenameBuffer), argv[1].toString());

   if(!ResourceManager->getCrc(scriptFilenameBuffer, crcVal))
      return(-1);
   return(S32(crcVal));
}

ConsoleFunction(isFile, bool, 2, 2, "isFile(fileName)")
{
   argc;
   Con::expandScriptFilename(scriptFilenameBuffer, sizeof(scriptFilenameBuffer), argv[1].toString());
   return bool(ResourceManager->find(scriptFilenameBuffer));
}

ConsoleFunction(isWriteableFileName, bool, 2, 2, "isWriteableFileName(fileName)")
{
   argc;
   // in a writeable directory?
   Con::expandScriptFilename(scriptFilenameBuffer, sizeof(scriptFilenameBuffer), argv[1].toString());
   if(!ResourceManager->isValidWriteFileName(scriptFilenameBuffer))
      return(false);

   // exists?
   FileStream fs;
   if(!fs.open(scriptFilenameBuffer, FileStream::Read))
      return(true);

   // writeable? (ReadWrite will create file if it does not exist)
   fs.close();
   if(!fs.open(scriptFilenameBuffer, FileStream::ReadWrite))
      return(false);

   return(true);
}

//----------------------------------------------------------------

ConsoleFunction(fileExt, const char*, 2, 2, "fileExt(fileName) - Returns file extension with the dot.")
{
    argc;
    const char* ret = dStrrchr(argv[1].toString(), '.');
    if (ret) {
        // dont't catch a weird dotted base path when there's no ext...
        if (dStrchr(ret + 1, '/'))
            return "";
        return ret;
    }
    return "";
}

ConsoleFunction(fileBase, const char *, 2, 2, "fileBase(fileName)")
{
   argc;
   const char *path = dStrrchr(argv[1].toString(), '/');
   if(!path)
      path = argv[1].toString();
   else
      path++;
   char const* ext = dStrrchr(path, '.');
   ConsoleValue ret;
   ret.concatStringU(path, ext? ext - path : dStrlen(path));
   return ret;
}

ConsoleFunction(fileName, const char *, 2, 2, "fileName(filePathName)")
{
   argc;
   const char *name = dStrrchr(argv[1].toString(), '/');
   if(!name)
      name = argv[1].toString();
   else
      name++;
   ConsoleValue ret;
   ret.concatStringU(name, dStrlen(name));
   return ret;
}

ConsoleFunction(filePath, const char *, 2, 2, "filePath(fileName)")
{
   argc;
   const char *arg = argv[1].toString();
   const char *path = dStrrchr(arg, '/');
   if(!path)
      return "";
   U32 len = path - arg;
   ConsoleValue ret;
   ret.concatStringU(arg, len);
   return ret;
}

ConsoleFunctionGroupEnd( FileSystem );

ConsoleFunctionGroupBegin( Utility, "Utility global functions.");

ConsoleFunction( max, F32, 2, 0, "max(...) - Get max argument")
{
    F64 curMax = argv[1].getNumber();
    for (S32 i = 2; i < argc; ++i)
        curMax = getMax(argv[i].getNumber(), curMax);
    return curMax;
}

ConsoleFunction( min, F32, 2, 0, "min(...) - Get min argument")
{
    F64 curMin = argv[1].getNumber();
    for (S32 i = 2; i < argc; ++i)
        curMin = getMin(argv[i].getNumber(), curMin);
    return curMin;
}

ConsoleFunctionGroupEnd( Utility );
