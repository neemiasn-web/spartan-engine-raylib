#include "world.h"
#include <stdlib.h>

World InitWorld(void) {
    World world = { 0 };

    Mesh mesh = GenMeshPlane(100.0f, 100.0f, 10, 10);
    world.terrain = LoadModelFromMesh(mesh);

    Image terrainTex = GenImageChecked(1024, 1024, 64, 64, (Color){50,130,50,255}, (Color){35,100,35,255});
    world.terrain.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTextureFromImage(terrainTex);
    UnloadImage(terrainTex);

    world.position = (Vector3){ 0.0f, 0.0f, 0.0f };

    return world;
}

void DrawWorld(World world) {
    DrawModel(world.terrain, world.position, 1.0f, WHITE);
}

void UnloadWorld(World world) {
    UnloadModel(world.terrain);
}
