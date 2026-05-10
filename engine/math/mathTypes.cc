//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#include "console/consoleTypes.h"
#include "console/console.h"
#include "math/mPoint.h"
#include "math/mMatrix.h"
#include "math/mRect.h"
#include "math/mBox.h"
#include "math/mathTypes.h"
#include "math/mRandom.h"

//////////////////////////////////////////////////////////////////////////
// TypePoint2I
//////////////////////////////////////////////////////////////////////////
ConsoleType( Point2I, TypePoint2I, sizeof(Point2I) )

ConsoleGetType( TypePoint2I )
{
   Point2I *pt = (Point2I *) dptr;
   return ConsoleValueList::from(pt->x, pt->y);
}

ConsoleSetType( TypePoint2I )
{
   *((Point2I *) dptr) = val.getPoint2I();
}

//////////////////////////////////////////////////////////////////////////
// TypePoint2F
//////////////////////////////////////////////////////////////////////////
ConsoleType( Point2F, TypePoint2F, sizeof(Point2F) )

ConsoleGetType( TypePoint2F )
{
   Point2F *pt = (Point2F *) dptr;
   return ConsoleValueList::from(pt->x, pt->y);
}

ConsoleSetType( TypePoint2F )
{
   *((Point2F*)dptr) = val.getPoint2F();
}

//////////////////////////////////////////////////////////////////////////
// TypePoint3F
//////////////////////////////////////////////////////////////////////////
ConsoleType( Point3F, TypePoint3F, sizeof(Point3F) )

ConsoleGetType( TypePoint3F )
{
   Point3F *pt = (Point3F *) dptr;
   return ConsoleValueList::from(pt->x, pt->y, pt->z);
}

ConsoleSetType( TypePoint3F )
{
   *((Point3F *) dptr) = val.getPoint3F();
}

//////////////////////////////////////////////////////////////////////////
// TypePoint4F
//////////////////////////////////////////////////////////////////////////
ConsoleType( Point4F, TypePoint4F, sizeof(Point4F) )

ConsoleGetType( TypePoint4F )
{
   Point4F *pt = (Point4F *) dptr;
   return ConsoleValueList::from(pt->x, pt->y, pt->z, pt->w);
}

ConsoleSetType( TypePoint4F )
{
   *((Point4F *) dptr) = val.getPoint4F();
}

//////////////////////////////////////////////////////////////////////////
// TypeRectI
//////////////////////////////////////////////////////////////////////////
ConsoleType( RectI, TypeRectI, sizeof(RectI) )

ConsoleGetType( TypeRectI )
{
   RectI *rect = (RectI *) dptr;
   return ConsoleValueList::from(rect->point.x, rect->point.y, rect->extent.x, rect->extent.y);
}

ConsoleSetType( TypeRectI )
{
   *((RectI*) dptr) = val.getPoint4F();
}

//////////////////////////////////////////////////////////////////////////
// TypeRectF
//////////////////////////////////////////////////////////////////////////
ConsoleType( RectF, TypeRectF, sizeof(RectF) )

ConsoleGetType( TypeRectF )
{
   RectF *rect = (RectF *) dptr;
   return ConsoleValueList::from(rect->point.x, rect->point.y, rect->extent.x, rect->extent.y);
}

ConsoleSetType( TypeRectF )
{
   *((RectF*)dptr) = val.getPoint4F();
}

//////////////////////////////////////////////////////////////////////////
// TypeMatrixPosition
//////////////////////////////////////////////////////////////////////////
ConsoleType( MatrixPosition, TypeMatrixPosition, sizeof(4*sizeof(F32)) )

ConsoleGetType( TypeMatrixPosition )
{
   F32 *col = (F32 *) dptr + 3;
   if(col[12] == 1.f)
      return ConsoleValueList::from(col[0], col[4], col[8]);
   else
      return ConsoleValueList::from(col[0], col[4], col[8], col[12]);
}

ConsoleSetType( TypeMatrixPosition )
{
   F32 *col = ((F32 *) dptr) + 3;
   col[0] = col[4] = col[8] = 0.f; col[12] = 1.f;
   if (!val.isList()) 
      dSscanf(val.toString(), "%g %g %g %g", &col[0], &col[4], &col[8], &col[12]);
   else
   {
      for (S32 i = 0; i < val.getListSizeU(); i++)
         col[i << 2] = val.getListValueDefU(i, i < 4? col[i<<2] : 0.f).getNumber();
   }
   // Con::printf("Matrix position must be set as { x, y, z, w } or \"x y z w\"");
}

//////////////////////////////////////////////////////////////////////////
// TypeMatrixRotation
//////////////////////////////////////////////////////////////////////////
ConsoleType( MatrixRotation, TypeMatrixRotation, sizeof(MatrixF) )

ConsoleGetType( TypeMatrixRotation )
{
   AngAxisF aa(*(MatrixF *) dptr);
   aa.axis.normalize();
   return ConsoleValueList::from(aa.axis.x,aa.axis.y,aa.axis.z,mRadToDeg(aa.angle));
}

ConsoleSetType( TypeMatrixRotation )
{
   // DMM: Note that this will ONLY SET the ULeft 3x3 submatrix.
   //
   AngAxisF aa(Point3F(0,0,0),0);

   if (val.isList()) 
   {
       for (S32 i = 0; i < val.getListSizeU(); i++)
           ((F32*)&aa)[i] = val.getListValueDefU(i, 0.0).getNumber();
       aa.angle = mDegToRad(aa.angle);
   }
   else
   {
       dSscanf(val.toString(), "%g %g %g %g", &aa.axis.x, &aa.axis.y, &aa.axis.z, &aa.angle);
       aa.angle = mDegToRad(aa.angle);
   }
   // Con::printf("Matrix rotation must be set as { x, y, z, angle } or \"x y z angle\"");

   //
   MatrixF temp;
   aa.setMatrix(&temp);

   F32* pDst = *(MatrixF *)dptr;
   const F32* pSrc = temp;
   for (U32 i = 0; i < 3; i++)
      for (U32 j = 0; j < 3; j++)
         pDst[i*4 + j] = pSrc[i*4 + j];
}



//////////////////////////////////////////////////////////////////////////
// TypeBox3F
//////////////////////////////////////////////////////////////////////////
ConsoleType( Box3F, TypeBox3F, sizeof(Box3F) )

ConsoleGetType( TypeBox3F )
{
   const Box3F* pBox = (const Box3F*)dptr;
   return ConsoleValueList::from(
            pBox->min.x, pBox->min.y, pBox->min.z,
            pBox->max.x, pBox->max.y, pBox->max.z);
}

ConsoleSetType( TypeBox3F )
{
   Box3F* pDst = (Box3F*)dptr;
   if (val.isList()) 
   {
      pDst->min.x = val.getListValueDefU(0, 0.0).getNumber();
      pDst->min.y = val.getListValueDefU(1, 0.0).getNumber();
      pDst->min.z = val.getListValueDefU(2, 0.0).getNumber();
      pDst->max.x = val.getListValueDefU(3, 0.0).getNumber();
      pDst->max.y = val.getListValueDefU(4, 0.0).getNumber();
      pDst->max.z = val.getListValueDefU(5, 0.0).getNumber();
   } 
   else 
   {
      U32 args = dSscanf(val.toString(), "%g %g %g %g %g %g",
                         &pDst->min.x, &pDst->min.y, &pDst->min.z,
                         &pDst->max.x, &pDst->max.y, &pDst->max.z);
      AssertWarn(args == 6, "Warning, box probably not read properly");
   }
}


//----------------------------------------------------------------------------

ConsoleFunctionGroupBegin( VectorMath, "Vector manipulation functions.");

ConsoleFunction( VectorAdd, const char*, 3, 3, "(Vector3F a, Vector3F b) Returns a+b.")
{
   VectorF v1 = argv[1].getPoint3F();
   VectorF v2 = argv[2].getPoint3F();
   return ConsoleValueList::from(v1.x+v2.x, v1.y+v2.y, v1.z+v2.z);
}

ConsoleFunction( VectorSub, const char*, 3, 3, "(Vector3F a, Vector3F b) Returns a-b.")
{
   VectorF v1 = argv[1].getPoint3F();
   VectorF v2 = argv[2].getPoint3F();
   return ConsoleValueList::from(v1.x-v2.x, v1.y-v2.y, v1.z-v2.z);
}

ConsoleFunction( VectorScale, const char*, 3, 3, "(Vector3F a, float scalar) Returns a scaled by scalar (ie, a*scalar).")
{
   VectorF v = argv[1].getPoint3F();
   F32 scalar = argv[2].getNumber();
   return ConsoleValueList::from(v.x*scalar,v.y*scalar,v.z*scalar);
}

ConsoleFunction( VectorNormalize, const char*, 2, 2, "(Vector3F a) Returns a scaled such that length(a) = 1.")
{
   VectorF v = argv[1].getPoint3F();
   if (v.len() != 0)
      v.normalize();
   return ConsoleValueList::from(v.x,v.y,v.z);
}

ConsoleFunction( VectorDot, F32, 3, 3, "(Vector3F a, Vector3F b) Calculate the dot product of a and b.")
{
   return mDot(argv[1].getPoint3F(), argv[2].getPoint3F());
}

ConsoleFunction(VectorCross, const char*, 3, 3, "(Vector3F a, Vector3F b) Calculate the cross product of a and b.")
{
   VectorF v;
   mCross(argv[1].getPoint3F(), argv[2].getPoint3F(), &v);
   return ConsoleValueList::from(v.x,v.y,v.z);
}

ConsoleFunction(VectorDist, F32, 3, 3, "(Vector3F a, Vector3F b) Calculate the distance between a and b.")
{
   VectorF v = argv[2].getPoint3F() - argv[1].getPoint3F();
   return mSqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

ConsoleFunction(VectorLen, F32, 2, 2, "(Vector3F v) Calculate the length of a vector.")
{
   VectorF v = argv[1].getPoint3F();
   return v.len();
}

ConsoleFunction(VectorFlip, const char*, 2, 2, "(Vector3F v) Flip a vector (-v).")
{
    VectorF v = -(argv[1].getPoint3F());
    return ConsoleValueList::from(v.x, v.y, v.z);
}

ConsoleFunction( VectorOrthoBasis, const char*, 2, 2, "(AngAxisF aaf) Create an orthogonal basis from the given vector. Return a matrix.")
{
   AngAxisF aa = argv[1].getPoint4F();
   MatrixF mat;
   aa.setMatrix(&mat);
   Point3F col0, col1, col2;
   mat.getColumn(0, &col0);
   mat.getColumn(1, &col1);
   mat.getColumn(2, &col2);
   return ConsoleValueList::from(col0.x, col0.y, col0.z, col1.x, col1.y, col1.z, col2.x, col2.y, col2.z);
}

ConsoleFunctionGroupEnd(VectorMath);

ConsoleFunctionGroupBegin(MatrixMath, "Matrix manipulation functions.");

ConsoleFunction( MatrixIdentity, const char*, 1, 1, "Create an identity matrix (base AA axis is X)" )
{
   AngAxisF aa(Point3F(1.f, 0.f, 0.f), 0.f);
   return ConsoleValueList::from(0.f, 0.f, 0.f, aa.axis.x, aa.axis.y, aa.axis.z, aa.angle);
}

ConsoleFunction( MatrixCreate, const char*, 3, 3, "(Vector3F pos, Vector3F rot) Create a matrix representing the given translation and rotation.")
{
   Point3F pos = argv[1].getPoint3F();
   AngAxisF aa = argv[2].getPoint4F();
   aa.angle = mDegToRad(aa.angle);

   return ConsoleValueList::from(pos.x, pos.y, pos.z, aa.axis.x, aa.axis.y, aa.axis.z, aa.angle);
}

ConsoleFunction( MatrixCreateFromEuler, const char*, 2, 2, "(Vector3F e) Create a matrix from the given rotations.")
{
   EulerF rot = argv[1].getPoint3F();
   QuatF rotQ(rot);
   AngAxisF aa;
   aa.set(rotQ);

   return ConsoleValueList::from(aa.axis.x,aa.axis.y,aa.axis.z,aa.angle);
}


ConsoleFunction( MatrixMultiply, const char*, 3, 3, "(Matrix4F left, Matrix4F right) Multiply the two matrices.")
{
   Point3F pos1;
   AngAxisF aa1(Point3F(0,0,0),0);
   if (argv[1].isList()) {
      pos1 = argv[1].getPoint3F();
      aa1 = argv[1].getPoint4F(3);
   }
   else {
      dSscanf(argv[1].toString(), "%g %g %g %g %g %g %g", &pos1.x, &pos1.y, &pos1.z, &aa1.axis.x, &aa1.axis.y, &aa1.axis.z, &aa1.angle);
   }

   MatrixF temp1(true);
   aa1.setMatrix(&temp1);
   temp1.setColumn(3, pos1);

   Point3F pos2;
   AngAxisF aa2(Point3F(0,0,0),0);
   if (argv[2].isList()) {
      pos2 = argv[2].getPoint3F();
      aa2 = argv[2].getPoint4F(3);
   }
   else {
      dSscanf(argv[2].toString(), "%g %g %g %g %g %g %g", &pos2.x, &pos2.y, &pos2.z, &aa2.axis.x, &aa2.axis.y, &aa2.axis.z, &aa2.angle);
   }

   MatrixF temp2(true);
   aa2.setMatrix(&temp2);
   temp2.setColumn(3, pos2);

   temp1.mul(temp2);
   Point3F pos;
   AngAxisF aa(temp1);
   aa.axis.normalize();
   temp1.getColumn(3, &pos);

   return ConsoleValueList::from(pos.x, pos.y, pos.z, aa.axis.x, aa.axis.y, aa.axis.z, aa.angle);
}


ConsoleFunction( MatrixMulVector, const char*, 3, 3, "(MatrixF xfrm, Point3F vector) Multiply the vector by the transform.")
{
   Point3F pos1;
   AngAxisF aa1(Point3F(0,0,0),0);
   if (argv[1].isList()) {
       pos1 = argv[1].getPoint3F();
       aa1 = argv[1].getPoint4F(3);
   }
   else {
       dSscanf(argv[1].toString(), "%g %g %g %g %g %g %g", &pos1.x, &pos1.y, &pos1.z, &aa1.axis.x, &aa1.axis.y, &aa1.axis.z, &aa1.angle);
   }

   MatrixF temp1(true);
   aa1.setMatrix(&temp1);
   temp1.setColumn(3, pos1);

   Point3F vec1 = argv[2].getPoint3F();

   Point3F result;
   temp1.mulV(vec1, &result);
   return ConsoleValueList::from(result.x, result.y, result.z);
}

ConsoleFunction( MatrixMulPoint, const char*, 3, 3, "(MatrixF xfrm, Point3F pnt) Multiply pnt by xfrm.")
{
   Point3F pos1;
   AngAxisF aa1(Point3F(0,0,0),0);
   if (argv[1].isList()) {
       pos1 = argv[1].getPoint3F();
       aa1 = argv[1].getPoint4F(3);
   }
   else {
       dSscanf(argv[1].toString(), "%g %g %g %g %g %g %g", &pos1.x, &pos1.y, &pos1.z, &aa1.axis.x, &aa1.axis.y, &aa1.axis.z, &aa1.angle);
   }

   MatrixF temp1(true);
   aa1.setMatrix(&temp1);
   temp1.setColumn(3, pos1);

   Point3F vec1 = argv[2].getPoint3F();

   Point3F result;
   temp1.mulP(vec1, &result);
   return ConsoleValueList::from(result.x, result.y, result.z);
}

ConsoleFunctionGroupEnd(MatrixMath);

//------------------------------------------------------------------------------

ConsoleFunctionGroupBegin(PlaneMath, "Plane manipulation functions.");

ConsoleFunction(Plane, const char*, 2, 3, "(Point3F normal, Point3F pos=\"0 0 0\") -> PlaneF")
{
    Point3F n = argv[1].getPoint3F();
    Point3F p;
    if (argc > 2)
        p = argv[2].getPoint3F();
    else
        p.set(0.f, 0.f, 0.f);

    PlaneF plane(p, n);
    return ConsoleValueList::from(plane.x, plane.y, plane.z, plane.d);
}

ConsoleFunction(PlaneDist, F32, 3, 3, "(PlaneF plane, Point3F pt) Get signed distance of pt from plane.")
{
    PlaneF pl = argv[1].getPoint4F();
    Point3F pt = argv[2].getPoint3F();

    return pl.distToPlane(pt);
}

ConsoleFunction(PlaneProject, const char*, 3, 3, "(PlaneF plane, Point3F pt) Project pt on plane.")
{
    PlaneF pl = argv[1].getPoint4F();

    Point3F pt = pl.project(argv[2].getPoint3F());
    return ConsoleValueList::from(pt.x, pt.y, pt.z);
}

ConsoleFunctionGroupEnd(PlaneMath);

//------------------------------------------------------------------------------

ConsoleFunction( getBoxCenter, const char*, 2, 2, "(Box b) Get the center point of a box.")
{
   Box3F box;
   box.min = argv[1].getPoint3F();
   box.max = argv[1].getPoint3F(3);

   Point3F p;
   box.getCenter(&p);
   return ConsoleValueList::from(p.x,p.y,p.z);
}


//------------------------------------------------------------------------------
ConsoleFunctionGroupBegin(RandomNumbers, "Functions relating to the generation of random numbers.");

ConsoleFunction(setRandomSeed, void, 1, 2, "(int seed=-1) Set the current random seed. If no seed is provided, then the current time in ms is used.")
{
	U32 seed = Platform::getRealMilliseconds();
    if (argc == 2)
        seed = argv[1].getInt();
	MRandomLCG::setGlobalRandSeed(seed);
}

ConsoleFunction(getRandomSeed, S32, 1, 1, "Return the current random seed.")
{
   return gRandGen.getSeed();
}

S32 mRandI(S32 i1, S32 i2)
{
   return gRandGen.randI(i1, i2);
}

F32 mRandF(F32 f1, F32 f2)
{
   return gRandGen.randF(f1, f2);
}

ConsoleFunction(getRandom, F32, 1, 3, "(int a=1, int b=0)"
                "Get a random number between a and b.")
{
   if (argc == 2)
      return F32(gRandGen.randI(0,argv[1].getInt()));
   else
   {
      if (argc == 3) {
         S32 min = argv[1].getInt();
         S32 max = argv[2].getInt();
         if (min > max) {
            S32 t = min;
            min = max;
            max = t;
         }
         return F32(gRandGen.randI(min,max));
      }
   }
   return gRandGen.randF();
}

ConsoleFunctionGroupEnd(RandomNumbers);
//------------------------------------------------------------------------------