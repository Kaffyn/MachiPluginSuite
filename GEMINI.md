# Ability System Component (ASC) - Planta Baixa

## Visão Geral

**Componente:** `AbilitySystemComponent`
**Responsabilidade:** Centralizar a gestão de Habilidades, Efeitos e Atributos de uma entidade. Unifica dados e lógica.

## Planta Baixa (Blueprint)

```gdscript
## AbilitySystemComponent (ASC)
##
## Central component for the Gameplay Ability System.
## Unifies data management (Attributes/Stats, Effects) and logic execution (States, Transitions).

@tool
class_name AbilitySystemComponent extends Node

# ==================== SIGNALS ====================

# State Signals
signal state_changed(old_state: State, new_state: State)

# Effect Signals
signal effect_applied(effect: Effect)
signal effect_removed(effect: Effect)

# Context/Attribute Signals
signal context_changed(category: String, value: int)
signal damage_dealt(target: Node, amount: int)
signal skill_learned(skill: Skill)

# ==================== EXPORTS ====================

@export_group("Data & Config")
@export var character_sheet: CharacterSheet
@export var skill_tree: SkillTree

@export_group("Debug")
@export var blackboard: Dictionary = {} # Runtime data

var current_state: State = null
var current_context: StateContext = null

# Context for Queries (Attributes/Tags)
var context: Dictionary = {}

# Active Effect Contexts
var active_effects: Array[EffectContext] = []

func _ready() -> void:

func _physics_process(delta: float) -> void:

func _process(delta: float) -> void:

func _input(event: InputEvent) -> void:

func change_state(new_state: State) -> void:

func _enter_state(state: State) -> void:

func _exit_state(state: State) -> void:

func set_context(category: String, value: int) -> void:

func get_context(category: String) -> int:

func get_stat(stat_name: String) -> Variant:

func modify_stat(stat_name: String, amount: float) -> void:

func apply_effect(effect: Effect) -> void:

func _process_effects(delta: float) -> void:

func remove_effect(effect: Effect) -> void:

func remove_effect_context(ctx: EffectContext) -> void:

func _get_active_effect_context(effect: Effect) -> EffectContext:

func _trigger_effect_components(ctx: EffectContext, method: String, args: Array = []) -> void:

func get_all_available_states() -> Array[State]:
```
