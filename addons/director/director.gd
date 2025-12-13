@tool
extends EditorPlugin

const AUTOLOAD_NAME = "Director"
const AUTOLOAD_PATH = "res://addons/director/director_autoload.gd"

func _enter_tree() -> void:
	add_autoload_singleton(AUTOLOAD_NAME, AUTOLOAD_PATH)
	print_rich("[color=indigo]Director Sequencer Activated![/color]")

func _exit_tree() -> void:
	remove_autoload_singleton(AUTOLOAD_NAME)
