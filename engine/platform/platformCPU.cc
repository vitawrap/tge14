//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------


#include "platform/platform.h"
#include "core/stringTable.h"

enum CPUFlags
{
   BIT_FPU     = BIT(0),
   BIT_RDTSC   = BIT(4),
   BIT_MMX     = BIT(23),
   BIT_SSE     = BIT(25),
   BIT_3DNOW   = BIT(31),
};

// fill the specified structure with information obtained from asm code
void SetProcessorInfo(Platform::SystemInfo_struct::Processor& pInfo, char const* vendor, char const* brand)
{
   if (dStricmp(vendor, "GenuineIntel") == 0)
   {
      pInfo.type = CPU_Intel;
      pInfo.name = StringTable->insert(brand? brand : "Intel");
   }
   //--------------------------------------
   else if (dStricmp(vendor, "AuthenticAMD") == 0)
   {
      pInfo.type = CPU_AMD;
      pInfo.name = StringTable->insert(brand? brand : "AMD");
   }
   //--------------------------------------
   else if (dStricmp(vendor, "Apple") == 0)
   {
      pInfo.type = CPU_Apple;
      pInfo.name = StringTable->insert(brand? brand : "Apple");
   }
   else
   {
#if defined(TORQUE_CPU_ARM64)
      pInfo.type = CPU_ARMCompatible;
      pInfo.name = StringTable->insert(brand? brand : "Arm Compatible (unknown)");
#else
      pInfo.type = CPU_X86Compatible;
      pInfo.name = StringTable->insert(brand? brand : "x86 Compatible (unknown)");
#endif
   }
}
