@tool
## O Painel do Editor (Bottom Panel Integration).
##
## Fornece a interface visual (Library, Editor, Factory, Debugger, Grimório) para o BehaviorStates.
class_name AbilitySystemPanel extends Control

var config: AbilitySystemConfig

func _ready() -> void:
	_load_config()

func _load_config() -> void:
	var config_path = "res://addons/ability_system/data/config.tres"
	if ResourceLoader.exists(config_path):
		config = load(config_path)
	if not config:
		# If class_name AbilitySystemConfig is not available yet, this might fail unless we update Config resource script first.
		# Assuming we rename BehaviorStatesConfig to AbilitySystemConfig.
		# For now, let's just use Resource or check.
		pass # config = AbilitySystemConfig.new()

func _switch_to_editor_with_resource(path: String) -> void:
	# Find TabContainer and switch to Editor tab (index 1)
	var tab_container = $MarginContainer/TabContainer
	if tab_container:
		tab_container.current_tab = 1  # Editor is index 1
		
		# Get Editor tab and load resource
		var editor = tab_container.get_child(1)
		if editor and editor.has_method("load_resource_from_library"):
			editor.load_resource_from_library(path)
