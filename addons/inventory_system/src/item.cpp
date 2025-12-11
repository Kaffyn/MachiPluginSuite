#include "item.h"

void Item::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_id", "id"), &Item::set_id);
	ClassDB::bind_method(D_METHOD("get_id"), &Item::get_id);

    ClassDB::bind_method(D_METHOD("set_display_name", "display_name"), &Item::set_display_name);
	ClassDB::bind_method(D_METHOD("get_display_name"), &Item::get_display_name);

    ClassDB::bind_method(D_METHOD("set_description", "description"), &Item::set_description);
	ClassDB::bind_method(D_METHOD("get_description"), &Item::get_description);

    ClassDB::bind_method(D_METHOD("set_icon", "icon"), &Item::set_icon);
	ClassDB::bind_method(D_METHOD("get_icon"), &Item::get_icon);

    ClassDB::bind_method(D_METHOD("set_max_stack", "max_stack"), &Item::set_max_stack);
	ClassDB::bind_method(D_METHOD("get_max_stack"), &Item::get_max_stack);

    ClassDB::bind_method(D_METHOD("set_components", "components"), &Item::set_components);
	ClassDB::bind_method(D_METHOD("get_components"), &Item::get_components);

    ADD_PROPERTY(PropertyInfo(Variant::STRING, "id"), "set_id", "get_id");
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "display_name"), "set_display_name", "get_display_name");
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "description", PROPERTY_HINT_MULTILINE_TEXT), "set_description", "get_description");
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "icon", PROPERTY_HINT_RESOURCE_TYPE, "Texture2D"), "set_icon", "get_icon");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "max_stack"), "set_max_stack", "get_max_stack");
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "components", PROPERTY_HINT_RESOURCE_TYPE, "ItemComponent"), "set_components", "get_components");
}

void Item::set_id(const String &p_id) { id = p_id; }
String Item::get_id() const { return id; }

void Item::set_display_name(const String &p_name) { display_name = p_name; }
String Item::get_display_name() const { return display_name; }

void Item::set_description(const String &p_desc) { description = p_desc; }
String Item::get_description() const { return description; }

void Item::set_icon(const Ref<Texture2D> &p_icon) { icon = p_icon; }
Ref<Texture2D> Item::get_icon() const { return icon; }

void Item::set_max_stack(int p_stack) { max_stack = p_stack; }
int Item::get_max_stack() const { return max_stack; }

void Item::set_components(const TypedArray<ItemComponent> &p_components) { components = p_components; }
TypedArray<ItemComponent> Item::get_components() const { return components; }
