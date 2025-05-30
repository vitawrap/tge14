//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#include "console/console.h"
#include "console/consoleValue.h"
#include "core/memstream.h"

const int stringCSize = 1024;
thread_local static char stringConv[stringCSize];

bool ConsoleValue::castTo(ConsoleValue::Type dstType) {
	ConsoleValue::Type const srcType = type;

	F64 fval;
	S64 ival;
	ConsoleValueList* vlist;

	switch (dstType) {
	case TypeString:
		switch (srcType) {
		case TypeInt:
			dSprintf(stringConv, stringCSize, "%d", i);
			str.length = 0; // reset state
			setString(stringConv);
			break;

		case TypeFloat:
			dSprintf(stringConv, stringCSize, "%g", f);
			str.length = 0; // reset state
			setString(stringConv);
			break;

		case TypeValueList:
			// In true torquescript fashion, string->list can become a word list.
			vlist = list;
			str.length = 0;
			for (ConsoleValue* itr = vlist->begin(); itr != vlist->end(); itr++) {
				concatU(*itr);
				if (itr + 1 != vlist->end())
					concatString(" ", 1);
			}
			destroyList(vlist);	// unref the list we had
			break;

		case TypeString:
			return true;

		default:
			return false;
		}
		break;

	case TypeFloat:
		switch (srcType) {
		case TypeString:
			fval = dAtof(getString());
			clearString();	// clear union
			f = fval;
			break;

		case TypeInt:
			f = i;
			break;

		//case TypeValueList:
		//	if (list->size()) {
		//		*this = list->first();
		//		castTo(dstType);
		//	} else f = 0.0;
		//	destroyList(list);
		//	break;

		case TypeFloat:
			return true;

		default:
			return false;
		}
		break;

	case TypeInt:
		switch (srcType) {
		case TypeString:
			ival = dAtoi(getString());
			clearString();	// clear union
			i = ival;
			break;

		case TypeFloat:
			i = f;
			break;

		case TypeValueList:
			if (list->size()) {
				vlist = list;
				*this = vlist->first();
				castTo(dstType);
				destroyList(vlist);
				break;
			}
			i = 0;
			destroyList(list);
			break;

		case TypeInt:
			return true;

		default:
			return false;
		}
		break;

	case TypeValueList:
		if (srcType == TypeValueList)
			return true;
	//	if (srcType != TypeValueList) {
	//		auto* vl = new ConsoleValueList;
	//		vl->push_back(ConsoleValue(*this));
	//		list = NULL;
	//		copyList(vl);
	//	}
	//	break;
	default:
		return false;
	}

	type = dstType;
	return true;
}

S32 ConsoleValue::toString(char* out, S32 size) const {
	ConsoleValue strBuf(*this);
	char const* str = strBuf.toString();
	return dSprintf(out, size, "%s", str);
}

S32 ConsoleValue::serialize(char* out, S32 size) {
	ConsoleValue strBuf;
	switch (type) {
	case TypeInt:
		dSprintf(stringConv, stringCSize, "%d", i);
		strBuf.setString(stringConv);
		break;

	case TypeFloat:
		dSprintf(stringConv, stringCSize, "%g", i);
		strBuf.setString(stringConv);
		break;

	case TypeString:
		// TODO: Failsafe for expandEscape size
		const_cast<char*>(getString())[str.length] = 0;
		expandEscape(stringConv, getString());
		strBuf.concatStringU("\"", 1);
		strBuf.concatStringU(stringConv, dStrlen(stringConv));
		strBuf.concatStringU("\"", 1);
		break;

	case TypeValueList:
		strBuf.concat("{");
		for (ConsoleValue* itr = list->begin(); itr != list->end(); itr++) {
			itr->serialize(stringConv, stringCSize);
			strBuf.concatStringU(stringConv, dStrlen(stringConv));
			if (itr + 1 != list->end())
				strBuf.concatStringU(",", 1);
		}
		strBuf.concatStringU("}", 1);
		break;
	}

	return dSprintf(out, size, "%s", strBuf.getString());
}

void ConsoleValue::innerPack(MemStream& stream) const
{
	switch (type) {
	case TypeInt:
		stream.write((U8)'I');
		stream.write((S32) i); // TODO: Split into two S32's
		break;
	case TypeFloat:
		stream.write((U8)'F');
		stream.write(f);
		break;
	case TypeString:
		stream.write((U8)'S');
		stream.writeString(getString());
		break;
	case TypeValueList:
		stream.write((U8)'L');
		stream.write((U16)list->size());
		for (S32 i = 0; i < list->size(); ++i)
			list->at(i).innerPack(stream);
		break;
	}
}

bool ConsoleValue::innerUnpack(MemStream& stream)
{
	clear(true);

	U8 key;
	stream.read(&key);
	switch (key) {
	case 'I': {
		type = TypeInt;
		S32 smallInt;
		stream.read(&smallInt);
		i = (S64) smallInt;
	}
		break;
	case 'F':
		type = TypeFloat;
		stream.read(&f);
		break;
	case 'S': {
		type = TypeString;
		char stringBuffer[256];
		stream.readString(stringBuffer);
		setString(stringBuffer);
	}
		break;
	case 'L': {
		type = TypeValueList;
		list = new ConsoleValueList(true);
		U16 listSize;
		stream.read(&listSize);
		while (listSize--) {
			ConsoleValue val;
			if (!val.innerUnpack(stream))
				return false;
			list->push_back(val);
		}
	}
		break;
	default:
		return false;
	}
	return true;
}

void ConsoleValue::pack(U64 size, char* buffer) const
{
	MemStream stream(size, buffer, false, true);
	innerPack(stream);
}

bool ConsoleValue::unpack(U64 size, char* buffer)
{
	MemStream stream(size, buffer, true, false);
	return innerUnpack(stream);
}

bool ConsoleValue::isTagString() const
{
	return (type == TypeString) && (getString()[0] == StringTagPrefixByte);
}
