@tool
extends EditorPlugin

var main_panel_instance


# ==================== CONSTANTS ====================
const TRANSLATION_PATH = "res://addons/ability_system/assets/translations/"

# ==================== NODES ====================
const ABILITY_SYSTEM_COMPONENT = preload("res://addons/ability_system/nodes/ability_system_component.gd")
const ABILITY_SYSTEM_ICON = preload("res://addons/ability_system/assets/icons/machine.svg") # Use machine icon for now

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
const AUTOLOAD_NAME = "AbilitySystem" # Was BehaviorStates

# ==================== EDITOR UI ====================
const BOTTOM_PANEL = preload("res://addons/ability_system/scenes/panel.tscn")
var bottom_panel_instance: Control

func _enter_tree() -> void:
	# 1. Add Autoload (Global Singleton)
	# add_autoload_singleton(AUTOLOAD_NAME, "res://addons/ability_system/ability_system_enums.gd")
	# Using enums file as singleton might not be best, but mimicking previous behavior if it was doing that.
	# The previous code seemed to reference specific paths.
	
	# 2. Register Custom Types
	add_custom_type("AbilitySystemComponent", "Node", ABILITY_SYSTEM_COMPONENT, ABILITY_SYSTEM_ICON)
	
	add_custom_type("State", "Resource", STATE_SCRIPT, STATE_ICON)
	add_custom_type("Compose", "Resource", COMPOSE_SCRIPT, COMPOSE_ICON)
	add_custom_type("Skill", "Resource", SKILL_SCRIPT, SKILL_ICON)
	add_custom_type("SkillTree", "Resource", SKILL_TREE_SCRIPT, SKILL_TREE_ICON)
	
	# 3. Add Translations
	_add_translations()
	
	# 4. Add Bottom Panel
	bottom_panel_instance = BOTTOM_PANEL.instantiate()
	add_control_to_bottom_panel(bottom_panel_instance, "Ability System")
	
	print_rich("[color=green]Ability System (GAS) v2.0 Activated![/color]")

func _exit_tree() -> void:
	# 1. Remove Bottom Panel
	if bottom_panel_instance:
		remove_control_from_bottom_panel(bottom_panel_instance)
		bottom_panel_instance.queue_free()
	
	# 2. Remove Custom Types
	remove_custom_type("AbilitySystemComponent")
	remove_custom_type("State")
	remove_custom_type("Compose")
	remove_custom_type("Skill")
	remove_custom_type("SkillTree")
	
	# 3. Remove Translations
	_remove_translations()
	
	# 4. Remove Autoload
	# remove_autoload_singleton(AUTOLOAD_NAME)
	
	print_rich("[color=yellow]Ability System Deactivated.[/color]")

func _add_translations() -> void:
	var files = [
		"en_US.po",
		"es_LA.po",
		"pt_BR.po"
	]
	
	for file in files:
		var translation = load(TRANSLATION_PATH + file)
		if translation:
			TranslationServer.add_translation(translation)

func _remove_translations() -> void:
	var files = [
		"en_US.po",
		"es_LA.po",
		"pt_BR.po"
	]
	
	for file in files:
		var translation = load(TRANSLATION_PATH + file)
		if translation:
			TranslationServer.remove_translation(translation)
