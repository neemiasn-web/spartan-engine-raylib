#include "player.h"
#include "raymath.h"
#include "rcamera.h"

Player InitPlayer(Vector3 pos) {
    Player p = { 0 };
    p.position = pos;
    p.height = 1.8f;
    p.radius = 0.4f;
    return p;
}

void UpdatePlayer(Player *player, Camera3D *camera, float dt) {
    // Sincroniza posição do jogador com a câmera (ou vice-versa)
    // No modo CAMERA_FIRST_PERSON do raylib, o UpdateCamera já faz muito disso,
    // mas aqui poderíamos adicionar lógica de física/gravidade.
    
    player->position = camera->position;
    
    // Atualiza bounding box para colisões
    player->bounds = (BoundingBox){
        (Vector3){ player->position.x - player->radius, player->position.y - player->height, player->position.z - player->radius },
        (Vector3){ player->position.x + player->radius, player->position.y, player->position.z + player->radius }
    };
}

bool CheckPlayerCollision(Player *player, BoundingBox box) {
    return CheckCollisionBoxes(player->bounds, box);
}
