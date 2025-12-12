@tool
extends EditorPlugin

const PANEL_SCENE = preload("res://addons/library_core/scenes/panel.tscn")
var panel_instance

func _enter_tree():
	# Load the full Library Core Panel (Library C++, Editor, Factory)
	panel_instance = PANEL_SCENE.instantiate()
	add_control_to_bottom_panel(panel_instance, "Core")

func _exit_tree():
	if panel_instance:
		remove_control_from_bottom_panel(panel_instance)
		panel_instance.queue_free()
