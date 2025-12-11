# Behavior Tree: A Lógica por Trás da Ação

> **Inspiração:** Baseado na robustez das árvores da **Unreal Engine** e na leveza do **LimboAI**.
> **Integração:** Projetado para ser o "Motorista" do **Ability System (GAS)**.

---

## 🧠 Conceito: O Motorista e o Carro

Se o **Ability System (ASC)** é o Carro (Motor, Rodas, Capacidade de Mover e Atacar), a **Behavior Tree** é o Motorista (IA).

- **A BT não move o personagem diretamente.**
- A BT diz para o ASC: _"Eu quero andar para frente"_.
- O ASC decide _como_ andar (animação, física, colisão).

Essa separação garante que a IA use as mesmas regras de gameplay que o Player.

---

## 🏛️ Arquitetura

O sistema segue o padrão clássico de Behavior Trees com melhorias de "Quality of Life" da Godot.

### 1. Blackboard (A Memória de Curto Prazo)

Um Resource/Dicionário que armazena o conhecimento da IA sobre o mundo atual.

- `target: Node3D`
- `last_known_position: Vector3`
- `alert_level: float`
- `has_los: bool`

### 2. Composites (O Fluxo)

Nodes que controlam o fluxo de decisão.

- **Selector (?):** Tenta executar filhos até um ter sucesso. (Lógica OR)
- **Sequence (->):** Executa filhos em ordem até um falhar. (Lógica AND)
- **SimpleParallel:** Executa múltiplos nós simultaneamente (ex: Mirar e Andar).

### 3. Decorators (As Condições)

Guardiões que permitem ou negam a execução de um ramo.

- `BlackboardCheck`: "Tenho um alvo?"
- `Cooldown`: "Posso usar essa skill de novo?"
- `ASC_CanActivate`: "O Ability System permite 'Attack' agora?"

### 4. Tasks (As Folhas)

Onde a magia acontece. São os nós que interagem com o mundo.

#### Integração com Ability System

As tasks não devem ter código de gameplay complexo (move_and_slide). Elas devem delegar para o ASC.

- **`BTTask_SetIntent`:** Define inputs no ASC (ex: pressionar "Jump").
- **`BTTask_ActivateAbility`:** Tenta ativar uma Skill ou State específico.
- **`BTTask_WaitAbility`:** Espera uma habilidade terminar (ex: "Cast Fireball").

---

## 🚀 Exemplo de Árvore: Inimigo Básico

```text
ROOT
└── Selector (?)
    ├── Sequence (->) [Combat]
    │   ├── Decorator: HasTarget?
    │   ├── Decorator: DistanceTo < 200
    │   ├── Selector (?)
    │       ├── Sequence (->) [Melee Attack]
    │       │   ├── Decorator: DistanceTo < 50
    │       │   ├── Task: ASC_StopMovement
    │       │   └── Task: ASC_ActivateAbility("HeavySlash")
    │       └── Sequence (->) [Chase]
    │           └── Task: ASC_MoveTo(target.position)
    │
    └── Sequence (->) [Patrol]
        ├── Task: GetRandomPoint
        ├── Task: ASC_MoveTo(point)
        └── Task: Wait(2.0)
```

## 📂 Estrutura de Pastas

```text
addons/behavior_tree/
├── nodes/
│   ├── bt_player.gd         # O Executor da árvore
│   └── bt_node.gd           # Classe base
├── resources/
│   ├── blackboard.gd        # Dados compartilhados
│   └── behavior_tree.gd     # O Resource da árvore (editável visualmente)
├── tasks/
│   ├── bt_task_wait.gd
│   ├── bt_task_move_to.gd
│   └── asc_tasks/           # Integração com Ability System
│       ├── bt_task_activate_ability.gd
│       └── bt_task_set_context.gd
└── editor/                  # GraphEdit customizado (similar ao LimboAI)
```

---

_Behavior Tree — Decisão Inteligente, Execução Robusta._
