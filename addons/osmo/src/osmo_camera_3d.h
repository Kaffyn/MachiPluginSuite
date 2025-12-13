#ifndef OSMO_CAMERA_3D_H
#define OSMO_CAMERA_3D_H

#include <godot_cpp/classes/camera3d.hpp>

using namespace godot;

class OsmoCamera3D : public Camera3D {
	GDCLASS(OsmoCamera3D, Camera3D);

protected:
	static void _bind_methods();

public:
	OsmoCamera3D();
	~OsmoCamera3D();

    void set_follow_speed(float p_speed);
    float get_follow_speed() const;

	void _process(double delta) override;

private:
    float follow_speed = 5.0f;
};

#endif // OSMO_CAMERA_3D_H
