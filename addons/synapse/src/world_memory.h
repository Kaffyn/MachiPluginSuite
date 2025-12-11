#ifndef WORLD_MEMORY_H
#define WORLD_MEMORY_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/string.hpp>

using namespace godot;

class WorldMemory : public Node {
	GDCLASS(WorldMemory, Node);

private:
	Dictionary flags;
	static WorldMemory *singleton;

protected:
	static void _bind_methods();

public:
	WorldMemory();
	~WorldMemory();

	static WorldMemory *get_singleton();

	void set_flag(const String &p_name, const Variant &p_value);
	Variant get_flag(const String &p_name, const Variant &p_default = Variant()) const;
    bool has_flag(const String &p_name) const;
    bool remove_flag(const String &p_name);

	Dictionary get_all_flags() const;
    void set_all_flags(const Dictionary &p_flags);
    
    // Helper to print debug info
    void print_flags() const;
};

#endif // WORLD_MEMORY_H
