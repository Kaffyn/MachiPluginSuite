# Machi Quest System

> **"A Jornada do Herói, em Dados."**

O **Quest System** fornece uma estrutura robusta, orientada a dados e orientada a eventos para criar missões narrativas complexas, desde simples "Fetch Quests" até campanhas ramificadas.

---

## 💎 Filosofia

1. **Quests são Máquinas de Estado:** Uma Quest não é apenas uma lista de tarefas. É um grafo de estados (`NotStarted` -> `Active` -> `Completed`/`Failed`) que reage ao mundo.
2. **Objetivos Desacoplados:** O Quest System não sabe o que é "Matar 10 Goblins". Ele sabe que precisa esperar um sinal `Events.MONSTER_DIED` com payload `{type: "goblin"}` 10 vezes. Isso é feito via integração com o **Synapse**.
3. **Narrativa Não-Linear:** Suporte a objetivos opcionais, falhas parciais e múltiplos desfechos.

---

## 🏗️ Arquitetura

### 1. Resources (O DNA)

#### `QuestResource`

A definição estática da missão.

- **Metadados:** Nome, Descrição, Ícone, Categoria (Main/Side).
- **Steps (Graph/Stages):** Uma sequência ou grafo de etapas (`QuestStep`).
- **Rewards:** Lista de `RewardResource` (XP, Itens, Skills).
- **Requirements:** Condições para aceitar (Level, outra Quest completa).

#### `QuestStep`

Uma etapa da missão. Pode ter múltiplos objetivos.

- **Objectives:** Lista de `ObjectiveResource`.
- **IsOptional:** Se falhar ou pular, a quest continua?

#### `ObjectiveResource`

A menor unidade de progresso.

- **Target:** O que deve ser feito.
- **Count:** Quantidade (1/10).
- **EventTrigger:** (Integração **Synapse**) Qual "Sinapse" dispara esse objetivo?

---

### 2. Runtime (O Motor)

#### `QuestJournal` (Manager)

O cérebro que gerencia o estado das Quests do jogador.

- Mantém lista de `ActiveQuests`, `CompletedQuests`, `FailedQuests`.
- Serializável (Save/Load).
- Dispara sinais globais: `quest_started`, `objective_updated`, `quest_completed`.

#### `QuestNode` (Opcional)

Um nó utilitário para colocar na cena, útil para NPCs ou triggers de área.

- `start_quest()`
- `complete_objective()`

---

## 🔌 Integrações (O Ecossistema)

### Library Core (JEI)

- O `QuestResource` será registrado no Library Core para fácil acesso e organização.
- Ícone dedicado na aba "Quests".

### Synapse (Events)

- A **Synapse** é o "ouvido" da Quest.
- Objetivos escutam canais da Synapse.
  - Ex: O jogador mata um monstro -> `Synapse.pulse("combat", "kill_enemy", {id="slime"})` -> Quest checa: "Preciso de slime? Sim. +1".

### Inventory System

- **Rewards:** Ao completar, o Quest System pede ao Inventory System para adicionar itens.
- **Objectives:** Objetivos do tipo "Coletar Item" consultam o Inventário.

---

## 🗺️ Roadmap

- [ ] Criar estrutura base de Resources (`Quest`, `Step`, `Objective`).
- [ ] Implementar `QuestJournal` (Logic only).
- [ ] Criar Editor Visual para Quests (GraphEdit ou TreeView).
- [ ] Integração com Synapse para objetivos automáticos.
- [ ] UI de HUD e Journal In-Game.
