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
# Inventory Integration: Loose coupling (optional)
# We might fetch this via group or external assignment, or keep it if strongly coupled.
# Ideally, ASC shouldn't know about Backpack directly for strict separation, but for now we follow the previous pattern
# or interface via signals/method calls if needed.
# For now, let's omit direct Backpack export to enforce separation, OR keep it as a 'NodePath' or loose reference.
# Previous 'Behavior' had 'backpack'. Let's see if we can decouple.
# If 'Backpack' is now in another plugin, we can't type hint it easily without circular dependency risks 
# if the user hasn't enabled the other plugin.
# BUT custom types in Godot are global. So `Backpack` class_name is available if the plugin is there.
# We'll use dynamic access for now or assume it's assigned.

@export_group("Debug")
@export var blackboard: Dictionary = {} # Runtime data

# ==================== INTERNAL STATE ====================

var current_state: State = null
var current_context: StateContext = null

# Context for Queries (Attributes/Tags)
var context: Dictionary = {}

# Active Effect Contexts
var active_effects: Array[EffectContext] = []

# ==================== LIFECYCLE ====================

func _ready() -> void:
	pass

func _physics_process(delta: float) -> void:
	if Engine.is_editor_hint():
		return
	
	# 1. Process Logic (Machine Loop)
	if current_state and current_context:
		current_context.delta = delta
		for component in current_state.components:
			component.on_physics(current_context, delta)
			
	# 2. Process Effects (Behavior Loop)
	_process_effects(delta)

func _process(delta: float) -> void:
	if Engine.is_editor_hint():
		return
		
	if current_state and current_context:
		current_context.delta = delta
		for component in current_state.components:
			component.on_process(current_context)

func _input(event: InputEvent) -> void:
	if Engine.is_editor_hint() or not current_state:
		return
		
	if current_context:
		for component in current_state.components:
			component.on_input(current_context, event)

# ==================== STATE MANAGEMENT (Ex-Machine) ====================

func change_state(new_state: State) -> void:
	var old_state = current_state
	
	if old_state:
		_exit_state(old_state)
	
	current_state = new_state
	
	if new_state:
		_enter_state(new_state)
	
	state_changed.emit(old_state, new_state)

func _enter_state(state: State) -> void:
	# Create new context
	current_context = StateContext.new()
	current_context.state = state
	current_context.actor = get_parent()
	current_context.blackboard = blackboard 
	# Inject Reference to ASC
	# We might need to extend StateContext to hold 'asc' or 'machine' reference.
	# For backwards compatibility, 'actor' is usually the CharacterBody.
	# But components often need to call 'change_state' on the machine.
	# We should ensure StateContext has access to this component.
	current_context.machine = self # If StateContext has this property. If not, we need to add it.
	
	for component in state.components:
		component.on_enter(current_context)

func _exit_state(state: State) -> void:
	if current_context:
		for component in state.components:
			component.on_exit(current_context)
	
	current_context = null

# ==================== ATTRIBUTES & CONTEXT (Ex-Behavior) ====================

func set_context(category: String, value: int) -> void:
	if context.get(category, 0) != value:
		context[category] = value
		context_changed.emit(category, value)

func get_context(category: String) -> int:
	return context.get(category, 0)

# ==================== STATS ====================

func get_stat(stat_name: String) -> Variant:
	if not character_sheet:
		return 0.0
	return character_sheet.get_stat(stat_name)

func modify_stat(stat_name: String, amount: float) -> void:
	if not character_sheet:
		return
	var current = get_stat(stat_name)
	character_sheet.set_stat(stat_name, current + amount)

# ==================== EFFECTS SYSTEM ====================

func apply_effect(effect: Effect) -> void:
	if not effect or not character_sheet:
		return
	
	# Check if already active
	var existing_ctx = _get_active_effect_context(effect)
	
	if existing_ctx:
		# Stack logic
		var stack_comp = effect.get_component("Stacking")
		var max_stacks = stack_comp.max_stacks if stack_comp else 1
		
		if existing_ctx.stacks < max_stacks:
			existing_ctx.stacks += 1
			# Refresh duration
			var dur_comp = effect.get_component("Duration")
			if dur_comp:
				existing_ctx.remaining_time = dur_comp.duration
			
			_trigger_effect_components(existing_ctx, "on_apply")
		else:
			# Refresh duration even at max stacks?
			var dur_comp = effect.get_component("Duration")
			if dur_comp:
				existing_ctx.remaining_time = dur_comp.duration
	else:
		# New Context
		var ctx = EffectContext.new()
		ctx.setup(effect, character_sheet, self)
		
		var dur_comp = effect.get_component("Duration")
		if dur_comp:
			ctx.remaining_time = dur_comp.duration
			active_effects.append(ctx)
		
		_trigger_effect_components(ctx, "on_apply")

	effect_applied.emit(effect)

func _process_effects(delta: float) -> void:
	var to_remove = []
	
	for i in range(active_effects.size()):
		var ctx = active_effects[i]
		
		# Tick
		ctx.tick_timer += delta
		_trigger_effect_components(ctx, "on_tick", [delta])
		
		# Duration
		if ctx.remaining_time > 0: 
			ctx.remaining_time -= delta
			if ctx.remaining_time <= 0:
				to_remove.append(ctx)
	
	for ctx in to_remove:
		remove_effect_context(ctx)

func remove_effect(effect: Effect) -> void:
	var ctx = _get_active_effect_context(effect)
	if ctx:
		remove_effect_context(ctx)

func remove_effect_context(ctx: EffectContext) -> void:
	_trigger_effect_components(ctx, "on_remove")
	active_effects.erase(ctx)
	effect_removed.emit(ctx.effect)

func _get_active_effect_context(effect: Effect) -> EffectContext:
	for ctx in active_effects:
		if ctx.effect == effect:
			return ctx
	return null

func _trigger_effect_components(ctx: EffectContext, method: String, args: Array = []) -> void:
	if ctx.effect and "components" in ctx.effect:
		for comp in ctx.effect.components:
			if comp.has_method(method):
				comp.callv(method, [ctx] + args)

# ==================== QUERY HELPERS ====================

func get_all_available_states() -> Array[State]:
	var states: Array[State] = []
	
	# From SkillTree
	if skill_tree:
		states.append_array(skill_tree.get_all_unlocked_states())
		
	# From Equipped Items (Need to check how to access this now)
	# If we have an "Equipment" component or similar on the character, we ask it.
	# Or we rely on an external system to push available states to us.
	# For now, let's assume we might have a method 'get_external_states' or similar,
	# or we query the 'Backpack' if we find one in our siblings/children (auto-discovery).
	
	# Auto-discover Backpack sibling?
	var parent = get_parent()
	if parent:
		for child in parent.get_children():
			if child.has_method("get_equipped_compose"):
				var compose = child.get_equipped_compose()
				if compose:
					states.append_array(compose.get_move_states())
					states.append_array(compose.get_attack_states())
					
	return states
