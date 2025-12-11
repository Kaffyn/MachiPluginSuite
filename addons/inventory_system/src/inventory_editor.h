#ifndef INVENTORY_EDITOR_H
#define INVENTORY_EDITOR_H

#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/label.hpp>

using namespace godot;

class InventoryEditor : public Control {
	GDCLASS(InventoryEditor, Control);

private:
    Label *info_label;

protected:
	static void _bind_methods();

public:
    InventoryEditor();
    ~InventoryEditor();
};

#endif // INVENTORY_EDITOR_H
