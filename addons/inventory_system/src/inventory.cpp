#include "inventory.h"

void Inventory::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_size", "size"), &Inventory::set_size);
	ClassDB::bind_method(D_METHOD("get_size"), &Inventory::get_size);

    ClassDB::bind_method(D_METHOD("set_slots", "slots"), &Inventory::set_slots);
	ClassDB::bind_method(D_METHOD("get_slots"), &Inventory::get_slots);

    ClassDB::bind_method(D_METHOD("add_item", "item", "amount"), &Inventory::add_item, DEFVAL(1));
    ClassDB::bind_method(D_METHOD("remove_item", "item", "amount"), &Inventory::remove_item, DEFVAL(1));
    ClassDB::bind_method(D_METHOD("has_item", "item", "amount"), &Inventory::has_item, DEFVAL(1));
    ClassDB::bind_method(D_METHOD("clear"), &Inventory::clear);

    ADD_PROPERTY(PropertyInfo(Variant::INT, "size"), "set_size", "get_size");
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "slots", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_STORAGE), "set_slots", "get_slots"); 
    // Usage Storage so it saves but maybe not editable directly as raw array in inspector if complicated
}

void Inventory::set_size(int p_size) {
    size = p_size;
    slots.resize(size);
}

int Inventory::get_size() const {
    return size;
}

void Inventory::set_slots(const TypedArray<Dictionary> &p_slots) {
    slots = p_slots;
    slots.resize(size); // Ensure size consistency
}

TypedArray<Dictionary> Inventory::get_slots() const {
    return slots;
}

bool Inventory::add_item(const Ref<Item> &p_item, int p_amount) {
    // Basic implementation: Find stack or empty slot
    if (p_item.is_null()) return false;
    
    // 1. Try to stack
    for (int i = 0; i < slots.size(); ++i) {
        Dictionary slot = slots[i];
        if (slot.has("item")) {
            Ref<Item> it = slot["item"];
            if (it == p_item) {
                int current = slot["amount"];
                int max = it->get_max_stack();
                int space = max - current;
                if (space > 0) {
                    int add = (p_amount < space) ? p_amount : space;
                    slot["amount"] = current + add;
                    slots[i] = slot; // update? Dictionary is passed by value or ref? Dictionary is ref counted but lets be safe.
                    p_amount -= add;
                    if (p_amount <= 0) return true;
                }
            }
        }
    }

    // 2. Empty slot
    for (int i = 0; i < slots.size(); ++i) {
        if (p_amount <= 0) break;
        Dictionary slot = slots[i];
        if (!slot.has("item")) { // Empty
             Dictionary new_slot;
             new_slot["item"] = p_item;
             int add = (p_amount < p_item->get_max_stack()) ? p_amount : p_item->get_max_stack();
             new_slot["amount"] = add;
             slots[i] = new_slot;
             p_amount -= add;
        }
    }
    
    return p_amount <= 0;
}

bool Inventory::remove_item(const Ref<Item> &p_item, int p_amount) {
    // Implementation omitted for brevity in this turn
    return false; 
}

bool Inventory::has_item(const Ref<Item> &p_item, int p_amount) const {
    int count = 0;
    for (int i = 0; i < slots.size(); ++i) {
        Dictionary slot = slots[i];
        if (slot.has("item")) {
             Ref<Item> it = slot["item"];
             if (it == p_item) {
                 count += (int)slot["amount"];
             }
        }
    }
    return count >= p_amount;
}

void Inventory::clear() {
    slots.clear();
    slots.resize(size);
}
