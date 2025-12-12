@tool
extends EditorPlugin

const AUTOLOAD_NAME = "Gaia"
const AUTOLOAD_PATH = "res://addons/gaia/gaia_autoload.gd"

func _enter_tree() -> void:
	add_autoload_singleton(AUTOLOAD_NAME, AUTOLOAD_PATH)
	print_rich("[color=green]Gaia Environment Activated![/color]")

func _exit_tree() -> void:
	remove_autoload_singleton(AUTOLOAD_NAME)
