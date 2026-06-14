#include "ecs_module.h"
#include "raymath.h"

// Sistema de Movimentação
void MoveSystem(ecs_iter_t *it) {
    Position *p = ecs_field(it, Position, 1);
    Velocity *v = ecs_field(it, Velocity, 2);

    for (int i = 0; i < it->count; i++) {
        p[i].position.x += v[i].velocity.x * it->delta_time;
        p[i].position.y += v[i].velocity.y * it->delta_time;
        p[i].position.z += v[i].velocity.z * it->delta_time;
    }
}

// Sistema de Renderização
void RenderSystem(ecs_iter_t *it) {
    Position *p = ecs_field(it, Position, 1);
    Renderable *r = ecs_field(it, Renderable, 2);

    for (int i = 0; i < it->count; i++) {
        DrawModel(r[i].model, p[i].position, 1.0f, r[i].color);
    }
}

ECS_COMPONENT_DECLARE(Position);
ECS_COMPONENT_DECLARE(Velocity);
ECS_COMPONENT_DECLARE(Renderable);

ecs_world_t* InitECS(void) {
    ecs_world_t *world = ecs_init();

    // Registrar Componentes
    ECS_COMPONENT_DEFINE(world, Position);
    ECS_COMPONENT_DEFINE(world, Velocity);
    ECS_COMPONENT_DEFINE(world, Renderable);

    // Registrar Sistemas
    ECS_SYSTEM(world, MoveSystem, EcsOnUpdate, Position, Velocity);
    ECS_SYSTEM(world, RenderSystem, EcsOnStore, Position, Renderable);

    return world;
}

void UpdateECS(ecs_world_t *world, float dt) {
    ecs_progress(world, dt);
}

void DrawECS(ecs_world_t *world) {
    // No Flecs, podemos rodar sistemas específicos de renderização
    // ou simplesmente iterar. Aqui o RenderSystem já está no EcsOnStore.
}
