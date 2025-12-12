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
};

#endif // OPTION_WIDGET_H
