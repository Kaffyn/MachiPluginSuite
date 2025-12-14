# Gaia (Environment) - Planta Baixa

## Visão Geral

**Componente:** `MachiGaia` (Singleton `Gaia`)
**Responsabilidade:** Simular o ciclo de vida do mundo (Dia/Noite, Clima, Estações) e controlar o ambiente visual (2D/3D).

## Arquitetura

1.  **MachiGaia (C++):** Mantém o estado do tempo (`current_time`) e lógica de rotação do sol/cor do céu.
2.  **Wrappers (GDScript):** `setup_3d` permite injetar `WorldEnvironment` e `DirectionalLight3D` da cena atual.
3.  **Drivers:**
    *   **2D:** Controla `CanvasModulate` (Tintura global).
    *   **3D:** Controla `DirectionalLight3D` (Rotação) e `WorldEnvironment` (Sky).

## Planta Baixa (Blueprint)

```gdscript
## MachiGaia (C++ Singleton)
## Exposed as Autoload 'Gaia'

class_name MachiGaia extends Node

# Properties
var time: float # 0.0 to 24.0

# Methods
func set_time(value: float) -> void:
func get_time() -> float:
func set_weather(type: String) -> void:

# 3D Registration
func register_sky(world_env: Node) -> void:
func register_sun(sun: Node) -> void:
```

```gdscript
## Gaia (Autoload Wrapper)
## Extends MachiGaia to add GDScript helpers.

extends MachiGaia

# Helper to connect 3D nodes in one call
func setup_3d(environment: WorldEnvironment, sun: DirectionalLight3D) -> void:
```

## Dependências

-   **Nenhuma:** Gaia é um provedor de dados/visual.
