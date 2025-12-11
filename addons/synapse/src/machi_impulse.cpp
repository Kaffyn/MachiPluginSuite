#include "machi_impulse.h"

#include <godot_cpp/variant/utility_functions.hpp>

void MachiImpulse::_bind_methods() {
	ClassDB::bind_method(D_METHOD("execute", "context"), &MachiImpulse::execute);
}

void MachiImpulse::execute(Object *p_context) {
	// Base implementation can print an error or be empty.
	// In GDScript, users will override this.
	// For C++ derived classes, they should override this method.
	// if (get_script_instance()) {
	// 	return;
	// }
    // Fallback/Default behavior
    UtilityFunctions::print("MachiImpulse executed (Default C++).");
}
