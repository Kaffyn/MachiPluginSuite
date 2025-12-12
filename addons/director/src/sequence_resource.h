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
};

#endif // SEQUENCE_RESOURCE_H
