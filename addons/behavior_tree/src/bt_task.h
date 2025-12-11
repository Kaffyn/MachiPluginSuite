#ifndef BT_TASK_H
#define BT_TASK_H

#include "bt_node.h"

class BTTask : public BTNode {
	GDCLASS(BTTask, BTNode);

protected:
	static void _bind_methods();

public:
    // Tasks are leaf nodes. Override tick in GDScript or subclass.
};

#endif // BT_TASK_H
