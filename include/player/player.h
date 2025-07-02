// Module for initializing player and handling movement
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

// Create & initialize player.
void InitPlayer(Player* player);

// Update player every frame.
void UpdatePlayer(Player *player, float deltaTime);

// Draw player's sprite.
void DrawPlayer(Player* player);

// Set X and Y offset of bullet spawn position relative to the center of player.
Vector2 PlayerGetBulletSpawnPos(Player* player, float offsetX, float offsetY);
