#include "blackboard.h"

void Blackboard::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_value", "key", "value"), &Blackboard::set_value);
	ClassDB::bind_method(D_METHOD("get_value", "key", "default"), &Blackboard::get_value, DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("has_value", "key"), &Blackboard::has_value);
	ClassDB::bind_method(D_METHOD("erase_value", "key"), &Blackboard::erase_value);
	ClassDB::bind_method(D_METHOD("clear"), &Blackboard::clear);
    
    ClassDB::bind_method(D_METHOD("get_data"), &Blackboard::get_data);
	ClassDB::bind_method(D_METHOD("set_data", "data"), &Blackboard::set_data);

    ADD_PROPERTY(PropertyInfo(Variant::DICTIONARY, "data"), "set_data", "get_data");
}

void Blackboard::set_value(const String &p_key, const Variant &p_value) {
	data[p_key] = p_value;
}

Variant Blackboard::get_value(const String &p_key, const Variant &p_default) const {
	if (data.has(p_key)) {
		return data[p_key];
	}
	return p_default;
}

bool Blackboard::has_value(const String &p_key) const {
	return data.has(p_key);
}

void Blackboard::erase_value(const String &p_key) {
	data.erase(p_key);
}

void Blackboard::clear() {
    data.clear();
}

Dictionary Blackboard::get_data() const {
    return data;
}

void Blackboard::set_data(const Dictionary &p_data) {
    data = p_data;
}
