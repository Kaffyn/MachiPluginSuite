#include "condition.h"

void Condition::_bind_methods() {
	ClassDB::bind_method(D_METHOD("is_met", "context"), &Condition::is_met);
}

bool Condition::is_met(Object *p_context) {
    // Default to true if not overridden
	return true;
}
