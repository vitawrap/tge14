
#include "dgl/dgl.h"
#include "sceneGraph/detailManager.h"
#include "math/mathIO.h"
#include "game/gameConnection.h"
#include "audio/audioDataBlock.h"
#include "fx/particleEngine.h"
#include "game/rotatingDoor.h"
#include "collision/boxConvex.h"
#include "collision/earlyOutPolyList.h"
#include "console/consoleTypes.h"

IMPLEMENT_CO_DATABLOCK_V1(RotatingDoorData);
IMPLEMENT_CO_NETOBJECT_V1(RotatingDoor);

const U32 sDoorCollisionMask =	(	StaticShapeObjectType | VehicleObjectType |
									PlayerObjectType | StaticTSObjectType	);

RotatingDoorData::RotatingDoorData()
{ 
	//mRotationAngleAxis.set(0.1f, 0.0f, 0.f, 0.f);
	//mRotationOrigin.set(0.f, 0.5f, 0.f);

	mRotationTransform.identity();
	MatrixF rot;
	rot.set(EulerF(0.f, 0.f, 90.f));
	mRotationTransform = rot.mul(mRotationTransform);
	mRotationTransform.setPosition(Point3F(0.8f, 0.f, 0.f));

	for (S32 i = 0; i < MaxDoorSounds; i++)
		mSounds[i] = NULL;

	mOpenOneWay = false;
	mSecBeforeMoving = 0;
	mSecRotationTime = 1.5f;

	mBlockOnCollision = true;
	mCollisionIgnoreMask = STATIC_COLLISION_MASK;
	mCollisionEmitter = NULL;
	mCollisionEmitterID = 0;
	mSpawnParticlesOnCollision = false;
}

RotatingDoorData::~RotatingDoorData()
{

}

bool RotatingDoorData::onAdd()
{
	if (!Parent::onAdd())
		return false;
	return true;
}

bool RotatingDoorData::preload(bool server, char errorBuffer[ErrorBufferSize])
{
	if (!Parent::preload(server, errorBuffer))
		return false;

	// Resolve objects transmitted from server
	if (!server) {
		for (S32 i = 0; i < MaxDoorSounds; i++)
			if (mSounds[i])
				// Hack to resolve sim addresses from temp id store
				Sim::findObject(SimObjectId(mSounds[i]), mSounds[i]);

		if (mSpawnParticlesOnCollision && !Sim::findObject(mCollisionEmitterID, mCollisionEmitter)) {
			dStrcpy(errorBuffer, "Invalid particle emitter for RotatingDoorData");
			return false;
		}
	}
	return true;
}

void RotatingDoorData::packData(BitStream* stream)
{
	Parent::packData(stream);

	//mathWrite(*stream, mRotationAngleAxis);
	//mathWrite(*stream, mRotationOrigin);
	mathWrite(*stream, mRotationTransform);

	S32 i;
	for (i = 0; i < MaxDoorSounds; i++)
		if (stream->writeFlag(mSounds[i]))
			stream->writeRangedU32(packed ? SimObjectId(mSounds[i]) :
				mSounds[i]->getId(), DataBlockObjectIdFirst, DataBlockObjectIdLast);

	stream->writeFlag(mOpenOneWay);
	stream->write(mSecBeforeMoving);

	if (stream->writeFlag(mBlockOnCollision))
	{
		stream->writeCussedU32(mCollisionIgnoreMask);
		if (stream->writeFlag(mSpawnParticlesOnCollision))
			if (stream->writeFlag(mCollisionEmitter))
				stream->writeRangedU32(mCollisionEmitter->getId(), DataBlockObjectIdFirst, DataBlockObjectIdLast);
	}
}

void RotatingDoorData::unpackData(BitStream* stream)
{
	Parent::unpackData(stream);

	//mathRead(*stream, &mRotationAngleAxis);
	//mathRead(*stream, &mRotationOrigin);
	mathRead(*stream, &mRotationTransform);

	S32 i;
	for (i = 0; i < MaxDoorSounds; i++) {
		mSounds[i] = NULL;
		if (stream->readFlag())
			mSounds[i] = (AudioProfile*)
				stream->readRangedU32(DataBlockObjectIdFirst, DataBlockObjectIdLast);
	}

	mOpenOneWay = stream->readFlag();
	stream->read(&mSecBeforeMoving);

	if (mBlockOnCollision = stream->readFlag())
	{
		mCollisionIgnoreMask = stream->readCussedU32();
		if (mSpawnParticlesOnCollision = stream->readFlag())
			if (stream->readFlag())
				mCollisionEmitterID = stream->readRangedU32(DataBlockObjectIdFirst, DataBlockObjectIdLast);
	}
}

void RotatingDoorData::initPersistFields()
{
	Parent::initPersistFields();

	addGroup("Transform");			// Usually this would be TypeMatrixRotation, but this isn't part of a matrix...
		//addField("rotationAngleAxis",	TypePoint4F,			Offset(mRotationAngleAxis,		RotatingDoorData));
		//addField("rotationOrigin",	TypePoint3F,			Offset(mRotationOrigin,			RotatingDoorData));
		addField("rotationOrigin",		TypeMatrixPosition,		Offset(mRotationTransform,		RotatingDoorData));
		addField("rotationAngleAxis",	TypeMatrixRotation,		Offset(mRotationTransform,		RotatingDoorData));
	endGroup("Transform");

	addGroup("Sounds");
		addField("toggleSound",			TypeAudioProfilePtr,	Offset(mSounds[Toggle],			RotatingDoorData));
		addField("movingSound",			TypeAudioProfilePtr,	Offset(mSounds[Moving],			RotatingDoorData));
		addField("closedSound",			TypeAudioProfilePtr,	Offset(mSounds[Closed],			RotatingDoorData));
		addField("openedSound",			TypeAudioProfilePtr,	Offset(mSounds[Opened],			RotatingDoorData));
		addField("haltedSound",			TypeAudioProfilePtr,	Offset(mSounds[Halted],			RotatingDoorData));
	endGroup("Sounds");

	addGroup("Settings");
		addField("openTwoWays",			TypeBool,				Offset(mOpenOneWay,				RotatingDoorData));
		addField("secBeforeMoving",		TypeF32,				Offset(mSecBeforeMoving,		RotatingDoorData));
		addField("secRotationTime",		TypeF32,				Offset(mSecRotationTime,		RotatingDoorData));
	endGroup("Settings");

	addGroup("Collisions");
		addField("blockOnCollision",	TypeBool,				Offset(mBlockOnCollision,		RotatingDoorData));
		addField("collisionIgnoreMask",	TypeS32,				Offset(mCollisionIgnoreMask,	RotatingDoorData));
		addField("collisionParticles",TypeParticleEmitterDataPtr,Offset(mCollisionEmitter,		RotatingDoorData));
		addField("spawnParticlesOnCollision", TypeBool,		Offset(mSpawnParticlesOnCollision,	RotatingDoorData));
	endGroup("Collisions");
}


void RotatingDoor::initPersistFields()
{
	Parent::initPersistFields();
}

void RotatingDoor::inspectPostApply()
{
	if (isServerObject()) {
		setMaskBits(~0);
	}
}

RotatingDoor::RotatingDoor()
{
	mDataBlock = NULL;
	mTypeMask |= StaticShapeObjectType | StaticObjectType;

	mLocked = false;
	mMovingSoundHandle = NULL_AUDIOHANDLE;

	mDirection = 1.f;
	mComplRatio = 0.f;
	mRevTimeSec = 0.f;
	mMaxAngleRad = (M_PI_F * .5f);
	mDoorState = 
	mPrevState =
		DoorState::PrepClose;
}

bool RotatingDoor::onAdd()
{
	if (!Parent::onAdd() || !mDataBlock)
		return false;

	resetWorldBox();
	addToScene();

	if (isServerObject())
		scriptOnAdd();

	mConvexTransform = getTransform();
	return true;
}

void RotatingDoor::onRemove()
{
	mConvexList->nukeList();
	scriptOnRemove();
	removeFromScene();

	Parent::onRemove();
}

bool RotatingDoor::onNewDataBlock(GameBaseData* dptr)
{
	mDataBlock = dynamic_cast<RotatingDoorData*>(dptr);
	if (!mDataBlock || !Parent::onNewDataBlock(dptr))
		return false;

	// Setup the box for our convex object...

	scriptOnNewDataBlock();
	return true;
}

void RotatingDoor::scriptOnOpened()
{
	Con::executef(this, 1, "onOpened");
}

void RotatingDoor::scriptOnClosed()
{
	Con::executef(this, 1, "onClosed");
}

void RotatingDoor::advanceState(F32 dt)
{
	// dt is always a float in second unit before dec point

	DoorState lastState = mPrevState;
	mPrevState = mDoorState;

	bool clientside = !isServerObject();

	MatrixF mtx;

	// State management code
	switch (mDoorState)
	{
	case DoorState::Closing:
	{
		mRevTimeSec += dt;
		mComplRatio = mRevTimeSec / mDataBlock->mSecRotationTime;

		if (mComplRatio >= 1.f) {
			mComplRatio = 1.f;
			mDoorState = DoorState::Closed;

			if (clientside)
			{
				if (alxIsValidHandle(mMovingSoundHandle) && alxIsPlaying(mMovingSoundHandle))
					alxStop(mMovingSoundHandle);

				AudioProfile* sdb = mDataBlock->mSounds[RotatingDoorData::Closed];
				if (sdb)
					alxPlay(sdb, &getTransform());
			}
			else {
				scriptOnClosed();
				setMaskBits(NotifySync);
			}

			return;
		}

		setAngleTransformed((mMaxAngleRad * ((1.f - mComplRatio) * mDirection)));
	}
	break;
	case DoorState::Opening:
	{
		mRevTimeSec += dt;
		mComplRatio = mRevTimeSec / mDataBlock->mSecRotationTime;

		if (mComplRatio >= 1.f) {
			mComplRatio = 1.f;
			mDoorState = DoorState::Opened;

			if (clientside)
			{
				if (alxIsValidHandle(mMovingSoundHandle) && alxIsPlaying(mMovingSoundHandle))
					alxStop(mMovingSoundHandle);

				AudioProfile* sdb = mDataBlock->mSounds[RotatingDoorData::Opened];
				if (sdb)
					alxPlay(sdb, &getTransform());
			}
			else {
				scriptOnOpened();
				setMaskBits(NotifySync);
			}

			return;
		}

		setAngleTransformed((mMaxAngleRad * (mComplRatio * mDirection)));
	}
	break;
	case DoorState::Closed:
	{
		//if (clientside && mForcedState)
		//	setAngleTransformed(0.f);
		mRevTimeSec = 0.0f;
	}
	break;
	case DoorState::Opened:
	{
		//if (clientside && mForcedState)
		//	setAngleTransformed(mMaxAngleRad * mDirection);
		mRevTimeSec = 0.0f;
	}
	break;

	// PrepOpen/PrepClose: The direction was already set
	case DoorState::PrepOpen:
	{
		if (clientside)
		{
			if (alxIsValidHandle(mMovingSoundHandle) && alxIsPlaying(mMovingSoundHandle))
				alxStop(mMovingSoundHandle);

			AudioProfile* sdb = mDataBlock->mSounds[RotatingDoorData::Toggle];
			if (sdb)
				alxPlay(sdb, &getTransform());

			// TODO: Play this after RotatingDoorData::mMsBeforeMoving
			AudioProfile* movedb = mDataBlock->mSounds[RotatingDoorData::Moving];
			if (movedb)
				mMovingSoundHandle = alxPlay(movedb, &getTransform());
		}

		mDoorState = DoorState::Opening;	// Don't need ::setState, client will simulate this correctly without a message
		mRevTimeSec = 0.f;
		mComplRatio = 0.f;
	}
	break;
	case DoorState::PrepClose:
	{
		if (clientside)
		{
			if (alxIsValidHandle(mMovingSoundHandle) && alxIsPlaying(mMovingSoundHandle))
				alxStop(mMovingSoundHandle);

			AudioProfile* sdb = mDataBlock->mSounds[RotatingDoorData::Toggle];
			if (sdb)
				alxPlay(sdb, &getTransform());

			AudioProfile* movedb = mDataBlock->mSounds[RotatingDoorData::Moving];
			if (movedb)
				mMovingSoundHandle = alxPlay(movedb, &getTransform());
		}

		mDoorState = DoorState::Closing;	// Don't need ::setState, client will simulate this correctly without a message
		mRevTimeSec = 0.f;
		mComplRatio = 0.f;
	}
	break;
	}

	//mForcedState = false;

	if (isMounted()) {
		MatrixF mat;
		mMount.object->getRenderMountTransform(mMount.node, &mat);
		mat.mul(mtx); // Add rotation
		Parent::setRenderTransform(mat);
	}
}

void RotatingDoor::setForcedClientState(DoorState state)
{
	if (
		((state == DoorState::Opened) && (mDoorState == DoorState::Opening)) ||
		((state == DoorState::Closed) && (mDoorState == DoorState::Closing))
	)
	{
		// Misprediction, just snap to finished state if there's too much
		// of a time difference.
		if (mComplRatio < 0.9f)
		{
			mRevTimeSec = mDataBlock->mSecRotationTime;
			mComplRatio = 1.f;
			mDoorState = state;
		}
	}
}

void RotatingDoor::processTick(const Move* move)
{
	Parent::processTick(move);

	// Advance state
	if (!isGhost())
		advanceState(TickSec);

	// Collision management code

	// Image Triggers
	if (move && mDamageState == Enabled) {
		setImageTriggerState(0, move->trigger[0]);
		setImageTriggerState(1, move->trigger[1]);
	}

	if (isMounted()) {
		MatrixF mat;
		mMount.object->getMountTransform(mMount.node, &mat);
		Parent::setTransform(mat);
		Parent::setRenderTransform(mat);
	}
}

void RotatingDoor::interpolateTick(F32 dt)
{
	Parent::interpolateTick(dt);

	// Really no need for tick interpolation.
	// No precise movement nor warping is needed.
}

void RotatingDoor::setAngleTransformed(F32 openAngle)
{
	MatrixF mtx = mDataBlock->mRotationTransform, 
	otw;

	Point3F pos;
	mtx.getColumn(3, &pos);

	MatrixF orig(true), iorig(true);
	orig.setPosition(pos);
	iorig.setPosition(-pos);

	MatrixF rot(true);
	AngAxisF aa(mtx);
	aa.angle = openAngle;
	aa.setMatrix(&rot);

	MatrixF local = orig.mul(rot.mul(iorig));

	otw = mObjToWorld;
	mConvexTransform = otw.mul(local);

	if (isGhost())
		setRenderTransform(mConvexTransform);
}

void RotatingDoor::advanceTime(F32 dt)
{
	Parent::advanceTime(dt);

	mPrevState = mDoorState;

	MatrixF mtx;

	// State management code
	advanceState(dt);
}

void RotatingDoor::setTransform(const MatrixF& mat)
{
	Parent::setTransform(mat);

	if (isServerObject())
		setMaskBits(PositionMask);
}

void RotatingDoor::buildConvex(const Box3F& box, Convex* convex)
{
	if (mShapeInstance == NULL)
		return;

	// These should really come out of a pool
	mConvexList->collectGarbage();

	Box3F realBox = box;
	mWorldToObj.mul(realBox);
	realBox.min.convolveInverse(mObjScale);
	realBox.max.convolveInverse(mObjScale);

	if (realBox.isOverlapped(getObjBox()) == false)
		return;

	for (U32 i = 0; i < mDataBlock->collisionDetails.size(); i++)
	{
		Box3F newbox = mDataBlock->collisionBounds[i];
		newbox.min.convolve(mObjScale);
		newbox.max.convolve(mObjScale);
		mObjToWorld.mul(newbox);
		if (box.isOverlapped(newbox) == false)
			continue;

		// See if this hull exists in the working set already...
		Convex* cc = 0;
		CollisionWorkingList& wl = convex->getWorkingList();
		for (CollisionWorkingList* itr = wl.wLink.mNext; itr != &wl; itr = itr->wLink.mNext) {
			if (itr->mConvex->getType() == ShapeBaseConvexType &&
				(static_cast<ShapeBaseConvex*>(itr->mConvex)->pShapeBase == this &&
					static_cast<ShapeBaseConvex*>(itr->mConvex)->hullId == i)) {
				cc = itr->mConvex;
				break;
			}
		}
		if (cc)
			continue;

		// Create a new convex.
		ShapeBaseConvex* cp = new ShapeBaseConvex;
		mConvexList->registerObject(cp);
		convex->addToWorkingList(cp);
		cp->mObject = this;
		cp->pShapeBase = this;
		cp->hullId = i;
		cp->box = mDataBlock->collisionBounds[i];
		cp->transform = &mConvexTransform;
		cp->findNodeTransform();
	}
}

U64  RotatingDoor::packUpdate(NetConnection* conn, U64 mask, BitStream* stream)
{
	U64 retMask = Parent::packUpdate(conn, mask, stream);

	if (stream->writeFlag(mask & PositionMask)) {
		stream->writeAffineTransform(mObjToWorld);
		mathWrite(*stream, mObjScale);
	}

	if (stream->writeFlag(mask & ToggleOpen))
		stream->writeSignedFloat(mDirection, MoveDirPrecision);

	stream->writeFlag(mask & ToggleClose);

	// Forced state sync
	if (stream->writeFlag(mask & NotifySync))
		stream->writeFlag(mDoorState == DoorState::Opened);

	// Immediately replicate current state to connection
	if (stream->writeFlag(mask & InitialUpdateMask)) {
		stream->writeSignedFloat(mDirection, MoveDirPrecision);
		stream->writeFloat(mComplRatio, MoveDirPrecision);
		stream->writeRangedU32((U32)mDoorState, 0, (U32)DoorState::DoorStateCount);
	}

	return retMask;
}

void RotatingDoor::unpackUpdate(NetConnection* conn, BitStream* stream)
{
	Parent::unpackUpdate(conn, stream);

	if (stream->readFlag()) {
		MatrixF mat;
		stream->readAffineTransform(&mat);
		setTransform(mat);

		VectorF scale;
		mathRead(*stream, &scale);
		setScale(scale);
		resetWorldBox();
		setRenderTransform(mat);
	}

	// Toggle open
	if (stream->readFlag()) {
		mDirection = stream->readSignedFloat(MoveDirPrecision);
		mDoorState = DoorState::PrepOpen;
	}

	// Toggle close
	if (stream->readFlag()) {
		mDoorState = DoorState::PrepClose;
	}

	// Forced states

	// Notify Sync
	if (stream->readFlag()) {
		setForcedClientState(stream->readFlag() ? DoorState::Opened : DoorState::Closed);
	}

	// Set current replicated state
	if (stream->readFlag()) {
		mDirection = stream->readSignedFloat(MoveDirPrecision);
		mComplRatio = stream->readFloat(MoveDirPrecision);
		mDoorState = (DoorState)stream->readRangedU32(0, (U32)DoorState::DoorStateCount);
	}
}

void RotatingDoor::resetSimValues()
{
	mComplRatio = 0.f;
	mRevTimeSec = 0.f;
	mDoorState = DoorState::Closed;
}

bool RotatingDoor::canCollideWith(SceneObject* obj)
{
	if (!mDataBlock) return false;
	if (!mDataBlock->mBlockOnCollision) return false;
	return (obj->getTypeMask() & mDataBlock->mCollisionIgnoreMask) != 0U;
}

void RotatingDoor::setLock(bool state) {
	state;
}

void RotatingDoor::requestOpen(SceneObject* activator)
{
	if (isGhost()) return;

	if (!getLock())
		open(activator);
}

void RotatingDoor::open(SceneObject* activator)
{
	// This tests the state machine in processTick
	if ((!isGhost()) && (getState() == DoorState::Closed))
	{
		// Try and get the side of the door the player is facing
		if (activator && !mDataBlock->mOpenOneWay)
		{
			PlaneF divider;
			const MatrixF& mat = getTransform();
			Point3F dir;
			Point3F pos;
			mat.getColumn(3, &pos);	// mObjToWorld position
			mat.getColumn(1, &dir);	// mObjToWorld frwd vec
			divider.set(pos, dir);
			mDirection = F32(-divider.whichSide(activator->getPosition()));
		}
		else {
			mDirection = 1.f;
		}

		setNetState(DoorState::PrepOpen);
	}
}

void RotatingDoor::close()
{
	// This tests the state machine in processTick
	if ((!isGhost()) && (getState() == DoorState::Opened))
	{
		setNetState(DoorState::PrepClose);
	}
}

// Group together state change and net replication
void RotatingDoor::setNetState(RotatingDoor::DoorState newState)
{
	mDoorState = newState;

	switch (newState)
	{
	case DoorState::PrepOpen:
		setMaskBits(ToggleOpen);
		break;
	case DoorState::PrepClose:
		setMaskBits(ToggleClose);
		break;
	}
}

bool RotatingDoor::getLock() const
{
	return mLocked;
}

RotatingDoor::DoorState RotatingDoor::getState() const
{
	return mDoorState;
}

// Console methods
ConsoleMethod(RotatingDoor, open, void, 3, 3, "(SimObject activator)")
{
	object->requestOpen(dynamic_cast<SceneObject*>(Sim::findObject(argv[2].toString())));
}

ConsoleMethod(RotatingDoor, close, void, 2, 2, "close the door if open")
{
	object->close();
}

ConsoleMethod(RotatingDoor, canCollideWith, bool, 3, 3, "(SceneObject)")
{
	SceneObject* obj = NULL;
	if (Sim::findObject(argv[2].toString(), obj))
		return object->canCollideWith(obj);
	else return false;
}

ConsoleMethod(RotatingDoor, setLock, void, 3, 3, "(bool) set door lock state")
{
	return object->setLock(argv[2].getInt());
}

ConsoleMethod(RotatingDoor, isLocked, bool, 2, 2, "returns true if locked, false otherwise")
{
	return object->getLock();
}

ConsoleMethod(RotatingDoor, isClosed, bool, 2, 2, "returns true if locked, false otherwise")
{
	return object->getState() == RotatingDoor::DoorState::Closed;
}
