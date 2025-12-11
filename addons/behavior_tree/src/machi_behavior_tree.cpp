#include "machi_behavior_tree.h"

void MachiBehaviorTree::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_root_node", "root_node"), &MachiBehaviorTree::set_root_node);
	ClassDB::bind_method(D_METHOD("get_root_node"), &MachiBehaviorTree::get_root_node);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "root_node", PROPERTY_HINT_RESOURCE_TYPE, "MachiBTNode"), "set_root_node", "get_root_node");
}

void MachiBehaviorTree::set_root_node(const Ref<MachiBTNode> &p_root_node) {
    root_node = p_root_node;
}

Ref<MachiBTNode> MachiBehaviorTree::get_root_node() const {
    return root_node;
}
