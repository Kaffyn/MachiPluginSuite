#include "synapse_sensor_2d.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/vector2.hpp>

using namespace godot;

void SynapseSensor2D::_bind_methods() {
    ClassDB::bind_method(D_METHOD("can_see", "target"), &SynapseSensor2D::can_see);
}

SynapseSensor2D::SynapseSensor2D() {
}

SynapseSensor2D::~SynapseSensor2D() {
}

void SynapseSensor2D::_process(double delta) {
    if (Engine::get_singleton()->is_editor_hint()) return;
}

bool SynapseSensor2D::can_see(Node2D* p_target) {
    if (!p_target) return false;
    
    // Placeholder logic for 2D angle/raycast check
    Vector2 to_target = p_target->get_global_position() - get_global_position();
    if (to_target.length() > max_range) return false;
    
    // Should cast a ray here
    return true; 
}

bool SynapseSensor2D::can_hear(Node2D* p_source, float p_db) {
    // Distance attenuation logic
    return true;
}
