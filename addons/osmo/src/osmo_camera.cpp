#include "osmo_camera.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>

using namespace godot;

void OsmoCamera::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_deadzone", "deadzone"), &OsmoCamera::set_deadzone);
    ClassDB::bind_method(D_METHOD("get_deadzone"), &OsmoCamera::get_deadzone);
    ClassDB::bind_method(D_METHOD("set_damping", "damping"), &OsmoCamera::set_damping);
    ClassDB::bind_method(D_METHOD("get_damping"), &OsmoCamera::get_damping);

    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "deadzone"), "set_deadzone", "get_deadzone");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "damping"), "set_damping", "get_damping");
}

OsmoCamera::OsmoCamera() {
}

OsmoCamera::~OsmoCamera() {
}

void OsmoCamera::set_deadzone(float p_deadzone) {
    deadzone = p_deadzone;
}

float OsmoCamera::get_deadzone() const {
    return deadzone;
}

void OsmoCamera::set_damping(float p_damping) {
    damping = p_damping;
}

float OsmoCamera::get_damping() const {
    return damping;
}

void OsmoCamera::_process(double delta) {
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }
    
    // Basic Damping Logic
    Vector2 target = get_global_position(); // Placeholder for target logic
    // In a real implementation, we would interpolate towards a target
}
