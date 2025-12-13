#include "osmo_camera_3d.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>

using namespace godot;

void OsmoCamera3D::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_follow_speed", "speed"), &OsmoCamera3D::set_follow_speed);
    ClassDB::bind_method(D_METHOD("get_follow_speed"), &OsmoCamera3D::get_follow_speed);

    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "follow_speed"), "set_follow_speed", "get_follow_speed");
}

OsmoCamera3D::OsmoCamera3D() {
}

OsmoCamera3D::~OsmoCamera3D() {
}

void OsmoCamera3D::set_follow_speed(float p_speed) {
    follow_speed = p_speed;
}

float OsmoCamera3D::get_follow_speed() const {
    return follow_speed;
}

void OsmoCamera3D::_process(double delta) {
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }
    // 3D Logic: Interpolation and following target
}
