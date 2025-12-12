#ifndef OSMO_REGISTER_TYPES_H
#define OSMO_REGISTER_TYPES_H

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void initialize_osmo_module(ModuleInitializationLevel p_level);
void uninitialize_osmo_module(ModuleInitializationLevel p_level);

#endif // OSMO_REGISTER_TYPES_H
