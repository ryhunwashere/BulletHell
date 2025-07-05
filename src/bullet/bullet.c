#include "bullet/bullet.h"
#include <math.h> // for atan2f function
#include <stdio.h>

static Texture2D gDefaultCircleTexture = {0};
static Texture2D gDefaultRectTexture = {0};

// Local master function for spawning bullets
static void spawnBullet(Bullet bullets[], int maxBullets, Vector2 spawnPos, Vector2 direction, float speed, BulletType type, float radius, Vector2 size, float rotation, Texture2D sprite)
{
    // If rotation is set to 0, bullets will automatically face the direction it is heading to
    if (rotation == 0)
    {
        rotation = atan2f(direction.y, direction.x) * RAD2DEG;
    }

    for (int i = 0; i < maxBullets; i++)
    {
        if (!bullets[i].active)
        {
            bullets[i].position = spawnPos;
            bullets[i].direction = direction;
            bullets[i].speed = speed;
            bullets[i].rotation = rotation;
            bullets[i].type = type;
            bullets[i].radius = radius;
            bullets[i].size = size;
            bullets[i].sprite = sprite;
            bullets[i].active = true;
            break;
        }
    }
}

void InitBullets(Bullet bullets[], int maxBullets)
{
    for (int i = 0; i < maxBullets; i++)
        bullets[i].active = false;
}

void SetBulletDefaultTextures(Texture2D circleTexture, Texture2D rectTexture)
{
    gDefaultCircleTexture = circleTexture;
    gDefaultRectTexture = rectTexture;
}

void SpawnBulletCircle(Bullet bullets[], int maxBullets, Vector2 spawnPos, Vector2 direction, float speed, float radius, Texture2D sprite)
{
    if (sprite.id == 0)
        sprite = gDefaultCircleTexture;
    spawnBullet(bullets, maxBullets, spawnPos, direction, speed, BULLET_CIRCLE, radius, (Vector2){radius * 2, radius * 2}, 0, sprite);
}

void SpawnBulletRect(Bullet bullets[], int maxBullets, Vector2 spawnPos, Vector2 direction, float speed, Vector2 size, float rotation, Texture2D sprite)
{
    if (sprite.id == 0)
        sprite = gDefaultRectTexture;
    spawnBullet(bullets, maxBullets, spawnPos, direction, speed, BULLET_RECT, 0, size, rotation, sprite);
}

void UpdateBullet(Bullet bullets[], int maxBullets, float deltaTime)
{
    for (int i = 0; i < maxBullets; i++)
    {
        if (bullets[i].active)
        {
            bullets[i].position.x += bullets[i].direction.x * bullets[i].speed * deltaTime;
            bullets[i].position.y += bullets[i].direction.y * bullets[i].speed * deltaTime;
            
            // Deactivate bullets that goes beyond the window + some margins
            if (bullets[i].position.x > SCREEN_WIDTH + SCREEN_MARGIN ||
                bullets[i].position.x < 0 - SCREEN_MARGIN || 
                bullets[i].position.y > SCREEN_HEIGHT + SCREEN_MARGIN || 
                bullets[i].position.y < 0 - SCREEN_MARGIN)
            {
                bullets[i].active = false;
            }
        }
    }
}

void DrawBullet(Bullet bullets[], int maxBullets)
{
    for (int i = 0; i < maxBullets; i++)
    {
        if (bullets[i].active)
        {
            Bullet *b = &bullets[i];

            DrawTexturePro(b->sprite,
                           (Rectangle){0, 0, b->sprite.width, b->sprite.height},            // source
                           (Rectangle){b->position.x, b->position.y, b->size.x, b->size.y}, // dest
                           (Vector2){b->size.x / 2, b->size.y / 2},                         // origin
                           b->rotation,
                           (Color){ 255, 255, 255, 150 });                                  // reduced bullet opacity
        }
    }
}
