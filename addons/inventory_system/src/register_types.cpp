#include "register_types.h"

#include "item.h"
#include "item_component.h"
#include "inventory.h"
#include "inventory_editor.h"

#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_inventory_system_module(ModuleInitializationLevel p_level) {
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
        ClassDB::register_class<ItemComponent>();
        ClassDB::register_class<Item>();
        ClassDB::register_class<Inventory>();
        ClassDB::register_class<InventoryEditor>();
	}
}

void uninitialize_inventory_system_module(ModuleInitializationLevel p_level) {
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
        // Cleanup if necessary
    }
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT inventory_system_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

	init_obj.register_initializer(initialize_inventory_system_module);
	init_obj.register_terminator(uninitialize_inventory_system_module);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}
