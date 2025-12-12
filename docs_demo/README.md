# Documentação Técnica: Machi Demo

Bem-vindo à documentação do projeto de demonstração da **Machi Plugin Suite**.

Este projeto é uma "Vertical Slice" completa de um RPG de Ação Top-Down, projetado para validar e exibir o poder de todos os 11 plugins trabalhando em harmonia.

## 📚 Índice de Documentação

A documentação foi dividida em múltiplos arquivos para facilitar a leitura e manutenção:

1. [GDD (Game Design Document)](../GDD.md)
   - Visão geral do design, mecânicas, inimigos e fluxo de jogo. Documento mestre de design na raiz do projeto.
2. [Arquitetura do Projeto](./ARCHITECTURE.md)
   - Estrutura de pastas, padrões de código e integração de sistemas.
3. [Guia de Plugins](./PLUGINS.md)
   - Detalhes técnicos da implementação dos 11 plugins.

### 📜 Detalhes do Design

- [História e Lore](./STORY.md)
- [O Jogador (Mecânicas)](./PLAYER.md)
- [Bestiário (Inimigos)](./ENEMIES.md)
- [Mundo e Levels](./LEVELS.md)
- [NPCs e Diálogos](./NPCS.md)
- [Livro de Quests](./QUESTS.md)
- [Itens e Crafting](./ITEMS.md)

## 🚀 Como Executar

1. **Compilação:** Certifique-se de que todos os plugins em `addons/` foram compilados.
   - Execute `python build.py` na raiz do projeto.
2. **Godot:** Abra o projeto na versão 4.x da Godot Engine.
3. **Play:** Carregue a cena `res://scenes/levels/Zone1_Village.tscn` e pressione F5.

## ⚠️ Notas de Desenvolvimento

- **Idiomas:** Toda a documentação técnica oficial está em **Português (PT-BR)**.
- **Padrão de Código:** Utilizamos GDScript tipado (`: int`, `: String`) e Style Guide oficial da Godot.
