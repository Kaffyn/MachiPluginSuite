# Arquitetura e Plantas Baixas (Blueprints)

> **Contexto AI:** Este arquivo contém a "Planta Baixa" (Interface Pública/Blueprint) de todos os sistemas core do Machi Plugin Suite. Use-o como referência absoluta para assinaturas de métodos e sinais.

---

## 1. Ability System (GAS)

### `AbilitySystemComponent` (ASC)

**Responsabilidade:** Centralizar Habilidades, Efeitos e Atributos.

```gdscript
@tool
class_name AbilitySystemComponent extends Node

# Signals
signal state_changed(old_state: State, new_state: State)
signal effect_applied(effect: Effect)
signal effect_removed(effect: Effect)
signal context_changed(category: String, value: int)
signal damage_dealt(target: Node, amount: int)
signal skill_learned(skill: Skill)

# API
func change_state(new_state: State) -> void:
func set_context(category: String, value: int) -> void:
func get_context(category: String) -> int:
func get_stat(stat_name: String) -> Variant:
func modify_stat(stat_name: String, amount: float) -> void:
func apply_effect(effect: Effect) -> void:
func remove_effect(effect: Effect) -> void:
func get_all_available_states() -> Array[State]:
```

---

## 2. Yggdrasil (Scene Manager)

### `YggdrasilServer` (C++ Singleton)

**Responsabilidade:** Loading assíncrono e Threading.

```gdscript
class_name YggdrasilServer extends Node

signal load_completed()

func start_load(path: String) -> void:
func get_load_progress() -> float:
func is_loading() -> bool:
func get_loaded_scene() -> PackedScene:
```

### `Yggdrasil` (Autoload Wrapper)

**Responsabilidade:** Gerenciar Viewport e Transições.

```gdscript
extends YggdrasilServer

func setup_frame(target_parent: Node) -> void:
func change_scene(scene_path: String, params: Dictionary = {}) -> void:
func get_current_level() -> Node:
```

---

## 3. Synapse (Perception & Events)

### `WorldMemory` (Global State)

**Responsabilidade:** Flags globais e persistência de mundo.

```gdscript
class_name WorldMemory extends Node

signal flag_changed(id: String, value: Variant)

func set_flag(name: String, value: Variant) -> void:
func get_flag(name: String, default: Variant = null) -> Variant:
func has_flag(name: String) -> bool:
func remove_flag(name: String) -> bool:
func get_all_flags() -> Dictionary:
```

### `Synapse` (Trigger)

**Responsabilidade:** Disparar Impulsos.

```gdscript
class_name Synapse extends Node

@export var impulses: Array[Impulse]

func trigger() -> void:
```

### `SynapseSensor2D` (Perception)

**Responsabilidade:** Detectar estímulos visuais/auditivos.

```gdscript
class_name SynapseSensor2D extends Area2D

@export var vision_angle: float = 60.0
@export var max_range: float = 300.0

func can_see(target: Node2D) -> bool:
func can_hear(source: Node2D, db: float) -> bool:
```

### `Impulse` (Command)

**Responsabilidade:** Ação atômica (Command Pattern).

```gdscript
class_name Impulse extends Resource

func execute(context: Object) -> void:
```
