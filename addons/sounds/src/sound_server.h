#ifndef SOUND_SERVER_H
#define SOUND_SERVER_H

#include <godot_cpp/classes/audio_server.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/ref.hpp> 

using namespace godot;

// SoundServer acts as a singleton for global audio logic.
// Extending Object to be a Singleton.
class SoundServer : public Object {
	GDCLASS(SoundServer, Object);

private:
	static SoundServer *singleton;

protected:
	static void _bind_methods();

public:
	static SoundServer *get_singleton();

	SoundServer();
	~SoundServer();
    
    // Core methods to manage buses, etc. 
    // Usually AudioServer handles buses. SoundServer orchestrates Cues.
    
    void play_global_cue(const Ref<Resource> &p_cue); // Forward to SoundManager?
};

#endif // SOUND_SERVER_H
