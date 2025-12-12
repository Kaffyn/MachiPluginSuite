#include "osmo_camera.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void OsmoCamera::_bind_methods() {
}

OsmoCamera::OsmoCamera() {
}

OsmoCamera::~OsmoCamera() {
}

void OsmoCamera::_process(double delta) {
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }
    // TODO: Implement smoothing and deadzone logic
}
