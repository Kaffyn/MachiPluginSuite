#ifndef BEHAVIOR_TREE_H
#define BEHAVIOR_TREE_H

#include <godot_cpp/classes/resource.hpp>
#include "bt_node.h"

using namespace godot;

class BehaviorTree : public Resource {
	GDCLASS(BehaviorTree, Resource);

private:
    Ref<BTNode> root_node;

protected:
	static void _bind_methods();

public:
    void set_root_node(const Ref<BTNode> &p_root_node);
    Ref<BTNode> get_root_node() const;
};

#endif // BEHAVIOR_TREE_H
