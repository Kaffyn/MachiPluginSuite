#include "machi_audio_3d.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void MachiAudio3D::_bind_methods() {
    ClassDB::bind_method(D_METHOD("play_cue", "cue"), &MachiAudio3D::play_cue);
}

MachiAudio3D::MachiAudio3D() {
}

MachiAudio3D::~MachiAudio3D() {
}

void MachiAudio3D::play_cue(const Ref<SoundCue> &p_cue) {
    if (p_cue.is_null()) {
        UtilityFunctions::push_warning("MachiAudio3D: Attempted to play null SoundCue.");
        return;
    }
    
    Ref<AudioStream> stream = p_cue->get_next_stream();
    if (stream.is_null()) {
        return; // No stream to play
    }
    
    set_stream(stream);
    set_pitch_scale(p_cue->get_next_pitch());
    set_volume_db(p_cue->get_next_volume());
    
    play();
}
