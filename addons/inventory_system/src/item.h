#ifndef ITEM_H
#define ITEM_H

#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/templates/vector.hpp>
#include "item_component.h"

using namespace godot;

class Item : public Resource {
	GDCLASS(Item, Resource);

private:
    String id;
    String display_name;
    String description;
    Ref<Texture2D> icon;
    int max_stack = 1;
    TypedArray<ItemComponent> components;

protected:
	static void _bind_methods();

public:
    void set_id(const String &p_id);
    String get_id() const;

    void set_display_name(const String &p_name);
    String get_display_name() const;

    void set_description(const String &p_desc);
    String get_description() const;

    void set_icon(const Ref<Texture2D> &p_icon);
    Ref<Texture2D> get_icon() const;

    void set_max_stack(int p_stack);
    int get_max_stack() const;

    void set_components(const TypedArray<ItemComponent> &p_components);
    TypedArray<ItemComponent> get_components() const;
};

#endif // ITEM_H
