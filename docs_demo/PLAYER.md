# O Jogador: Elara (Alquimista)

Este documento detalha as mecânicas, atributos e habilidades da personagem principal.

## 📊 Atributos Base (Ability System)

| Atributo         | Valor Inicial | Descrição                                 |
| :--------------- | :------------ | :---------------------------------------- |
| **Health (HP)**  | 100           | Pontos de Vida. Regenera fora de combate. |
| **Mana (MP)**    | 50            | Usado para habilidades especiais.         |
| **Stamina (SP)** | 80            | Usado para correr e esquivar.             |
| **Speed**        | 120           | Velocidade de movimento em pixels/sec.    |
| **Defense**      | 0             | Redução de dano plano.                    |

## 🎮 Controles e Ações

- **Movimento (WASD):** Movimentação omnidirecional. (Consome SP ao correr com Shift).
- **Interagir (E):** Falar com NPCs, pegar itens, abrir baús.
- **Ataque Primário (Botão Esquerdo):** Combate corpo-a-corpo com Cajado.
- **Habilidade (Botão Direito):** Arremessar Frasco Alquímico selecionado.
- **Esquiva (Espaço):** Dash rápido na direção do movimento (Invencibilidade curta).

## ⚔️ Habilidades (Skills)

### 1. Golpe de Cajado (Melee)

- **Tipo:** Ativo, Instantâneo.
- **Dano:** 15 Físico.
- **Custo:** 0.
- **Descrição:** Um golpe básico. Se acertar 3 vezes seguidas, o terceiro golpe causa empurrão (Knockback).

### 2. Arremessar Frasco (Ranged/AoE)

- **Tipo:** Projétil com arco parabólico.
- **Custo:** 1 Item "Frasco" do inventário correspondente.
- **Variações:**
  - **Fogo:** Cria uma poça de fogo por 5s (Dano por segundo).
  - **Gelo:** Congela inimigos por 2s.
  - **Ácido:** Reduz a defesa do inimigo em 50%.

### 3. Transmutação de Emergência (Ultimate)

- **Tipo:** Buff (Desbloqueado no final do jogo).
- **Custo:** 50 MP.
- **Descrição:** Transforma a pele de Elara em pedra por 3s, negando todo dano, mas impedindo movimento.

## 📷 Câmera (Osmo)

- **Top-Down Fixa:** Ângulo levemente inclinado.
- **Deadzone:** A câmera tem um pequeno atraso (lag) para dar sensação de peso.
- **Shake:**
  - Leve: Ao dar dano.
  - Pesado: Ao receber dano.
  - Contínuo: Durante tempestades ou terremotos.

## 🎒 Inventário Inicial

- 1x Cajado de Aprendiz (Equipado).
- 3x Poção de Vida Pequena.
- 5x Frasco Vazio.
