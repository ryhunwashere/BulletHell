#include "enemy/enemy.h"
#include <stdio.h>

#define MAX_ENEMIES 50

static Enemy enemyPool[MAX_ENEMIES];

void InitAllEnemies()
{
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        enemyPool[i].active = false;
    }
}

void UpdateEnemy(Enemy* enemy, float deltaTime)
{
    float speed = enemy->speed;
}

void SpawnEnemy(Vector2 pos, Texture2D texture, float speed, int health)
{
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        if (!enemyPool[i].active)
        {
            enemyPool[i].position = pos;
            enemyPool[i].texture = texture;
            enemyPool[i].speed = speed;
            enemyPool[i].health = health;
            enemyPool[i].active = true;
            break;
        }
    }
}

void UpdateAllEnemies(Enemy *enemy, float deltaTime)
{
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        if (enemyPool[i].active)
        {
            UpdateEnemy(&enemyPool[i], deltaTime);
        }
    }
}

void DrawAllEnemies() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemyPool[i].active) {
            DrawEnemy(&enemyPool[i]);
        }
    }
}

void DrawEnemy(Enemy *enemy)
{
    float scaledWidth = enemy->texture.width;
    float scaledHeight = enemy->texture.height;

    // Source rect
    Rectangle source = {0, 0, enemy->texture.width, enemy->texture.height};

    // Destination rect: centered on enemy->position
    Rectangle dest = {
        enemy->position.x, // center X
        enemy->position.y, // center Y
        scaledWidth,
        scaledHeight};

    // Origin rect: center of texture (so it rotates/scales around center)
    Vector2 origin = {scaledWidth / 2, scaledHeight / 2};

    // Draw
    DrawTexturePro(
        enemy->texture,
        source,
        dest,
        origin,
        0.0f, // rotation
        WHITE);

    // Draw enemy hitbox
    DrawRectangleV(enemy->position, enemy->hitbox, PINK);
}

Vector2 EnemyGetBulletSpawnPos(Enemy *enemy, float offsetY)
{
    float scaledHeight = enemy->texture.height;

    return (Vector2){enemy->position.x, enemy->position.y - (scaledHeight / 2.0f) - offsetY};
}
