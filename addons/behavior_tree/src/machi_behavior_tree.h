#ifndef MACHI_BEHAVIOR_TREE_H
#define MACHI_BEHAVIOR_TREE_H

#include <godot_cpp/classes/resource.hpp>
#include "machi_bt_node.h"

using namespace godot;

class MachiBehaviorTree : public Resource {
	GDCLASS(MachiBehaviorTree, Resource);

private:
    Ref<MachiBTNode> root_node;

protected:
	static void _bind_methods();

public:
    void set_root_node(const Ref<MachiBTNode> &p_root_node);
    Ref<MachiBTNode> get_root_node() const;
};

#endif // MACHI_BEHAVIOR_TREE_H
