#include "bt_decorator.h"

void BTDecorator::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_child", "child"), &BTDecorator::set_child);
	ClassDB::bind_method(D_METHOD("get_child"), &BTDecorator::get_child);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "child", PROPERTY_HINT_RESOURCE_TYPE, "BTNode"), "set_child", "get_child");
}

void BTDecorator::set_child(const Ref<BTNode> &p_child) {
    child = p_child;
}

Ref<BTNode> BTDecorator::get_child() const {
    return child;
}

void BTDecorator::reset() {
    BTNode::reset();
    if (child.is_valid()) {
        child->reset();
    }
}
