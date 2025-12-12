#include "save_profile.h"

using namespace godot;

void SaveProfile::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_metadata", "metadata"), &SaveProfile::set_metadata);
    ClassDB::bind_method(D_METHOD("get_metadata"), &SaveProfile::get_metadata);

    ADD_PROPERTY(PropertyInfo(Variant::DICTIONARY, "metadata"), "set_metadata", "get_metadata");
}

SaveProfile::SaveProfile() {
}

SaveProfile::~SaveProfile() {
}

void SaveProfile::set_metadata(Dictionary p_metadata) {
    metadata = p_metadata;
}

Dictionary SaveProfile::get_metadata() const {
    return metadata;
}
