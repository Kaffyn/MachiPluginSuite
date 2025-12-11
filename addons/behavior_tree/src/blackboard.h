#ifndef BLACKBOARD_H
#define BLACKBOARD_H

#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>

using namespace godot;

class Blackboard : public Resource {
	GDCLASS(Blackboard, Resource);

private:
	Dictionary data;
    // Potentially parent blackboard for inheritance?

protected:
	static void _bind_methods();

public:
	void set_value(const String &p_key, const Variant &p_value);
	Variant get_value(const String &p_key, const Variant &p_default = Variant()) const;
	bool has_value(const String &p_key) const;
	void erase_value(const String &p_key);
    void clear();

    Dictionary get_data() const;
    void set_data(const Dictionary &p_data);
};

#endif // BLACKBOARD_H
