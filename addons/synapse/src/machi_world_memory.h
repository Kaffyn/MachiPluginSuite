#ifndef MACHI_WORLD_MEMORY_H
#define MACHI_WORLD_MEMORY_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/string.hpp>

using namespace godot;

class MachiWorldMemory : public Node {
	GDCLASS(MachiWorldMemory, Node);

private:
	Dictionary flags;
	static MachiWorldMemory *singleton;

protected:
	static void _bind_methods();

public:
	MachiWorldMemory();
	~MachiWorldMemory();

	static MachiWorldMemory *get_singleton();

	void set_flag(const String &p_name, const Variant &p_value);
	Variant get_flag(const String &p_name, const Variant &p_default = Variant()) const;
    bool has_flag(const String &p_name) const;

	Dictionary get_all_flags() const;
    void set_all_flags(const Dictionary &p_flags);
};

#endif // MACHI_WORLD_MEMORY_H
