@tool
extends EditorPlugin

# ==================== NODES ====================
const ABILITY_SYSTEM_COMPONENT = preload("res://addons/ability_system/nodes/ability_system_component.gd")
const ABILITY_SYSTEM_ICON = preload("res://addons/ability_system/assets/icons/machine.svg") 

# ==================== RESOURCES ====================
const STATE_SCRIPT = preload("res://addons/ability_system/resources/state.gd")
const STATE_ICON = preload("res://addons/ability_system/assets/icons/state.svg")

const COMPOSE_SCRIPT = preload("res://addons/ability_system/resources/compose.gd")
const COMPOSE_ICON = preload("res://addons/ability_system/assets/icons/compose.svg")

const SKILL_SCRIPT = preload("res://addons/ability_system/resources/skill.gd")
const SKILL_ICON = preload("res://addons/ability_system/assets/icons/skill.svg")

const SKILL_TREE_SCRIPT = preload("res://addons/ability_system/resources/skilltree.gd")
const SKILL_TREE_ICON = preload("res://addons/ability_system/assets/icons/skill.svg")

# ==================== SINGLETONS ====================
const AUTOLOAD_NAME = "AbilitySystem"

func _enter_tree() -> void:
	# Register Custom Types
	add_custom_type("AbilitySystemComponent", "Node", ABILITY_SYSTEM_COMPONENT, ABILITY_SYSTEM_ICON)
	
	add_custom_type("State", "Resource", STATE_SCRIPT, STATE_ICON)
	add_custom_type("Compose", "Resource", COMPOSE_SCRIPT, COMPOSE_ICON)
	add_custom_type("Skill", "Resource", SKILL_SCRIPT, SKILL_ICON)
	add_custom_type("SkillTree", "Resource", SKILL_TREE_SCRIPT, SKILL_TREE_ICON)
	
	# Register with Library Service (JEI Pattern)
	# Check if LibraryService exists (it might not if library is disabled)
	if Engine.has_singleton("LibraryService") or DisplayServer.get_name() != "headless": 
		# Note: In Editor, Autoloads are available as globally named nodes if tool is active.
		# Safe access pattern via implicit name if it works, or check root.
		# Ideally, we assume LibraryService is active if Core is active.
		var service = get_node_or_null("/root/LibraryService")
		if service:
			service.register_resource("State", STATE_ICON, "Behavior")
			service.register_resource("Compose", COMPOSE_ICON, "Behavior")
			service.register_resource("Skill", SKILL_ICON, "Systems")
			service.register_resource("SkillTree", SKILL_TREE_ICON, "Systems")
			service.register_resource("AbilitySystemConfig", ABILITY_SYSTEM_ICON, "Systems")
			service.register_resource("CharacterSheet", ABILITY_SYSTEM_ICON, "Systems")
	
	print_rich("[color=green]Ability System (GAS) v2.0 Activated![/color]")

func _exit_tree() -> void:
	# Remove Custom Types
	remove_custom_type("AbilitySystemComponent")
	remove_custom_type("State")
	remove_custom_type("Compose")
	remove_custom_type("Skill")
	remove_custom_type("SkillTree")
	
	print_rich("[color=yellow]Ability System Deactivated.[/color]")
