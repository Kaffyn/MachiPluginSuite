## Factory Presets
## Define presets para criação rápida de recursos.
class_name FactoryPresets extends RefCounted

# ========== STATE PRESETS ==========
const STATE_PRESETS = {
	"Idle": {
		"description": "Estado parado, sem movimento",
		"values": {
			"name": "Idle",
			"speed": 0.0,
			"components": [
				{"name": "Appears in Editor", "values": {}}, # Placeholder to force scan? No, name must match ComponentDefinition
				{"name": "Standard Move", "values": {"multiplier": 0.0}}
			]
		}
	},
	"Walk": {
		"description": "Movimento lento",
		"values": {
			"name": "Walk",
			"speed": 0.5,
			"components": [
				{"name": "Standard Move", "values": {"multiplier": 0.5}}
			]
		}
	},
	"Run": {
		"description": "Movimento rápido",
		"values": {
			"name": "Run",
			"speed": 1.0,
			"components": [
				{"name": "Standard Move", "values": {"multiplier": 1.0}}
			]
		}
	},
	"Jump": {
		"description": "Pulo (Platform2D)",
		"values": {
			"name": "Jump",
			"components": [
				{"name": "Physics", "values": {"jump_force": -500.0, "ignore_gravity": false}}
			]
		}
	},
	"Fall": {
		"description": "Queda (Platform2D)",
		"values": {
			"name": "Fall",
			"components": [
				{"name": "Physics", "values": {"ignore_gravity": false}}
			]
		}
	},
	"Dash": {
		"description": "Dash rápido",
		"values": {
			"name": "Dash",
			"speed": 3.0,
			"components": [
				{"name": "Dash", "values": {"dash_speed": 600.0, "preserve_y_velocity": true}},
				{"name": "Duration", "values": {"duration": 0.2}},
				{"name": "Physics", "values": {"ignore_gravity": true}}
			]
		}
	},
	"Attack Light": {
		"description": "Ataque leve e rápido",
		"values": {
			"name": "AttackLight",
			"components": [
				{"name": "Hitbox", "values": {"damage_multiplier": 1.0, "active_time": 0.2}},
				{"name": "Duration", "values": {"duration": 0.3}},
				{"name": "Movement", "values": {"lock_input": true}}
			]
		}
	},
	"Attack Heavy": {
		"description": "Ataque pesado e lento",
		"values": {
			"name": "AttackHeavy",
			"components": [
				{"name": "Hitbox", "values": {"damage_multiplier": 2.5, "active_time": 0.4}},
				{"name": "Duration", "values": {"duration": 0.8}},
				{"name": "Movement", "values": {"lock_input": true}}
			]
		}
	},
	"Hurt": {
		"description": "Tomando dano",
		"values": {
			"name": "Hurt",
			"components": [
				{"name": "Duration", "values": {"duration": 0.3}},
				{"name": "Movement", "values": {"lock_input": true}}
			]
		}
	},
	"Die": {
		"description": "Morte",
		"values": {
			"name": "Die",
			"components": [
				{"name": "Movement", "values": {"lock_input": true}}
			]
		}
	}
}

# ========== ITEM PRESETS ==========
const ITEM_PRESETS = {
	"Weapon": {
		"description": "Arma equipável",
		"values": {
			"name": "New Weapon",
			"components": [
				{"name": "Identity", "values": {"category": 0, "display_name": "New Weapon"}},
				{"name": "Equipment", "values": {"equip_slot": 1}},
				{"name": "Stacking", "values": {"stackable": false, "max_stack": 1}}
			]
		}
	},
	"Consumable": {
		"description": "Item consumível (poções, comida)",
		"values": {
			"name": "New Consumable",
			"components": [
				{"name": "Identity", "values": {"category": 1, "display_name": "New Potion"}},
				{"name": "Consumable", "values": {"consume_on_use": true}},
				{"name": "Stacking", "values": {"stackable": true, "max_stack": 20}}
			]
		}
	},
	"Material": {
		"description": "Material para craft",
		"values": {
			"name": "New Material",
			"components": [
				{"name": "Identity", "values": {"category": 2, "display_name": "Scrap"}},
				{"name": "Stacking", "values": {"stackable": true, "max_stack": 999}}
			]
		}
	},
	"Armor": {
		"description": "Armadura equipável",
		"values": {
			"name": "New Armor",
			"components": [
				{"name": "Identity", "values": {"category": 3, "display_name": "Leather Armor"}},
				{"name": "Equipment", "values": {"equip_slot": 4}},
				{"name": "Durability", "values": {"max_durability": 100}}
			]
		}
	},
	"Key Item": {
		"description": "Item de quest",
		"values": {
			"name": "New Key Item",
			"components": [
				{"name": "Identity", "values": {"category": 5}},
				{"name": "Stacking", "values": {"stackable": false}}
			]
		}
	}
}

# ========== SKILL PRESETS ==========
const SKILL_PRESETS = {
	"Active": {
		"description": "Habilidade ativa",
		"values": {
			"name": "New Skill",
			"cost": 1,
			"max_level": 5
		}
	},
	"Passive": {
		"description": "Habilidade passiva",
		"values": {
			"name": "New Passive",
			"cost": 1,
			"max_level": 1
		}
	},
	"Ultimate": {
		"description": "Habilidade poderosa",
		"values": {
			"name": "New Ultimate",
			"cost": 3,
			"required_level": 10,
			"max_level": 3
		}
	}
}

# ========== COMPOSE PRESETS ==========
const COMPOSE_PRESETS = {
	"Movement Set": {
		"description": "Conjunto de movimentos básicos",
		"values": {}
	},
	"Combat Set": {
		"description": "Conjunto de ataques",
		"values": {}
	},
	"Full Set": {
		"description": "Movimento + Combate",
		"values": {}
	}
}

# ========== INVENTORY PRESETS ==========
const INVENTORY_PRESETS = {
	"Player Backpack": {
		"description": "Mochila padrão do jogador",
		"values": {
			"name": "PlayerInventory",
			# Inventory relies on array of items, typically empty at start
			# But we could pre-fill if we had logic (omitted for now)
		}
	},
	"Small Chest": {
		"description": "Combinação Pequena",
		"values": {
			"name": "SmallChest",
		}
	}
}

# ========== SKILL TREE PRESETS ==========
const SKILL_TREE_PRESETS = {
	"Basic Class": {
		"description": "Árvore de habilidades básica",
		"values": {
			"name": "BasicClassTree"
		}
	}
}

# ========== CHARACTER SHEET PRESETS ==========
const CHARACTER_SHEET_PRESETS = {
	"Hero": {
		"description": "Personagem Jogável (Hero)",
		"values": {
			"name": "HeroSheet",
			"components": [
				{"name": "Health", "values": {"max_health": 100.0}},
				{"name": "Stamina", "values": {"max_stamina": 100.0}},
				{"name": "Experience", "values": {"level": 1}},
				{"name": "Base Attributes", "values": {"strength": 10, "dexterity": 10}}
			]
		}
	},
	"Enemy Grunt": {
		"description": "Inimigo básico",
		"values": {
			"name": "GruntSheet",
			"components": [
				{"name": "Health", "values": {"max_health": 30.0}},
				{"name": "Combat Stats", "values": {"attack_power": 5.0}}
			]
		}
	}
}

static func get_presets_for_type(type_name: String) -> Dictionary:
	match type_name:
		"State": return STATE_PRESETS
		"Item": return ITEM_PRESETS
		"Skill": return SKILL_PRESETS
		"Compose": return COMPOSE_PRESETS
		"Inventory": return INVENTORY_PRESETS
		"SkillTree": return SKILL_TREE_PRESETS
		"CharacterSheet": return CHARACTER_SHEET_PRESETS
	return {}

static func get_preset_names_for_type(type_name: String) -> Array:
	var presets = get_presets_for_type(type_name)
	return presets.keys()

static func apply_preset_to_resource(res: Resource, type_name: String, preset_name: String) -> void:
	var presets = get_presets_for_type(type_name)
	if not preset_name in presets:
		return
	
	var values = presets[preset_name].get("values", {})
	for key in values.keys():
		if key in res:
			res.set(key, values[key])
