# Library Plugin

**Ferramentas de Editor e Gestão de Assets.**

Este plugin é uma coleção de ferramentas de produtividade para o Editor Godot, totalmente independente do runtime do jogo. Ele não injeta dependências no código do gameplay.

## 🔧 Componentes

### Library (Bottom Panel)

Um painel centralizado para gerenciamento de assets e recursos da suite.

> **Arquitetura Híbrida:** UI em GDScript (`.tscn`) rodando sobre lógica C++.

#### Abas Principais:

1. **Assets:** Navegador visual para recursos.
2. **Editor:** Ferramentas e utilitários.
3. **Factory:** Criador de Resources.

### Utilities

- Funções auxiliares de editor.

## 📦 Integração

Este plugin é **Passivo**. Ele não é necessário para que o jogo rode, servindo apenas para acelerar o workflow de desenvolvimento no Editor.
