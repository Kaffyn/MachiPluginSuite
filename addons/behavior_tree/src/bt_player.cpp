#include "bt_player.h"

#include <godot_cpp/classes/engine.hpp>

BTPlayer::BTPlayer() {
    active = true;
    // Initialize blackboard if needed
    blackboard.instantiate();
}

BTPlayer::~BTPlayer() {
}

void BTPlayer::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_behavior_tree", "behavior_tree"), &BTPlayer::set_behavior_tree);
	ClassDB::bind_method(D_METHOD("get_behavior_tree"), &BTPlayer::get_behavior_tree);
    
	ClassDB::bind_method(D_METHOD("set_blackboard", "blackboard"), &BTPlayer::set_blackboard);
	ClassDB::bind_method(D_METHOD("get_blackboard"), &BTPlayer::get_blackboard);

    ClassDB::bind_method(D_METHOD("set_active", "active"), &BTPlayer::set_active);
	ClassDB::bind_method(D_METHOD("is_active"), &BTPlayer::is_active);
    
    ClassDB::bind_method(D_METHOD("update", "delta"), &BTPlayer::update);
    ClassDB::bind_method(D_METHOD("restart"), &BTPlayer::restart);

    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "behavior_tree", PROPERTY_HINT_RESOURCE_TYPE, "BehaviorTree"), "set_behavior_tree", "get_behavior_tree");
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "blackboard", PROPERTY_HINT_RESOURCE_TYPE, "Blackboard"), "set_blackboard", "get_blackboard");
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "active"), "set_active", "is_active");
}

void BTPlayer::_notification(int p_what) {
	if (p_what == NOTIFICATION_READY) {
        set_process_internal(true); 
        set_physics_process_internal(true);
        restart();
	}
    if (p_what == NOTIFICATION_PHYSICS_PROCESS) {
        if (active && !Engine::get_singleton()->is_editor_hint()) {
            double delta = get_physics_process_delta_time();
            update(delta);
        }
    }
}

void BTPlayer::set_behavior_tree(const Ref<BehaviorTree> &p_tree) {
    behavior_tree = p_tree;
    restart();
}

Ref<BehaviorTree> BTPlayer::get_behavior_tree() const {
    return behavior_tree;
}

void BTPlayer::set_blackboard(const Ref<Blackboard> &p_blackboard) {
    blackboard = p_blackboard;
}

Ref<Blackboard> BTPlayer::get_blackboard() const {
    return blackboard;
}

void BTPlayer::set_active(bool p_active) {
    active = p_active;
}

bool BTPlayer::is_active() const {
    return active;
}

void BTPlayer::restart() {
    if (behavior_tree.is_valid()) {
        Ref<BTNode> root = behavior_tree->get_root_node();
        if (root.is_valid()) {
            runtime_root = root; 
            runtime_root->reset();
        }
    }
}

void BTPlayer::update(double p_delta) {
    if (runtime_root.is_valid()) {
        Node *actor = get_parent();
        if (!actor) actor = this;

        runtime_root->tick(actor, blackboard);
    }
}
