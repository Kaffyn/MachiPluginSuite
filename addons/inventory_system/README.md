# Inventory System

**A Mochila do Herói.**

Sistema de inventário modular, flexível e data-driven, projetado para integração nativa com o Ability System (GAS).

## 🌟 Funcionalidades e Arquitetura

### Nodes & Componentes

- **`InventoryContainer` (Logic):** O cérebro do inventário.
- **`Slot` (UI):** Componente visual pronto para Drag & Drop.
- **`CraftingStation`:** Workbenches que processam receitas.

### Resources (Data)

- **`Item`:** A definição base.
- **`ItemCategory`:** Filtros e regras de organização.
- **`Inventory`:** O Storage serializável.
- **`LootTable`:** Regras de drop probabilístico.
- **`Recipe`:** Regras de input/output para Crafting.

### Integração com GAS

- **Skills:** Itens podem conceder habilidades ativas ou passivas.
- **Stats:** Equipamentos aplicam `AttributeModifiers`.

## 🛠️ Editor

- Painel dedicado para criação e balanceamento de itens.
- Visualização de loot tables.
