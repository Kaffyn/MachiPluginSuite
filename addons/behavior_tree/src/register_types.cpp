#include "register_types.h"

#include "machi_bt_node.h"
#include "machi_bt_composite.h"
#include "machi_bt_decorator.h"
#include "machi_bt_task.h"
#include "machi_blackboard.h"
#include "machi_behavior_tree.h"
#include "machi_bt_player.h"

#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_behavior_tree_module(ModuleInitializationLevel p_level) {
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
        ClassDB::register_class<MachiBTNode>();
        ClassDB::register_class<MachiBTComposite>();
        ClassDB::register_class<MachiBTSequence>();
        ClassDB::register_class<MachiBTSelector>();
        ClassDB::register_class<MachiBTDecorator>();
        ClassDB::register_class<MachiBTTask>();
        ClassDB::register_class<MachiBlackboard>();
        ClassDB::register_class<MachiBehaviorTree>();
        ClassDB::register_class<MachiBTPlayer>();
	}
}

void uninitialize_behavior_tree_module(ModuleInitializationLevel p_level) {
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
        // Cleanup if necessary
    }
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT behavior_tree_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

	init_obj.register_initializer(initialize_behavior_tree_module);
	init_obj.register_terminator(uninitialize_behavior_tree_module);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}
