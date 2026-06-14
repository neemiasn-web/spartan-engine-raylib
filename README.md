# Spartan Engine - Protótipo 3D com Raylib

Este projeto é um protótipo de motor de jogo 3D (estilo *Immersive Sim* ou FPS) desenvolvido em C99, utilizando a biblioteca **raylib** e o sistema **Flecs ECS**. Ele segue a filosofia "Spartan-programmer", focando em código limpo, modular e eficiente, sem o uso de editores visuais.

## Funcionalidades Implementadas

*   **Arquitetura e Configuração Inicial:**
    *   Linguagem C99 com nomenclatura PascalCase/camelCase.
    *   Estrutura de projeto modular (`src`, `include`, `assets`).
    *   Inicialização de janela e loop principal com FPS fixo (60 FPS).

*   **Sistemas de Câmera e Controle:**
    *   Câmera em primeira pessoa (`Camera3D`).
    *   Movimentação básica (WASD + Mouse) através de `UpdateCamera()`.

*   **Construção do Mundo 3D:**
    *   Geração de terreno (heightmap) procedural simples.
    *   Carregamento de modelos 3D (cubos de teste).

*   **Lógica Avançada e Renderização:**
    *   Integração do paradigma ECS (Entity Component System) com **Flecs** para gerenciamento de entidades.
    *   Sistema de renderização básico com suporte a shaders PBR (Physically Based Rendering) simplificado.
    *   Shaders GLSL (`pbr.vs`, `pbr.fs`) para um pipeline de renderização customizado.

*   **Interface e Áudio:**
    *   Inicialização do dispositivo de áudio.
    *   UI básica (FPS, informações de posição da câmera, crosshair).

## Estrutura do Projeto

```
spartan_engine/
├── assets/
│   ├── audio/        # Para arquivos de áudio (sons, música)
│   ├── models/       # Para modelos 3D (IQM, glTF, etc.)
│   ├── shaders/      # Shaders GLSL (pbr.vs, pbr.fs)
│   └── textures/     # Texturas (heightmaps, diffuse, normal, etc.)
├── include/
│   ├── audio_module.h
│   ├── ecs_module.h
│   ├── player.h
│   └── world.h
├── src/
│   ├── audio_module.c
│   ├── ecs_module.c
│   ├── main.c
│   ├── player.c
│   └── world.c
├── Makefile
└── README.md
```

## Como Compilar e Executar

### Pré-requisitos

Certifique-se de ter as seguintes dependências instaladas em seu sistema:

*   `build-essential` (gcc, g++)
*   `cmake`
*   `libasound2-dev`, `libx11-dev`, `libxrandr-dev`, `libxi-dev`, `libgl1-mesa-dev`, `libglu1-mesa-dev`, `libxcursor-dev`, `libxinerama-dev`, `libwayland-dev`, `libxkbcommon-dev` (para raylib)

As bibliotecas **raylib** e **Flecs** foram compiladas e instaladas a partir do código fonte em `/usr/local/lib` e `/usr/local/include`.

### Compilação

1.  Navegue até o diretório `spartan_engine`:
    ```bash
    cd /home/ubuntu/spartan_engine
    ```
2.  Compile o projeto usando o `Makefile` fornecido:
    ```bash
    make
    ```
    Isso criará o executável `spartan_engine` no diretório `bin/`.

### Execução

Após a compilação, execute o protótipo:

```bash
./bin/spartan_engine
```

## Controles

*   **WASD:** Movimentação para frente, trás, esquerda e direita.
*   **Mouse:** Controle da direção da câmera.
*   **ESC:** Fechar a janela do jogo.

## Observações Técnicas

*   **raylib:** A biblioteca raylib é utilizada para renderização, gerenciamento de janela, input e áudio. Ela é auto-contida e não requer dependências externas adicionais além das listadas acima.
*   **Flecs ECS:** O Flecs é um sistema Entity Component System (ECS) que permite uma arquitetura de jogo modular e escalável. Componentes como `Position`, `Velocity` e `Renderable` são definidos e processados por sistemas (`MoveSystem`, `RenderSystem`).
*   **PBR Básico:** Um shader PBR simplificado foi implementado para demonstrar materiais mais realistas. Ele inclui cálculo de iluminação difusa básica.
*   **Licença:** O projeto segue a licença zlib/libpng, permitindo modificação e distribuição livre.

---

**Desenvolvido por:Neemias Hermes 
