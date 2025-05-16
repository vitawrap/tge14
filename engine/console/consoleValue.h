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
		U64 i;
		F64 f;
		Vector<ConsoleValue> list;
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

	// Run destructors for all console values in the list, and clear.
	void destroyList(Vector<ConsoleValue>& lcv) {
		for (ConsoleValue* itr = lcv.begin(); itr != lcv.end(); itr++)
			itr->~ConsoleValue();
		lcv.clear();	// destructor should come shortly after
	}

	// Does not destroy our list before copying over.
	void copyList(Vector<ConsoleValue> const& lcv) {
		list.reserve(lcv.size());
		for (S32 i = 0; i < lcv.size(); ++i)
			constructInPlace(&list[i], &lcv[i]);
	}

	void setString(char const* in) {
		str.length = 0;
		while (in && in[str.length])
			++str.length;
		if (str.length >= CONVALUE_SSO_SIZE) {
			str.ptr = new char[str.length + 1];
			dMemmove(str.ptr, in, (str.length + 1) * sizeof(char));
		}
		else if (str.length > 0)
			dMemmove(str.small, in, (str.length + 1) * sizeof(char));
	}

	void copyString(ConsoleValue const& rhs) {
		str.length = rhs.str.length;
		if (str.length >= CONVALUE_SSO_SIZE) {
			str.ptr = new char[str.length + 1];
			dMemcpy(str.ptr, rhs.str.ptr, (str.length + 1) * sizeof(char));
		}
		else if (str.length > 0)
			dMemcpy(str.small, rhs.str.small, (str.length + 1) * sizeof(char));
	}

	void concat(ConsoleValue const& rhs) {
		char const* rStr = rhs.getString();
		size_t csz = str.length + rhs.str.length;
		char* buf = NULL;
		if (str.length < CONVALUE_SSO_SIZE && csz >= CONVALUE_SSO_SIZE) {
			buf = new char[csz + 1];
			dMemmove(buf, str.small, str.length * sizeof(char));
			str.ptr = buf;
		}
		else
			buf = str.small;
		dMemcpy(&buf[str.length], rStr, (rhs.str.length + 1) * sizeof(char));
	}

	char const* getString() const {
		return str.length < CONVALUE_SSO_SIZE ? str.small : str.ptr;
	}

	void clearString() {
		if (str.length >= CONVALUE_SSO_SIZE)
			delete[] str.ptr;
		str.length = 0;
	}

	void clear(bool coherent = false) {
		if (type == TypeString && str.length >= CONVALUE_SSO_SIZE)
			delete[] str.ptr;
		else if (type == TypeValueList) {
			destroyList(list);
			list.~Vector();
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
		type = rhs.type;
		switch (type) {
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

	ConsoleValue(U64 val)
		: type(TypeInt)
	{ i = val; }

	ConsoleValue(char const* val)
		: type(TypeString)
	{ setString(val); }

	ConsoleValue(F64 val)
		: type(TypeFloat)
	{ f = val; }

	ConsoleValue()
		: type(TypeValueList)
	{ constructInPlace(&list); }

	void clearValue() { clear(true); }

	bool isNull() const {
		switch (type) {
		case TypeInt:
		case TypeFloat:
			return i == 0;
		case TypeString:
			return str.length == 0;
		case TypeValueList:
			return list.empty() || (list.size() == 1 && list[0].isNull());
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
			return list.empty() ? 0.0 : list[0].getNumber();
		}
	}

	// Quick integer getter
	U64 getInt() const {
		switch (type) {
		case TypeInt: return i;
		case TypeFloat: return f;
		case TypeString: return dAtoi(getString());
		case TypeValueList:
			return list.empty() ? 0 : list[0].getInt();
		}
	}

	Type getType() const { return type; }

	void castTo(Type dstType);

	// Unchecked getters (used after getType() or a successful castTo(T)).

	U64 getIntU() const { return i; }
	F64 getFloatU() const { return f; }
	char const* getStringU() const { return getString(); }
	Vector<ConsoleValue> const& getListU() const { return list; }
	Vector<ConsoleValue>& getListU() { return list; }

	size_t getListSizeU() const { return list.size(); }
	ConsoleValue& getListValueU(U32 i) { return list[i]; }
	ConsoleValue const& getListValueU(U32 i) const { return list[i]; }

	// Checked toString (mutates console value!)

	char const* toString() { castTo(TypeString); return getString(); }
	StringTableEntry toSTString() { return StringTable->insert(toString()); }


};

// 32-byte limit is somewhat arbitrary, but huge console values will be significantly slower.
#ifdef TORQUE_DEBUG_GUARD
static_assert(sizeof(ConsoleValue) <= 40UL, "Please keep ConsoleValue within 40 bytes.");
#else
static_assert(sizeof(ConsoleValue) <= 32UL, "Please keep ConsoleValue within 32 bytes.");
#endif

static_assert(sizeof(ConsoleValue) <= 256UL, "Upper limit for cache lines.");

#endif
