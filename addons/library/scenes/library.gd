@tool
extends MarginContainer

@onready var search_edit: LineEdit = $VBoxContainer/HBoxContainer/SearchEdit
@onready var content_box: VBoxContainer = $VBoxContainer/ScrollContainer/Content

const ASSET_CARD_SCENE = "res://addons/library/scenes/components/asset_card.tscn"
var AssetCardScene: PackedScene

var _all_assets: Array[String] = []

# C++ Backend Scanner
var _scanner: CoreLibrary 

func _ready() -> void:
	# Initialize C++ Backend
	_scanner = CoreLibrary.new()
	
	AssetCardScene = load(ASSET_CARD_SCENE)
	
	if search_edit:
		search_edit.text_changed.connect(_on_search_text_changed)
	
	refresh_assets()

func _exit_tree():
	if _scanner:
		_scanner.free()

func refresh_assets() -> void:
	if not _scanner: return
	
	# Use C++ Scanner!
	var result = _scanner.scan_project("res://")
	
	# Convert TypedArray to Array[String]
	_all_assets.clear()
	for path in result:
		_all_assets.append(path)
		
	_update_grid()

func _update_grid(filter: String = "") -> void:
	if not content_box:
		return
	
	for child in content_box.get_children():
		child.queue_free()
	
	# Buckets: Group -> Array[Resource]
	var grouped_assets: Dictionary = {} # "Group Name" -> [Resource]
	var ungrouped_assets: Dictionary = {} # "Folder Name" -> [Resource] (fallback)
	var linked_paths: Dictionary = {}
	
	var editor_theme = EditorInterface.get_editor_theme()
	var fallback_icon = editor_theme.get_icon("Object", "EditorIcons")
	
	# Access Service
	var service = get_node_or_null("/root/LibraryService")
	
	# 1. Load and Classify
	var loaded_resources: Array[Resource] = []
	
	for path in _all_assets:
		if not filter.is_empty() and not (filter.to_lower() in path.get_file().to_lower()):
			continue
			
		var res = load(path)
		if not res: continue
		loaded_resources.append(res)
		
		# Allow resources to declare their dependencies to hide them (like linked states)
		# NOTE: This part was hardcoded for "Compose". Ideally Compose should implement a "get_hidden_dependencies" method?
		# For now, I'll keep the specialized logic but make it safe.
		if res.has_method("get_linked_states"): 
			# Hypothetical method, or check properties dynamically if we want to be generic.
			# But since "Compose" is just a Resource, we inspect properties.
			# To stay JEI-compliant, we shouldn't hardcode "Compose" logic here technically,
			# but hiding children is a UI behavior.
			# Let's check typical fields if they exist.
			var moves = res.get("move_states")
			if moves: for s in moves: if s: linked_paths[s.resource_path] = true
			var attacks = res.get("attack_states")
			if attacks: for s in attacks: if s: linked_paths[s.resource_path] = true
			var interact = res.get("interactive_states")
			if interact: for s in interact: if s: linked_paths[s.resource_path] = true
	
	# 2. Group
	for res in loaded_resources:
		# check if hidden
		if linked_paths.has(res.resource_path):
			continue
			
		var type = _get_resource_type_name(res)
		var group = ""
		
		if service:
			group = service.get_group(type)
		
		if not group.is_empty():
			if not grouped_assets.has(group): grouped_assets[group] = []
			grouped_assets[group].append(res)
		else:
			# Fallback: Group by Folder
			var dir = res.resource_path.get_base_dir().replace("res://", "")
			if not ungrouped_assets.has(dir): ungrouped_assets[dir] = []
			ungrouped_assets[dir].append(res)
	
	# 3. Create Sections (Registered Groups First)
	for group_name in grouped_assets.keys():
		_create_section(group_name, grouped_assets[group_name], fallback_icon, service)
		
	# 4. Create Sections (Folders)
	for dir_name in ungrouped_assets.keys():
		if not ungrouped_assets[dir_name].is_empty():
			_create_section("Folder: " + dir_name, ungrouped_assets[dir_name], fallback_icon, service)

func _create_section(title: String, assets: Array, fallback_icon: Texture2D, service: Node) -> void:
	var section = VBoxContainer.new()
	content_box.add_child(section)
	
	var label = Label.new()
	label.text = title
	label.add_theme_font_size_override("font_size", 16)
	label.add_theme_color_override("font_color", Color("#a0aec0"))
	section.add_child(label)
	
	var grid = HFlowContainer.new()
	grid.size_flags_horizontal = Control.SIZE_EXPAND_FILL
	grid.add_theme_constant_override("h_separation", 16)
	grid.add_theme_constant_override("v_separation", 16)
	section.add_child(grid)
	
	for res in assets:
		var card = AssetCardScene.instantiate()
		grid.add_child(card)
		
		var type = _get_resource_type_name(res)
		var icon = fallback_icon
		if service:
			var registered_icon = service.get_icon(type)
			if registered_icon:
				icon = registered_icon
		
		card.setup(res.resource_path, icon)
		card.clicked.connect(_on_card_clicked)
		card.activated.connect(_on_card_activated)

func _on_search_text_changed(new_text: String) -> void:
	_update_grid(new_text)

func _on_card_activated(path: String) -> void:
	EditorInterface.edit_resource(load(path))

func _on_card_clicked(path: String, btn: int) -> void:
	if btn == MOUSE_BUTTON_RIGHT:
		EditorInterface.edit_resource(load(path))
	elif btn == MOUSE_BUTTON_LEFT:
		EditorInterface.inspect_object(load(path))

func _on_refresh_pressed() -> void:
	refresh_assets()

func _on_new_pressed() -> void:
	print("New resource dialog TODO")

func _get_resource_type_name(res: Resource) -> String:
	var script = res.get_script()
	if script:
		var class_name_str = script.get_global_name()
		if not class_name_str.is_empty():
			return class_name_str
	return res.get_class()

