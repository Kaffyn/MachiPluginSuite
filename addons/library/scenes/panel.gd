@tool
## Painel Principal do Library Core.
##
## Gerencia as abas: Library (Hybrid), Editor, Factory.
class_name CorePanel extends Control

const LIBRARY_SCENE = preload("res://addons/library/scenes/library.tscn")
var config

func _ready() -> void:
	# 1. Add Library Tab (GDScript UI + C++ Backend)
	var library = LIBRARY_SCENE.instantiate()
	library.name = "Library"
	var tabs = $MarginContainer/TabContainer
	if tabs:
		tabs.add_child(library)
		tabs.move_child(library, 0) # Ensure it's first
		tabs.current_tab = 0

	_load_config()

func _load_config() -> void:
	var config_path = "res://addons/ability_system/data/config.tres"
	if ResourceLoader.exists(config_path):
		config = load(config_path)

func _switch_to_editor_with_resource(path: String) -> void:
	var tab_container = $MarginContainer/TabContainer
	if tab_container:
		tab_container.current_tab = 1
		var editor = tab_container.get_child(1)
		if editor and editor.has_method("load_resource_from_library"):
			editor.load_resource_from_library(path)
