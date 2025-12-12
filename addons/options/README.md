# Options

> **O Gerenciador de Configuração.**
> Sistema unificado para gerenciar Vídeo, Áudio, Inputs e Gameplay Settings, com persistência automática e geração de UI.

---

## 🏛️ Arquitetura

Centraliza a "chatice" de configurar menus de opções.

1. **Resource-Oriented:** `SettingsSchema` define quais opções existem.
2. **Server/Singleton:** `OptionsManager` aplica as mudanças no Hardware/Engine.
3. **UI:** Geração automática ou Binding fácil.

### Core Classes

#### `SettingsSchema` (Resource)

Define a estrutura do menu.

- Ex: `VideoSection` contém `ResolutionOption`, `VSyncOption`.
- Ex: `AudioSection` contém `MasterVolume`, `MusicVolume`.

#### `OptionsManager` (Singleton)

- Carrega/Salva o arquivo `user://settings.cfg`.
- Aplica as configurações usando as APIs nativas da Godot (`DisplayServer`, `AudioServer`, `InputMap`).
- Garante que as configurações sejam aplicadas no start do jogo.

#### `OptionProfile` (Resource)

Preset de configurações (ex: "Low", "Ultra").

#### `OptionsContainer` (Node)

Gerador de UI dinâmico. Recebe um `SettingsSchema` e cria os `OptionWidgets` automaticamente na tela.

#### `InputRemapper` (Helper)

- API simplificada para remapear `InputActions` em runtime.
- Resolve conflitos de teclas duplicadas.

---

## 🎮 Features

- **Vídeo:** Resolução, Fullscreen/Windowed, VSync, FPS Limit, MSAA/FXAA.
- **Áudio:** Controle de Bus automapeado (linear ou logarítmico).
- **Input:** Remapping com suporte a controle e teclado.
