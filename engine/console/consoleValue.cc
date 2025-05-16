//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#include "console/consoleValue.h"

void ConsoleValue::castTo(ConsoleValue::Type dstType) {
	const int stringCSize = 128;
	thread_local static char stringConv[stringCSize];
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

		case TypeValueList:
			// In true torquescript fashion, string->list can become a word list.
			str.length = 0;
			Vector<ConsoleValue> vlist; list.move(vlist);
			for (ConsoleValue* itr = vlist.begin(); itr != vlist.end(); itr++) {
				concat(*itr);
				if (itr + 1 != list.end())
					concat(" ");
			}
			destroyList(vlist);
			break;
		}
		break;

	case TypeFloat:
		switch (srcType) {
		case TypeString:
			F32 fval = dAtof(getString());
			clearString();	// clear union
			f = fval;
			break;

		case TypeInt:
			f = i;
			break;

		case TypeValueList:
			if (list.size()) {
				*this = list[0];
				castTo(dstType);
			} else f = 0.0;
			destroyList(list);
			break;
		}
		break;

	case TypeInt:
		switch (srcType) {
		case TypeString:
			F32 ival = dAtoi(getString());
			clearString();	// clear union
			i = ival;
			break;

		case TypeFloat:
			i = f;
			break;

		case TypeValueList:
			if (list.size()) {
				*this = list[0];
				castTo(dstType);
			} else i = 0;
			destroyList(list);
			break;
		}
		break;

	case TypeValueList:
		if (srcType != TypeValueList) {
			ConsoleValue primitive(*this);
			constructInPlace(&list);
			list.reserve(1);
			constructInPlace(list.begin(), &primitive);
		}
		break;
	}

	type = dstType;
}
