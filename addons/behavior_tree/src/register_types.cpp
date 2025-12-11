#include "register_types.h"

#include "bt_node.h"
#include "bt_composite.h"
#include "bt_decorator.h"
#include "bt_task.h"
#include "blackboard.h"
#include "behavior_tree.h"
#include "bt_player.h"

#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_behavior_tree_module(ModuleInitializationLevel p_level) {
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
        ClassDB::register_class<BTNode>();
        ClassDB::register_class<BTComposite>();
        ClassDB::register_class<BTSequence>();
        ClassDB::register_class<BTSelector>();
        ClassDB::register_class<BTDecorator>();
        ClassDB::register_class<BTTask>();
        ClassDB::register_class<Blackboard>();
        ClassDB::register_class<BehaviorTree>();
        ClassDB::register_class<BTPlayer>();
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
