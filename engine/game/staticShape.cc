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
#include "sim/netConnection.h"

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
   collisionTol = 0.1f;
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
   mRelativeTransform.identity();
   mRelativeCollision = true;

   mCollisionList = NULL;
   mConvex.mObject = NULL;
   mConvex.pShapeBase = NULL;
}

StaticShape::~StaticShape()
{
}

void StaticShape::initPersistFields()
{
    Parent::initPersistFields();

    // Transform relative to mTransformParent, not used if the parent is NULL.
    addField("relativePosition", TypeMatrixPosition, Offset(mRelativeTransform, StaticShape));
    addField("relativeRotation", TypeMatrixRotation, Offset(mRelativeTransform, StaticShape));
    addField("relativeCollision", TypeBool, Offset(mRelativeCollision, StaticShape));
}

void StaticShape::onStaticModified(StringTableEntry key)
{
    // tweenable property
    if ((key == StringTable->insert("relativePosition")
        || key == StringTable->insert("relativeRotation")) && mTransformParent)
        setMaskBits(PositionMask);
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
   setMonitorCollisions(false); // free collision stuff
   scriptOnRemove();
   removeFromScene();
   Parent::onRemove();
}


//----------------------------------------------------------------------------

void StaticShape::updateCollisions(F32 dt)
{
    AssertFatal(mCollisionList, "Collision list must exist when a StaticShape updates collisions!");

    // Update working list
    // (This does no effort at inflating the box from predicted movement yet, might act erratic!)
    Box3F convexBox = mConvex.getBoundingBox(getTransform(), getScale());
    disableCollision();
    mConvex.updateWorkingList(convexBox, STATIC_COLLISION_MASK);
    enableCollision();

    // Update collision information
    MatrixF mat = getTransform();
    MatrixF cmat;
    mConvex.transform = &mat;
    cmat = mConvex.getTransform();

    mCollisionList->count = 0;
    CollisionState* state = mConvex.findClosestState(cmat, getScale(), mDataBlock->collisionTol);
    if (state && state->dist <= mDataBlock->collisionTol) {
        mConvex.getCollisionInfo(cmat, getScale(), mCollisionList, mDataBlock->collisionTol);
    }

    // Now resolve collisions we care about
    CollisionList& cList = *mCollisionList;
    for (S32 i = 0; i < cList.count; i++) {
        Collision& c = cList.collision[i];

        // Skip static shapes attached to us (or sharing the same parent, if any)
        if (c.object->getTypeMask() & StaticShapeObjectType) {
            StaticShape* col = static_cast<StaticShape*>(c.object);
            if (!col->collidesWithParent() && (col->getTransformParent() == this ||
                (col->getTransformParent() == getTransformParent() && getTransformParent()))) {
                cList.removeCollision(i--);
                continue;
            }
        }

        if (c.distance < mDataBlock->collisionTol) {
            // Keep track of objects we collide with
            if (!isGhost() && c.object->getTypeMask() & ShapeBaseObjectType) {
                ShapeBase* col = static_cast<ShapeBase*>(c.object);
                queueCollision(col, col->getVelocity());
            }
        }
    }
}

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
   else if (mTransformParent) {
      MatrixF mat;
      mat.mul(mTransformParent->getTransform(), mRelativeTransform);
      Parent::setTransform(mat);
      Parent::setRenderTransform(mat);
   }
   if (mCollisionList)
       updateCollisions(TickSec);
}

void StaticShape::interpolateTick(F32)
{
   if (isMounted()) {
      MatrixF mat;
      mMount.object->getRenderMountTransform(mMount.node,&mat);
      Parent::setRenderTransform(mat);
   }
   else if (mTransformParent) {
      MatrixF mat;
      mat.mul(mTransformParent->getRenderTransform(), mRelativeTransform);
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

   bool relative = mTransformParent;

   // Very ugly way to interpolate a matrix ahead:
   if (mInterpolateTransform && (mLastTickInterpolate > 0.f)) {
        // value to balance lagging behind on overall smoothness
        delta /= (TickSec * 3.f);

        // minimize branching...
        if (relative) {
            MatrixF now = mRelativeTransform;

            Point3F pos;
            now.getColumn(3, &pos);
            pos += mLinearVelocity * delta;
            QuatF rot(mInitialRotation);
            rot.slerp(QuatF(mTargetTransform), 1.f - mLastTickInterpolate);
            rot.setMatrix(&now);
            now.setColumn(3, pos);

            mRelativeTransform = now;

            mLastTickInterpolate -= delta;
            if (mLastTickInterpolate < 0.f)
                mRelativeTransform = mTargetTransform;
        }
        else {
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

void StaticShape::setTransformParent(ShapeBase* shape)
{
    if (!isGhost()) {
        mTransformParent = shape;
        if (mTransformParent && !mTransformParent->isGhostAlways())
            mTransformParent->setScopeAlways();
        setMaskBits(XParentMask | PositionMask);
        if (shape)
            processAfter(shape);
    }
}

void StaticShape::setMonitorCollisions(bool monitor)
{
    if (monitor) {
        if (!isGhost() && mDataBlock && mDataBlock->collisionDetails[0] != -1) {
            mConvex.mObject = this;
            mConvex.pShapeBase = this;
            mConvex.hullId = 0;
            mConvex.box = mObjBox;
            mConvex.box.min.convolve(mObjScale);
            mConvex.box.max.convolve(mObjScale);
            mConvex.findNodeTransform();
            if (!mCollisionList)
                mCollisionList = new CollisionList();
        }
    }
    else {
        delete mCollisionList;
        mConvex.nukeList();
        mConvex.mObject = NULL;
        mConvex.pShapeBase = NULL;
    }
}

//----------------------------------------------------------------------------

U64 StaticShape::packUpdate(NetConnection *con, U64 mask, BitStream *bstream)
{
   U64 retMask = Parent::packUpdate(con,mask,bstream);
   if (bstream->writeFlag(mask & InterpMask))
      bstream->writeFlag(mInterpolateTransform);

   if (bstream->writeFlag(mask & XParentMask)) {
       if (bool(mTransformParent))
       {
           // Potentially have to write this to the client, let's make sure it has a
           //  ghost on the other side...
           S32 ghostIndex = con->getGhostIndex(mTransformParent);
           if (bstream->writeFlag(ghostIndex != -1))
               bstream->writeRangedU32(U32(ghostIndex), 0, NetConnection::MaxGhostCount);
           else // havn't recieved the ghost for the source object yet, try again later
               retMask |= XParentMask;
       }
       else
           bstream->writeFlag(false);
   }

   if (bstream->writeFlag(mask & PositionMask)) {
      // Backported from T3D, comments hint to better replication using mathWrite.
      mathWrite(*bstream, bstream->writeFlag(mTransformParent)? mRelativeTransform : mObjToWorld);
      mathWrite(*bstream, mObjScale);

      // Here until I find a better way
      bstream->writeFlag(mRelativeCollision);
   }

   // powered?
   bstream->writeFlag(mPowered);

   return retMask;
}

void StaticShape::unpackUpdate(NetConnection *con, BitStream *bstream)
{
   Parent::unpackUpdate(con,bstream);
   if (bstream->readFlag())
      mInterpolateTransform = bstream->readFlag();
   
   if (bstream->readFlag()) {
       if (bstream->readFlag()) {
           U32 sId = bstream->readRangedU32(0, NetConnection::MaxGhostCount);

           NetObject* pObject = con->resolveGhost(sId);
           if (pObject != NULL)
               mTransformParent = dynamic_cast<ShapeBase*>(pObject);
       }
       else
           mTransformParent = NULL;
   }

   if (bstream->readFlag()) {
      bool relative = bstream->readFlag();

      MatrixF mat;
      mathRead(*bstream, &mat);
      if (mInterpolateTransform) {
          MatrixF& last = relative ? mRelativeTransform : mObjToWorld;
          mLastTickInterpolate = 1.0;
          mTargetTransform = mat;
          mLinearVelocity = mat.getPosition() - last.getPosition();
          mInitialRotation = QuatF(last);
      }
      else {
          if (relative)
              mRelativeTransform = mat;
          else {
              Parent::setTransform(mat);
              Parent::setRenderTransform(mat);
          }
      }

      VectorF scale;
      mathRead(*bstream, &scale);
      setScale(scale);

      // Here until I find a better way
      mRelativeCollision = bstream->readFlag();
   }

   // powered?
   mPowered = bstream->readFlag();
}


//----------------------------------------------------------------------------
ConsoleMethod( StaticShape, setPoweredState, void, 3, 3, "(bool isPowered)")
{
   if(!object->isServerObject())
      return;
   object->setPowered(argv[2].getInt());
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
    object->setInterpolate(argv[2].getInt());
}

ConsoleMethod(StaticShape, isInterpolating, bool, 2, 2, "")
{
    if (!object->isServerObject())
        return(false);
    return(object->isInterpolating());
}

ConsoleMethod(StaticShape, setParent, void, 3, 3, "(simObject parent) - set transform parent")
{
    if (!object->isServerObject())
        return;
    ShapeBase* obj = NULL;
    Sim::findObject(argv[2], obj);
    object->setTransformParent(obj);    // allow NULL, to detach.
}

ConsoleMethod(StaticShape, getParent, bool, 2, 2, "get transform parent")
{
    ShapeBase* parent = object->getTransformParent();
    return S64( parent? parent->getId() : 0 );
}

ConsoleMethod(StaticShape, setMonitorCollisions, void, 3, 3, "(bool monitor) - make this shape respond to collisions")
{
    object->setMonitorCollisions(argv[2].getInt());
}

ConsoleMethod(StaticShape, isMonitoringCollisions, bool, 2, 2, "() - is this shape responding to collisions?")
{
    return object->isMonitoringCollisions();
}
