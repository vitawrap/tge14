//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#ifndef _AST_H_
#define _AST_H_

struct ConsoleValue;
class ExprEvalState;
class Namespace;
class SimObject;
class SimGroup;

// do we pop the stack or not?
enum TypeReq {
   TypeReqNone,
   TypeReqValue
};

// Fold type
enum TypeConst {
   TypeConstUnknown,
   TypeConstString,
   TypeConstFloat,
   TypeConstInt,
   TypeConstList
};

/// Representation of a node for the scripting language parser.
///
/// When the scripting language is evaluated, it is turned from a string representation,
/// into a parse tree, thence into byte code, which is ultimately interpreted by the VM.
///
/// This is the base class for the nodes in the parse tree. There are a great many subclasses,
/// each representing a different language construct.
struct StmtNode
{
   StmtNode *next;   ///< Next entry in parse tree.

   StmtNode();

   /// @name next Accessors
   /// @{

   ///
   void append(StmtNode *next);
   StmtNode *getNext() { return next; }

   /// @}

   /// @name Debug Info
   /// @{

   StringTableEntry dbgFileName; ///< Name of file this node is associated with.
   S32 dbgLineNumber;            ///< Line number this node is associated with.
   /// @}

   /// @name Breaking
   /// @{

   //void addBreakCount();
   //void addBreakLine(U32 ip);
   /// @}

   /// @name Compilation
   /// @{

   virtual TypeConst getFoldType() const { return TypeConstUnknown; }
   virtual ConsoleValue getFoldValue() const;
   virtual StmtNode* fold() { return this; }

   virtual U32 precompileStmt(U32 loopCount) = 0;
   virtual U32 compileStmt(U64* codeStream, U64 ip, U32 continuePoint, U32 breakPoint) = 0;
   virtual void setPackage(StringTableEntry packageName);
   /// @}
};

// This can appear during the AST folding stage if a node has to exist but nothing can be compiled.
struct NoStmtNode : StmtNode
{
   static NoStmtNode* alloc();

   U32 precompileStmt(U32) { return 0; }
   U32 compileStmt(U64*, U64 ip, U32, U32) { return ip; }
};

struct BreakStmtNode : StmtNode
{
   static BreakStmtNode *alloc();

   U32 precompileStmt(U32 loopCount);
   U32 compileStmt(U64* codeStream, U64 ip, U32 continuePoint, U32 breakPoint);
};

struct ContinueStmtNode : StmtNode
{
   static ContinueStmtNode *alloc();
   U32 precompileStmt(U32 loopCount);
   U32 compileStmt(U64* codeStream, U64 ip, U32 continuePoint, U32 breakPoint);
};

/// A mathematical expression.
struct ExprNode : StmtNode
{
   U32 precompileStmt(U32 loopCount);
   U32 compileStmt(U64* codeStream, U64 ip, U32 continuePoint, U32 breakPoint);

   virtual U32 precompile(TypeReq type) = 0;
   virtual U32 compile(U64* codeStream, U64 ip, TypeReq type) = 0;
   virtual TypeReq getPreferredType() = 0;
};

struct ReturnStmtNode : StmtNode
{
   ExprNode *expr;

   static ReturnStmtNode *alloc(ExprNode *expr);
   U32 precompileStmt(U32 loopCount);
   U32 compileStmt(U64* codeStream, U64 ip, U32 continuePoint, U32 breakPoint);

   StmtNode* fold() override;
};

struct IfStmtNode : StmtNode
{
   ExprNode *testExpr;
   StmtNode *ifBlock, *elseBlock;
   U32 endifOffset;
   U32 elseOffset;
   bool integer;
   bool propagate;

   static IfStmtNode *alloc(S32 lineNumber, ExprNode *testExpr, StmtNode *ifBlock, StmtNode *elseBlock, bool propagateThrough);
   void propagateSwitchExpr(ExprNode *left, bool string);
   ExprNode *getSwitchOR(ExprNode *left, ExprNode *list, bool string);
   U32 precompileStmt(U32 loopCount);
   U32 compileStmt(U64* codeStream, U64 ip, U32 continuePoint, U32 breakPoint);

   StmtNode* fold() override;
};

struct SwitchStmtNode : StmtNode
{
    ExprNode* testExpr;

    static SwitchStmtNode* alloc(S32 lineNumber, ExprNode* testExpr);

    StmtNode* fold() override;
};

struct LoopStmtNode : StmtNode
{
   ExprNode *testExpr;
   ExprNode *initExpr;
   ExprNode *endLoopExpr;
   StmtNode *loopBlock;
   bool isDoLoop;
   U32 breakOffset;
   U32 continueOffset;
   U32 loopBlockStartOffset;
   bool integer;

   static LoopStmtNode *alloc(S32 lineNumber, ExprNode *testExpr, ExprNode *initExpr, ExprNode *endLoopExpr, StmtNode *loopBlock, bool isDoLoop);
   U32 precompileStmt(U32 loopCount);
   U32 compileStmt(U64* codeStream, U64 ip, U32 continuePoint, U32 breakPoint);

   StmtNode* fold() override;
};

/// A binary mathematical expression (ie, left op right).
struct BinaryExprNode : ExprNode
{
   S32 op;
   ExprNode *left;
   ExprNode *right;

   StmtNode* fold() override;
};

struct FloatBinaryExprNode : BinaryExprNode
{
   static FloatBinaryExprNode *alloc(S32 op, ExprNode *left, ExprNode *right);
   U32 precompile(TypeReq type);
   U32 compile(U64* codeStream, U64 ip, TypeReq type);
   TypeReq getPreferredType();

   StmtNode* fold() override;
};

struct ConditionalExprNode : ExprNode
{
   ExprNode *testExpr;
   ExprNode *trueExpr;
   ExprNode *falseExpr;
   bool integer;
   static ConditionalExprNode *alloc(ExprNode *testExpr, ExprNode *trueExpr, ExprNode *falseExpr);
   virtual U32 precompile(TypeReq type);
   virtual U32 compile(U64* codeStream, U64 ip, TypeReq type);
   virtual TypeReq getPreferredType();

   StmtNode* fold() override;
};

struct IntBinaryExprNode : BinaryExprNode
{
   TypeReq subType;
   U32 operand;

   static IntBinaryExprNode *alloc(S32 op, ExprNode *left, ExprNode *right);

   void getSubTypeOperand();
   U32 precompile(TypeReq type);
   U32 compile(U64* codeStream, U64 ip, TypeReq type);
   TypeReq getPreferredType();

   StmtNode* fold() override;
};

struct StreqExprNode : BinaryExprNode
{
   bool eq;
   static StreqExprNode *alloc(ExprNode *left, ExprNode *right, bool eq);
   U32 precompile(TypeReq type);
   U32 compile(U64* codeStream, U64 ip, TypeReq type);
   TypeReq getPreferredType();

   StmtNode* fold();
};

struct StrcatExprNode : BinaryExprNode
{
   int appendChar;
   static StrcatExprNode *alloc(ExprNode *left, ExprNode *right, int appendChar);
   U32 precompile(TypeReq type);
   U32 compile(U64* codeStream, U64 ip, TypeReq type);
   TypeReq getPreferredType();

   StmtNode* fold();
};

struct StrForgiveExprNode : BinaryExprNode
{
    static StrForgiveExprNode* alloc(ExprNode* left, ExprNode* right);
    U32 precompile(TypeReq type);
    U32 compile(U64* codeStream, U64 ip, TypeReq type);
    TypeReq getPreferredType();

    StmtNode* fold();
};

struct CommaCatExprNode : BinaryExprNode
{
   static CommaCatExprNode *alloc(ExprNode *left, ExprNode *right);

   U32 precompile(TypeReq type);
   U32 compile(U64* codeStream, U64 ip, TypeReq type);
   TypeReq getPreferredType();

   StmtNode* fold();
};

struct InstanceOfExprNode : BinaryExprNode
{
    static InstanceOfExprNode* alloc(ExprNode* left, ExprNode* right);

    U32 precompile(TypeReq type);
    U32 compile(U64* codeStream, U64 ip, TypeReq type);
    TypeReq getPreferredType();
};

struct IntUnaryExprNode : ExprNode
{
   S32 op;
   ExprNode *expr;
   bool integer;

   static IntUnaryExprNode *alloc(S32 op, ExprNode *expr);
   U32 precompile(TypeReq type);
   U32 compile(U64* codeStream, U64 ip, TypeReq type);
   TypeReq getPreferredType();

   StmtNode* fold() override;
};

struct FloatUnaryExprNode : ExprNode
{
   S32 op;
   ExprNode *expr;

   static FloatUnaryExprNode *alloc(S32 op, ExprNode *expr);
   U32 precompile(TypeReq type);
   U32 compile(U64* codeStream, U64 ip, TypeReq type);
   TypeReq getPreferredType();

   StmtNode* fold() override;
};

struct VarNode : ExprNode
{
   bool local;
   StringTableEntry varName;
   ExprNode *arrayIndex;

   static VarNode *alloc(StringTableEntry varName, ExprNode *arrayIndex);
   U32 precompile(TypeReq type);
   U32 compile(U64* codeStream, U64 ip, TypeReq type);
   TypeReq getPreferredType();

   StmtNode* fold() override;
};

struct IntNode : ExprNode
{
   S32 value;
   U32 index; // if it's converted to float/string

   static IntNode *alloc(S32 value);
   U32 precompile(TypeReq type);
   U32 compile(U64* codeStream, U64 ip, TypeReq type);
   TypeReq getPreferredType();

   TypeConst getFoldType() const override { return TypeConstInt; }
   ConsoleValue getFoldValue() const override;
};

struct FloatNode : ExprNode
{
   F64 value;
   U32 index;

   static FloatNode *alloc(F64 value);
   U32 precompile(TypeReq type);
   U32 compile(U64* codeStream, U64 ip, TypeReq type);
   TypeReq getPreferredType();

   TypeConst getFoldType() const override { return TypeConstFloat; }
   ConsoleValue getFoldValue() const override;
};

struct StrConstNode : ExprNode
{
   char *str;
   F64 fVal;
   U32 index;
   bool tag;

   static StrConstNode *alloc(char *str, bool tag);
   U32 precompile(TypeReq type);
   U32 compile(U64* codeStream, U64 ip, TypeReq type);
   TypeReq getPreferredType();

   StmtNode* fold() override;
   TypeConst getFoldType() const override { return TypeConstString; }
   ConsoleValue getFoldValue() const override;
};

struct ConstantNode : ExprNode
{
   StringTableEntry value;
   F64 fVal;
   U32 index;

   static ConstantNode *alloc(StringTableEntry value);
   U32 precompile(TypeReq type);
   U32 compile(U64* codeStream, U64 ip, TypeReq type);
   TypeReq getPreferredType();

   TypeConst getFoldType() const override { return TypeConstString; }
   ConsoleValue getFoldValue() const override;
};

struct AssignExprNode : ExprNode
{
   bool local;
   StringTableEntry varName;
   ExprNode *expr;
   ExprNode *arrayIndex;
   TypeReq subType;

   static AssignExprNode *alloc(StringTableEntry varName, ExprNode *arrayIndex, ExprNode *expr);
   U32 precompile(TypeReq type);
   U32 compile(U64* codeStream, U64 ip, TypeReq type);
   TypeReq getPreferredType();

   StmtNode* fold() override;
};

struct AssignDecl
{
   S32 token;
   ExprNode *expr;
   bool integer;
};

struct AssignOpExprNode : ExprNode
{
   bool local;
   StringTableEntry varName;
   ExprNode *expr;
   ExprNode *arrayIndex;
   S32 op;
   U32 operand;
   TypeReq subType;

   static AssignOpExprNode *alloc(StringTableEntry varName, ExprNode *arrayIndex, ExprNode *expr, S32 op);
   U32 precompile(TypeReq type);
   U32 compile(U64* codeStream, U64 ip, TypeReq type);
   TypeReq getPreferredType();

   StmtNode* fold() override;
};

struct ValueListExprNode : ExprNode
{
   ExprNode *list;

   static ValueListExprNode* alloc(ExprNode* exprList);
   U32 precompile(TypeReq type);
   U32 compile(U64* codeStream, U64 ip, TypeReq type);
   TypeReq getPreferredType();

   StmtNode* fold() override;
};

struct FuncCallExprNode : ExprNode
{
   StringTableEntry funcName;
   StringTableEntry nameSpace;
   ExprNode *args;
   U32 callType;
   enum {
      FunctionCall,
      MethodCall,
      ParentCall
   };

   static FuncCallExprNode *alloc(StringTableEntry funcName, StringTableEntry nameSpace, ExprNode *args, bool dot);
   U32 precompile(TypeReq type);
   U32 compile(U64* codeStream, U64 ip, TypeReq type);
   TypeReq getPreferredType();

   StmtNode* fold() override;
};

struct SlotDecl
{
   ExprNode         *object;
   StringTableEntry slotName;
   ExprNode         *array;
};

struct SlotAccessNode : ExprNode
{
   ExprNode *objectExpr, *arrayExpr;
   StringTableEntry slotName;

   static SlotAccessNode *alloc(ExprNode *objectExpr, ExprNode *arrayExpr, StringTableEntry slotName);
   U32 precompile(TypeReq type);
   U32 compile(U64* codeStream, U64 ip, TypeReq type);
   TypeReq getPreferredType();

   StmtNode* fold() override;
};

struct SlotAssignNode : ExprNode
{
   ExprNode *objectExpr, *arrayExpr;
   StringTableEntry slotName;
   ExprNode *valueExpr;

   static SlotAssignNode *alloc(ExprNode *objectExpr, ExprNode *arrayExpr, StringTableEntry slotName, ExprNode *valueExpr);
   U32 precompile(TypeReq type);
   U32 compile(U64* codeStream, U64 ip, TypeReq type);
   TypeReq getPreferredType();

   StmtNode* fold() override;
};

struct SlotAssignOpNode : ExprNode
{
   ExprNode *objectExpr, *arrayExpr;
   StringTableEntry slotName;
   S32 op;
   ExprNode *valueExpr;
   U32 operand;
   TypeReq subType;

   static SlotAssignOpNode *alloc(ExprNode *objectExpr, StringTableEntry slotName, ExprNode *arrayExpr, S32 op, ExprNode *valueExpr);
   U32 precompile(TypeReq type);
   U32 compile(U64* codeStream, U64 ip, TypeReq type);
   TypeReq getPreferredType();

   StmtNode* fold() override;
};

struct ObjectDeclNode : ExprNode
{
   ExprNode *classNameExpr;
   StringTableEntry parentObject;
   ExprNode *objectNameExpr;
   ExprNode *argList;
   SlotAssignNode *slotDecls;
   ObjectDeclNode *subObjects;
   bool structDecl;
   U32 failOffset;

   static ObjectDeclNode *alloc(ExprNode *classNameExpr, ExprNode *objectNameExpr, ExprNode *argList, StringTableEntry parentObject, SlotAssignNode *slotDecls, ObjectDeclNode *subObjects, bool structDecl);
   U32 precompile(TypeReq type);
   U32 precompileSubObject(bool);
   U32 compile(U64* codeStream, U64 ip, TypeReq type);
   U32 compileSubObject(U64 *codeStream, U64 ip, bool);
   TypeReq getPreferredType();

   StmtNode* fold() override;
};

struct ObjectBlockDecl
{
   SlotAssignNode *slots;
   ObjectDeclNode *decls;
};

struct FunctionDeclStmtNode : StmtNode
{
   StringTableEntry fnName;
   VarNode *args;
   StmtNode *stmts;
   StringTableEntry nameSpace;
   StringTableEntry package;
   U32 endOffset;
   U32 argc;

   static FunctionDeclStmtNode *alloc(StringTableEntry fnName, StringTableEntry nameSpace, VarNode *args, StmtNode *stmts);
   U32 precompileStmt(U32 loopCount);
   U32 compileStmt(U64 *codeStream, U64 ip, U32 continuePoint, U32 breakPoint);
   void setPackage(StringTableEntry packageName);

   StmtNode* fold() override;
};

extern StmtNode *statementList;
extern void createFunction(const char *fnName, VarNode *args, StmtNode *statements);
extern ExprEvalState gEvalState;
extern bool lookupFunction(const char *fnName, VarNode **args, StmtNode **statements);
typedef const char *(*cfunc)(S32 argc, char **argv);
extern bool lookupCFunction(const char *fnName, cfunc *f);

// This already supports nullable statement lists
template <typename T>
static T* foldNodeList(T* start) {
    StmtNode* newStart = NULL;
    StmtNode* prev = NULL;
    for (StmtNode* walk = start; walk; walk = (StmtNode*)walk->next) {
        StmtNode* savedNext = walk->next;
        walk = walk->fold();
        walk->next = savedNext;
        // Previous node needs to be aware that his successor changed.
        if (prev) prev->next = walk;
        prev = walk;
        // Prepare to return new head
        if (!newStart) newStart = walk;
    }
    return newStart ? (T*)newStart : start;
}

#endif
