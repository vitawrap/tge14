%{
#define YYLMAX 4096

#include <stdio.h>
#include "platform/platform.h"
#include "core/stringTable.h"
#include "console/console.h"
#include "console/compiler.h"

using namespace Compiler;

#define YY_NEVER_INTERACTIVE 1
#define YY_NO_UNISTD_H 1

// Some basic parsing primitives...
static int Sc_ScanString(int ret);
static int Sc_ScanNum();
static int Sc_ScanVar();
static int Sc_ScanHex();

// Deal with debuggability of FLEX.
#ifdef TORQUE_DEBUG
#define FLEX_DEBUG 1
#else
#define FLEX_DEBUG 0
#endif

// Install our own input code...
#undef cmdgetc
int cmdgetc();

// Hack to make windows lex happy.
#ifndef isatty
inline int isatty(int) { return 0; }
#endif

// Wrap our getc, so that lex doesn't try to do its own buffering/file IO.
#define YY_INPUT(buf,result,max_size) \
   { \
      int c = '*', n; \
      for ( n = 0; n < max_size && \
            (c = cmdgetc()) != EOF && c != '\n'; ++n ) \
         buf[n] = (char) c; \
      if ( c == '\n' ) \
         buf[n++] = (char) c; \
      result = n; \
   }

// General helper stuff.
static int lineIndex;

// File state
void CMDSetScanBuffer(const char *sb, const char *fn);
const char * CMDgetFileLine(int &lineNumber);

// Error reporting
void cmderror(char * s, ...);

// Reset the parser.
void cmdrestart(FILE *in);

%}

%option nounistd
%option prefix="CMD"
%option outfile="CMDscan.cc"

DIGIT    [0-9]
INTEGER  {DIGIT}+
FLOAT    ({INTEGER}\.{INTEGER})|({INTEGER}(\.{INTEGER})?[eE][+-]?{INTEGER})
LETTER   [A-Za-z_]
FILECHAR [A-Za-z_\.]
VARMID   [:A-Za-z0-9_]
IDTAIL   [A-Za-z0-9_]
VARTAIL  {VARMID}*{IDTAIL}
VAR      [$%]{LETTER}{VARTAIL}*
ID       {LETTER}{IDTAIL}*
ILID     [$%]{DIGIT}+{LETTER}{VARTAIL}*
FILENAME {FILECHAR}+
SPACE    [ \t\v\f]
HEXDIGIT [a-fA-F0-9]

%%
         ;
{SPACE}+ { }
"//"[^\n\r]*   ;
[\r]        ;
[\n]        {lineIndex++;}
\"(\\.|[^\\"\n\r])*\"      { return(Sc_ScanString(STRATOM)); }
\'(\\.|[^\\'\n\r])*\'      { return(Sc_ScanString(TAGATOM)); }
"=="        return(cmdlval.i = opEQ);
"!="        return(cmdlval.i = opNE);
">="        return(cmdlval.i = opGE);
"<="        return(cmdlval.i = opLE);
"&&"        return(cmdlval.i = opAND);
"||"        return(cmdlval.i = opOR);
"??"        return(cmdlval.i = opFORGIVE);
"::"        return(cmdlval.i = opCOLONCOLON);
"--"        return(cmdlval.i = opMINUSMINUS);
"++"        return(cmdlval.i = opPLUSPLUS);
"$="        return(cmdlval.i = opSTREQ);
"!$="       return(cmdlval.i = opSTRNE);
"<<"        return(cmdlval.i = opSHL);
">>"        return(cmdlval.i = opSHR);
"+="        return(cmdlval.i = opPLASN);
"-="        return(cmdlval.i = opMIASN);
"*="        return(cmdlval.i = opMLASN);
"/="        return(cmdlval.i = opDVASN);
"%="        return(cmdlval.i = opMODASN);
"&="        return(cmdlval.i = opANDASN);
"^="        return(cmdlval.i = opXORASN);
"|="        return(cmdlval.i = opORASN);
"<<="       return(cmdlval.i = opSLASN);
">>="       return(cmdlval.i = opSRASN);
"instanceof" return(cmdlval.i = opINSTANCE);
"NL"        {cmdlval.i = '\n'; return '@'; }
"TAB"       {cmdlval.i = '\t'; return '@'; }
"SPC"       {cmdlval.i = ' '; return '@'; }
"@"         {cmdlval.i = 0; return '@'; }
"/*"		{
				register int c;
				for ( ; ; )
				{
					while ( (c = cmdgetc()) != '*' && c != EOF )
					; /* eat up text of comment */

					if ( c == '*' )
					{
						while ( (c = cmdgetc()) == '*' )
						;
						if ( c == '/' )
							break; /* found the end */
					}

					if ( c == EOF )
					{
						cmderror( "EOF in comment" );
						break;
					}
				}
			}
"?" |
"[" |
"]" |
"(" | 
")" | 
"+" | 
"-" | 
"*" | 
"/" |
"<" | 
">" | 
"|" | 
"." | 
"!" |
":" | 
";" |
"{" | 
"}" | 
"," |
"&" |
"%" |
"^" |
"~" |
"=" {       return(cmdlval.i = CMDtext[0]); }
"or"        { cmdlval.i = lineIndex; return(rwCASEOR); }
"break"     { cmdlval.i = lineIndex; return(rwBREAK); }
"return"    { cmdlval.i = lineIndex; return(rwRETURN); }
"else"      { cmdlval.i = lineIndex; return(rwELSE); }
"while"     { cmdlval.i = lineIndex; return(rwWHILE); }
"do"        { cmdlval.i = lineIndex; return(rwDO); }
"if"        { cmdlval.i = lineIndex; return(rwIF); }
"for"       { cmdlval.i = lineIndex; return(rwFOR); }
"continue"  { cmdlval.i = lineIndex; return(rwCONTINUE); }
"function"  { cmdlval.i = lineIndex; return(rwDEFINE); }
"new"       { cmdlval.i = lineIndex; return(rwDECLARE); }
"datablock" { cmdlval.i = lineIndex; return(rwDATABLOCK); }
"case"      { cmdlval.i = lineIndex; return(rwCASE); }
"switch$"   { cmdlval.i = lineIndex; return(rwSWITCHSTR); }
"switch"    { cmdlval.i = lineIndex; return(rwSWITCH); }
"default"   { cmdlval.i = lineIndex; return(rwDEFAULT); }
"package"   { cmdlval.i = lineIndex; return(rwPACKAGE); }
"namespace" { cmdlval.i = lineIndex; return(rwNAMESPACE); }
"true"      { cmdlval.i = 1; return INTCONST; }
"false"     { cmdlval.i = 0; return INTCONST; }
{VAR}       return(Sc_ScanVar());
{ID}        { CMDtext[CMDleng] = 0; cmdlval.s = StringTable->insert(CMDtext); return(IDENT); }
0[xX]{HEXDIGIT}+ return(Sc_ScanHex());
{INTEGER}   { CMDtext[CMDleng] = 0; cmdlval.i = dAtoi(CMDtext); return INTCONST; }
{FLOAT}     return Sc_ScanNum();
{ILID}      return(ILLEGAL_TOKEN);
.           return(ILLEGAL_TOKEN);
%%

static const char *scanBuffer;
static const char *fileName;
static int scanIndex;
 
const char * CMDGetCurrentFile()
{
   return fileName;
}

int CMDGetCurrentLine()
{
   return lineIndex;
}

void cmderror(char *, ...)
{
   gSyntaxError = true;
   if(fileName)
      Con::errorf(ConsoleLogEntry::Script, "%s Line: %d - Syntax error.",
         fileName, lineIndex);
   else
      Con::errorf(ConsoleLogEntry::Script, "Syntax error in input.");
}

void CMDSetScanBuffer(const char *sb, const char *fn)
{
   scanBuffer = sb;
   fileName = fn;
   scanIndex = 0;
   lineIndex = 1;
}

int cmdgetc()
{
   int ret = scanBuffer[scanIndex];
   if(ret)
      scanIndex++;
   else
      ret = -1;
   return ret;
}

int CMDwrap()
{
   return 1;
}

static int Sc_ScanVar()
{
   // Truncate the temp buffer...
   CMDtext[CMDleng] = 0;
   
   // Make it a stringtable string!
   cmdlval.s = StringTable->insert(CMDtext);
   return(VAR);
}

static int charConv(int in)
{
   switch(in)
   {
      case 'r':
         return '\r';
      case 'n':
         return '\n';
      case 't':
         return '\t';
      default:
         return in;
   }
}

static int getHexDigit(char c)
{
   if(c >= '0' && c <= '9')
      return c - '0';
   if(c >= 'A' && c <= 'F')
      return c - 'A' + 10;
   if(c >= 'a' && c <= 'f')
      return c - 'a' + 10;
   return -1;
}

static int Sc_ScanString(int ret)
{
   CMDtext[CMDleng - 1] = 0;
   if(!collapseEscape(CMDtext+1))
      return -1;
   cmdlval.str = (char *) consoleAlloc(dStrlen(CMDtext));
   dStrcpy(cmdlval.str, CMDtext + 1);
   return(ret);
}

void expandEscape(char *dest, const char *src)
{
   U8 c;
   while((c = (U8) *src++) != 0)
   {
      if(c == '\"')
      {
         *dest++ = '\\';
         *dest++ = '\"';
      }
      else if(c == '\\')
      {
         *dest++ = '\\';
         *dest++ = '\\';
      }
      else if(c == '\r')
      {
         *dest++ = '\\';
         *dest++ = 'r';
      }
      else if(c == '\n')
      {
         *dest++ = '\\';
         *dest++ = 'n';
      }
      else if(c == '\t')
      {
         *dest++ = '\\';
         *dest++ = 't';
      }
      else if(c == '\'')
      {
         *dest++ = '\\';
         *dest++ = '\'';
      }
      else if((c >= 1 && c <= 7) ||
              (c >= 11 && c <= 12) ||
              (c >= 14 && c <= 15))
      {
        /*  Remap around: \b = 0x8, \t = 0x9, \n = 0xa, \r = 0xd */
        static U8 expandRemap[15] = { 0x0,
                                        0x0,
                                        0x1,
                                        0x2,
                                        0x3,
                                        0x4,
                                        0x5,
                                        0x6,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x7,
                                        0x8,
                                        0x0,
                                        0x9 };

         *dest++ = '\\';
         *dest++ = 'c';
         if(c == 15)
            *dest++ = 'r';
         else if(c == 16)
            *dest++ = 'p';
         else if(c == 17)
            *dest++ = 'o';
         else 
            *dest++ = expandRemap[c] + '0';
      }
      else if(c < 32)
      {
         *dest++ = '\\';
         *dest++ = 'x';
         S32 dig1 = c >> 4;
         S32 dig2 = c & 0xf;
         if(dig1 < 10)
            dig1 += '0';
         else
            dig1 += 'A' - 10;
         if(dig2 < 10)
            dig2 += '0';
         else
            dig2 += 'A' - 10;
         *dest++ = dig1;
         *dest++ = dig2;
      }
      else
         *dest++ = c;
   }
   *dest = '\0';
}   

bool collapseEscape(char *buf)
{
   S32 len = dStrlen(buf) + 1;
   for(S32 i = 0; i < len;)
   {
      if(buf[i] == '\\')
      {
         if(buf[i+1] == 'x')
         {
            S32 dig1 = getHexDigit(buf[i+2]);
            if(dig1 == -1)
               return false;

            S32 dig2 = getHexDigit(buf[i+3]);
            if(dig2 == -1)
               return false;
            buf[i] = dig1 * 16 + dig2;
            dMemmove(buf + i + 1, buf + i + 4, len - i - 3);
            len -= 3;
            i++;
         }
         else if(buf[i+1] == 'c')
         {
            /*  Remap around: \b = 0x8, \t = 0x9, \n = 0xa, \r = 0xd */
            static U8 collapseRemap[10] = { 0x1,
                                              0x2,
                                              0x3,
                                              0x4,
                                              0x5,
                                              0x6,
                                              0x7,
                                              0xb,
                                              0xc,
                                              0xe };
                                            
            if(buf[i+2] == 'r')
                buf[i] = 15;
            else if(buf[i+2] == 'p')
               buf[i] = 16;
            else if(buf[i+2] == 'o')
               buf[i] = 17;
            else
            {
                int dig1 = buf[i+2] - '0';
                if(dig1 < 0 || dig1 > 9)
                   return false;
                buf[i] = collapseRemap[dig1];
            }
            // Make sure we don't put 0x1 at the beginning of the string.
            if ((buf[i] == 0x1) && (i == 0))
            {
               buf[i] = 0x2;
               buf[i+1] = 0x1;
               dMemmove(buf + i + 2, buf + i + 3, len - i - 1);
               len -= 1;
            }
            else
            {
               dMemmove(buf + i + 1, buf + i + 3, len - i - 2);
               len -= 2;
            }
            i++;         
         }
         else
         {
            buf[i] = charConv(buf[i+1]);
            dMemmove(buf + i + 1, buf + i + 2, len - i - 1);
            len--;
            i++;
         }
      }
      else
         i++;
   }
   return true;
}

static int Sc_ScanNum()
{
   CMDtext[CMDleng] = 0;
   cmdlval.f = dAtof(CMDtext);
   return(FLTCONST);
}

static int Sc_ScanHex()
{
   S32 val = 0;
   dSscanf(CMDtext, "%x", &val);
   cmdlval.i = val;
   return INTCONST;
}

void CMD_reset()
{
   CMDrestart(NULL);
}