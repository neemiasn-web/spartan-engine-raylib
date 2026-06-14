#include "world.h"
#include <stdlib.h>

World InitWorld(void) {
    World world = { 0 };
    
    // Criar um heightmap procedural simples (já que não temos assets externos ainda)
    Image image = GenImageChecked(64, 64, 8, 8, DARKGRAY, GRAY);
    // Simular relevo (opcional: carregar de arquivo se existir)
    // Image image = LoadImage("assets/textures/heightmap.png"); 
    
    Mesh mesh = GenMeshHeightmap(image, (Vector3){ 100, 10, 100 });
    world.terrain = LoadModelFromMesh(mesh);
    
    // Textura para o terreno
    Image terrainTex = GenImageChecked(1024, 1024, 32, 32, GREEN, DARKGREEN);
    world.terrain.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTextureFromImage(terrainTex);
    
    UnloadImage(image);
    UnloadImage(terrainTex);
    
    world.position = (Vector3){ -50.0f, 0.0f, -50.0f };
    
    return world;
}

void DrawWorld(World world) {
    DrawModel(world.terrain, world.position, 1.0f, WHITE);
}

void UnloadWorld(World world) {
    UnloadModel(world.terrain);
}
