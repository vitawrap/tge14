
#ifndef INCLUDED_TYPES_CLANG_H
#define INCLUDED_TYPES_CLANG_H


// Useful page for clang built-in macros?
// https://clang.llvm.org/docs/LanguageExtensions.html


//--------------------------------------
// Types
typedef signed long long    S64;
typedef unsigned long long  U64;


//--------------------------------------
// Compiler Version
#define TORQUE_COMPILER_CLANG (__clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__)

//--------------------------------------
// Identify the Operating System
#if defined(__WIN64__) || defined(_WIN64)
#  define TORQUE_OS_STRING "Win64"
#  define TORQUE_OS_WIN64
//#  define TORQUE_SUPPORTS_NASM
#  define TORQUE_SUPPORTS_GCC_INLINE_X64_ASM
#  include "platform/types.win32.h"

#elif defined(__WIN32__) || defined(_WIN32)
#  define TORQUE_OS_STRING "Win32"
#  define TORQUE_OS_WIN32
#  define TORQUE_SUPPORTS_NASM
#  define TORQUE_SUPPORTS_GCC_INLINE_X86_ASM
#  include "platform/types.win32.h"

#elif defined(__unix__) && defined(__x86_64__)
#  define TORQUE_OS_STRING "Linux"
#  define TORQUE_OS_LINUX
//#  define TORQUE_SUPPORTS_NASM
#  define TORQUE_SUPPORTS_GCC_INLINE_X64_ASM
#  include "platform/types.posix.h"

#elif defined(__unix__)
#  define TORQUE_OS_STRING "Linux"
#  define TORQUE_OS_LINUX
#  define TORQUE_SUPPORTS_NASM
#  define TORQUE_SUPPORTS_GCC_INLINE_X86_ASM
#  include "platform/types.posix.h"

#elif defined(__OpenBSD__)
#  define TORQUE_OS_STRING "OpenBSD"
#  define TORQUE_OS_OPENBSD
#  define TORQUE_SUPPORTS_NASM
#  define TORQUE_SUPPORTS_GCC_INLINE_X86_ASM
#  include "platform/types.posix.h"

#elif defined(__FreeBSD__)
#  define TORQUE_OS_STRING "FreeBSD"
#  define TORQUE_OS_FREEBSD
#  define TORQUE_SUPPORTS_NASM
#  define TORQUE_SUPPORTS_GCC_INLINE_X86_ASM
#  include "platform/types.posix.h"

#elif defined(__APPLE__)
#  define TORQUE_OS_MAC
#  define TORQUE_OS_MAC_OSX
#  include "platform/types.ppc.h"
// for the moment:
#  include "platformMacCarb/macCarb_common_prefix.h"
#else 
#  error "CLANG: Unsupported Operating System"
#endif


//--------------------------------------
// Identify the CPU
#if defined(__x86_64__)
#  define TORQUE_CPU_STRING "Intel x64"
#  define TORQUE_CPU_X64
#  define TORQUE_LITTLE_ENDIAN

#elif defined(i386) || defined(__i386__)
#  define TORQUE_CPU_STRING "Intel x86"
#  define TORQUE_CPU_X86
#  define TORQUE_LITTLE_ENDIAN

#elif defined(__ppc__)
#  define TORQUE_CPU_STRING "PowerPC"
#  define TORQUE_CPU_PPC
#  define TORQUE_BIG_ENDIAN

#else
#  error "CLANG: Unsupported Target CPU"
#endif


#endif // INCLUDED_TYPES_CLANG_H

