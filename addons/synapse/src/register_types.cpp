#include "register_types.h"

#include "world_memory.h"
#include "synapse.h"
#include "impulse.h"
#include "condition.h"

#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/engine.hpp>

using namespace godot;

static WorldMemory *world_memory_singleton = nullptr;

void initialize_synapse_module(ModuleInitializationLevel p_level) {
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
        ClassDB::register_class<Impulse>();
        ClassDB::register_class<Condition>();
        ClassDB::register_class<WorldMemory>();
        ClassDB::register_class<Synapse>();
        
        // Register Singleton
        world_memory_singleton = memnew(WorldMemory);
        Engine::get_singleton()->register_singleton("WorldMemory", WorldMemory::get_singleton());
	}
}

void uninitialize_synapse_module(ModuleInitializationLevel p_level) {
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
        if (world_memory_singleton) {
            Engine::get_singleton()->unregister_singleton("WorldMemory");
            memdelete(world_memory_singleton);
            world_memory_singleton = nullptr;
        }
    }
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT synapse_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

	init_obj.register_initializer(initialize_synapse_module);
	init_obj.register_terminator(uninitialize_synapse_module);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}
