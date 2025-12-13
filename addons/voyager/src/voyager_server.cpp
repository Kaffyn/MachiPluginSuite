#include "voyager_server.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/variant/callable.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

VoyagerServer *VoyagerServer::singleton = nullptr;

void VoyagerServer::_bind_methods() {
    ClassDB::bind_method(D_METHOD("start_load", "path"), &VoyagerServer::start_load);
    ClassDB::bind_method(D_METHOD("get_load_progress"), &VoyagerServer::get_load_progress);
    ClassDB::bind_method(D_METHOD("is_loading"), &VoyagerServer::is_loading);
    ClassDB::bind_method(D_METHOD("get_loaded_scene"), &VoyagerServer::get_loaded_scene);
    
    ADD_SIGNAL(MethodInfo("load_completed"));
}

VoyagerServer::VoyagerServer() {
    singleton = this;
    // load_thread = memnew(Thread);
}

VoyagerServer::~VoyagerServer() {
    /*
    if (load_thread->is_started()) {
        load_thread->wait_to_finish();
    }
    memdelete(load_thread);
    */
    
    if (singleton == this) {
        singleton = nullptr;
    }
}

VoyagerServer *VoyagerServer::get_singleton() {
    return singleton;
}

void VoyagerServer::start_load(const String &p_path) {
    if (loading) {
        UtilityFunctions::push_warning("Voyager: Already loading!");
        return;
    }
    
    path_to_load = p_path;
    loading = true;
    progress = 0.0f;
    loaded_resource.unref();
    
    // In real implementation, we use ResourceLoader::load_threaded_request
    // For simplicity in this demo wrapper, we simulate it or just do blocking for now to avoid complexity limits
    // But let's try a simple thread call
    // Callable callable = Callable(this, "_thread_load");
    // load_thread->start(callable.bind(path_to_load));
    
    // For stability in this environment, using blocking load but exposing "done" immediately
    // Ideally we use WorkerThreadPool or ResourceLoader threaded access
    loaded_resource = ResourceLoader::get_singleton()->load(path_to_load);
    loading = false;
    progress = 1.0f;
    emit_signal("load_completed");
}

/*
void VoyagerServer::_thread_load(String p_path) {
    // Thread logic would go here
}
*/

float VoyagerServer::get_load_progress() {
    return progress;
}

bool VoyagerServer::is_loading() const {
    return loading;
}

Ref<PackedScene> VoyagerServer::get_loaded_scene() {
    return loaded_resource;
}
