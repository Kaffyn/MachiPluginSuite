#ifndef BT_PLAYER_H
#define BT_PLAYER_H

#include <godot_cpp/classes/node.hpp>
#include "behavior_tree.h"
#include "blackboard.h"

using namespace godot;

class BTPlayer : public Node {
	GDCLASS(BTPlayer, Node);

private:
    Ref<BehaviorTree> behavior_tree;
    Ref<Blackboard> blackboard;
    bool active = true;

    Ref<BTNode> runtime_root;

protected:
	static void _bind_methods();
    void _notification(int p_what);

public:
    BTPlayer();
    ~BTPlayer();

    void set_behavior_tree(const Ref<BehaviorTree> &p_tree);
    Ref<BehaviorTree> get_behavior_tree() const;

    void set_blackboard(const Ref<Blackboard> &p_blackboard);
    Ref<Blackboard> get_blackboard() const;

    void set_active(bool p_active);
    bool is_active() const;

    void update(double p_delta);
    void restart();
};

#endif // BT_PLAYER_H
