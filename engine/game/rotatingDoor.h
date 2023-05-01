#ifndef _ROTATING_DOOR_H_
#define _ROTATING_DOOR_H_

#ifndef _GAMEBASE_H_
#include "game/gameBase.h"
#endif
#ifndef _SHAPEBASE_H_
#include "game/shapeBase.h"
#endif
#ifndef _BOXCONVEX_H_
#include "collision/boxConvex.h"
#endif
#ifndef _PLATFORMAUDIO_H_
#include "platform/platformAudio.h"
#endif

#include "game/fx/particleEmitter.h"

class RotatingDoorData : public ShapeBaseData {
private:
    typedef ShapeBaseData Parent;

public:
    enum Sounds {
        Toggle = 0,     // After validating opening or closing
        Moving,         // Moving (loop recommended)
        Closed,         // Door snaps closed    (stops Sounds::Moving)
        Opened,         // Door snaps open      (stops Sounds::Moving)
        Halted,         // When the door collides with a prop
        MaxDoorSounds
    };

    //// Rotation origin point
    //Point3F mRotationOrigin;
    //// Axis angle rotation (radians)
    //Point4F mRotationAngleAxis;

    // Holds origin and rotation data
    MatrixF mRotationTransform;

    // Sounds
    AudioProfile* mSounds[MaxDoorSounds];

    // Whether the door opens one way or both
    bool mOpenOneWay;
    // Delay before actually moving after opening
    F32 mSecBeforeMoving;
    // How long a full rotation should last
    F32 mSecRotationTime;

    // Stop the door if it collides with something
    bool mBlockOnCollision;
    // Do we spawn particles when colliding? (on collision point)
    bool mSpawnParticlesOnCollision;
    // Mask of object types to ignore if collision testing is enabled
    U32 mCollisionIgnoreMask;
    // Collision particles if they're enabled
    ParticleEmitterData* mCollisionEmitter;
    S32 mCollisionEmitterID;

    DECLARE_CONOBJECT(RotatingDoorData);
    RotatingDoorData();
    ~RotatingDoorData();
    bool onAdd();
    bool preload(bool server, char errorBuffer[ErrorBufferSize]);
    static void initPersistFields();
    virtual void packData(BitStream* stream);
    virtual void unpackData(BitStream* stream);
};
DECLARE_CONSOLETYPE(RotatingDoorData)

// ShapeBase is so complex...
// There is a lot of features to remove
// to end up with simple doors.
class RotatingDoor : public ShapeBase {
private:
    typedef ShapeBase Parent;
    RotatingDoorData* mDataBlock;

    MatrixF     mConvexTransform;
    Box3F       mBoundingBox;
    // Inherited

    bool mLocked;

    // Simulation state
    F32 mDirection;
    F32 mComplRatio;
    F32 mRevTimeSec;       // Time spent rotating
    F32 mMaxAngleRad;

    // Client-only sound handle
    AUDIOHANDLE mMovingSoundHandle;

    void resetSimValues();
    void advanceState(F32 dt);
    void setAngleTransformed(F32 openAngle);
    
    void scriptOnOpened();
    void scriptOnClosed();

    enum MaskBits : U64 {
        PositionMask= (U64)Parent::NextFreeMask,
        ToggleOpen  = (U64)Parent::NextFreeMask << 1,
        ToggleClose = (U64)Parent::NextFreeMask << 2,
        NotifySync  = (U64)Parent::NextFreeMask << 4,    // Forced client state if lag
        NotifyHalt  = (U64)Parent::NextFreeMask << 5,    // Forced client state
        NextFreeMask= (U64)Parent::NextFreeMask << 6
    };

public:
    enum class DoorState {
        Closed,
        PrepClose,
        Closing,
        Opened,
        PrepOpen,
        Opening,
        PrepHalted,
        Halted,
        DoorStateCount
    };

    enum DoorNetConstants {
        MoveDirPrecision = 4
    };

private:
    DoorState mDoorState;
    DoorState mPrevState;
    void setForcedClientState(DoorState state);

public:
    DECLARE_CONOBJECT(RotatingDoor);
    static void initPersistFields();
    void inspectPostApply();

    RotatingDoor();
    virtual bool onAdd() override;
    virtual void onRemove() override;

    virtual bool onNewDataBlock(GameBaseData* dptr) override;

    virtual void processTick(const Move*) override;
    virtual void interpolateTick(F32 delta) override;
    virtual void advanceTime(F32 dt) override;
    virtual void setTransform(const MatrixF& mat) override;
    virtual void buildConvex(const Box3F& box, Convex* convex) override;

    virtual U64  packUpdate(NetConnection* conn, U64 mask, BitStream* stream) override;
    virtual void unpackUpdate(NetConnection* conn, BitStream* stream) override;

    // Door methods
    bool canCollideWith(SceneObject* obj);
    void setLock(bool state);
    void requestOpen(SceneObject* activator);
    void open(SceneObject* activator);
    void close();
    void setNetState(DoorState newState);  // Server state of door object

    bool getLock() const;
    DoorState getState() const;
};

#endif // --!_ROTATING_DOOR_H_