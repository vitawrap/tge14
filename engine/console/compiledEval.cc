//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#include "platform/platform.h"
#include "console/console.h"

#include "console/ast.h"
#include "core/tAlgorithm.h"
#include "core/resManager.h"

#include "core/findMatch.h"
#include "console/consoleInternal.h"
#include "core/fileStream.h"
#include "console/compiler.h"

#include "console/simBase.h"
#include "sim/netStringTable.h"

#include "console/stringStack.h"
#include "console/consoleValue.h"

using namespace Compiler;

enum EvalConstants {
   MaxStackSize = 1024
};

namespace Con
{
// Current script file name and root, these are registered as
// console variables.
extern StringTableEntry gCurrentFile;
extern StringTableEntry gCurrentRoot;
}

ConsoleValue valueStack[MaxStackSize];
S32 TOP = 0; // This should be -1, but torque always needs an extra argument for a function name...

static inline void popValueStack(int n = 1) {
    while (n--) valueStack[TOP--].clearValue();
}

template <typename T>
static inline void pushValueStack(T const& val) {
    valueStack[++TOP] = val;
}

static ConsoleValue getNamespaceList(Namespace *ns)
{
   ConsoleValue ret;
   Namespace * walk;
   for(walk = ns; walk; walk = walk->mParent)
   {
      ret.concatStringU(walk->mName, dStrlen(walk->mName));
      if(walk->mParent)
         ret.concatStringU(" -> ", 4);
   }
   return ret;
}

//------------------------------------------------------------

F64 consoleStringToNumber(const char *str, StringTableEntry file, U32 line)
{
   char* end;
   F64 val = dStrtod(str, &end);
   if (*end == 0 || (end[dStrspn(end, " \t")] == 0))
       return val;
   else if (!dStricmp(str, "true"))
       return 1;
   else if (!dStricmp(str, "false"))
       return 0;
   else if(file)
   {
      Con::warnf(ConsoleLogEntry::General, "%s (%d): string always evaluates to 0.", file, line);
      return 0;
   }
   return 0;
}

//------------------------------------------------------------

//namespace Con
//{
//
//   char *getReturnBuffer(U32 bufferSize)
//   {
//      return STR.getReturnBuffer(bufferSize);
//   }
//
//   char *getArgBuffer(U32 bufferSize)
//   {
//      return STR.getArgBuffer(bufferSize);
//   }
//
//   char *getFloatArg(F64 arg)
//   {
//
//      char *ret = STR.getArgBuffer(32);
//      dSprintf(ret, 32, "%g", arg);
//      return ret;
//   }
//
//   char *getIntArg(S32 arg)
//   {
//
//      char *ret = STR.getArgBuffer(32);
//      dSprintf(ret, 32, "%d", arg);
//      return ret;
//   }
//}

//------------------------------------------------------------

inline void ExprEvalState::setCurVarName(StringTableEntry name)
{
    currentVariable = globalVars.lookup(name);
}

inline void ExprEvalState::setCurVarNameCreate(StringTableEntry name)
{
    currentVariable = globalVars.add(name);
}

inline void ExprEvalState::setCurLocalName(StringTableEntry name)
{
    if (stack.size())
        currentVariable = stack.last().lookup(name);
    if (!currentVariable && gWarnUndefinedScriptVariables)
        Con::warnf(ConsoleLogEntry::Script, "Variable referenced before assignment: %s", name);
}

inline void ExprEvalState::setCurLocalNameCreate(StringTableEntry name)
{
    if (stack.size())
        currentVariable = stack.last().add(name);
    else
    {
        currentVariable = NULL;
        Con::warnf(ConsoleLogEntry::Script, "Accessing local variable in global scope... failed: %s", name);
    }
}

//------------------------------------------------------------

inline ConsoleValue ExprEvalState::getVariable() const
{
   return currentVariable ? currentVariable->getValue() : "";
}

//------------------------------------------------------------

inline void ExprEvalState::setVariable(ConsoleValue& val)
{
   AssertFatal(currentVariable != NULL, "Invalid evaluator state - trying to set null variable!");
   currentVariable->setValue(val);
}

//------------------------------------------------------------

void CodeBlock::getFunctionArgs(char buffer[1024], U64 ip)
{
   U32 fnArgc = code[ip + 5];
   buffer[0] = 0;
   for(U32 i = 0; i < fnArgc; i++)
   {
      StringTableEntry var = U64toSTE(code[ip + i + 6]);
      
      // Add a comma so it looks nice!
      if(i != 0)
         dStrcat(buffer, ", ");

      dStrcat(buffer, "var ");

      // Try to capture junked parameters
      if(var[0])
        dStrcat(buffer, var+1);
      else
        dStrcat(buffer, "JUNK");
   }
}

ConsoleValue CodeBlock::exec(U64 ip, const char *functionName, Namespace *thisNamespace, U32 argc, ConsoleValue *argv, bool noCalls, StringTableEntry packageName, S32 setFrame)
{
   static char traceBuffer[1024];
   U32 i;

#ifdef TORQUE_DEBUG
   S32 DBG_ENTER_TOP = TOP;
#endif

   incRefCount();
   FloatIntConv conv;
   char *curStringTable;
   StringTableEntry thisFunctionName = NULL;
   bool popFrame = false;
   if(argv)
   {
      // assume this points into a function decl:
      U32 fnArgc = code[ip + 5];
      thisFunctionName = U64toSTE(code[ip]);
      argc = getMin(argc-1, fnArgc); // Get argc that need to be populated for this call. argv[0] is the func name.
      if(gEvalState.traceOn)
      {
         traceBuffer[0] = 0;
         dStrcat(traceBuffer, "Entering ");
         if(packageName)
         {
            dStrcat(traceBuffer, "[");
            dStrcat(traceBuffer, packageName);
            dStrcat(traceBuffer, "]");
         }
         if(thisNamespace && thisNamespace->mName)
         {
            dSprintf(traceBuffer + dStrlen(traceBuffer), sizeof(traceBuffer) - dStrlen(traceBuffer),
               "%s::%s(", thisNamespace->mName, thisFunctionName);
         }
         else
         {
            dSprintf(traceBuffer + dStrlen(traceBuffer), sizeof(traceBuffer) - dStrlen(traceBuffer),
               "%s(", thisFunctionName);
         }
         for(i = 0; i < argc; i++)
         {
            size_t used = dStrlen(traceBuffer);
            argv[i + 1].toString(traceBuffer + used, 1024 - used);
            if(i != argc - 1)
               dStrcat(traceBuffer, ", ");
         }
         dStrcat(traceBuffer, ")");
         Con::printf("%s", traceBuffer);
      }
      gEvalState.pushFrame(thisFunctionName, thisNamespace);
      popFrame = true;
      for(i = 0; i < argc; i++) // We know the static arg layout starts at 0 due to FunctionDeclStmtNode::compile
      {
         StringTableEntry var = U64toSTE(code[ip + i + 6]);
         gEvalState.setCurLocalNameCreate(var);
         gEvalState.setVariable(argv[i+1]);
      }
      ip = ip + fnArgc + 6;
      curStringTable = functionStrings;
   }
   else
   {
      curStringTable = globalStrings;

      // Do we want this code to execute using a new stack frame?
      if (setFrame < 0)
      {
         gEvalState.pushFrame(NULL, NULL);
         popFrame = true;
      }
      else if (!gEvalState.stack.empty())
      {
         // We want to copy a reference to an existing stack frame
         // on to the top of the stack.  Any change that occurs to 
         // the locals during this new frame will also occur in the 
         // original frame.
         S32 stackIndex = gEvalState.stack.size() - setFrame - 1;
         gEvalState.pushFrameRef( stackIndex );
         popFrame = true;
      }
   }

   //if (TelDebugger && setFrame < 0)
   //   TelDebugger->pushStackFrame();

   StringTableEntry var, objParent;
   U32 failJump;
   StringTableEntry fnName;
   StringTableEntry fnNamespace, fnPackage;
   SimObject *currentNewObject = 0;
   StringTableEntry curField;
   SimObject *curObject;
   SimObject *saveObject=NULL;
   Namespace::Entry *nsEntry;
   Namespace *ns;

   U32 callArgc;
   ConsoleValue *callArgv;

   ConsoleValue curFieldArray;
   ConsoleValue curArray;
   ConsoleValue returnVal;

   CodeBlock *saveCodeBlock = smCurrentCodeBlock;
   smCurrentCodeBlock = this;
   if(this->name)
   {
      Con::gCurrentFile = this->name;
      Con::gCurrentRoot = mRoot;
   }
   const char * val;
   for(;;)
   {
      U32 instruction = code[ip++];
breakContinue:
      switch(instruction)
      {
         case OP_FUNC_DECL:
            if(!noCalls)
            {
               fnName       = U64toSTE(code[ip]);
               fnNamespace  = U64toSTE(code[ip+1]);
               fnPackage    = U64toSTE(code[ip+2]);
               bool hasBody = bool(code[ip+3]);
               
               Namespace::unlinkPackages();
               ns = Namespace::find(fnNamespace, fnPackage);
               ns->addFunction(fnName, this, hasBody ? ip : 0);// if no body, set the IP to 0
               Namespace::relinkPackages();

               //Con::printf("Adding function %s::%s (%d)", fnNamespace, fnName, ip);
            }
            ip = code[ip + 4];
            break;

         case OP_CREATE_OBJECT:
         {
            // If we don't allow calls, we certainly don't allow creating objects!
            if(noCalls)
                goto fail_cleanup;

            // Read some useful info.
            callArgc         =          code[ip    ];   // at least 3.
            objParent        = U64toSTE(code[ip + 1]);  // ...(Name : Parent [,...])... (copy fields, eg. Gui profiles)
            bool isDataBlock =          code[ip + 2];   // datablock ...{...};
            failJump         =          code[ip + 3];   // if we can't create the object...

            // TODO: Readjust callbacks to not account for fnName (even for OP_CALL_FUNC)

            // Get the constructor arguments off the stack.
            // argv = {0: NULL, 1: ClassName, 2: ObjectName, 3...N: Constructor args}
            callArgv = &valueStack[TOP - callArgc];

            // Con::printf("Creating object...");

            // objectName = argv[1]...
            currentNewObject = NULL;

            // Are we creating a datablock? If so, deal with case where we override
            // an old one.
            if(isDataBlock)
            {
               // Con::printf("  - is a datablock");

               // Find the old one if any.
               SimObject *db = Sim::getDataBlockGroup()->findObject(callArgv[2].toSTString());
               
               // Make sure we're not changing types on ourselves...
               if(db && dStricmp(db->getClassName(), callArgv[1].toString()))
               {
                  Con::errorf(ConsoleLogEntry::General, "Cannot re-declare data block %s with a different class.", callArgv[2]);
                  goto fail_cleanup;
               }

               // If there was one, set the currentNewObject and move on.
               if(db)
                  currentNewObject = db;
            }

            if(!currentNewObject)
            {
               // Well, looks like we have to create a new object. (no need for ST string here, already done in call.)
               ConsoleObject *object = ConsoleObject::create(callArgv[1].toString());

               // Deal with failure!
               if(!object)
               {
                  Con::errorf(ConsoleLogEntry::General, "%s: Unable to instantiate non-conobject class %s.", getFileLine(ip-1), callArgv[1]);
                  goto fail_cleanup;
               }

               // Do special datablock init if appropros
               if(isDataBlock)
               {
                  SimDataBlock *dataBlock = dynamic_cast<SimDataBlock *>(object);
                  if(dataBlock)
                  {
                     dataBlock->assignId();
                  }
                  else
                  {
                     // They tried to make a non-datablock with a datablock keyword!
                     Con::errorf(ConsoleLogEntry::General, "%s: Unable to instantiate non-datablock class %s.", getFileLine(ip-1), callArgv[1]);

                     // Clean up...
                     delete object;
                     goto fail_cleanup;
                  }
               }

               // Finally, set currentNewObject to point to the new one.
               currentNewObject = dynamic_cast<SimObject *>(object);

               // Deal with the case of a non-SimObject.
               if(!currentNewObject)
               {
                  Con::errorf(ConsoleLogEntry::General, "%s: Unable to instantiate non-SimObject class %s.", getFileLine(ip-1), callArgv[1]);
                  delete object;
                  goto fail_cleanup;
               }

               // Does it have a parent object? (ie, the copy constructor : syntax, not inheriance)
               if(*objParent)
               {
                  // Find it!
                  SimObject *parent;
                  if(Sim::findObject(objParent, parent))
                  {
                     // Con::printf(" - Parent object found: %s", parent->getClassName());

                     // and suck the juices from it!
                     currentNewObject->assignFieldsFrom(parent);
                  }
                  else
                     Con::errorf(ConsoleLogEntry::General, "%s: Unable to find parent object %s for %s.", getFileLine(ip-1), objParent, callArgv[1]);

                  // Mm! Juices!
               }

               // If a name was passed, assign it.
               if(callArgv[2].castTo(ConsoleValue::TypeString) && !callArgv[2].isNullString())
                  currentNewObject->assignName(callArgv[2].getStringU());

               // Do the constructor parameters.
               if(!currentNewObject->processArguments(callArgc-3, callArgv+3))
               {
                  delete currentNewObject;
                  currentNewObject = NULL;
                  goto fail_cleanup;
               }

               // If it's not a datablock, allow people to modify bits of it.
               if(!isDataBlock)
               {
                  currentNewObject->setModStaticFields(true);
                  currentNewObject->setModDynamicFields(true);
               }
            }

            // Clean stack and advance the IP past the create info...
            // (Argc - 1)
            popValueStack(callArgc-1);
            ip += 4;
            break;

         fail_cleanup:
            ip = failJump;
            popValueStack(callArgc-1);
            break;
         }

         case OP_ADD_OBJECT:
         {
            // Do we place this object at the root?
            bool placeAtRoot = code[ip++];

            // Con::printf("Adding object %s", currentNewObject->getName());

            // Make sure it wasn't already added, then add it.
            if(currentNewObject->isProperlyAdded() == false && !currentNewObject->registerObject())
            {
               // This error is usually caused by failing to call Parent::initPersistFields in the class' initPersistFields().
               Con::warnf(ConsoleLogEntry::General, "%s: Register object failed for object %s of class %s.", getFileLine(ip-2), currentNewObject->getName(), currentNewObject->getClassName());
               delete currentNewObject;
               ip = failJump;
               break;
            }

            // Are we dealing with a datablock?
            SimDataBlock *dataBlock = dynamic_cast<SimDataBlock *>(currentNewObject);
            static char errorBuffer[SimDataBlock::ErrorBufferSize];

            // If so, preload it.
            if(dataBlock && !dataBlock->preload(true, errorBuffer))
            {
               Con::errorf(ConsoleLogEntry::General, "%s: preload failed for %s: %s.", getFileLine(ip-2),
                           currentNewObject->getName(), errorBuffer);
               dataBlock->deleteObject();
               ip = failJump;
               break;
            }

            // What group will we be added to, if any?
            U32 groupAddId = valueStack[TOP].getInt();
            SimGroup *grp = NULL;
            SimSet   *set = NULL;

            if(!placeAtRoot || !currentNewObject->getGroup())
            {
               if(placeAtRoot)
               {
                  // Deal with the instantGroup if we're being put at the root.
                  const char *addGroupName = Con::getVariable("instantGroup").toString();
                  if(!Sim::findObject(addGroupName, grp))
                     Sim::findObject(RootGroupId, grp);
               }
               else
               {
                  // Otherwise just add to the requested group or set.
                  if(!Sim::findObject(groupAddId, grp))
                     Sim::findObject(groupAddId, set);
               }

               // If we didn't get a group, then make sure we have a pointer to
               // the rootgroup.
               if(!grp)
                  Sim::findObject(RootGroupId, grp);

               // add to the parent group
               grp->addObject(currentNewObject);

               // add to any set we might be in
               if(set)
                  set->addObject(currentNewObject);
            }

            // store the new object's ID on the stack (overwriting the group/set
            // id, if one was given, otherwise getting pushed)
            if(placeAtRoot) 
               valueStack[TOP] = currentNewObject->scriptThis();
            else
               valueStack[++TOP] = currentNewObject->scriptThis();

            break;
         }

         case OP_END_OBJECT:
         {
            // If we're not to be placed at the root, make sure we clean up
            // our group reference.
            bool placeAtRoot = code[ip++];
            if (!placeAtRoot)
               popValueStack();
            break;
         }

         case OP_INSTANCEOF_OBJECT:
         {
            SimObject* object = Sim::findObject( valueStack[TOP-1].toSTString() );
            var = valueStack[TOP].toSTString();
            bool found = false;
            if (object)
            {
                Namespace* ns = object->getNamespace();
                for (; ns; ns = ns->mParent)
                    if (ns->mName == var)
                    {
                        found = true;
                        break;
                    }
            }
            valueStack[TOP-1] = S64(found);
            popValueStack();
            break;
         }

         case OP_JMPIFFNOT:
            if(valueStack[TOP].getNumber()) {
               ip++;
               popValueStack();
               break;
            }
            popValueStack();
            ip = code[ip];
            break;
         case OP_JMPIFNOT:
            if(valueStack[TOP].getInt()) {
               ip++;
               popValueStack();
               break;
            }
            popValueStack();
            ip = code[ip];
            break;
         case OP_JMPIFF:
            if(!valueStack[TOP].getNumber()) {
               ip++;
               popValueStack();
               break;
            }
            popValueStack();
            ip = code[ip];
            break;
         case OP_JMPIF:
            if(!valueStack[TOP].getInt()) {
               ip ++;
               popValueStack();
               break;
            }
            popValueStack();
            ip = code[ip];
            break;
         case OP_JMPIFNOT_NP:
            if(valueStack[TOP].getInt()) {
               popValueStack();
               ip++;
               break;
            }
            ip = code[ip];
            break;
         case OP_JMPIF_NP:
            if(!valueStack[TOP].getInt()) {
               popValueStack();
               ip++;
               break;
            }
            ip = code[ip];
            break;
         case OP_JMP:
            ip = code[ip];
            break;

         case OP_RETURN:
            returnVal = valueStack[TOP];
            popValueStack();
         case OP_RETURN_NONE:
            goto execFinished;

         case OP_CMPEQ:
            valueStack[TOP-1] = S64(valueStack[TOP-1].compare(valueStack[TOP]) == 0);
            popValueStack();
            break;

         case OP_CMPGR:
            valueStack[TOP-1] = S64(valueStack[TOP-1].compare(valueStack[TOP]) > 0);
            popValueStack();
            break;

         case OP_CMPGE:
            valueStack[TOP-1] = S64(valueStack[TOP-1].compare(valueStack[TOP]) >= 0);
            popValueStack();
            break;

         case OP_CMPLT:
            valueStack[TOP-1] = S64(valueStack[TOP-1].compare(valueStack[TOP]) < 0);
            popValueStack();
            break;

         case OP_CMPLE:
            valueStack[TOP-1] = S64(valueStack[TOP-1].compare(valueStack[TOP]) <= 0);
            popValueStack();
            break;

         case OP_CMPNE:
            valueStack[TOP-1] = S64(valueStack[TOP-1].compare(valueStack[TOP]) != 0);
            popValueStack();
            break;

         case OP_XOR:
            valueStack[TOP-1] = S64(valueStack[TOP-1].getInt() ^ valueStack[TOP].getInt());
            popValueStack();
            break;

         case OP_MOD:
            valueStack[TOP-1] = S64(valueStack[TOP-1].getInt() % valueStack[TOP].getInt());
            popValueStack();
            break;

         case OP_BITAND:
            valueStack[TOP-1] = S64(valueStack[TOP-1].getInt() & valueStack[TOP].getInt());
            popValueStack();
            break;

         case OP_BITOR:
            valueStack[TOP-1] = S64(valueStack[TOP-1].getInt() | valueStack[TOP].getInt());
            popValueStack();
            break;

         case OP_NOT:
            valueStack[TOP] = S64(!valueStack[TOP].getInt());
            break;

         case OP_ONESCOMPLEMENT:
            valueStack[TOP] = S64(~valueStack[TOP].getInt());
            break;

         case OP_SHR:
            valueStack[TOP-1] = S64(valueStack[TOP-1].getInt() >> valueStack[TOP].getInt());
            popValueStack();
            break;

         case OP_SHL:
            valueStack[TOP-1] = S64(valueStack[TOP-1].getInt() << valueStack[TOP].getInt());
            popValueStack();
            break;

         case OP_ADD:
            valueStack[TOP-1] = F64(valueStack[TOP-1].getNumber() + valueStack[TOP].getNumber());
            popValueStack();
            break;

         case OP_SUB:
            valueStack[TOP-1] = F64(valueStack[TOP-1].getNumber() - valueStack[TOP].getNumber());
            popValueStack();
            break;

         case OP_MUL:
            valueStack[TOP-1] = F64(valueStack[TOP-1].getNumber() * valueStack[TOP].getNumber());
            popValueStack();
            break;
         case OP_DIV:
            valueStack[TOP-1] = F64(valueStack[TOP-1].getNumber() / valueStack[TOP].getNumber());
            popValueStack();
            break;
         case OP_NEG:
            valueStack[TOP] = F64(-valueStack[TOP].getNumber());
            break;

        // GLOBAL VARIABLES
         case OP_SETCURVAR:
            var = U64toSTE(code[ip]);
            ip++;
            gEvalState.setCurVarName(var);
            break;

         case OP_SETCURVAR_CREATE:
            var = U64toSTE(code[ip]);
            ip++;
            gEvalState.setCurVarNameCreate(var);
            break;

         case OP_SETCURVAR_ARRAY:
            // Rely on str index argument
            curArray = U64toSTE(code[ip++]);
            curArray.concatU(valueStack[TOP]);
            gEvalState.setCurVarName(curArray.toSTString());
            popValueStack();
            break;

         case OP_SETCURVAR_ARRAY_CREATE:
            // Rely on previous call to OP_LOADIDENT
            valueStack[TOP-1].concatU(valueStack[TOP]);
            gEvalState.setCurVarNameCreate(valueStack[TOP-1].toSTString());
            popValueStack(2);
            break;

        // LOCAL VARIABLES
         case OP_SETCURLOCAL:
             var = U64toSTE(code[ip++]);
             gEvalState.setCurLocalName(var);
             break;

         case OP_SETCURLOCAL_CREATE:
             var = U64toSTE(code[ip++]);
             gEvalState.setCurLocalNameCreate(var);
             break;

         case OP_SETCURLOCAL_ARRAY:
             // Rely on str index argument
             curArray = U64toSTE(code[ip++]);
             curArray.concatU(valueStack[TOP]);
             gEvalState.setCurLocalName(curArray.toSTString());
             popValueStack();
             break;

         case OP_SETCURLOCAL_ARRAY_CREATE:
             // Rely on previous call to OP_LOADIDENT
             valueStack[TOP-1].concatU(valueStack[TOP]);
             gEvalState.setCurLocalNameCreate(valueStack[TOP-1].toSTString());
             popValueStack(2);
             break;

         case OP_LOADVAR:
            valueStack[TOP++] = gEvalState.getVariable();
            break;

         case OP_SAVEVAR:
            gEvalState.setVariable(valueStack[TOP]);
            break;

         case OP_SETCUROBJECT:
            if (valueStack[TOP].getType() == ConsoleValue::TypeInt)
                curObject = Sim::findObject(valueStack[TOP].getIntU());
            else curObject = Sim::findObject(valueStack[TOP].toSTString());
            popValueStack();
            break;

         case OP_SETCUROBJECT_NEW:
            // object being constructed, valid between OP_CREATE_OBJECT and OP_ADD_OBJECT.
            curObject = currentNewObject; 
            break;

         case OP_SETCURFIELD:
            curField = U64toSTE(code[ip]);
            curFieldArray = CONVALUE_NULL;
            ip++;
            break;

         case OP_SETCURFIELD_ARRAY:
            // consume array expression for field.
            curFieldArray = valueStack[TOP];
            popValueStack();
            break;

         case OP_LOADFIELD:
            if(curObject)
               valueStack[++TOP] = curObject->getDataField(curField, curFieldArray.toString());
            else
               valueStack[++TOP] = CONVALUE_NULL;
            break;

         case OP_SAVEFIELD:
            if(curObject)
               curObject->setDataField(curField, curFieldArray.toString(), valueStack[TOP]);
            break;

         case OP_STRNOTNULL:
            // useful to test if not equal to null term (0)
            valueStack[TOP] = S64( !valueStack[TOP].isNullString() );
            break;

         case OP_VAL_TO_NONE:
            // This exists simply to deal with popping the stack when an expression is used as a statement.
            popValueStack();
            break;

         case OP_LOADIMMED_UINT:
            valueStack[++TOP] = S64(code[ip++]);
            break;

         case OP_LOADIMMED_FLT:
            conv.i = code[ip++];
            valueStack[++TOP] = conv.f;
            break;

         case OP_TAG_TO_STR:
            code[ip-1] = OP_LOADIMMED_STR;
            // it's possible the string has already been converted
            if(U8(curStringTable[code[ip]]) != StringTagPrefixByte)
            {
               U32 id = GameAddTaggedString(curStringTable + code[ip]);
               dSprintf(curStringTable + code[ip] + 1, 7, "%d", id);
               *(curStringTable + code[ip]) = StringTagPrefixByte;
            }

         case OP_LOADIMMED_STR:
            valueStack[++TOP] = curStringTable + code[ip++];
            break;

         case OP_LOADIMMED_IDENT:
            valueStack[++TOP] = U64toSTE(code[ip++]);
            break;

         case OP_CALLFUNC_RESOLVE:
            // This deals with a function that is potentially living in a namespace.
            fnNamespace = U64toSTE(code[ip+1]);
            fnName      = U64toSTE(code[ip]);

            // Try to look it up.
            ns = Namespace::find(fnNamespace);  // Awful.
            nsEntry = ns->lookup(fnName);
            if(!nsEntry)
            {
               ip+= 4; // Must be the same offset as done in OP_CALLFUNC
               Con::warnf(ConsoleLogEntry::General,
                  "%s: Unable to find function %s%s%s",
                  getFileLine(ip-4), fnNamespace ? fnNamespace : "",
                  fnNamespace ? "::" : "", fnName);
               // FIXME: The line below is useless, right???
               //STR.getArgcArgv(fnName, &callArgc, &callArgv);
               break;
            }
            // Now, rewrite our code a bit (ie, avoid future lookups) and fall
            // through to OP_CALLFUNC
            code[ip+1] = *((U64 *) &nsEntry);
            code[ip-1] = OP_CALLFUNC;

         case OP_CALLFUNC:
         {
            fnName = U64toSTE(code[ip]);

            //if this is called from inside a function, append the ip and codeptr
            if (!gEvalState.stack.empty())
            {
               gEvalState.stack.last().code = this;
               gEvalState.stack.last().ip = ip - 1;
            }

            U32 callType = code[ip+2];  // FuncCallExprNode::calltype
            callArgc     = code[ip+3];

            ip += 4;    // Pre-emptively move from call to next instruction for later.
            
            // Args are already pushed on the string stack, retrieve them.
            // argv = {0: FuncName, 1: Object, 2...N: args} or {0: FuncName, 1...N: args}
            callArgv = &valueStack[TOP - callArgc];

            if(callType == FuncCallExprNode::FunctionCall) {
               nsEntry = *((Namespace::Entry **) &code[ip-3]);
               ns = NULL;
            }
            else if(callType == FuncCallExprNode::MethodCall)
            {
               saveObject = gEvalState.thisObject;
               gEvalState.thisObject = Sim::findObject(callArgv[1].toString());
               if(!gEvalState.thisObject)
               {
                  gEvalState.thisObject = 0;
                  Con::warnf(ConsoleLogEntry::General,"%s: Unable to find object: '%s' attempting to call function '%s'", getFileLine(ip-4), callArgv[1], fnName);
                  break;
               }
               ns = gEvalState.thisObject->getNamespace();
               if(ns)
                  nsEntry = ns->lookup(fnName);
               else
                  nsEntry = NULL;
            }
            else // it's a ParentCall
            {
               if(thisNamespace)
               {
                  ns = thisNamespace->mParent;
                  if(ns)
                     nsEntry = ns->lookup(fnName);
                  else
                     nsEntry = NULL;
               }
               else
               {
                  ns = NULL;
                  nsEntry = NULL;
               }
            }

            if(!nsEntry || noCalls)
            {
               if(!noCalls)
               {
                  Con::warnf(ConsoleLogEntry::General,"%s: Unknown command %s.", getFileLine(ip-4), fnName);
                  if(callType == FuncCallExprNode::MethodCall)
                  {
                     ConsoleValue nspaceList = dMove(getNamespaceList(ns));
                     Con::warnf(ConsoleLogEntry::General, "  Object %s(%d) %s",
                           gEvalState.thisObject->getName() ? gEvalState.thisObject->getName() : "",
                           gEvalState.thisObject->getId(), nspaceList.getStringU());
                  }
               }
               popValueStack(callArgc);
               valueStack[++TOP] = CONVALUE_NULL;
               break;
            }
            if(nsEntry->mType == Namespace::Entry::ScriptFunctionType)
            {
               if (nsEntry->mFunctionOffset) {
                  returnVal = nsEntry->mCode->exec(nsEntry->mFunctionOffset, fnName, nsEntry->mNamespace, callArgc+1, callArgv, false, nsEntry->mPackage, -1);
                  if (callArgc) {
                      popValueStack(callArgc-1); // only pop arg stack for script functions called within script.
                      valueStack[TOP] = returnVal;
                  } else
                      valueStack[++TOP] = returnVal;
               }
               else // no body, return null on stack
                  valueStack[++TOP] = CONVALUE_NULL;
            }
            else
            {
               if((nsEntry->mMinArgs && S32(callArgc+1) < nsEntry->mMinArgs) || (nsEntry->mMaxArgs && S32(callArgc+1) > nsEntry->mMaxArgs))
               {
                  const char* nsName = ns? ns->mName: "";
                  Con::warnf(ConsoleLogEntry::Script, "%s: %s::%s - wrong number of arguments.", getFileLine(ip-4), nsName, fnName);
                  Con::warnf(ConsoleLogEntry::Script, "%s: usage: %s", getFileLine(ip-4), nsEntry->mUsage);
               }
               else
               {
                  if(nsEntry->mType == Namespace::Entry::VoidCallbackType)
                  {
                     nsEntry->cb.mVoidCallbackFunc(gEvalState.thisObject, callArgc+1, callArgv);
                     popValueStack(callArgc);
                     if (code[ip] != OP_VAL_TO_NONE)
                         Con::warnf(ConsoleLogEntry::General, "%s: Call to %s in %s uses result of void function call.", getFileLine(ip - 4), fnName, functionName);
                     else ip++; // void: if OP_VAL_TO_NONE, nothing to pop -> skip.
                  } else {
                     returnVal = nsEntry->cb.mStringCallbackFunc(gEvalState.thisObject, callArgc+1, callArgv);
                     if (code[ip] != OP_VAL_TO_NONE) {
                         if (callArgc) {
                             popValueStack(callArgc-1); // pop arg stack for engine functions called within script.
                             valueStack[TOP] = returnVal;
                         } else valueStack[++TOP] = returnVal;
                     } else ip++; // engine callbacks do not push to the valueStack, "returnVal" is all we get.
                  }
               }
            }

            if(callType == FuncCallExprNode::MethodCall)
               gEvalState.thisObject = saveObject;
            break;
         }
         case OP_CONCAT_STR:
            if (valueStack[TOP-1].castTo(ConsoleValue::TypeString)) {
                valueStack[TOP-1].concatU(valueStack[TOP]);
            }
            popValueStack();
            break;

         case OP_CONCAT_CHAR:
            // Relies on U64 char to be stored as LE, so it already has 7 natural null terms.
            if (valueStack[TOP].castTo(ConsoleValue::TypeString)) {
                valueStack[TOP].concatU(ConsoleValue((char const*) &code[ip]));
            }
            ++ip;
            break;

         case OP_CONCAT_STR_COMMA:
            if (valueStack[TOP-1].castTo(ConsoleValue::TypeString)) {
                valueStack[TOP-1].concatU(ConsoleValue("_"));
                valueStack[TOP-1].concatU(valueStack[TOP]);
            }
            popValueStack();
            break;

         //case OP_ADVANCE_STR_NUL:
         //   STR.advanceChar(0);
         //   break;

         //case OP_REWIND_STR:
         //   STR.rewind();
         //   break;

         //case OP_TERMINATE_REWIND_STR:  // Can be called after dynamic variable name lookup ($a[b])
         //   STR.rewindTerminate();
         //   break;

         case OP_COMPARE_STR:
            valueStack[TOP-1] = S64(!valueStack[TOP-1].compare(valueStack[TOP]));
            popValueStack();
            break;
         /*case OP_PUSH:
            STR.push();
            break;

         case OP_PUSH_FRAME:
            STR.pushFrame();
            break;*/
         //case OP_BREAK:
         //{
         //   //append the ip and codeptr before managing the breakpoint!
         //   AssertFatal( !gEvalState.stack.empty(), "Empty eval stack on break!");
         //   gEvalState.stack.last()->code = this;
         //   gEvalState.stack.last()->ip = ip - 1;

         //   U32 breakLine;
         //   findBreakLine(ip-1, breakLine, instruction);
         //   if(!breakLine)
         //      goto breakContinue;
         //   //TelDebugger->executionStopped(this, breakLine);
         //   goto breakContinue;
         //}
         case OP_INVALID:

         default:
            // error!
            goto execFinished;
      }
   }
execFinished:

   //if (TelDebugger && setFrame < 0)
   //   TelDebugger->popStackFrame();

   if ( popFrame )
      gEvalState.popFrame();

   if(argv)
   {
      if(gEvalState.traceOn)
      {
         traceBuffer[0] = 0;
         dStrcat(traceBuffer, "Leaving ");

         if(packageName)
         {
            dStrcat(traceBuffer, "[");
            dStrcat(traceBuffer, packageName);
            dStrcat(traceBuffer, "]");
         }
         size_t used = dStrlen(traceBuffer);
         if(thisNamespace && thisNamespace->mName)
         {
            used += dSprintf(traceBuffer + used, sizeof(traceBuffer) - used,
               "%s::%s() - return ", thisNamespace->mName, thisFunctionName);
            returnVal.serialize(traceBuffer, 1024 - used);
         }
         else
         {
            used += dSprintf(traceBuffer + used, sizeof(traceBuffer) - used,
               "%s() - return ", thisFunctionName);
            returnVal.serialize(traceBuffer, 1024 - used);
         }
         Con::printf("%s", traceBuffer);
      }
   }
   else
   {
      delete[] const_cast<char*>(globalStrings);
      globalStrings = NULL;
   }
   smCurrentCodeBlock = saveCodeBlock;
   if(saveCodeBlock && saveCodeBlock->name)
   {
      Con::gCurrentFile = saveCodeBlock->name;
      Con::gCurrentRoot = saveCodeBlock->mRoot;
   }

   // curFieldArray is also free'd here implicitly.
   AssertFatal(DBG_ENTER_TOP == TOP, "The stack was not cleaned up correctly.");

   decRefCount();
   return returnVal;
}

//------------------------------------------------------------
