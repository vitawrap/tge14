//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#include "console/consoleTypes.h"
#include "platform/platform.h"
#include "core/tweener.h"
#include "audioBlender.h"

IMPLEMENT_CONOBJECT(AudioBlender);

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

AudioBlender::AudioBlender()
	: SimObject()
{
	mBlendSource = AL_NONE;
	mBlendDestination = AL_NONE;
	mBlendValue = 0.f;
	mTween = 0;
}

void AudioBlender::onStaticModified(StringTableEntry field)
{
	// callback for tween
	if (field == StringTable->insert("blendValue")) {
		if (mBlendSource != AL_NONE) {
			alxSourcef(mBlendSource, AL_GAIN_LINEAR, 1.f - mBlendValue);

			if (mBlendValue >= 1.f) {
				alxSourcef(mBlendSource, AL_GAIN_LINEAR, 0.f);
				alxStop(mBlendSource);
			}
		}
		if (mBlendDestination != AL_NONE) {
			alxSourcef(mBlendDestination, AL_GAIN_LINEAR, mBlendValue);

			if (!alxIsPlaying(mBlendDestination))
				alxPlay(mBlendDestination);
		}
	}
}

void AudioBlender::initPersistFields() {
	Parent::initPersistFields();

	addGroup("Crossfade");
	addField("blendSource", TypeS32, Offset(mBlendSource, AudioBlender));
	addField("blendDest", TypeS32, Offset(mBlendDestination, AudioBlender));
	endGroup("Crossfade");

	// Somewhat of a hack to use this from the tweener.
	addField("blendValue", TypeF32, Offset(mBlendValue, AudioBlender));
}

ConsoleMethod(AudioBlender, fadeIn, void, 4, 4, "(AUDIOHANDLE source, S32 ms) - Fade source in")
{
	object->fadeIn(dAtoi(argv[2]), dAtoi(argv[3]));
}

ConsoleMethod(AudioBlender, fadeOut, void, 3, 3, "(S32 ms) - Fade source (from fadeIn) out")
{
	object->fadeOut(dAtoi(argv[2]));
}

ConsoleMethod(AudioBlender, crossFade, void, 4, 4, "AUDIOHANDLE b, S32 ms) - Fade source out")
{
	object->crossFade(dAtoi(argv[2]), dAtoi(argv[3]));
}
