//-----------------------------------------------------------------------------
// Torque Game Engine 
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Required particle stuff
//-----------------------------------------------------------------------------

datablock ParticleEmitterNodeData(DefaultEmitterNode)
{
   timeMultiple = 1;
};

//-----------------------------------------------------------------------------
// Generated game particles
//-----------------------------------------------------------------------------

datablock ParticleData(SingularityParticle) {
   dragCoefficient = "1";
   windCoefficient = "0";
   gravityCoefficient = "0";
   inheritedVelFactor = "1.5";
   constantAcceleration = "-5";
   lifetimeMS = "630";
   lifetimeVarianceMS = "0";
   spinSpeed = "0";
   spinRandomMin = "-2";
   spinRandomMax = "0";
   useInvAlpha = "0";
   animateTexture = "0";
   framesPerSec = "1";
   textureName = "~/data/fx/streak";
   colors[0] = "0 0 0 0";
   colors[1] = "0 0 0 0";
   colors[2] = "0.7 0.2 0 1";
   colors[3] = "1 0.5 0 1";
   sizes[0] = "0";
   sizes[1] = "0";
   sizes[2] = "0.1";
   sizes[3] = "4.89";
   times[0] = "0";
   times[1] = "0.24";
   times[2] = "0.38";
   times[3] = "1";
};

datablock ParticleEmitterData(SingularityEmitter) {
   className = "ParticleEmitterData";
   ejectionPeriodMS = "10";
   periodVarianceMS = "0";
   ejectionVelocity = "20";
   velocityVariance = "0";
   ejectionOffset = "6";
   thetaMin = "0";
   thetaMax = "180";
   phiReferenceVel = "0";
   phiVariance = "360";
   overrideAdvance = "1";
   orientParticles = "1";
   orientOnVelocity = "1";
   particles = "SingularityParticle";
   lifetimeMS = "0";
   lifetimeVarianceMS = "0";
   useEmitterSizes = "0";
   useEmitterColors = "0";
};


datablock ParticleData(FireSmokeParticle) {
   dragCoefficient = "0.99218";
   windCoefficient = "1.24";
   gravityCoefficient = "-1";
   inheritedVelFactor = "0.0978474";
   constantAcceleration = "0.5";
   lifetimeMS = "1726";
   lifetimeVarianceMS = "224";
   spinSpeed = "0";
   spinRandomMin = "-35";
   spinRandomMax = "35";
   useInvAlpha = "1";
   animateTexture = "0";
   framesPerSec = "1";
   textureName = "~/data/fx/smoke";
   animTexName[0] = "~/data/fx/smoke";
   colors[0] = "0 0 0 0";
   colors[1] = "0.393701 0.0944882 0 0.0944882";
   colors[2] = "0.0944882 0.0944882 0.0944882 0.393701";
   colors[3] = "0.181102 0.181102 0.299213 0";
   sizes[0] = "0.3";
   sizes[1] = "1.2";
   sizes[2] = "1.8";
   sizes[3] = "1";
   times[0] = "0";
   times[1] = "0.5";
   times[2] = "0.8";
   times[3] = "1";
};

datablock ParticleData(FireFlameParticle) {
   dragCoefficient = "0.83089";
   windCoefficient = "1";
   gravityCoefficient = "-1";
   inheritedVelFactor = "0.12";
   constantAcceleration = "-1.9";
   lifetimeMS = "928";
   lifetimeVarianceMS = "0";
   spinSpeed = "0.07";
   spinRandomMin = "0";
   spinRandomMax = "80";
   useInvAlpha = "0";
   animateTexture = "0";
   framesPerSec = "0";
   textureName = "~/data/fx/fire";
   animTexName[0] = "~/data/fx/fire";
   colors[0] = "0.393701 0.181102 0 0";
   colors[1] = "1 0.677165 0.582677 0.582677";
   colors[2] = "1 0.496063 0.299213 1";
   colors[3] = "1 0.0944882 0.299213 0";
   sizes[0] = "1";
   sizes[1] = "1.43";
   sizes[2] = "0.22";
   sizes[3] = "0.18";
   times[0] = "0";
   times[1] = "0.54";
   times[2] = "0.77";
   times[3] = "1";
};

datablock ParticleEmitterData(FireEmitter) {
   className = "ParticleEmitterData";
   ejectionPeriodMS = "20";
   periodVarianceMS = "10";
   ejectionVelocity = "1.19";
   velocityVariance = "1.18";
   ejectionOffset = "0.3";
   thetaMin = "0";
   thetaMax = "90";
   phiReferenceVel = "0";
   phiVariance = "360";
   overrideAdvance = "1";
   orientParticles = "1";
   orientOnVelocity = "1";
   particles = "FireFlameParticle\tFireSmokeParticle";
   lifetimeMS = "0";
   lifetimeVarianceMS = "0";
   useEmitterSizes = "0";
   useEmitterColors = "0";
};

datablock ParticleEmitterData(SmokeEmitter) {
   className = "ParticleEmitterData";
   ejectionPeriodMS = "20";
   periodVarianceMS = "10";
   ejectionVelocity = "1.19";
   velocityVariance = "1.18";
   ejectionOffset = "0.3";
   thetaMin = "0";
   thetaMax = "30";
   phiReferenceVel = "0";
   phiVariance = "360";
   overrideAdvance = "1";
   orientParticles = "1";
   orientOnVelocity = "1";
   particles = "FireSmokeParticle";
   lifetimeMS = "0";
   lifetimeVarianceMS = "0";
   useEmitterSizes = "0";
   useEmitterColors = "0";
};

datablock ShapeBaseImageData(FireShapeImage)
{
   shapeFile = "~/data/shapes/empty.dts";
   emap = false;

   lightType = "ConstantLight";
   lightRadius = 10;
   lightColor = "1 0.496063 0.299213 1";
   lightTime = 10000;

   stateName[0] = "Activate";
      stateTransitionOnTimeout[0] = "Ready";
      stateTransitionOnNotWet[0] = "Ready";
      stateSound[0] = FireIgniteSound;

   stateName[1] = "Ready";
      stateEmitter[1] = FireEmitter;
      stateEmitterTime[1] = 0.3;
      stateTimeoutValue[1] = 0.2;
      stateWaitForTimeout[1] = false;
      stateTransitionOnTimeout[1] = "Activate";
      stateTransitionOnWet[1] = "Extinguish";

   stateName[2] = "Extinguish";
      stateEmitter[2] = SmokeEmitter;
      stateEmitterTime[2] = 10000;
      stateSound[2] = FireExtinguishSound;
};