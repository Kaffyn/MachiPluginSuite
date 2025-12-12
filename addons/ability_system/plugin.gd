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
	
	print_rich("[color=green]Ability System (GAS) v2.0 Activated![/color]")

func _exit_tree() -> void:
	# Remove Custom Types
	remove_custom_type("AbilitySystemComponent")
	remove_custom_type("State")
	remove_custom_type("Compose")
	remove_custom_type("Skill")
	remove_custom_type("SkillTree")
	
	print_rich("[color=yellow]Ability System Deactivated.[/color]")
