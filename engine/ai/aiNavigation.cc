//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#include "ai/aiNavigation.h"
#include "sceneGraph/sceneGraph.h"
#include "sim/sceneObject.h"

IMPLEMENT_CONOBJECT(AINavigation);

void AINavigation::initPersistFields()
{

}

AINavigation::AINavigation()
{

}

AINavigation::~AINavigation()
{

}

bool AINavigation::onAdd()
{
	if (!Parent::onAdd())
		return false;

	return true;
}

void AINavigation::onRemove()
{
	Parent::onRemove();
}

void AINavigation::trashPathCache()
{

}

void AINavigation::reseed(S32 seed)
{
	mRandom.setSeed(seed);
}

void AINavigation::mapFloors()
{
	/*
	gServerContainer

	TerrainBlock* terrain = gServerSceneGraph->getCurrentTerrain();
	if (!terrain)
		return;

	*/
}

void AINavigation::rainfallInit(Box3F const& area, bool penetration, U32 typeMask, F32 raysPerUnit)
{
	/*
	* We cast rays vertically from the top of the area to the bottom.
	* Each intersection (if the type is accepted) is added as an AI node.
	* Default density (rays per unit) is 0.125 so roughly one ray every 8 units.
	*/

	if (!gServerSceneGraph)
		return;
	
	U32 rayCount = raysPerUnit * area.getVolume();

	for (U32 i = 0; i < rayCount; ++i)
	{
		F32 xPos = mRandom.randF() * area.len_x();
		F32 yPos = mRandom.randF() * area.len_y();
		F32 zOrigin = area.max.z;

		RayInfo rayInfo{};
		while (gServerContainer.castRay(Point3F(xPos, yPos, zOrigin), Point3F(xPos, yPos, area.min.z), typeMask, &rayInfo))
		{
			zOrigin = rayInfo.point.z - POINT_EPSILON;
		}
	}
}