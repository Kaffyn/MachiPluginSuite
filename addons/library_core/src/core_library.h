#ifndef CORE_LIBRARY_H
#define CORE_LIBRARY_H

#include <godot_cpp/classes/margin_container.hpp>
#include <godot_cpp/classes/v_box_container.hpp>
#include <godot_cpp/classes/h_box_container.hpp>
#include <godot_cpp/classes/line_edit.hpp>
#include <godot_cpp/classes/button.hpp>
#include <godot_cpp/classes/scroll_container.hpp>
#include <godot_cpp/classes/h_flow_container.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/classes/texture_rect.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/input_event.hpp>

using namespace godot;

class CoreLibrary : public MarginContainer {
	GDCLASS(CoreLibrary, MarginContainer);

private:
    // UI Elements
    LineEdit *search_edit;
    VBoxContainer *content_box;
    Button *refresh_btn;
    Button *new_btn;
    
    // Resources
    Ref<PackedScene> asset_card_scene;
    Dictionary icon_cache;
    TypedArray<String> all_assets;

    // Constants
    const String ICON_STATE = "res://addons/ability_system/assets/icons/state.svg";
    const String ICON_COMPOSE = "res://addons/ability_system/assets/icons/compose.svg";
    const String ICON_SKILL = "res://addons/ability_system/assets/icons/skill.svg";
    const String ICON_CHARACTER_SHEET = "res://addons/ability_system/assets/icons/character_sheet.svg";
    const String ICON_CONFIG = "res://addons/ability_system/assets/icons/config.svg";
    const String ICON_ITEM = "res://addons/inventory_system/assets/icons/item.svg";

    // Internal Methods
    void _setup_ui();
    void _preload_icons();
    void _scan_directory(String path);
    void _update_grid(String filter = "");
    void _create_section(String title, Array assets, Ref<Texture2D> fallback_icon);
    String _get_resource_type_name(Ref<Resource> res);

protected:
	static void _bind_methods();
    void _notification(int p_what);

public:
    // Signal callbacks need to be public/bound
    void _on_search_text_changed(String new_text);
    void _on_refresh_pressed();
    void _on_new_pressed();
    void _on_card_clicked(String path, int mouse_btn);
    void _on_card_activated(String path);

	CoreLibrary();
	~CoreLibrary();
    
    void refresh_assets();
};

#endif // CORE_LIBRARY_H
