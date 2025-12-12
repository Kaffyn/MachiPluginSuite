#ifndef QUEST_JOURNAL_H
#define QUEST_JOURNAL_H

#include <godot_cpp/classes/node.hpp>

using namespace godot;

class QuestJournal : public Node {
	GDCLASS(QuestJournal, Node);

protected:
	static void _bind_methods();

public:
	QuestJournal();
	~QuestJournal();

    void start_quest(String p_quest_id);
};

#endif // QUEST_JOURNAL_H
