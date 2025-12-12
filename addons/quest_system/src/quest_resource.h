#ifndef QUEST_RESOURCE_H
#define QUEST_RESOURCE_H

#include <godot_cpp/classes/resource.hpp>

using namespace godot;

class QuestResource : public Resource {
	GDCLASS(QuestResource, Resource);

protected:
	static void _bind_methods();

public:
	QuestResource();
	~QuestResource();
};

#endif // QUEST_RESOURCE_H
