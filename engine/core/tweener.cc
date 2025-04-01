//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#include "tweener.h"
#include "console/consoleTypes.h"
#include "math/mathTypes.h"

TweenerBase* TweenerBase::smHead = NULL;
S32 TweenerBase::smStaticIdGenerator = 0;

void TweenerBase::unlink() {
	if (mPrev)
		mPrev->mNext = mNext;
	else smHead = mNext;
	if (mNext)
		mNext->mPrev = mPrev;
}

void TweenerBase::processLiveTweens(S32 dt) {
	TweenerBase* walk = smHead;
	while (walk) {
		walk->process(dt);
		if (walk->mTimeLeftMS <= 0) {
			walk->interpolateValue(1.f);
			walk->apply();
			TweenerBase* temp = walk;
			walk = walk->mNext;
			temp->unlink();
			delete temp;
		} else
			walk = walk->mNext;
	}
}

TweenerBase* TweenerBase::findTween(S32 id) {
	TweenerBase* walk = smHead;
	while (walk) {
		if (walk->getId() == id)
			return walk;
		walk = walk->mNext;
	}
	return NULL;
}

bool TweenerBase::removeTween(S32 id) {
	TweenerBase* tb = findTween(id);
	if (tb) {
		tb->unlink();
		delete tb;
		return true;
	}
	return false;
}

S32 TweenerBase::pushLiveTween(TweenerBase* tween) {
	if (!tween) return -1;
	if (smStaticIdGenerator < 0)
		smStaticIdGenerator = 0;
	tween->mId = ++smStaticIdGenerator;
	tween->mNext = smHead;
	smHead = tween;
	return tween->mId;
}

TweenerBase* TweenerBase::create(SimObject* pObject, char const* field, char const* targetScriptVal, S32 ms) {
	if (!pObject || !pObject->getClassRep() || !field || !field[0])
		return NULL;

	AbstractClassRep* rep = pObject->getClassRep();
	AbstractClassRep::Field const* fptr = rep->findField(StringTable->insert(field));
	// If we got no field info, then it's a dynamic field.
	if (!fptr) {
		char const* cname = pObject->getClassName();
		Con::errorf("Tween: %s::%s is not static (dynamic fields are currently not supported).", cname, field);
		return NULL;
	}
	TweenerBase* tweener = NULL;

	// Have to do a lame if/else if chain because console type ids are not constants.
	if (TypeF32 == fptr->type)					tweener = new TweenerFloat();
	else if (TypePoint3F == fptr->type)			tweener = new TweenerPoint3F();
	else if (TypePoint2F == fptr->type)			tweener = new TweenerPoint2F();
	else if (TypePoint2I == fptr->type)			tweener = new TweenerPoint2I();
	else if (TypeColorF == fptr->type)			tweener = new TweenerColorF();
	else if (TypeColorI == fptr->type)			tweener = new TweenerColorI();
	else if (TypeMatrixRotation == fptr->type)	tweener = new TweenerQuatF();
	else if (TypeMatrixPosition == fptr->type ||
		TypePoint4F == fptr->type)				tweener = new TweenerPoint4F();
	else {
		char const* cname = pObject->getClassName();
		Con::errorf("Tween: %s::%s is not a tweenable type.", cname, field);
		return NULL;
	}

	tweener->mPtr = pObject;
	tweener->mDurationMS = ms;
	tweener->mTimeLeftMS = ms;
	tweener->mStaticField = fptr;
	tweener->saveInitVal(((const char*)pObject) + fptr->offset, fptr->type);
	tweener->saveTargetVal(targetScriptVal);
	return tweener;
}

F32 tweenEaseIn(F32 x) { return x * x; }
F32 tweenEaseOut(F32 x) { return 1.f - (x * x); }
F32 tweenEaseInOut(F32 x) { return x * x * (3.0f - 2.0f * x); }

ConsoleFunctionGroupBegin(Tween, "Functions for (static) tweening based on AbstractClassRep fields")

ConsoleFunction(tween, S32, 5, 5, "(object, property, targetValue, timeMS) - linear")
{
	argc;
	TweenerBase* tweener = tweener->create(Sim::findObject(argv[1]), argv[2], argv[3], dAtoi(argv[4]));
	if (tweener) return TweenerBase::pushLiveTween(tweener);
	return -1;
}

ConsoleFunction(tweenIn, S32, 5, 5, "(object, property, targetValue, timeMS) - ease in")
{
	argc;
	TweenerBase* tweener = tweener->create(Sim::findObject(argv[1]), argv[2], argv[3], dAtoi(argv[4]));
	if (tweener) {
		tweener->setFunction(tweenEaseIn);
		return TweenerBase::pushLiveTween(tweener);
	}
	return -1;
}

ConsoleFunction(tweenOut, S32, 5, 5, "(object, property, targetValue, timeMS) - ease out")
{
	argc;
	TweenerBase* tweener = tweener->create(Sim::findObject(argv[1]), argv[2], argv[3], dAtoi(argv[4]));
	if (tweener) {
		tweener->setFunction(tweenEaseOut);
		return TweenerBase::pushLiveTween(tweener);
	}
	return -1;
}

ConsoleFunction(tweenInOut, S32, 5, 5, "(object, property, targetValue, timeMS) - ease in and out")
{
	argc;
	TweenerBase* tweener = tweener->create(Sim::findObject(argv[1]), argv[2], argv[3], dAtoi(argv[4]));
	if (tweener) {
		tweener->setFunction(tweenEaseInOut);
		return TweenerBase::pushLiveTween(tweener);
	}
	return -1;
}

ConsoleFunction(tweenFinalize, bool, 2, 2, "(id) - instantly finalize tweener")
{
	argc;
	TweenerBase* tb = TweenerBase::findTween(dAtoi(argv[1]));
	if (tb) {
		tb->interpolateValue(1.f);
		tb->apply();
		tb->unlink();
		delete tb;
		return true;
	}
	return false;
}

ConsoleFunction(tweenCancel, bool, 2, 2, "(id)")
{
	argc;
	return TweenerBase::removeTween(dAtoi(argv[1]));
}

ConsoleFunctionGroupEnd(Tween)
