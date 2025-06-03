//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#include "platform/platform.h"
#include "core/dnet.h"
#include "core/idGenerator.h"
#include "core/bitStream.h"
#include "console/simBase.h"
#include "console/console.h"
#include "console/consoleTypes.h"
#include "sim/netConnection.h"
#include "sim/netObject.h"
#include "game/gameConnection.h"
#include "game/net/serverQuery.h"

StringTableEntry gMasterAddress;

//----------------------------------------------------------------
// remote procedure call console functions
//----------------------------------------------------------------

class RemoteCommandEvent : public NetEvent
{
public:
   enum {
      MaxRemoteCommandArgs = 20,
      CommandArgsBits = 5
   };

private:
   S32 mArgc;
   ConsoleValue mArgv[MaxRemoteCommandArgs + 1];
   StringHandle mTagv[MaxRemoteCommandArgs + 1]; // is this even used beyond the constructor?????
   static char mBuf[1024]; // work buffer for string ops
public:
   RemoteCommandEvent(S32 argc=0, ConsoleValue *argv=NULL, NetConnection *conn = NULL)
   {
      mArgc = argc;
      for(S32 i = 0; i < argc; i++)
      {
         if(argv[i].isTagString())
         {
            char buffer[256];
            mTagv[i+1] = StringHandle(dAtoi(argv[i].getStringU()+1));
            if(conn)
			{
               // Turn tagged string argument into "\x01<id>"
               dSprintf(buffer + 1, sizeof(buffer) - 1, "%d", conn->getNetSendId(mTagv[i+1]));
               buffer[0] = StringTagPrefixByte;
               mArgv[i+1] = buffer;
			}
         }
         else
            mArgv[i+1] = argv[i];
      }
   }

#ifdef TORQUE_DEBUG_NET
   const char *getDebugName()
   {
      static char buffer[256];
      dSprintf(buffer, sizeof(buffer), "%s [%s]", getClassName(), gNetStringTable->lookupString(dAtoi(mArgv[1] + 1)) );
      return buffer;
   }
#endif

   ~RemoteCommandEvent()
   {
   }

   virtual void pack(NetConnection* conn, BitStream *bstream)
   {
      bstream->writeInt(mArgc, CommandArgsBits);
      // write it out reversed... why?
      // automatic string substitution with later arguments -
      // handled automatically by the system.

      for (S32 i = 0; i < mArgc; i++) {
          mArgv[i + 1].pack(1024, mBuf);
          conn->packString(bstream, mBuf);
      }
   }

   virtual void write(NetConnection* conn, BitStream *bstream)
   {
      pack(conn, bstream);
   }

   virtual void unpack(NetConnection* conn, BitStream *bstream)
   {
      mArgc = bstream->readInt(CommandArgsBits);
      // read it out backwards
      for(S32 i = 0; i < mArgc; i++)
      {
         conn->unpackString(bstream, mBuf);
         mArgv[i+1].unpack(1024, mBuf);
      }
   }

   virtual void process(NetConnection *conn)
   {
      // de-tag the command name

      for(S32 i = mArgc - 1; i >= 0; i--)
      {
         ConsoleValue arg = mArgv[i+1];
         if(arg.isTagString())
         {
            // it's a tag:
            U32 localTag = dAtoi(arg.getStringU() + 1);
            StringHandle tag = conn->translateRemoteStringId(localTag);
            NetStringTable::expandString( tag,
                                          mBuf,
                                          sizeof(mBuf),
                                          (mArgc - 1) - i,
                                          mArgv + i + 2 );
            mArgv[i+1] = mBuf;
         }
      }
      const char *rmtCommandName = dStrchr(mArgv[1].toString(), ' ') + 1;
      if(conn->isConnectionToServer())
      {
         dSprintf(mBuf, 1024, "clientCmd%s", rmtCommandName);

         ConsoleValue temp = mArgv[1];
         mArgv[1] = mBuf;

         Con::execute(mArgc, mArgv+1);
         mArgv[1] = temp;
      }
      else
      {
         dSprintf(mBuf, 1024, "serverCmd%s", rmtCommandName);
         ConsoleValue temp = mArgv[1];

         mArgv[0] = mBuf;
         mArgv[1] = (S64) conn->getId();

         Con::execute(mArgc+1, mArgv);
         mArgv[1] = temp;
      }

      // destructor should automatically clean up consolevalues.
   }

   DECLARE_CONOBJECT(RemoteCommandEvent);
};
char RemoteCommandEvent::mBuf[1024];

IMPLEMENT_CO_NETEVENT_V1(RemoteCommandEvent);

static void sendRemoteCommand(NetConnection *conn, S32 argc, ConsoleValue *argv)
{
   if(!argv[0].isTagString())
   {
      Con::errorf(ConsoleLogEntry::Script, "Remote Command Error - command must be a tag.");
      return;
   }
   S32 i;
   for(i = argc - 1; i >= 0; i--)
   {
      // if(argv[i][0] != 0)
      if(!argv[i].isNullString()) // translated to !argv[i].isNullString() since that would be the default empty value.
         break;
      argc = i;
   }
   for(i = 0; i < argc; i++)
      conn->validateSendString(argv[i].toString()); // this only validates tagged strings, don't care about other value types.
   RemoteCommandEvent *cevt = new RemoteCommandEvent(argc, argv, conn);
   conn->postNetEvent(cevt);
}

ConsoleFunctionGroupBegin( Net, "Functions for use with the network; tagged strings and remote commands.");

ConsoleFunction( commandToServer, void, 2, RemoteCommandEvent::MaxRemoteCommandArgs + 1, "(string func, ...)"
                "Send a command to the server.")
{
   NetConnection *conn = NetConnection::getConnectionToServer();
   if(!conn)
      return;
   sendRemoteCommand(conn, argc - 1, argv + 1);
}

ConsoleFunction( commandToClient, void, 3, RemoteCommandEvent::MaxRemoteCommandArgs + 2, "(NetConnection client, string func, ...)")
{
   NetConnection *conn;
   if(!Sim::findObject(argv[1], conn))
      return;
   sendRemoteCommand(conn, argc - 2, argv + 2);
}

ConsoleFunction(removeTaggedString, void, 2, 2, "(int tag)")
{
   if (argv[1].getType() == ConsoleValue::TypeInt)
      gNetStringTable->removeString(argv[1].getIntU(), true);
   else if (argv[1].getStrlen() > 0)
      gNetStringTable->removeString(dAtoi(argv[1].toString() + 1), true);
}

ConsoleFunction( addTaggedString, const char*, 2, 2, "(string str)")
{
   StringHandle s(argv[1].toString());
   gNetStringTable->incStringRefScript(s.getIndex());

   char ret[16];
   ret[0] = StringTagPrefixByte;
   dSprintf(ret + 1, 15, "%d", s.getIndex());
   return ret;
}

ConsoleFunction( getTaggedString, const char*, 2, 2, "(int tag)")
{
   const char *indexPtr = argv[1].toString();
   if (*indexPtr == StringTagPrefixByte)
      indexPtr++;
   return gNetStringTable->lookupString(dAtoi(indexPtr));
}

ConsoleFunction( buildTaggedString, const char*, 2, 11, "(string format, ...)")
{
   const char *indexPtr = argv[1].toString();
   if (*indexPtr == StringTagPrefixByte)
      indexPtr++;
   const char *fmtString = gNetStringTable->lookupString(dAtoi(indexPtr));
   char strBuffer[512];
   const char *fmtStrPtr = fmtString;
   char *strBufPtr = strBuffer;
   S32 strMaxLength = 511;
   if (!fmtString)
      goto done;

   //build the string
   while (*fmtStrPtr)
   {
      //look for an argument tag
      if (*fmtStrPtr == '%')
      {
         if (fmtStrPtr[1] >= '1' && fmtStrPtr[1] <= '9')
         {
            S32 argIndex = S32(fmtStrPtr[1] - '0') + 1;
            if (argIndex >= argc)
               goto done;
            const char *argStr = argv[argIndex].toString();
            if (!argStr)
               goto done;
            S32 strLength = dStrlen(argStr);
            if (strLength > strMaxLength)
               goto done;
            dStrcpy(strBufPtr, argStr);
            strBufPtr += strLength;
            strMaxLength -= strLength;
            fmtStrPtr += 2;
            continue;
         }
      }

      //if we don't continue, just copy the character
      if (strMaxLength <= 0)
         goto done;
      *strBufPtr++ = *fmtStrPtr++;
      strMaxLength--;
   }

done:
   *strBufPtr = '\0';
   return strBuffer;
}

ConsoleFunctionGroupEnd( Net );

void netInit()
{
   gMasterAddress = "";
   Con::addVariable( "MasterServerAddress", TypeString, &gMasterAddress );
}
