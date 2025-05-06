//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#ifndef _AUDIO_BLENDER_H_
#define _AUDIO_BLENDER_H_

#ifndef _SIMBASE_H_
#include "console/simBase.h"
#endif

#ifndef _PLATFORMAUDIO_H_
#include "platform/platformAudio.h"
#endif

/**
	Convenience object type to be used with the Tweener.
	Fade in/out a music channel, or crossfade between channels.

	Passing sources created from alxPlay technically works,
	but ideally sources from alxCreateSource(profile) should be
	passed.

	AudioBlender takes ownership of the sources that it is given.
	(alxStop is called which deallocates the sources.)
*/
class AudioBlender : public SimObject {
	typedef SimObject Parent;

	S32 mTween;
	AUDIOHANDLE mBlendSource;
	AUDIOHANDLE mBlendDestination;

	F32 mBlendValue;

public:
	void fadeOut(S32 msToZeroVolume);
	void fadeIn(AUDIOHANDLE source, S32 msToFullVolume);
	void crossFade(AUDIOHANDLE b, S32 msToComplete);

	void onStaticModified(StringTableEntry field) override;

	DECLARE_CONOBJECT(AudioBlender);
	static void initPersistFields();

	AudioBlender();
};

#endif  // _AUDIO_BLENDER_H_
