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

// Size for small string in console value
#define CONVALUE_SSO_SIZE 16

// Construct a null console value.
// (The default constructor makes a list.)
#define CONVALUE_NULL (ConsoleValue(""))

class ConsoleValueList;

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
				char small[CONVALUE_SSO_SIZE];	///< Small-size string
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
				str.ptr = (char*) dMalloc(strPSize(len));
				if (intact) dMemmove(str.ptr, str.small, oldLen + 1);
			}
			return str.ptr;
		}
		else if (oldLen >= CONVALUE_SSO_SIZE) {
			dFree(str.ptr);
			str.ptr = NULL;
		}
		return str.small;
	}

	void setString(char const* in) {
		size_t newLen = dStrlen(in);
		char* buf = validateStrSize(newLen);
		if (newLen > 0)
			dMemmove(buf, in, (str.length + 1) * sizeof(char));
	}

	void copyString(ConsoleValue const& rhs) {
		size_t newLen = rhs.str.length;
		char* buf = validateStrSize(newLen);
		if (newLen > 0)
			dMemcpy(buf, rhs.getString(), (str.length + 1) * sizeof(char));
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

	char const* getString() const {
		return str.length < CONVALUE_SSO_SIZE ? str.small : str.ptr;
	}

	void clearString() {
		if (str.length >= CONVALUE_SSO_SIZE)
			dFree(str.ptr);
		str.length = 0;
	}

	void clear(bool coherent = false) {
		if (type == TypeString && str.length >= CONVALUE_SSO_SIZE)
			dFree(str.ptr);
		else if (type == TypeValueList) {
			destroyList(list);
		}
		// If we need a coherent value afterwards, just nullify it.
		if (coherent) {
			type = TypeInt;
			i = 0;
		}
	}

public:
	~ConsoleValue() { clear(); }

	ConsoleValue(ConsoleValue const& rhs)
		: type(rhs.type)
	{
		switch (type) {
		case TypeInt:
		case TypeFloat:
			i = rhs.i;
		case TypeString:
			setString(rhs.getString());
		case TypeValueList:
			copyList(rhs.list);
		}
	}

	ConsoleValue& operator = (ConsoleValue const& rhs) {
		clear();
		switch ((type = rhs.type)) {
		case TypeInt:
		case TypeFloat:
			i = rhs.i;
		case TypeString:
			setString(rhs.getString());
		case TypeValueList:
			copyList(rhs.list);
		}
		return *this;
	}

	ConsoleValue(S64 val)
		: type(TypeInt)
	{ i = val; }

	ConsoleValue(char const* val)
		: type(TypeString)
	{ setString(val); }

	ConsoleValue(F64 val)
		: type(TypeFloat)
	{ f = val; }

	ConsoleValue(ConsoleValueList* lcv = NULL)
		: type(TypeValueList)
	{
		if (lcv)	copyList(lcv);
		else		list = new ConsoleValueList;
	}

	void clearValue() { clear(true); }

	bool isNull() const {
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

	// More restrictive null check
	bool isNullString() const {
		return type == TypeString && str.length == 0;
	}

	// Quick float getter
	F64 getNumber() const {
		switch (type) {
		case TypeInt: return i;
		case TypeFloat: return f;
		case TypeString: return dAtof(getString());
		case TypeValueList:
			return list->empty() ? 0.0 : (*list)[0].getNumber();
		}
	}

	// Quick integer getter
	S64 getInt() const {
		switch (type) {
		case TypeInt: return i;
		case TypeFloat: return f;
		case TypeString: return dAtoi(getString());
		case TypeValueList:
			return list->empty() ? 0 : (*list)[0].getInt();
		}
	}

	Type getType() const { return type; }

	bool castTo(Type dstType);

	bool isList() const { return type == TypeValueList; }

	// Unchecked getters (used after getType() or a successful castTo(T)).

	S64 getIntU() const { return i; }
	F64 getFloatU() const { return f; }
	char const* getStringU() const { return getString(); }
	Vector<ConsoleValue> const& getListU() const { return *list; }
	Vector<ConsoleValue>& getListU() { return *list; }

	size_t getListSizeU() const { return list->size(); }
	ConsoleValue& getListValueU(U32 i) { return (*list)[i]; }
	ConsoleValue const& getListValueU(U32 i) const { return (*list)[i]; }

	// Checked toString (mutates console value!)
	char const* toString() { return castTo(TypeString)? getString() : ""; }
	StringTableEntry toSTString() { return StringTable->insert(toString()); }

	// Non-mutating toString, requires an output buffer.
	S32 toString(char* out, S32 size) const;

	// Fancier "toString" method to write down console values with their real syntax.
	S32 serialize(char* out, S32 size);
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
	ConsoleValueList(bool incRef = true)
		: mRefCount(incRef)
		, Parent()
	{}

	ConsoleValueList::~ConsoleValueList() {
		for (ConsoleValue* itr = begin(); itr != end(); itr++)
			itr->~ConsoleValue();
		Parent::~Vector();
	}

	void incRef() const { ++mRefCount; }
	void decRef() {
		// TODO: Free'd list pool?
		if (--mRefCount)
			delete this;
	}

	void copyList(ConsoleValueList const& lcv) {
		reserve(lcv.size());
		for (S32 i = 0; i < lcv.size(); ++i)
			constructInPlace(&operator[](i), &lcv[i]);
	}

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
};

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

// 32-byte limit is somewhat arbitrary, but huge console values will be significantly slower.
static_assert(sizeof(ConsoleValue) <= 32UL, "Please keep ConsoleValue within 32 bytes.");
static_assert(sizeof(ConsoleValue) <= 256UL, "Upper limit for cache lines.");

#endif
