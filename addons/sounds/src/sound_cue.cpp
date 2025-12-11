#include "sound_cue.h"
#include <godot_cpp/variant/utility_functions.hpp>

void SoundCue::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_audio_streams", "audio_streams"), &SoundCue::set_audio_streams);
	ClassDB::bind_method(D_METHOD("get_audio_streams"), &SoundCue::get_audio_streams);
	ClassDB::bind_method(D_METHOD("set_pitch_min", "pitch_min"), &SoundCue::set_pitch_min);
	ClassDB::bind_method(D_METHOD("get_pitch_min"), &SoundCue::get_pitch_min);
	ClassDB::bind_method(D_METHOD("set_pitch_max", "pitch_max"), &SoundCue::set_pitch_max);
	ClassDB::bind_method(D_METHOD("get_pitch_max"), &SoundCue::get_pitch_max);
	ClassDB::bind_method(D_METHOD("set_volume_min_db", "volume_min_db"), &SoundCue::set_volume_min_db);
	ClassDB::bind_method(D_METHOD("get_volume_min_db"), &SoundCue::get_volume_min_db);
	ClassDB::bind_method(D_METHOD("set_volume_max_db", "volume_max_db"), &SoundCue::set_volume_max_db);
	ClassDB::bind_method(D_METHOD("get_volume_max_db"), &SoundCue::get_volume_max_db);
    ClassDB::bind_method(D_METHOD("set_is_sequence", "is_sequence"), &SoundCue::set_is_sequence);
	ClassDB::bind_method(D_METHOD("get_is_sequence"), &SoundCue::get_is_sequence);

	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "audio_streams", PROPERTY_HINT_RESOURCE_TYPE, "AudioStream"), "set_audio_streams", "get_audio_streams");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "pitch_min"), "set_pitch_min", "get_pitch_min");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "pitch_max"), "set_pitch_max", "get_pitch_max");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "volume_min_db"), "set_volume_min_db", "get_volume_min_db");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "volume_max_db"), "set_volume_max_db", "get_volume_max_db");
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "is_sequence"), "set_is_sequence", "get_is_sequence");
}

void SoundCue::set_audio_streams(const TypedArray<AudioStream> &p_streams) { audio_streams = p_streams; }
TypedArray<AudioStream> SoundCue::get_audio_streams() const { return audio_streams; }

void SoundCue::set_pitch_min(float p_pitch) { pitch_min = p_pitch; }
float SoundCue::get_pitch_min() const { return pitch_min; }

void SoundCue::set_pitch_max(float p_pitch) { pitch_max = p_pitch; }
float SoundCue::get_pitch_max() const { return pitch_max; }

void SoundCue::set_volume_min_db(float p_volume_db) { volume_min_db = p_volume_db; }
float SoundCue::get_volume_min_db() const { return volume_min_db; }

void SoundCue::set_volume_max_db(float p_volume_db) { volume_max_db = p_volume_db; }
float SoundCue::get_volume_max_db() const { return volume_max_db; }

void SoundCue::set_is_sequence(bool p_sequence) { is_sequence = p_sequence; }
bool SoundCue::get_is_sequence() const { return is_sequence; }

Ref<AudioStream> SoundCue::get_next_stream() {
    if (audio_streams.is_empty()) return Ref<AudioStream>();
    
    if (is_sequence) {
        _last_index = (_last_index + 1) % audio_streams.size();
        return audio_streams[_last_index];
    } else {
        return audio_streams[UtilityFunctions::randi() % audio_streams.size()];
    }
}

float SoundCue::get_next_pitch() const {
    return UtilityFunctions::randf_range(pitch_min, pitch_max);
}

float SoundCue::get_next_volume() const {
    return UtilityFunctions::randf_range(volume_min_db, volume_max_db);
}
