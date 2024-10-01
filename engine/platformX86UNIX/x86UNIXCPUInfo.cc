//-----------------------------------------------------------------------------
// Torque Game Engine 
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------



#include "platform/platform.h"
#include "platformX86UNIX/platformX86UNIX.h"
#include "console/console.h"
#include "core/stringTable.h"
#include <math.h>

Platform::SystemInfo_struct Platform::SystemInfo;

extern void PlatformBlitInit();
extern void SetProcessorInfo(Platform::SystemInfo_struct::Processor& pInfo, 
   char const* vendor, char const* brand); // platform/platformCPU.cc

// asm cpu detection routine from platform code
extern "C" 
{
void detectX86CPUInfo(char *vendor, U32 *processor, U32 *properties);
}

/* used in the asm */
static U32 time[2];
static U32 clockticks = 0;
static char vendor[13] = {0,};
static char brand[64] {};
static U32 properties = 0;
static U32 processor  = 0;

void Processor::init()
{
   // Reference:
   //    www.cyrix.com
   //    www.amd.com
   //    www.intel.com
   //       http://developer.intel.com/design/PentiumII/manuals/24512701.pdf
#if defined(TORQUE_CPU_ARM64)
   Platform::SystemInfo.processor.type = CPU_ARMCompatible;
   Platform::SystemInfo.processor.name = StringTable->insert("Unknown ARM Compatible");
#else
   Platform::SystemInfo.processor.type = CPU_X86Compatible;
   Platform::SystemInfo.processor.name = StringTable->insert("Unknown x86 Compatible");
#endif
   Platform::SystemInfo.processor.mhz  = 0;
   Platform::SystemInfo.processor.properties = CPU_PROP_C | CPU_PROP_FPU;  // assume FPU...

   clockticks = properties = processor = 0;
   dStrcpy(vendor, "");

   char line[1024];
   FILE* fp = fopen("/proc/cpuinfo", "rt");
   if (fp) {
      while (fgets(line, 1024, fp)) {
         char* values = NULL;
         if (!(values = dStrchr(line, ':')))
            continue;

         // setup line (terminate in place of newline)
         size_t nl = dStrcspn(line, "\r\n");
         if (nl < 1024) line[nl] = 0;

         // setup key (terminate after all words)
         char* keyTerm = values - 1;
         while (keyTerm[0] == ' ' || keyTerm[0] == '\t')
            --keyTerm;
         keyTerm[1] = 0;

         // setup value (go to real start of value)
         values += dStrspn(values, " \t:");

         // start gathering info
         if (dStrcmp(line, "vendor_id") == 0) {
            dStrncpy(vendor, values, 13);
            vendor[12] = 0;
         }
         else if (dStrcmp(line, "model name") == 0) {
            dStrncpy(brand, values, 64);
            brand[63] = 0;
         }
         else if (dStrcmp(line, "flags") == 0) {
            if (! dStrstr((const char*) values, "fpu"))
               Platform::SystemInfo.processor.properties &= ~CPU_PROP_FPU;
            if (dStrstr((const char*) values, "mmx"))
               Platform::SystemInfo.processor.properties |= CPU_PROP_MMX;
            if (dStrstr((const char*) values, "sse4_2"))
               Platform::SystemInfo.processor.properties |= CPU_PROP_SSE4_2;
            if (dStrstr((const char*) values, "sse4_1"))
               Platform::SystemInfo.processor.properties |= CPU_PROP_SSE4_1;
            if (dStrstr((const char*) values, "ssse3"))
               Platform::SystemInfo.processor.properties |= CPU_PROP_SSE3;
            if (dStrstr((const char*) values, "sse2"))
               Platform::SystemInfo.processor.properties |= CPU_PROP_SSE2;
            if (dStrstr((const char*) values, "sse"))
               Platform::SystemInfo.processor.properties |= CPU_PROP_SSE;
            if (dStrstr((const char*) values, "tsc"))
               Platform::SystemInfo.processor.properties |= CPU_PROP_RDTSC;
         }
      }
      fclose(fp);
   }

   // now try getting frequency
   fp = fopen("/sys/devices/system/cpu/cpu0/cpufreq/base_frequency", "rt");
   if (fp) {
      size_t freq = 0;
      fscanf(fp, "%llu", &freq);
      Platform::SystemInfo.processor.mhz = freq / 1000;
      fclose(fp);
   }

   SetProcessorInfo(Platform::SystemInfo.processor, vendor, brand);

   Con::printf("Processor Init:");
   Con::printf("   %s, %d Mhz", Platform::SystemInfo.processor.name, Platform::SystemInfo.processor.mhz);
   if (Platform::SystemInfo.processor.properties & CPU_PROP_FPU)
      Con::printf("   FPU detected");
   if (Platform::SystemInfo.processor.properties & CPU_PROP_RDTSC)
      Con::printf("   RDTSC detected");
   if (Platform::SystemInfo.processor.properties & CPU_PROP_MMX)
      Con::printf("   MMX detected");
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
