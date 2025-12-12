# Level Design: O Mundo de Aethelgard

O jogo é dividido em 3 Zonas principais, cada uma com uma estética e desafios únicos.

## 🗺️ Zona 1: A Vila Decrepita (Hub Central)

**Tema:** Outono, melancolia, cores quentes mas desbotadas.
**Música:** Violino triste, vento.

### Locais de Interesse

1.  **Praça Central:** Onde fica a estátua do Fundador (Checkpoint).
2.  **Cabana de Orion:** Local trancado no início. Contém a bancada de Alquimia (Crafting).
3.  **Portão Norte:** Saída para a floresta. Bloqueado inicialmente por raízes (requer machado ou fogo).
4.  **Loja da Velha Mara:** Vende poções e ingredientes básicos.

### NPCs

- **Ancião Thorne:** Dá a Quest Principal.
- **Mara:** Mercadora.

---

## 🌲 Zona 2: Bosque dos Sussurros (Exploração)

**Tema:** Floresta densa, névoa roxa, perigo.
**Música:** Percussão tribal, sons de animais.

### Layout

- Labiríntico, mas com clareiras abertas para combate.
- **Verticalidade:** O jogador deve achar rampas para subir em colinas e pegar baús.

### Desafios Noturnos

- À noite, a névoa fica mais densa (Shader).
- Plantas espinhosas se abrem e causam dano ao toque.

### Pontos Chave

- **Clareira do Lobo:** Mini-boss (Lobo Alpha) que guarda a "Chave das Ruínas".
- **Acampamento Abandonado:** Local de descanso (Save point).

---

## 🏛️ Zona 3: Ruínas Antigas (Dungeon)

**Tema:** Pedra, musgo, tecnologia mágica azul brilhante.
**Música:** Sintetizadores retrowave misturados com orquestra.

### Mecânicas de Puzzle

1.  **Blocos de Pressão:** O jogador deve empurrar blocos de pedra sobre botões no chão para abrir portas.
2.  **Tochas Mágicas:** Acender tochas na ordem correta (dica visual na parede) usando Frascos de Fogo.

### Layout da Dungeon

- **Sala 1:** Entrada e combate simples (Slimes).
- **Sala 2:** Puzzle das Tochas.
- **Sala 3:** Corredor das Armadilhas (Espinhos que saem do chão em ritmo).
- **Sala 4:** Arena do Boss (Ent Corrompido).
- **Sala 5:** Câmara do Núcleo (Cutscene Final).

---

## Estrutura de Cenas Godot

```
res://scenes/levels/
├── Introduction.tscn (Menu Principal + Cutscene Inicial)
├── Zone1_Village.tscn
├── Zone2_Forest.tscn
├── Zone3_Ruins.tscn
└── EndCredits.tscn
```
