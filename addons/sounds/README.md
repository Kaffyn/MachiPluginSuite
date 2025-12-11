# Sounds: Audio Architecture

> **Inspiração:** Middleware de áudio como **Wwise** e **FMOD**, mas nativo e "Resource-Oriented".

---

## 🎵 O Problema: Escala e Gerenciamento

A Godot 4 já possui o `AudioStreamRandomizer` para resolver repetição (Pitch/Volume/Weight).
Porém, ainda faltam recursos de **orquestração de alto nível**:

1. **Concorrência:** Impedir que 50 tiros toquem simultaneamente (estourando CPU e ouvido).
2. **Prioridade:** Se o limite de sons for atingido, priorizar o "Tiro do Player" sobre o "Passo do NPC distante".
3. **Pooling:** Não instanciar `AudioStreamPlayer` a cada tiro.

## 🔊 A Solução: `SmartAudio`

Nós usamos os recursos nativos da Godot (`AudioStream` e `AudioStreamRandomizer`) e os envolvemos em um sistema de gerenciamento inteligente.

### 1. SoundCue (Resource wrapper)

Um wrapper opcional que adiciona metadados ao `AudioStream`:

- **Stream:** O `AudioStream` nativo (pode ser um `.wav` único ou um `AudioStreamRandomizer`).
- **Concurrency:** `max_instances` (ex: 5).
- **Stealing Behavior:** Se lotar, `IGNORE_NEW` ou `STEAL_OLDEST`?
- **Cooldown:** Tempo mínimo entre triggers (ex: evitar "metralhadora" de som de hit).

### 2. SoundManager (O Maestro)

Um Singleton (`Sounds`) que gerencia um Pool de AudioStreamPlayers.

- **Fire and Forget:** `Sounds.play(sound_cue, global_position)`
- **Pooling:** Reutiliza players para evitar instanciamento em runtime.
- **Bus Routing:** Garante que sons de UI vão para o bus UI e SFX para SFX.

---

### 3. Workflow Automatizado (The Scanner)

Em vez de criar `SoundCues` manualmente para cada som, o plugin inclui um **Gerador de Manifesto**:

1. **Scan:** Percorre pastas definidas (`res://assets/sfx/footsteps`).
2. **Group:** Agrupa arquivos por pasta (`footstep_01.wav`, `footstep_02.wav`).
3. **Generate:** Cria/Atualiza automaticamente recursos `AudioStreamRandomizer` (Playlists) para cada grupo.
4. **Manifest:** Salva um dicionário global de acesso rápido.

> **Resultado:** Adicione um arquivo `.wav` na pasta, rode o script, e ele já está pronto para uso no jogo como `Sounds.play("footsteps")`.

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
