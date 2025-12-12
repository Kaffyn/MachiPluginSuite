# Machi Plugin Suite (MPS)

> **Engenharia de Jogos para Godot 4.x**
> Uma coleção unificada de ferramentas de nível Enterprise/AAA para construir sistemas complexos, escaláveis e desacoplados.

---

## 💎 Visão & Metodologia

Muitos plugins focam em "fazer rápido". O **Machi Plugin Suite** foca em **"fazer para durar"**.
Nossa filosofia é trazer padrões da indústria (como Unreal GAS, Wwise, Behavior Trees) para o ecossistema Godot, mantendo a sensação "Godot-Native" (Resource-first).

- **Data-Driven:** Comportamento é Dado. Tudo editável no Inspector.
- **Modular:** Peças pequenas que se encaixam (LEGO), não monólitos.
- **Desacoplado:** Sistemas conversam via Sinais e Recursos, nunca referência direta.

---

## 🧩 O Ecossistema

### 0. [Library](addons/library/README.md)

**A Fundação.**
Ferramentas de produtividade para o Editor Godot, independentes de runtime.

- **Panel:** `Assets` (Browser), `Editor` (Tools), `Factory` (Creators).
- **Core:** Hybrid Architecture (C++ Logic + GDScript UI).

### 1. [Ability System](addons/ability_system/README.md)

**O Cérebro e os Músculos.**
Framework de comportamento "Query-Based" que substitui máquinas de estado hardcoded.

- **Singletons:** `BehaviorStates` (Vocabulário Global).
- **Nodes:** `AbilitySystemComponent` (Brain), `Behavior` (Orchestrator), `Machine` (Executor).
- **Resources:** `State`, `Compose` (Rules), `Skill`, `Effect`, `AttributeSet`.

### 2. [Behavior Tree](addons/behavior_tree/README.md)

**O Motorista.**
Inteligência Artificial que pilota o Ability System (o Carro).

- **Nodes:** `BehaviorTreePlayer` (Runtime Executor).
- **Resources:** `BehaviorTree` (Asset), `Blackboard` (Memory Context).
- **Logic:** `Selector`, `Sequence`, `Decorator` (Conditions), `Task` (Actions).

### 3. [Inventory System](addons/inventory_system/README.md)

**A Mochila.**
Gestão de itens e equipamentos com integração profunda de gameplay.

- **Nodes:** `InventoryContainer` (Logic), `Slot` (UI Component).
- **Resources:** `Item`, `Inventory` (Storage), `LootTable`.
- **Integration:** Itens podem conceder `Skills` e modificar `Stats`.

### 4. [Synapse](addons/synapse/README.md)

**O Sistema Nervoso (Mundo & Mente).**
Gerencia Eventos Globais (Macro) e Percepção Sensorial (Micro).

- **Singletons:** `WorldMemory` (Global Flags/State).
- **Nodes:** `SynapseTrigger` (Event Detector), `VisualSynapse` (Eyes), `AuditorySynapse` (Ears).
- **Resources:** `Impulse` (Command Pattern), `VisualStimulus`, `AudioStimulus`.

### 5. [Sounds](addons/sounds/README.md)

**A Voz.**
Gerenciador de áudio com foco em concorrência e instanciamento dinâmico.

- **Singletons:** `SoundServer` (C++ Mixer), `SoundsManager` (Node API).
- **Nodes:** `SoundPlayer` (Pooled AudioStreamPlayer).
- **Resources:** `SoundCue` (Complex Audio Events: Pitch/Vol/Seq).

### 6. [Quest System](addons/quest_system/README.md)

**A Jornada.**
Sistema narrativo de estados baseado em Grafos e Eventos.

- **Singletons:** `QuestJournal` (Manager).
- **Nodes:** `QuestNode` (World Trigger).
- **Resources:** `QuestResource`, `QuestStep`, `Objective`, `Reward`.

### 7. [Gaia System](addons/gaia/README.md)

**A Vida.**
Simulação ambiental estética (Ciclos e Clima).

- **Nodes:** `DayNightCycle`, `WeatherController`.
- **Resources:** `TimeCurve`, `WeatherResource`, `SeasonManager`.
- **Events:** Emite sinais de hora/clima para o Synapse.

### 8. [Director](addons/director/README.md)

**O Diretor.**
Timeline Sequencer para Cutscenes lineares e eventos scriptados.

- **Singletons:** `DirectorManager` (Transitions/State).
- **Nodes:** `DirectorPlayer` (Scene Executor).
- **Resources:** `SequenceResource` (Tracks/Keyframes/ActorBindings).

### 9. [Memento](addons/memento/README.md)

**A Memória.**
Camada de persistência assíncrona e serialização segura.

- **Singletons:** `MementoManager` (Async IO/Encryption).
- **Nodes:** `SaveInterface` (Opt-in component for Nodes).
- **Resources:** `SaveProfile` (Slot Data), `SaveSchema` (Structure).

### 10. [Options](addons/options/README.md)

**O Painel.**
Gerenciador de configurações de usuário com UI automática.

- **Singletons:** `OptionsManager` (Apply Settings).
- **Resources:** `SettingsSchema` (Menu Structure).
- **Nodes:** `OptionWidget` (Auto-bind UI elements).

---

## 📦 Instalação

A Suite é projetada para funcionar em conjunto, mas cada plugin é isolado o suficiente para ser usado (com adaptações) separadamente.

1. Clone o repositório em `addons/`.
2. Ative os plugins desejados em `ProjectSettings > Plugins`.

---

_Machi Plugin Suite — Construindo Jogos, não Gambiarras._
