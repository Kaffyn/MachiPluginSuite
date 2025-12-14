#include "machi_gaia.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

MachiGaia *MachiGaia::singleton = nullptr;

MachiGaia::MachiGaia() {
	singleton = this;
}

MachiGaia::~MachiGaia() {
	if (singleton == this) {
		singleton = nullptr;
	}
}

MachiGaia *MachiGaia::get_singleton() {
	return singleton;
}

void MachiGaia::set_time(float p_time) {
    current_time = p_time;
    _update_environment();
}

float MachiGaia::get_time() const {
    return current_time;
}

void MachiGaia::set_weather(String type) {
    UtilityFunctions::print("[Gaia] Changing weather to: ", type);
    // TODO: Emit signal or call WeatherController
}

void MachiGaia::register_sky(Node *p_world_env) {
    world_env = p_world_env;
    UtilityFunctions::print("[Gaia] Sky registered.");
}

void MachiGaia::register_sun(Node *p_directional_light) {
    sun_light = p_directional_light;
    UtilityFunctions::print("[Gaia] Sun registered.");
}

void MachiGaia::_update_environment() {
    if (sun_light) {
        double hours = current_time;
        double angle = (hours / 24.0) * 360.0 - 90.0;
        sun_light->call("set_rotation_degrees", Vector3(angle, -90.0, 0.0));
    }
}

void MachiGaia::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_time"), &MachiGaia::get_time);
    ClassDB::bind_method(D_METHOD("set_time", "p_time"), &MachiGaia::set_time);
    ClassDB::bind_method(D_METHOD("set_weather", "type"), &MachiGaia::set_weather);
    
    ClassDB::bind_method(D_METHOD("register_sky", "p_world_env"), &MachiGaia::register_sky);
    ClassDB::bind_method(D_METHOD("register_sun", "p_directional_light"), &MachiGaia::register_sun);
    
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "time"), "set_time", "get_time");
}
