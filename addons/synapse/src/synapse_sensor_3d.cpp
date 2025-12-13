#include "synapse_sensor_3d.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>

using namespace godot;

void SynapseSensor3D::_bind_methods() {
    ClassDB::bind_method(D_METHOD("can_see", "target"), &SynapseSensor3D::can_see);
}

SynapseSensor3D::SynapseSensor3D() {
}

SynapseSensor3D::~SynapseSensor3D() {
}

void SynapseSensor3D::_process(double delta) {
    if (Engine::get_singleton()->is_editor_hint()) return;
}

bool SynapseSensor3D::can_see(Node3D* p_target) {
    if (!p_target) return false;
    // 3D Dot Product & Raycast Check
    return true;
}
