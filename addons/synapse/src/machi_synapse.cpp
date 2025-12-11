#include "machi_synapse.h"

MachiSynapse::MachiSynapse() {
}

MachiSynapse::~MachiSynapse() {
}

void MachiSynapse::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_impulses", "impulses"), &MachiSynapse::set_impulses);
	ClassDB::bind_method(D_METHOD("get_impulses"), &MachiSynapse::get_impulses);
	ClassDB::bind_method(D_METHOD("trigger"), &MachiSynapse::trigger);

	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "impulses", PROPERTY_HINT_RESOURCE_TYPE, "MachiImpulse"), "set_impulses", "get_impulses");
}

void MachiSynapse::set_impulses(const TypedArray<MachiImpulse> &p_impulses) {
	impulses = p_impulses;
}

TypedArray<MachiImpulse> MachiSynapse::get_impulses() const {
	return impulses;
}

void MachiSynapse::trigger() {
	for (int i = 0; i < impulses.size(); ++i) {
		Ref<MachiImpulse> impulse = impulses[i];
		if (impulse.is_valid()) {
			impulse->execute(this);
		}
	}
}
