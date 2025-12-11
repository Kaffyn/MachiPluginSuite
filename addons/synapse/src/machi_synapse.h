#ifndef MACHI_SYNAPSE_H
#define MACHI_SYNAPSE_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/templates/vector.hpp>
#include "machi_impulse.h"

using namespace godot;

class MachiSynapse : public Node {
	GDCLASS(MachiSynapse, Node);

private:
	TypedArray<MachiImpulse> impulses;

protected:
	static void _bind_methods();

public:
	MachiSynapse();
	~MachiSynapse();

	void set_impulses(const TypedArray<MachiImpulse> &p_impulses);
	TypedArray<MachiImpulse> get_impulses() const;

	void trigger();
};

#endif // MACHI_SYNAPSE_H
