@tool
extends EditorPlugin

var library_instance: CoreLibrary

func _enter_tree():
	# Core Library Initialization (Full C++)
	library_instance = CoreLibrary.new()
	library_instance.name = "Library"
	add_control_to_bottom_panel(library_instance, "Library")

func _exit_tree():
	if library_instance:
		remove_control_from_bottom_panel(library_instance)
		library_instance.free()
