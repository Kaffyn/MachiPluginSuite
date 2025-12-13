extends Enemy
class_name Slime

func _ready() -> void:
	super._ready()
	# Slime specific logic
	move_speed = 80.0

func die() -> void:
	# GDD: Slime divides on death
	split()
	super.die()

func split() -> void:
	print("Slime splitted into smaller blobs!")
	# Logic to spawn 2 smaller slimes would go here
