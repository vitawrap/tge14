//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#ifndef _AINAVIGATION_H_
#define _AINAVIGATION_H_

#ifndef _SIMBASE_H_
#include "console/simBase.h"
#endif

/**
 * Not quite Tribes 2's AI graph navmesh system or whatever...
 * But a small module to aid in pathfinding and navigation.
 */
class AINavigation : public SimObject
{
private:
	typedef SimObject Parent;

protected:

public:
	AINavigation();
	~AINavigation();

	virtual bool onAdd() override;
	virtual void onRemove() override;

	// High-level function
	void mapFloors();

	static void initPersistFields();
	DECLARE_CONOBJECT(AINavigation);
};

#endif
