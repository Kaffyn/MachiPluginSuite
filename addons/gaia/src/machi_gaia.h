#ifndef MACHI_GAIA_H
#define MACHI_GAIA_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/dictionary.hpp>

using namespace godot;

class MachiGaia : public Node {
	GDCLASS(MachiGaia, Node);

private:
	static MachiGaia *singleton;
    
    // Time System State
    float current_time = 8.0f; // Start at 8 AM
    float time_scale = 1.0f;

protected:
	static void _bind_methods();

public:
	MachiGaia();
	~MachiGaia();

	static MachiGaia *get_singleton();
    
    // Time API
    float get_time() const;
    void set_time(float p_time);
    
    // Weather API (Placeholder)
    void set_weather(String type);
};

#endif // MACHI_GAIA_H
