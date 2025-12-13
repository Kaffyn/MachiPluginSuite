@tool
extends EditorPlugin

const AUTOLOAD_NAME = "Osmo"
const AUTOLOAD_PATH = "res://addons/osmo/osmo_autoload.gd"

func _enter_tree() -> void:
	add_autoload_singleton(AUTOLOAD_NAME, AUTOLOAD_PATH)
	print_rich("[color=rose]Osmo Camera System Activated![/color]")

func _exit_tree() -> void:
	remove_autoload_singleton(AUTOLOAD_NAME)
