#ifndef CORE_LIBRARY_H
#define CORE_LIBRARY_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/typed_array.hpp>
#include <godot_cpp/variant/string.hpp>

using namespace godot;

class CoreLibrary : public Node {
	GDCLASS(CoreLibrary, Node);

private:
    TypedArray<String> found_assets;
    void _scan_recursive(String path);

protected:
	static void _bind_methods();

public:
	CoreLibrary();
	~CoreLibrary();
    
    // API for GDScript
    TypedArray<String> scan_project(String root_path = "res://");
};

#endif // CORE_LIBRARY_H
