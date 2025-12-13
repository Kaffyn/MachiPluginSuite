#ifndef VOYAGER_SERVER_H
#define VOYAGER_SERVER_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/classes/thread.hpp>
#include <godot_cpp/classes/mutex.hpp>

using namespace godot;

class VoyagerServer : public Node {
	GDCLASS(VoyagerServer, Node);

protected:
	static void _bind_methods();

public:
	VoyagerServer();
	~VoyagerServer();

    static VoyagerServer *get_singleton();

    // Async Loading API
    void start_load(const String &p_path);
    float get_load_progress();
    bool is_loading() const;
    Ref<PackedScene> get_loaded_scene();

private:
    static VoyagerServer *singleton;
    
    // Threading
    Thread *load_thread;
    Mutex mutex;
    bool loading = false;
    float progress = 0.0f;
    String path_to_load;
    Ref<PackedScene> loaded_resource;
    
    void _thread_load(String p_path);
};

#endif // VOYAGER_SERVER_H
