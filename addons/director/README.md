# Director

> **O Cineasta.**
> Sistema de sequenciamento linear para Cutscenes e Eventos Scriptados. Controla Câmeras, Animações e Sinais em uma Timeline unificada.

---

## 🏛️ Arquitetura

O Director segue os pilares do Machi Plugin Suite:

1. **Resource-Oriented:** As sequências são Resources (`SequenceResource`).
2. **Server/Singleton:** `DirectorManager` gerencia o estado global e transições.
3. **Nodes:** `DirectorPlayer` executa a lógica na cena.

### Core Classes

#### `SequenceResource` (Resource)

Define os dados da cutscene: duração, tracks, keys de animação, trocas de câmera. É o "roteiro".

- Pode ser salvo como `.tres` e reutilizado.

#### `DirectorManager` (Singleton)

Autoload responsável por:

- Gerenciar o estado de "Cinematic Mode" (desabilita input do player, esconde HUD).
- Transições de Câmera globais (Blending).
- Fila de Cutscenes.

#### `DirectorPlayer` (Node)

O executor na cena.

- Toca um `SequenceResource`.
- Faz o binding dinâmico entre os "Atores Virtuais" do recurso e os Nodes reais da cena (ex: Vincular o "Hero" da cutscene ao `Player` atual).

---

## 🔌 Integrações

- **Synapse:** Pode disparar Globais Events em frames específicos (ex: `QuestCompleted`).
- **Sounds:** Dispara `SoundCues` sincronizados com a animação.
