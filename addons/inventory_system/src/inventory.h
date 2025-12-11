#ifndef INVENTORY_H
#define INVENTORY_H

#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/typed_array.hpp>
#include "item.h"

using namespace godot;

class Inventory : public Resource {
	GDCLASS(Inventory, Resource);

private:
    TypedArray<Dictionary> slots;
    int size = 20;

protected:
	static void _bind_methods();

public:
    void set_size(int p_size);
    int get_size() const;

    void set_slots(const TypedArray<Dictionary> &p_slots);
    TypedArray<Dictionary> get_slots() const;

    bool add_item(const Ref<Item> &p_item, int p_amount = 1);
    bool remove_item(const Ref<Item> &p_item, int p_amount = 1);
    bool has_item(const Ref<Item> &p_item, int p_amount = 1) const;
    void clear();
};

#endif // INVENTORY_H
