# Itens e Crafting

Gerenciado pelo plugin **Inventory System**.

## 🧪 Consumíveis

| Ícone | Nome                 | Efeito               | Receita (Crafting)           |
| :---- | :------------------- | :------------------- | :--------------------------- |
| ❤️     | **Poção de Vida**    | Recupera 50 HP.      | 2x Erva-de-Cura + 1x Água    |
| ⚡     | **Poção de Stamina** | Recupera 100% SP.    | 2x Cogumelo-Veloz + 1x Água  |
| 🔥     | **Frasco de Fogo**   | Dano em área (Fogo). | 1x Óleo + 1x Pólvora         |
| 🧊     | **Frasco de Gelo**   | Congela inimigos.    | 1x Cristal de Gelo + 1x Água |

## 🗝️ Itens Chave (Key Items)

Sao itens que não podem ser vendidos ou descartados.

- **Cajado de Orion:** Arma inicial.
- **Diário de Orion:** Contém lore.
- **Chave das Ruínas:** Abre o portão da Zona 3.
- **Colar de Mara:** Item da Sidequest.

## ⚒️ Materiais de Crafting

Espalhados pelo mundo como "Coletáveis" (Nodes interativos).

- **Erva-de-Cura:** Comum na Vila.
- **Cogumelo-Veloz:** Comum na Floresta.
- **Minério de Ferro:** Encontrado nas Ruínas.
- **Cristal de Essência:** Drop de inimigos mágicos.

## 🛒 Loja da Mara (Tabela de Preços)

O `InventorySystem` permite definir valor de compra e venda.

- Compra:
  - Poção de Vida: 10 Gold
  - Ingredientes: 5 Gold
- Venda:
  - Itens de jogador valem 50% do preço de compra.

## Estrutura de Dados (ItemResource)

```gdscript
class_name ItemResource extends Resource

@export var id: String
@export var name: String
@export var icon: Texture2D
@export var max_stack: int = 99
@export var value: int = 10
@export var category: ItemCategory # Enum: Weapon, Potion, Key, Material
```
