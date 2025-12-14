import os

# Configuration
ICON_SIZE = 128
BASE_DIR = "addons"

PLUGINS = {
    "ability_system": {
        "color": "#8B5CF6", # Purple
        "icons": ["AbilitySystemComponent", "Behavior", "Machine", "State", "Skill", "AttributeSet", "Effect", "PassiveAbility", "GameplayTag"]
    },
    "gaia": {
        "color": "#06B6D4", # Cyan
        "icons": ["SeasonManager", "SeasonPreset", "WeatherResource", "DayNightCycle", "WeatherController"]
    },
    "sounds": {
        "color": "#F97316", # Orange
        "icons": ["SoundCue", "SoundManager"]
    },
    "behavior_tree": {
        "color": "#14B8A6", # Teal
        "icons": ["BehaviorTreePlayer", "BehaviorTree", "BlackboardPlan", "BTSelector", "BTSequence", "BTDecorator", "BTTask"]
    },
    "inventory_system": {
        "color": "#F59E0B", # Amber
        "icons": ["InventoryContainer", "Item", "Recipe", "CraftingStation", "Slot"]
    },
    "synapse": {
        "color": "#EC4899", # Pink
        "icons": ["Synapse", "Impulse", "SynapseTrigger", "SynapseSensor2D", "SynapseSensor3D"]
    },
    "director": {
        "color": "#6366F1", # Indigo
        "icons": ["DirectorPlayer", "DirectorManager", "SequenceResource"]
    },
    "memento": {
        "color": "#64748B", # Slate
        "icons": ["SaveInterface", "MementoManager", "SaveProfile"]
    },
    "options": {
        "color": "#71717A", # Zinc
        "icons": ["OptionWidget", "OptionsManager", "SettingsSchema"]
    },
    "quest_system": {
        "color": "#10B981", # Emerald
        "icons": ["QuestNode", "QuestJournal", "QuestResource"]
    },
    "osmo": {
        "color": "#F43F5E", # Rose
        "icons": ["OsmoCamera2D", "OsmoCamera3D", "OsmoServer", "CameraState", "CameraZone"]
    },
    "library": {
        "color": "#0EA5E9", # Sky
        "icons": ["Library"]
    },
    "yggdrasil": {
        "color": "#8B5CF6", # Violet
        "icons": ["YggdrasilServer", "LevelAnchor"]
    }
}

SVG_TEMPLATE = """<svg width="{size}" height="{size}" viewBox="0 0 {size} {size}" fill="none" xmlns="http://www.w3.org/2000/svg">
<rect width="{size}" height="{size}" rx="20" fill="{color}"/>
<text x="50%" y="50%" dominant-baseline="middle" text-anchor="middle" font-family="Arial" font-weight="bold" font-size="64" fill="white">{letter}</text>
</svg>
"""

def generate_icons():
    for plugin, data in PLUGINS.items():
        color = data["color"]
        icons = data["icons"]
        
        # Ensure icons directory exists
        icon_dir = os.path.join(BASE_DIR, plugin, "icons")
        if not os.path.exists(icon_dir):
            os.makedirs(icon_dir)
            print(f"Created directory: {icon_dir}")
        
        for icon_name in icons:
            letter = icon_name[0].upper()
            svg_content = SVG_TEMPLATE.format(size=ICON_SIZE, color=color, letter=letter)
            
            file_path = os.path.join(icon_dir, f"{icon_name}.svg")
            with open(file_path, "w") as f:
                f.write(svg_content)
            print(f"Generated {file_path}")

if __name__ == "__main__":
    generate_icons()
