# Osmo (Camera System)

> **O Cinegrafista Dinâmico.**
> Sistema de câmera 2D físico e inteligente, inspirado na fluidez do DJI Osmo.

---

## 📸 Visão Geral

O **Osmo** é um sistema de câmera focado em "Feel". Ele substitui a `Camera2D` padrão da Godot por uma câmera física virtual que possui massa, aceleração e comportamento de smoothing real.

## 🏛️ Arquitetura

### 1. Servers & Singletons

- **`CameraServer`:** Gerenciador global de transições. Permite misturar múltiplos targets (ex: Player + Inimigo) e transitar suavemente entre câmeras virtuais.

### 2. Nodes

- **`OsmoCamera`:** A câmera física principal.
  - **Features:** Deadzone, Lookahead, Damping, Framing Automático.
- **`CameraZone`:** Áreas de gatilho no mundo que sobrescrevem os parâmetros da câmera (ex: Zoom out ao entrar em uma sala grande).
- **`VirtualCamera`:** Pontos de interesse estáticos ou móveis para onde o `CameraServer` pode cortar ou transitar.

### 3. Resources

- **`CameraShake`:** Definição de algorítmos de tremor (Perlin Noise) para impactos e explosões.
- **`CameraState`:** Presets de configuração (ex: "Indoor", "BossFight", "Cutscene") para troca rápida de comportamento.

## 🔌 Integrações

- **Director:** O Osmo é totalmente controlável pela timeline do Director para cutscenes.
- **Synapse:** Eventos de jogo (ex: Dano) disparam `CameraShakes` automaticamente.

---
