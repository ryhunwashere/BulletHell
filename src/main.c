#include <raylib.h>
#include <stdio.h>

#include "bullet.h"
#include "player.h"

float bulletVelocity = 800.0f;
float shootCooldown = 0.05f;
float shootTimer = 0.0f;

int main()
{
    InitWindow(1280, 720, "Raylib Bullet Hell Test");
    InitBullets();

    Player player;
    InitPlayer(&player);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        shootTimer += dt;

        // Update player movement
        UpdatePlayer(&player, dt);

        // Shoot bullet
        if (IsKeyDown(KEY_X) && shootTimer >= shootCooldown)
        {
            Vector2 spawnPos = PlayerGetBulletSpawnPos(&player);
            Vector2 bulletDirection = { 0, -1 };
            SpawnBullet(spawnPos, bulletDirection);
            shootTimer = 0.0f;
        }

        UpdateBullets(dt, bulletVelocity, 720);

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawPlayer(&player);
        DrawBullets();

        DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}