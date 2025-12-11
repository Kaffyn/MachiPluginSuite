#include "world_memory.h"
#include <godot_cpp/variant/utility_functions.hpp>

WorldMemory *WorldMemory::singleton = nullptr;

WorldMemory::WorldMemory() {
	singleton = this;
}

WorldMemory::~WorldMemory() {
	if (singleton == this) {
		singleton = nullptr;
	}
}

WorldMemory *WorldMemory::get_singleton() {
	return singleton;
}

void WorldMemory::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_flag", "name", "value"), &WorldMemory::set_flag);
	ClassDB::bind_method(D_METHOD("get_flag", "name", "default"), &WorldMemory::get_flag, DEFVAL(Variant()));
    ClassDB::bind_method(D_METHOD("has_flag", "name"), &WorldMemory::has_flag);
    ClassDB::bind_method(D_METHOD("remove_flag", "name"), &WorldMemory::remove_flag);
	ClassDB::bind_method(D_METHOD("get_all_flags"), &WorldMemory::get_all_flags);
    ClassDB::bind_method(D_METHOD("set_all_flags", "flags"), &WorldMemory::set_all_flags);
    ClassDB::bind_method(D_METHOD("print_flags"), &WorldMemory::print_flags);

	ADD_SIGNAL(MethodInfo("flag_changed", PropertyInfo(Variant::STRING, "name"), PropertyInfo(Variant::NIL, "value")));
}

void WorldMemory::set_flag(const String &p_name, const Variant &p_value) {
	flags[p_name] = p_value;
	emit_signal("flag_changed", p_name, p_value);
}

Variant WorldMemory::get_flag(const String &p_name, const Variant &p_default) const {
	if (flags.has(p_name)) {
		return flags[p_name];
	}
	return p_default;
}

bool WorldMemory::has_flag(const String &p_name) const {
    return flags.has(p_name);
}

bool WorldMemory::remove_flag(const String &p_name) {
    return flags.erase(p_name);
}

Dictionary WorldMemory::get_all_flags() const {
	return flags;
}

void WorldMemory::set_all_flags(const Dictionary &p_flags) {
    flags = p_flags;
}

void WorldMemory::print_flags() const {
    UtilityFunctions::print("Current WorldMemory Flags: ", flags);
}
