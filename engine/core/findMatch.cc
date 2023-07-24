//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#include "platform/platform.h"
#include "core/findMatch.h"

//--------------------------------------------------------------------------------
// NAME
//   FindMatch::FindMatch( const char *_expression, S32 maxNumMatches )
//
// DESCRIPTION
//   Class to match regular expressions (file names)
//   only works with '*','?', and 'chars'
//
// ARGUMENTS
//   _expression  -  The regular expression you intend to match (*.??abc.bmp)
//   _maxMatches  -  The maximum number of strings you wish to match.
//
// RETURNS
//
// NOTES
//
//--------------------------------------------------------------------------------

FindMatch::FindMatch( U32 _maxMatches )
{
   VECTOR_SET_ASSOCIATION(matchList);

   expression = NULL;
   maxMatches = _maxMatches;
   matchList.reserve( maxMatches );
}

FindMatch::FindMatch( char *_expression, U32 _maxMatches )
{
   VECTOR_SET_ASSOCIATION(matchList);

   expression = NULL;
   setExpression( _expression );
   maxMatches = _maxMatches;
   matchList.reserve( maxMatches );
}

FindMatch::~FindMatch()
{
   delete [] expression;
   matchList.clear();
}

void FindMatch::setExpression( const char *_expression )
{
   delete [] expression;

   expression = new char[dStrlen(_expression) + 1];
   dStrcpy(expression, _expression);
   dStrupr(expression);
}

bool FindMatch::findMatch( const char *str, bool caseSensitive )
{
   if ( isFull() )
      return false;

   char nstr[512];
   dStrcpy( nstr,str );
   dStrupr(nstr);
   if ( isMatch( expression, nstr, caseSensitive ) )
   {
      matchList.push_back( (char*)str );
      return true;
   }
   return false;
}

// Backported from T3D
#define IS_CHAR_MATCH(a, b, sens) ((sens)? (a) == (b) : dTolower(a) == dTolower(b))
bool FindMatch::isMatch( const char *exp, const char *str, bool caseSensitive )
{
    if (str == NULL || exp == NULL)
        return false;

    while (*str && (*exp != '*'))
        if ( !IS_CHAR_MATCH(*exp++, *str++, caseSensitive) )
            return false;

    const char* cp = NULL;
    const char* mp = NULL;

    while (*str)
    {
        if (*exp == '*')
        {
            if (!*++exp)
                return true;

            mp = exp;
            cp = str + 1;
        }
        else if ( (*exp == '?') || IS_CHAR_MATCH(*exp, *str, caseSensitive) )
        {
            exp++;
            str++;
        }
        else
        {
            exp = mp;
            str = cp++;
        }
    }

    while (*exp == '*')
        exp++;

    return !*exp;
}


bool FindMatch::isMatchMultipleExprs( const char *exps, const char *str, bool caseSensitive )
{
   char *tok = 0;
   int len = dStrlen(exps);

   char *e = new char[len+1];
   dStrcpy(e,exps);

   // allow for either tab or space seperated.
   for(int i=0;i<len;i++)
   {
      if(e[i]=='\t')
         e[i]=' ';
   }

   // search for each expression. return true soon as we see one.
   for( tok = dStrtok(e," "); tok != NULL; tok = dStrtok(NULL," "))
   {
      if( isMatch( tok, str, caseSensitive) )
      {
         delete []e;
         return true;
      }
   }

   delete []e;
   return false;
}
