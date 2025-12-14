# Synapse: O Sistema Nervoso do Jogo

> **Conceito:** Se o _Ability System_ é o Cérebro e os Músculos do personagem, o **Synapse** é o **Sistema Nervoso do Mundo**. Ele conecta eventos isolados (entrar em uma sala, matar um boss) a reações globais (música mudar, porta abrir, quest atualizar).

---

## 🧠 Filosofia: "Action & Reaction"

Jogos complexos morrem quando você começa a fazer `if game_manager.boss_is_dead:` dentro do código da porta. O **Synapse** desacopla isso através de **Flags** e **Impulsos**.

1. **O Mundo tem Memória:** Um dicionário global de `Flags` ("boss_defeated", "first_time_castle").
2. **Receptores Ouvem:** Portas, luzes e spawners "ouvem" essas flags.
3. **Impulsos Agem:** Quando uma flag muda (ou um gatilho é ativado), um `Impulse` é disparado.

## Planta Baixa (Blueprints)

```gdscript
## WorldMemory (WM)
## Global State Manager. Stores flags and signals changes.

class_name WorldMemory extends Node

signal flag_changed(id: String, value: Variant)

func set_flag(name: String, value: Variant) -> void:
func get_flag(name: String, default: Variant = null) -> Variant:
func has_flag(name: String) -> bool:
func remove_flag(name: String) -> bool:
func get_all_flags() -> Dictionary:
```

```gdscript
## Synapse
## Generic Trigger Node. Dispatches Impulses when triggered.

class_name Synapse extends Node

@export var impulses: Array[Impulse]

func trigger() -> void:
    # Executes all assigned impulses
```

```gdscript
## SynapseSensor2D
## Perception Node (Eyes/Ears). Detects stimuli in the world.

class_name SynapseSensor2D extends Area2D

@export var vision_angle: float = 60.0
@export var max_range: float = 300.0

func can_see(target: Node2D) -> bool:
func can_hear(source: Node2D, db: float) -> bool:
```

```gdscript
## Impulse (Command)
## Resource that performs an action when triggered.

class_name Impulse extends Resource

func execute(context: Object) -> void: # Virtual
```

## 🏛️ Arquitetura

### 1. WorldMemory (A Memória)

O Autoload ou Resource que contém o estado atual do save.

- **Flags:** `{"met_npc_arya": true, "dungeon_keys": 3}`.
- **Signals:** `flag_changed(id, value)`.

### 2. Synapse (O Gatilho)

Um Node que pode ser colocado em qualquer lugar para **detectar** algo e **disparar** Impulsos.

- **Ex:** `SynapseTrigger` (Genérico).
- **Ex:** `VisualSensor` (Eyes - Cone de Visão).
- **Ex:** `AuditorySensor` (Ears - Raio de Audição).
- **Ex:** `ProximitySensor` (Touch/Near - Área).

### 3. Impulse (A Ação)

Resources modulares que fazem coisas. Eles são "Comandos".

- `ImpulsePlaySound`
- `ImpulseLoadScene`
- `ImpulseSetFlag`
- key: `ImpulseGiveItem`
- `ImpulseSpawnScene`

### 4. Perception (Os Sentidos)

Como parte do Sistema Nervoso, o Synapse gerencia como os agentes percebem o mundo. Substitui Raycasts manuais por um sistema de registro centralizado.

- **Stimuli:** Objetos emitem estímulos (`VisualStimulus`, `AudioStimulus`) com tags (`TEAM_A`, `DANGEROUS`).
- **Sensors:** Nodes que captam estímulos (`VisualSensor`, `AuditorySensor`).
- **StimulusArea:** Área que emite estímulo constante (ex: Cheiro/Heat).
- **Integração BT:** Sensores populam automaticamente a Blackboard da Behavior Tree (ex: `Target`, `LastKnownLocation`).

---

## 🚀 Exemplo de Uso: "Boss Battle"

Imagine a seguinte sequência complexa configurada **apenas no Inspector**, sem uma linha de código específica:

1. **Jogador entra na Arena (Area3D):**

   - **SynapseTrigger:** Ao entrar, dispara lista de Impulsos.
   - **Impulse 1:** `System.SetFlag("boss_encounter_started", true)`
   - **Impulse 2:** `Audio.PlayMusic("BossTheme")`
   - **Impulse 3:** `Door.Lock()`

2. **Boss Morre (HealthComponent):**

   - **SynapseTrigger:** No sinal `on_death`.
   - **Impulse 1:** `System.SetFlag("boss_defeated", true)`
   - **Impulse 2:** `System.SetFlag("boss_encounter_started", false)`

3. **Porta de Saída (Listening Node):**
   - **Condition:** Escuta a flag `boss_defeated`.
   - **Reaction:** Se `true` -> `Door.Unlock()`.

---

## 📂 Estrutura de Pastas

addons/synapse/
├── src/ # Código C++ (GDExtension)
│ ├── synapse.cpp # Nó base para gatilhos
│ ├── world_memory.cpp # Singleton de estado
│ └── ...
├── bin/ # Binários compilados
└── plugin.cfg

_Synapse — Conectando o caos._
