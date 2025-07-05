#include "player/player_shoot.h"
#include "bullet/bullet_player.h"
#include "config.h"
#include "audio.h"
#include <raylib.h>
#include <raymath.h>

static float shootCooldown = SHOOT_COOLDOWN;
static float shootTimer = SHOOT_TIMER;
static float bulletVelocity = PLAYER_BULLET_VELOCITY;

Texture2D circleBulletSprite;
Texture2D rectBulletSprite;
static Vector2 rectBulletSize = {50, 20};

void InitPlayerShooting(Player *player)
{
    circleBulletSprite = LoadTexture("../assets/bullets/CircleBullet1.png");
    rectBulletSprite = LoadTexture("../assets/bullets/PlayerBullet1.png");

    if (circleBulletSprite.id == 0 || rectBulletSprite.id == 0)
    {
        TraceLog(LOG_ERROR, "Failed to load bullet textures!");
    }
}

// Set angle of the bullet shot in degrees.
static Vector2 shootAngle(int angle)
{
    Vector2 origin = (Vector2){ 0, -1 };    // towards up
    int ang = DEG2RAD * angle;

    Vector2 result = Vector2Rotate(origin, ang);
    
    return result;
}

void UpdatePlayerShooting(Player *player, float deltaTime)
{
    shootTimer += deltaTime;
    Vector2 bulletDir = shootAngle(0);

    if (IsKeyDown(KEY_X) && shootTimer >= shootCooldown)
    {
        Vector2 bulletMidPos = PlayerGetBulletSpawnPos(player, 0, 5);

        Vector2 bulletLeft1Pos = PlayerGetBulletSpawnPos(player, -20, 5);
        Vector2 bulletLeft2Pos = PlayerGetBulletSpawnPos(player, -40, 5);
        Vector2 bulletLeft3Pos = PlayerGetBulletSpawnPos(player, -60, 5);

        Vector2 bulletRight1Pos = PlayerGetBulletSpawnPos(player, 20, 5);
        Vector2 bulletRight2Pos = PlayerGetBulletSpawnPos(player, 40, 5);
        Vector2 bulletRight3Pos = PlayerGetBulletSpawnPos(player, 60, 5);

        SpawnPlayerBulletCircle(bulletMidPos, bulletDir, bulletVelocity, 10, circleBulletSprite);

        SpawnPlayerBulletRect(bulletLeft1Pos, bulletDir, bulletVelocity, rectBulletSize, 0, rectBulletSprite);
        SpawnPlayerBulletRect(bulletLeft2Pos, bulletDir, bulletVelocity, rectBulletSize, 0, rectBulletSprite);
        SpawnPlayerBulletCircle(bulletLeft3Pos, bulletDir, bulletVelocity, 10, circleBulletSprite);

        SpawnPlayerBulletRect(bulletRight1Pos, bulletDir, bulletVelocity, rectBulletSize, 0, rectBulletSprite);
        SpawnPlayerBulletRect(bulletRight2Pos, bulletDir, bulletVelocity, rectBulletSize, 0, rectBulletSprite);
        SpawnPlayerBulletCircle(bulletRight3Pos, bulletDir, bulletVelocity, 10, circleBulletSprite);

        PlaySoundFX(0);
        shootTimer = 0.0f;
    }
}

void UnloadPlayerShooting()
{
    UnloadTexture(circleBulletSprite);
    UnloadTexture(rectBulletSprite);
}