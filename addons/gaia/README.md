# Gaia - Environment System

> **"A Vida do Mundo."**

O **Gaia** é o plugin responsável por simular o ambiente vivo do jogo, controlando Ciclo Dia/Noite, Clima (Weather) e Estações (Seasons). Ele foca puramente na estética e simulação ambiental, delegando eventos de gameplay para a **Synapse**.

---

## 🌎 Módulos

### 1. Chronos (Day/Night Cycle)

Controla a passagem do tempo e a iluminação global **2D**.

- **TimeCurve:** Recurso `Curve` para definir a cor do `CanvasModulate` baseada na hora (0.0 a 1.0).
- **DateSystem:** Dia, Mês, Ano.
- **Target:** Controla um `CanvasModulate` na cena para tintura global.

### 2. Atmosphere (Weather)

Gerenciador de estados climáticos **2D**.

- **WeatherResource:** Define um clima (Chuva, Neve, Tempestade).
  - `particles: PackedScene` (Prefab com `GPUParticles2D`).
  - `audio_ambience: AudioStream` (Loop de fundo).
  - `overlay_shader: ShaderMaterial` (Opcional, ex: Distorção de calor).

### 3. Seasons (Estações)

Macrociclo que altera as probabilidades de clima e a paleta visual do mundo.

- `SeasonManager`: Controla transição suave entre Primavera -> Verão -> Outono -> Inverno.

---

## 🔌 Integrações

### Synapse

O Gaia é um grande emissor de eventos.

- `Gaia.pulse("time", "hour_changed", {hour=8})`
- `Gaia.pulse("weather", "started", {type="rain"})`
- **Exemplo:** NPCs vão para casa à noite porque a Behavior Tree deles escuta o evento `hour_changed`.

### Sounds Plugin

- Gaia usa o **Sounds** para tocar ambiências de forma inteligente (crossfade entre chuva e sol), sem implementar lógica de áudio própria.

---

## 🗺️ Roadmap

- [ ] Implementar `DayNightCycle` (Node) e `TimeCurve` (Resource).
- [ ] Implementar `WeatherController` e `WeatherResource`.
- [ ] Integração com `WorldEnvironment`.
- [ ] Conectar com Synapse Signals.
