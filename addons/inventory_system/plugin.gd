@tool
extends EditorPlugin

func _enter_tree() -> void:
	# Register Custom Types
	# Note: class_name in GDScript usually suffices for global access, 
	# but add_custom_type allows them to appear in the Create New Node dialog more explicitly.
	# For Resources (Item, Inventory), class_name is definitely enough.
	# For Nodes (Backpack, Slot), we might want them in the node list.
	
	add_custom_type("Backpack", "Control", preload("nodes/backpack.gd"), null)
	add_custom_type("Slot", "Panel", preload("nodes/slot.gd"), null)
	
	# Register with Library Service (JEI Pattern)
	if Engine.has_singleton("LibraryService") or DisplayServer.get_name() != "headless":
		var service = get_node_or_null("/root/LibraryService")
		if service:
			# Using icons from AbilitySystem for now (shared assets)
			var item_icon = load("res://addons/ability_system/assets/icons/item.svg")
			var inv_icon = load("res://addons/ability_system/assets/icons/inventory.svg")
			
			service.register_resource("Item", item_icon, "Inventory")
			service.register_resource("Inventory", inv_icon, "Inventory")
			print_rich("[color=cyan]Inventory System Registered with Library![/color]")

func _exit_tree() -> void:
	# Clean up
	remove_custom_type("Backpack")
	remove_custom_type("Slot")
