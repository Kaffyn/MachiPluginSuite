#include "machi_bt_node.h"

void MachiBTNode::_bind_methods() {
	ClassDB::bind_method(D_METHOD("tick", "actor", "blackboard"), &MachiBTNode::tick);
    ClassDB::bind_method(D_METHOD("reset"), &MachiBTNode::reset);

    BIND_ENUM_CONSTANT(FRESH);
    BIND_ENUM_CONSTANT(RUNNING);
    BIND_ENUM_CONSTANT(SUCCESS);
    BIND_ENUM_CONSTANT(FAILURE);
}

BTStatus MachiBTNode::tick(Node *p_actor, Ref<MachiBlackboard> p_blackboard) {
    // Default implementation returns SUCCESS immediately.
    // Derived classes should override this.
    return SUCCESS;
}

void MachiBTNode::reset() {
    status = FRESH;
}
