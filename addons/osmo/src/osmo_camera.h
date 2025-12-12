#ifndef OSMO_CAMERA_H
#define OSMO_CAMERA_H

#include <godot_cpp/classes/camera2d.hpp>

using namespace godot;

class OsmoCamera : public Camera2D {
	GDCLASS(OsmoCamera, Camera2D);

protected:
	static void _bind_methods();

public:
	OsmoCamera();
	~OsmoCamera();

	void _process(double delta) override;
};

#endif // OSMO_CAMERA_H
