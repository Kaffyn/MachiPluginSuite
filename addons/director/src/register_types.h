#ifndef DIRECTOR_REGISTER_TYPES_H
#define DIRECTOR_REGISTER_TYPES_H

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void initialize_director_module(ModuleInitializationLevel p_level);
void uninitialize_director_module(ModuleInitializationLevel p_level);

#endif // DIRECTOR_REGISTER_TYPES_H
