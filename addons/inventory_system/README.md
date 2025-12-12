# Inventory System

**A Mochila do Herói.**

Sistema de inventário modular, flexível e data-driven, projetado para integração nativa com o Ability System (GAS).

## 🌟 Funcionalidades Principais

### Data-Driven Items

- Itens são Resources (`Item.tres`).
- Composição via **Componentes**: Adicione `EquippableComponent`, `ConsumableComponent`, `QuestItemComponent` para definir comportamento.

### Inventory Container

- Recurso `Inventory` que gerencia slots, peso e empilhamento.
- Suporte a múltiplos inventários (Mochila, Bau, Equipamento).

### Integração com GAS

- Itens podem conceder **Habilidades** (Skills).
- Equipamentos podem modificar **Atributos** (Stats) e aplicar **Efeitos** (Buffs/Debuffs).

## 🛠️ Editor

- Painel dedicado para criação e balanceamento de itens.
- Visualização de loot tables.
