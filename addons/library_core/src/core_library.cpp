#include "core_library.h"

#include <godot_cpp/classes/dir_access.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/editor_interface.hpp>
#include <godot_cpp/classes/theme.hpp>
#include <godot_cpp/classes/style_box_flat.hpp>
#include <godot_cpp/classes/script.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

void CoreLibrary::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_on_search_text_changed", "new_text"), &CoreLibrary::_on_search_text_changed);
    ClassDB::bind_method(D_METHOD("_on_refresh_pressed"), &CoreLibrary::_on_refresh_pressed);
    ClassDB::bind_method(D_METHOD("_on_new_pressed"), &CoreLibrary::_on_new_pressed);
    ClassDB::bind_method(D_METHOD("_on_card_clicked", "path", "mouse_btn"), &CoreLibrary::_on_card_clicked);
    ClassDB::bind_method(D_METHOD("_on_card_activated", "path"), &CoreLibrary::_on_card_activated);
    
    ClassDB::bind_method(D_METHOD("refresh_assets"), &CoreLibrary::refresh_assets);
}

CoreLibrary::CoreLibrary() {
    // Constructor - minimize logic here, use NOTIFICATION_READY for heavy lifting
}

CoreLibrary::~CoreLibrary() {
}

void CoreLibrary::_notification(int p_what) {
    if (p_what == NOTIFICATION_READY) {
        _setup_ui();
        
        // Load Asset Card Scene
        // Note: Using the one we moved to library_core
        asset_card_scene = ResourceLoader::get_singleton()->load("res://addons/library_core/scenes/components/asset_card.tscn");
        
        _preload_icons();
        refresh_assets();
    }
}

void CoreLibrary::_setup_ui() {
    // Root formatting
    set_anchors_preset(PRESET_FULL_RECT);
    add_theme_constant_override("margin_top", 10);
    add_theme_constant_override("margin_left", 10);
    add_theme_constant_override("margin_right", 10);
    add_theme_constant_override("margin_bottom", 10);

    // VBox Container Main
    VBoxContainer *main_vbox = memnew(VBoxContainer);
    main_vbox->set_v_size_flags(SIZE_EXPAND_FILL);
    add_child(main_vbox);

    // Toolbar (HBox)
    HBoxContainer *toolbar = memnew(HBoxContainer);
    main_vbox->add_child(toolbar);

    // Search Edit
    search_edit = memnew(LineEdit);
    search_edit->set_h_size_flags(SIZE_EXPAND_FILL);
    search_edit->set_placeholder("Filtrar por nome...");
    search_edit->connect("text_changed", Callable(this, "_on_search_text_changed"));
    toolbar->add_child(search_edit);

    // New Button
    new_btn = memnew(Button);
    new_btn->set_text("+ Novo");
    new_btn->connect("pressed", Callable(this, "_on_new_pressed"));
    toolbar->add_child(new_btn);

    // Refresh Button
    refresh_btn = memnew(Button);
    refresh_btn->set_text("Refresh");
    refresh_btn->connect("pressed", Callable(this, "_on_refresh_pressed"));
    toolbar->add_child(refresh_btn);

    // Scroll Container
    ScrollContainer *scroll = memnew(ScrollContainer);
    scroll->set_v_size_flags(SIZE_EXPAND_FILL);
    scroll->set_horizontal_scroll_mode(ScrollContainer::SCROLL_MODE_DISABLED);
    main_vbox->add_child(scroll);

    // Content Box
    content_box = memnew(VBoxContainer);
    content_box->set_h_size_flags(SIZE_EXPAND_FILL);
    scroll->add_child(content_box);
}

void CoreLibrary::_preload_icons() {
    ResourceLoader *rl = ResourceLoader::get_singleton();
    if (rl->exists(ICON_STATE)) icon_cache["State"] = rl->load(ICON_STATE);
    if (rl->exists(ICON_COMPOSE)) icon_cache["Compose"] = rl->load(ICON_COMPOSE);
    if (rl->exists(ICON_ITEM)) icon_cache["Item"] = rl->load(ICON_ITEM);
    if (rl->exists(ICON_SKILL)) icon_cache["Skill"] = rl->load(ICON_SKILL);
    if (rl->exists(ICON_CHARACTER_SHEET)) icon_cache["CharacterSheet"] = rl->load(ICON_CHARACTER_SHEET);
    if (rl->exists(ICON_CONFIG)) icon_cache["AbilitySystemConfig"] = rl->load(ICON_CONFIG);
}

void CoreLibrary::refresh_assets() {
    all_assets.clear();
    _scan_directory("res://");
    _update_grid("");
}

void CoreLibrary::_scan_directory(String path) {
    Ref<DirAccess> dir = DirAccess::open(path);
    if (dir.is_valid()) {
        dir->list_dir_begin();
        String file_name = dir->get_next();
        while (file_name != "") {
            if (dir->current_is_dir()) {
                if (file_name != "." && file_name != ".." && file_name != ".godot") {
                    _scan_directory(path + "/" + file_name);
                }
            } else {
                if (file_name.ends_with(".tres")) {
                    all_assets.append(path + "/" + file_name);
                }
            }
            file_name = dir->get_next();
        }
    }
}

void CoreLibrary::_update_grid(String filter) {
    // Clear existing
    while (content_box->get_child_count() > 0) {
        Node *child = content_box->get_child(0);
        content_box->remove_child(child);
        child->queue_free();
    }

    // Bucket Logic
    TypedArray<Resource> system_assets;
    TypedArray<Resource> composes;
    Dictionary states; // path -> resource
    Dictionary linked_states;

    // Filter and Sort
    for (int i = 0; i < all_assets.size(); i++) {
        String path = all_assets[i];
        if (!filter.is_empty() && path.get_file().to_lower().find(filter.to_lower()) == -1) {
            continue;
        }

        Ref<Resource> res = ResourceLoader::get_singleton()->load(path);
        if (res.is_null()) continue;

        String type = _get_resource_type_name(res);

        if (type == "Compose") {
            composes.append(res);
            // Map links (simplified for C++ iteration)
            // Ideally we'd reflectively get properties, but for now trusting the logic
            Variant moves = res->get("move_states");
            if (moves.get_type() == Variant::ARRAY) {
                Array arr = moves;
                for (int j=0; j<arr.size(); j++) {
                    Ref<Resource> s = arr[j];
                    if (s.is_valid()) linked_states[s->get_path()] = true;
                }
            }
            Variant attacks = res->get("attack_states");
             if (attacks.get_type() == Variant::ARRAY) {
                Array arr = attacks;
                for (int j=0; j<arr.size(); j++) {
                    Ref<Resource> s = arr[j];
                    if (s.is_valid()) linked_states[s->get_path()] = true;
                }
            }

        } else if (type == "AbilitySystemConfig" || type == "Skill" || type == "SkillTree" || type == "CharacterSheet") {
             system_assets.append(res);
        } else if (type == "State") {
            states[path] = res;
        }
    }

    // Editor Theme for Fallback
    Ref<Texture2D> fallback = EditorInterface::get_singleton()->get_editor_theme()->get_icon("Object", "EditorIcons");

    // Create Sections
    if (system_assets.size() > 0) _create_section("Systems & Config", system_assets, fallback);
    if (composes.size() > 0) _create_section("Composes", composes, fallback);

    // Group States
    Dictionary folder_groups;
    Array state_paths = states.keys();
    for (int i=0; i<state_paths.size(); i++) {
        String path = state_paths[i];
        if (linked_states.has(path)) continue;

        String dir = path.get_base_dir().replace("res://", "");
        if (!folder_groups.has(dir)) folder_groups[dir] = Array();
        Array group = folder_groups[dir];
        group.append(states[path]);
        folder_groups[dir] = group; // Reassign because Dictionary returns copy? No, Ref, but safe.
    }

    Array dirs = folder_groups.keys();
    for (int i=0; i<dirs.size(); i++) {
        String dir = dirs[i];
        Array assets = folder_groups[dir];
        if (assets.size() > 0) {
            _create_section("States: " + dir, assets, fallback);
        }
    }
}

void CoreLibrary::_create_section(String title, Array assets, Ref<Texture2D> fallback_icon) {
    VBoxContainer *section = memnew(VBoxContainer);
    content_box->add_child(section);

    Label *label = memnew(Label);
    label->set_text(title);
    label->add_theme_font_size_override("font_size", 16);
    label->add_theme_color_override("font_color", Color::hex(0xa0aec0ff));
    section->add_child(label);

    HFlowContainer *grid = memnew(HFlowContainer);
    grid->set_h_size_flags(SIZE_EXPAND_FILL);
    grid->add_theme_constant_override("h_separation", 16);
    grid->add_theme_constant_override("v_separation", 16);
    section->add_child(grid);

    if (asset_card_scene.is_valid()) {
        for (int i=0; i<assets.size(); i++) {
            Ref<Resource> res = assets[i];
            Node *card_node = asset_card_scene->instantiate();
            Control *card = Object::cast_to<Control>(card_node);
            
            if (card) {
                grid->add_child(card);
                
                String type = _get_resource_type_name(res);
                Ref<Texture2D> icon = fallback_icon;
                if (icon_cache.has(type)) {
                    icon = icon_cache[type];
                }

                // Call setup(path, icon) on GDScript
                card->call("setup", res->get_path(), icon);
                
                // Connect signals
                card->connect("clicked", Callable(this, "_on_card_clicked"));
                card->connect("activated", Callable(this, "_on_card_activated"));
            } else {
                memdelete(card_node);
            }
        }
    }
}

void CoreLibrary::_on_search_text_changed(String new_text) {
    _update_grid(new_text);
}

void CoreLibrary::_on_refresh_pressed() {
    refresh_assets();
}

void CoreLibrary::_on_new_pressed() {
    UtilityFunctions::print("New functionality pending in Full C++.");
}

void CoreLibrary::_on_card_clicked(String path, int mouse_btn) {
    if (mouse_btn == MOUSE_BUTTON_RIGHT) {
         EditorInterface::get_singleton()->edit_resource(ResourceLoader::get_singleton()->load(path));
    } else {
         EditorInterface::get_singleton()->inspect_object(ResourceLoader::get_singleton()->load(path).ptr());
    }
}

void CoreLibrary::_on_card_activated(String path) {
    EditorInterface::get_singleton()->edit_resource(ResourceLoader::get_singleton()->load(path));
}

String CoreLibrary::_get_resource_type_name(Ref<Resource> res) {
    Ref<Script> script = res->get_script();
    if (script.is_valid()) {
       String global_name = script->get_global_name();
       if (!global_name.is_empty()) return global_name;
    }
    return res->get_class();
}
