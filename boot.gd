extends Node

func _ready() -> void:
	# Initialize Voyager
	# We attach the frame to this Boot node (or a UI root)
	# Since Boot is root, we add it here.
	Voyager.setup_frame(self)
	
	# Load the Hub Level
	call_deferred("start_game")

func start_game() -> void:
	Voyager.change_scene("res://levels/main.tscn")
