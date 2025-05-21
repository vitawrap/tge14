//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#include "console/consoleTypes.h"
#include "platform/platform.h"
#include "core/tweener.h"
#include "audioBlender.h"

IMPLEMENT_CONOBJECT(AudioBlender);

F32 AudioBlender::sQuietVolume = .32f;

//-----------------------------------------------------------------------------

void AudioBlender::fadeIn(AUDIOHANDLE source, S32 msToFullVolume)
{
	if (!alxIsValidHandle(source)) {
		Con::errorf("Audio handle %u is not a valid AL source.", source);
		return;
	}

	if (mBlendDestination != AL_NONE) {
		if (alxIsValidHandle(mBlendDestination))
			alxStop(mBlendDestination);
	}
	mBlendDestination = source;
	mBlendValue = 0.f;

	if (mTween)
		TweenerBase::removeTween(mTween);

	TweenerBase* t = TweenerBase::create(this, "blendValue", "1.0", msToFullVolume);
	mTween = t? TweenerBase::pushLiveTween(t) : 0;
}

void AudioBlender::fadeOut(S32 msToZeroVolume)
{
	if (mBlendSource != AL_NONE) {
		if (alxIsValidHandle(mBlendSource))
			alxStop(mBlendSource);
		mBlendSource = AL_NONE;
	}
	mBlendSource = mBlendDestination;
	mBlendDestination = AL_NONE;
	mBlendValue = 0.f;

	if (mTween)
		TweenerBase::removeTween(mTween);

	TweenerBase* t = TweenerBase::create(this, "blendValue", "1.0", msToZeroVolume);
	mTween = t ? TweenerBase::pushLiveTween(t) : 0;
}

void AudioBlender::crossFade(AUDIOHANDLE b, S32 msToComplete)
{
	if (!alxIsValidHandle(b)) {
		Con::errorf("Audio handle %u is not a valid AL source.", b);
		return;
	}

	if (mBlendSource != AL_NONE) {
		if (alxIsValidHandle(mBlendSource))
			alxStop(mBlendSource);
		mBlendSource = AL_NONE;
	}
	mBlendSource = mBlendDestination;
	mBlendDestination = b;
	mBlendValue = 0.f;

	if (mTween)
		TweenerBase::removeTween(mTween);

	TweenerBase* t = TweenerBase::create(this, "blendValue", "1.0", msToComplete);
	mTween = t ? TweenerBase::pushLiveTween(t) : 0;
}

void AudioBlender::quieten(S32 msToQuiet)
{
	if (mQuietTween)
		TweenerBase::removeTween(mQuietTween);

	char quietVol[128];
	dSprintf(quietVol, sizeof(quietVol), "%g", sQuietVolume);
	TweenerBase* t = TweenerBase::create(this, "quietValue", quietVol, msToQuiet);
	mQuietTween = t ? TweenerBase::pushLiveTween(t) : 0;
}

void AudioBlender::louden(S32 msToLoud)
{
	if (mQuietTween)
		TweenerBase::removeTween(mQuietTween);

	TweenerBase* t = TweenerBase::create(this, "quietValue", "1.0", msToLoud);
	mQuietTween = t ? TweenerBase::pushLiveTween(t) : 0;
}

AudioBlender::AudioBlender()
	: SimObject()
{
	mBlendSource = AL_NONE;
	mBlendDestination = AL_NONE;
	mBlendValue = 0.f;
	mTween = 0;
	mQuietValue = 1.f;
	mQuietTween = 0;
}

void AudioBlender::onStaticModified(StringTableEntry field)
{
	F32 vol = mQuietValue;

	// callback for tween
	if (field == StringTable->insert("blendValue")) {
		if (mBlendSource != AL_NONE) {
			alxSourcef(mBlendSource, AL_GAIN_LINEAR, (1.f - mBlendValue) * vol);

			if (mBlendValue >= 1.f) {
				alxSourcef(mBlendSource, AL_GAIN_LINEAR, 0.f);
				alxStop(mBlendSource);
				mBlendSource = AL_NONE;
			}
		}
		if (mBlendDestination != AL_NONE) {
			alxSourcef(mBlendDestination, AL_GAIN_LINEAR, mBlendValue * vol);

			if (!alxIsPlaying(mBlendDestination))
				alxPlay(mBlendDestination);
		}
	}

	else if (field == StringTable->insert("quietValue")) {
		if (mBlendSource != AL_NONE)
			alxSourcef(mBlendSource, AL_GAIN_LINEAR, (1.f - mBlendValue) * vol);
		if (mBlendDestination != AL_NONE)
			alxSourcef(mBlendDestination, AL_GAIN_LINEAR, mBlendValue * vol); 
	}
}

void AudioBlender::initPersistFields() {
	Parent::initPersistFields();

	addGroup("Crossfade");
	addField("blendSource", TypeS32, Offset(mBlendSource, AudioBlender));
	addField("blendDest", TypeS32, Offset(mBlendDestination, AudioBlender));
	endGroup("Crossfade");

	// Somewhat of a hack to use this from the tweener.
	addGroup("Tweenable");
	addField("blendValue", TypeF32, Offset(mBlendValue, AudioBlender));
	addField("quietValue", TypeF32, Offset(mQuietValue, AudioBlender));
	endGroup("Tweenable");

	// Also register this global variable.
	Con::addVariable("AudioBlender::QuietVolume", TypeF32, &AudioBlender::sQuietVolume);
}

ConsoleMethod(AudioBlender, fadeIn, void, 4, 4, "(AUDIOHANDLE source, S32 ms) - Fade source in")
{
	object->fadeIn(argv[2].getInt(), argv[3].getInt());
}

ConsoleMethod(AudioBlender, fadeOut, void, 3, 3, "(S32 ms) - Fade source (from fadeIn) out")
{
	object->fadeOut(argv[2].getInt());
}

ConsoleMethod(AudioBlender, crossFade, void, 4, 4, "(AUDIOHANDLE b, S32 ms) - Fade source out")
{
	object->crossFade(argv[2].getInt(), argv[3].getInt());
}

ConsoleMethod(AudioBlender, quieten, void, 2, 3, "(S32 ms = 500) - Lower tracks to $AudioBlender::QuietVolume")
{
	object->quieten(argc == 2? 500: argv[2].getInt());
}

ConsoleMethod(AudioBlender, louden, void, 2, 3, "(S32 ms = 1000)")
{
	object->louden(argc == 2? 1000 : argv[2].getInt());
}
