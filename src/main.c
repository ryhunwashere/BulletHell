#include <raylib.h>
#include <stdio.h>

#include "config.h"
#include "player.h"
#include "bullet_player.h"
#include "audio.h"

float bulletVelocity = 1000.0f;
float shootCooldown = 0.08f;
float shootTimer = 0.0f;

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib Bullet Hell Test");
    InitPlayerBullets();
    InitAudioComponents();
    PlayMusicTrack(0);

    Player player;
    InitPlayer(&player);

    Texture2D circleBulletSprite = LoadTexture("../assets/bullets/CircleBullet1.png");
    Texture2D rectBulletSprite = LoadTexture("../assets/bullets/PlayerBullet1.png");
    Vector2 rectBulletSize = { 50, 20 };

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();
        shootTimer += GetFrameTime();

        UpdateMusicPlayer();

        // Update player movement
        UpdatePlayer(&player);

        // Shoot bullet
        if (IsKeyDown(KEY_X) && shootTimer >= shootCooldown)
        {
            Vector2 bulletMidPos = PlayerGetBulletSpawnPos(&player, 0, 10);
            Vector2 bulletLeftPos = PlayerGetBulletSpawnPos(&player, -40, 10);
            Vector2 bulletRightPos = PlayerGetBulletSpawnPos(&player, 40, 10);

            Vector2 bulletMidDir = { 0, -1 };
            Vector2 bulletLeftDir = { 0, -1 };
            Vector2 bulletRightDir = { 0, -1 };

            SpawnPlayerBulletCircle(bulletMidPos, bulletMidDir, bulletVelocity, 10, circleBulletSprite);
            SpawnPlayerBulletRect(bulletLeftPos, bulletLeftDir, bulletVelocity, rectBulletSize, 0, rectBulletSprite);
            SpawnPlayerBulletRect(bulletRightPos, bulletRightDir, bulletVelocity, rectBulletSize, 0, rectBulletSprite);

            PlaySoundFX(0);

            shootTimer = 0.0f;
        }

        UpdatePlayerBullet(deltaTime);

        // Draw
        BeginDrawing();
        ClearBackground(BLACK);

        DrawPlayer(&player);
        DrawPlayerBullet();

        DrawFPS(10, 10);
        DrawText(TextFormat("Active bullets: %d", CountActivePlayerBullets()), 10, 40, 20, WHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}