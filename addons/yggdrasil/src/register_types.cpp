#include "register_types.h"
#include "yggdrasil_server.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/engine.hpp>

using namespace godot;

static YggdrasilServer *yggdrasil_server_singleton = nullptr;

void initialize_yggdrasil_module(ModuleInitializationLevel p_level) {
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
		ClassDB::register_class<YggdrasilServer>();
        
        // Register Singleton
        yggdrasil_server_singleton = memnew(YggdrasilServer);
        Engine::get_singleton()->register_singleton("YggdrasilServer", YggdrasilServer::get_singleton());
	}
}

void uninitialize_yggdrasil_module(ModuleInitializationLevel p_level) {
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
        if (yggdrasil_server_singleton) {
            Engine::get_singleton()->unregister_singleton("YggdrasilServer");
            memdelete(yggdrasil_server_singleton);
            yggdrasil_server_singleton = nullptr;
        }
	}
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT yggdrasil_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

	init_obj.register_initializer(initialize_yggdrasil_module);
	init_obj.register_terminator(uninitialize_yggdrasil_module);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}
