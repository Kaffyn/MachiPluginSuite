#include "machi_bt_player.h"

#include <godot_cpp/classes/engine.hpp>

MachiBTPlayer::MachiBTPlayer() {
    active = true;
    // Initialize blackboard if needed
    blackboard.instantiate();
}

MachiBTPlayer::~MachiBTPlayer() {
}

void MachiBTPlayer::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_behavior_tree", "behavior_tree"), &MachiBTPlayer::set_behavior_tree);
	ClassDB::bind_method(D_METHOD("get_behavior_tree"), &MachiBTPlayer::get_behavior_tree);
    
	ClassDB::bind_method(D_METHOD("set_blackboard", "blackboard"), &MachiBTPlayer::set_blackboard);
	ClassDB::bind_method(D_METHOD("get_blackboard"), &MachiBTPlayer::get_blackboard);

    ClassDB::bind_method(D_METHOD("set_active", "active"), &MachiBTPlayer::set_active);
	ClassDB::bind_method(D_METHOD("is_active"), &MachiBTPlayer::is_active);
    
    ClassDB::bind_method(D_METHOD("update", "delta"), &MachiBTPlayer::update);
    ClassDB::bind_method(D_METHOD("restart"), &MachiBTPlayer::restart);

    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "behavior_tree", PROPERTY_HINT_RESOURCE_TYPE, "MachiBehaviorTree"), "set_behavior_tree", "get_behavior_tree");
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "blackboard", PROPERTY_HINT_RESOURCE_TYPE, "MachiBlackboard"), "set_blackboard", "get_blackboard");
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "active"), "set_active", "is_active");
}

void MachiBTPlayer::_notification(int p_what) {
	if (p_what == NOTIFICATION_READY) {
        set_process_internal(true); // Or physics process
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

void MachiBTPlayer::set_behavior_tree(const Ref<MachiBehaviorTree> &p_tree) {
    behavior_tree = p_tree;
    restart();
}

Ref<MachiBehaviorTree> MachiBTPlayer::get_behavior_tree() const {
    return behavior_tree;
}

void MachiBTPlayer::set_blackboard(const Ref<MachiBlackboard> &p_blackboard) {
    blackboard = p_blackboard;
}

Ref<MachiBlackboard> MachiBTPlayer::get_blackboard() const {
    return blackboard;
}

void MachiBTPlayer::set_active(bool p_active) {
    active = p_active;
}

bool MachiBTPlayer::is_active() const {
    return active;
}

void MachiBTPlayer::restart() {
    if (behavior_tree.is_valid()) {
        Ref<MachiBTNode> root = behavior_tree->get_root_node();
        if (root.is_valid()) {
            // In a real robust system, we would deep copy the tree nodes here to RuntimeRoot.
            // For now, we assume the user creates unique resources or we implement duplication later.
            // WARNING: Storing state in Shared Resources is bad if multiple AI use the same tree resource.
            // TODO: Implement DeepCopy/Instantiate for BT Nodes.
            runtime_root = root; 
            runtime_root->reset();
        }
    }
}

void MachiBTPlayer::update(double p_delta) {
    if (runtime_root.is_valid()) {
        // Ticking the tree
        // Node* actor = get_parent(); // Usually the actor is the parent
        // Passing 'this' as context vs 'parent'. Let's pass 'parent' assuming BTPlayer is a child.
        // Or if BTPlayer is the root of the character, pass 'this'.
        // Assuming Component pattern: BTPlayer is child of CharacterBody3D.
        Node *actor = get_parent();
        if (!actor) actor = this;

        runtime_root->tick(actor, blackboard);
    }
}
