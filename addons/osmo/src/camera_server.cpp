#include "camera_server.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void CameraServer::_bind_methods() {
    ClassDB::bind_method(D_METHOD("register_camera", "camera"), &CameraServer::register_camera);
}

CameraServer::CameraServer() {
}

CameraServer::~CameraServer() {
}

void CameraServer::register_camera(Node* p_camera) {
    // TODO: Implement registration logic
}
