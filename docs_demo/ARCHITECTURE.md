# Arquitetura do Projeto Demo

Este documento detalha a estrutura de pastas e a organização técnica do projeto **Machi Demo**, separando a lógica do jogo da lógica dos plugins.

## 🛠️ Estrutura de Pastas

A organização segue uma separação clara entre "Core/Plugins" e "GameContent".

```
res://
├── addons/                  # Machi Plugin Suite (11 GDExtensions)
├── assets/                  # Assets de Arte, Áudio e Fontes
├── data/                    # Resources do Jogo (Items, Quests, Skills)
│   ├── items/
│   ├── quests/
│   ├── skills/
│   └── ...
├── scenes/                  # Cenas do Jogo
│   ├── actors/              # Player, Inimigos, NPCs
│   ├── levels/              # Mapas e Dungeons
│   └── ui/                  # Menus e HUD
├── scripts/                 # Scripts de Gameplay (GDScript)
└── systems/                 # Gerenciadores Globais/Autoloads
```

## 🧩 Guia de Implementação

### 1. GameInstance (Singleton)

O `GameInstance` atua como o ponto central de acesso para o estado do jogo que não é coberto pelos plugins.

- **Responsabilidade:** Gerenciar transições de cena, estado global da sessão (ex: "Gameover", "Pause").
- **Localização:** `res://systems/game_instance.gd`

### 2. Separação Dados vs Lógica

Utilizamos estritamente o paradigma de **Resource-Oriented Design**.

- **Dados:** Toda a configuração de balanceamento (Dano, HP, Drops) fica em arquivos `.tres` na pasta `res://data/`.
- **Lógica:** O comportamento é definido pelos Nodes dos plugins (`AbilitySystemComponent`, `BehaviorTree`) e scripts controladores em `res://scripts/`.

### 3. Integração de Sistemas

Nenhum sistema roda isolado. A "cola" entre eles é feita através de **Sinais** e **Eventos**.

- **Exemplo:** Quando o `QuestSystem` completa uma missão, ele emite um sinal. O `Director` pode ouvir esse sinal para iniciar uma cutscene de recompensa, e o `InventorySystem` pode ouvir para adicionar o item de recompensa.

## ⚠️ Detalhes Importantes

- **Performance:** A lógica pesada (Pathfinding, AI, Física) roda em C++ via GDExtension. O GDScript é usado apenas para a lógica de gameplay de alto nível.
- **Extensibilidade:** Para criar um novo inimigo, basta criar um novo `Resource` de Atributos e uma nova `BehaviorTree`, sem necessidade de recompilar código C++.
