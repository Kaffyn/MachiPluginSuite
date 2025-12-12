#ifndef OPTIONS_MANAGER_H
#define OPTIONS_MANAGER_H

#include <godot_cpp/classes/node.hpp>

using namespace godot;

class OptionsManager : public Node {
	GDCLASS(OptionsManager, Node);

protected:
	static void _bind_methods();

public:
	OptionsManager();
	~OptionsManager();

    void apply_settings();
};

#endif // OPTIONS_MANAGER_H
