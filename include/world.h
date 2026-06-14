#ifndef WORLD_H
#define WORLD_H

#include "raylib.h"

typedef struct {
    Model terrain;
    Texture2D heightmap;
    Vector3 position;
} World;

World InitWorld(void);
void DrawWorld(World world);
void UnloadWorld(World world);

#endif
