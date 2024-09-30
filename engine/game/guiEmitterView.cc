//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#include "gui/core/guiCanvas.h"
#include "console/consoleTypes.h"
#include "gui/core/guiTSControl.h"
#include "game/fx/particleEngine.h"
#include "gui/shiny/guiTickCtrl.h"

class GuiEmitterView : public GuiTSCtrl, public virtual ITickable
{
private:
	typedef GuiTSCtrl Parent;
	U32 lastTimeDelta;

	F32 mZoomLevel;

	// Equivalent to view matrix
	MatrixF mCameraMatrix;

	// Emitter + DB, and datablock name to act as life ticket.
	ParticleEmitter*		mEmitter;
	ParticleEmitterData*	mEmitterData;
	StringTableEntry		mEmitterDataName;

protected:
	void interpolateTick(F32 delta) override {}
	void processTick() override;
	void advanceTime(F32 timeDelta) override;

public:
	DECLARE_CONOBJECT(GuiEmitterView);
	GuiEmitterView();
	~GuiEmitterView();

	void onStaticModified(const char* name) override;

	bool processCameraQuery(CameraQuery* query) override;

	void onPreRender() override;
	void renderWorld(const RectI& updateRect) override;

	bool onWake() override;
	void onSleep() override;
	bool pointInControl(const Point2I& parentCoords) override;

	void emit();

	static void initPersistFields();
};

IMPLEMENT_CONOBJECT(GuiEmitterView);

GuiEmitterView::GuiEmitterView()
{
	mZoomLevel = 1.f;
	mCameraMatrix.identity();	// keep at origin

	mEmitter = NULL;
	mEmitterData = NULL;
	mEmitterDataName = NULL;
}

GuiEmitterView::~GuiEmitterView()
{
	if (mEmitter) {
		mEmitter->deleteObject();
	}
}

void GuiEmitterView::onStaticModified(char const* field)
{
	if (dStricmp(field, "datablock") == 0)
		mEmitterDataName = mEmitterData ? mEmitterData->getName() : NULL;
}

void GuiEmitterView::processTick()
{
	if (mEmitter)
		mEmitter->processTick(NULL);
}

void GuiEmitterView::advanceTime(F32 timeDelta)
{
	lastTimeDelta = timeDelta * 1000.f;
	if (mEmitter)
		mEmitter->advanceTime(timeDelta);
}

bool GuiEmitterView::processCameraQuery(CameraQuery* query)
{
	/*
	F32 invZoomLevel = 1.f / mZoomLevel;
	query->leftRight = mBounds.extent.x * .5f * invZoomLevel;
	query->leftRight = mBounds.extent.x * .5f * invZoomLevel;
	query->cameraMatrix = mCameraMatrix;
	query->nearPlane = 0.01f;
	query->farPlane = 20.f;
	query->ortho = true;
	*/

	// TODO: Shorten to just a zoom value and a cam position.
	// The camera always looks forward but can have another origin.

	// Make sure the orbit distance is within the acceptable range:
	F32 mOrbitDist = 5.0;
	Point3F mCameraPos;
	EulerF mCameraRot(0, 0, 0);
	Point3F mOrbitPos(0, 0, 0);

	// Adjust the camera so that we are still facing the model:
	Point3F vec;
	MatrixF xRot, zRot;
	xRot.set(EulerF(mCameraRot.x, 0, 0));
	zRot.set(EulerF(0, 0, mCameraRot.z));

	mCameraMatrix.mul(zRot, xRot);
	mCameraMatrix.getColumn(1, &vec);
	vec *= mOrbitDist;
	mCameraPos = mOrbitPos - vec;

	query->nearPlane = 0.1;
	query->farPlane = 2100.0;
	query->fov = 3.1415 / 3.5;
	mCameraMatrix.setColumn(3, mCameraPos);
	query->cameraMatrix = mCameraMatrix;
	return true;
}

bool GuiEmitterView::onWake()
{
	if (!Parent::onWake())
		return false;

	setActive(false);	// make sure it is not tabable

	// datablocks are volatile, so before we potentially render,
	// we need to check back on the referenced datablock...
	if (mEmitterDataName && Sim::findObject(mEmitterDataName, mEmitterData)) {
		if (mEmitter && !mEmitter->onNewDataBlock(mEmitterData))
			Con::errorf("GuiEmitterView: Datablock reassignment failed for %s.", mEmitterDataName);
	}
	else if (mEmitterDataName) {
		Con::errorf("GuiEmitterView: Could not recover datablock %s.", mEmitterDataName);
		mEmitter->deleteObject();
		mEmitter = NULL;
	}
	return true;
}

void GuiEmitterView::onSleep()
{
	Parent::onSleep();
	mEmitterData = NULL;
}

bool GuiEmitterView::pointInControl(const Point2I& p)
{
	// Pass through by relaying test to parent.
	if (getParent()) {
		return getParent()->pointInControl(p + mBounds.point);
	}
	return false;
}

void GuiEmitterView::onPreRender()
{
	Parent::onPreRender();

	if (mEmitter) {
		static const Point3F point(0, 0, 0);
		static const Point3F normal(0, 0, 1);
		mEmitter->emitParticles(point, point, normal, normal, lastTimeDelta);
	}
}

void GuiEmitterView::renderWorld(const RectI& updateRect)
{
	if (!mEmitter)
		return;

	glClear(GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	Point3F camPos;
	mCameraMatrix.getColumn(3, &camPos);
	MatrixF modelview(mSaveModelview);
	mEmitter->render(camPos, modelview);

	//dglDrawBillboard(Point3F(0, 0, 0), 8, 2);

	glDisable(GL_DEPTH_TEST);
	dglSetClipRect(updateRect);
	dglSetCanonicalState();
}

void GuiEmitterView::initPersistFields()
{
	Parent::initPersistFields();

	addGroup("Display");
	addField("datablock", TypeParticleEmitterDataPtr, Offset(mEmitterData, GuiEmitterView));
	addField("zoomLevel", TypeF32, Offset(mZoomLevel, GuiEmitterView));
	endGroup("Display");
}

void GuiEmitterView::emit()
{
	ParticleEmitter* pEmitter = new ParticleEmitter;
	pEmitter->onNewDataBlock(mEmitterData);
	if (pEmitter->registerObject() == false)
	{
		Con::warnf(ConsoleLogEntry::General, "Could not register base emitter for particle of class: %s", mEmitterData->getName());
		delete pEmitter;
		return;
	}
	pEmitter->setAddToScene(false);
	mEmitter = pEmitter;
}

ConsoleMethod(GuiEmitterView, emit, void, 2, 2, "() - Start emitting particles")
{
	object->emit();
}