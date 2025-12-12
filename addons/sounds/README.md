# Sounds Plugin

**A Sinfonia do Caos.**

Gerenciador de Áudio Inteligente e Singleton Nativo.

## 🔊 Arquitetura (Refatorada)

### SoundServer (C++ Singleton)

A extensão direta do `AudioServer` da Godot.

- Orquestra a reprodução global de áudio.
- Gerencia canais, prioridades e ducking.

### SoundsManager (Node)

O braço direito do SoundServer na SceneTree.

- **Pooling Inteligente:** Reutiliza `AudioStreamPlayers` para evitar instanciação custosa.
- **Fire & Forget:** Toque sons com uma única linha de código. `Sounds.play_cue(explosion_cue)`.
- Gerenciamento de Música de Fundo com Crossfading automático.

### SoundCue (Resource)

Definição de evento sonoro.

- Variação de Pitch/Volume randomizada.
- Múltiplos streams (ex: variações de passos).
- Concatenação sequencial.
