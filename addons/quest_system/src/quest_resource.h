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

    void set_quest_id(String p_id);
    String get_quest_id() const;

    void set_title(String p_title);
    String get_title() const;

    void set_description(String p_description);
    String get_description() const;

private:
    String quest_id;
    String title;
    String description;
};

#endif // QUEST_RESOURCE_H
