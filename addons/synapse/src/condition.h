#ifndef CONDITION_H
#define CONDITION_H

#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

class Condition : public Resource {
	GDCLASS(Condition, Resource);

protected:
	static void _bind_methods();

public:
	virtual bool is_met(Object *p_context);
};

#endif // CONDITION_H
