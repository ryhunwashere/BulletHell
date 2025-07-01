// Module for handling the player
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
void UpdatePlayer(Player* player);                      // Update player every frame
void DrawPlayer(Player* player);                        // Draw player's sprite
Vector2 PlayerGetBulletSpawnPos(Player* player);        // Ensure player's bullets are spawned from top middle position of the player
