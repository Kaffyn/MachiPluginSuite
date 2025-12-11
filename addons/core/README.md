# Core Plugin

**O Alicerce do Machi Plugin Suite.**

Este plugin fornece a infraestrutura compartilhada para todos os outros sistemas (Ability System, Inventory, Behavior Tree, etc).

## 🔧 Componentes

### CoreLibrary (Bottom Panel)
Um painel centralizado para gerenciamento de assets e recursos da suite. Substitui as libraries individuais de cada plugin, unificando a experiência de edição.
- Implementado em C++ para máxima performance.
- Navegador de Assets.
- Factory de Resources.

### Utilities
- Funções auxiliares de baixo nível compartilhadas.
- Definições de macros e tipos comuns.

## 📦 Integração
Este plugin é uma dependência obrigatória para o uso completo da Suite. Ele é registrado automaticamente como um tool.
