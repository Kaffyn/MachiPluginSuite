#ifndef MACHI_IMPULSE_H
#define MACHI_IMPULSE_H

#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

class MachiImpulse : public Resource {
	GDCLASS(MachiImpulse, Resource);

protected:
	static void _bind_methods();

public:
	// Virtual method to execute the impulse.
	// We use Object* context to allow passing any relevant node/object.
	virtual void execute(Object *p_context);
};

#endif // MACHI_IMPULSE_H
