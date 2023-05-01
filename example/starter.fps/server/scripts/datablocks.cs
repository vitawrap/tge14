//-----------------------------------------------------------------------------
// Torque Game Engine 
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

datablock AudioProfile(FireIgniteSound)
{
	filename = "~/data/sound/ignite.wav";
	description = AudioDefault3d;
	preload = true;
};

datablock AudioProfile(FireExtinguishSound)
{
	filename = "~/data/sound/extinguish.wav";
	description = AudioDefault3d;
	preload = true;
};

// Test
datablock fxLightData (TestLight)
{
	Colour = "1 0 0 1";
	Radius = 30;

	animColour = true;
	singleColourKeys = false;
	redKeys = "AZA";
	greenKeys = "FCF";
	blueKeys = "ZAZ";
	colourTime = 1;

	animRadius = true;
	minRadius = 2;
	maxRadius = 40;
	radiusKeys = "AZA";
	radiusTime = 1/2;
};

datablock fxBeamData (smokeBeam)
{
	texture = "~/data/fx/beam.png";
	color = "0 0.3 1";
	isFinite = false;
	width = 3;
	height = 30;
	texStretch = 5;
	scrollSec = 5;
	glow = true;
};

datablock RotatingDoorData(BaseDoorData) {
    shapeFile = "~/data/shapes/maps/pushdoor.dts";

    // Transform
    rotationOrigin = "0 0 0";
    rotationAngleAxis = "3.1415 0 0 1";

    // Sounds
    //toggleSound = ButtonDownSound;
    //movingSound = VehicleRollSound;
    //closedSound = MonitorImpactSound;
    //openedSound = MonitorImpactSound;
    //haltedSound = MonitorImpactSound;

    // Settings
    openTwoWays = false;
    msBeforeMoving = 0;
    msRotationTime = 1000;

    // Collisions
    blockOnCollision = false;
    collisionIgnoreMask = 0;
    collisionParticles = "";
    spawnParticlesOnCollision = false;
};

//$tdoor = new RotatingDoor("testDoor"){ datablock = BaseDoorData; position = localclientconnection.player.getTransform(); }; MissionGroup.add($tdoor);
