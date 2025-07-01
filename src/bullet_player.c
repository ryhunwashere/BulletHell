#include "bullet.h"
#include <stdio.h>

static Bullet playerBullets[MAX_PLAYER_BULLETS];

void InitPlayerBullets()
{
    InitBullets(playerBullets, MAX_PLAYER_BULLETS);
}

void SpawnPlayerBulletCircle(Vector2 spawnPosition, Vector2 direction, float speed, float radius, Texture2D sprite)
{
    SpawnBulletCircle(playerBullets, MAX_PLAYER_BULLETS, spawnPosition, direction, speed, radius, sprite);
}

void SpawnPlayerBulletRect(Vector2 spawnPosition, Vector2 direction, float speed, Vector2 size, float rotation, Texture2D sprite)
{
    SpawnBulletRect(playerBullets, MAX_PLAYER_BULLETS, spawnPosition, direction, speed, size, rotation, sprite);
}

void UpdatePlayerBullet(float deltaTime)
{
    UpdateBullet(playerBullets, MAX_PLAYER_BULLETS, deltaTime, 1280, 720);
}

void DrawPlayerBullet()
{
    DrawBullet(playerBullets, MAX_PLAYER_BULLETS);
}

int CountActivePlayerBullets()
{
    int count = 0;
    for (int i = 0; i < MAX_PLAYER_BULLETS; i++)
    {
        if (playerBullets[i].active) count++;
    }
    return count;
}
