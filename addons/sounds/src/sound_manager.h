#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/audio_stream_player.hpp>
#include <godot_cpp/templates/vector.hpp>
#include "sound_cue.h"

using namespace godot;

class SoundManager : public Node {
	GDCLASS(SoundManager, Node);

private:
    // Pool
    TypedArray<AudioStreamPlayer> pool;
    int initial_pool_size = 10;

    AudioStreamPlayer *_get_available_player();

protected:
	static void _bind_methods();

public:
    SoundManager();
    ~SoundManager();

    void play_cue(const Ref<SoundCue> &p_cue);
    // play_2d_cue...
};

#endif // SOUND_MANAGER_H
