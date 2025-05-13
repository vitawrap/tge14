//-----------------------------------------------------------------------------
// Torque Game Engine 
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------



#include "platformX86UNIX/platformX86UNIX.h"
#include "platform/platformInput.h"
#include "platform/platformVideo.h"
#include "platform/event.h"
#include "platform/gameInterface.h"
#include "console/console.h"
#include "platformX86UNIX/x86UNIXState.h"
#include "platformX86UNIX/x86UNIXInputManager.h"

#include <X11/Xlib.h>
#include <X11/Xatom.h>

#include <SDL2/SDL.h>

#ifdef LOG_INPUT
#include <time.h>
#include <stdarg.h>
#include <fcntl.h>
#include <platformX86UNIX/x86UNIXUtils.h>

extern int x86UNIXOpen(const char *path, int oflag);
extern int x86UNIXClose(int fd);
extern ssize_t x86UNIXWrite(int fd, const void *buf, size_t nbytes);
#endif

// Static class variables:
InputManager*  Input::smManager;

// smActive is not maintained under unix.  Use Input::isActive()
// instead
bool           Input::smActive = false;

// unix platform state
extern x86UNIXPlatformState * x86UNIXState;

extern AsciiData AsciiTable[NUM_KEYS];

#ifdef LOG_INPUT
S32 gInputLog = -1;
#endif 

//------------------------------------------------------------------------------
void Input::init()
{
   Con::printf( "Input Init:" );

   destroy();

#ifdef LOG_INPUT
   struct tm* newTime;
   time_t aclock;
   time( &aclock );
   newTime = localtime( &aclock );
   asctime( newTime );

   gInputLog = x86UNIXOpen("input.log", O_WRONLY | O_CREAT);
   log("Input log opened at %s\n", asctime( newTime ) );
   log("Operating System:\n" );
   log("  %s", UUtils->getOSName());
   log("\n");
#endif

   smActive = false;
   smManager = NULL;

   UInputManager *uInputManager = new UInputManager;
   if ( !uInputManager->enable() )
   {
      Con::errorf( "   Failed to enable Input Manager." );
      delete uInputManager;
      return;
   }

   uInputManager->init();

   smManager = uInputManager;

   Con::printf("   Input initialized");
   Con::printf(" ");
}

//------------------------------------------------------------------------------
ConsoleFunction( isJoystickDetected, bool, 1, 1, "isJoystickDetected()" )
{
   argc; argv;
   UInputManager* manager = dynamic_cast<UInputManager*>(Input::getManager());
   if (manager)
      return manager->joystickDetected();
   else
      return false;
}

//------------------------------------------------------------------------------
ConsoleFunction( getJoystickAxes, const char*, 2, 2, "getJoystickAxes( instance )" )
{
   argc; argv;
   UInputManager* manager = dynamic_cast<UInputManager*>(Input::getManager());
   if (manager)
      return manager->getJoystickAxesString(dAtoi(argv[1]));
   else
      return "";
}

//------------------------------------------------------------------------------

U16 Input::getKeyCode( U16 asciiCode )
{
   if ( asciiCode > 255 )
      return 0;

   U16 keyCode = 0;
   U16 i;
   
   // This is done three times so the lowerkey will always
   // be found first. Some foreign keyboards have duplicate
   // chars on some keys.
   for ( i = KEY_FIRST; i < NUM_KEYS && !keyCode; i++ )
   {
      if ( AsciiTable[i].lower.ascii == asciiCode )
      {
         keyCode = i;
         break;
      };
   }

   for ( i = KEY_FIRST; i < NUM_KEYS && !keyCode; i++ )
   {
      if ( AsciiTable[i].upper.ascii == asciiCode )
      {
         keyCode = i;
         break;
      };
   }

   for ( i = KEY_FIRST; i < NUM_KEYS && !keyCode; i++ )
   {
      if ( AsciiTable[i].goofy.ascii == asciiCode )
      {
         keyCode = i;
         break;
      };
   }

   return( keyCode );
}

//-----------------------------------------------------------------------------
//
// This function gets the standard ASCII code corresponding to our key code
// and the existing modifier key state.
//
//-----------------------------------------------------------------------------
U16 Input::getAscii( U16 keyCode, KEY_STATE keyState )
{
   if ( keyCode >= NUM_KEYS )
      return 0;

   switch ( keyState )
   {
      case STATE_LOWER:
         return AsciiTable[keyCode].lower.ascii;
      case STATE_UPPER:
         return AsciiTable[keyCode].upper.ascii;
      case STATE_GOOFY:
         return AsciiTable[keyCode].goofy.ascii;
   }

   return 0;
}

//------------------------------------------------------------------------------
void Input::destroy()
{   
#ifdef LOG_INPUT
   if ( gInputLog != -1 )
   {
      log( "*** CLOSING LOG ***\n" );
      x86UNIXClose(gInputLog);
      gInputLog = -1;
   }
#endif

   if ( smManager && smManager->isEnabled() )
   {
      smManager->disable();
      delete smManager;
      smManager = NULL;
   }
}

//------------------------------------------------------------------------------
bool Input::enable()
{   
   if ( smManager && !smManager->isEnabled() )
      return( smManager->enable() );
   
   return( false );
}

//------------------------------------------------------------------------------
void Input::disable()
{
   if ( smManager && smManager->isEnabled() )
      smManager->disable();
}

//------------------------------------------------------------------------------
void Input::activate()
{
   if ( smManager && smManager->isEnabled() && !isActive())
   {
#ifdef LOG_INPUT
      Input::log( "Activating Input...\n" );
#endif
      UInputManager* uInputManager = dynamic_cast<UInputManager*>( smManager );
      if ( uInputManager )
         uInputManager->activate();
   }
}

//------------------------------------------------------------------------------
void Input::deactivate()
{
   if ( smManager && smManager->isEnabled() && isActive() )
   {
#ifdef LOG_INPUT
      Input::log( "Deactivating Input...\n" );
#endif
      UInputManager* uInputManager = dynamic_cast<UInputManager*>( smManager );
      if ( uInputManager )
         uInputManager->deactivate();
   }
}

//------------------------------------------------------------------------------
void Input::reactivate()
{
   Input::deactivate();
   Input::activate();
}

//------------------------------------------------------------------------------
bool Input::isEnabled()
{
   if ( smManager )
      return smManager->isEnabled();
   return false;
}

//------------------------------------------------------------------------------
bool Input::isActive()
{
   UInputManager* uInputManager = dynamic_cast<UInputManager*>( smManager );
   if ( uInputManager )
      return uInputManager->isActive();
   return false;
}

//------------------------------------------------------------------------------
void Input::process()
{
   if ( smManager )
      smManager->process();
}

//------------------------------------------------------------------------------
InputManager* Input::getManager()
{
   return smManager;
}

#ifdef LOG_INPUT
//------------------------------------------------------------------------------
void Input::log( const char* format, ... )
{
   if ( gInputLog == -1)
      return;
   
   va_list argptr;
   va_start( argptr, format );

   const int BufSize = 4096;
   char buffer[BufSize];
   dVsprintf( buffer, BufSize, format, argptr );
   x86UNIXWrite(gInputLog, buffer, dStrlen( buffer ));
   va_end( argptr );
}

ConsoleFunction( inputLog, void, 2, 2, "inputLog( string )" )
{
   argc;
   Input::log( "%s\n", argv[1] );
}
#endif // LOG_INPUT

//------------------------------------------------------------------------------
void NotifySelectionEvent(XEvent& event)
{
   // somebody sent us a select event
   // if (event.type == SelectionRequest)
   //    xclipboard.handleSelectionRequest(event.xselectionrequest);
}

//------------------------------------------------------------------------------
const char* Platform::getClipboard()
{
   return SDL_HasClipboardText() ? SDL_GetClipboardText() : "";
}

//------------------------------------------------------------------------------
bool Platform::setClipboard(const char *text)
{
   if (!text)
      return false;

   SDL_SetClipboardText(text);
   return true;
}
