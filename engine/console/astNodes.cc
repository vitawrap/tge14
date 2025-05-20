//-----------------------------------------------------------------------------
// Torque Game Engine 
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#include "platform/platform.h"
#include "console/console.h"
#include "platform/event.h"

#include "console/ast.h"
#include "core/tAlgorithm.h"
#include "core/resManager.h"

#include "core/findMatch.h"
#include "console/consoleInternal.h"
#include "core/fileStream.h"
#include "console/compiler.h"

#include "console/simBase.h"

// This enables extra breakpoint lines in the DSO output at the
// exit points of functions as well as on code outside of functions
// in the main body of a script file.  We #ifdef this because it
// currently adds many nops to the codeblock to do this.
//#ifdef TORQUE_DEBUG   
//   #define TORQUE_EXTRA_BREAKLINES
//#endif

namespace Compiler
{
   U32 precompileBlock(StmtNode *block, U32 loopCount)
   {
      U32 sum = 0;
      for(StmtNode *walk = block; walk; walk = walk->getNext())
         sum += walk->precompileStmt(loopCount);
      return sum;
   }

   U64 compileBlock(StmtNode *block, U64 *codeStream, U64 ip, U32 continuePoint, U32 breakPoint)
   {
      for(StmtNode *walk = block; walk; walk = walk->getNext())
         ip = walk->compileStmt(codeStream, ip, continuePoint, breakPoint);
      return ip;
   }
};

using namespace Compiler;

//-----------------------------------------------------------------------------

//void StmtNode::addBreakCount()
//{
//   #ifndef TORQUE_EXTRA_BREAKLINES      
//   if(CodeBlock::smInFunction)
//   #endif
//      CodeBlock::smBreakLineCount++;
//}
//
//void StmtNode::addBreakLine(U32 ip)
//{
//   #ifndef TORQUE_EXTRA_BREAKLINES      
//   if(CodeBlock::smInFunction)
//   {
//   #endif
//
//      U32 line = CodeBlock::smBreakLineCount * 2;
//      CodeBlock::smBreakLineCount++;
//
//      if(getBreakCodeBlock()->lineBreakPairs)
//      {
//         getBreakCodeBlock()->lineBreakPairs[line] = dbgLineNumber;
//         getBreakCodeBlock()->lineBreakPairs[line+1] = ip;
//      }
//
//   #ifndef TORQUE_EXTRA_BREAKLINES      
//   }
//   #endif
//}

//------------------------------------------------------------

StmtNode::StmtNode()
{
   next = NULL;
   dbgFileName = CodeBlock::smCurrentParser->getCurrentFile();
   dbgLineNumber = CodeBlock::smCurrentParser->getCurrentLine();
}

void StmtNode::setPackage(StringTableEntry)
{
}

void StmtNode::append(StmtNode *next)
{
   StmtNode *walk = this;
   while(walk->next)
      walk = walk->next;
   walk->next = next;
}


void FunctionDeclStmtNode::setPackage(StringTableEntry packageName)
{
   package = packageName;
}

//------------------------------------------------------------
//
// Console language compilers
//
//------------------------------------------------------------

static void conversionOp(TypeReq src, TypeReq dst, U64* codeStream, U64& ip)
{
   if(src == TypeReqValue && dst == TypeReqNone)
      codeStream[ip++] = OP_VAL_TO_NONE;
   return;
}

static U32 conversionSize(TypeReq src, TypeReq dst)
{
   if (src == TypeReqValue && dst == TypeReqNone)
       return 1;
   return 0;
}

//------------------------------------------------------------

U32 BreakStmtNode::precompileStmt(U32 loopCount)
{
   if(loopCount)
   {
      //addBreakCount();
      return 2;
   }
   Con::warnf(ConsoleLogEntry::General, "%s (%d): break outside of loop... ignoring.", dbgFileName, dbgLineNumber);
   return 0;
}

U32 BreakStmtNode::compileStmt(U64 *codeStream, U64 ip, U32, U32 breakPoint)
{
   if(breakPoint)
   {
      //addBreakLine(ip);
      codeStream[ip++] = OP_JMP;
      codeStream[ip++] = breakPoint;
   }
   return ip;
}

//------------------------------------------------------------

U32 ContinueStmtNode::precompileStmt(U32 loopCount)
{
   if(loopCount)
   {
      //addBreakCount();
      return 2;
   }
   Con::warnf(ConsoleLogEntry::General, "%s (%d): continue outside of loop... ignoring.", dbgFileName, dbgLineNumber);
   return 0;
}

U32 ContinueStmtNode::compileStmt(U64* codeStream, U64 ip, U32 continuePoint, U32)
{
   if(continuePoint)
   {
      //addBreakLine(ip);
      codeStream[ip++] = OP_JMP;
      codeStream[ip++] = continuePoint;
   }
   return ip;
}

//------------------------------------------------------------

U32 ExprNode::precompileStmt(U32)
{
   //addBreakCount();
   return precompile(TypeReqNone);
}

U32 ExprNode::compileStmt(U64 *codeStream, U64 ip, U32, U32)
{
   //addBreakLine(ip);
   return compile(codeStream, ip, TypeReqNone);
}

//------------------------------------------------------------

U32 ReturnStmtNode::precompileStmt(U32)
{
   //addBreakCount();
   if(!expr)
      return 1;
   else
      return 1 + expr->precompile(TypeReqValue);
}

U32 ReturnStmtNode::compileStmt(U64 *codeStream, U64 ip, U32, U32)
{
   //addBreakLine(ip);
   if(!expr)
      codeStream[ip++] = OP_RETURN_NONE;
   else
   {
      ip = expr->compile(codeStream, ip, TypeReqValue);
      codeStream[ip++] = OP_RETURN;
   }
   return ip;
}

//------------------------------------------------------------

ExprNode *IfStmtNode::getSwitchOR(ExprNode *left, ExprNode *list, bool string)
{
   ExprNode *nextExpr = (ExprNode *) list->getNext();
   ExprNode *test;
   if(string)
      test = StreqExprNode::alloc(left, list, true);
   else
      test = IntBinaryExprNode::alloc(opEQ, left, list);
   if(!nextExpr)
      return test;
   return IntBinaryExprNode::alloc(opOR, test, getSwitchOR(left, nextExpr, string));
}

void IfStmtNode::propagateSwitchExpr(ExprNode *left, bool string)
{
   testExpr = getSwitchOR(left, testExpr, string);
   if(propagate && elseBlock)
      ((IfStmtNode *) elseBlock)->propagateSwitchExpr(left, string);
}

U32 IfStmtNode::precompileStmt(U32 loopCount)
{
   integer = true;
   U32 exprSize = testExpr->precompile(TypeReqValue);

   // next is the JMPIFNOT or JMPIFFNOT - size of 2
   U32 ifSize = precompileBlock(ifBlock, loopCount);
   if(!elseBlock)
      endifOffset = ifSize + 2 + exprSize;
   else
   {
      elseOffset = exprSize + 2 + ifSize + 2;
      U32 elseSize = precompileBlock(elseBlock, loopCount);
      endifOffset = elseOffset + elseSize;
   }
   return endifOffset;
}

U32 IfStmtNode::compileStmt(U64 *codeStream, U64 ip, U32 continuePoint, U32 breakPoint)
{
   U32 start = ip;
   //addBreakLine(ip);

   ip = testExpr->compile(codeStream, ip, TypeReqValue);
   codeStream[ip++] = integer ? OP_JMPIFNOT : OP_JMPIFFNOT;

   if(elseBlock)
   {
      codeStream[ip++] = start + elseOffset;
      ip = compileBlock(ifBlock, codeStream, ip, continuePoint, breakPoint);
      codeStream[ip++] = OP_JMP;
      codeStream[ip++] = start + endifOffset;
      ip = compileBlock(elseBlock, codeStream, ip, continuePoint, breakPoint);
   }
   else
   {
      codeStream[ip++] = start + endifOffset;
      ip = compileBlock(ifBlock, codeStream, ip, continuePoint, breakPoint);
   }
   return ip;
}

//------------------------------------------------------------

U32 LoopStmtNode::precompileStmt(U32 loopCount)
{
   integer = true;
   U32 initSize = 0;
   //addBreakCount();

   if(initExpr)
      initSize = initExpr->precompile(TypeReqNone);

   U32 testSize = testExpr->precompile(TypeReqValue);

   U32 blockSize = precompileBlock(loopBlock, loopCount + 1);

   U32 endLoopSize = 0;
   if(endLoopExpr)
      endLoopSize = endLoopExpr->precompile(TypeReqNone);

   // if it's a for loop or a while loop it goes:
   // initExpr
   // testExpr
   // OP_JMPIFNOT to break point
   // loopStartPoint:
   // loopBlock
   // continuePoint:
   // endLoopExpr
   // testExpr
   // OP_JMPIF loopStartPoint
   // breakPoint:

   // otherwise if it's a do ... while() it goes:
   // initExpr
   // loopStartPoint:
   // loopBlock
   // continuePoint:
   // endLoopExpr
   // testExpr
   // OP_JMPIF loopStartPoint
   // breakPoint:

   if(!isDoLoop)
   {
      loopBlockStartOffset = initSize + testSize + 2;
      continueOffset       = loopBlockStartOffset + blockSize;
      breakOffset          = continueOffset + endLoopSize + testSize + 2;
   }
   else
   {
      loopBlockStartOffset = initSize;
      continueOffset       = initSize + blockSize;
      breakOffset          = continueOffset + endLoopSize + testSize + 2;
   }
   return breakOffset;
}

U32 LoopStmtNode::compileStmt(U64 *codeStream, U64 ip, U32, U32)
{
   //addBreakLine(ip);
   U32 start = ip;
   if(initExpr)
      ip = initExpr->compile(codeStream, ip, TypeReqNone);

   if(!isDoLoop)
   {
      ip = testExpr->compile(codeStream, ip, TypeReqValue);
      codeStream[ip++] = integer ? OP_JMPIFNOT : OP_JMPIFFNOT;
      codeStream[ip++] = start + breakOffset;
   }

   // Compile internals of loop.
   ip = compileBlock(loopBlock, codeStream, ip, start + continueOffset, start + breakOffset);

   if(endLoopExpr)
      ip = endLoopExpr->compile(codeStream, ip, TypeReqNone);

   ip = testExpr->compile(codeStream, ip, TypeReqValue);

   codeStream[ip++] = integer ? OP_JMPIF : OP_JMPIFF;
   codeStream[ip++] = start + loopBlockStartOffset;

   return ip;
}

//------------------------------------------------------------

U32 ConditionalExprNode::precompile(TypeReq type)
{
   // code is testExpr
   // JMPIFNOT falseStart
   // trueExpr
   // JMP end
   // falseExpr
   integer = true;
   return 
      testExpr->precompile(TypeReqValue) +
      trueExpr->precompile(type) +
      falseExpr->precompile(type) + 4;
}

U32 ConditionalExprNode::compile(U64 *codeStream, U64 ip, TypeReq type)
{
   ip = testExpr->compile(codeStream, ip, TypeReqValue);
   codeStream[ip++] = integer ? OP_JMPIFNOT : OP_JMPIFFNOT;
   U32 jumpElseIp = ip++;
   ip = trueExpr->compile(codeStream, ip, type);
   codeStream[ip++] = OP_JMP;
   U32 jumpEndIp = ip++;
   codeStream[jumpElseIp] = ip;
   ip = falseExpr->compile(codeStream, ip, type);
   codeStream[jumpEndIp] = ip;
   return ip;
}

TypeReq ConditionalExprNode::getPreferredType()
{
   return trueExpr->getPreferredType();
}

//------------------------------------------------------------

U32 FloatBinaryExprNode::precompile(TypeReq type)
{
   U32 addSize = left->precompile(TypeReqValue) + right->precompile(TypeReqValue) + 1;
   return addSize + conversionSize(TypeReqValue, type);
}

U32 FloatBinaryExprNode::compile(U64 *codeStream, U64 ip, TypeReq type)
{
   ip = right->compile(codeStream, ip, TypeReqValue);
   ip = left->compile(codeStream, ip, TypeReqValue);
   U32 operand = OP_INVALID;
   switch(op)
   {
   case '+':
      operand = OP_ADD;
      break;
   case '-':
      operand = OP_SUB;
      break;
   case '/':
      operand = OP_DIV;
      break;
   case '*':
      operand = OP_MUL;
      break;
   }
   codeStream[ip++] = operand;
   conversionOp(TypeReqValue, type, codeStream, ip);
   return ip;
}

TypeReq FloatBinaryExprNode::getPreferredType()
{
   return TypeReqValue;
}

//------------------------------------------------------------

void IntBinaryExprNode::getSubTypeOperand()
{
   subType = TypeReqValue;
   switch(op)
   {
   case '^':
      operand = OP_XOR;
      break;
   case '%':
      operand = OP_MOD;
      break;
   case '&':
      operand = OP_BITAND;
      break;
   case '|':
      operand = OP_BITOR;
      break;
   case '<':
      operand = OP_CMPLT;
      break;
   case '>':
      operand = OP_CMPGR;
      break;
   case opGE:
      operand = OP_CMPGE;
      break;
   case opLE:
      operand = OP_CMPLE;
      break;
   case opEQ:
      operand = OP_CMPEQ;
      break;
   case opNE:
      operand = OP_CMPNE;
      break;
   case opOR:
      operand = OP_OR;
      break;
   case opAND:
      operand = OP_AND;
      break;
   case opSHR:
      operand = OP_SHR;
      break;
   case opSHL:
      operand = OP_SHL;
      break;
   }
}

U32 IntBinaryExprNode::precompile(TypeReq type)
{
   getSubTypeOperand();
   U32 addSize = left->precompile(subType) + right->precompile(subType);
   if(operand == OP_OR || operand == OP_AND)
      addSize += 2;
   else
      addSize += 1;
   return addSize + conversionSize(TypeReqValue, type);
}

U32 IntBinaryExprNode::compile(U64 *codeStream, U64 ip, TypeReq type)
{
   if(operand == OP_OR || operand == OP_AND)
   {
      // NP: Keep result on stack if left expr is to be returned, otherwise pop and eval right.
      ip = left->compile(codeStream, ip, subType);
      codeStream[ip++] = operand == OP_OR ? OP_JMPIF_NP : OP_JMPIFNOT_NP;
      U32 jmpIp = ip++;
      ip = right->compile(codeStream, ip, subType);
      codeStream[jmpIp] = ip;
   }
   else
   {
      ip = right->compile(codeStream, ip, subType);
      ip = left->compile(codeStream, ip, subType);
      codeStream[ip++] = operand;
   }
   conversionOp(TypeReqValue, type, codeStream, ip);
   return ip;
}

TypeReq IntBinaryExprNode::getPreferredType()
{
   return TypeReqValue;
}

//------------------------------------------------------------

U32 StreqExprNode::precompile(TypeReq type)
{
   // eval str left
   // eval str right
   // OP_COMPARE_STR
   // if !eq: OP_NOT
   // optional conversion
   U32 addSize = left->precompile(TypeReqValue) + right->precompile(TypeReqValue) + 1;
   if(!eq)
      addSize ++;
   return addSize + conversionSize(TypeReqValue, type);
}

U32 StreqExprNode::compile(U64 *codeStream, U64 ip, TypeReq type)
{
   ip = left->compile(codeStream, ip, TypeReqValue);
   ip = right->compile(codeStream, ip, TypeReqValue);
   codeStream[ip++] = OP_COMPARE_STR;
   if(!eq)
      codeStream[ip++] = OP_NOT;
   conversionOp(TypeReqValue, type, codeStream, ip);
   return ip;
}

TypeReq StreqExprNode::getPreferredType()
{
   return TypeReqValue;
}

//------------------------------------------------------------

U32 StrcatExprNode::precompile(TypeReq type)
{
   U32 addSize = left->precompile(TypeReqValue) + right->precompile(TypeReqValue) + 1;
   if(appendChar)
      addSize += 2;

   return addSize + conversionSize(TypeReqValue, type);
}

U32 StrcatExprNode::compile(U64 *codeStream, U64 ip, TypeReq type)
{
    ip = left->compile(codeStream, ip, TypeReqValue);
    if (appendChar)
    {
        codeStream[ip++] = OP_CONCAT_CHAR;
        codeStream[ip++] = appendChar;
    }
    ip = right->compile(codeStream, ip, TypeReqValue);
    codeStream[ip++] = OP_CONCAT_STR;
    conversionOp(TypeReqValue, type, codeStream, ip);
    return ip;
}

TypeReq StrcatExprNode::getPreferredType()
{
   return TypeReqValue;
}

//------------------------------------------------------------

U32 StrForgiveExprNode::precompile(TypeReq type)
{
    U32 addSize = left->precompile(TypeReqValue) + right->precompile(TypeReqValue) + 3;
    return addSize + conversionSize(TypeReqValue, type);
}

U32 StrForgiveExprNode::compile(U64* codeStream, U64 ip, TypeReq type)
{
    ip = left->compile(codeStream, ip, TypeReqValue);
    codeStream[ip++] = OP_STRNOTNULL;
    codeStream[ip++] = OP_JMPIF;
    U32 jmpIp = ip++;
    ip = right->compile(codeStream, ip, TypeReqValue);
    codeStream[jmpIp] = ip;

    conversionOp(TypeReqValue, type, codeStream, ip);
    return ip;
}

TypeReq StrForgiveExprNode::getPreferredType()
{
    return TypeReqValue;
}

//------------------------------------------------------------

U32 CommaCatExprNode::precompile(TypeReq type)
{
   U32 addSize = left->precompile(TypeReqValue) + right->precompile(TypeReqValue) + 1;
   return addSize + conversionSize(TypeReqValue, type);
}

U32 CommaCatExprNode::compile(U64 *codeStream, U64 ip, TypeReq type)
{
   ip = left->compile(codeStream, ip, TypeReqValue);
   ip = right->compile(codeStream, ip, TypeReqValue);
   codeStream[ip++] = OP_CONCAT_STR_COMMA;

   // At this point the stack has the concatenated string.

   // But we're paranoid, so accept (but whine) if we get an oddity...
   /*if(type == TypeReqUInt || type == TypeReqFloat)
      Con::warnf(ConsoleLogEntry::General, "%s (%d): converting comma string to a number... probably wrong.", dbgFileName, dbgLineNumber);*/
   conversionOp(TypeReqValue, type, codeStream, ip);
   return ip;
}

TypeReq CommaCatExprNode::getPreferredType()
{
   return TypeReqValue;
}

//------------------------------------------------------------

U32 InstanceOfExprNode::precompile(TypeReq type)
{
    U32 addSize = left->precompile(TypeReqValue) + right->precompile(TypeReqValue) + 1;
    return addSize + conversionSize(TypeReqValue, type);
}

U32 InstanceOfExprNode::compile(U64* codeStream, U64 ip, TypeReq type)
{
    // Left could either be an object name or an object id, handle both.
    ip = right->compile(codeStream, ip, TypeReqValue);
    ip = left->compile(codeStream, ip, TypeReqValue);
    codeStream[ip++]= OP_INSTANCEOF_OBJECT;

    // At this point the stack has the result.
    conversionOp(TypeReqValue, type, codeStream, ip);
    return ip;
}

TypeReq InstanceOfExprNode::getPreferredType()
{
    return TypeReqValue;
}

//------------------------------------------------------------

U32 IntUnaryExprNode::precompile(TypeReq type)
{
   integer = true;
   U32 exprSize = expr->precompile(TypeReqValue);
   return exprSize + conversionSize(TypeReqValue, type) + 1;
}

U32 IntUnaryExprNode::compile(U64* codeStream, U64 ip, TypeReq type)
{
   ip = expr->compile(codeStream, ip, TypeReqValue);
   if(op == '!')
      codeStream[ip++] = OP_NOT;
   else if(op == '~')
      codeStream[ip++] = OP_ONESCOMPLEMENT;
   // FIXME: Does this work weirdly with TypeReqNone too??? breakpoint on this please!
   conversionOp(TypeReqValue, type, codeStream, ip);
   return ip;
}

TypeReq IntUnaryExprNode::getPreferredType()
{
   return TypeReqValue;
}

//------------------------------------------------------------

U32 FloatUnaryExprNode::precompile(TypeReq type)
{
   U32 exprSize = expr->precompile(TypeReqValue);
   return exprSize + 1 + conversionSize(TypeReqValue, type);
}

U32 FloatUnaryExprNode::compile(U64 *codeStream, U64 ip, TypeReq type)
{
   ip = expr->compile(codeStream, ip, TypeReqValue);
   codeStream[ip++] = OP_NEG;
   conversionOp(TypeReqValue, type, codeStream, ip);
   return ip;
}

TypeReq FloatUnaryExprNode::getPreferredType()
{
   return TypeReqValue;
}

//------------------------------------------------------------

U32 VarNode::precompile(TypeReq type)
{
   // if this has an arrayIndex...
   // OP_LOADIMMED_IDENT
   // varName
   // OP_ADVANCE_STR
   // evaluate arrayIndex TypeReqString
   // OP_REWIND_STR
   // OP_SETCURVAR_ARRAY
   // OP_LOADVAR (type)

   // else
   // OP_SETCURVAR
   // varName
   // OP_LOADVAR (type)
   if(type == TypeReqNone)
      return 0;

   precompileIdent(varName);
   if(arrayIndex)
      return arrayIndex->precompile(TypeReqValue) + 2;
   else
      return 2;
}

U32 VarNode::compile(U64 *codeStream, U64 ip, TypeReq type)
{
    if(type == TypeReqNone) // script discards value after get?
        return ip;

    if(arrayIndex) {
        ip = arrayIndex->compile(codeStream, ip, TypeReqValue);
        codeStream[ip++] = local ? OP_SETCURLOCAL_ARRAY : OP_SETCURVAR_ARRAY;
    } else
        codeStream[ip++] = local ? OP_SETCURLOCAL : OP_SETCURVAR;
    codeStream[ip] = STEtoU64(varName, ip);
    ip++;
    return ip;
}

TypeReq VarNode::getPreferredType()
{
   return TypeReqNone; // no preferred type
}

//------------------------------------------------------------

U32 IntNode::precompile(TypeReq type)
{
   if(type == TypeReqNone)
      return 0;
   return 2;
}

U32 IntNode::compile(U64 *codeStream, U64 ip, TypeReq type)
{
   if (type == TypeReqNone)
      return ip;

   FloatIntConv conv;
   conv.f = value;
   codeStream[ip++] = OP_LOADIMMED_UINT;
   codeStream[ip++] = value;
   return ip;
}

TypeReq IntNode::getPreferredType()
{
   return TypeReqValue;
}

//------------------------------------------------------------

U32 FloatNode::precompile(TypeReq type)
{
   if(type == TypeReqNone)
      return 0;
   return 2;
}

U32 FloatNode::compile(U64 *codeStream, U64 ip, TypeReq type)
{
   if (type == TypeReqNone)
      return ip;

   FloatIntConv conv;
   conv.f = value;
   codeStream[ip++] = OP_LOADIMMED_FLT;
   codeStream[ip++] = conv.i;
   return ip;
}

TypeReq FloatNode::getPreferredType()
{
   return TypeReqValue;
}

//------------------------------------------------------------

U32 StrConstNode::precompile(TypeReq type)
{
   if(!consoleStringIsNumber(str) && !consoleStringMatchesConstant(str))
   {
      index = getCurrentStringTable()->add(str, true, tag);
      return 2;
   }
   else if(type == TypeReqNone)
      return 0;

   fVal = consoleStringToNumber(str, dbgFileName, dbgLineNumber);
   return 2;
}

U32 StrConstNode::compile(U64 *codeStream, U64 ip, TypeReq type)
{
   if (type == TypeReqNone)
       return ip;

   FloatIntConv conv;
   conv.f = fVal;
   if (consoleStringIsNumber(str)) {
      codeStream[ip++] = OP_LOADIMMED_FLT;
      codeStream[ip++] = conv.i;
   } else if (consoleStringMatchesConstant(str)) {
      codeStream[ip++] = OP_LOADIMMED_UINT;
      codeStream[ip++] = U32(fVal);
   } else {
      codeStream[ip++] = tag ? OP_TAG_TO_STR : OP_LOADIMMED_STR;
      codeStream[ip++] = index;
   }
   return ip;
}

TypeReq StrConstNode::getPreferredType()
{
   return TypeReqValue;
}

//------------------------------------------------------------

U32 ConstantNode::precompile(TypeReq type)
{
   if(type == TypeReqNone)
      return 0;

   index = 0;
   if (consoleStringMatchesConstant(value)) {
      index = 1;
      fVal = consoleStringToNumber(value, dbgFileName, dbgLineNumber);
   } else if (consoleStringIsNumber(value)) {
      index = 2;
      fVal = consoleStringToNumber(value, dbgFileName, dbgLineNumber);
   } else
      precompileIdent(value);

   return 2;
}

U32 ConstantNode::compile(U64 *codeStream, U64 ip, TypeReq type)
{
   if (type == TypeReqNone)
      return ip;

   FloatIntConv conv;
   conv.f = fVal;
   if (index == 1) {
      codeStream[ip++] = OP_LOADIMMED_UINT;
      codeStream[ip++] = U32(fVal);
   }
   else if (index == 2) {
      codeStream[ip++] = OP_LOADIMMED_FLT;
      codeStream[ip++] = conv.i;
   }
   else {
      codeStream[ip++] = OP_LOADIMMED_IDENT;
      codeStream[ip] = STEtoU64(value, ip);
      ip++;
   }
   return ip;
}

TypeReq ConstantNode::getPreferredType()
{
   return TypeReqValue;
}

//------------------------------------------------------------

U32 AssignExprNode::precompile(TypeReq type)
{
   subType = expr->getPreferredType();
   if(subType == TypeReqNone)
      subType = TypeReqValue;
   // if it's an array expr, the formula is:
   // eval expr
   // (push and pop if it's TypeReqString) OP_ADVANCE_STR
   // OP_LOADIMMED_IDENT
   // varName
   // OP_ADVANCE_STR
   // eval array
   // OP_REWIND_STR
   // OP_SETCURVAR_ARRAY_CREATE
   // OP_TERMINATE_REWIND_STR
   // OP_SAVEVAR

   //else
   // eval expr
   // OP_SETCURVAR_CREATE
   // varname
   // OP_SAVEVAR
   precompileIdent(varName);

   U32 conSize = conversionSize(subType, type);
   U32 expSize = expr->precompile(subType);
   if(arrayIndex)
      return arrayIndex->precompile(TypeReqValue) + expSize + conSize + 4;
   else
      return expSize + conSize + 3;
}

U32 AssignExprNode::compile(U64 *codeStream, U64 ip, TypeReq type)
{
   ip = expr->compile(codeStream, ip, subType);
   if(arrayIndex)
   {
      codeStream[ip++] = OP_LOADIMMED_IDENT;
      codeStream[ip] = STEtoU64(varName, ip);
      ip++;
      ip = arrayIndex->compile(codeStream, ip, TypeReqValue);
      codeStream[ip++] = local? OP_SETCURLOCAL_ARRAY_CREATE : OP_SETCURVAR_ARRAY_CREATE;
   }
   else
   {
      codeStream[ip++] = local ? OP_SETCURLOCAL_CREATE : OP_SETCURVAR_CREATE;
      codeStream[ip] = STEtoU64(varName, ip);
      ip++;
   }
   codeStream[ip++] = OP_SAVEVAR;
   conversionOp(subType, type, codeStream, ip);
   return ip;
}

TypeReq AssignExprNode::getPreferredType()
{
   return expr->getPreferredType();
}

//------------------------------------------------------------

static void getAssignOpTypeOp(S32 op, U32 &operand)
{
   switch(op)
   {
   case '+':
      operand = OP_ADD;
      break;
   case '-':
      operand = OP_SUB;
      break;
   case '*':
      operand = OP_MUL;
      break;
   case '/':
      operand = OP_DIV;
      break;
   case '%':
      operand = OP_MOD;
      break;
   case '&':
      operand = OP_BITAND;
      break;
   case '^':
      operand = OP_XOR;
      break;
   case '|':
      operand = OP_BITOR;
      break;
   case opSHL:
      operand = OP_SHL;
      break;
   case opSHR:
      operand = OP_SHR;
      break;
   }   
}

U32 AssignOpExprNode::precompile(TypeReq type)
{
   // goes like this...
   // eval expr as float or int
   // if there's an arrayIndex

   // OP_LOADIMMED_IDENT
   // varName
   // OP_ADVANCE_STR
   // eval arrayIndex stringwise
   // OP_REWIND_STR
   // OP_SETCURVAR_ARRAY_CREATE

   // else
   // OP_SETCURVAR_CREATE
   // varName

   // OP_LOADVAR_FLT or UINT
   // operand
   // OP_SAVEVAR_FLT or UINT

   // conversion OP if necessary.
   getAssignOpTypeOp(op, operand);
   precompileIdent(varName);
   U32 size = expr->precompile(subType) + 3 + conversionSize(subType, type);
   if(!arrayIndex)
      return size + 2;
   else
   {
      size += arrayIndex->precompile(TypeReqValue);
      return size + 3;
   }
}

U32 AssignOpExprNode::compile(U64 *codeStream, U64 ip, TypeReq type)
{
   ip = expr->compile(codeStream, ip, subType);
   if(!arrayIndex)
   {
      // TODO: This can be simplified to remove OP_LOADIMMED_IDENT
      codeStream[ip++] = OP_LOADIMMED_IDENT;
      codeStream[ip] = STEtoU64(varName, ip);
      ip++;
      ip = arrayIndex->compile(codeStream, ip, TypeReqValue);
      codeStream[ip++] = local? OP_SETCURLOCAL_ARRAY_CREATE : OP_SETCURVAR_ARRAY_CREATE;
   }
   else
   {
      codeStream[ip++] = local ? OP_SETCURLOCAL_CREATE : OP_SETCURVAR_CREATE;
      codeStream[ip] = STEtoU64(varName, ip);
      ip++;
   }
   codeStream[ip++] = OP_LOADVAR;
   codeStream[ip++] = operand;
   codeStream[ip++] = OP_SAVEVAR;
   conversionOp(subType, type, codeStream, ip);
   return ip;
}

TypeReq AssignOpExprNode::getPreferredType()
{
   getAssignOpTypeOp(op, operand);
   return subType;
}

//------------------------------------------------------------

U32 TTagSetStmtNode::precompileStmt(U32 loopCount)
{
   loopCount;
   return 0;
}

U32 TTagSetStmtNode::compileStmt(U64*, U64 ip, U32, U32)
{
   return ip;
}

//------------------------------------------------------------

U32 TTagDerefNode::precompile(TypeReq)
{
   return 0;
}

U32 TTagDerefNode::compile(U64*, U64 ip, TypeReq)
{
   return ip;
}

TypeReq TTagDerefNode::getPreferredType()
{
   return TypeReqNone;
}

//------------------------------------------------------------

U32 TTagExprNode::precompile(TypeReq)
{
   return 0;
}

U32 TTagExprNode::compile(U64*, U64 ip, TypeReq)
{
   return ip;
}

TypeReq TTagExprNode::getPreferredType()
{
   return TypeReqNone;
}

//------------------------------------------------------------

U32 FuncCallExprNode::precompile(TypeReq type)
{
   // OP_PUSH_FRAME
   // arg OP_PUSH arg OP_PUSH arg OP_PUSH
   // eval all the args, then call the function.

   // OP_CALLFUNC
   // function
   // namespace
   // isDot
   // argc

   precompileIdent(funcName);
   precompileIdent(nameSpace);

   U32 size = conversionSize(TypeReqValue, type);
   for(ExprNode *walk = args; walk; walk = (ExprNode *) walk->getNext())
      size += walk->precompile(TypeReqValue);
   return size + 5;
}

U32 FuncCallExprNode::compile(U64 *codeStream, U64 ip, TypeReq type)
{
   // Pushes a string stack frame and pushes strings to STR in compiledEval.cc
   // NOW it just compiles and auto-pushes everything in the value stack.
   U32 argc = 0;
   for (ExprNode* walk = args; walk; walk = (ExprNode*)walk->getNext()) {
       ip = walk->compile(codeStream, ip, TypeReqValue);
       ++argc;
   }
   if(callType == MethodCall || callType == ParentCall)
      codeStream[ip++] = OP_CALLFUNC;
   else
      codeStream[ip++] = OP_CALLFUNC_RESOLVE;

   // compiledEval.cc has to skip past this info after reading it!
   codeStream[ip] = STEtoU64(funcName, ip); ip++;
   codeStream[ip] = STEtoU64(nameSpace, ip); ip++;
   codeStream[ip++] = callType;
   codeStream[ip++] = argc;
   conversionOp(TypeReqValue, type, codeStream, ip);
   return ip;
}

TypeReq FuncCallExprNode::getPreferredType()
{
   return TypeReqValue;
}

//------------------------------------------------------------

U32 SlotAccessNode::precompile(TypeReq type)
{
   if(type == TypeReqNone)
      return 0;
   U32 size = 0;
   precompileIdent(slotName);
   if(arrayExpr)
   {
      // eval array
      // OP_ADVANCE_STR
      // evaluate object expression sub (OP_SETCURFIELD)
      // OP_TERMINATE_REWIND_STR
      // OP_SETCURFIELDARRAY
      // total add of 4 + array precomp
      size += 1 + arrayExpr->precompile(TypeReqValue);
   }
   // eval object expression sub + 3 (op_setCurField + OP_SETCUROBJECT)
   return objectExpr->precompile(TypeReqValue) + size + 4;
}

U32 SlotAccessNode::compile(U64 *codeStream, U64 ip, TypeReq type)
{
   if(type == TypeReqNone)
      return ip;

   ip = objectExpr->compile(codeStream, ip, TypeReqValue);
   codeStream[ip++] = OP_SETCUROBJECT;
   codeStream[ip++] = OP_SETCURFIELD;
   codeStream[ip] = STEtoU64(slotName, ip);
   ip++;
   if(arrayExpr)
   {
      ip = arrayExpr->compile(codeStream, ip, TypeReqValue);
      codeStream[ip++] = OP_SETCURFIELD_ARRAY;
   }
   codeStream[ip++] = OP_LOADFIELD;
   return ip;
}

TypeReq SlotAccessNode::getPreferredType()
{
   return TypeReqNone; // FIXME: is this right????
}

//------------------------------------------------------------

U32 SlotAssignNode::precompile(TypeReq type)
{
   // evaluate object expr
   // OP_SETCUROBJECT
   // or OP_SETCUROBJECT_NEW
   
   // OP_SETCURFIELD fieldName

   // if there's an array:
   // eval array
   // OP_SETCURFIELDARRAY

   // eval the expression TypeReqValue

   // OP_SAVEFIELD
   // pop if necessary.

   U32 size = conversionSize(TypeReqValue, type);

   precompileIdent(slotName);

   if(objectExpr)
      size += objectExpr->precompile(TypeReqValue) + 1;
   else
      size += 1;

   if(arrayExpr)
      size += arrayExpr->precompile(TypeReqValue) + 1;

   return size + valueExpr->precompile(TypeReqValue) + 3;
}

U32 SlotAssignNode::compile(U64 *codeStream, U64 ip, TypeReq type)
{
   if(objectExpr)
   {
      ip = objectExpr->compile(codeStream, ip, TypeReqValue);
      codeStream[ip++] = OP_SETCUROBJECT;
   }
   else codeStream[ip++] = OP_SETCUROBJECT_NEW;
   codeStream[ip++] = OP_SETCURFIELD;
   codeStream[ip] = STEtoU64(slotName, ip);
   ip++;
   if(arrayExpr)
   {
      ip = arrayExpr->compile(codeStream, ip, TypeReqValue);
      codeStream[ip++] = OP_SETCURFIELD_ARRAY;
   }
   ip = valueExpr->compile(codeStream, ip, TypeReqValue);
   codeStream[ip++] = OP_SAVEFIELD;
   conversionOp(TypeReqValue, type, codeStream, ip);
   return ip;
}

TypeReq SlotAssignNode::getPreferredType()
{
   return TypeReqValue;
}

//------------------------------------------------------------

U32 SlotAssignOpNode::precompile(TypeReq type)
{
   // evaluate object expr
   // OP_SETCUROBJECT
   // OP_SETCURFIELD
   // fieldName

   // if it's an array:
   //   eval array
   //   OP_SETCURFIELDARRAY

   // OP_LOADFIELD of appropriate type
   // eval the expression as its type
   // operand
   // OP_SAVEFIELD of appropriate type
   // convert to return type if necessary.

   getAssignOpTypeOp(op, operand);
   precompileIdent(slotName);

   U32 size = valueExpr->precompile(subType) + objectExpr->precompile(TypeReqValue) + 6;
   size += conversionSize(subType, type);
   if(arrayExpr)
      size += arrayExpr->precompile(TypeReqValue) + 1;
   return size;
}

U32 SlotAssignOpNode::compile(U64 *codeStream, U64 ip, TypeReq type)
{
   ip = objectExpr->compile(codeStream, ip, TypeReqValue);
   codeStream[ip++] = OP_SETCUROBJECT;
   codeStream[ip++] = OP_SETCURFIELD;
   codeStream[ip] = STEtoU64(slotName, ip);
   ip++;
   if(arrayExpr)
   {
      ip = arrayExpr->compile(codeStream, ip, TypeReqValue);
      codeStream[ip++] = OP_SETCURFIELD_ARRAY;
   }
   codeStream[ip++] = OP_LOADFIELD;
   ip = valueExpr->compile(codeStream, ip, subType);
   codeStream[ip++] = operand;
   codeStream[ip++] = OP_SAVEFIELD;
   conversionOp(subType, type, codeStream, ip);
   return ip;
}

TypeReq SlotAssignOpNode::getPreferredType()
{
   getAssignOpTypeOp(op, operand);
   return subType;
}

//------------------------------------------------------------

U32 ObjectDeclNode::precompileSubObject(bool)
{
   // goes

   // OP_PUSHFRAME 1
   // name expr
   // OP_PUSH 1
   // args... PUSH
   // OP_CREATE_OBJECT 1
   // className 1
   // datablock? 1
   // fail point 1

   // for each field, eval
   // OP_ADD_OBJECT (to UINT[0]) 1
   // root? 1

   // add all the sub objects.
   // OP_END_OBJECT 1
   // root? 1

   U32 argSize = 0;
   precompileIdent(parentObject);
   for(ExprNode *exprWalk = argList; exprWalk; exprWalk = (ExprNode *) exprWalk->getNext())
      argSize += exprWalk->precompile(TypeReqValue);
   argSize += classNameExpr->precompile(TypeReqValue);

   U32 nameSize = objectNameExpr->precompile(TypeReqValue);

   U32 slotSize = 0;
   for(SlotAssignNode *slotWalk = slotDecls; slotWalk; slotWalk = (SlotAssignNode *) slotWalk->getNext())
      slotSize += slotWalk->precompile(TypeReqNone);

   // OP_ADD_OBJECT
   U32 subObjSize = 0;
   for(ObjectDeclNode *objectWalk = subObjects; objectWalk; objectWalk = (ObjectDeclNode *) objectWalk->getNext())
      subObjSize += objectWalk->precompileSubObject(false);

   failOffset = 8 + nameSize + argSize + slotSize + subObjSize;
   return failOffset;
}

U32 ObjectDeclNode::precompile(TypeReq type)
{
   // root object decl does:

   // push 0 onto the UINT stack OP_LOADIMMED_UINT
   // precompiles the subObject(true)
   // UINT stack now has object id
   // type conv to type

   return 2 + precompileSubObject(true) + conversionSize(TypeReqValue, type);
}

U32 ObjectDeclNode::compileSubObject(U64 *codeStream, U64 ip, bool root)
{
   // Compile arguments and automatically push them into the stack
   U32 argc = 0;
   U32 start = ip;
   ip = classNameExpr->compile(codeStream, ip, TypeReqValue);
   ip = objectNameExpr->compile(codeStream, ip, TypeReqValue);
   for (ExprNode* exprWalk = argList; exprWalk; exprWalk = (ExprNode*)exprWalk->getNext()) {
      ip = exprWalk->compile(codeStream, ip, TypeReqValue);
      ++argc;
   }

   // Sub object
   codeStream[ip++] = OP_CREATE_OBJECT;
   codeStream[ip++] = argc + 3; // always 3 at minimum (null, object class, object name)
   codeStream[ip] = STEtoU64(parentObject, ip);
   ip++;
   codeStream[ip++] = structDecl;
   codeStream[ip++] = start + failOffset;
   for(SlotAssignNode *slotWalk = slotDecls; slotWalk; slotWalk = (SlotAssignNode *) slotWalk->getNext())
      ip = slotWalk->compile(codeStream, ip, TypeReqNone);
   codeStream[ip++] = OP_ADD_OBJECT;
   codeStream[ip++] = root; // not at root means we have to consume a group Id in the stack.
   for(ObjectDeclNode *objectWalk = subObjects; objectWalk; objectWalk = (ObjectDeclNode *) objectWalk->getNext())
      ip = objectWalk->compileSubObject(codeStream, ip, false);
   codeStream[ip++] = OP_END_OBJECT;
   codeStream[ip++] = root || structDecl;
   return ip;
}

U32 ObjectDeclNode::compile(U64 *codeStream, U64 ip, TypeReq type)
{
   // push root id on stack, the placeAtRoot flag of OP_ADD_OBJECT determines if it gets overwritten.
   // weirdly this saves the stack argv address calculation in compiledEval.cc to account for blank name.
   codeStream[ip++] = OP_LOADIMMED_UINT;
   codeStream[ip++] = 0;
   ip = compileSubObject(codeStream, ip, true);
   conversionOp(TypeReqValue, type, codeStream, ip);
   return ip;
}   
TypeReq ObjectDeclNode::getPreferredType()
{
   return TypeReqValue;
}

//------------------------------------------------------------

U32 FunctionDeclStmtNode::precompileStmt(U32)
{
   // OP_FUNC_DECL
   // func name
   // namespace
   // package
   // stmts flag
   // func end ip
   // argc
   // static stack size
   // code
   // OP_RETURN_NONE
   setCurrentStringTable(&getFunctionStringTable());

   argc = 0;
   for(VarNode *walk = args; walk; walk = (VarNode *)((StmtNode*)walk)->getNext())
      ++argc;
   
   CodeBlock::smInFunction = true;
   
   precompileIdent(fnName);
   precompileIdent(nameSpace);
   precompileIdent(package);
   
   U32 subSize = precompileBlock(stmts, 0);
   
   #ifdef TORQUE_EXTRA_BREAKLINES
      //addBreakCount();   
   #endif

   CodeBlock::smInFunction = false;

   setCurrentStringTable(&getGlobalStringTable());

   endOffset = argc + subSize + 8;
   return endOffset;
}

U32 FunctionDeclStmtNode::compileStmt(U64 *codeStream, U64 ip, U32, U32)
{
   U32 start = ip;
   codeStream[ip++] = OP_FUNC_DECL;
   codeStream[ip] = STEtoU64(fnName, ip);
   ip++;
   codeStream[ip] = STEtoU64(nameSpace, ip);
   ip++;
   codeStream[ip] = STEtoU64(package, ip);
   ip++;
   codeStream[ip++] = bool(stmts != NULL);
   codeStream[ip++] = start + endOffset;
   codeStream[ip++] = argc;
   for(VarNode *walk = args; walk; walk = (VarNode *)((StmtNode*)walk)->getNext())
   {
      codeStream[ip] = STEtoU64(walk->varName, ip);
      ip++;
   }
   
   CodeBlock::smInFunction = true;
   ip = compileBlock(stmts, codeStream, ip, 0, 0);

   #ifdef TORQUE_EXTRA_BREAKLINES      
      //addBreakLine(ip);   
   #endif

   CodeBlock::smInFunction = false;
   codeStream[ip++] = OP_RETURN_NONE;
   return ip;
}