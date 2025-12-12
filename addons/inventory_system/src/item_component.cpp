#include "item_component.h"

void ItemComponent::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_enabled", "enabled"), &ItemComponent::set_enabled);
    ClassDB::bind_method(D_METHOD("get_enabled"), &ItemComponent::get_enabled);

    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "enabled"), "set_enabled", "get_enabled");
}

void ItemComponent::set_enabled(bool p_enabled) { enabled = p_enabled; }
bool ItemComponent::get_enabled() const { return enabled; }


