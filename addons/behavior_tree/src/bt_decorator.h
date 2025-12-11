#ifndef BT_DECORATOR_H
#define BT_DECORATOR_H

#include "bt_node.h"

class BTDecorator : public BTNode {
	GDCLASS(BTDecorator, BTNode);

private:
    Ref<BTNode> child;

protected:
	static void _bind_methods();

public:
    void set_child(const Ref<BTNode> &p_child);
    Ref<BTNode> get_child() const;

    virtual void reset() override;
};

#endif // BT_DECORATOR_H
