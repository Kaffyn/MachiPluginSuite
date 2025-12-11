#include "bt_composite.h"

void BTComposite::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_children", "children"), &BTComposite::set_children);
	ClassDB::bind_method(D_METHOD("get_children"), &BTComposite::get_children);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "children", PROPERTY_HINT_RESOURCE_TYPE, "BTNode"), "set_children", "get_children");
}

void BTComposite::set_children(const TypedArray<BTNode> &p_children) {
    children = p_children;
}

TypedArray<BTNode> BTComposite::get_children() const {
    return children;
}

void BTComposite::reset() {
    BTNode::reset();
    running_child_index = 0;
    for (int i = 0; i < children.size(); ++i) {
        Ref<BTNode> child = children[i];
        if (child.is_valid()) {
            child->reset();
        }
    }
}

// --- Sequence ---

BTStatus BTSequence::tick(Node *p_actor, Ref<Blackboard> p_blackboard) {
    TypedArray<BTNode> kids = get_children();
    
    for (int i = running_child_index; i < kids.size(); ++i) {
        Ref<BTNode> child = kids[i];
        if (child.is_valid()) {
            BTStatus child_status = child->tick(p_actor, p_blackboard);
            
            if (child_status == RUNNING) {
                running_child_index = i;
                status = RUNNING;
                return RUNNING;
            } else if (child_status == FAILURE) {
                running_child_index = 0; // Reset for next run
                status = FAILURE;
                return FAILURE;
            }
        }
    }
    
    running_child_index = 0; // Completed all
    status = SUCCESS;
    return SUCCESS;
}

// --- Selector ---

BTStatus BTSelector::tick(Node *p_actor, Ref<Blackboard> p_blackboard) {
    TypedArray<BTNode> kids = get_children();

    for (int i = running_child_index; i < kids.size(); ++i) {
        Ref<BTNode> child = kids[i];
        if (child.is_valid()) {
            BTStatus child_status = child->tick(p_actor, p_blackboard);

            if (child_status == RUNNING) {
                running_child_index = i;
                status = RUNNING;
                return RUNNING;
            } else if (child_status == SUCCESS) {
                running_child_index = 0; // Reset for next run
                status = SUCCESS;
                return SUCCESS;
            }
        }
    }

    running_child_index = 0; // All failed
    status = FAILURE;
    return FAILURE;
}
