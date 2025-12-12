#ifndef SAVE_INTERFACE_H
#define SAVE_INTERFACE_H

#include <godot_cpp/classes/node.hpp>

using namespace godot;

class SaveInterface : public Node {
	GDCLASS(SaveInterface, Node);

protected:
	static void _bind_methods();

public:
	SaveInterface();
	~SaveInterface();

    Dictionary serialize();
    void deserialize(Dictionary p_data);
};

#endif // SAVE_INTERFACE_H
