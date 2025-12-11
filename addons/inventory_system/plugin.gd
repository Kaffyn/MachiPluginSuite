@tool
extends EditorPlugin

func _enter_tree() -> void:
	# Register Custom Types
	# Note: class_name in GDScript usually suffices for global access, 
	# but add_custom_type allows them to appear in the Create New Node dialog more explicitly.
	# For Resources (Item, Inventory), class_name is definitely enough.
	# For Nodes (Backpack, Slot), we might want them in the node list.
	
	add_custom_type("Backpack", "Control", preload("nodes/backpack.gd"), preload("res://addons/inventory_system/assets/icons/backpack.svg") if FileAccess.file_exists("res://addons/inventory_system/assets/icons/backpack.svg") else null)
	add_custom_type("Slot", "Panel", preload("nodes/slot.gd"), null)

func _exit_tree() -> void:
	# Clean up
	remove_custom_type("Backpack")
	remove_custom_type("Slot")
