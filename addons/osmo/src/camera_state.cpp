#include "camera_state.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void CameraState::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_zoom_level", "zoom_level"), &CameraState::set_zoom_level);
    ClassDB::bind_method(D_METHOD("get_zoom_level"), &CameraState::get_zoom_level);
    ClassDB::bind_method(D_METHOD("set_offset", "offset"), &CameraState::set_offset);
    ClassDB::bind_method(D_METHOD("get_offset"), &CameraState::get_offset);

    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "zoom_level"), "set_zoom_level", "get_zoom_level");
    ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "offset"), "set_offset", "get_offset");
}

CameraState::CameraState() {
}

CameraState::~CameraState() {
}

void CameraState::set_zoom_level(float p_zoom) {
    zoom_level = p_zoom;
}

float CameraState::get_zoom_level() const {
    return zoom_level;
}

void CameraState::set_offset(Vector2 p_offset) {
    offset = p_offset;
}

Vector2 CameraState::get_offset() const {
    return offset;
}
