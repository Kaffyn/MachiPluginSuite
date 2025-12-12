# Memento

> **A Camada de Persistência.**
> Sistema de Serialização e SaveGame de alta performance, focado em estruturas de dados complexas (Resources e Scene Graphs).

---

## 🏛️ Arquitetura

O Memento abstrai a complexidade de `FileAccess` e JSON/Binary parsing.

1. **Resource-Oriented:** O Schema do Save é definido por Resources (`SaveProfile`, `SaveSchema`).
2. **Server/Singleton:** `MementoManager` executa a serialização em threads separadas.
3. **Interfaces:** Nodes implementam métodos para definir _o que_ salvar.

### Core Classes

#### `SaveProfile` (Resource)

Representa um "Slot" de save no disco. Contém metadados (`SaveSlot`) e o blob de dados.

- **Metadados:** Data, Hora, Screenshot, Local, Playtime.
- **Blob:** Os dados binários serializados.

#### `MementoManager` (Singleton)

Autoload responsável por:

- **Async IO:** Salvar/Carregar sem congelar o jogo.
- **Slot Management:** Gerenciar múltiplos slots (AutoSave, QuickSave, Manual).
- **Encryption:** Criptografia opcional dos dados.

#### `Saveable` (Interface / Node)

Pode ser um Node ou uma Interface que os objetos implementam.

- `func serialize() -> Dictionary`: Retorna o estado atual.
- `func deserialize(data: Dictionary)`: Restaura o estado.

---

## 💾 Formato

Utiliza o formato binário nativo da Godot (`var_to_bytes`/`bytes_to_var`) ou custom wrappers C++ para máxima velocidade em saves gigantes.
