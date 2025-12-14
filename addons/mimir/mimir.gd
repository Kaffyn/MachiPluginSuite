@tool
extends EditorPlugin

const AUTOLOAD_NAME = "Mimir"
const AUTOLOAD_PATH = "res://addons/mimir/mimir_autoload.gd"

func _enter_tree() -> void:
	add_autoload_singleton(AUTOLOAD_NAME, AUTOLOAD_PATH)
	print_rich("[color=slate]Mimir Save System Activated![/color]")

func _exit_tree() -> void:
	remove_autoload_singleton(AUTOLOAD_NAME)
