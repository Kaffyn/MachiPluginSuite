#ifndef CORE_LIBRARY_H
#define CORE_LIBRARY_H

#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/label.hpp>

using namespace godot;

class CoreLibrary : public Control {
	GDCLASS(CoreLibrary, Control);

private:
    Label *status_label;

protected:
	static void _bind_methods();
    void _notification(int p_what);

public:
	CoreLibrary();
	~CoreLibrary();
};

#endif // CORE_LIBRARY_H
