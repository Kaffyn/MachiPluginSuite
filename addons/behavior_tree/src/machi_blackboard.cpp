#include "machi_blackboard.h"

void MachiBlackboard::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_value", "key", "value"), &MachiBlackboard::set_value);
	ClassDB::bind_method(D_METHOD("get_value", "key", "default"), &MachiBlackboard::get_value, DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("has_value", "key"), &MachiBlackboard::has_value);
	ClassDB::bind_method(D_METHOD("erase_value", "key"), &MachiBlackboard::erase_value);
	ClassDB::bind_method(D_METHOD("clear"), &MachiBlackboard::clear);
    
    ClassDB::bind_method(D_METHOD("get_data"), &MachiBlackboard::get_data);
	ClassDB::bind_method(D_METHOD("set_data", "data"), &MachiBlackboard::set_data);

    ADD_PROPERTY(PropertyInfo(Variant::DICTIONARY, "data"), "set_data", "get_data");
}

void MachiBlackboard::set_value(const String &p_key, const Variant &p_value) {
	data[p_key] = p_value;
}

Variant MachiBlackboard::get_value(const String &p_key, const Variant &p_default) const {
	if (data.has(p_key)) {
		return data[p_key];
	}
	return p_default;
}

bool MachiBlackboard::has_value(const String &p_key) const {
	return data.has(p_key);
}

void MachiBlackboard::erase_value(const String &p_key) {
	data.erase(p_key);
}

void MachiBlackboard::clear() {
    data.clear();
}

Dictionary MachiBlackboard::get_data() const {
    return data;
}

void MachiBlackboard::set_data(const Dictionary &p_data) {
    data = p_data;
}
