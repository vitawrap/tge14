//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#ifndef _CLIPPEDPOLYLIST_H_
#define _CLIPPEDPOLYLIST_H_

#ifndef _MMATH_H_
#include "math/mMath.h"
#endif
#ifndef _TVECTOR_H_
#include "core/tVector.h"
#endif
#ifndef _ABSTRACTPOLYLIST_H_
#include "collision/abstractPolyList.h"
#endif


//----------------------------------------------------------------------------
/// Clipped PolyList
///
/// This takes the geometry passed to it and clips against the PlaneList set
/// by the caller.
//
/// @see AbstractPolyList
class ClippedPolyList: public AbstractPolyList
{
   void memcpy(U32* d, U32* s,U32 size);

public:
   struct Vertex {
      Point3F point;
      U32 mask;
   };

   struct Poly {
      PlaneF plane;
      SceneObject* object;
      U32 material;
      U32 vertexStart;
      U32 vertexCount;
      U32 surfaceKey;
   };

   typedef Vector<PlaneF> PlaneList;
   typedef Vector<Vertex> VertexList;
   typedef Vector<Poly> PolyList;
   typedef Vector<U32> IndexList;

   // Internal data
   PolyList   mPolyList;
   VertexList mVertexList;
   IndexList  mIndexList;

   PlaneList mPolyPlaneList;

   // Data set by caller
   PlaneList mPlaneList;
   VectorF mNormal;

   //
   ClippedPolyList();
   ~ClippedPolyList();
   void clear();
   void render();

   // Virtual methods
   bool isEmpty() const;
   U32  addPoint(const Point3F& p);
   U32  addPlane(const PlaneF& plane);
   void begin(U32 material,U32 surfaceKey);
   void plane(U32 v1,U32 v2,U32 v3);
   void plane(const PlaneF& p);
   void plane(const U32 index);
   void vertex(U32 vi);
   void end();

   // Shortcut to set poly clip planes from AABB.
   void setPlanesFrom(Box3F const& box)
   {
       mNormal.set(0, 0, 0);
       mPlaneList.setSize(6);
       mPlaneList[0].set(box.min, VectorF(-1, 0, 0));
       mPlaneList[1].set(box.max, VectorF(0, 1, 0));
       mPlaneList[2].set(box.max, VectorF(1, 0, 0));
       mPlaneList[3].set(box.min, VectorF(0, -1, 0));
       mPlaneList[4].set(box.min, VectorF(0, 0, -1));
       mPlaneList[5].set(box.max, VectorF(0, 0, 1));
   }

  protected:
   const PlaneF& getIndexedPlane(const U32 index);
};


#endif
