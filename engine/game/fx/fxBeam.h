//-----------------------------------------------------------------------------
// Torque Game Engine
// Written by viwrap, 19th December 2022.
//-----------------------------------------------------------------------------

#ifndef _FXBEAM_H_
#define _FXBEAM_H_

#ifndef _SPAPEBASE_H_
#include "game/shapeBase.h"
#endif

//------------------------------------------------------------------------------
// Class: fxBeamData
//------------------------------------------------------------------------------
class fxBeamData : public GameBaseData
{
public:
    typedef GameBaseData Parent;

    fxBeamData();

    bool onAdd();
    static void  initPersistFields();
    virtual void packData(BitStream* stream);
    virtual void unpackData(BitStream* stream);
    virtual bool preload(bool server, char errorBuffer[ErrorBufferSize]);

    // Beam texture.
    StringTableEntry mBeamTextureName;
    TextureHandle mBeamTexture;

    // 
    F32 mWidth;     // Beam width
    F32 mHeight;    // Beam height (if finite)
    F32 mTexStretch;// Texture stretch factor along beam
    bool bIsFinite; // If false, it will behave like a laser beam, good for light effects.
    
    ColorF mColor;  // Beam color
    bool bGlow;     // True to perform additive blending, false for premultiplied.

    F32 mScrollSec; // Scrolling units / sec

    DECLARE_CONOBJECT(fxBeamData);
};
DECLARE_CONSOLETYPE(fxBeamData)


//------------------------------------------------------------------------------
// Class: fxBeam
// 
// This fx object is a purely cosmetic oriented quad to be used for any object
// that must look like a railgun beam, a taut rope or chain, a lightshow ray...
// It effectively behaves like a single oriented particle.
// The beam can also be attached to an object on its outer end, this is mostly
// to relieve scripts of attempting to mimick that behavior in a stuttering way.
//------------------------------------------------------------------------------
class fxBeam : public GameBase
{
private:
    typedef GameBase Parent;
    fxBeamData* mDataBlock;
    Point3F mLastObjEndPos;

protected:
    ShapeBase* mAttachedObject;
    U32 mAttachedSlot;
    Point3F mBeamNormal;

    /// Bit masks for different types of events
    enum MaskBits {
        InitialUpdateMask = Parent::NextFreeMask << 0,
        TransformUpdateMask = Parent::NextFreeMask << 1,
        UpdateAttachmentMask = Parent::NextFreeMask << 2
    };

    // *********************************
    // Configuration Interface.
    // *********************************

    void recalculateBeamBox(const Point3F& objEnd, F32 beamWidth);
    //void reset(void);

    // GameBase.
    void processTick(const Move*);
    void interpolateTick(F32 delta);
    void advanceTime(F32);

    // SceneObject
    bool prepRenderImage(SceneState* state, const U32 stateKey, const U32 startZone, const bool modifyBaseZoneState);
    void renderObject(SceneState* state, SceneRenderImage* image);

    // SimObject
    bool onAdd();
    void onRemove();
    void onDeleteNotify(SimObject*);

    void inspectPostApply();

    // NetObject
    U64 packUpdate(NetConnection*, U64, BitStream*);
    void unpackUpdate(NetConnection*, BitStream*);

public:
    fxBeam();
    ~fxBeam();

    // Beam object functions.
    void setDirection(Point3F norm);
    void attachToObject(const char* ObjectName, U32 slot);
    void detachFromObject(void);

    // SceneObject.
    void setTransform(const MatrixF& mat);

    // GameBase.
    bool onNewDataBlock(GameBaseData* dptr);
    // ConObject
    static void initPersistFields();

    // Declare Console Object.
    DECLARE_CONOBJECT(fxBeam);
};

#endif // _FXBEAM_H_