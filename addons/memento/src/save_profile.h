#ifndef SAVE_PROFILE_H
#define SAVE_PROFILE_H

#include <godot_cpp/classes/resource.hpp>

using namespace godot;

class SaveProfile : public Resource {
	GDCLASS(SaveProfile, Resource);

protected:
	static void _bind_methods();

public:
	SaveProfile();
	~SaveProfile();
};

#endif // SAVE_PROFILE_H
