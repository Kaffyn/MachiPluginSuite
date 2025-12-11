#include "machi_sound_manager.h"
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void MachiSoundManager::_bind_methods() {
	ClassDB::bind_method(D_METHOD("play_cue", "cue"), &MachiSoundManager::play_cue);
}

MachiSoundManager::MachiSoundManager() {
}

MachiSoundManager::~MachiSoundManager() {
}

void MachiSoundManager::play_cue(const Ref<MachiSoundCue> &p_cue) {
    if (p_cue.is_null()) {
        UtilityFunctions::printerr("MachiSoundManager: Attempted to play null cue");
        return;
    }

    Ref<AudioStream> stream = p_cue->get_stream();
    if (stream.is_null()) {
         UtilityFunctions::printerr("MachiSoundManager: Cue has no stream");
         return;
    }

    // Basic implementation: Create a player and play. 
    // In a real production environment you would use pooling here.
    AudioStreamPlayer *player = memnew(AudioStreamPlayer);
    add_child(player);
    player->set_stream(stream);
    player->play();
    
    // Auto-free when finished (connecting strictly in C++ is verbose, usually simpler to queue_free logic on process 
    // or connect to "finished". For this snippet we'll trust the wrapper logic later or assume manual cleanup/pooling for V1)
    // Connecting signal in C++:
    player->connect("finished", Callable(player, "queue_free"));
}
