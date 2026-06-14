#ifndef ECS_MODULE_H
#define ECS_MODULE_H

#include <flecs.h>
#include "raylib.h"

// Componentes
typedef struct {
    Vector3 position;
} Position;

typedef struct {
    Vector3 velocity;
} Velocity;

typedef struct {
    Model model;
    Color color;
} Renderable;

// Component IDs
extern ECS_COMPONENT_DECLARE(Position);
extern ECS_COMPONENT_DECLARE(Velocity);
extern ECS_COMPONENT_DECLARE(Renderable);

// Funções do ECS
ecs_world_t* InitECS(void);
void UpdateECS(ecs_world_t *world, float dt);
void DrawECS(ecs_world_t *world);

#endif
