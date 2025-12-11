#include "inventory_editor.h"

void InventoryEditor::_bind_methods() {
    // Bindings
}

InventoryEditor::InventoryEditor() {
    info_label = memnew(Label);
    info_label->set_text("Inventory Editor - Work in Progress");
    add_child(info_label);
}

InventoryEditor::~InventoryEditor() {
}
