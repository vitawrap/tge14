//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#include "sim/sceneObject.h"
#include "core/fileStream.h"

void RegisterGameFunctions();

// query
SimpleQueryList gServerQueryList;
U32 gServerQueryIndex = 0;

//SERVER FUNCTIONS ONLY
ConsoleFunctionGroupBegin( Containers, "Spatial query functions. <b>Server side only!</b>");

ConsoleFunction(containerFindFirst, S32, 6, 6, "(bitset type, Point3F point, float x, float y, float z)"
                "Find objects matching the bitmask type within a box centered at point, with extents x, y, z.\n\n"
                "Returns the first object found; thereafter, you can get more results using containerFindNext().")
{
   //find out what we're looking for
   U32 typeMask = argv[1].getInt();

   //find the center of the container volume
   Point3F origin = argv[2].getPoint3F();
   //dSscanf(argv[2], "%g %g %g", &origin.x, &origin.y, &origin.z);

   //find the box dimensions
   Point3F size(0, 0, 0);
   size.x = mFabs(argv[3].getNumber());
   size.y = mFabs(argv[4].getNumber());
   size.z = mFabs(argv[5].getNumber());

   //build the container volume
   Box3F queryBox;
   queryBox.min = origin;
   queryBox.max = origin;
   queryBox.min -= size;
   queryBox.max += size;

   //initialize the list, and do the query
   gServerQueryList.mList.clear();
   gServerContainer.findObjects(queryBox, typeMask, SimpleQueryList::insertionCallback, &gServerQueryList);

   //return the first element
   gServerQueryIndex = 0;
   if (gServerQueryList.mList.size())
      return (S64) gServerQueryList.mList[gServerQueryIndex++]->getId();
   return 0LL;
}

ConsoleFunction( containerFindNext, S32, 1, 1, "Get more results from a previous call to containerFindFirst().")
{
   //return the next element
   if (gServerQueryIndex < gServerQueryList.mList.size())
      return (S64) gServerQueryList.mList[gServerQueryIndex++]->getId();
   return 0LL;
}

ConsoleFunctionGroupEnd( Containers );
