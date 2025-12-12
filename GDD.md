# Machi Demo: O Fardo da Alquimista

**Gênero:** Action RPG Top-Down
**Estilo:** Pixel Art, Atmosférico, Era 16-bit (Inspiração: Zelda ALttP / Hyper Light Drifter)
**Engine:** Godot 4.x
**Tech Stack:** Machi Plugin Suite (Todos os 11 Plugins)

---

## 1. Visão Geral

Em **O Fardo da Alquimista**, os jogadores controlam Elara, uma alquimista novata buscando curar uma praga mágica que consome sua vila. O jogo serve como uma "Vertical Slice" (fatia vertical) demonstrando a capacidade total da Machi Plugin Suite.

### Pilares Centrais

1. **Mundo Reativo:** O ambiente muda com o tempo (Dia/Noite), clima e ações do jogador. (Gaia, Synapse)
2. **Combate Tático:** Não é apenas hack-and-slash; requer uso de itens, ambiente e habilidades. (Ability System, Behavior Tree)
3. **Profundidade Narrativa:** Cutscenes e escolhas de diálogo importam. (Director, Quest System)

---

## 2. Mecânicas de Gameplay e Integração

### 2.1. Personagem (Elara)

- **Movimento:** Movimentação em 8 direções com aceleração/atrito.
  - _Plugin:_ **Ability System** (atributos para velocidade, stamina), **Osmo** (Câmera segue o player).
- **Combate:**
  - **Primário:** Cajado Melee (Combo de 3 hits).
  - **Secundário:** Frascos Alquímicos (Granadas - Fogo, Gelo, Ácido).
  - _Plugin:_ **Ability System** (Skills: `MeleeAttack`, `ThrowFlask`), **Inventory System** (Consumo de frascos).
- **Stats:**
  - Vida (HP), Stamina (SP), Mana (MP).
  - _Plugin:_ **Ability System** (`AttributeSet` no Player).

### 2.2. O Mundo (Ambiente)

- **Ciclo Dia/Noite:**
  - Dia: Música pacífica, NPCs ativos, inimigos raros.
  - Noite: Música tensa, inimigos "Sombra" perigosos aparecem, visibilidade reduzida.
  - _Plugin:_ **Gaia** (Controle de tempo, iluminação), **Sounds** (Crossfading de música).
- **Clima:**
  - Chuva: Apaga ataques de fogo, aumenta dano elétrico.
  - _Plugin:_ **Gaia** (Estados climáticos), **Synapse** (Evento global `WeatherChanged` afeta gameplay).

### 2.3. Inimigos (IA)

- **Sistema:** IA baseada em **Behavior Tree** com percepção via **Synapse**.
- **Tipos de Inimigos:**
  1. **Slime (Básico):** Vagueia. Agresivo ao ver. Divide ao morrer.
  2. **Shadow Stalker (Noturno):** Invisível até chegar perto. Flanqueia o jogador. Foge de luzes fortes.
  3. **Golem (Tanque):** Alto HP. Lento. Telegrafa ataques pesados.
  4. **Chefe: O Ent Corrompido:** Luta em múltiplas fases (Intro e meio da luta via Director).
- **Lógica de IA (Behavior Tree):**
  - `Selector` -> `Sequence(HasLowHealth, Flee)` -> `Sequence(CanSeePlayer, Chase)` -> `Wander`.
  - **Synapse:** Usa `VisualSensor` para detectar Player e `AuditorySensor` para ouvir explosões de frascos.

### 2.4. Quests e Narrativa

- **Quest Principal:** "A Fonte da Corrupção" - Encontrar os 3 núcleos elementais para purificar a vila.
- **Side Quest:** "Herança Perdida" - Encontrar o colar de um NPC (Recuperação noturna).
- _Plugin:_ **Quest System** (Rastreamento: `Find`, `Kill`, `Talk`), **Director** (Sequências de diálogo).

### 2.5. Sistemas

- **Inventário:** Baseado em Grade ou Slots. Crafting de poções a partir de ervas coletadas.
  - _Plugin:_ **Inventory System**.
- **Configurações:** Volume, Rebind de Teclas, Qualidade Gráfica.
  - _Plugin:_ **Options**.
- **Save/Load:** Checkpoints nas "Fogueiras do Alquimista".
  - _Plugin:_ **Memento**.

---

## 3. Level Design (A Fatia Vertical)

### Zona 1: A Vila Decrepita (Hub)

- **Features:** Zona segura, NPCs, Loja, Estação de Crafting, Cama (Dormir para pular tempo).
- **Implementação:** `Gaia` (Lógica Dia/Noite para horários de NPCs), `Inventory` (Loja/Crafting).

### Zona 2: Bosque dos Sussurros (Combate)

- **Features:** Floresta densa, verticalidade (penhascos), caminhos ocultos.
- **Inimigos:** Slimes, Lobos.
- **Eventos:** Tempestade repentina (Gaia) força o jogador a buscar abrigo.

### Zona 3: Ruínas Antigas (Dungeon)

- **Features:** Resolução de Puzzles (empurrar blocos, acender tochas).
- **Chefe:** Ent Corrompido.
- **Implementação:** `Director` (Cutscene de intro do Boss), `Osmo` (Câmera trava na arena do boss).

---

## 4. UI/UX

- **HUD:** Barras de Vida/Stamina (Ability System), Hotbar (Inventory), Minimap.
- **Menus:** Menu de Pausa (Options), Log de Quests (Quest System), Tela de Inventário.
- **Feedback:** Números de Dano, Tremor de Tela (Osmo), Cues Sonoros (Sounds).

---

## 5. Lista de Assets (Ícones e Visuais)

- **Player:** Idle, Run, Attack, Throw, Hit, Die.
- **Inimigos:** Slime, Stalker, Golem, Treant.
- **Ambiente:** Árvores, Rochas, Água, Tileset de Ruínas.
- **Ícones:** Ícones Coloridos de 128px (Verificado na suite de plugins).

---

## 6. Plano de Implementação (Estrutura de Código)

- `GameInstance` (Singleton): Segura o estado global.
- `PlayerController`: Gerencia inputs -> Ability System.
- `GameMode`: Gerencia pontos de spawn e regras do jogo.
