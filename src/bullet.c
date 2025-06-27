#include "bullet.h"

Bullet bullets[MAX_BULLETS] = {0};

void InitBullets()
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        bullets[i].active = false;
    }
}

void SpawnBullet(Vector2 spawnPos, Vector2 direction)
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        if (!bullets[i].active) // Find inactive bullets
        {
            bullets[i].position = spawnPos;
            bullets[i].direction = direction;
            bullets[i].active = true;
            break;
        }
    }
}

void UpdateBullets(float deltaTime, float bulletVelocity, int screenHeight)
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        bullets[i].position.x += bullets[i].direction.x * bulletVelocity * deltaTime;
        bullets[i].position.y += bullets[i].direction.y * bulletVelocity * deltaTime;

        if (bullets[i].position.y < 0 || bullets[i].position.y > screenHeight) // Deactivate bullet if goes beyond screen height
        {
            bullets[i].active = false;
        }
    }
}

void DrawBullets()
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        if (bullets[i].active)
        {
            DrawCircleV(bullets[i].position, 5, RED);
        }
    }
}