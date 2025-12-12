# Guia de Uso dos Plugins

Este documento explica como cada um dos 11 plugins da Machi Suite é utilizado especificamente dentro do contexto do Demo "O Fardo da Alquimista".

## 1. Character Controller (Ability System + Osmo)

- **Player Node:** `CharacterBody2D` com um `AbilitySystemComponent` anexado.
- **Atributos:** Definidos no `AbilitySystem` (HP, Mana, Stamina, Velocidade).
- **Câmera:** `OsmoCamera` anexada ao jogador.
  - _Uso:_ Fornece amortecimento (damping) suave e "camera shake" em impactos.
  - _Código:_ `Context.camera_server.shake("heavy_impact")` ao receber dano.

## 2. World State (Gaia + Synapse)

- **Dia/Noite:** `Gaia` controla o `CanvasModulate` global para iluminação.
- **IA Reativa:** Listeners do `Synapse` nos NPCs detectam o evento "NightStart" do `Gaia` para mudar de comportamento (ex: ir dormir ou spawnar monstros).
- **Clima:** O controlador de clima do `Gaia` emite sinais que o `Synapse` captura para aplicar debuffs em magias de fogo (ambiente úmido).

## 3. IA & Lógica (Behavior Tree + Synapse)

- **Tomada de Decisão:** A IA dos inimigos utiliza nodes de `BehaviorTree`.
  - _Raiz:_ `Selector`
  - _Ramos:_ `Combat`, `Investigate`, `Patrol`.
- **Percepção:** `Synapse` fornece nodes `VisualSensor` e `AuditorySensor`.
  - _Lógica:_ Quando o `VisualSensor` detecta o grupo "Player", ele escreve na Blackboard, acionando o ramo `Combat` na Behavior Tree.

## 4. Narrativa & Progressão (Director + Quest + Memento)

- **Cutscenes:** Acionadas via `DirectorPlayer`.
  - _Exemplo:_ Entrar na sala do chefe toca a sequência `boss_intro.tres`.
- **Quests:** Gerenciadas pelo `QuestJournal`.
  - _Integração:_ Matar um inimigo emite um sinal. O `QuestSystem` escuta e atualiza o objetivo ativo "Matar Slimes".
- **Persistência:** `Memento` lida com Salvar/Carregar.
  - _Escopo:_ Salva Posição do Player, Stats (AbilitySystem), Inventário e Estado das Quests.

## 5. UI & Áudio (Options + Sounds + Inventory)

- **Configurações:** O Menu de Opções usa nodes `OptionWidget` linkados diretamente ao `OptionsManager`. Nenhum código manual de salvamento é necessário.
- **Áudio:** `SoundManager` toca resources `SoundCue`.
  - _Feature:_ `SoundCue` permite variação aleatória de pitch/volume para passos e ataques sem código extra.
- **Inventário:** A UI confia nos sinais do `InventorySystem` (`item_added`, `item_removed`) para atualizar a grade visual.
