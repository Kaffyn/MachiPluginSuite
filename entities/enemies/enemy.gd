class_name Enemy extends Entity

# ------------------------------------------------------------------------------
# Components
# ------------------------------------------------------------------------------
# Enzymes use BehaviorTrees for AI logic
@onready var behavior_tree: Node = $BehaviorTree

# Synapse for Perception (Vision/Hearing)
@onready var synapse: Node = $Synapse

# ------------------------------------------------------------------------------
# AI Properties
# ------------------------------------------------------------------------------
@export var aggro_range: float = 300.0
@export var attack_range: float = 40.0
@export var target: Node2D = null

func _ready() -> void:
	super._ready()
	# Initialize AI
	if behavior_tree and behavior_tree.has_method("start"):
		behavior_tree.start()

func _physics_process(delta: float) -> void:
	# Enemies usually move via NavigationAgent, handled by BehaviorTree
	# velocity logic here is a fallback or for simple movement
	move_and_slide()

# ------------------------------------------------------------------------------
# AI Interfaces
# ------------------------------------------------------------------------------
func set_target(new_target: Node2D) -> void:
	target = new_target

func get_target() -> Node2D:
	return target
