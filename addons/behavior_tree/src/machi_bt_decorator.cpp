#include "machi_bt_decorator.h"

void MachiBTDecorator::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_child", "child"), &MachiBTDecorator::set_child);
	ClassDB::bind_method(D_METHOD("get_child"), &MachiBTDecorator::get_child);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "child", PROPERTY_HINT_RESOURCE_TYPE, "MachiBTNode"), "set_child", "get_child");
}

void MachiBTDecorator::set_child(const Ref<MachiBTNode> &p_child) {
    child = p_child;
}

Ref<MachiBTNode> MachiBTDecorator::get_child() const {
    return child;
}

void MachiBTDecorator::reset() {
    MachiBTNode::reset();
    if (child.is_valid()) {
        child->reset();
    }
}
