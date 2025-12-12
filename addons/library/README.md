# Core Plugin

**O Alicerce do Machi Plugin Suite.**

Este plugin fornece a infraestrutura compartilhada para todos os outros sistemas (Ability System, Inventory, Behavior Tree, etc).

## 🔧 Componentes

### CoreLibrary (Bottom Panel)

Um painel centralizado para gerenciamento de assets e recursos da suite. Substitui as libraries individuais de cada plugin, unificando a experiência de edição.

> **Arquitetura Híbrida:** Combina o poder bruto do C++ (GDExtension) com a flexibilidade de UI do GDScript/Scenes (`.tscn`).

#### Abas Principais:

1.  **Assets:** Navegador visual otimizado para Resources do Machi.
2.  **Editor:** Ferramentas especializadas e Inspectores customizados.
3.  **Factory:** Criador rápido de Resources complexos (ex: Item com componentes).

### Utilities

- Funções auxiliares de baixo nível compartilhadas.
- Definições de macros e tipos comuns.

## 📦 Integração

Este plugin é uma dependência obrigatória para o uso completo da Suite. Ele é registrado automaticamente como um tool.
