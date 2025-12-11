#ifndef MACHI_BT_NODE_H
#define MACHI_BT_NODE_H

#include <godot_cpp/classes/resource.hpp>
#include "machi_blackboard.h"
#include <godot_cpp/classes/node.hpp> // For actor context

using namespace godot;

// Status enum compatible with standard BTs
enum BTStatus {
    FRESH,
    RUNNING,
    SUCCESS,
    FAILURE
};

// We need to register the enum
VARIANT_ENUM_CAST(BTStatus);

class MachiBTNode : public Resource {
	GDCLASS(MachiBTNode, Resource);

protected:
	static void _bind_methods();

public:
    // Helper to store last status
    BTStatus status = FRESH;

    // Tick the node. 
    // p_actor: The Node (Character) executing this tree.
    // p_blackboard: The memory.
	virtual BTStatus tick(Node *p_actor, Ref<MachiBlackboard> p_blackboard);
    
    // Reset status to FRESH
    virtual void reset();
};

#endif // MACHI_BT_NODE_H
