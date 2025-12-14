#ifndef MACHI_AUDIO_3D_H
#define MACHI_AUDIO_3D_H

#include <godot_cpp/classes/audio_stream_player3d.hpp>
#include "sound_cue.h"

using namespace godot;

class MachiAudio3D : public AudioStreamPlayer3D {
	GDCLASS(MachiAudio3D, AudioStreamPlayer3D);

protected:
	static void _bind_methods();

public:
	MachiAudio3D();
	~MachiAudio3D();

    void play_cue(const Ref<SoundCue> &p_cue);
};

#endif // MACHI_AUDIO_3D_H
