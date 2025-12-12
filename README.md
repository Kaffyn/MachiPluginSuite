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

### 1. [Ability System](addons/ability_system/README.md)

**O Cérebro e os Músculos.**
Um framework completo para definir **O QUE** o personagem pode fazer. Gerencia States, Skills, Attributes (Health/Mana), Cooldowns e Effects.

- _Baseado em:_ Unreal GAS.

### 2. [Behavior Tree](addons/behavior_tree/README.md)

**O Motorista.**
A Inteligência Artificial que pilota o Ability System. C++ Based.

- _Baseado em:_ Unreal Behavior Tree & LimboAI.

### 3. [Inventory System](addons/inventory_system/README.md)

**A Mochila.**
Sistema de inventário modular que se integra nativamente com o GAS. Itens dão Habilidades. Equipamentos mudam Stats. C++ Based.

### 4. [Synapse](addons/synapse/README.md)

**O Sistema Nervoso do Mundo e da Mente.**
Orquestrador de Game Flow e Percepção Sensorial.

- **Micro:** Gerencia visão e audição da IA (Sense).
- **Macro:** Conecta eventos isolados (matar boss, entrar em área) a reações globais (quest update, música, cutscene).

- _Baseado em:_ Unreal AIPerception + Event-Driven Architecture.

### 5. [Sounds](addons/sounds/README.md)

**A Voz.**
Gerenciador de Áudio Inteligente. Foca em concorrência, prioridade e pooling, usando `AudioStreamRandomizer` nativo para variedade. Inclui workflow de auto-scan para assets.

- _Baseado em:_ Wwise/FMOD (Middlewares).

### 6. [Quest System](addons/quest_system/README.md)

**A Jornada.**
Gerenciador de Narrativa e Missões. Criação de objetivos lineares ou ramificados, com total integração ao sistema de eventos (Synapse) e recompensas.

- _Baseado em:_ Event-Driven Architecture / Graph Theory.

### 7. [Gaia System](addons/gaia/README.md)

**A Vida do Mundo.**
Simulador ambiental. Ciclo Dia/Noite, Clima e Estações. Totalmente desacoplado, focado em estética e imersão.

- _Baseado em:_ Solar/Lunar Cycles & Weather States.

### 8. [Director](addons/director/README.md)

**O Diretor.**
Sequencer e Cutscene Engine. Controla Câmeras, Animações e Eventos em uma Timeline unificada. Perfeito para narrativa linear.

- _Baseado em:_ Unreal Sequencer.

### 9. [Memento](addons/memento/README.md)

**A Memória.**
Sistema de Save/Load robusto. Serializa Resources complexos, suporta múltiplos slots e criptografia.

- _Baseado em:_ Unreal SaveGame.

### 10. [Options](addons/options/README.md)

**O Painel de Controle.**
Gerenciamento de Configurações (Vídeo, Áudio, Input, Gameplay) com persistência automática e geração de UI.

- _Baseado em:_ GameUserSettings.

---

## 📦 Instalação

A Suite é projetada para funcionar em conjunto, mas cada plugin é isolado o suficiente para ser usado (com adaptações) separadamente.

1. Clone o repositório em `addons/`.
2. Ative os plugins desejados em `ProjectSettings > Plugins`.

---

_Machi Plugin Suite — Construindo Jogos, não Gambiarras._
