#ifndef SEQUENCE_RESOURCE_H
#define SEQUENCE_RESOURCE_H

#include <godot_cpp/classes/resource.hpp>

using namespace godot;

class SequenceResource : public Resource {
	GDCLASS(SequenceResource, Resource);

protected:
	static void _bind_methods();

public:
	SequenceResource();
	~SequenceResource();

    void set_tracks(TypedArray<Resource> p_tracks);
    TypedArray<Resource> get_tracks() const;

private:
    TypedArray<Resource> tracks;
};

#endif // SEQUENCE_RESOURCE_H
