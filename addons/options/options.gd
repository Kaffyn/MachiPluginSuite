@tool
extends EditorPlugin

const AUTOLOAD_NAME = "Options"
const AUTOLOAD_PATH = "res://addons/options/options_autoload.gd"

func _enter_tree() -> void:
	add_autoload_singleton(AUTOLOAD_NAME, AUTOLOAD_PATH)
	print_rich("[color=zinc]Options Manager Activated![/color]")

func _exit_tree() -> void:
	remove_autoload_singleton(AUTOLOAD_NAME)
