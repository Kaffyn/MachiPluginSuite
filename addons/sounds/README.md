# Sounds (Machi Audio) - Planta Baixa

## Visão Geral

**Componente:** `MachiAudio2D` / `MachiAudio3D`
**Responsabilidade:** Tocar efeitos sonoros variados e espacializados a partir de recursos `SoundCue`, abstraindo a lógica de variação de pitch/volume.

## Arquitetura

1.  **SoundCue (Resource):** Container de áudios com regras de randomização.
2.  **MachiAudio (Nodes):** Wrappers de `AudioStreamPlayer` que sabem tocar `SoundCue`.
3.  **MachiSoundManager (Global):** Gerencia música e canais globais.

## Planta Baixa (Blueprint)

```gdscript
## SoundCue (Resource)
@export var audio_streams: Array[AudioStream]
@export var pitch_min: float = 1.0
@export var pitch_max: float = 1.0
@export var volume_min_db: float = 0.0
@export var volume_max_db: float = 0.0

func get_next_stream() -> AudioStream:
func get_next_pitch() -> float:
func get_next_volume() -> float:
```

```gdscript
## MachiAudio2D (Node)
extends AudioStreamPlayer2D

func play_cue(cue: SoundCue) -> void:
```

```gdscript
## MachiAudio3D (Node)
extends AudioStreamPlayer3D

func play_cue(cue: SoundCue) -> void:
```

## Dependências

-   **Nenhuma:** Sistema independente.
