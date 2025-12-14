@tool
extends EditorPlugin

# ------------------------------------------------------------------------------
# Constants
# ------------------------------------------------------------------------------
const AUTOLOAD_NAME = "Yggdrasil"
const AUTOLOAD_PATH = "res://addons/yggdrasil/yggdrasil_autoload.gd"

# ------------------------------------------------------------------------------
# Built-in Methods
# ------------------------------------------------------------------------------
func _enter_tree() -> void:
	add_autoload_singleton(AUTOLOAD_NAME, AUTOLOAD_PATH)

func _exit_tree() -> void:
	remove_autoload_singleton(AUTOLOAD_NAME)
