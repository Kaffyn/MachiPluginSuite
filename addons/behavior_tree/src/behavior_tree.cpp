#include "behavior_tree.h"

void BehaviorTree::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_root_node", "root_node"), &BehaviorTree::set_root_node);
	ClassDB::bind_method(D_METHOD("get_root_node"), &BehaviorTree::get_root_node);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "root_node", PROPERTY_HINT_RESOURCE_TYPE, "BTNode"), "set_root_node", "get_root_node");
}

void BehaviorTree::set_root_node(const Ref<BTNode> &p_root_node) {
    root_node = p_root_node;
}

Ref<BTNode> BehaviorTree::get_root_node() const {
    return root_node;
}
