#ifndef MACHI_BT_PLAYER_H
#define MACHI_BT_PLAYER_H

#include <godot_cpp/classes/node.hpp>
#include "machi_behavior_tree.h"
#include "machi_blackboard.h"

using namespace godot;

class MachiBTPlayer : public Node {
	GDCLASS(MachiBTPlayer, Node);

private:
    Ref<MachiBehaviorTree> behavior_tree;
    Ref<MachiBlackboard> blackboard;
    bool active = true;

    // We need to instantiate/duplicate the tree at runtime because nodes have state (status, running index).
    // For simplicity now, we assume the resource is unique or we use it directly (stateless approach is harder with status).
    // Proper BT implementations duplicate the resource on start.
    Ref<MachiBTNode> runtime_root;

protected:
	static void _bind_methods();
    void _notification(int p_what);

public:
    MachiBTPlayer();
    ~MachiBTPlayer(); // Destructor definition

    void set_behavior_tree(const Ref<MachiBehaviorTree> &p_tree);
    Ref<MachiBehaviorTree> get_behavior_tree() const;

    void set_blackboard(const Ref<MachiBlackboard> &p_blackboard);
    Ref<MachiBlackboard> get_blackboard() const;

    void set_active(bool p_active);
    bool is_active() const;

    void update(double p_delta);
    void restart();
};

#endif // MACHI_BT_PLAYER_H
