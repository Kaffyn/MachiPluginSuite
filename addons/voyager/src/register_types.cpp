#include "register_types.h"
#include "voyager_server.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/engine.hpp>

using namespace godot;

static VoyagerServer *voyager_server_singleton = nullptr;

void initialize_voyager_module(ModuleInitializationLevel p_level) {
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
		ClassDB::register_class<VoyagerServer>();
        
        // Register Singleton
        voyager_server_singleton = memnew(VoyagerServer);
        Engine::get_singleton()->register_singleton("VoyagerServer", VoyagerServer::get_singleton());
	}
}

void uninitialize_voyager_module(ModuleInitializationLevel p_level) {
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
        if (voyager_server_singleton) {
            Engine::get_singleton()->unregister_singleton("VoyagerServer");
            memdelete(voyager_server_singleton);
            voyager_server_singleton = nullptr;
        }
	}
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT voyager_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

	init_obj.register_initializer(initialize_voyager_module);
	init_obj.register_terminator(uninitialize_voyager_module);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}
