#ifndef QUEST_NODE_H
#define QUEST_NODE_H

#include <godot_cpp/classes/node.hpp>

using namespace godot;

class QuestNode : public Node {
	GDCLASS(QuestNode, Node);

protected:
	static void _bind_methods();

public:
	QuestNode();
	~QuestNode();
};

#endif // QUEST_NODE_H
