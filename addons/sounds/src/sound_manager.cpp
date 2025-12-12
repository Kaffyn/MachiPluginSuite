#include "sound_manager.h"

void MachiSoundManager::_bind_methods() {
	ClassDB::bind_method(D_METHOD("play_cue", "cue"), &MachiSoundManager::play_cue);
}

MachiSoundManager::MachiSoundManager() {
}

MachiSoundManager::~MachiSoundManager() {
}

AudioStreamPlayer *MachiSoundManager::_get_available_player() {
    for (int i = 0; i < pool.size(); ++i) {
        AudioStreamPlayer *player = Object::cast_to<AudioStreamPlayer>(pool[i]);
        if (player && !player->is_playing()) {
            return player;
        }
    }
    // Expand pool
    AudioStreamPlayer *new_player = memnew(AudioStreamPlayer);
    add_child(new_player);
    pool.append(new_player);
    return new_player;
}

void MachiSoundManager::play_cue(const Ref<SoundCue> &p_cue) {
    if (p_cue.is_null()) return;
    
    AudioStreamPlayer *player = _get_available_player();
    if (player) {
         player->set_stream(p_cue->get_next_stream());
         player->set_pitch_scale(p_cue->get_next_pitch());
         player->set_volume_db(p_cue->get_next_volume());
         player->play();
    }
}
