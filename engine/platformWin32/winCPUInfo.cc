//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#include "platform/platform.h"
#include "platformWin32/platformWin32.h"
#include "console/console.h"
#include "core/stringTable.h"
#include "core/frameAllocator.h"
#include <math.h>
#include <intrin.h> // __cpuid

Platform::SystemInfo_struct Platform::SystemInfo;
extern void PlatformBlitInit();
extern void SetProcessorInfo(Platform::SystemInfo_struct::Processor& pInfo,
   char const* vendor, char const* brand); // platform/platformCPU.cc

static void getBrand(char* brand)
{
    S32 extendedInfo[4];
    __cpuid(extendedInfo, 0x80000000);
    S32 numberExtendedIds = extendedInfo[0];

    // Sets brand
    if (numberExtendedIds >= 0x80000004)
    {
        int offset = 0;
        for (int i = 0; i < 3; ++i)
        {
            S32 brandInfo[4];
            __cpuidex(brandInfo, 0x80000002 + i, 0);

            *reinterpret_cast<int*>(brand + offset + 0) = brandInfo[0];
            *reinterpret_cast<int*>(brand + offset + 4) = brandInfo[1];
            *reinterpret_cast<int*>(brand + offset + 8) = brandInfo[2];
            *reinterpret_cast<int*>(brand + offset + 12) = brandInfo[3];

            offset += sizeof(S32) * 4;
        }
    }
}

enum CpuFlags
{
    // EDX Register flags
    BIT_MMX = BIT(23),
    BIT_SSE = BIT(25),
    BIT_SSE2 = BIT(26),
    BIT_3DNOW = BIT(31), // only available for amd cpus in x86

    // These use a different value for comparison than the above flags (ECX Register)
    BIT_SSE3 = BIT(0),
    BIT_SSE3ex = BIT(9),
    BIT_SSE4_1 = BIT(19),
    BIT_SSE4_2 = BIT(20),
};

static void detectCpuFeatures(Platform::SystemInfo_struct::Processor& processor)
{
    S32 cpuInfo[4];
    __cpuid(cpuInfo, 1);
    U32 edx = cpuInfo[3];   // edx
    U32 ecx = cpuInfo[2];   // ecx

    processor.properties |= (edx & BIT_MMX) ? CPU_PROP_MMX : 0;
    processor.properties |= (edx & BIT_SSE) ? CPU_PROP_SSE : 0;
    processor.properties |= (edx & BIT_SSE2) ? CPU_PROP_SSE2 : 0;
    processor.properties |= (edx & BIT_3DNOW) ? CPU_PROP_3DNOW: 0;
    processor.properties |= (ecx & BIT_SSE3|BIT_SSE3ex) ? CPU_PROP_SSE3 : 0;
    processor.properties |= (ecx & BIT_SSE4_1) ? CPU_PROP_SSE4_1 : 0;
    processor.properties |= (ecx & BIT_SSE4_2) ? CPU_PROP_SSE4_2 : 0;

    // For now do not do AVX-related detection, nor MP/64bit.
}

#if defined(TORQUE_SUPPORTS_NASM)
// asm cpu detection routine from platform code
extern "C"
{
   void detectX86CPUInfo(char *vendor, U32 *processor, U32 *properties);
}
#endif

#ifdef _MSC_VER
#include <intrin.h>
#endif // _MSC_VER


void Processor::init()
{
   // Reference:
   //    www.cyrix.com
   //    www.amd.com
   //    www.intel.com
   //       http://developer.intel.com/design/PentiumII/manuals/24512701.pdf

   Con::printf("Processor Init:");

   Platform::SystemInfo.processor.type = CPU_X86Compatible;
   Platform::SystemInfo.processor.name = StringTable->insert("Unknown " TORQUE_CPU_STRING " Compatible");
   Platform::SystemInfo.processor.mhz  = 0;
   Platform::SystemInfo.processor.properties = CPU_PROP_C | CPU_PROP_FPU;

   char  vendor[0x20] {};
   U32   properties = 0;
   U32   processor  = 0;

#if defined(TORQUE_SUPPORTS_NASM)
//#if 0
   detectX86CPUInfo(vendor, &processor, &properties);

#elif defined(TORQUE_SUPPORTS_VC_INLINE_X86_ASM)
   __asm
   {
      //--------------------------------------
      // is CPUID supported
      push     ebx
      push     edx
      push     ecx
      pushfd
      pushfd                     // save EFLAGS to stack
      pop      eax               // move EFLAGS into EAX
      mov      ebx, eax
      xor      eax, 0x200000     // flip bit 21
      push     eax
      popfd                      // restore EFLAGS
      pushfd
      pop      eax
      cmp      eax, ebx
      jz       EXIT              // doesn't support CPUID instruction

      //--------------------------------------
      // Get Vendor Informaion using CPUID eax==0
      xor      eax, eax
      cpuid

      mov      DWORD PTR vendor, ebx
      mov      DWORD PTR vendor+4, edx
      mov      DWORD PTR vendor+8, ecx

      // get Generic Extended CPUID info
      mov      eax, 1
      cpuid                      // eax=1, so cpuid queries feature information

      and      eax, 0x0ff0
      mov      processor, eax    // just store the model bits
      mov      properties, edx

      // Want to check for 3DNow(tm).  Need to see if extended cpuid functions present.
      mov      eax, 0x80000000
      cpuid
      cmp      eax, 0x80000000
      jbe      MAYBE_3DLATER
      mov      eax, 0x80000001
      cpuid
      and      edx, 0x80000000      // 3DNow if bit 31 set -> put bit in our properties
      or       properties, edx
   MAYBE_3DLATER:


   EXIT:
      popfd
      pop      ecx
      pop      edx
      pop      ebx
   }
#elif defined(_MSC_VER) // Use MSVC intrinsics?

   // Get vendor info
   S32 vendorInfo[4];
   __cpuid(vendorInfo, 0);
   *reinterpret_cast<int*>(vendor) = vendorInfo[1];     // ebx
   *reinterpret_cast<int*>(vendor + 4) = vendorInfo[3]; // edx
   *reinterpret_cast<int*>(vendor + 8) = vendorInfo[2]; // ecx

   // Get brand info
   char brand[0x40];
   dMemset(brand, 0, sizeof(brand));
   getBrand(brand);

#endif

   SetProcessorInfo(Platform::SystemInfo.processor, vendor, brand);
   detectCpuFeatures(Platform::SystemInfo.processor);

// now calculate speed of processor...
   U16 nearmhz = 0; // nearest rounded mhz
   U16 mhz = 0; // calculated value.
#if defined(TORQUE_SUPPORTS_VC_INLINE_X86_ASM) || defined(TORQUE_COMPILER_MINGW)
   //--------------------------------------
   // if RDTSC support calculate the aproximate Mhz of the CPU
   if (Platform::SystemInfo.processor.properties & CPU_PROP_RDTSC &&
       Platform::SystemInfo.processor.properties & CPU_PROP_FPU)
   {
      const U32 msToWait = 1000; // bigger this is, more accurate we are.
      U32 tsLo1 = 0, tsHi1 = 0; // time stamp storage.
      U32 tsLo2 = 0, tsHi2 = 0; // time stamp storage.
      U16 Nearest66Mhz = 0, Delta66Mhz = 0;
      U16 Nearest50Mhz = 0, Delta50Mhz = 0;
      F64 tsFirst, tsSecond, tsDelta;
      U32 ms;

      // starting time marker.
      ms = GetTickCount(); // !!!!TBD - this function may have too high an error... dunno.

   #if defined(TORQUE_COMPILER_MINGW)
      asm ("rdtsc" : "=a" (tsLo1), "=d" (tsHi1));
   #elif defined(TORQUE_SUPPORTS_VC_INLINE_X86_ASM)  // VC|CW
      __asm
      {
           push  eax
           push  edx
         rdtsc
         mov  tsLo1, eax
         mov  tsHi1, edx
           pop  edx
           pop  eax
      }
   #endif

      // the faster this check and exit is, the more accurate the time-stamp-delta will be.
      while(GetTickCount() < ms + msToWait) {};

   #if defined(TORQUE_COMPILER_MINGW)
      asm ("rdtsc" : "=a" (tsLo2), "=d" (tsHi2));
   #elif defined(TORQUE_SUPPORTS_VC_INLINE_X86_ASM)  // VC|CW
      __asm
      {
           push  eax
           push  edx
         rdtsc
         mov  tsLo2, eax
         mov  tsHi2, edx
           pop  edx
           pop  eax
      }
   #endif

      // do calculations in doubles for accuracy, since we're working with 64-bit math here...
      // grabbed this from the MINGW sample.
      tsFirst = ((F64)tsHi1 * (F64)0x10000 * (F64)0x10000) + (F64)tsLo1;
      tsSecond = ((F64)tsHi2 * (F64)0x10000 * (F64)0x10000) + (F64)tsLo2;
      // get the timestamp delta.  potentially large number here, as it's in Hz.
      tsDelta = tsSecond - tsFirst;

      // adjust for slightly-off-delay -- better to assume +1ms than try to really calc.
      tsDelta *= (F64)(msToWait + 1);
      tsDelta /= (F64)msToWait;
      // factor back into 1s of time.
      tsDelta *= ((F64)1000/(F64)msToWait);
      // then convert into Mhz
      tsDelta /= (F64)1000000;
      tsDelta += 0.5f; // trying to get closer to the right values, effectively rounding up.
      mhz = (U32)tsDelta;

      // Find nearest full/half multiple of 66/133 MHz
      Nearest66Mhz = ((((mhz * 3) + 100) / 200) * 200) / 3;
      // 660 = 1980 = 2080 = 100 = 2000 = 666
      // 440 = 1320 = 1420 = 70 = 1400 = 466

      // find delta to nearest 66 multiple.
      Delta66Mhz = abs(Nearest66Mhz - mhz);

      // Find nearest full/half multiple of 100 MHz
      Nearest50Mhz = (((mhz + 25) / 50) * 50);
      // 440 = 465 = 9 = 450

      // find delta to nearest 50 multiple.
      Delta50Mhz = abs(Nearest50Mhz - mhz);

      if (Delta50Mhz < Delta66Mhz) // closer to a 50 boundary
         nearmhz = Nearest50Mhz;
      else
      {
         nearmhz = Nearest66Mhz;
         if (nearmhz==666) // hack around -- !!!!TBD - other cases?!?!
            nearmhz = 667;
      }

      // !!!TBD
      // would be nice if we stored both the calculated and the adjusted/guessed values.
      Platform::SystemInfo.processor.mhz = nearmhz; // hold onto adjusted value only.
   }
#else
   // We can only operate with intrinsics here...
   mhz = nearmhz = 1000;  // start with generous assumption.

   LONG result;
   DWORD data = 0;
   DWORD dataSize = 4;
   HKEY hKey;

   result = ::RegOpenKeyExA(HKEY_LOCAL_MACHINE,
       "Hardware\\Description\\System\\CentralProcessor\\0", 0, KEY_QUERY_VALUE, &hKey);

   if (result == ERROR_SUCCESS) {
       result = ::RegQueryValueExA(hKey, "~MHz", NULL, NULL, (LPBYTE)&data, &dataSize);
       if (result == ERROR_SUCCESS) {
           mhz = data;
           nearmhz = data;
       }
       ::RegCloseKey(hKey);
   }
   Platform::SystemInfo.processor.mhz = mhz;
#endif

   if (mhz==0)
   {
      Con::printf("   %s, (Unknown) Mhz", Platform::SystemInfo.processor.name);
      // stick SOMETHING in so it isn't ZERO.
      Platform::SystemInfo.processor.mhz = 200; // seems a decent value.
   }
   else
   {
      if (nearmhz >= 1000)
         Con::printf("   %s, ~%.2f Ghz", Platform::SystemInfo.processor.name, ((float)nearmhz)/1000.0f);
      else
         Con::printf("   %s, ~%d Mhz", Platform::SystemInfo.processor.name, nearmhz);
      if (nearmhz != mhz)
      {
         if (mhz >= 1000)
            Con::printf("     (timed at roughly %.2f Ghz)", ((float)mhz)/1000.0f);
         else
            Con::printf("     (timed at roughly %d Mhz)", mhz);
      }
   }

   if (Platform::SystemInfo.processor.properties & CPU_PROP_FPU)
      Con::printf("   FPU detected");
   if (Platform::SystemInfo.processor.properties & CPU_PROP_RDTSC)
      Con::printf("   RDTSC detected");
   if (Platform::SystemInfo.processor.properties & CPU_PROP_MMX)
      Con::printf("   MMX detected");
   if (Platform::SystemInfo.processor.properties & CPU_PROP_3DNOW)
      Con::printf("   3DNow detected");
   if (Platform::SystemInfo.processor.properties & CPU_PROP_SSE)
      Con::printf("   SSE detected");
   if (Platform::SystemInfo.processor.properties & CPU_PROP_SSE2)
      Con::printf("   SSE2 detected");
   if (Platform::SystemInfo.processor.properties & CPU_PROP_SSE3)
      Con::printf("   SSE3 detected");
   if (Platform::SystemInfo.processor.properties & CPU_PROP_SSE4_1)
      Con::printf("   SSE4.1 detected");
   if (Platform::SystemInfo.processor.properties & CPU_PROP_SSE4_2)
      Con::printf("   SSE4.2 detected");
   Con::printf(" ");

   PlatformBlitInit();
}
