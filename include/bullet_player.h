#pragma once
#include <raylib.h>

void InitPlayerBullets();
void SpawnPlayerBulletCircle(Vector2 spawnPosition, Vector2 direction, float speed, float radius, Texture2D sprite);
void SpawnPlayerBulletRect(Vector2 spawnPosition, Vector2 direction, float speed, Vector2 size, float rotation, Texture2D sprite);
void UpdatePlayerBullet(float deltaTime);
void DrawPlayerBullet();
int CountActivePlayerBullets();
