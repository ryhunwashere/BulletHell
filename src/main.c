#include <raylib.h>
#include <stdio.h>

#include "config.h"
#include "player.h"
#include "bullet_player.h"
#include "audio.h"

float bulletVelocity = 600.0f;
float shootCooldown = 0.1f;
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
            Vector2 playerPos = PlayerGetBulletSpawnPos(&player, 0);

            Vector2 bulletMidDirection = { 0, -1 };
            Vector2 bulletDiagLeftDirection = { -0.5, -1 };
            Vector2 bulletDiagRightDirection = { 0.5, -1 };
            Vector2 bulletRightDirection = { 1, 0 };
            Vector2 bulletLeftDirection = { -1, 0 };

            SpawnPlayerBulletCircle(playerPos, bulletMidDirection, bulletVelocity, 10, circleBulletSprite);
            SpawnPlayerBulletRect(playerPos, bulletDiagLeftDirection, bulletVelocity, rectBulletSize, 0, rectBulletSprite);
            SpawnPlayerBulletRect(playerPos, bulletDiagRightDirection, bulletVelocity, rectBulletSize, 0, rectBulletSprite);
            SpawnPlayerBulletCircle(playerPos, bulletRightDirection, bulletVelocity, 10, circleBulletSprite);
            SpawnPlayerBulletCircle(playerPos, bulletLeftDirection, bulletVelocity, 10, circleBulletSprite);

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