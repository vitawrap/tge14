//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#ifndef _CONSOLEINTERNAL_H_
#define _CONSOLEINTERNAL_H_

#ifndef _STRINGTABLE_H_
#include "core/stringTable.h"
#endif
#ifndef _TVECTOR_H_
#include "core/tVector.h"
#endif
#ifndef _CONSOLETYPES_H_
#include "console/consoleTypes.h"
#endif
#ifndef _DICTIONARY_H_
#include "core/tDictionary.h"
#endif

class ExprEvalState;
struct FunctionDecl;
class CodeBlock;
class AbstractClassRep;

class Namespace
{
    enum {
        MaxActivePackages = 512,
    };

    static U32 mNumActivePackages;
    static U32 mOldNumActivePackages;
    static StringTableEntry mActivePackages[MaxActivePackages];
public:
    StringTableEntry mName;
    StringTableEntry mPackage;

    Namespace *mParent;
    Namespace *mNext;
    AbstractClassRep *mClassRep;
    U32 mRefCountToParent;

    struct Entry
    {
        enum {
            GroupMarker                  = -3,
            OverloadMarker               = -2,
            InvalidFunctionType          = -1,
            ScriptFunctionType,
            ValueCallbackType,
            VoidCallbackType,
        };

        Namespace *mNamespace;
        Entry *mNext;
        StringTableEntry mFunctionName;
        S32 mType;
        S32 mMinArgs;
        S32 mMaxArgs;
        const char *mUsage;
        StringTableEntry mPackage;

        CodeBlock *mCode;
        U32 mFunctionOffset;
        union {
            ValueCallback mStringCallbackFunc;
            VoidCallback mVoidCallbackFunc;
            const char* mGroupName;
        } cb;
        Entry();
        void clear();

        ConsoleValue execute(S32 argc, ConsoleValue* argv, ExprEvalState *state);

    };
    Entry *mEntryList;

    Entry **mHashTable;
    U32 mHashSize;
    U32 mHashSequence;  ///< @note The hash sequence is used by the autodoc console facility
                        ///        as a means of testing reference state.

    Namespace();
    void addFunction(StringTableEntry name, CodeBlock *cb, U32 functionOffset);
    void addCommand(StringTableEntry name,ValueCallback, const char *usage, S32 minArgs, S32 maxArgs);
    void addCommand(StringTableEntry name,VoidCallback, const char *usage, S32 minArgs, S32 maxArgs);

    void addOverload(const char *name, const char* altUsage);

    void markGroup(const char* name, const char* usage);
    char * lastUsage;

    void getEntryList(Vector<Entry *> *);
    void getEntryList(Vector<Entry*>* engine, Vector<Entry*>* script);  // Overload to separate engine and script functions

    Entry *lookup(StringTableEntry name);
    Entry *lookupRecursive(StringTableEntry name);
    Entry *createLocalEntry(StringTableEntry name);
    void buildHashTable();
    void clearEntries();
    bool classLinkTo(Namespace *parent);

    const char *tabComplete(const char *prevText, S32 baseLen, bool fForward);

    static U32 mCacheSequence;
    static DataChunker mCacheAllocator;
    static DataChunker mAllocator;
    static void trashCache();
    static Namespace *mNamespaceList;
    static Namespace *mGlobalNamespace;

    static void init();
    static void shutdown();
    static Namespace *global();

    static Namespace *find(StringTableEntry name, StringTableEntry package=NULL);

    static void activatePackage(StringTableEntry name);
    static void deactivatePackageStack(StringTableEntry name);
    static void deactivatePackage(StringTableEntry name);
    static void dumpClasses();
    static void dumpFunctions();
    static void printNamespaceEntries(Namespace * g);
    static void unlinkPackages();
    static void relinkPackages();
    static bool isPackage(StringTableEntry name);
    static bool isPackageActive(StringTableEntry name);
};

extern char *typeValueEmpty;

struct ConsoleValueEntry : public DictEntryBase<ConsoleValueEntry>
{
    // Positive type values are reserved for Type### constants set by ConsoleType(...)
    enum
    {
        TypeInternalValue = -1,
    };

    S32 type;   // either our internal types or a public console type
    ConsoleValue value;
    void* dataPtr;

    ConsoleValueEntry(StringTableEntry in_name)
        : value(""), DictEntryBase(in_name)
    {
        dataPtr = NULL;
        type = TypeInternalValue;
    }

    ConsoleValue getValue()
    {
        if (type == TypeInternalValue)
            return value;
        else
            return Con::getData(type, dataPtr, 0);
    }

    void setValue(ConsoleValue& src)
    {
        if (type == TypeInternalValue)
            value = src;
        else
            Con::setData(type, dataPtr, 0, src);
    }
};

class ConsoleValueDictionary : public Dictionary<ConsoleValueEntry>
{
private:
    typedef Dictionary<ConsoleValueEntry> Parent;
    ExprEvalState *exprState;
public:
    StringTableEntry scopeName;
    Namespace *scopeNamespace;
    CodeBlock *code;
    U32 ip;

    ConsoleValueDictionary();
    ConsoleValueDictionary(ExprEvalState *state, ConsoleValueDictionary* ref=NULL);

    void setStateEx(ExprEvalState* state, ConsoleValueDictionary* ref = NULL);

    void exportVariables(const char *varString, const char *fileName, bool append, bool runnable = true);
    void deleteVariables(const char *varString);

    void setVariable(StringTableEntry name, ConsoleValue& cv);
    ConsoleValue getVariable(StringTableEntry name, bool *valid = NULL);

    void addVariable(const char *name, S32 type, void *dataPtr);
    bool removeVariable(StringTableEntry name);

    /// Return the best tab completion for prevText, with the length
    /// of the pre-tab string in baseLen.
    const char *tabComplete(const char *prevText, S32 baseLen, bool);
};

class ExprEvalState
{
public:
    /// @name Expression Evaluation
    /// @{

    ///
    SimObject *thisObject;
    ConsoleValueDictionary::Entry *currentVariable;
    bool traceOn;

    ExprEvalState();
    ~ExprEvalState();

    /// @}

    /// @name Stack Management
    /// @{

    ///
    ConsoleValueDictionary globalVars;
    Vector<ConsoleValueDictionary> stack;
    void setCurVarName(StringTableEntry name);
    void setCurVarNameCreate(StringTableEntry name);
    void setCurLocalName(StringTableEntry name);
    void setCurLocalNameCreate(StringTableEntry name);
    ConsoleValue getVariable() const;
    void setVariable(ConsoleValue& value);

    void pushFrame(StringTableEntry frameName, Namespace *ns);
    void popFrame();

    /// Puts a reference to an existing stack frame
    /// on the top of the stack.
    void pushFrameRef(S32 stackIndex);

    /// @}
};

#endif
