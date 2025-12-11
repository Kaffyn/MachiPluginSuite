#include "bt_node.h"

void BTNode::_bind_methods() {
	ClassDB::bind_method(D_METHOD("tick", "actor", "blackboard"), &BTNode::tick);
    ClassDB::bind_method(D_METHOD("reset"), &BTNode::reset);

    BIND_ENUM_CONSTANT(FRESH);
    BIND_ENUM_CONSTANT(RUNNING);
    BIND_ENUM_CONSTANT(SUCCESS);
    BIND_ENUM_CONSTANT(FAILURE);
}

BTStatus BTNode::tick(Node *p_actor, Ref<Blackboard> p_blackboard) {
    // Default implementation returns SUCCESS immediately.
    // Derived classes should override this.
    return SUCCESS;
}

void BTNode::reset() {
    status = FRESH;
}
