@tool
## Serviço central para registro de metadados de Resources.
## Segue o padrão JEI (Just Enough Items): Outros plugins registram seus conteúdos aqui.
extends Node

# Dictionary[String, Texture2D] - Maps "ClassName" -> Icon
var _icons: Dictionary = {}

# Dictionary[String, String] - Maps "ClassName" -> GroupName
var _groups: Dictionary = {}

# Default Icon
var _fallback_icon: Texture2D

func _ready() -> void:
    # Try to load a generic fallback from editor theme if possible, or use a placeholder
    # In tool mode, we might not always have EditorInterface ready in _ready for singletons?
    # Safer to fetch fallback on demand.
    pass

## Registra um tipo de resource para ser exibido na Library.
## [param type_name]: Nome da classe (ex: "State", "Item").
## [param icon]: Ícone para exibir nos cards.
## [param group]: Nome do grupo/aba onde ele deve aparecer (ex: "Systems", "Combat").
func register_resource(type_name: String, icon: Texture2D, group: String = "") -> void:
    if icon:
        _icons[type_name] = icon
    
    if not group.is_empty():
        _groups[type_name] = group
    
    print_rich("[color=cyan][LibraryService][/color] Registered: %s (Group: %s)" % [type_name, group])

## Retorna o ícone registrado para o tipo, ou null.
func get_icon(type_name: String) -> Texture2D:
    return _icons.get(type_name, null)

## Retorna o grupo registrado para o tipo, ou "" se não houver.
func get_group(type_name: String) -> String:
    return _groups.get(type_name, "")
