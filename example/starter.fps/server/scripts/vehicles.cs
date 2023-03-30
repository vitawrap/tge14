datablock AudioProfile(CrashSlowSound)
{
   fileName = "~/data/sound/veh_hardimpact.wav";
   description = AudioClose3d;
   preload = true;
};

datablock AudioProfile(CrashFastSound)
{
   fileName = "~/data/sound/veh_fastimpact.wav";
   description = AudioDefault3d;
   preload = true;
};

datablock AudioProfile(VehicleRollSound)
{
   fileName = "~/data/sound/veh_loop.wav";
   description = AudioCloseLooping3d;
   preload = true;
};

datablock WheeledVehicleSpring(BaseSpring)
{
   // Wheel suspension properties
   length = 0.45;			 // Suspension travel
   force = 6000; //3000;		 // Spring force
   damping = 800; //600;		 // Spring damping
   antiSwayForce = 2; //3;		 // Lateral anti-sway force
};

datablock WheeledVehicleTire(BaseTire)
{
   // Tires act as springs and generate lateral and longitudinal
   // forces to move the vehicle. These distortion/spring forces
   // are what convert wheel angular velocity into forces that
   // act on the rigid body.
	shapeFile = "~/data/shapes/vehicles/wheel.dts";
	
	mass = 10;
    radius = 1;
    staticFriction = 0.6;	// Slide off hills
	kineticFriction = 2;	// Reasonably stop sliding away
	restitution = 0.5;	

	// Spring that generates lateral tire forces
	lateralForce = 6000;
	lateralDamping = 4000;
	lateralRelaxation = 0.01;

	// Spring that generates longitudinal tire forces
	longitudinalForce = 14000;
	longitudinalDamping = 2000;
	longitudinalRelaxation = 0.01;
};

datablock WheeledVehicleData(BaseVehicle)
{
	category = "Vehicles";
	displayName = " ";
	shapeFile = "~/data/shapes/vehicles/veh_cadlike.dts";
	emap = true;
	minMountDist = 3;
   
	numMountPoints = 2;
	mountPose[0] = "driving";
	mountPose[1] = "sitting";

	// scripts
	fireMountPoint = 4;

	maxDamage = 200.00;
	destroyedLevel = 200.00;
	speedDamageScale = 1.04;
	collDamageThresholdVel = 20.0;
	collDamageMultiplier   = 0.02;

	massCenter = "0 0 0";
	//massBox = "2 5 1";

	maxSteeringAngle = 0.9785;  // Maximum steering angle, should match animation
	integration = 4;           // Force integration time: TickSec/Rate

	// 3rd person camera settings
	cameraRoll = false;         // Roll the camera with the vehicle
	cameraMaxDist = 7;         // Far distance from vehicle
	cameraOffset = 1;        // Vertical offset from camera mount point
	cameraLag = 0.1;           // Velocity lag of camera
	cameraDecay = 0.75;        // Decay per sec. rate of velocity lag
	cameraTilt = 0.4;
	collisionTol = 0.1;        // Collision distance tolerance
	contactTol = 0.1;

	useEyePoint = false;	

	defaultTire	= BaseTire;
	defaultSpring	= BaseSpring;
	//flatTire	= BaseFlatTire;
	//flatSpring	= BaseFlatSpring;

	numWheels = 4;

	// Rigid Body
	mass = 300;
	density = 0.9;
	drag = 1.6;
	bodyFriction = 0.6;
	bodyRestitution = 0.6;
	minImpactSpeed = 10;        // Impacts over this invoke the script callback
	softImpactSpeed = 10;       // Play SoftImpact Sound
	hardImpactSpeed = 30;      // Play HardImpact Sound
	groundImpactMinSpeed    = 10.0;

	// Engine
	engineTorque = 2000; //4000;       // Engine power
	engineBrake = 2000;         // Braking when throttle is 0
	brakeTorque = 25000;        // When brakes are applied
	maxWheelSpeed = 60;        // Engine scale by current speed / max speed

	rollForce		= 900;
	yawForce		= 600;
	pitchForce		= 1000;
	rotationalDrag		= 0.2;

	// Advanced Steering
	steeringAutoReturn = true;
	steeringAutoReturnRate = 0.9;
	steeringAutoReturnMaxSpeed = 10;
	steeringUseStrafeSteering = true;
	steeringStrafeSteeringRate = 0.1;

	// Energy
	maxEnergy = 100;
	jetForce = 3000;
	minJetEnergy = 30;
	jetEnergyDrain = 2;

	splash = vehicleSplash;
	splashVelocity = 4.0;
	splashAngle = 67.0;
	splashFreqMod = 300.0;
	splashVelEpsilon = 0.60;
	bubbleEmitTime = 1.4;
	//splashEmitter[0] = vehicleFoamDropletsEmitter;
	//splashEmitter[1] = vehicleFoamEmitter;
	//splashEmitter[2] = vehicleBubbleEmitter;
	mediumSplashSoundVelocity = 10.0;   
	hardSplashSoundVelocity = 20.0;   
	exitSplashSoundVelocity = 5.0;
		
	//mediumSplashSound = "";
	//hardSplashSound = "";
	//exitSplashSound = "";
	
	// Sounds
	jetSound = VehicleRollSound;
	engineSound = VehicleRollSound;
	//squealSound = CrashSquealSound;
	softImpactSound = CrashSlowSound;
	hardImpactSound = CrashFastSound;
	//wheelImpactSound = TireLandSound;

	//   explosion = VehicleExplosion;
	justcollided = 0;
	
	rideable = true;
		lookUpLimit = 0.65;
		lookDownLimit = 0.45;

	numDmgEmitterAreas = 1;

	initialExplosionOffset = 0;         //offset only uses a z value for now

	burnTime = 4000;

	finalExplosionOffset = 0.5;          //offset only uses a z value for now

	minRunOverSpeed    = 4;   //how fast you need to be going to run someone over (do damage)
	runOverDamageScale = 8;   //when you run over someone, speed * runoverdamagescale = damage amt
	runOverPushScale   = 1.2; //how hard a person you're running over gets pushed

	//protection for passengers
	protectPassengersBurn   = false;  //protect passengers from the burning effect of explosions?
	protectPassengersRadius = true;  //protect passengers from radius damage (explosions) ?
	protectPassengersDirect = false; //protect passengers from direct damage (bullets) ?
};

//-----------------------------------------------------------------------------

function WheeledVehicleData::create(%block)
{
   %obj = new WheeledVehicle() {
      dataBlock = %block;
   };
   return(%obj);
}

//-----------------------------------------------------------------------------

function WheeledVehicleData::onAdd(%this,%obj)
{
   // Setup the car with some defaults tires & springs
   for (%i = %obj.getWheelCount() - 1; %i >= 0; %i--) {
      %obj.setWheelTire(%i,%obj.getDatablock().defaultTire);
      %obj.setWheelSpring(%i,%obj.getDatablock().defaultSpring);
      %obj.setWheelPowered(%i,false);
   }
   
   // Steer front tires
   %obj.setWheelSteering(0,1);
   %obj.setWheelSteering(1,1);

   // Only power the two rear wheels...
   %obj.setWheelPowered(2,true);
   %obj.setWheelPowered(3,true);
}

function WheeledVehicleData::onCollision(%this,%obj,%col,%vec,%speed)
{
   // Collision with other objects, including items
}

function WheeledVehicleData::onEnterLiquid(%this,%obj,%coverage,%type)
{
	%obj.setDamageDt(0.2, $damageType);
}

function WheeledVehicleData::onLeaveLiquid(%this,%obj,%type)
{
	%obj.clearDamageDt();
}

function WheeledVehicleData::damage(%this, %obj, %position, %source, %amount, %damageType)
{
	%obj.applyDamage(%amount);
}

function WheeledVehicle::setDamageDt(%this, %damageAmount, %damageType)
{
   // This function is used to apply damage over time.  The damage
   // is applied at a fixed rate (50 ms).  Damage could be applied
   // over time using the built in ShapBase C++ repair functions
   // (using a neg. repair), but this has the advantage of going
   // through the normal script channels.
   if (%this.getDamagePercent() < 1) {
      %this.damage(0, "0 0 0", %damageAmount, %damageType);
      %this.damageSchedule = %this.schedule(50, "setDamageDt", %damageAmount, %damageType);
   }
   else
      %this.damageSchedule = "";
}