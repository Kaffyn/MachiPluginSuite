#include "option_widget.h"

using namespace godot;

void OptionWidget::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_setting_name", "setting_name"), &OptionWidget::set_setting_name);
    ClassDB::bind_method(D_METHOD("get_setting_name"), &OptionWidget::get_setting_name);

    ADD_PROPERTY(PropertyInfo(Variant::STRING, "setting_name"), "set_setting_name", "get_setting_name");
}

OptionWidget::OptionWidget() {
}

OptionWidget::~OptionWidget() {
}

void OptionWidget::set_setting_name(String p_name) {
    setting_name = p_name;
}

String OptionWidget::get_setting_name() const {
    return setting_name;
}
