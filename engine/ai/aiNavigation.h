//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#ifndef _AINAVIGATION_H_
#define _AINAVIGATION_H_

#ifndef _SIMBASE_H_
#include "console/simBase.h"
#endif
#ifndef _SIMPATH_H_
#include "sim/simPath.h"
#endif
#ifndef _PATHMANAGER_H_
#include "sim/pathManager.h"
#endif

/**
 * Not quite Tribes 2's AI graph navmesh system or whatever...
 * But a small module to aid in pathfinding and navigation.
 * 
 * This stores the adjacency lists of the paths it registers.
 * 
 * To use this structure optimally, an initialization sequence
 * in script would have to, upon initializing a mission:
 * * Trash cache
 * * Look for mission path groups (from path manager)
 *   * add them if any
 * * Look for mission AI zones (not programmed yet)
 *   * perform rainfall initialization on them
 *   * rainfall density can be adjusted in the zone
 * * Finish mission loading
 */
class AINavigation : public SimObject
{
private:
	typedef SimObject Parent;

	// Randomizer used for this object
	MRandomLCG mRandom;

protected:
	// When path nodes are changed, we must destroy our cache...
	void trashPathCache();

public:
	AINavigation();
	~AINavigation();

	virtual bool onAdd() override;
	virtual void onRemove() override;

	// Change random seed
	void reseed(S32 seed);

	// High-level function
	void mapFloors();

	// Return available path manager
	static PathManager* getPathManager()
	{
		if (gServerPathManager)
			return gServerPathManager;
		return gClientPathManager;
	}

	// Simple pathfinding (shortest path)
	void findPath(PathNode const* node);

	// Pathfinding with respect to weights (shortest path)
	void findMinPath(PathNode const* node);

	// Perform rainfall initialization, (Penetration is whether or not we still extend the ray past intersections)
	void rainfallInit(Box3F const& area, bool penetration = true, U32 typeMask = STATIC_COLLISION_MASK, F32 density = 0.125);

	static void initPersistFields();
	DECLARE_CONOBJECT(AINavigation);
};

#endif
