#include "osmo_camera_2d.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>

using namespace godot;

void OsmoCamera2D::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_deadzone", "deadzone"), &OsmoCamera2D::set_deadzone);
    ClassDB::bind_method(D_METHOD("get_deadzone"), &OsmoCamera2D::get_deadzone);
    ClassDB::bind_method(D_METHOD("set_damping", "damping"), &OsmoCamera2D::set_damping);
    ClassDB::bind_method(D_METHOD("get_damping"), &OsmoCamera2D::get_damping);

    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "deadzone"), "set_deadzone", "get_deadzone");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "damping"), "set_damping", "get_damping");
}

OsmoCamera2D::OsmoCamera2D() {
}

OsmoCamera2D::~OsmoCamera2D() {
}

void OsmoCamera2D::set_deadzone(float p_deadzone) {
    deadzone = p_deadzone;
}

float OsmoCamera2D::get_deadzone() const {
    return deadzone;
}

void OsmoCamera2D::set_damping(float p_damping) {
    damping = p_damping;
}

float OsmoCamera2D::get_damping() const {
    return damping;
}

void OsmoCamera2D::_process(double delta) {
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }
    // Placeholder 2D logic: simple smoothing or following handled by Camera2D base for now
    // In a real implementation effectively apply damping/deadzone here 
}
