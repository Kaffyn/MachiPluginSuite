#ifndef SYNAPSE_H
#define SYNAPSE_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/templates/vector.hpp>
#include "impulse.h"

using namespace godot;

class Synapse : public Node {
	GDCLASS(Synapse, Node);

private:
	TypedArray<Impulse> impulses;

protected:
	static void _bind_methods();

public:
	Synapse();
	~Synapse();

	void set_impulses(const TypedArray<Impulse> &p_impulses);
	TypedArray<Impulse> get_impulses() const;

	void trigger();
};

#endif // SYNAPSE_H
