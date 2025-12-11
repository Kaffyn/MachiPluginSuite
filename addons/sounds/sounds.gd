@tool
extends EditorPlugin

func _enter_tree():
	add_autoload_singleton("SoundManager", "res://addons/sounds/sounds_autoload.gd")

func _exit_tree():
	remove_autoload_singleton("SoundManager")
