#ifndef DIRECTOR_PLAYER_H
#define DIRECTOR_PLAYER_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/resource.hpp>

using namespace godot;

class DirectorPlayer : public Node {
	GDCLASS(DirectorPlayer, Node);

protected:
	static void _bind_methods();

public:
	DirectorPlayer();
	~DirectorPlayer();

    void play(Ref<Resource> p_sequence);
    void stop();
    bool is_playing() const;

private:
    bool playing = false;
};

#endif // DIRECTOR_PLAYER_H
