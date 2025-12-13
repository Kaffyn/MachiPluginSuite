#include "camera_server.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

#include "osmo_camera_2d.h"
#include "osmo_camera_3d.h"
#include <godot_cpp/variant/utility_functions.hpp>

void OsmoServer::_bind_methods() {
    ClassDB::bind_method(D_METHOD("register_camera", "camera"), &OsmoServer::register_camera);
}

OsmoServer::OsmoServer() {
}

OsmoServer::~OsmoServer() {
}

void OsmoServer::register_camera(Node* p_camera) {
    if (Object::cast_to<OsmoCamera2D>(p_camera)) {
        UtilityFunctions::print("OsmoServer: Registered 2D Camera: ", p_camera->get_name());
    } else if (Object::cast_to<OsmoCamera3D>(p_camera)) {
        UtilityFunctions::print("OsmoServer: Registered 3D Camera: ", p_camera->get_name());
    } else {
        UtilityFunctions::print("OsmoServer: Unknown camera type registered.");
    }
}
