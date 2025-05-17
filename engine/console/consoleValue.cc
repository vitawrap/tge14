//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#include "console/console.h"
#include "console/consoleValue.h"

const int stringCSize = 1024;
thread_local static char stringConv[stringCSize];

bool ConsoleValue::castTo(ConsoleValue::Type dstType) {
	ConsoleValue::Type const srcType = type;

	switch (dstType) {
	case TypeString:
		switch (srcType) {
		case TypeInt:
			dSprintf(stringConv, stringCSize, "%d", i);
			setString(stringConv);
			break;

		case TypeFloat:
			dSprintf(stringConv, stringCSize, "%f", f);
			setString(stringConv);
			break;

		//case TypeValueList:
		//	// In true torquescript fashion, string->list can become a word list.
		//	ConsoleValueList* vlist = list;
		//	str.length = 0;
		//	for (ConsoleValue* itr = vlist->begin(); itr != vlist->end(); itr++) {
		//		concat(*itr);
		//		if (itr + 1 != vlist->end())
		//			concat(" ");
		//	}
		//	destroyList(vlist);	// unref the list we had
		//	break;

		case TypeString:
			return true;

		default:
			return false;
		}
		break;

	case TypeFloat:
		switch (srcType) {
		case TypeString:
			F64 fval = dAtof(getString());
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
			S64 ival = dAtoi(getString());
			clearString();	// clear union
			i = ival;
			break;

		case TypeFloat:
			i = f;
			break;

		case TypeValueList:
			if (list->size()) {
				*this = list->first();
				castTo(dstType);
			} else i = 0;
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
	ConsoleValue strBuf("");
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
		expandEscape(stringConv, getString());
		strBuf.concat("\"");
		strBuf.concat(stringConv);
		strBuf.concat("\"");
		break;

	case TypeValueList:
		strBuf.concat("{");
		for (ConsoleValue* itr = list->begin(); itr != list->end(); itr++) {
			itr->serialize(stringConv, stringCSize);
			strBuf.concat(stringConv);
			if (itr + 1 != list->end())
				strBuf.concat(",");
		}
		strBuf.concat("}");
		break;
	}

	dSprintf(out, size, "%s", strBuf.getString());
}
