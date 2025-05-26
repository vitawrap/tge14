//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#ifndef _CONSOLEVALUE_H_
#define _CONSOLEVALUE_H_

//Includes
#ifndef _TVECTOR_H_
#include "core/tVector.h"
#endif
#ifndef _PLATFORM_H_
#include "platform/platform.h"
#endif
#ifndef _STRINGTABLE_H_
#include "core/stringTable.h"
#endif
#ifndef _MPOINT_H_
#include "math/mPoint.h"
#endif
#ifndef _COLOR_H_
#include "core/color.h"
#endif

// Size for small string in console value
#define CONVALUE_SSO_SIZE 16

// Construct a null console value.
#define CONVALUE_NULL (ConsoleValue(""))

// Lazy console value string conversion
// Uses the existing string if it is a string, otherwise copies and converts it.
#define CONVALUE_TOSTRING(cv) \
((cv).getType() == ConsoleValue::TypeString? (cv).getStringU() : ConsoleValue((cv)).toString())

class ConsoleValueList;
class MemStream;

/**
	Console value object used at runtime.
	The goal of this container is to behave
	like a variant, replacing all hardcoded
	casts, and potentially offering a base
	for more types than just int, str, float.

	This also allows script code to neglect
	hardcoded casts.
 */
struct ConsoleValue {
	union {
		struct {
			union {
				char smal[CONVALUE_SSO_SIZE];	///< Small-size string
				char* ptr;
			};
			U32 length;
		} str;
		S64 i;
		F64 f;
		ConsoleValueList* list;
	};

	enum Type {
		// Torque types
		TypeInt,
		TypeString,
		TypeFloat,

		// Experimental types
		TypeValueList,

		TypeCount,
	} type;

private:
	friend class ConsoleValueList;
	typedef char Char;

	// Deref list and discard.
	inline void destroyList(ConsoleValueList*& lcv);

	// Does not destroy our list before copying over.
	inline void copyList(ConsoleValueList* lcv);

	// Calculate alloc size with padding
	constexpr size_t strPSize(size_t len) {
		return ((len + 1) + 15) & ~15;
	}

	// Possibly resize or allocate string buffer, and return the correct pointer for writing.
	char* validateStrSize(size_t len, bool intact = false) {
		size_t oldLen = str.length;
		str.length = len;

		bool grow = false;
		if (oldLen >= CONVALUE_SSO_SIZE && (strPSize(len) > strPSize(oldLen)))
			grow = true;
		
		if (len >= CONVALUE_SSO_SIZE) {
			if (grow) // try to keep contents when we can...
				str.ptr = (char*) dRealloc(str.ptr, strPSize(len));
			else if (oldLen < CONVALUE_SSO_SIZE) {
				auto* ptr = (char*) dMalloc(strPSize(len));
				if (intact) dMemmove(ptr, str.smal, oldLen + 1);
				str.ptr = ptr;
			}
			return str.ptr;
		}
		else if (oldLen >= CONVALUE_SSO_SIZE) {
			dFree(str.ptr);
			str.ptr = NULL;
		}
		return str.smal;
	}

	void setString(char const* in) {
		size_t newLen = dStrlen(in);
		char* buf = validateStrSize(newLen);
		if (newLen > 0)
			dMemmove(buf, in, (str.length + 1) * sizeof(char));
		else str.smal[0] = 0;
	}

	void copyString(ConsoleValue const& rhs) {
		size_t newLen = rhs.str.length;
		char* buf = validateStrSize(newLen);
		if (newLen > 0)
			dMemcpy(buf, rhs.getString(), (str.length + 1) * sizeof(char));
		else str.smal[0] = 0;
	}

	void concat(ConsoleValue const& rhs) {
		char const* rStr = rhs.getString();
		size_t firstLen = str.length;
		size_t csz = firstLen + rhs.str.length;
		if (csz == firstLen)
			return;

		char* buf = validateStrSize(csz, true);
		dMemcpy(&buf[firstLen], rStr, (rhs.str.length + 1) * sizeof(char));
	}

	// This is more or less here as a replacement for Con::getReturnBuffer.
	void concatString(char const* rhs, size_t len) {
		size_t firstLen = str.length;
		size_t csz = firstLen + len;
		if (csz == firstLen)
			return;

		char* buf = validateStrSize(csz, true);
		dMemcpy(&buf[firstLen], rhs, len * sizeof(char));
		buf[csz] = 0; // This is the only time where we are unsure of an existing NTerm.
	}

	char const* getString() const {
		return str.length < CONVALUE_SSO_SIZE ? str.smal : str.ptr;
	}

	void clearString() {
		if (str.length >= CONVALUE_SSO_SIZE)
			dFree(str.ptr);
		str.length = 0;
	}

	void clear(bool coherent = false) {
		if ((type == TypeString) && (str.length >= CONVALUE_SSO_SIZE))
			dFree(str.ptr);
		else if (type == TypeValueList) {
			destroyList(list);
		}
		// If we need a coherent value afterwards, just nullify it.
		if (coherent) {
			type = TypeString;
			str.smal[0] = 0;
			str.length = 0;
		}
	}

	void innerPack(MemStream& stream) const;
	bool innerUnpack(MemStream& stream);

public:
	~ConsoleValue() { clear(); }

	ConsoleValue(ConsoleValue const& rhs)
		: type(rhs.type)
	{
		switch (type) {
		case TypeInt:
		case TypeFloat:
			i = rhs.i;
			break;
		case TypeString:
			str.length = 0;
			copyString(rhs);
			break;
		case TypeValueList:
			copyList(rhs.list);
			break;
		}
	}

	inline ConsoleValue& operator = (ConsoleValue const& rhs);

	ConsoleValue& operator = (ConsoleValue&& rhs) {
		if (&rhs == this) return *this;
		clear();
		switch ((type = rhs.type))
		{
		case ConsoleValue::TypeInt:
		case ConsoleValue::TypeFloat:
			i = rhs.i;
			break;
		case ConsoleValue::TypeString:
			str.length = rhs.str.length;
			if (str.length >= CONVALUE_SSO_SIZE) {
				str.ptr = rhs.str.ptr;
				rhs.str.ptr = NULL; // also works to NT the small buffer.
			} else if (str.length > 0)
				dMemmove(str.smal, rhs.str.smal, str.length + 1);
			else str.smal[0] = 0;
			break;
		case ConsoleValue::TypeValueList:
			list = rhs.list;
			break;
		}
		// Set rhs to null string.
		rhs.type = TypeString;
		rhs.str.smal[0] = 0;
		rhs.str.length = 0;
		return *this;
	}

	ConsoleValue(ConsoleValue&& rhs) {
		(void)((*this) = dMove(rhs));
	}

	ConsoleValue(S64 val)
		: type(TypeInt)
	{ i = val; }

	ConsoleValue(bool val)
		: type(TypeInt)
	{ i = val; }

	ConsoleValue(char const* val)
		: type(TypeString)
	{
		str.length = 0;
		setString(val? val : "");
	}

	ConsoleValue(S32 val)
		: ConsoleValue((S64) val)
	{}

	ConsoleValue(F64 val)
		: type(TypeFloat)
	{ f = val; }

	inline ConsoleValue(ConsoleValueList* lcv);

	ConsoleValue& operator = (S64 value) {
		clear();
		type = TypeInt; i = value;
		return *this;
	}

	ConsoleValue& operator = (S32 value) {
		clear();
		type = TypeInt; i = value;
		return *this;
	}

	ConsoleValue& operator = (U32 value) {
		clear();
		type = TypeInt; i = value;
		return *this;
	}

	ConsoleValue& operator = (F64 value) {
		clear();
		type = TypeFloat; f = value;
		return *this;
	}

	ConsoleValue& operator = (F32 value) {
		clear();
		type = TypeFloat; f = value;
		return *this;
	}

	ConsoleValue& operator = (char const* value) {
		clear();
		type = TypeString; str.length = 0;
		setString(value ? value : "");
		return *this;
	}

	// Default construct to null string
	ConsoleValue()
		: type(TypeString)
	{
		str.length = 0;
		str.smal[0] = 0;
	}

	void clearValue() { clear(true); }

	// More restrictive null check
	bool isNullString() const {
		return type == TypeString && str.length == 0;
	}

	inline bool isNull() const;

	// Quick float getter
	inline F64 getNumber() const;

	// Quick integer getter
	inline S64 getInt() const;

	S64 compare(ConsoleValue right, bool caseSens = false, bool strict = false) const {
		if (!strict)
			right.castTo(type);

		if (type == right.type) {
			switch (type) {
			case TypeInt: return i - right.i;
			case TypeFloat: return f - right.f;
			case TypeString: return 
				str.length == right.str.length?
					(caseSens ? dStrcmp(getString(), right.getString()) :
					dStricmp(getString(), right.getString()))
				: str.length - right.str.length;
			case TypeValueList:
				return !(list == right.list);	// TODO: List equality compare
			}
		}
		return 1LL; // this works, return non-equal
	}

	Type getType() const { return type; }

	bool castTo(Type dstType);

	bool isList() const { return type == TypeValueList && list; }

	// Works for local and remote tagged strings
	bool isTagString() const;

	// Unchecked getters (used after getType() or a successful castTo(T)).

	S64 getIntU() const { return i; }
	F64 getFloatU() const { return f; }
	char const* getStringU() const { return getString(); }
	S64 getStrlenU() const { return str.length; }
	void concatU(ConsoleValue& v) { v.castTo(TypeString); concat(v); }
	void concatStringU(char const* string, size_t len) { concatString(string, len); }

	inline ConsoleValueList const& getListU() const;
	inline ConsoleValueList& getListU();
	inline size_t getListSizeU() const;
	inline ConsoleValue& getListValueU(U32 i);
	inline ConsoleValue const& getListValueU(U32 i) const;
	inline ConsoleValue const& getListValueDefU(U32 i, ConsoleValue const& def = "") const;

	// Checked toString (mutates console value!)
	// Make sure the lifetime of the ConsoleValue guarantees the lifetime of the ptr to the string!
	char const* toString() { return castTo(TypeString)? getString() : ""; }
	StringTableEntry toSTString() { return StringTable->insert(toString()); }
	S64 getStrlen() { return castTo(TypeString)? str.length : 0 ; }

	// Non-mutating toString, requires an output buffer.
	S32 toString(char* out, S32 size) const;

	// Fancier "toString" method to write down console values with their real syntax.
	S32 serialize(char* out, S32 size);

	// More specific conversions
	Point2I getPoint2I() {
		if (isList())
			return Point2I(
				getListValueDefU(0, 0).getInt(),
				getListValueDefU(1, 0).getInt()
			);
		Point2I ret;
		dSscanf(toString(), "%d %d", &ret.x, &ret.y);
		return ret;
	}

	Point2F getPoint2F() {
		if (isList())
			return Point2F(
				getListValueDefU(0, 0.0).getNumber(),
				getListValueDefU(1, 0.0).getNumber()
			);
		Point2F ret;
		dSscanf(toString(), "%g %g", &ret.x, &ret.y);
		return ret;
	}

	// Point3F can be the max of a console box3F, so allow an offset.
	Point3F getPoint3F(S64 offset = 0) {
		if (isList())
			return Point3F(
				getListValueDefU(offset  , 0.0).getNumber(),
				getListValueDefU(offset+1, 0.0).getNumber(),
				getListValueDefU(offset+2, 0.0).getNumber()
			);
		else return Point3F(toString());
	}

	// Point4F can be an AngleAxis in a console matrix, so allow an offset.
	Point4F getPoint4F(S64 offset = 0) {
		if (isList())
			return Point4F(
				getListValueDefU(offset  , 0.0).getNumber(),
				getListValueDefU(offset+1, 0.0).getNumber(),
				getListValueDefU(offset+2, 0.0).getNumber(),
				getListValueDefU(offset+3, 0.0).getNumber()
			);
		Point4F ret;
		dSscanf(toString(), "%g %g %g %g", &ret.x, &ret.y, &ret.z, &ret.w);
		return ret;
	}

	ColorF getColorF() {
		if (isList())
			return ColorF(
				getListValueDefU(0, 0.0).getNumber(),
				getListValueDefU(1, 0.0).getNumber(),
				getListValueDefU(2, 0.0).getNumber(),
				getListValueDefU(3, 1.0).getNumber() // default alpha: 1.0
			);
		ColorF ret(0.f, 0.f, 0.f, 1.f);
		dSscanf(toString(), "%g %g %g %g", &ret.red, &ret.green, &ret.blue, &ret.alpha);
		return ret;
	}

	ColorI getColorI() {
		if (isList())
			return ColorI(
				getListValueDefU(0,  0).getInt(),
				getListValueDefU(1,  0).getInt(),
				getListValueDefU(2,  0).getInt(),
				getListValueDefU(3,255).getInt() // default alpha: 255
			);
		ColorI ret(0, 0, 0, 255);
		dSscanf(toString(), "%hhu %hhu %hhu %hhu", &ret.red, &ret.green, &ret.blue, &ret.alpha);
		return ret;
	}

	// Network serialization
	void pack(U64 size, char* buffer) const;
	bool unpack(U64 size, char* buffer);
};

/**
	Reference-type value for ConsoleValue
 */
class ConsoleValueList : public Vector<ConsoleValue>
{
	typedef Vector<ConsoleValue> Parent;
	mutable S32 mRefCount;

public:
	// Auto-increment ref-count when constructing
	ConsoleValueList(bool incRef = false)
		: mRefCount(incRef)
		, Parent()
	{}

	ConsoleValueList::~ConsoleValueList() {
		for (ConsoleValue* itr = begin(); itr != end(); itr++)
			itr->clear();
	}

	void incRef() const { ++mRefCount; }
	void decRef() {
		// TODO: Free'd list pool?
		if (!--mRefCount)
			delete this;
	}

	void copyList(ConsoleValueList const& lcv) {
		reserve(lcv.size());
		for (S32 i = 0; i < lcv.size(); ++i)
			constructInPlace(&operator[](i), &lcv[i]);
	}

	ConsoleValue& at(S32 index) { return (*this)[index]; }
	ConsoleValue const& at(S32 index) const { return (*this)[index]; }

	// SHADOW METHODS! NEVER USE DYNAMICALLY FROM BASE CLASS!

	void clear() {
		for (ConsoleValue* itr = begin(); itr != end(); itr++)
			itr->~ConsoleValue();
		Parent::clear();
	}

	void push_back(const ConsoleValue& cv) {
		increment();
		constructInPlace(&last(), &cv);
	}

	// Static constructor

	template <typename ...CVArgs>
	static ConsoleValueList* from(CVArgs const&... args) {
		S64 i = 0;
		auto* list = new ConsoleValueList;
		list->increment(sizeof...(CVArgs));
		int dummy[sizeof...(CVArgs)] =
		{ (constructInPlace<ConsoleValue>(&list->at(i++), &ConsoleValue(Con::Cast(args))),0)... };
		return list;
	}
};

inline ConsoleValue::ConsoleValue(ConsoleValueList* lcv)
	: type(TypeValueList)
{
	if (lcv)	copyList(lcv);
	else		list = new ConsoleValueList;
}

inline ConsoleValue& ConsoleValue::operator = (ConsoleValue const& rhs) {
	// Edge case where self-assignment can lose the list from clearing.
	bool shared = type == TypeValueList && list && this == &rhs;
	if (shared) list->incRef();
	clear();
	switch ((type = rhs.type)) {
	case TypeInt:
	case TypeFloat:
		i = rhs.i;
		break;
	case TypeString:
		if (this != &rhs) str.length = 0;
		copyString(rhs);
		break;
	case TypeValueList:
		copyList(rhs.list);
		break;
	}
	if (shared) list->decRef();
	return *this;
}

inline void ConsoleValue::destroyList(ConsoleValueList*& lcv)
{
	AssertFatal(lcv, "Destroying null list in ConsoleValue!");
	lcv->decRef();
	lcv = NULL;
}

inline void ConsoleValue::copyList(ConsoleValueList* lcv)
{
	AssertFatal(lcv, "Copying null list in ConsoleValue!");
	lcv->incRef();
	list = lcv;
}

inline size_t ConsoleValue::getListSizeU() const
{ return list->size(); }

inline ConsoleValue& ConsoleValue::getListValueU(U32 i)
{ return (*list)[i]; }

inline ConsoleValue const& ConsoleValue::getListValueU(U32 i) const
{ return (*list)[i]; }

inline ConsoleValue const& ConsoleValue::getListValueDefU(U32 i, ConsoleValue const& def) const {
	return getListSizeU() > i ? (*list)[i] : def;
}

inline ConsoleValueList const& ConsoleValue::getListU() const
{ return *list; }

inline ConsoleValueList& ConsoleValue::getListU()
{ return *list; }

inline bool ConsoleValue::isNull() const {
	switch (type) {
	case TypeInt:
	case TypeFloat:
		return i == 0;
	case TypeString:
		return str.length == 0;
	case TypeValueList:
		return list->empty() || (list->size() == 1 && (*list)[0].isNull());
	}
	return false;
}

// Quick float getter
inline F64 ConsoleValue::getNumber() const {
	switch (type) {
	case TypeInt: return i;
	case TypeFloat: return f;
	case TypeString: return dAtof(getString());
	case TypeValueList:
		return list->empty() ? 0.0 : (*list)[0].getNumber();
	}
	return 0.0;
}

// Quick integer getter
inline S64 ConsoleValue::getInt() const {
	switch (type) {
	case TypeInt: return i;
	case TypeFloat: return f;
	case TypeString: return dAtoi(getString());
	case TypeValueList:
		return list->empty() ? 0 : (*list)[0].getInt();
	}
	return 0LL;
}

// 32-byte limit is somewhat arbitrary, but huge console values will be significantly slower.
static_assert(sizeof(ConsoleValue) <= 32UL, "Please keep ConsoleValue within 32 bytes.");
static_assert(sizeof(ConsoleValue) <= 256UL, "Upper limit for cache lines.");

// When there's really no way out.
class ReturnBuffer {
	char* mBuffer;
	size_t mSize;

public:
	ReturnBuffer(size_t size)
		: mBuffer(NULL)
	{
		if (size) mBuffer = (char*) dMalloc(size * sizeof(char));
	}

	~ReturnBuffer() {
		if (mBuffer) dFree(mBuffer);
	}

	ConsoleValue toValue() const { return ConsoleValue(mBuffer); }

	char* ptr() { return mBuffer; }
	char const* string() const { return mBuffer; }
	size_t size() const { return mSize; }

	operator ConsoleValue() const { return ConsoleValue(mBuffer); }
	char* operator *() { return mBuffer; }
};

#endif
