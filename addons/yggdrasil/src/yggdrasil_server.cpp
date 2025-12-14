#include "yggdrasil_server.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/variant/callable.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

YggdrasilServer *YggdrasilServer::singleton = nullptr;

void YggdrasilServer::_bind_methods() {
    ClassDB::bind_method(D_METHOD("start_load", "path"), &YggdrasilServer::start_load);
    ClassDB::bind_method(D_METHOD("get_load_progress"), &YggdrasilServer::get_load_progress);
    ClassDB::bind_method(D_METHOD("is_loading"), &YggdrasilServer::is_loading);
    ClassDB::bind_method(D_METHOD("get_loaded_scene"), &YggdrasilServer::get_loaded_scene);
    
    ADD_SIGNAL(MethodInfo("load_completed"));
}

YggdrasilServer::YggdrasilServer() {
    singleton = this;
    // load_thread = memnew(Thread);
}

YggdrasilServer::~YggdrasilServer() {
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

YggdrasilServer *YggdrasilServer::get_singleton() {
    return singleton;
}

void YggdrasilServer::start_load(const String &p_path) {
    if (loading) {
        UtilityFunctions::push_warning("Yggdrasil: Already loading!");
        return;
    }
    
    path_to_load = p_path;
    loading = true;
    progress = 0.0f;
    loaded_resource.unref();
    
    loaded_resource = ResourceLoader::get_singleton()->load(path_to_load);
    loading = false;
    progress = 1.0f;
    emit_signal("load_completed");
}

/*
void YggdrasilServer::_thread_load(String p_path) {
    // Thread logic would go here
}
*/

float YggdrasilServer::get_load_progress() {
    return progress;
}

bool YggdrasilServer::is_loading() const {
    return loading;
}

Ref<PackedScene> YggdrasilServer::get_loaded_scene() {
    return loaded_resource;
}
