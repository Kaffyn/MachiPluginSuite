#ifndef MACHI_BT_TASK_H
#define MACHI_BT_TASK_H

#include "machi_bt_node.h"

class MachiBTTask : public MachiBTNode {
	GDCLASS(MachiBTTask, MachiBTNode);

protected:
	static void _bind_methods();

public:
    // Tasks are leaf nodes. Override tick in GDScript or subclass.
};

#endif // MACHI_BT_TASK_H
