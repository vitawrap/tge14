//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#include "game/missionArea.h"
#include "console/consoleTypes.h"
#include "core/bitStream.h"
#include "math/mathIO.h"

IMPLEMENT_CO_NETOBJECT_V1(MissionArea);

RectI MissionArea::smMissionArea(Point2I(768, 768), Point2I(512, 512));

//------------------------------------------------------------------------------

MissionArea::MissionArea()
{
   mArea.set(Point2I(768, 768), Point2I(512, 512));
   mNetFlags.set(Ghostable | ScopeAlways);

   mFlightCeiling      = 2000;
   mFlightCeilingRange = 50;
}

//------------------------------------------------------------------------------

void MissionArea::setArea(const RectI & area)
{
   // set it
   mArea = MissionArea::smMissionArea = area;

   // pass along..
   if(isServerObject())
      mNetFlags.set(UpdateMask);
}

//------------------------------------------------------------------------------

const MissionArea * MissionArea::getServerObject()
{
   SimSet * scopeAlwaysSet = Sim::getGhostAlwaysSet();
   for(SimSet::iterator itr = scopeAlwaysSet->begin(); itr != scopeAlwaysSet->end(); itr++)
   {
      MissionArea * ma = dynamic_cast<MissionArea*>(*itr);
      if(ma)
      {
         AssertFatal(ma->isServerObject(), "MissionArea::getServerObject: found client object in ghost always set!");
         return(ma);
      }
   }
   return(0);
}

//------------------------------------------------------------------------------

bool MissionArea::onAdd()
{
   if(isServerObject() && MissionArea::getServerObject())
   {
      Con::errorf(ConsoleLogEntry::General, "MissionArea::onAdd - MissionArea already instantiated!");
      return(false);
   }

   if(!Parent::onAdd())
      return(false);

   setArea(mArea);
   return(true);
}

//------------------------------------------------------------------------------

void MissionArea::initPersistFields()
{
   Parent::initPersistFields();

   addGroup("Dimensions");	
   addField("area", TypeRectI, Offset(mArea, MissionArea));
   addField("flightCeiling", TypeF32, Offset(mFlightCeiling, MissionArea));
   addField("flightCeilingRange", TypeF32, Offset(mFlightCeilingRange, MissionArea));
   endGroup("Dimensions");	
}

//------------------------------------------------------------------------------
ConsoleMethod( MissionArea, getArea, const char *, 2, 2, "()"
              "Returns 4 fields: starting x, starting y, extents x, extents y")
{
   RectI area = object->getArea();
   return ConsoleValueList::from(area.point.x, area.point.y, area.extent.x, area.extent.y);
}

ConsoleMethod( MissionArea, setArea, void, 3, 6, "(int x, int y, int width, int height)")
{
   if(object->isClientObject()) {
      Con::errorf(ConsoleLogEntry::General, "MissionArea::cSetArea - cannot alter client object!");
      return;
   }

   RectI rect;
   if (argv[2].isList())
       rect = argv[2].getPoint4F();
   else if (argc == 6) {
       rect.point.x =  argv[2].getInt();
       rect.point.y =  argv[3].getInt();
       rect.extent.x = argv[4].getInt();
       rect.extent.y = argv[5].getInt();
   } else
       Con::errorf(ConsoleLogEntry::General, "MissionArea::cSetArea - either a list or 4 arguments must be provided!");

   object->setArea(rect);
}

//------------------------------------------------------------------------------

void MissionArea::unpackUpdate(NetConnection *, BitStream * stream)
{
   // ghost (initial) and regular updates share flag..
   if(stream->readFlag())
   {
      mathRead(*stream, &mArea);
      stream->read(&mFlightCeiling);
      stream->read(&mFlightCeilingRange);
   }
}

U64 MissionArea::packUpdate(NetConnection *, U64 mask, BitStream * stream)
{
   if(stream->writeFlag(mask & UpdateMask))
   {
      mathWrite(*stream, mArea);
      stream->write(mFlightCeiling);
      stream->write(mFlightCeilingRange);
   }
   return(0);
}
