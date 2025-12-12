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
Sistema híbrido (C++ e GDScript) que fornece as ferramentas compartilhadas do editor. Inclui Navegador de Assets, Factory e Utilities.

- **Panel:** `Assets` (Browser), `Editor` (Tools), `Factory` (Creators).
- **Core:** Hybrid Architecture (C++ Logic + GDScript UI).

### 1. [Ability System](addons/ability_system/README.md)

**O Sistema de Jogo mais importante.**
Define habilidades, estados, atributos, efeitos, custo, cooldowns, tags, gatilhos e modificadores.

**Funções Principais:**

- Atributos (Health, Mana, Stamina, Armor…).
- States (Idle, Roll, Attack, Cast…).
- Active Abilities (inputs, animações, custos).
- Passive Abilities (buffs/auras).
- Gameplay Effects (modificadores temporários/permanentes).
- Gameplay Tags.
- Prediction & Authority (para Multiplayer futuro).

**Arquitetura:**

- **Singletons:** `BehaviorStates` (Vocabulário Global).
- **Nodes:** `AbilitySystemComponent` (Brain), `Behavior` (Orchestrator), `Machine` (Executor).
- **Resources:** `State`, `Compose` (Rules), `Skill`, `Effect`, `AttributeSet`.

### 2. [Behavior Tree](addons/behavior_tree/README.md)

**A Inteligência que controla personagens e sistemas vivos.**
Motor de Behavior Tree completo, escrito em C++, com nó custom, decorators, services e blackboard global.

**Funções Principais:**

- Execução hierárquica de comportamentos.
- Blackboard com suporte a Resources e tipos customizados.
- Services periódicos.
- Decorators condicionais.
- Query Nodes integrados ao Synapse e Navigation.
- Controle AI-driven de Abilities (via Ability System).
- Serve tanto para IA quanto para lógica sistêmica.

**Arquitetura:**

- **Nodes:** `BehaviorTreePlayer` (Runtime Executor).
- **Resources:** `BehaviorTree` (Asset), `Blackboard` (Memory Context).
- **Logic:** `Selector`, `Sequence`, `Decorator` (Conditions), `Task` (Actions).

### 3. [Inventory System](addons/inventory_system/README.md)

**O sistema de itens unificado.**
Inventário modular, orientado a Resources, profundamente integrado ao Ability System.

**Funções Principais:**

- Slots, Stacks e Categorias.
- Equipamentos que alteram atributos e adicionam habilidades.
- Itens ativos (usáveis) e passivos.
- Bancos de crafting, loot tables e containers.
- Integração direta com Synapse e BehaviorTree.

**Arquitetura:**

- **Nodes:** `InventoryContainer` (Logic), `Slot` (UI Component).
- **Resources:** `Item`, `Inventory` (Storage), `LootTable`.
- **Integration:** Itens podem conceder `Skills` e modificar `Stats`.

### 4. [Synapse](addons/synapse/README.md)

**O Sistema Nervoso Central: Percepção + Eventos.**
Conecta tudo no jogo: mente, mundo, cenários e sistemas. É literalmente o glue system que a Unreal usa: enxergar + reagir.

**Funções Principais:**

- Senses 2D: visão, audição, proximidade, tags, áreas.
- Stimuli: qualquer evento pode virar um estímulo (som, hit, uso, área, item).
- Propagation: eventos se propagam para IAs, Director, Quest, Ability System.
- Event Orchestration: um único hub para eventos globais.

**Arquitetura:**

- **Singletons:** `WorldMemory` (Global Flags/State).
- **Nodes:** `SynapseTrigger` (Event Detector), `VisualSynapse` (Eyes), `AuditorySynapse` (Ears).
- **Resources:** `Impulse` (Command Pattern), `VisualStimulus`, `AudioStimulus`.

### 5. [Sounds](addons/sounds/README.md)

**Gerenciamento inteligente de áudio.**
Sistema escalável que cuida de playback, prioridade, pool e variações.

**Funções Principais:**

- Sound Cues como Resources.
- Randomizers e Layers.
- Concurrency Rules (limitar sons repetidos).
- Prioridades e distâncias.
- Áudio contextual com Synapse (event-driven).

**Arquitetura:**

- **Singletons:** `SoundServer` (C++ Mixer), `SoundsManager` (Node API).
- **Nodes:** `SoundPlayer` (Pooled AudioStreamPlayer).
- **Resources:** `SoundCue` (Complex Audio Events: Pitch/Vol/Seq).

### 6. [Quest System](addons/quest_system/README.md)

**Narrativa Sistemática.**
Framework de missões com objetivos lineares, ramificados e sistêmicos.

**Funções Principais:**

- Missões como Resources.
- Objetivos com condições dinâmicas.
- Hooks diretos para Synapse (event-driven).
- Rewards integrados ao Inventory e Ability System.
- Tracking, UI e persistência.

**Arquitetura:**

- **Singletons:** `QuestJournal` (Manager).
- **Nodes:** `QuestNode` (World Trigger).
- **Resources:** `QuestResource`, `QuestStep`, `Objective`, `Reward`.

### 7. [Gaia System](addons/gaia/README.md)

**Simulação de Ambiente e Atmosfera.**
Sistema global de clima, ciclos e estados ambientais.

**Funções Principais:**

- Ciclo dia/noite com curvas configuráveis.
- Clima (clear, rain, storm, fog).
- Estações com presets.
- Exposição pública via Resources.
- Hooks para Synapse e Director.

**Arquitetura:**

- **Nodes:** `DayNightCycle`, `WeatherController`.
- **Resources:** `TimeCurve`, `WeatherResource`, `SeasonManager`.
- **Events:** Emite sinais de hora/clima para o Synapse.

### 8. [Director](addons/director/README.md)

**Timeline unificada para cinematics, eventos e animações.**
Engine de sequenciamento estilo Unreal Sequencer, mas 2D e Godot-native.

**Funções Principais:**

- Faixas de animação, posição, câmera, áudio e eventos.
- Controle de cutscenes e transições narrativas.
- Integração com Osmo (Camera).
- Eventos de timeline conectados ao Synapse.
- Usado tanto para cenas quanto para scripting visual de gameplay.

**Arquitetura:**

- **Singletons:** `DirectorManager` (Transitions/State).
- **Nodes:** `DirectorPlayer` (Scene Executor).
- **Resources:** `SequenceResource` (Tracks/Keyframes/ActorBindings).

### 9. [Osmo](addons/osmo/README.md)

**O Sistema de Câmera Dinâmico 2D.**
Inspirado na fluidez do DJI Osmo.

**Funções Principais:**

- Câmera física 2D com real smoothing.
- Tracks de câmera do Director.
- Camera Zones inteligentes.
- Zoom dinâmico e framing automático.
- Suporte a câmeras múltiplas e virtual cameras.

**Arquitetura:**

- **Singletons:** `CameraServer` (Transition Manager).
- **Nodes:** `OsmoCamera` (Physical Camera), `CameraZone`.
- **Resources:** `CameraShake`, `CameraState` (Preset).

### 10. [Memento](addons/memento/README.md)

**Persistência Completa.**
Save/Load que entende Resources complexos.

**Funções Principais:**

- Serialização com controle preciso de versões.
- Múltiplos perfis e slots.
- Criptografia opcional.
- Integração automática com Ability System, Inventory, Quest, Gaia.

**Arquitetura:**

- **Singletons:** `MementoManager` (Async IO/Encryption).
- **Nodes:** `SaveInterface` (Opt-in component for Nodes).
- **Resources:** `SaveProfile` (Slot Data), `SaveSchema` (Structure).

### 11. [Options](addons/options/README.md)

**Painel de Configurações Universal.**

**Funções Principais:**

- Perfis e presets.
- Configurações de áudio, vídeo, input e gameplay.
- Aplicação automática no ProjectSettings.
- Gerador de UI pronto para Themes.

**Arquitetura:**

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
