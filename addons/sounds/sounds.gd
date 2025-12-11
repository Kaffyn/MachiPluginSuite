@tool
extends EditorPlugin

func _enter_tree() -> void:
	# Check if the singleton is already present to avoid errors (good practice)
	if not ProjectSettings.has_setting("autoload/Sounds"):
		add_autoload_singleton("Sounds", "res://addons/sounds/autoload/sound_manager.gd")

func _exit_tree() -> void:
	remove_autoload_singleton("Sounds")
