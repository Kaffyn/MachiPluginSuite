#include "quest_journal.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void QuestJournal::_bind_methods() {
    ClassDB::bind_method(D_METHOD("start_quest", "quest_id"), &QuestJournal::start_quest);
}

QuestJournal::QuestJournal() {
}

QuestJournal::~QuestJournal() {
}

void QuestJournal::start_quest(String p_quest_id) {
    // TODO: Implement start quest logic
}
