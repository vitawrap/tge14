//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#include "platform/platform.h"
#include "core/dataChunker.h"


//----------------------------------------------------------------------------

DataChunker::DataChunker(S32 size)
{
   chunkSize          = size;
   curBlock           = new DataBlock(size);
   curBlock->next     = NULL;
   curBlock->curIndex = 0;
}

DataChunker::~DataChunker()
{
   freeBlocks();
}

void *DataChunker::alloc(S32 size)
{
   //AssertFatal(size <= chunkSize, "Data chunk too large.");
   AssertWarn(size <= chunkSize, "Data chunk requested is very large, issues may occur.");
   U32 sz = chunkSize;
   while (size > sz)
       sz <<= 1;

   if(!curBlock || size + curBlock->curIndex >= curBlock->curSize)
   {
      DataBlock *temp = new DataBlock(sz);
      temp->next = curBlock;
      temp->curIndex = 0;
      curBlock = temp;
   }
   void *ret = curBlock->data + curBlock->curIndex;
   curBlock->curIndex += (size + 3) & ~3; // dword align
   return ret;
}

DataChunker::DataBlock::DataBlock(S32 size)
{
   data = new U8[size];
   curSize = size;
}

DataChunker::DataBlock::~DataBlock()
{
   delete[] data;
}

void DataChunker::freeBlocks()
{
   while(curBlock)
   {
      DataBlock *temp = curBlock->next;
      delete curBlock;
      curBlock = temp;
   }
}

//----------------------------------------------------------------------------

StackAllocator::StackBlock::StackBlock(S32 size)
{
    data = new U8[size];
    curSize = size;
}

StackAllocator::StackBlock::~StackBlock()
{
    delete[] data;
}

void* StackAllocator::alloc(S32 size, StackMarker& mkr)
{
    AssertWarn(size <= chunkSize, "Stack chunk requested is very large, issues may occur.");
    U32 sz = chunkSize;
    while (size > sz)
        sz <<= 1;

    if (!curBlock || size + curBlock->curIndex >= curBlock->curSize)
    {
        StackBlock* temp = new StackBlock(sz);
        temp->id = ++curId;
        temp->next = curBlock;
        temp->curIndex = 0;
        curBlock = temp;
    }
    void* ret = curBlock->data + curBlock->curIndex;

    // dword align (valid because sz always multiple of 4)
    curBlock->curIndex += (size + 3) & ~3;
    mkr = curId;
    return ret;
}

void StackAllocator::free(void* ptr, StackMarker& mkr)
{
    if (mkr == -1) return;  // Invalidated marker

    S32 destId = mkr;
    while (curBlock->id > destId)
    {
        StackBlock* temp = curBlock->next;
        delete curBlock;
        curBlock = temp;
    }
    if (curBlock)
        curBlock->curIndex = (U8*)ptr - curBlock->data;
    mkr = -1;
}

void StackAllocator::freeBlocks()
{
    while (curBlock)
    {
        StackBlock* temp = curBlock->next;
        delete curBlock;
        curBlock = temp;
    }
    curId = -1;
}

StackAllocator::StackAllocator(S32 size)
    : chunkSize(size)
    , curBlock(NULL)
    , curId(-1)
{
}

StackAllocator::~StackAllocator()
{
    freeBlocks();
}