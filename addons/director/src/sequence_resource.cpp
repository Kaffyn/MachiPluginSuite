#include "sequence_resource.h"

using namespace godot;

void SequenceResource::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_tracks", "tracks"), &SequenceResource::set_tracks);
    ClassDB::bind_method(D_METHOD("get_tracks"), &SequenceResource::get_tracks);

    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "tracks", PROPERTY_HINT_RESOURCE_TYPE, "Resource"), "set_tracks", "get_tracks");
}

SequenceResource::SequenceResource() {
}

SequenceResource::~SequenceResource() {
}

void SequenceResource::set_tracks(TypedArray<Resource> p_tracks) {
    tracks = p_tracks;
}

TypedArray<Resource> SequenceResource::get_tracks() const {
    return tracks;
}
