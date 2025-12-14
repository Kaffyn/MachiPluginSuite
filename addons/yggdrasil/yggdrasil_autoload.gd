extends YggdrasilServer

# ------------------------------------------------------------------------------
# Dependencies
# ------------------------------------------------------------------------------
const FRAME_SCENE = preload("res://addons/yggdrasil/scenes/yggdrasil_frame.tscn")

var _frame: SubViewportContainer
var _viewport: SubViewport
var _current_level_node: Node

func _ready() -> void:
    # We don't auto-instantiate the frame here because it might be part of a custom root.
    # But usually, Yggdrasil manages the window.
    pass

func setup_frame(target_parent: Node) -> void:
    if _frame: return
    _frame = FRAME_SCENE.instantiate()
    target_parent.add_child(_frame)
    _viewport = _frame.get_node("SubViewport")
    _current_level_node = _viewport.get_node("CurrentScene")

func change_scene(scene_path: String, params: Dictionary = {}) -> void:
    if not _viewport:
        push_warning("Yggdrasil: No Viewport configured. Call setup_frame() first.")
        # Fallback to standard? Or fail? failing is safer for strict usage.
        return

    # 1. Async Load (Stub for now, doing sync for stability step 1)
    var new_scene_res = load(scene_path)
    if not new_scene_res:
        push_error("Yggdrasil: Failed to load scene: " + scene_path)
        return
        
    # 2. Memento Save (TODO)
    
    # 3. Swap
    if _current_level_node:
        _current_level_node.queue_free()
    
    var new_instance = new_scene_res.instantiate()
    _viewport.add_child(new_instance)
    _current_level_node = new_instance
    
    # 4. Memento Load (TODO)

