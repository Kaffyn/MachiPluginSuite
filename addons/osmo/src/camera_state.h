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
    Vector2 offset = Vector2(0, 0);

    void set_offset(Vector2 p_offset);
    Vector2 get_offset() const;
};

#endif // CAMERA_STATE_H
