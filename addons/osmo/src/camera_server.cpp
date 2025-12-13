#include "camera_server.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void OsmoServer::_bind_methods() {
    ClassDB::bind_method(D_METHOD("register_camera", "camera"), &OsmoServer::register_camera);
}

OsmoServer::OsmoServer() {
}

OsmoServer::~OsmoServer() {
}

void OsmoServer::register_camera(Node* p_camera) {
    // TODO: Implement registration logic
}
