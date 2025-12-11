#ifndef MACHI_CONDITION_H
#define MACHI_CONDITION_H

#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

class MachiCondition : public Resource {
	GDCLASS(MachiCondition, Resource);

protected:
	static void _bind_methods();

public:
	virtual bool is_met(Object *p_context);
};

#endif // MACHI_CONDITION_H
