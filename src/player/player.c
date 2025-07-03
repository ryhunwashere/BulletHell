#include "player/player.h"
#include "config.h"
#include <raymath.h>        // for clamping the movement

void InitPlayer(Player *player)
{
    player->position = (Vector2){500, 500};
    player->baseSpeed = PLAYER_SPEED;
    player->hitboxRadius = 4.0f * PLAYER_SCALE;
    player->grazeRadius = 16.0f * PLAYER_SCALE;
    player->texture = LoadTexture("../assets/player/player_sprite.png");

    if (player->texture.id == 0)
    {
        TraceLog(LOG_ERROR, "Failed to load player texture!");
    }
}

void UpdatePlayer(Player *player, float deltaTime)
{
    float speed = player->baseSpeed;

    if (IsKeyDown(KEY_LEFT_SHIFT))
        speed = 200.0f;

    if (IsKeyDown(KEY_RIGHT))
        player->position.x += speed * deltaTime;
    if (IsKeyDown(KEY_LEFT))
        player->position.x -= speed * deltaTime;
    if (IsKeyDown(KEY_UP))
        player->position.y -= speed * deltaTime;
    if (IsKeyDown(KEY_DOWN))
        player->position.y += speed * deltaTime;
    
    // Prevent the player to move beyond the game window
    player->position.x = Clamp(player->position.x, player->hitboxRadius, SCREEN_WIDTH - player->hitboxRadius);
    player->position.y = Clamp(player->position.y, player->hitboxRadius, SCREEN_HEIGHT - player->hitboxRadius);
}

void DrawPlayer(Player *player)
{
    float scaledWidth = player->texture.width * PLAYER_SCALE;
    float scaledHeight = player->texture.height * PLAYER_SCALE;

    // Source rect
    Rectangle source = {0, 0, player->texture.width, player->texture.height};

    // Destination rect: centered on player->position
    Rectangle dest = {
        player->position.x, // center X
        player->position.y, // center Y
        scaledWidth,
        scaledHeight};

    // Origin rect: center of texture (so it rotates/scales around center)
    Vector2 origin = {scaledWidth / 2, scaledHeight / 2};

    // Draw
    DrawTexturePro(
        player->texture,
        source,
        dest,
        origin,
        0.0f,
        WHITE);

    // Show hitbox when slowed
    if (IsKeyDown(KEY_LEFT_SHIFT))
    {
        // Draw hitbox
        DrawCircleV(player->position, player->hitboxRadius, RED);

        // Draw graze area
        DrawCircleLinesV(player->position, player->grazeRadius, SKYBLUE);
    }
}

Vector2 PlayerGetBulletSpawnPos(Player *player, float offsetX, float offsetY)
{
    float scaledHeight = player->texture.height * PLAYER_SCALE;

    // Top middle → center.x, center.y - half height - offsetY
    return (Vector2){player->position.x + offsetX, player->position.y - (scaledHeight / 2.0f) - offsetY};
}
