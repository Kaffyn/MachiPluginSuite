#ifndef DIRECTOR_MANAGER_H
#define DIRECTOR_MANAGER_H

#include <godot_cpp/classes/node.hpp>

using namespace godot;

class DirectorManager : public Node {
	GDCLASS(DirectorManager, Node);

protected:
	static void _bind_methods();

public:
	DirectorManager();
	~DirectorManager();
};

#endif // DIRECTOR_MANAGER_H
