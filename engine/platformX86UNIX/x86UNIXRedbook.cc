//-----------------------------------------------------------------------------
// Torque Game Engine 
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------



#include "console/console.h"
#include "platformX86UNIX/platformX86UNIX.h"
#include "platform/platformRedBook.h"

#if defined(__linux__)
#include <linux/cdrom.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <string.h>
#endif

#include <SDL2/SDL.h>

class UnixRedBookDevice : public RedBookDevice
{
#if !defined(__FreeBSD__)
   private:
#endif
      void openVolume();
      void closeVolume();
      void setLastError(const char *);

   public:
      UnixRedBookDevice();
      ~UnixRedBookDevice();

      bool open();
      bool close();
      bool play(U32);
      bool stop();
      bool getTrackCount(U32 *);
      bool getVolume(F32 *);
      bool setVolume(F32);

      bool isPlaying() { return false; }
      bool updateStatus();
      void setDeviceInfo(S32 deviceId, const char *deviceName);
};

//-------------------------------------------------------------------------------
// Class: UnixRedBookDevice
//-------------------------------------------------------------------------------
UnixRedBookDevice::UnixRedBookDevice()
{
#if !defined(__FreeBSD__)
#endif	// !defined(__FreeBSD__)
}

//------------------------------------------------------------------------------
UnixRedBookDevice::~UnixRedBookDevice()
{
#if !defined(__FreeBSD__)
   close();
#endif	// !defined(__FreeBSD__)
}

//------------------------------------------------------------------------------
bool UnixRedBookDevice::updateStatus()
{
#if !defined(__FreeBSD__)
#endif	// !defined(__FreeBSD__)
}

//------------------------------------------------------------------------------
void UnixRedBookDevice::setDeviceInfo(S32 deviceId, const char *deviceName)
{
#if !defined(__FreeBSD__)
#endif	// !defined(__FreeBSD__)
}

//------------------------------------------------------------------------------
bool UnixRedBookDevice::open()
{
#if !defined(__FreeBSD__)
#endif	// !defined(__FreeBSD__)
}

//------------------------------------------------------------------------------
bool UnixRedBookDevice::close()
{
#if !defined(__FreeBSD__)
#endif	// !defined(__FreeBSD__)
}

//------------------------------------------------------------------------------
bool UnixRedBookDevice::play(U32 track)
{
#if !defined(__FreeBSD__)
#endif	// !defined(__FreeBSD__)
}

//------------------------------------------------------------------------------
bool UnixRedBookDevice::stop()
{
#if !defined(__FreeBSD__)
#endif	// !defined(__FreeBSD__)
}

//------------------------------------------------------------------------------
bool UnixRedBookDevice::getTrackCount(U32 * numTracks)
{
#if !defined(__FreeBSD__)
#endif	// !defined(__FreeBSD__)
}

template <class Type>
static inline Type max(Type v1, Type v2)
{
   if (v1 <= v2)
      return v2;
   else
      return v1;
}
//------------------------------------------------------------------------------
bool UnixRedBookDevice::getVolume(F32 * volume)
{
#if !defined(__FreeBSD__)
#endif	// !defined(__FreeBSD__)
}

//------------------------------------------------------------------------------
bool UnixRedBookDevice::setVolume(F32 volume)
{
#if !defined(__FreeBSD__)
#endif	// !defined(__FreeBSD__)
}

//------------------------------------------------------------------------------
void UnixRedBookDevice::openVolume()
{
#if !defined(__FreeBSD__)
#endif	// !defined(__FreeBSD__)
}

void UnixRedBookDevice::closeVolume()
{
#if !defined(__FreeBSD__)
#endif	// !defined(__FreeBSD__)
}

//------------------------------------------------------------------------------
void UnixRedBookDevice::setLastError(const char * error)
{
#if !defined(__FreeBSD__)
#endif	// !defined(__FreeBSD__)
}

//------------------------------------------------------------------------------
void InstallRedBookDevices()
{
#if !defined(__FreeBSD__) 
#endif	// !defined(__FreeBSD__)
}

//------------------------------------------------------------------------------
void PollRedbookDevices()
{
#if !defined(__FreeBSD__)
#endif	// !defined(__FreeBSD__)
}
