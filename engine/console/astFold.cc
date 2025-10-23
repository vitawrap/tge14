//-----------------------------------------------------------------------------
// Torque Game Engine 
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#include "console/consoleValue.h"
#include "console/compiler.h"

//-----------------------------------------------------------------------------
// The folding system heavily relies on consoleAlloc to be able to carelessly
// replace nodes with new ones on the fly. Otherwise it would be a pain to do.
//-----------------------------------------------------------------------------

static inline bool isConstNode(StmtNode* node) {
	return node->getFoldType() > TypeConstUnknown;
}

// When one of the operators is a float, try to short the other into a float too.
static inline bool tryCoerceFloat(ConsoleValue& left, ConsoleValue& right) {
	if (left.getType() == ConsoleValue::TypeFloat)
		return right.castTo(ConsoleValue::TypeFloat);
	if (right.getType() == ConsoleValue::TypeFloat)
		return left.castTo(ConsoleValue::TypeFloat);
	return false;
}

// ...or when one of the operators is an int, try to short the other into an int too.
static inline bool tryCoerceInt(ConsoleValue& left, ConsoleValue& right) {
	if (left.getType() == ConsoleValue::TypeInt)
		return right.castTo(ConsoleValue::TypeInt);
	if (right.getType() == ConsoleValue::TypeInt)
		return left.castTo(ConsoleValue::TypeInt);
	return false;
}

// This forces the compiler to only generate nodeBinaryOp when it has a T
// to check against this (otherwise it can decide to always generate the default case).
template <typename T>
struct AssertFail {
	static constexpr bool value = false;
};

template <typename T>
static T nodeBinaryOp(ConsoleValue& lVal, ConsoleValue& rVal, S32 op) {
	static_assert(AssertFail<T>::value, "Illegal type for nodeBinaryOp<T>.");
	return T();
}

#define CommonBinaryOps(l, r, getter)				\
case '+': return (l).getter() + (r).getter();		\
case '-': return (l).getter() - (r).getter();		\
case '*': return (l).getter() * (r).getter();		\
case '/': return (l).getter() / (r).getter();		\
case '<': return (l).getter() < (r).getter();		\
case '>': return (l).getter() > (r).getter();		\
case opEQ: return (l).getter() == (r).getter();		\
case opGE: return (l).getter() >= (r).getter();		\
case opLE: return (l).getter() <= (r).getter();		\
case opNE: return (l).getter() != (r).getter();		\
case opOR: return (l).getter() ? (l).getter() : (r).getter();

template <>
static S64 nodeBinaryOp<S64>(ConsoleValue& lVal, ConsoleValue& rVal, S32 op) {
	switch (op) {
	CommonBinaryOps(lVal, rVal, getInt)
	case '%': return lVal.getInt() % rVal.getInt();
	case opAND: return lVal.getInt()? rVal.getInt() : 0LL;
	case '&': return lVal.getInt() & rVal.getInt();
	case '|': return lVal.getInt() | rVal.getInt();
	case '^': return lVal.getInt() ^ rVal.getInt();
	case opSHL: return lVal.getInt() << rVal.getInt();
	case opSHR: return lVal.getInt() >> rVal.getInt();
	}
	AssertFatal(false, "Failed to fold binary operator for 2 int constants");
	return 0LL;
}

template <>
static F64 nodeBinaryOp<F64>(ConsoleValue& lVal, ConsoleValue& rVal, S32 op) {
	switch (op) {
	CommonBinaryOps(lVal, rVal, getNumber)
	case '%': return fmod(lVal.getNumber(), rVal.getNumber());
	case opAND: return lVal.getNumber() ? rVal.getNumber() : 0.0;
	}
	AssertFatal(false, "Failed to fold binary operator for 2 float constants");
	return 0LL;
}

// Merge as much of the array expr as we can to the varname.
// The return value is the nonconstant array expr that must be evaulated at runtime.
static ExprNode* foldArrayExpr(StringTableEntry& varName, ExprNode* varArray, S32 depth = 0) {
	if (isConstNode(varArray)) {
		char merge[512];
		dSprintf(merge, sizeof(merge), depth? "%s_%s" : "%s%s", varName, varArray->getFoldValue().toString());
		varName = StringTable->insert(merge);
		return NULL;
	}
	else if (dynamic_cast<CommaCatExprNode*>(varArray)) {
		auto* cat = reinterpret_cast<CommaCatExprNode*>(varArray);
		if (!foldArrayExpr(varName, cat->left, depth))
			return foldArrayExpr(varName, cat->right, depth+1);
	}
	return varArray;
}

//-----------------------------------------------------------------------------

ConsoleValue StmtNode::getFoldValue() const { return ""; }

// FIXME: Does this work with tags?
ConsoleValue StrConstNode::getFoldValue() const { return str; }
ConsoleValue ConstantNode::getFoldValue() const { return value; }
ConsoleValue IntNode::getFoldValue() const { return value; }
ConsoleValue FloatNode::getFoldValue() const { return value; }

//-----------------------------------------------------------------------------
// ExprNodes
//-----------------------------------------------------------------------------

#define FoldNullableExpr(expr) { if (expr) expr = (ExprNode*) expr->fold(); }
#define FoldNullableArrayExpr(name, expr) \
{ if (expr) { expr = (ExprNode*) expr->fold(); expr = foldArrayExpr(name, expr); } }

// Default implementation for binary expr nodes
StmtNode* BinaryExprNode::fold() {
	right = (ExprNode*)right->fold();
	left = (ExprNode*)left->fold();
	return this;
}

StmtNode* IntBinaryExprNode::fold() {
	right = (ExprNode*) right->fold();
	left = (ExprNode*) left->fold();
	if (isConstNode(left) && isConstNode(right)) {
		ConsoleValue lVal = left->getFoldValue();
		ConsoleValue rVal = right->getFoldValue();
		if (tryCoerceInt(lVal, rVal))
			return IntNode::alloc(nodeBinaryOp<S64>(lVal, rVal, op));
		if (tryCoerceFloat(lVal, rVal))
			return FloatNode::alloc(nodeBinaryOp<F64>(lVal, rVal, op));
	}
	return this;
}

StmtNode* FloatBinaryExprNode::fold() {
	right = (ExprNode*)right->fold();
	left = (ExprNode*)left->fold();
	if (isConstNode(left) && isConstNode(right)) {
		ConsoleValue lVal = left->getFoldValue();
		ConsoleValue rVal = right->getFoldValue();
		if (tryCoerceFloat(lVal, rVal))
			return FloatNode::alloc(nodeBinaryOp<F64>(lVal, rVal, op));
	}
	return this;
}

StmtNode* IntUnaryExprNode::fold() {
	expr = (ExprNode*) expr->fold();
	if (isConstNode(expr)) {
		ConsoleValue val = expr->getFoldValue();
		if (val.castTo(ConsoleValue::TypeInt))
			switch (op) {
			case '!': return IntNode::alloc(!val.getIntU());
			case '~': return IntNode::alloc(~val.getIntU());
			}
	}
	return this;
}

StmtNode* FloatUnaryExprNode::fold() {
	expr = (ExprNode*) expr->fold();
	if (isConstNode(expr)) {
		ConsoleValue val = expr->getFoldValue();
		if (val.castTo(ConsoleValue::TypeFloat))
			return FloatNode::alloc(-val.getFloatU());
	}
	return this;
}

StmtNode* StrConstNode::fold() {
	if (Compiler::consoleStringIsNumber(str))
		return FloatNode::alloc(Compiler::consoleStringToNumber(str, dbgFileName, dbgLineNumber));
	return this;
}

StmtNode* StreqExprNode::fold() {
	left = (ExprNode*)left->fold();
	right = (ExprNode*)right->fold();
	if (isConstNode(left) && isConstNode(right)) {
		ConsoleValue lVal = left->getFoldValue();
		ConsoleValue rVal = right->getFoldValue();
		if (lVal.castTo(ConsoleValue::TypeString))
			return IntNode::alloc(eq? !lVal.compare(rVal) : !!lVal.compare(rVal));
	}
	else if (isConstNode(right) && right->getFoldValue().isNullString())
		nullCheck = true;
	else if (isConstNode(left) && left->getFoldValue().isNullString())
		nullCheck = true, left = right; // deal with symmetrical case
	return this;
}

StmtNode* StrcatExprNode::fold() {
	left = (ExprNode*)left->fold();
	right = (ExprNode*)right->fold();
	if (isConstNode(left) && isConstNode(right)) {
		ConsoleValue lVal = left->getFoldValue();
		ConsoleValue rVal = right->getFoldValue();
		if (lVal.castTo(ConsoleValue::TypeString)) {
			if (appendChar)
				lVal.concatStringU((const char*) &appendChar, 1);
			lVal.concatU(rVal);
			size_t mergeLen = lVal.getStrlenU();
			char* buffer = (char*) Compiler::consoleAlloc(mergeLen + 1);
			dStrcpy(buffer, lVal.getStringU());
			buffer[mergeLen] = 0;
			return StrConstNode::alloc(buffer, false);
		}
	}
	return this;
}

StmtNode* CommaCatExprNode::fold() {
	left = (ExprNode*)left->fold();
	right = (ExprNode*)right->fold();
	if (isConstNode(left) && isConstNode(right)) {
		ConsoleValue lVal = left->getFoldValue();
		ConsoleValue rVal = right->getFoldValue();
		if (lVal.castTo(ConsoleValue::TypeString)) {
			lVal.concatStringU("_", 1);
			lVal.concatU(rVal);
			size_t mergeLen = lVal.getStrlenU();
			char* buffer = (char*)Compiler::consoleAlloc(mergeLen + 1);
			dStrcpy(buffer, lVal.getStringU());
			buffer[mergeLen] = 0;
			return StrConstNode::alloc(buffer, false);
		}
	}
	return this;
}

StmtNode* VarNode::fold() {
	FoldNullableArrayExpr(varName, arrayIndex);
	return this;
}

StmtNode* AssignOpExprNode::fold() {
	FoldNullableArrayExpr(varName, arrayIndex);
	expr = (ExprNode*) expr->fold();
	return this;
}

StmtNode* ValueListExprNode::fold() {
	list = foldNodeList(list);
	return this;
}

StmtNode* FuncCallExprNode::fold() {
	args = foldNodeList(args);
	return this;
}

StmtNode* SlotAccessNode::fold() {
	objectExpr = (ExprNode*) objectExpr->fold();
	FoldNullableExpr(arrayExpr);	// cannot merge array when dealing with slots
	return this;
}

StmtNode* SlotAssignNode::fold() {
	FoldNullableExpr(arrayExpr);	// cannot merge array when dealing with slots
	FoldNullableExpr(objectExpr);
	valueExpr = (ExprNode*)valueExpr->fold();
	return this;
}

StmtNode* SlotAssignOpNode::fold() {
	objectExpr = (ExprNode*)objectExpr->fold();
	valueExpr = (ExprNode*)valueExpr->fold();
	FoldNullableExpr(arrayExpr);	// cannot merge array when dealing with slots
	return this;
}

StmtNode* AssignExprNode::fold() {
	expr = (ExprNode*)expr->fold();
	FoldNullableArrayExpr(varName, arrayIndex);
	return this;
}

StmtNode* StrForgiveExprNode::fold() {
	left = (ExprNode*)left->fold();
	right = (ExprNode*)right->fold();
	if (isConstNode(left) && isConstNode(right)) {
		ConsoleValue lVal = left->getFoldValue();
		if (lVal.isNullString())
			return right;
		return left;
	}
	return this;
}

StmtNode* ObjectDeclNode::fold() {
	classNameExpr = (ExprNode*)classNameExpr->fold();
	objectNameExpr = (ExprNode*)objectNameExpr->fold();
	slotDecls = foldNodeList(slotDecls);
	subObjects = foldNodeList(subObjects);
	argList = foldNodeList(argList);
	return this;
}

StmtNode* ConditionalExprNode::fold() {
	testExpr = (ExprNode*) testExpr->fold();
	trueExpr = (ExprNode*) trueExpr->fold();
	falseExpr= (ExprNode*)falseExpr->fold();
	if (isConstNode(testExpr)) {
		return testExpr->getFoldValue().isNull()?
			falseExpr : trueExpr;
	}
	return this;
}

//-----------------------------------------------------------------------------
// StmtNodes
//-----------------------------------------------------------------------------

StmtNode* ReturnStmtNode::fold() {
	// TODO: Could unlink "next" here too?
	FoldNullableExpr(expr);
	return this;
}

StmtNode* IfStmtNode::fold() {
	testExpr = (ExprNode*) testExpr->fold();
	if (isConstNode(testExpr)) {
		ConsoleValue val = testExpr->getFoldValue();
		if (val.isNull())
			return elseBlock? foldNodeList(elseBlock) : NoStmtNode::alloc();
		return ifBlock? foldNodeList(ifBlock) : NoStmtNode::alloc();
	}
	return this;
}

StmtNode* SwitchStmtNode::fold() {
	// TODO: This should fold like IfStmtNode.
	FoldNullableExpr(testExpr);
	return this;
}

StmtNode* LoopStmtNode::fold() {
	// TODO: Many loop types induce many folding types... need to figure it out.
	FoldNullableExpr(testExpr);
	FoldNullableExpr(initExpr);
	FoldNullableExpr(endLoopExpr);
	loopBlock = foldNodeList(loopBlock);
	return this;
}

StmtNode* FunctionDeclStmtNode::fold() {
	// Do not fold varnodes, they only exist as containers for arg names.
	stmts = foldNodeList(stmts);
	return this;
}
