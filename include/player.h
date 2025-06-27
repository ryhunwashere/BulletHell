#pragma once

#include <raylib.h>

typedef struct
{
    Vector2 position;
    float width;
    float baseSpeed;
    Texture2D texture;
} Player;

void InitPlayer(Player* player);                        // Create & initialize player
void UpdatePlayer(Player* player, float deltaTime);     // Update player every frame
void DrawPlayer(Player* player);                        // Draw player
Vector2 PlayerGetBulletSpawnPos(Player* player);
