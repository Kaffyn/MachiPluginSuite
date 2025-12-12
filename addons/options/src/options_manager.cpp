#include "options_manager.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void OptionsManager::_bind_methods() {
    ClassDB::bind_method(D_METHOD("apply_settings"), &OptionsManager::apply_settings);
}

OptionsManager::OptionsManager() {
}

OptionsManager::~OptionsManager() {
}

void OptionsManager::apply_settings() {
    // TODO: Implement settings application logic
}
