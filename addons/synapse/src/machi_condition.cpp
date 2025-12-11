#include "machi_condition.h"

void MachiCondition::_bind_methods() {
	ClassDB::bind_method(D_METHOD("is_met", "context"), &MachiCondition::is_met);
}

bool MachiCondition::is_met(Object *p_context) {
    // Default to true if not overridden
	return true;
}
