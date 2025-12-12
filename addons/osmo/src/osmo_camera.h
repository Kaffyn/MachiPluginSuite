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

    void set_deadzone(float p_deadzone);
    float get_deadzone() const;

    void set_damping(float p_damping);
    float get_damping() const;

	void _process(double delta) override;

private:
    float deadzone = 0.1f;
    float damping = 0.5f;
};

#endif // OSMO_CAMERA_H
