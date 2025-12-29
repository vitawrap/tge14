//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#ifndef _STATICSHAPE_H_
#define _STATICSHAPE_H_

#ifndef _SHAPEBASE_H_
#include "game/shapeBase.h"
#endif

//----------------------------------------------------------------------------

struct StaticShapeData: public ShapeBaseData {
   typedef ShapeBaseData Parent;

  public:
   StaticShapeData();

   bool  noIndividualDamage;
   S32   dynamicTypeField;
   bool  isShielded;
   F32   energyPerDamagePoint;
   F32   collisionTol;

   //
   DECLARE_CONOBJECT(StaticShapeData);
   static void initPersistFields();
   virtual void packData(BitStream* stream);
   virtual void unpackData(BitStream* stream);
};


//----------------------------------------------------------------------------

class StaticShape: public ShapeBase
{
   typedef ShapeBase Parent;

   bool              mPowered;
   bool              mRelativeCollision;        ///< Collide with parent?
   bool              mInterpolateTransform;     ///< Smoothen movement?

   StaticShapeData*  mDataBlock;

   SimObjectPtr<ShapeBase> mTransformParent;
   MatrixF           mRelativeTransform;

   F32               mLastTickInterpolate;
   MatrixF           mTargetTransform;
   QuatF             mInitialRotation;
   Point3F           mLinearVelocity;

   ShapeBaseConvex   mConvex;                  ///< Enabled only when monitoring collisions.
   CollisionList*    mCollisionList;           ///< Not all static shapes need this.

   void onUnmount(ShapeBase* obj,S32 node);
   void updateCollisions(F32 dt);

  protected:
   enum MaskBits : U64 {
      PositionMask = Parent::NextFreeMask,
      XParentMask  = Parent::NextFreeMask << 1,
      InterpMask   = Parent::NextFreeMask << 2,
      NextFreeMask = Parent::NextFreeMask << 3
   };

public:
   DECLARE_CONOBJECT(StaticShape);
   static void initPersistFields();

   void onStaticModified(StringTableEntry key) override;

   StaticShape();
   ~StaticShape();

   bool onAdd();
   void onRemove();
   bool onNewDataBlock(GameBaseData* dptr);

   void processTick(const Move *move);
   void interpolateTick(F32 delta);
   void advanceTime(F32 delta) override;
   void setTransform(const MatrixF &mat);

   U64  packUpdate  (NetConnection *conn, U64 mask, BitStream *stream);
   void unpackUpdate(NetConnection *conn,           BitStream *stream);

   // power
   void setPowered(bool power)      {mPowered = power;}
   bool isPowered() const           {return(mPowered);}

   // interpolate
   void setInterpolate(bool interp);
   bool isInterpolating() const     { return mInterpolateTransform; }

   // transform parent
   void setTransformParent(ShapeBase*);
   ShapeBase* getTransformParent() const { return mTransformParent; }

   bool collidesWithParent() const { return mRelativeCollision; }

   void setMonitorCollisions(bool monitor);
   bool isMonitoringCollisions() const { return !!mCollisionList; }
};


#endif
