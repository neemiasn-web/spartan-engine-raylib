#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

typedef struct {
    Vector3 position;
    Vector3 velocity;
    float height;
    float radius;
    BoundingBox bounds;
} Player;

Player InitPlayer(Vector3 pos);
void UpdatePlayer(Player *player, Camera3D *camera, float dt);
bool CheckPlayerCollision(Player *player, BoundingBox box);

#endif
