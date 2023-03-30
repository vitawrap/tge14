//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#include "platform/platform.h"

//--------------------------------------
//U32 getBinLog2(U32 io_num)
//{
//   AssertFatal(io_num != 0 && isPow2(io_num) == true,
//               "Error, this only works on powers of 2 > 0");
//
//   S32 shiftCount = 0;
//   while (io_num) {
//      shiftCount++;
//      io_num >>= 1;
//   }
//
//   return U32(shiftCount - 1);
//}