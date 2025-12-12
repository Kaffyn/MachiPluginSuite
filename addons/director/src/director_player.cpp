#include "director_player.h"

using namespace godot;

void DirectorPlayer::_bind_methods() {
    ClassDB::bind_method(D_METHOD("play", "sequence"), &DirectorPlayer::play);
    ClassDB::bind_method(D_METHOD("stop"), &DirectorPlayer::stop);
    ClassDB::bind_method(D_METHOD("is_playing"), &DirectorPlayer::is_playing);
}

DirectorPlayer::DirectorPlayer() {
}

DirectorPlayer::~DirectorPlayer() {
}

void DirectorPlayer::play(Ref<Resource> p_sequence) {
    if (p_sequence.is_valid()) {
        playing = true;
        // Logic to start sequence
    }
}

void DirectorPlayer::stop() {
    playing = false;
}

bool DirectorPlayer::is_playing() const {
    return playing;
}
