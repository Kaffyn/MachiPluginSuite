@tool
extends EditorPlugin

const AUTOLOAD_NAME = "Memento"
const AUTOLOAD_PATH = "res://addons/memento/memento_autoload.gd"

func _enter_tree() -> void:
	add_autoload_singleton(AUTOLOAD_NAME, AUTOLOAD_PATH)
	print_rich("[color=slate]Memento Save System Activated![/color]")

func _exit_tree() -> void:
	remove_autoload_singleton(AUTOLOAD_NAME)
