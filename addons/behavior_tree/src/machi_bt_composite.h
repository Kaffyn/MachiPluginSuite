#ifndef MACHI_BT_COMPOSITE_H
#define MACHI_BT_COMPOSITE_H

#include "machi_bt_node.h"
#include <godot_cpp/templates/vector.hpp>

class MachiBTComposite : public MachiBTNode {
	GDCLASS(MachiBTComposite, MachiBTNode);

private:
    TypedArray<MachiBTNode> children;
    // Track execution state if needed (e.g. running child index for sequence)
    int running_child_index = 0;

protected:
	static void _bind_methods();

public:
    void set_children(const TypedArray<MachiBTNode> &p_children);
    TypedArray<MachiBTNode> get_children() const;

    virtual void reset() override;
    
    // Derived classes (Selector, Sequence) will implement tick.
    // However, to keep it simple for GDExtension, 
    // we might need to expose specific composite types or make this one generic with an enum.
    // For now, let's make it a base and assume Selector/Sequence are GDScript or derived C++ classes.
    // Actually, user wants "Robust Behavior Tree". Implementing Sequence/Selector in C++ is better.

    // Let's implement generic Composite that relies on virtual implementation, 
    // or provide concrete C++ versions.
    // For the sake of this prompt, let's implement basic Selector/Sequence logic here or in derived classes.
    // We'll leave it as a base for now to be extended, or maybe just a base.
    // Actually, usually you want Standard Composites in C++.
};

class MachiBTSequence : public MachiBTComposite {
    GDCLASS(MachiBTSequence, MachiBTComposite);
protected:
    static void _bind_methods() {}
public:
    virtual BTStatus tick(Node *p_actor, Ref<MachiBlackboard> p_blackboard) override;
};

class MachiBTSelector : public MachiBTComposite {
    GDCLASS(MachiBTSelector, MachiBTComposite);
protected:
    static void _bind_methods() {}
public:
    virtual BTStatus tick(Node *p_actor, Ref<MachiBlackboard> p_blackboard) override;
};


#endif // MACHI_BT_COMPOSITE_H
