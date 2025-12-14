extends Node

func _ready() -> void:
	# Initialize Yggdrasil
	# We attach the frame to this Boot node (or a UI root)
	# Since Boot is root, we add it here.
	Yggdrasil.setup_frame(self)
	
	# Load the Hub Level
	call_deferred("start_game")

func start_game() -> void:
	Yggdrasil.change_scene("res://levels/main.tscn")
