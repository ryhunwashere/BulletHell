#include "player.h"

void InitPlayer(Player* player)
{
    player->position = (Vector2){500, 500};
    player->width = 50.0f;
    player->baseSpeed = 500.0f;
    player->texture = LoadTexture("../assets/player/player.png");
}

void UpdatePlayer(Player* player)
{
    float speed = player->baseSpeed;

    if (IsKeyDown(KEY_LEFT_SHIFT))
        speed *= 0.5f;

    if (IsKeyDown(KEY_RIGHT)) player->position.x += speed * GetFrameTime();
    if (IsKeyDown(KEY_LEFT))  player->position.x -= speed * GetFrameTime();
    if (IsKeyDown(KEY_UP))    player->position.y -= speed * GetFrameTime();
    if (IsKeyDown(KEY_DOWN))  player->position.y += speed * GetFrameTime();
}

void DrawPlayer(Player* player)
{
    DrawTextureV(player->texture, player->position, WHITE);
}

Vector2 PlayerGetBulletSpawnPos(Player* player)
{
    return (Vector2){ player->position.x + player->width / 2.0f, player->position.y };
}
