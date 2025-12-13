#ifndef SYNAPSE_SENSOR_3D_H
#define SYNAPSE_SENSOR_3D_H

#include <godot_cpp/classes/area3d.hpp>

using namespace godot;

class SynapseSensor3D : public Area3D {
	GDCLASS(SynapseSensor3D, Area3D);

protected:
	static void _bind_methods();

public:
    SynapseSensor3D();
    ~SynapseSensor3D();

    void _process(double delta) override;
    
    bool can_see(Node3D* p_target);
    
private:
    float vision_angle = 60.0f;
    float max_range = 30.0f;
};

#endif // SYNAPSE_SENSOR_3D_H
