#ifndef MACHI_SOUND_MANAGER_H
#define MACHI_SOUND_MANAGER_H

#include "machi_sound_cue.h"

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/audio_stream_player.hpp>
#include <godot_cpp/classes/audio_stream_player2d.hpp>
#include <godot_cpp/classes/audio_stream_player3d.hpp>
#include <godot_cpp/templates/vector.hpp>

using namespace godot;

class MachiSoundManager : public Node {
	GDCLASS(MachiSoundManager, Node);

private:
    Vector<AudioStreamPlayer*> pool_2d; // Simplification for now, strictly speaking play_sound usually implies global or positional.
    // For this example we will implement basic play functionality.

protected:
	static void _bind_methods();

public:
	MachiSoundManager();
	~MachiSoundManager();

    // Play a sound cue. Position is optional (Vector3 for 3D, Vector2 for 2D logic usually handled by separation or different methods).
    // For this "Godot CPP" demo, we will expose a simple play_cue method.
	void play_cue(const Ref<MachiSoundCue> &p_cue); 
};

#endif // MACHI_SOUND_MANAGER_H
