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

### 0. [Core](addons/core/README.md)

**O Cérebro e os Músculos.**
Um framework completo para definir **O QUE** o personagem pode fazer. Gerencia States, Skills, Attributes (Health/Mana), Cooldowns e Effects.

- _Baseado em:_ Unreal GAS.

### 1. [Ability System (GAS)](addons/ability_system/README.md)

**O Cérebro e os Músculos.**
Um framework completo para definir **O QUE** o personagem pode fazer. Gerencia States, Skills, Attributes (Health/Mana), Cooldowns e Effects.

- _Baseado em:_ Unreal GAS.

### 2. [Inventory System](addons/inventory_system/README.md) (Em Breve)

**A Mochila.**
Sistema de inventário modular que se integra nativamente com o GAS. Itens dão Habilidades. Equipamentos mudam Stats.

### 3. [Behavior Tree](addons/behavior_tree/README.md)

**O Motorista.**
A Inteligência Artificial que pilota o Ability System. Decide **QUANDO** usar uma habilidade.

- _Baseado em:_ Unreal Behavior Tree & LimboAI.

### 4. [Synapse](addons/synapse/README.md)

**O Sistema Nervoso do Mundo.**
Orquestrador de Game Flow. Conecta eventos isolados (matar boss, entrar em área) a reações globais (quest update, música, cutscene) sem "spaghetti code".

- _Baseado em:_ Event-Driven Architecture.

### 5. [Sounds](addons/sounds/README.md)

**A Voz.**
Gerenciador de Áudio Inteligente. Foca em concorrência, prioridade e pooling, usando `AudioStreamRandomizer` nativo para variedade. Inclui workflow de auto-scan para assets.

- _Baseado em:_ Wwise/FMOD (Middlewares).

---

## 📦 Instalação

A Suite é projetada para funcionar em conjunto, mas cada plugin é isolado o suficiente para ser usado (com adaptações) separadamente.

1. Clone o repositório em `addons/`.
2. Ative os plugins desejados em `ProjectSettings > Plugins`.

---

_Machi Plugin Suite — Construindo Jogos, não Gambiarras._
