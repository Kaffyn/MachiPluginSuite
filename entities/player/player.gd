class_name Player extends Entity

@export_category("Attributes")
@export var speed: float = 200.0
@export var acceleration: float = 800.0
@export var friction: float = 1000.0

@onready var osmo_camera: OsmoCamera2D = $OsmoCamera
@onready var ability_system: Node = $AbilitySystemComponent
# @onready var machine: Machine = $Machine # Uncomment when Machine is added

func _ready() -> void:
	# Initialize things if needed
	pass

func _physics_process(delta: float) -> void:
	move(delta)

func move(delta: float) -> void:
	# Get input direction (WASD / Arrows)
	var input_vector: Vector2 = Input.get_vector("ui_left", "ui_right", "ui_up", "ui_down")
	
	if input_vector != Vector2.ZERO:
		# Accelerate
		velocity = velocity.move_toward(input_vector * speed, acceleration * delta)
	else:
		# Decelerate
		velocity = velocity.move_toward(Vector2.ZERO, friction * delta)
	
	move_and_slide()
