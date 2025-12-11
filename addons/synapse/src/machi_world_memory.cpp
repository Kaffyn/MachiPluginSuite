#include "machi_world_memory.h"

MachiWorldMemory *MachiWorldMemory::singleton = nullptr;

MachiWorldMemory::MachiWorldMemory() {
	singleton = this;
}

MachiWorldMemory::~MachiWorldMemory() {
	if (singleton == this) {
		singleton = nullptr;
	}
}

MachiWorldMemory *MachiWorldMemory::get_singleton() {
	return singleton;
}

void MachiWorldMemory::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_flag", "name", "value"), &MachiWorldMemory::set_flag);
	ClassDB::bind_method(D_METHOD("get_flag", "name", "default"), &MachiWorldMemory::get_flag, DEFVAL(Variant()));
    ClassDB::bind_method(D_METHOD("has_flag", "name"), &MachiWorldMemory::has_flag);
	ClassDB::bind_method(D_METHOD("get_all_flags"), &MachiWorldMemory::get_all_flags);
    ClassDB::bind_method(D_METHOD("set_all_flags", "flags"), &MachiWorldMemory::set_all_flags);

	ADD_SIGNAL(MethodInfo("flag_changed", PropertyInfo(Variant::STRING, "name"), PropertyInfo(Variant::NIL, "value")));
}

void MachiWorldMemory::set_flag(const String &p_name, const Variant &p_value) {
	flags[p_name] = p_value;
	emit_signal("flag_changed", p_name, p_value);
}

Variant MachiWorldMemory::get_flag(const String &p_name, const Variant &p_default) const {
	if (flags.has(p_name)) {
		return flags[p_name];
	}
	return p_default;
}

bool MachiWorldMemory::has_flag(const String &p_name) const {
    return flags.has(p_name);
}

Dictionary MachiWorldMemory::get_all_flags() const {
	return flags;
}

void MachiWorldMemory::set_all_flags(const Dictionary &p_flags) {
    flags = p_flags;
    // Potentially emit signal for full update?
    // For now we assume this is used for loading saves.
}
