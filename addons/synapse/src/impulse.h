#ifndef IMPULSE_H
#define IMPULSE_H

#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

class Impulse : public Resource {
	GDCLASS(Impulse, Resource);

protected:
	static void _bind_methods();

public:
	// Virtual method to execute the impulse.
	// We use Object* context to allow passing any relevant node/object.
	virtual void execute(Object *p_context);
};

#endif // IMPULSE_H
