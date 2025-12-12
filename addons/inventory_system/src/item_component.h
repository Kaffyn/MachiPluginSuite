#ifndef ITEM_COMPONENT_H
#define ITEM_COMPONENT_H

#include <godot_cpp/classes/resource.hpp>

using namespace godot;

class ItemComponent : public Resource {
	GDCLASS(ItemComponent, Resource);

protected:
	static void _bind_methods();

    bool enabled = true;

public:
    void set_enabled(bool p_enabled);
    bool get_enabled() const;

    // Virtual method to apply effect?
    // virtual void apply(Node *target);
};

#endif // ITEM_COMPONENT_H
