class_name NPC extends Entity

# ------------------------------------------------------------------------------
# Interaction
# ------------------------------------------------------------------------------
@export var npc_name: String = "Villager"
@export_multiline var default_dialogue: String = "Hello there!"

# ------------------------------------------------------------------------------
# Components
# ------------------------------------------------------------------------------
# Director for Cutscenes/Complex Interaction
# @onready var director_player: DirectorPlayer = $DirectorPlayer 

func _ready() -> void:
	super._ready()

func interact(interactor: Node) -> void:
	print("Interacting with %s" % npc_name)
	# Trigger dialogue or Director sequence here
	# DialogueManager.start_dialogue(default_dialogue)
