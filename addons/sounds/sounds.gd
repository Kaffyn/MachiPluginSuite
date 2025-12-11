@tool
extends EditorPlugin

func _enter_tree() -> void:
	# Register the C++ Singleton as an Autoload (if desired)
	# For now, we just ensure the plugin loads without error.
	# Users can access MachiSoundManager directly or we can add an autoload here later.
	pass

func _exit_tree() -> void:
	pass
