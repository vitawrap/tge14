
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
