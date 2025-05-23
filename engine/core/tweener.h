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

#ifndef _MQUAT_H_
#include <math/mQuat.h>
#endif _MQUAT_H_

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
	virtual void saveInitVal(const void* ptr, S32) = 0;

	// save initial value on create
	virtual void saveTargetVal(ConsoleValue& string) = 0;

	// string to script value
	virtual void valueToConsole(ConsoleValue& out) = 0;

public:
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
		ConsoleValue outValue;
		valueToConsole(outValue);

		SimObject* ptr = mPtr;
		// This also has the side effect of calling SimObject::onStaticModified
		// and potentially passing the value through the field's type validator.
		ptr->setStaticField(mStaticField, NULL, outValue);
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

	static TweenerBase* create(SimObject* pObject, char const* field, ConsoleValue& targetScriptVal, S32 ms);

	// Unlink from tween list
	void unlink();

	void setFunction(InterpolationFn fn) { mFunction = fn; }

	// Server or client process.
	static void processLiveTweens(S32 dt);

	// Push new tween to process list.
	static S32 pushLiveTween(TweenerBase* tw);

	// Find live tweener in list.
	static TweenerBase* findTween(S32 id);

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
	typedef TweenerTyped<T> TweenerClass;

	void saveInitVal(const void* ptr, S32) override { initVal = *(const T*)ptr; }
};

// Tweener for single float
class TweenerFloat : public TweenerTyped<F32> {
protected:
	// string to script value
	void valueToConsole(ConsoleValue& out) override {
		out = currentVal;
	}

	void saveTargetVal(ConsoleValue& value) override {
		targetVal = value.getNumber();
	}

	void interpolateValue(F32 value) override {
		currentVal = mLerp(initVal, targetVal, value);
	}
};

// Tweener for 2d float vector
class TweenerPoint2F : public TweenerTyped<Point2F> {
	// Permanently hold a reference to this list
	ConsoleValueList* mPointRef;
public:
	TweenerPoint2F() {
		mPointRef = ConsoleValueList::from(0.0, 0.0);
		mPointRef->incRef();
	}
	~TweenerPoint2F() { mPointRef->decRef(); }
protected:
	// string to script value
	void valueToConsole(ConsoleValue& out) override {
		mPointRef->at(0) = currentVal.x;
		mPointRef->at(1) = currentVal.y;
		out = mPointRef;
	}

	void saveTargetVal(ConsoleValue& string) override {
		targetVal = string.getPoint2F();
	}

	void interpolateValue(F32 value) override {
		currentVal.interpolate(initVal, targetVal, value);
	}
};

// Tweener for 2d int vector (mostly for GUIs)
class TweenerPoint2I : public TweenerTyped<Point2I> {
	// Permanently hold a reference to this list
	ConsoleValueList* mPointRef;
public:
	TweenerPoint2I() {
		mPointRef = ConsoleValueList::from(0, 0);
		mPointRef->incRef();
	}
	~TweenerPoint2I() { mPointRef->decRef(); }
protected:
	// string to script value
	void valueToConsole(ConsoleValue& out) override {
		mPointRef->at(0) = currentVal.x;
		mPointRef->at(1) = currentVal.y;
		out = mPointRef;
	}

	void saveTargetVal(ConsoleValue& string) override {
		targetVal = string.getPoint2I();
	}

	void interpolateValue(F32 value) override {
		currentVal.interpolate(initVal, targetVal, value);
	}
};

// Tweener for 3d float vector
class TweenerPoint3F : public TweenerTyped<Point3F> {
	// Permanently hold a reference to this list
	ConsoleValueList* mPointRef;
public:
	TweenerPoint3F() {
		mPointRef = ConsoleValueList::from(0.0, 0.0, 0.0);
		mPointRef->incRef();
	}
	~TweenerPoint3F() { mPointRef->decRef(); }
protected:
	// string to script value
	void valueToConsole(ConsoleValue& out) override {
		mPointRef->at(0) = currentVal.x;
		mPointRef->at(1) = currentVal.y;
		mPointRef->at(2) = currentVal.z;
		out = mPointRef;
	}

	void saveTargetVal(ConsoleValue& string) override {
		targetVal = string.getPoint3F();
	}

	void interpolateValue(F32 value) override {
		currentVal.interpolate(initVal, targetVal, value);
	}
};

// Tweener for 4d float vector
class TweenerPoint4F : public TweenerTyped<Point4F> {
	// Permanently hold a reference to this list
	ConsoleValueList* mPointRef;
public:
	TweenerPoint4F() {
		mPointRef = ConsoleValueList::from(0.0, 0.0, 0.0, 0.0);
		mPointRef->incRef();
	}
	~TweenerPoint4F() { mPointRef->decRef(); }
protected:
	// string to script value
	void valueToConsole(ConsoleValue& out) override {
		mPointRef->at(0) = currentVal.x; 
		mPointRef->at(1) = currentVal.y;
		mPointRef->at(2) = currentVal.z;
		mPointRef->at(3) = currentVal.w;
		out = mPointRef;
	}
	// since this can be a TypeMatrixPosition, those usually don't have an explicit w component.
	void saveTargetVal(ConsoleValue& string) override {
		targetVal.x = string.getListValueDefU(0, 0.0).getNumber();
		targetVal.y = string.getListValueDefU(1, 0.0).getNumber();
		targetVal.z = string.getListValueDefU(2, 0.0).getNumber();
		targetVal.w = string.getListValueDefU(3, 1.0).getNumber();
	}

	void interpolateValue(F32 value) override {
		currentVal.interpolate(initVal, targetVal, value);
	}

	void saveInitVal(const void* ptr, S32 type) override {
		if (type == TypeMatrixPosition) {
			MatrixF const* mxField = reinterpret_cast<MatrixF const*>(ptr);
			mxField->getColumn(3, &initVal);
		}
		else TweenerClass::saveInitVal(ptr, type);
	}
};

// Quaternion class for matrix rotations
class TweenerQuatF : public TweenerTyped<QuatF> {
	// Permanently hold a reference to this list
	ConsoleValueList* mPointRef;
public:
	TweenerQuatF() {
		mPointRef = ConsoleValueList::from(0.0, 0.0, 0.0, 0.0);
		mPointRef->incRef();
	}
	~TweenerQuatF() { mPointRef->decRef(); }
protected:
	// string to script value
	void valueToConsole(ConsoleValue& out) override {
		AngAxisF aa(currentVal);
		mPointRef->at(0) = aa.axis.x;
		mPointRef->at(1) = aa.axis.y;
		mPointRef->at(2) = aa.axis.z;
		mPointRef->at(3) = mRadToDeg(aa.angle);
		out = mPointRef;
	}

	void saveTargetVal(ConsoleValue& string) override {
		AngAxisF aa = string.getPoint4F();
		aa.angle = mDegToRad(aa.angle);
		targetVal = aa;
	}

	void interpolateValue(F32 value) override {
		currentVal.interpolate(initVal, targetVal, value);
	}

	void saveInitVal(const void* ptr, S32 type) override {
		if (type == TypeMatrixRotation) {
			MatrixF const* mxField = reinterpret_cast<MatrixF const*>(ptr);
			initVal = *mxField;
		}
		else TweenerClass::saveInitVal(ptr, type);
	}
};

// Tweener for linear color
class TweenerColorF : public TweenerTyped<ColorF> {
	// Permanently hold a reference to this list
	ConsoleValueList* mPointRef;
public:
	TweenerColorF() {
		mPointRef = ConsoleValueList::from(0.0, 0.0, 0.0, 1.0);
		mPointRef->incRef();
	}
	~TweenerColorF() { mPointRef->decRef(); }
protected:
	// string to script value
	void valueToConsole(ConsoleValue& out) override {
		mPointRef->at(0) = currentVal.red;
		mPointRef->at(1) = currentVal.green;
		mPointRef->at(2) = currentVal.blue;
		mPointRef->at(3) = currentVal.alpha;
		out = mPointRef;
	}

	void saveTargetVal(ConsoleValue& string) override {
		targetVal = string.getColorF();
	}

	void interpolateValue(F32 value) override {
		currentVal.interpolate(initVal, targetVal, value);
	}
};

// Tweener for integer color
class TweenerColorI : public TweenerTyped<ColorI> {
	// Permanently hold a reference to this list
	ConsoleValueList* mPointRef;
public:
	TweenerColorI() {
		mPointRef = ConsoleValueList::from(0, 0, 0, 255);
		mPointRef->incRef();
	}
	~TweenerColorI() { mPointRef->decRef(); }
protected:
	// string to script value
	void valueToConsole(ConsoleValue& out) override {
		mPointRef->at(0) = currentVal.red;
		mPointRef->at(1) = currentVal.green;
		mPointRef->at(2) = currentVal.blue;
		mPointRef->at(3) = currentVal.alpha;
		out = mPointRef;
	}

	void saveTargetVal(ConsoleValue& string) override {
		targetVal = string.getColorI();
	}

	void interpolateValue(F32 value) override {
		currentVal.interpolate(initVal, targetVal, value);
	}
};

#endif