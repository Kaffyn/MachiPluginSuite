# Godot MBA: Diretrizes para Agentes de IA (GEMINI.md)

> **META-INSTRUÇÃO:** Este arquivo contém as **REGRAS IMUTÁVEIS** sobre como você (a IA) deve gerar código, documentação e estruturas neste projeto. Leia-o antes de tomar qualquer decisão arquitetural.

---

## 1. Regras de Documentação (`README.md`)

Todo plugin na pasta `addons/` deve possuir um `README.md` que funcione como um **GDD/PDD (Technical Design Document)**.

- ❌ **Proibido:** Readmes genéricos, curtos ou que apenas dizem "como instalar".
- ✅ **Obrigatório:** Documentos técnicos completos que explicam **O QUE** o sistema faz e **COMO** ele é arquitetado.

### Estrutura Obrigatória do README

1. **Visão Geral:** O propósito filosófico do componente.
2. **Arquitetura:** Diagramas ou explicações de fluxo de dados.
3. **Planta Baixa (Blueprint):** A seção mais importante (veja abaixo).

---

## 2. O Conceito de "Planta Baixa" (Blueprint)

Uma **Planta Baixa** é a especificação técnica dos scripts do plugin. Ela serve como a "interface pública" para que humanos e IAs entendam o sistema sem ler o código fonte.

### Regras da Planta Baixa:

1. **Formato:** Use blocos de código `gdscript`.
2. **Abrangência:** Deve cobrir **TODOS** os scripts principais (Classes, Singles, Resources).
3. **Conteúdo:**
   - `class_name` e `extends`.
   - **Sinais** (`signal name(args)`).
   - **Enums** exportados.
   - **Variáveis** exportadas.
   - **Métodos Públicos** com tipagem estrita (`func name(arg: Type) -> Ret:`) e comentários breves.
   - **NÃO** inclua implementação (corpo das funções).

---

## 3. Exemplo de Referência (Golden Sample)

Use este formato como gabarito para gerar novas Plantas Baixas.

### `AbilitySystemComponent` (Blueprint)

```gdscript
## AbilitySystemComponent (ASC)
##
## Componente central do GAS. Unifica dados e lógica.

@tool
class_name AbilitySystemComponent extends Node

# ==================== SIGNALS ====================

signal state_changed(old_state: State, new_state: State)
signal effect_applied(effect: Effect)
signal context_changed(category: String, value: int)

# ==================== PUBLIC API ====================

## Troca o estado atual, respeitando as regras de transição.
func change_state(new_state: State) -> void:

## Define uma variável de contexto para queries (ex: "Weapon", "Sword").
func set_context(category: String, value: int) -> void:

## Retorna o valor atual de um atributo (base + modificadores).
func get_stat(stat_name: String) -> Variant:

## Aplica um efeito de jogo (dano, cura, buff).
func apply_effect(effect: Effect) -> void:

## Lista todos os estados disponíveis no deck atual.
func get_all_available_states() -> Array[State]:
```
