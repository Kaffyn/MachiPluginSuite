#include "machi_bt_composite.h"

void MachiBTComposite::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_children", "children"), &MachiBTComposite::set_children);
	ClassDB::bind_method(D_METHOD("get_children"), &MachiBTComposite::get_children);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "children", PROPERTY_HINT_RESOURCE_TYPE, "MachiBTNode"), "set_children", "get_children");
}

void MachiBTComposite::set_children(const TypedArray<MachiBTNode> &p_children) {
    children = p_children;
}

TypedArray<MachiBTNode> MachiBTComposite::get_children() const {
    return children;
}

void MachiBTComposite::reset() {
    MachiBTNode::reset();
    running_child_index = 0;
    for (int i = 0; i < children.size(); ++i) {
        Ref<MachiBTNode> child = children[i];
        if (child.is_valid()) {
            child->reset();
        }
    }
}

// --- Sequence ---

BTStatus MachiBTSequence::tick(Node *p_actor, Ref<MachiBlackboard> p_blackboard) {
    TypedArray<MachiBTNode> kids = get_children();
    
    for (int i = running_child_index; i < kids.size(); ++i) {
        Ref<MachiBTNode> child = kids[i];
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

BTStatus MachiBTSelector::tick(Node *p_actor, Ref<MachiBlackboard> p_blackboard) {
    TypedArray<MachiBTNode> kids = get_children();

    for (int i = running_child_index; i < kids.size(); ++i) {
        Ref<MachiBTNode> child = kids[i];
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
