#include "register_types.h"

#include "sound_cue.h"
#include "sound_manager.h"
#include "sound_server.h"

#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

static SoundServer *sound_server_singleton = nullptr;

void initialize_sounds_module(ModuleInitializationLevel p_level) {
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
        ClassDB::register_class<SoundCue>();
        ClassDB::register_class<SoundManager>();
        ClassDB::register_class<SoundServer>();
        
        sound_server_singleton = memnew(SoundServer);
        Engine::get_singleton()->register_singleton("SoundServer", SoundServer::get_singleton());
	}
}

void uninitialize_sounds_module(ModuleInitializationLevel p_level) {
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
        if (sound_server_singleton) {
            Engine::get_singleton()->unregister_singleton("SoundServer");
            memdelete(sound_server_singleton);
            sound_server_singleton = nullptr;
        }
    }
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT sounds_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

	init_obj.register_initializer(initialize_sounds_module);
	init_obj.register_terminator(uninitialize_sounds_module);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}
