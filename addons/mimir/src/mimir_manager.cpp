#include "mimir_manager.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void MimirManager::_bind_methods() {
    ClassDB::bind_method(D_METHOD("save_level_state", "level_root"), &MimirManager::save_level_state);
    ClassDB::bind_method(D_METHOD("load_level_state", "level_root"), &MimirManager::load_level_state);
}

MimirManager::MimirManager() {
}

MimirManager::~MimirManager() {
}

void MimirManager::save_level_state(Node *p_level_root) {
    if (!p_level_root) return;
    UtilityFunctions::print("Mimir: Saving state for ", p_level_root->get_name());
    // TODO: Recursive state capture logic (SaveInterface implementation)
    // For now, simple mock
    last_state["level_name"] = p_level_root->get_name();
}

void MimirManager::load_level_state(Node *p_level_root) {
    if (!p_level_root) return;
    UtilityFunctions::print("Mimir: Loading state for ", p_level_root->get_name());
    // TODO: Recursive state restoration
}
