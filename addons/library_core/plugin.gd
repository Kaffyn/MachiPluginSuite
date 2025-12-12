@tool
extends EditorPlugin

const PANEL_SCENE = preload("res://addons/library_core/scenes/panel.tscn")
var panel_instance

const AUTOLOAD_NAME = "LibraryService"

func _enter_tree():
	# Register Service Singleton
	add_autoload_singleton(AUTOLOAD_NAME, "res://addons/library_core/library_service.gd")
	
	# Load the full Library Core Panel (Library C++, Editor, Factory)
	panel_instance = PANEL_SCENE.instantiate()
	add_control_to_bottom_panel(panel_instance, "Library")

func _exit_tree():
	if panel_instance:
		remove_control_from_bottom_panel(panel_instance)
		panel_instance.queue_free()
	
	remove_autoload_singleton(AUTOLOAD_NAME)
