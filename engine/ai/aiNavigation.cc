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

void AINavigation::mapFloors()
{
	/*
	gServerContainer

	TerrainBlock* terrain = gServerSceneGraph->getCurrentTerrain();
	if (!terrain)
		return;

	*/
}