//-----------------------------------------------------------------------------
// Torque Game Engine 
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

// Load dts shapes and merge animations
datablock TSShapeConstructor(PlayerDts)
{
   baseShape = "~/data/shapes/player/player.dts";
   sequence[0] = "~/data/shapes/player/player_root.dsq root";
   sequence[1] = "~/data/shapes/player/player_forward.dsq run";
   sequence[2] = "~/data/shapes/player/player_back.dsq back";
   sequence[3] = "~/data/shapes/player/player_side.dsq side";
   sequence[4] = "~/data/shapes/player/player_fall.dsq fall";
   sequence[5] = "~/data/shapes/player/player_land.dsq land";
   sequence[6] = "~/data/shapes/player/player_jump.dsq jump";
   sequence[7] = "~/data/shapes/player/player_standjump.dsq standjump";
   sequence[8] = "~/data/shapes/player/player_lookde.dsq look";
   sequence[9] = "~/data/shapes/player/player_head.dsq head";
   sequence[10] = "~/data/shapes/player/player_headside.dsq headside";
   sequence[11] = "~/data/shapes/player/player_celwave.dsq celwave";
};

datablock PlayerData(PlayerShape)
{
   renderFirstPerson = false;
   shapeFile = "~/data/shapes/player/player.dts";
};


//----------------------------------------------------------------------------
// PlayerShape Datablock methods
//----------------------------------------------------------------------------

function PlayerShape::onAdd(%this,%obj)
{
   // Called when the PlayerData datablock is first 'read' by the engine (executable)
}

function PlayerShape::onRemove(%this, %obj)
{
   if (%obj.client.player == %obj)
      %obj.client.player = 0;
}

function PlayerShape::onNewDataBlock(%this,%obj)
{
   // Called when this PlayerData datablock is assigned to an object
}
