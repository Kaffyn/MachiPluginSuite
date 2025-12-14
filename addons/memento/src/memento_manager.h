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

    // Persist a node and its children recursively to a Dictionary/Resource
    void save_level_state(Node *p_level_root);
    
    // Load state back into a node tree
    void load_level_state(Node *p_level_root);
    
    Dictionary get_last_saved_state() const { return last_state; }
    
private:
    Dictionary last_state;
};

#endif // MEMENTO_MANAGER_H
