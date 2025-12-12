# Personagens Não-Jogáveis (NPCs)

Os NPCs utilizam o sistema `Gaia` para rotinas diárias e `Director` para diálogos.

## 👴 Ancião Thorne

_O líder preocupado da vila._

- **Personalidade:** Sábio, mas cansado e sem esperança.
- **Localização:** Praça Central (Dia), Sua Casa (Noite).
- **Rotina (Gaia Schedule):**
  - `06:00`: Acorda e vai para a praça.
  - `12:00`: Almoça no banco da praça.
  - `18:00`: Volta para casa e tranca a porta.
- **Diálogos:**
  - _Inicial:_ "Elara, a barreira não vai aguentar. Precisamos de Orion."
  - _Pós-Quest:_ "Você salvou a todos nós, minha criança."

## 🧙‍♀️ Velha Mara

_A mercadora excêntrica._

- **Personalidade:** Gananciosa, mas tem um bom coração.
- **Localização:** Loja (Sempre).
- **Serviço:** Abre a UI de Loja (`InventorySystem`).
- **Quests:** Dá a sidequest "Herança Perdida".

## 👻 Mestre Orion (Memória/Boss)

_O mentor desaparecido._

- **Aparência:** Aparece em flashbacks como um homem gentil. Como Boss, é uma árvore retorcida com o rosto dele no tronco.
- **Papel:** Motor da narrativa. Não interage como NPC padrão.

---

## Sistema de Diálogo (Implementation Info)

Usamos o plugin **Director** para criar árvores de diálogo.

- **Recurso:** `Dialogue_Thorne_Intro.tres`
- **Estrutura:**
  - `Node Start`: "Olá Elara."
  - `Node Choice`:
    - Opção A: "Onde está Orion?" -> Vai para `Node ExplainOrion`.
    - Opção B: "Vou ajudar." -> Vai para `Node AcceptQuest`.
