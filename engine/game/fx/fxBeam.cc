//-----------------------------------------------------------------------------
// Torque Game Engine
// Written by viwrap, 19th December 2022.
//-----------------------------------------------------------------------------

#include "dgl/dgl.h"
#include "console/consoleTypes.h"
#include "core/bitStream.h"
#include "math/mRandom.h"
#include "math/mathIO.h"
#include "terrain/terrData.h"
#include "game/gameConnection.h"
#include "console/simBase.h"
#include "sceneGraph/sceneGraph.h"
#include "editor/editor.h"
#include "fxBeam.h"

IMPLEMENT_CO_DATABLOCK_V1(fxBeamData);
IMPLEMENT_CONSOLETYPE(fxBeamData);
IMPLEMENT_SETDATATYPE(fxBeamData);
IMPLEMENT_GETDATATYPE(fxBeamData);

fxBeamData::fxBeamData()
{
    mBeamTexture = 0;
    mBeamTextureName = NULL;

    mWidth = 1.f;
    mHeight = 1.f;
    bIsFinite = true;
    mScrollSec = 0.f;
    mColor.set(1.f, 1.f, 1.f);
    bGlow = true;
    mTexStretch = 1.f;
}

bool fxBeamData::onAdd()
{
    if (Parent::onAdd() == false)
        return false;

    return true;
}

void fxBeamData::initPersistFields()
{
    Parent::initPersistFields();

    addGroup("Media");
    addField("texture", TypeFilename, Offset(mBeamTextureName, fxBeamData));
    endGroup("Media");

    addGroup("Beam");
    addField("width", TypeF32, Offset(mWidth, fxBeamData));
    addField("height", TypeF32, Offset(mHeight, fxBeamData));
    addField("texStretch", TypeF32, Offset(mTexStretch, fxBeamData));
    addField("isFinite", TypeBool, Offset(bIsFinite, fxBeamData));
    addField("scrollSec", TypeF32, Offset(mScrollSec, fxBeamData));
    addField("color", TypeColorF, Offset(mColor, fxBeamData));
    addField("glow", TypeBool, Offset(bGlow, fxBeamData));
    endGroup("Beam");
}

void fxBeamData::packData(BitStream* stream)
{
    Parent::packData(stream);
    stream->writeString(mBeamTextureName);
}

void fxBeamData::unpackData(BitStream* stream)
{
    Parent::unpackData(stream);
    mBeamTextureName = stream->readSTString();
}

bool fxBeamData::preload(bool server, char errorBuffer[ErrorBufferSize])
{
    if (!Parent::preload(server, errorBuffer))
        return false;

    // TODO: Figure out if not checking for !server is bad?
    mBeamTexture = TextureHandle(mBeamTextureName, MeshTexture);
    if (!mBeamTexture.getName())
    {
        dSprintf(errorBuffer, ErrorBufferSize, "Missing beam texture: %s", mBeamTextureName);
        return false;
    }

    return true;
}


IMPLEMENT_CO_NETOBJECT_V1(fxBeam);

void fxBeam::initPersistFields()
{
    Parent::initPersistFields();

    //addField("direction", TypePoint3F, Offset(mBeamNormal, fxBeam));
}

fxBeam::fxBeam()
{
    //mTypeMask |= GameBaseObjectType;
    mNetFlags.set(Ghostable);

    mDataBlock      = NULL;
    mBeamNormal.set(0.f, 1.f, 0.f);
    mLastObjEndPos.set(0.f, 0.f, 0.f);
    
    mAttachedObject = NULL;
    mAttachedSlot = 0;
}

fxBeam::~fxBeam()
{

}

bool fxBeam::onAdd()
{
    if (!Parent::onAdd())
        return false;

    // Set Default Object Box.
    mObjBox.min.set(-0.5, -0.5, -0.5);
    mObjBox.max.set(0.5, 0.5, 0.5);

    // Reset the World Box.
    resetWorldBox();

    // Yes, so set the Render Transform.
    setRenderTransform(mObjToWorld);

    // Add to Scene.
    addToScene();

    // If we are in the editor and we are on the client then
    // we can manually startup replication.
    //if (isClientObject())

    // Renew shapes on Server.
    //if (isServerObject())

    return true;
}

void fxBeam::onRemove()
{
    // Yes, so remove from Scene.
    removeFromScene();

    // Destroy stuff.
    //

    // Do Parent.
    Parent::onRemove();
}

void fxBeam::inspectPostApply()
{
    // Set Parent.
    Parent::inspectPostApply();

    // Renew.
    //RenewShapes();

    // Set Replication Mask.
    if (isServerObject())
        setMaskBits(~0);
}

U64 fxBeam::packUpdate(NetConnection* conn, U64 mask, BitStream* stream)
{
    U64 retMask = Parent::packUpdate(conn, mask, stream);
    
    if (stream->writeFlag(mask & InitialUpdateMask))
    {

    }

    if (stream->writeFlag(mask & TransformUpdateMask))
    {
        mathWrite(*stream, mBeamNormal);
        stream->writeAffineTransform(mObjToWorld);
    }

    if (stream->writeFlag(mask & UpdateAttachmentMask))
    {
        // Get the GhostID of the object.
        S32 GhostID = mAttachedObject? conn->getGhostIndex(mAttachedObject) : -1;
        if (stream->writeFlag( mAttachedObject && (GhostID != -1) ))
        {
            // Send it to the client.
            stream->writeRangedU32(U32(GhostID), 0, NetConnection::MaxGhostCount);
            stream->writeRangedU32(mAttachedSlot, 0, ShapeBase::MaxMountedImages);
        }
    }

    return retMask;
}

void fxBeam::unpackUpdate(NetConnection* conn, BitStream* stream)
{
    Parent::unpackUpdate(conn, stream);

    if (stream->readFlag())
    { }

    if (stream->readFlag())
    {
        mathRead(*stream, &mBeamNormal);
        
        MatrixF objToWorld;
        stream->readAffineTransform(&objToWorld);
        setTransform(objToWorld);
    }

    if (stream->readFlag()) // UpdateAttachmentMask
    {
        if (stream->readFlag()) // mAttachedObject && (GhostID != -1)
        {
            // Resolve the GhostID from the server. (cannot be -1)
            S32 GhostID = stream->readRangedU32(0, NetConnection::MaxGhostCount);

            NetObject* obj = NULL;
            obj = conn->resolveGhost(GhostID);
            mAttachedObject = dynamic_cast<ShapeBase*>(obj);
            mAttachedSlot = stream->readRangedU32(0, ShapeBase::MaxMountedImages);
        } else
            mAttachedObject = NULL;
    }
}

void fxBeam::setTransform(const MatrixF& mat)
{
    Parent::setTransform(mat);

    if (isServerObject())
        setMaskBits(TransformUpdateMask);
}

bool fxBeam::onNewDataBlock(GameBaseData* dptr)
{
    mDataBlock = dynamic_cast<fxBeamData*>(dptr);
    if (!mDataBlock || !Parent::onNewDataBlock(dptr))
        return false;

    scriptOnNewDataBlock();
    return true;
}

void fxBeam::onDeleteNotify(SimObject* Obj)
{
    // Server?
    if (isServerObject())
    {
        // Yes, so detach the server way!
        detachFromObject();
    }
    else
    {
        // No, so do it manually (if needed).
        if (mAttachedObject) 
            clearNotify(mAttachedObject);

        // Store it happening.
        mAttachedObject = NULL;
    }

    // Do Parent.
    Parent::onDeleteNotify(Obj);
}

void fxBeam::attachToObject(const char* ObjectName, U32 slot)
{
    // Find the Selected Object.
    ShapeBase* Obj = dynamic_cast<ShapeBase*>(Sim::findObject(ObjectName));

    // Check we found it.
    if (!Obj)
    {
        Con::warnf("Couldn't find %s object to attach to!", ObjectName);
        return;
    }

    // If the object has a name then output attachment.
    //if (getName()) Con::printf("%s attached to object %s.", getName(), ObjectName);

    // set-up dependency.
    processAfter(Obj);

    // Make sure we know if it's deleted.
    deleteNotify(Obj);

    // Update our values
    mAttachedObject = Obj;
    mAttachedSlot = slot;

    // Set Config Change Mask.
    if (isServerObject()) setMaskBits(UpdateAttachmentMask);
}

void fxBeam::detachFromObject(void)
{
    // Return if nothing to do!
    if (!getProcessAfter()) return;

    // If the object has a name then output detachment.
    //if (getName()) Con::printf("%s detached from object %s.", getName(), getProcessAfter()->getName());

    // Don't need delete notification now.
    clearNotify(getProcessAfter());

    // Clear dependency.
    clearProcessAfter();

    // Clear our value
    mAttachedObject = NULL;

    // Set Config Change Mask.
    if (isServerObject())
    {
        // Signal Attach is no invalid.
        //mAttachValid = false;
        // Tell the client it's all over.
        setMaskBits(UpdateAttachmentMask);
    }
}

void fxBeam::processTick(const Move* move)
{
    Parent::processTick(move);
}

void fxBeam::interpolateTick(F32 delta)
{
    Parent::interpolateTick(delta);
}

void fxBeam::advanceTime(F32)
{
    Point3F pos;
    Point3F dir = mBeamNormal;
    MatrixF RXF = getTransform();
    RXF.getColumn(3, &pos);
    dglMultMatrix(&RXF);

    F32 width = mDataBlock->mWidth * .5f;

    Point3F end;
    // TODO: Move this elsewhere, ideally in processTick to act in the server instead?
    if (mAttachedObject)
    {
        MatrixF mx;
        Point3F mp;
        mAttachedObject->getMountTransform(mAttachedSlot, &mx);
        mx.getColumn(3, &mp);
        end = mp - pos;
    }
    else
    {
        RayInfo out;
        end = dir * 2000.f;
        if (gClientContainer.castRay(pos, pos + end, TerrainObjectType | InteriorObjectType | GameBaseObjectType, &out))
        {
            end = out.point - pos;  // Into local coordinates
        }
    }
    recalculateBeamBox(end, width);
    mLastObjEndPos = end;
}

bool fxBeam::prepRenderImage(SceneState* state, const U32 stateKey, const U32 startZone,
    const bool modifyBaseZoneState)
{
    // Return if last state.
    if (isLastState(state, stateKey)) return false;
    // Set Last State.
    setLastState(state, stateKey);

    // Is Object Rendered?
    if (state->isObjectRendered(this))
    {
        // Yes, so get a SceneRenderImage.
        SceneRenderImage* image = new SceneRenderImage;
        // Populate it.
        image->obj = this;
        image->isTranslucent = true;
        image->sortType = SceneRenderImage::EndSort;
        state->setImageRefPoint(this, image);
        // Insert it into the scene images.
        state->insertRenderImage(image);
    }

    return false;
}

void fxBeam::recalculateBeamBox(const Point3F& objPt, F32 beamWidth)
{
    beamWidth *= .5f;
    Point3F thickness(beamWidth, beamWidth, beamWidth);

    mObjBox.min.set(0.f, 0.f, 0.f);
    mObjBox.max.set(0.f, 0.f, 0.f);
    mObjBox.intersect(objPt);
    mObjBox.min -= thickness;
    mObjBox.max += thickness;

    resetWorldBox();
    setRenderTransform(mObjToWorld);
}

void fxBeam::renderObject(SceneState* state, SceneRenderImage* image)
{
    // Check we have received Canonical State.
    AssertFatal(dglIsInCanonicalState(), "Error, GL not in canonical state on entry");

    // Scroll offset
    F32 scroll = 0.f;
    if (mDataBlock->mScrollSec > 0.f)
        scroll = F32(Platform::getVirtualMilliseconds()) * 0.001f * mDataBlock->mScrollSec;

    MatrixF RXF;
    Point3F pos;

    // Screen Viewport.
    RectI viewport;

    // Setup out the Projection Matrix/Viewport.
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    dglGetViewport(&viewport);
    state->setupBaseProjection();
    glPushMatrix();

    // Get Object Transform.
    RXF = getTransform();
    RXF.getColumn(3, &pos);
    dglMultMatrix(&RXF);

    // Compute beam billboard and color.
    Point3F dir = mBeamNormal;
    if (mAttachedObject)
    {
        dir = mLastObjEndPos;
        dir.normalize();
    }
    Point3F camPos = state->getCameraPosition();

    Point3F dirFromCam = pos - camPos;
    Point3F crossDir;
    mCross(dirFromCam, dir, &crossDir);
    crossDir.normalize();
    dir.normalize();

    F32 width = mDataBlock->mWidth * .5f;

    dir *= width;
    crossDir *= width;
    Point3F start(0.f, 0.f, 0.f);
    Point3F end = mDataBlock->bIsFinite && !mAttachedObject ? dir * mDataBlock->mHeight : mLastObjEndPos;
    F32 texT = (end.len() * (1.f / width) * .5f) / mDataBlock->mTexStretch;

    GLenum blendMode;
    ColorF col = mDataBlock->mColor;
    if (mDataBlock->bGlow)
    {
        blendMode = GL_ONE;
    } else {
        blendMode = GL_ONE_MINUS_SRC_ALPHA;
        ColorF amb;
        if (getLightingAmbientColor(&amb))
            col *= amb;
    }
    
    // Draw Oriented Billboard.
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D, mDataBlock->mBeamTexture.getGLName());
    glBlendFunc(GL_SRC_ALPHA, blendMode);
    glColor4fv(col);
    glBegin(GL_QUADS);
        glTexCoord2f(-scroll, 1);
        glVertex3fv(start + crossDir);
        glTexCoord2f(-scroll, 0);
        glVertex3fv(start - crossDir);
        glTexCoord2f(texT - scroll, 0);
        glVertex3fv(end - crossDir);
        glTexCoord2f(texT - scroll, 1);
        glVertex3fv(end + crossDir);
    glEnd();

    // Restore canonical matrices
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    dglSetViewport(viewport);

    // Check we have restored Canonical State.
    AssertFatal(dglIsInCanonicalState(), "Error, GL not in canonical state on exit");
}

void fxBeam::setDirection(Point3F norm)
{
    norm.normalizeSafe();
    mBeamNormal = norm;

    if (isServerObject())
        setMaskBits(TransformUpdateMask);
}

ConsoleMethod(fxBeam, setDirection, void, 3, 3, "(normal) - set direction for beam (auto normalized)")
{
    object->setDirection(argv[2].getPoint3F());
}

ConsoleMethod(fxBeam, attachToObject, void, 3, 4, "(shapeBaseIdOrName [, mountSlot]) - aim beam at object")
{
    U32 slot = (argc > 3) ? argv[3].getInt() : 0;
    object->attachToObject(argv[2].toString(), slot);
}

ConsoleMethod(fxBeam, detachFromObject, void, 2, 2, "() - remove from attached object")
{
    object->detachFromObject();
}