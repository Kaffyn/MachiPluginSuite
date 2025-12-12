#ifndef DIRECTOR_PLAYER_H
#define DIRECTOR_PLAYER_H

#include <godot_cpp/classes/node.hpp>

using namespace godot;

class DirectorPlayer : public Node {
	GDCLASS(DirectorPlayer, Node);

protected:
	static void _bind_methods();

public:
	DirectorPlayer();
	~DirectorPlayer();
};

#endif // DIRECTOR_PLAYER_H
