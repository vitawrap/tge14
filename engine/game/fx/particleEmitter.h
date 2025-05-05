//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#ifndef _PARTICLEEMITTERDUMMY_H_
#define _PARTICLEEMITTERDUMMY_H_

#ifndef _GAMEBASE_H_
#include "game/gameBase.h"
#endif

class ParticleEmitterData;
class ParticleEmitter;

// -------------------------------------------------------------------------
class ParticleEmitterNodeData : public GameBaseData
{
   typedef GameBaseData Parent;

  protected:
   bool onAdd();

   //-------------------------------------- Console set variables
  public:
   F32 timeMultiple;

   //-------------------------------------- load set variables
  public:

   ParticleEmitterNodeData();
   ~ParticleEmitterNodeData();

   void packData(BitStream*);
   void unpackData(BitStream*);
   bool preload(bool server, char errorBuffer[ErrorBufferSize]);

   DECLARE_CONOBJECT(ParticleEmitterNodeData);
   static void initPersistFields();
};


// -------------------------------------------------------------------------
class ParticleEmitterNode : public GameBase
{
   typedef GameBase Parent;

  private:
   ParticleEmitterNodeData* mDataBlock;

  protected:
   bool onAdd();
   void onRemove();
   bool onNewDataBlock(GameBaseData *dptr);

   ParticleEmitterData* mEmitterDatablock;
   S32                  mEmitterDatablockId;

   ParticleEmitter* mEmitter;
   F32              mVelocity;
   Point3F			mEmitterBox;
   bool             mUseBox;

   void updateBox();

  public:
   ParticleEmitterNode();
   ~ParticleEmitterNode();

   enum EmitterNodeMasks : U64 {
       NodeUpdate = Parent::NextFreeMask,
       NextFreeMask = NodeUpdate << 1
   };

   // Time/Move Management
  public:
   void advanceTime(F32 dt);
   void setEmitterDataBlock(ParticleEmitterData* data);

   DECLARE_CONOBJECT(ParticleEmitterNode);
   static void initPersistFields();

   void onStaticModified(StringTableEntry field) override;

   U64  packUpdate  (NetConnection *conn, U64 mask, BitStream* stream);
   void unpackUpdate(NetConnection *conn,           BitStream* stream);

   virtual void onGroupAdd();
};

#endif // _H_PARTICLEEMISSIONDUMMY

