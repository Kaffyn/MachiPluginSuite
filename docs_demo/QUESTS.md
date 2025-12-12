# Livro de Missões (Quests)

Gerenciado pelo plugin **Quest System**.

## 🌟 Quest Principal: A Fonte da Corrupção

_Purifique a Árvore da Vida e salve a vila._

### Etapa 1: Preparação

- **ID:** `main_q1_prep`
- **Objetivo:** Coletar 5x Erva-de-Cura na orla da floresta.
- **Recompensa:** Receita: Poção de Vida, 50 XP.

### Etapa 2: O Rastro

- **ID:** `main_q2_track`
- **Objetivo:** Encontrar o Diário de Orion na Floresta (`Zone2`).
- **Gatilho:** AreaTrigger no Acampamento Abandonado.

### Etapa 3: A Chave

- **ID:** `main_q3_key`
- **Objetivo:** Derrotar o Lobo Alpha e obter a Chave das Ruínas.
- **Recompensa:** Acesso à Zona 3.

### Etapa 4: O Sacrifício

- **ID:** `main_q4_boss`
- **Objetivo:** Derrotar o Ent Corrompido.
- **Recompensa:** Fim do Jogo.

---

## 🌙 Side Quest: Herança Perdida

_Recupere o colar da Velha Mara._

- **Doador:** Velha Mara.
- **Requisito:** Falar com ela após completar a Etapa 1 da Main Quest.
- **Objetivo:** Encontrar o "Colar de Rubi" que caiu no poço da vila.
- **Twist:** O poço só seca à noite (Lógica do `Gaia`). O jogador deve esperar anoitecer para descer no poço.
- **Recompensa:** Desconto de 20% na loja + Item "Anel da Ganância" (+Gold drop).

---

# Estrutura de Quest Resource

Exemplo de configuração no Godot (`QuestResource.tres`):

```gdscript
title = "A Fonte da Corrupção"
description = "Orion sumiu. A árvore morre. Preciso agir."
steps = [
    { "id": "gather_herbs", "type": "collect", "target": "item_herb", "amount": 5 },
    { "id": "find_diary", "type": "visit", "target": "loc_camp" }
]
rewards = [ "item_potion_recipe" ]
```
