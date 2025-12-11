#ifndef BT_COMPOSITE_H
#define BT_COMPOSITE_H

#include "bt_node.h"
#include <godot_cpp/templates/vector.hpp>

class BTComposite : public BTNode {
	GDCLASS(BTComposite, BTNode);

private:
    TypedArray<BTNode> children;
    // Track execution state if needed (e.g. running child index for sequence)
    
protected:
    int running_child_index = 0;
	static void _bind_methods();

public:
    void set_children(const TypedArray<BTNode> &p_children);
    TypedArray<BTNode> get_children() const;

    virtual void reset() override;
};

class BTSequence : public BTComposite {
    GDCLASS(BTSequence, BTComposite);
protected:
    static void _bind_methods() {}
public:
    virtual BTStatus tick(Node *p_actor, Ref<Blackboard> p_blackboard) override;
};

class BTSelector : public BTComposite {
    GDCLASS(BTSelector, BTComposite);
protected:
    static void _bind_methods() {}
public:
    virtual BTStatus tick(Node *p_actor, Ref<Blackboard> p_blackboard) override;
};


#endif // BT_COMPOSITE_H
