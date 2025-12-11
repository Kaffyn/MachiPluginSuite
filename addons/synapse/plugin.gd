@tool
extends EditorPlugin

func _enter_tree() -> void:
    # GDExtension handles singleton registration via C++, but we might want to do extra editor setup here
    pass

func _exit_tree() -> void:
    pass
