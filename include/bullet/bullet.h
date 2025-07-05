#pragma once
#include <raylib.h>
#include "config.h"

typedef enum
{
    BULLET_CIRCLE,
    BULLET_RECT,
    BULLET_CUSTOM
} BulletType;

typedef struct
{
    Vector2 position;
    Vector2 direction;
    BulletType type;
    float radius;       // for circle bullets
    Vector2 size;       // for rect bullets
    float speed;
    float rotation;
    Texture2D sprite;   // default or custom
    bool active;
} Bullet;

void InitBullets(Bullet bullets[], int maxBullets);
void SetBulletDefaultTextures(Texture2D circleTexture, Texture2D rectTexture);
void SpawnBulletCircle(Bullet bullets[], int maxBullets, Vector2 spawnPos, Vector2 direction, float speed, float radius, Texture2D sprite);
void SpawnBulletRect(Bullet bullets[], int maxBullets, Vector2 spawnPos, Vector2 direction, float speed, Vector2 size, float rotation, Texture2D sprite);
void UpdateBullet(Bullet bullets[], int maxBullets, float deltaTime);
void DrawBullet(Bullet bullets[], int maxBullets);
