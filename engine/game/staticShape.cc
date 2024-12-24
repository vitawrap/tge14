//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#include "platform/platform.h"
#include "dgl/dgl.h"
#include "core/dnet.h"
#include "core/bitStream.h"
#include "game/game.h"
#include "math/mMath.h"
#include "console/simBase.h"
#include "console/console.h"
#include "console/consoleTypes.h"
#include "game/moveManager.h"
#include "ts/tsShapeInstance.h"
#include "core/resManager.h"
#include "game/staticShape.h"
#include "math/mathIO.h"
#include "game/shadow.h"

extern void wireCube(F32 size,Point3F pos);

static const U32 sgAllowedDynamicTypes = 0xffffff;

//----------------------------------------------------------------------------

IMPLEMENT_CO_DATABLOCK_V1(StaticShapeData);

StaticShapeData::StaticShapeData()
{
   dynamicTypeField     = 0;

   genericShadowLevel = StaticShape_GenericShadowLevel;
   noShadowLevel = StaticShape_NoShadowLevel;
   noIndividualDamage = false;
}

void StaticShapeData::initPersistFields()
{
   Parent::initPersistFields();

   addField("noIndividualDamage",   TypeBool, Offset(noIndividualDamage,   StaticShapeData));
   addField("dynamicType",          TypeS32,  Offset(dynamicTypeField,     StaticShapeData));
}

void StaticShapeData::packData(BitStream* stream)
{
   Parent::packData(stream);
   stream->writeFlag(noIndividualDamage);
   stream->write(dynamicTypeField);
}

void StaticShapeData::unpackData(BitStream* stream)
{
   Parent::unpackData(stream);
   noIndividualDamage = stream->readFlag();
   stream->read(&dynamicTypeField);
}


//----------------------------------------------------------------------------

IMPLEMENT_CO_NETOBJECT_V1(StaticShape);

StaticShape::StaticShape()
{
   mTypeMask |= StaticShapeObjectType | StaticObjectType;
   mDataBlock = 0;
   mPowered = false;
   mInterpolateTransform = false;
   mLastTickInterpolate = 0.f;
}

StaticShape::~StaticShape()
{
}


//----------------------------------------------------------------------------

bool StaticShape::onAdd()
{
   if(!Parent::onAdd() || !mDataBlock)
      return false;

   // We need to modify our type mask based on what our datablock says...
   mTypeMask |= (mDataBlock->dynamicTypeField & sgAllowedDynamicTypes);

   addToScene();

   if (isServerObject())
      scriptOnAdd();
   return true;
}

bool StaticShape::onNewDataBlock(GameBaseData* dptr)
{
   mDataBlock = dynamic_cast<StaticShapeData*>(dptr);
   if (!mDataBlock || !Parent::onNewDataBlock(dptr))
      return false;

   scriptOnNewDataBlock();
   return true;
}

void StaticShape::onRemove()
{
   scriptOnRemove();
   removeFromScene();
   Parent::onRemove();
}


//----------------------------------------------------------------------------

void StaticShape::processTick(const Move* move)
{
   Parent::processTick(move);

   // Image Triggers
   if (move && mDamageState == Enabled) {
      setImageTriggerState(0,move->trigger[0]);
      setImageTriggerState(1,move->trigger[1]);
   }

   if (isMounted()) {
      MatrixF mat;
      mMount.object->getMountTransform(mMount.node,&mat);
      Parent::setTransform(mat);
      Parent::setRenderTransform(mat);
   }
}

void StaticShape::interpolateTick(F32)
{
   if (isMounted()) {
      MatrixF mat;
      mMount.object->getRenderMountTransform(mMount.node,&mat);
      Parent::setRenderTransform(mat);
   }

   if (mShadow)
   {
      mShadow->setMoving(false);
      if (!mDataBlock->shape.isNull() && mDataBlock->shape->sequences.empty())
         // no sequences, can't animate...
         mShadow->setAnimating(false);
   }
}

void StaticShape::advanceTime(F32 delta) {
   Parent::advanceTime(delta);

   // Very ugly way to interpolate a matrix ahead:
   if (mInterpolateTransform && (mLastTickInterpolate > 0.f)) {
        // value to balance lagging behind on overall smoothness
        delta /= (TickSec * 3.f);

        MatrixF now = getTransform();

        Point3F pos;
        now.getColumn(3, &pos);
        pos += mLinearVelocity * delta;

        QuatF rot(mInitialRotation);
        rot.slerp(QuatF(mTargetTransform), 1.f - mLastTickInterpolate);

        rot.setMatrix(&now);
        now.setColumn(3, pos);

        Parent::setTransform(now);
        Parent::setRenderTransform(now);

        mLastTickInterpolate -= delta;
        if (mLastTickInterpolate < 0.f) {
            Parent::setTransform(mTargetTransform);
            Parent::setRenderTransform(mTargetTransform);
        }
   }
}

void StaticShape::setTransform(const MatrixF& mat)
{
   Parent::setTransform(mat);
   setMaskBits(PositionMask);
}

void StaticShape::onUnmount(ShapeBase*,S32)
{
   // Make sure the client get's the final server pos.
   setMaskBits(PositionMask);
}

void StaticShape::setInterpolate(bool interp)
{
    mInterpolateTransform = interp;
    setMaskBits(InterpMask | PositionMask);
}


//----------------------------------------------------------------------------

U64 StaticShape::packUpdate(NetConnection *connection, U64 mask, BitStream *bstream)
{
   U64 retMask = Parent::packUpdate(connection,mask,bstream);
   if (bstream->writeFlag(mask & InterpMask))
      bstream->writeFlag(mInterpolateTransform);

   if (bstream->writeFlag(mask & PositionMask)) {
      // Backported from T3D, comments hint to better replication using mathWrite.
      mathWrite(*bstream, mObjToWorld);
      mathWrite(*bstream, mObjScale);
   }

   // powered?
   bstream->writeFlag(mPowered);

   return retMask;
}

void StaticShape::unpackUpdate(NetConnection *connection, BitStream *bstream)
{
   Parent::unpackUpdate(connection,bstream);
   if (bstream->readFlag())
      mInterpolateTransform = bstream->readFlag();
   
   if (bstream->readFlag()) {
      MatrixF mat;
      mathRead(*bstream, &mat);
      if (mInterpolateTransform) {
          mLastTickInterpolate = 1.0;
          mTargetTransform = mat;
          mLinearVelocity = mat.getPosition() - getPosition();
          mInitialRotation = QuatF(getTransform());
      }
      else {
          Parent::setTransform(mat);
          Parent::setRenderTransform(mat);
      }

      VectorF scale;
      mathRead(*bstream, &scale);
      setScale(scale);
   }

   // powered?
   mPowered = bstream->readFlag();
}


//----------------------------------------------------------------------------
ConsoleMethod( StaticShape, setPoweredState, void, 3, 3, "(bool isPowered)")
{
   if(!object->isServerObject())
      return;
   object->setPowered(dAtob(argv[2]));
}

ConsoleMethod( StaticShape, getPoweredState, bool, 2, 2, "")
{
   if(!object->isServerObject())
      return(false);
   return(object->isPowered());
}

ConsoleMethod(StaticShape, setInterpolate, void, 3, 3, "(bool interp)")
{
    if (!object->isServerObject())
        return;
    object->setInterpolate(dAtob(argv[2]));
}

ConsoleMethod(StaticShape, isInterpolating, bool, 2, 2, "")
{
    if (!object->isServerObject())
        return(false);
    return(object->isInterpolating());
}
