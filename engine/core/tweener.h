//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#ifndef _TWEENER_H_
#define _TWEENER_H_

#ifndef _SIMBASE_H_
#include <console/simBase.h>
#endif _SIMBASE_H_

#ifndef _MPOINT_H_
#include <math/mPoint.h>
#endif _MPOINT_H_

#ifndef _COLOR_H_
#include <core/color.h>
#endif _COLOR_H_

#define TWEENER_SCRIPT_MAXBUF 512

/**
	Property tweener for Console objects.
	The goal here is to exploit the static nature of field slots
	and console types to automatically tween exposed fields.
*/
class TweenerBase {
	SimObjectPtr<SimObject> mPtr;
	AbstractClassRep::Field const* mStaticField;

	TweenerBase *mPrev, *mNext;

public:
	typedef F32(*InterpolationFn) (F32 x);
	InterpolationFn mFunction;

protected:
	static S32 smStaticIdGenerator;
	static TweenerBase* smHead;

	// save initial value on create
	virtual void saveInitVal(const void* ptr) = 0;

	// save initial value on create
	virtual void saveTargetVal(const char* string) = 0;

	// string to script value
	virtual void valueToString(char* buffer) = 0;

	// interpolate internal value
	virtual void interpolateValue(F32 ratio) = 0;

public:
	S32 mTimeLeftMS;
	S32 mDurationMS;
	S32 mId;

	TweenerBase()
		: mStaticField(NULL)
		, mFunction(NULL)
		, mPrev(NULL)
		, mNext(NULL)
		, mId(0)	// impossible to get from smStaticIdGenerator, and not -1.
	{
	}

	void apply() {
		char valueBuffer[TWEENER_SCRIPT_MAXBUF];
		char const* valuePtr = valueBuffer;
		valueToString(valueBuffer);

		SimObject* ptr = mPtr;
		// This also has the side effect of calling SimObject::onStaticModified
		// and potentially passing the value through the field's type validator.
		ptr->setStaticField(mStaticField, NULL, valuePtr);
	}

	void process(S32 dt) {
		if (mPtr && mStaticField) {
			mTimeLeftMS -= dt;
			F32 x = mClampF(F32(mDurationMS - mTimeLeftMS) / mDurationMS, 0.f, 1.f);
			if (mFunction) x = mFunction(x);
			interpolateValue(x);
			apply();
		}
	}

	static TweenerBase* create(SimObject* pObject, char const* field, char const* targetScriptVal, S32 ms);

	// Unlink from tween list
	void unlink();

	void setFunction(InterpolationFn fn) { mFunction = fn; }

	// Server or client process.
	static void processLiveTweens(S32 dt);

	// Push new tween to process list.
	static S32 pushLiveTween(TweenerBase* tw);

	// Remove existing tween by ID
	static bool removeTween(S32 id);

	// Get managed pointer to object (null if deleted)
	SimObject* getObject() const { return (SimObject*)mPtr; }

	// Get time left in milliseconds.
	S32 getTimeLeft() const { return mTimeLeftMS; }

	// Get tween ID.
	S32 getId() const { return mId; }
};

// Standard template for tweeners with value T for init, target, and current value.
template <typename T>
class TweenerTyped : public TweenerBase {
protected:
	T initVal;
	T targetVal;
	T currentVal;

public:
	typedef T ValueType;

	void saveInitVal(const void* ptr) { initVal = *(const T*)ptr; }
};

// Tweener for single float
class TweenerFloat : public TweenerTyped<F32> {
protected:
	// string to script value
	void valueToString(char* buffer) override {
		dSprintf(buffer, TWEENER_SCRIPT_MAXBUF, "%g", currentVal);
	}

	void saveTargetVal(char const* string) override {
		dSscanf(string, "%g", &targetVal);
	}

	void interpolateValue(F32 value) override {
		currentVal = mLerp(initVal, targetVal, value);
	}
};

// Tweener for 2d float vector
class TweenerPoint2F : public TweenerTyped<Point2F> {
protected:
	// string to script value
	void valueToString(char* buffer) override {
		dSprintf(buffer, TWEENER_SCRIPT_MAXBUF, "%g %g", currentVal.x, currentVal.y);
	}

	void saveTargetVal(char const* string) override {
		dSscanf(string, "%g %g", &targetVal.x, &targetVal.y);
	}

	void interpolateValue(F32 value) override {
		currentVal.interpolate(initVal, targetVal, value);
	}
};

// Tweener for 2d int vector (mostly for GUIs)
class TweenerPoint2I : public TweenerTyped<Point2I> {
protected:
	// string to script value
	void valueToString(char* buffer) override {
		dSprintf(buffer, TWEENER_SCRIPT_MAXBUF, "%d %d", currentVal.x, currentVal.y);
	}

	void saveTargetVal(char const* string) override {
		dSscanf(string, "%d %d", &targetVal.x, &targetVal.y);
	}

	void interpolateValue(F32 value) override {
		currentVal.interpolate(initVal, targetVal, value);
	}
};

// Tweener for 3d float vector
class TweenerPoint3F : public TweenerTyped<Point3F> {
protected:
	// string to script value
	void valueToString(char* buffer) override {
		dSprintf(buffer, TWEENER_SCRIPT_MAXBUF, "%g %g %g", currentVal.x, currentVal.y, currentVal.z);
	}

	void saveTargetVal(char const* string) override {
		dSscanf(string, "%g %g %g", &targetVal.x, &targetVal.y, &targetVal.z);
	}

	void interpolateValue(F32 value) override {
		currentVal.interpolate(initVal, targetVal, value);
	}
};

// Tweener for linear color
class TweenerColorF : public TweenerTyped<ColorF> {
	// string to script value
	void valueToString(char* buffer) override {
		dSprintf(buffer, TWEENER_SCRIPT_MAXBUF, "%g %g %g %g", currentVal.red, currentVal.green, currentVal.blue, currentVal.alpha);
	}

	void saveTargetVal(char const* string) override {
		dSscanf(string, "%g %g %g %g", &targetVal.red, &targetVal.green, &targetVal.blue, &targetVal.alpha);
	}

	void interpolateValue(F32 value) override {
		currentVal.interpolate(initVal, targetVal, value);
	}
};

// Tweener for integer color
class TweenerColorI : public TweenerTyped<ColorI> {
	// string to script value
	void valueToString(char* buffer) override {
		dSprintf(buffer, TWEENER_SCRIPT_MAXBUF, "%hhu %hhu %hhu %hhu",
			currentVal.red, currentVal.green, currentVal.blue, currentVal.alpha);
	}

	void saveTargetVal(char const* string) override {
		dSscanf(string, "%hhu %hhu %hhu %hhu", &targetVal.red, &targetVal.green, &targetVal.blue, &targetVal.alpha);
	}

	void interpolateValue(F32 value) override {
		currentVal.interpolate(initVal, targetVal, value);
	}
};

#endif