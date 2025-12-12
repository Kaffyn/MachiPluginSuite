#include "quest_resource.h"

using namespace godot;

void QuestResource::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_quest_id", "quest_id"), &QuestResource::set_quest_id);
    ClassDB::bind_method(D_METHOD("get_quest_id"), &QuestResource::get_quest_id);
    ClassDB::bind_method(D_METHOD("set_title", "title"), &QuestResource::set_title);
    ClassDB::bind_method(D_METHOD("get_title"), &QuestResource::get_title);
    ClassDB::bind_method(D_METHOD("set_description", "description"), &QuestResource::set_description);
    ClassDB::bind_method(D_METHOD("get_description"), &QuestResource::get_description);

    ADD_PROPERTY(PropertyInfo(Variant::STRING, "quest_id"), "set_quest_id", "get_quest_id");
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "title"), "set_title", "get_title");
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "description", "set_description", "get_description");
}

QuestResource::QuestResource() {
}

QuestResource::~QuestResource() {
}

void QuestResource::set_quest_id(String p_id) {
    quest_id = p_id;
}

String QuestResource::get_quest_id() const {
    return quest_id;
}

void QuestResource::set_title(String p_title) {
    title = p_title;
}

String QuestResource::get_title() const {
    return title;
}

void QuestResource::set_description(String p_description) {
    description = p_description;
}

String QuestResource::get_description() const {
    return description;
}
