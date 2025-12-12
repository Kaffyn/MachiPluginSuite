#ifndef CAMERA_STATE_H
#define CAMERA_STATE_H

#include <godot_cpp/classes/resource.hpp>

using namespace godot;

class CameraState : public Resource {
	GDCLASS(CameraState, Resource);

protected:
	static void _bind_methods();

public:
	CameraState();
	~CameraState();
    
    // Properties
    float zoom_level = 1.0f;
};

#endif // CAMERA_STATE_H
