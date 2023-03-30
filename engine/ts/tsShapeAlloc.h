//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#ifndef _TSSHAPEALLOC_H_
#define _TSSHAPEALLOC_H_

#ifndef _PLATFORM_H_
#include "platform/platform.h"
#endif
#ifndef _MMATH_H_
#include "math/mMath.h"
#endif

/// Alloc structure used in the reading/writing of shapes.
///
/// In read mode we assemble contents of 32-bit, 16-bit, and 8-bit buffers
/// into a single destination buffer.
///
/// In write mode we dissemble a stream of memory (which may be scattered in physical memory)
/// into 32-bit, 16-bit, 8-bit, Point3F, and Point2F buffers using function calls similar
/// to the read calls.
///
/// Read usage:
/// 1. call "setRead" with each incoming memory buffers and clear=true.
/// 2. run through set of operations for allocating and transfering memory to target buffer
///    these are the operations under "DECLARE_ALLOC" that call readOnly in the .cc file.
/// 3. call "doAlloc" to create buffer exactly as large as needed.
/// 4. repeat step 1 & 2 to do the actual transfer of memory, except with clear=false
///    (note: first time through nothing was copied to the shape, we only kept track
///    of the size of the transfer).
/// 5. call getBuffer to get the target (destination buffer)
///
/// write usage:
/// 1. call "setWrite" (no parameters).
/// 2. run through set of operations for allocating and transfering memory to internal buffers
///    these are the operations under "DECLARE_ALLOC" that call writeOnly in the .cc file.
/// 3. call getBuffer32 and getBufferSize32 to get 32-bit buffer and size.  Similarly for
///    16-bit, 8-bit (getBuffer16, getBuffer8).
///
/// TSShape::assesmbleShape and TSShape::dissembleShape can be used as examples
class TSShapeAlloc
{
   S32 mMode; ///< read or write

   /// reading and writing (when reading these are the input; when writing these are the output)
   S32     * mMemBuffer32;
   S16     * mMemBuffer16;
   S8      * mMemBuffer8;

   /// for writing only...
   S32 mSize32;
   S32 mSize16;
   S32 mSize8;
   S32 mFullSize32;
   S32 mFullSize16;
   S32 mFullSize8;

   /// reading and writing...
   S32 mMemGuard32;
   S16 mMemGuard16;
   S8 mMemGuard8;

   /// reading
   S32 mSaveGuard32;
   S16 mSaveGuard16;
   S8 mSaveGuard8;

   /// reading only...this is the output
   S8 * mDest;
   S32 mSize;
   S32 mMult; ///< mult incoming sizes by this (when 0, then mDest doesn't grow --> skip mode)

   public:

   enum { ReadMode = 0, WriteMode = 1, PageSize = 1024 }; ///< PageSize must be multiple of 4 so that we can always
                                                          ///< "over-read" up to next dword

   void setRead(S32 * buff32, S16 * buff16, S8 * buff8, bool clear);
   void setWrite();

   // reading only...
   void doAlloc();
   void align32(); ///< align on dword boundary
   S8 * getBuffer() { return mDest; }
   S32 getSize() { return mSize; }
   void setSkipMode(bool skip) { mMult = skip ? 0 : 1; }

   /// @name Reading Operations:
   ///
   /// get(): reads one or more entries of type from input buffer (doesn't affect output buffer)
   ///
   /// copyToShape(): copies entries of type from input buffer to output buffer
   ///
   /// allocShape(): creates room for entries of type in output buffer (no effect on input buffer)
   ///
   /// getPointer(): gets pointer to next entries of type in input buffer (no effect on input buffer)
   ///
   /// @note all operations advance current "position" of input and output buffers
   ///       writing operations:
   ///
   /// set(): adds one entry to appropriate buffer
   ///
   /// copyToBuffer(): adds count entries to approrpiate buffer
   ///
   /// getBuffer(): returns associated buffer (i.e., getBuffer32 gets 32bit buffer)
   ///
   /// getBufferSize(): returns size of associated buffer
   ///
   /// @{

    // S32 buffer
    S32 get32();
    void get32(S32*, S32);
    S32* copyToShape32(S32, bool returnSomething = false);
    S32* getPointer32(S32);
    S32* allocShape32(S32);
    bool checkGuard32();
    S32 getPrevGuard32();
    S32 getSaveGuard32();
    S32* getBuffer32();
    S32 getBufferSize32();
    void setGuard32();
    S32* extend32(S32);
    S32 set32(S32);
    void copyToBuffer32(S32*, S32);

    // S16 buffer
    S16 get16();
    void get16(S16*, S32);
    S16* copyToShape16(S32, bool returnSomething = false);
    S16* getPointer16(S32);
    S16* allocShape16(S32);
    bool checkGuard16();
    S16 getPrevGuard16();
    S16 getSaveGuard16();
    S16* getBuffer16();
    S32 getBufferSize16();
    void setGuard16();
    S16* extend16(S32);
    S16 set16(S16);
    void copyToBuffer16(S16*, S32);

    // S8 buffer
    S8 get8();
    void get8(S8*, S32);
    S8* copyToShape8(S32, bool returnSomething = false);
    S8* getPointer8(S32);
    S8* allocShape8(S32);
    bool checkGuard8();
    S8 getPrevGuard8();
    S8 getSaveGuard8();
    S8* getBuffer8();
    S32 getBufferSize8();
    void setGuard8();
    S8* extend8(S32);
    S8 set8(S8);
    void copyToBuffer8(S8*, S32);

    /// @}

    void checkGuard();
    void setGuard();
};

#endif // _H_TS_SHAPE_ALLOC_
