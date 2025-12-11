#ifndef ITEM_COMPONENT_H
#define ITEM_COMPONENT_H

#include <godot_cpp/classes/resource.hpp>

using namespace godot;

class ItemComponent : public Resource {
	GDCLASS(ItemComponent, Resource);

protected:
	static void _bind_methods();

public:
    // Virtual method to apply effect?
    // virtual void apply(Node *target);
};

#endif // ITEM_COMPONENT_H
