# Yggdrasil (Scene Manager) - Planta Baixa

## Visão Geral

**Componente:** `YggdrasilServer`
**Responsabilidade:** Gerenciar o ciclo de vida de Cenas, Carregamento Assíncrono, Transições e Persistência (Memento).
**Status:** Alpha

## Arquitetura

O Yggdrasil opera como uma **Árvore de Mundos**:

1. **Singleton (C++):** Gerencia threads de loading e sinalização de progresso.
2. **Container (Viewport):** Isola o "Mundo" atual do "Root" (Boot/Menu), permitindo transições visuais sem travar a thread principal.
3. **Persistência:** Atua como porteiro do `Memento`, garantindo que o estado seja salvo/carregado atomicamente na troca de cenas.

## Planta Baixa (Blueprint)

```gdscript
## Yggdrasil (Autoload Wrapper)
##
## GDScript wrapper for the C++ YggdrasilServer.
## Manages the SceneTree integration via SubViewport.

extends YggdrasilServer

# ==================== CONSTANTS ====================

const FRAME_SCENE = preload("res://addons/yggdrasil/scenes/yggdrasil_frame.tscn")

# ==================== STATE ====================

var _frame: SubViewportContainer
var _viewport: SubViewport
var _current_level_node: Node

# ==================== PUBLIC API ====================

## Initializes the Viewport container attached to the given parent (usually Boot).
func setup_frame(target_parent: Node) -> void:
    # Logic to instantiate FRAME_SCENE and capture _viewport

## Asynchronously loads a new scene, saves the old state, plays transition, and swaps.
func change_scene(scene_path: String, params: Dictionary = {}) -> void:
    # 1. Check strict requirements (Viewport existence)
    # 2. Trigger Transition In (Fade Out)
    # 3. Memento.save_level_state()
    # 4. YggdrasilServer.start_load(path) (Threaded)
    # 5. Await load_completed
    # 6. Instantiate new scene -> Add to Viewport
    # 7. Memento.load_level_state()
    # 8. Trigger Transition Out (Fade In)

## Returns the current active level node
func get_current_level() -> Node:
    return _current_level_node
```

## Dependências

- **Memento:** Para salvar/carregar persistência.
- **Director (Opcional):** Para "Level Sequencers" de entrada/saída.
