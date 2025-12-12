#ifndef CAMERA_SERVER_H
#define CAMERA_SERVER_H

#include <godot_cpp/classes/node.hpp>

using namespace godot;

class CameraServer : public Node {
	GDCLASS(CameraServer, Node);

protected:
	static void _bind_methods();

public:
	CameraServer();
	~CameraServer();

    void register_camera(Node* p_camera);
};

#endif // CAMERA_SERVER_H
