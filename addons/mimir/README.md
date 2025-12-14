# Mimir (Save System) - Planta Baixa

## Visão Geral

**Componente:** `MimirManager` (Singleton)
**Responsabilidade:** Gerenciar a persistência de dados do mundo (Save/Load). Implementa o padrão Memento para capturar estados de Nodes recursivamente.

## Arquitetura

O Mimir é o guardião da memória. Ele não sabe *como* salvar um inimigo específico, mas sabe como pedir para o inimigo se salvar.

1.  **Mimir (C++):** Itera sobre a árvore de nodes.
2.  **SaveInterface (Interface):** Nodes que implementam métodos de save (`_save_state`, `_load_state`) são processados.
3.  **Yggdrasil:** Aciona o Mimir durante transições de cena.

## Planta Baixa (Blueprint)

```gdscript
## Mimir (Autoload Wrapper)
## Global Save/Load Manager.
##
## Usage:
## Mimir.save_level_state(get_tree().current_scene)

extends MimirManager

# Inherits C++ API:
# func save_level_state(root: Node) -> void
# func load_level_state(root: Node) -> void
# func get_last_saved_state() -> Dictionary
```

## Dependências

-   **Nenhuma:** O Mimir é independente. O Yggdrasil depende dele.
