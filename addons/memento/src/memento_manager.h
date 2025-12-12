#ifndef MEMENTO_MANAGER_H
#define MEMENTO_MANAGER_H

#include <godot_cpp/classes/node.hpp>

using namespace godot;

class MementoManager : public Node {
	GDCLASS(MementoManager, Node);

protected:
	static void _bind_methods();

public:
	MementoManager();
	~MementoManager();
};

#endif // MEMENTO_MANAGER_H
