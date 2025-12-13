class_name Entity extends CharacterBody2D

# ------------------------------------------------------------------------------
# Signals
# ------------------------------------------------------------------------------
signal died

# ------------------------------------------------------------------------------
# Components
# ------------------------------------------------------------------------------
# All entities must have an AbilitySystemComponent for Stats/Attributes.
# Using @onready assumption that the node is named as such.
@onready var asc: Node = $AbilitySystemComponent 

# ------------------------------------------------------------------------------
# Properties
# ------------------------------------------------------------------------------
@export var move_speed: float = 150.0

func _ready() -> void:
	if asc:
		# Basic ASC initialization if needed
		pass

func take_damage(amount: float, source: Node = null) -> void:
	# Hook into AbilitySystem to apply damage effect
	# For now, simple implementation
	if asc and asc.has_method("apply_damage"):
		asc.apply_damage(amount)
	else:
		print_debug("Entity %s took %.1f damage (No ASC)" % [name, amount])

func die() -> void:
	emit_signal("died")
	queue_free()
