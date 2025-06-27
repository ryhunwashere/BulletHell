#pragma once
#include <raylib.h>

#define MAX_BULLETS 1000

typedef struct
{
    Vector2 position;
    Vector2 direction;
    bool active;
} Bullet;

void InitBullets();                                                             // Initialize all bullets in the pool to be inactive.
void SpawnBullet(Vector2 spawnPos, Vector2 direction);
void UpdateBullets(float deltaTime, float bulletVelocity, int screenHeight);
void DrawBullets();
