//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#include "platform/platform.h"
#include "console/console.h"
#include "math/mMathFn.h"
#include "math/mRandom.h"

ConsoleFunctionGroupBegin( GeneralMath, "General math functions. Use these whenever possible, as they'll run much faster than script equivalents.");

ConsoleFunction( mSolveQuadratic, const char *, 4, 4, "(float a, float b, float c)"
              "Solve a quadratic equation of form a*x^2 + b*x + c = 0.\n\n"
              "@returns A triple, contanining: sol x0 x1. sol is the number of"
              " solutions (being 0, 1, or 2), and x0 and x1 are the solutions, if any."
              " Unused x's are undefined.")
{
   F32 x[2];
   U32 sol = mSolveQuadratic(argv[1].getNumber(), argv[2].getNumber(), argv[3].getNumber(), x);
   return ConsoleValueList::from(sol, x[0], x[1]);
}

ConsoleFunction( mSolveCubic, const char *, 5, 5, "(float a, float b, float c, float d)"
              "Solve a cubic equation of form a*x^3 + b*x^2 + c*x + d = 0.\n\n"
              "@returns A 4-tuple, contanining: sol x0 x1 x2. sol is the number of"
              " solutions (being 0, 1, 2, or 3), and x0, x1, x2 are the solutions, if any."
              " Unused x's are undefined.")
{
   F32 x[3];
   U32 sol = mSolveCubic(argv[1].getNumber(), argv[2].getNumber(), argv[3].getNumber(), argv[4].getNumber(), x);
   return ConsoleValueList::from(sol, x[0], x[1], x[2]);
}

ConsoleFunction( mSolveQuartic, const char *, 6, 6, "(float a, float b, float c, float d, float e)"
              "Solve a quartic equation of form a*x^4 + b*x^3 + c*x^2 + d*x + e = 0.\n\n"
              "@returns A 5-tuple, contanining: sol x0 x1 x2 x3. sol is the number of"
              " solutions (ranging from 0-4), and x0, x1, x2 and x3 are the solutions, if any."
              " Unused x's are undefined.")
{
   F32 x[4];
   U32 sol = mSolveQuartic(argv[1].getNumber(), argv[2].getNumber(), argv[3].getNumber(), argv[4].getNumber(), argv[5].getNumber(), x);
   return ConsoleValueList::from(sol, x[0], x[1], x[2], x[3]);
}

ConsoleFunction( mFloor, S32, 2, 2, "(float v) Round v down to the nearest whole number.")
{
   return (S32)mFloor(argv[1].getNumber());
}

ConsoleFunction( mCeil, S32, 2, 2, "(float v) Round v up to the nearest whole number.")
{
   return (S32)mCeil(argv[1].getNumber());
}

ConsoleFunction( mRound, S32, 2, 2, "(float v) Round v to the nearest whole number.")
{
    return (S32)mRound(argv[1].getNumber());
}

ConsoleFunction( mFloatLength, const char *, 3, 3, "(float v, int numDecimals)"
              "Return a string containing v formatted with the specified number of decimal places.")
{
   char outBuffer[256];
   char fmtString[8] = "%.0f";
   U32 precision = argv[2].getInt();
   if (precision > 9)
      precision = 9;
   fmtString[2] = '0' + precision;

   dSprintf(outBuffer, 255, fmtString, argv[1].getNumber());
   return outBuffer;
}

//------------------------------------------------------------------------------
ConsoleFunction( mAbs, F32, 2, 2, "(float v) Returns the absolute value of the argument.")
{
   return(mFabs(argv[1].getNumber()));
}

ConsoleFunction( mSqrt, F32, 2, 2, "(float v) Returns the square root of the argument.")
{
   return(mSqrt(argv[1].getNumber()));
}

ConsoleFunction( mPow, F32, 3, 3, "(float b, float p) Returns the b raised to the pth power.")
{
   return(mPow(argv[1].getNumber(), argv[2].getNumber()));
}

ConsoleFunction( mLog, F32, 2, 2, "(float v) Returns the natural logarithm of the argument.")
{
   return(mLog(argv[1].getNumber()));
}

ConsoleFunction( mSin, F32, 2, 2, "(float th) Returns the sine of th, which is in radians.")
{
   return(mSin(argv[1].getNumber()));
}

ConsoleFunction( mCos, F32, 2, 2, "(float th) Returns the cosine of th, which is in radians.")
{
   return(mCos(argv[1].getNumber()));
}

ConsoleFunction( mTan, F32, 2, 2, "(float th) Returns the tangent of th, which is in radians.")
{
   return(mTan(argv[1].getNumber()));
}

ConsoleFunction( mAsin, F32, 2, 2, "(float th) Returns the arc-sine of th, which is in radians.")
{
   return(mAsin(argv[1].getNumber()));
}

ConsoleFunction( mAcos, F32, 2, 2, "(float th) Returns the arc-cosine of th, which is in radians.")
{
   return(mAcos(argv[1].getNumber()));
}

ConsoleFunction( mAtan, F32, 3, 3, "(float rise, float run) Returns the slope in radians (the arc-tangent) of a line with the given rise and run.")
{
   return(mAtan(argv[1].getNumber(), argv[2].getNumber()));
}

ConsoleFunction( mRadToDeg, F32, 2, 2, "(float radians) Converts a measure in radians to degrees.")
{
   return(mRadToDeg(argv[1].getNumber()));
}

ConsoleFunction( mDegToRad, F32, 2, 2, "(float degrees) Convert a measure in degrees to radians.")
{
   return(mDegToRad(argv[1].getNumber()));
}

ConsoleFunctionGroupEnd( GeneralMath );

ConsoleFunctionGroupBegin( GeneralHash, "General hash functions.");



ConsoleFunctionGroupEnd( GeneralHash );
