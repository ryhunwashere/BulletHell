// Module for handling enemy entities
#pragma once
#include <raylib.h>

typedef struct Enemy
{
    Vector2 position;
    Vector2 size;
    Vector2 hitbox;
    float speed;
    int health;
    Texture2D texture;
    bool active;
} Enemy;

// Initialize all enemies in the pool in inactive state.
void InitAllEnemies();

// Update Enemy every frame.
void UpdateEnemy(Enemy* enemy, float deltaTime);

void SpawnEnemy(Vector2 pos, Texture2D texture, float speed, int health);

// Draw Enemy's sprite.
void DrawEnemy(Enemy* enemy);

// Set X and Y offset of bullet spawn position relative to the center of Enemy.
Vector2 EnemyGetBulletSpawnPos(Enemy *enemy, float offsetY);
