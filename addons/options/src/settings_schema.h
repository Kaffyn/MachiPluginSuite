#ifndef SETTINGS_SCHEMA_H
#define SETTINGS_SCHEMA_H

#include <godot_cpp/classes/resource.hpp>

using namespace godot;

class SettingsSchema : public Resource {
	GDCLASS(SettingsSchema, Resource);

protected:
	static void _bind_methods();

public:
	SettingsSchema();
	~SettingsSchema();
};

#endif // SETTINGS_SCHEMA_H
