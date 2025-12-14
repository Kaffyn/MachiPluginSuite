#ifndef MACHI_AUDIO_2D_H
#define MACHI_AUDIO_2D_H

#include <godot_cpp/classes/audio_stream_player2d.hpp>
#include "sound_cue.h"

using namespace godot;

class MachiAudio2D : public AudioStreamPlayer2D {
	GDCLASS(MachiAudio2D, AudioStreamPlayer2D);

protected:
	static void _bind_methods();

public:
	MachiAudio2D();
	~MachiAudio2D();

    void play_cue(const Ref<SoundCue> &p_cue);
};

#endif // MACHI_AUDIO_2D_H
