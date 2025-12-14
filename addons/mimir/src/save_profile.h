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

    void set_metadata(Dictionary p_metadata);
    Dictionary get_metadata() const;

private:
    Dictionary metadata;
};

#endif // SAVE_PROFILE_H
