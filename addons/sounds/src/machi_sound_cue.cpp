#include "machi_sound_cue.h"

using namespace godot;

void MachiSoundCue::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_stream", "stream"), &MachiSoundCue::set_stream);
	ClassDB::bind_method(D_METHOD("get_stream"), &MachiSoundCue::get_stream);
	ClassDB::bind_method(D_METHOD("set_max_instances", "max_instances"), &MachiSoundCue::set_max_instances);
	ClassDB::bind_method(D_METHOD("get_max_instances"), &MachiSoundCue::get_max_instances);
	ClassDB::bind_method(D_METHOD("set_cooldown", "cooldown"), &MachiSoundCue::set_cooldown);
	ClassDB::bind_method(D_METHOD("get_cooldown"), &MachiSoundCue::get_cooldown);

	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "stream", PROPERTY_HINT_RESOURCE_TYPE, "AudioStream"), "set_stream", "get_stream");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "max_instances"), "set_max_instances", "get_max_instances");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "cooldown"), "set_cooldown", "get_cooldown");
}

MachiSoundCue::MachiSoundCue() {
	max_instances = 5;
	cooldown = 0.0f;
}

MachiSoundCue::~MachiSoundCue() {
}

void MachiSoundCue::set_stream(const Ref<AudioStream> &p_stream) {
	stream = p_stream;
}

Ref<AudioStream> MachiSoundCue::get_stream() const {
	return stream;
}

void MachiSoundCue::set_max_instances(int p_max) {
	max_instances = p_max;
}

int MachiSoundCue::get_max_instances() const {
	return max_instances;
}

void MachiSoundCue::set_cooldown(float p_cooldown) {
	cooldown = p_cooldown;
}

float MachiSoundCue::get_cooldown() const {
	return cooldown;
}
