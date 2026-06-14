#include "raylib.h"
#include "raymath.h"
#include "rcamera.h"
#include "world.h"
#include "player.h"
#include "ecs_module.h"
#include "audio_module.h"
#include <stdio.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

int main(void) {
    // 1. Inicialização
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Spartan Engine - 3D Prototype");
    InitAudio();
    SetTargetFPS(60);

    // 2. Setup do Mundo e Jogador
    World world = InitWorld();
    Player player = InitPlayer((Vector3){ 0.0f, 2.0f, 4.0f });
    
    Camera3D camera = { 0 };
    camera.position = player.position;
    camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    DisableCursor();

    // 3. Setup do ECS
    ecs_world_t *ecs = InitECS();
    
    // Criar uma entidade de teste no ECS
    ecs_entity_t cube = ecs_new(ecs);
    ecs_set(ecs, cube, Position, {{ 2.0f, 1.0f, 2.0f }});
    ecs_set(ecs, cube, Velocity, {{ 0.0f, 0.5f, 0.0f }}); // Vai flutuar
    
    Model testModel = LoadModelFromMesh(GenMeshCube(1.0f, 1.0f, 1.0f));
    ecs_set(ecs, cube, Renderable, { testModel, BLUE });

    // 4. Carregar Shaders
    Shader pbrShader = LoadShader("assets/shaders/pbr.vs", "assets/shaders/pbr.fs");
    // Aplicar shader ao modelo do mundo e do ECS
    world.terrain.materials[0].shader = pbrShader;
    testModel.materials[0].shader = pbrShader;

    // Loop Principal
    while (!WindowShouldClose()) {
        float dt = GetFrameTime();

        // 5. Atualização
        UpdateCamera(&camera, CAMERA_FIRST_PERSON);
        UpdatePlayer(&player, &camera, dt);
        UpdateECS(ecs, dt);

        // Lógica simples de "quicar" para o cubo do ECS
        const Position *p = ecs_get(ecs, cube, Position);
        if (p->position.y > 5.0f || p->position.y < 0.5f) {
            const Velocity *v = ecs_get(ecs, cube, Velocity);
            ecs_set(ecs, cube, Velocity, {{ 0.0f, -v->velocity.y, 0.0f }});
        }

        // 6. Desenho
        BeginDrawing();
            ClearBackground(SKYBLUE);

            BeginMode3D(camera);
                DrawWorld(world);
                
                // O ECS RenderSystem desenha as entidades
                // (Como o sistema está no pipeline do flecs, ele roda no ecs_progress)
                // Mas para controle Spartan, podemos iterar manualmente se preferir.
                
                // Desenha grade de referência
                DrawGrid(20, 1.0f);
            EndMode3D();

            // HUD / UI
            DrawRectangle(10, 10, 250, 120, Fade(SKYBLUE, 0.5f));
            DrawRectangleLines(10, 10, 250, 120, BLUE);
            
            DrawFPS(20, 20);
            DrawText("SPARTAN ENGINE v0.1", 20, 50, 20, RAYWHITE);
            DrawText(TextFormat("POS: %.2f, %.2f, %.2f", camera.position.x, camera.position.y, camera.position.z), 20, 80, 15, YELLOW);
            
            // Crosshair
            DrawCircle(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 2, RED);

        EndDrawing();
    }

    // 7. Limpeza
    UnloadWorld(world);
    UnloadModel(testModel);
    UnloadShader(pbrShader);
    ecs_fini(ecs);
    CloseAudio();
    CloseWindow();

    return 0;
}
