#include "impulse.h"

#include <godot_cpp/variant/utility_functions.hpp>

void Impulse::_bind_methods() {
	ClassDB::bind_method(D_METHOD("execute", "context"), &Impulse::execute);
}

void Impulse::execute(Object *p_context) {
    // Fallback/Default behavior
    UtilityFunctions::print("Impulse executed (Default C++).");
}
