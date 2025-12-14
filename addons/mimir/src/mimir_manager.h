#ifndef MIMIR_MANAGER_H
#define MIMIR_MANAGER_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/dictionary.hpp>

using namespace godot;

class MimirManager : public Node {
	GDCLASS(MimirManager, Node);

protected:
	static void _bind_methods();

public:
	MimirManager();
	~MimirManager();

    // Persist a node and its children recursively to a Dictionary/Resource
    void save_level_state(Node *p_level_root);
    
    // Load state back into a node tree
    void load_level_state(Node *p_level_root);
    
    Dictionary get_last_saved_state() const { return last_state; }
    
private:
    Dictionary last_state;
};

#endif // MIMIR_MANAGER_H
