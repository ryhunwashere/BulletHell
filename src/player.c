#include "player.h"

const float PLAYER_SCALE = 2;

void InitPlayer(Player *player)
{
    player->position = (Vector2){500, 500};
    player->baseSpeed = 500.0f;
    player->hitboxRadius = 4.0f * PLAYER_SCALE;
    player->grazeRadius = 16.0f * PLAYER_SCALE;
    player->texture = LoadTexture("../assets/player/player_sprite.png");
}

void UpdatePlayer(Player *player)
{
    float speed = player->baseSpeed;

    if (IsKeyDown(KEY_LEFT_SHIFT))
        speed *= 0.5f;

    if (IsKeyDown(KEY_RIGHT))
        player->position.x += speed * GetFrameTime();
    if (IsKeyDown(KEY_LEFT))
        player->position.x -= speed * GetFrameTime();
    if (IsKeyDown(KEY_UP))
        player->position.y -= speed * GetFrameTime();
    if (IsKeyDown(KEY_DOWN))
        player->position.y += speed * GetFrameTime();
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
        0.0f, // rotation
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
