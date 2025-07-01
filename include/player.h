// Module for handling the player
#pragma once
#include <raylib.h>

typedef struct Player
{
    Vector2 position;
    float baseSpeed;
    float hitboxRadius;
    float grazeRadius;
    Texture2D texture;
} Player;

void InitPlayer(Player* player);                                    // Create & initialize player
void UpdatePlayer(Player* player);                                  // Update player every frame
void DrawPlayer(Player* player);                                    // Draw player's sprite
Vector2 PlayerGetBulletSpawnPos(Player* player, float paddingTop);  // Make bullets spawn from top middle of player
