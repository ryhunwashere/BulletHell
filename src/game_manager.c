#include <raylib.h>
#include "game_manager.h"

// Player module
#include "player/player.h"
#include "player/player_shoot.h"

// Enemy module
#include "enemy/enemy.h"

// Bullet module
#include "bullet/bullet_player.h"

// Audio module
#include "audio.h"

// Global config
#include "config.h"

// Player instance
Player player;

void InitGame()
{
    InitPlayer(&player);
    InitPlayerBullets();
    InitPlayerShooting(&player);

    InitAudioComponents();
    PlayMusicTrack(0);
}

void UpdateGame(float deltaTime)
{
    UpdatePlayer(&player, deltaTime);
    UpdatePlayerShooting(&player, deltaTime);
    UpdatePlayerBullet(deltaTime);
    
    UpdateMusicPlayer();
}

void DrawGame()
{
    DrawPlayer(&player);
    DrawPlayerBullet();

    DrawFPS(10, 10);
    DrawText(TextFormat("Active bullets: %d", CountActivePlayerBullets()), 10, 40, 20, WHITE);
}

void UnloadGame()
{
    UnloadPlayerShooting();
    UnloadAudioComponents();
}
