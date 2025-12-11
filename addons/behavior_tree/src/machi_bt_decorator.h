#ifndef MACHI_BT_DECORATOR_H
#define MACHI_BT_DECORATOR_H

#include "machi_bt_node.h"

class MachiBTDecorator : public MachiBTNode {
	GDCLASS(MachiBTDecorator, MachiBTNode);

private:
    Ref<MachiBTNode> child;

protected:
	static void _bind_methods();

public:
    void set_child(const Ref<MachiBTNode> &p_child);
    Ref<MachiBTNode> get_child() const;

    virtual void reset() override;
    // Decorators typically wrap execution: if condition() -> return child.tick()
    // Concrete decorators will be implemented in GDScript or subclasses.
};

#endif // MACHI_BT_DECORATOR_H
