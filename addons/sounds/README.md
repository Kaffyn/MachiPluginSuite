# Sounds: Audio Architecture

> **Inspiração:** Middleware de áudio como **Wwise** e **FMOD**, mas nativo e "Resource-Oriented".

---

## 🎵 O Problema: `AudioStreamPlayer` é primitivo

Na Godot crua, você arrasta um `AudioStreamPlayer`, coloca um `.wav` e chama `.play()`.
Isso gera problemas em escala AAA:

1. **Repetição:** Ouvir o mesmo "passo" 100x enjoa.
2. **Variedade:** Você precisa de aleatoriedade de Pitch e Volume para "humanizar" o som.
3. **Concorrência:** 50 inimigos atirando ao mesmo tempo estouram o áudio e a CPU.
4. **Organização:** Arquivos de áudio espalhados por cenas.

## 🔊 A Solução: `SoundCue` (O Evento)

Nós não tocamos `.wav` ou `.ogg`. Nós tocamos **`SoundCues`**.

### 1. SoundCue (Resource)

Um Resource que encapsula a lógica de reprodução.

- **Variations:** Lista de AudioStreams (ex: `footstep_01.wav`, `footstep_02.wav`). O sistema escolhe um aleatório.
- **Randomization:** `pitch_range` (0.9 a 1.1), `volume_range` (-2db a +2db).
- **Concurrency:** "Max instances = 3". Se o quarto som tentar tocar, ele é ignorado ou rouba a voz do mais antigo.
- **Layers:** Pode disparar múltiplos sons (ex: Tiro = Som do Tiro + Som da Cápsula caindo).

### 2. SoundManager (O Maestro)

Um Singleton (`Sounds`) que gerencia um Pool de AudioStreamPlayers.

- **Fire and Forget:** `Sounds.play(sound_cue, global_position)`
- **Pooling:** Reutiliza players para evitar instanciamento em runtime.
- **Bus Routing:** Garante que sons de UI vão para o bus UI e SFX para SFX.

---

## 🏗️ Estrutura de Pastas

```text
addons/sounds/
├── nodes/
│   └── sound_bank.gd        # Preloader de sons
├── resources/
│   ├── sound_cue.gd         # O Resource principal
│   └── playlist.gd          # Para música (sequencial, loop)
└── autoload/
    └── sound_manager.gd     # Singleton global
```

## 🚀 Exemplo de Integração

### No Ability System (ActionBlock)

```gdscript
# AttackState.tres
actions:
  - PlaySound:
      cue: "res://assets/sounds/sword_swing_cue.tres"
```

### No Synapse (Impulse)

```gdscript
# ImpulsePlayMusic.tres
music_playlist: "res://assets/music/boss_theme_playlist.tres"
fade_time: 2.0
```

---

_Sounds — Áudio Dinâmico, Não Repetitivo._
