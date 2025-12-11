#include "synapse.h"

Synapse::Synapse() {
}

Synapse::~Synapse() {
}

void Synapse::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_impulses", "impulses"), &Synapse::set_impulses);
	ClassDB::bind_method(D_METHOD("get_impulses"), &Synapse::get_impulses);
	ClassDB::bind_method(D_METHOD("trigger"), &Synapse::trigger);

	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "impulses", PROPERTY_HINT_RESOURCE_TYPE, "Impulse"), "set_impulses", "get_impulses");
}

void Synapse::set_impulses(const TypedArray<Impulse> &p_impulses) {
	impulses = p_impulses;
}

TypedArray<Impulse> Synapse::get_impulses() const {
	return impulses;
}

void Synapse::trigger() {
	for (int i = 0; i < impulses.size(); ++i) {
		Ref<Impulse> impulse = impulses[i];
		if (impulse.is_valid()) {
			impulse->execute(this);
		}
	}
}
