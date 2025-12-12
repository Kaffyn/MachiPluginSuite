#ifndef OPTION_WIDGET_H
#define OPTION_WIDGET_H

#include <godot_cpp/classes/control.hpp>

using namespace godot;

class OptionWidget : public Control {
	GDCLASS(OptionWidget, Control);

protected:
	static void _bind_methods();

public:
	OptionWidget();
	~OptionWidget();

    void set_setting_name(String p_name);
    String get_setting_name() const;

private:
    String setting_name;
};

#endif // OPTION_WIDGET_H
