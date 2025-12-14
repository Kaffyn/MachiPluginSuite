#include "save_interface.h"

using namespace godot;

void SaveInterface::_bind_methods() {
    ClassDB::bind_method(D_METHOD("serialize"), &SaveInterface::serialize);
    ClassDB::bind_method(D_METHOD("deserialize", "data"), &SaveInterface::deserialize);
}

SaveInterface::SaveInterface() {
}

SaveInterface::~SaveInterface() {
}

Dictionary SaveInterface::serialize() {
    return Dictionary();
}

void SaveInterface::deserialize(Dictionary p_data) {
    // TODO: Implement deserialization logic
}
