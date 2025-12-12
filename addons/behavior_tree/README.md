# Behavior Tree: A Lógica por Trás da Ação

> **Inspiração:** Baseado na robustez das árvores da **Unreal Engine** e na experiência de usuário do **LimboAI**.
> **Integração:** Projetado para ser o "Motorista" do **Ability System (GAS)**.
> **Editor:** Funciona como um **Main Screen Plugin** (lado a lado com 2D/3D/Script), não como Bottom Panel.

---

## 🧠 Conceito: O Motorista e o Carro

Se o **Ability System (ASC)** é o Carro (Motor, Rodas, Capacidade de Mover e Atacar), a **Behavior Tree** é o Motorista (IA).

- **A BT não move o personagem diretamente.**
- A BT diz para o ASC: _"Eu quero andar para frente"_.
- O ASC decide _como_ andar (animação, física, colisão).

Essa separação garante que a IA use as mesmas regras de gameplay que o Player.

---

## 🏛️ Arquitetura

O sistema segue o padrão clássico de Behavior Trees com melhorias de "Quality of Life" da Godot e integração profunda com Synapse/GAS.

### 1. Nodes (Runtime)

- **`BehaviorTreePlayer`:** O executor que roda a árvore na SceneTree.

### 2. Resources (Assets)

- **`BehaviorTree`:** O asset da árvore em si.
- **`BlackboardPlan`:** Schema que define quais chaves a Blackboard DEVE ter (safety).

### 3. Logic Nodes (Leaves & Composites)

#### Composites (Fluxo)

- **`BTSelector` (?):** OR Logic.
- **`BTSequence` (->):** AND Logic.
- **`BTSimpleParallel`:** Concurrency.

#### Decorators (Condições)

- **`BTDecorator`:** Base class.
- **`BlackboardCheck`:** Verifica memória.
- **`Cooldown`:** Limita frequência.
- **`ASC_CanActivate`:** Checa se a habilidade pode ser usada.

#### Services (Periódicos)

- **`BTService`:** Roda a cada X segundos enquanto o ramo está ativo (ex: `CheckDistance`).

#### Tasks (Ações)

- **`BTTask`:** Base class.
- **`BTTask_SetIntent`:** Controla o GAS.
- **`SynapseQuery`:** Pergunta ao sistema de percepção (ex: "GetVisibleEnemies").

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

addons/behavior_tree/
├── src/ # Código C++ (GDExtension)
│ ├── bt_player.cpp # O Executor da árvore
│ ├── bt_node.cpp # Classe base
│ ├── blackboard.cpp # Dados compartilhados
│ └── ...
├── bin/ # Binários compilados
└── plugin.cfg

---

_Behavior Tree — Decisão Inteligente, Execução Robusta._
