#ifndef SYNAPSE_SENSOR_2D_H
#define SYNAPSE_SENSOR_2D_H

#include <godot_cpp/classes/area2d.hpp>
#include <godot_cpp/classes/ray_cast2d.hpp>

using namespace godot;

class SynapseSensor2D : public Area2D {
	GDCLASS(SynapseSensor2D, Area2D);

protected:
	static void _bind_methods();

public:
    SynapseSensor2D();
    ~SynapseSensor2D();

    void _process(double delta) override;
    
    // API to check visibility/hearing
    bool can_see(Node2D* p_target);
    bool can_hear(Node2D* p_source, float p_db);
    
private:
    float vision_angle = 60.0f;
    float max_range = 300.0f;
};

#endif // SYNAPSE_SENSOR_2D_H
