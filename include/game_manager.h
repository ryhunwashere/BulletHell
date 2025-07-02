// Game manager
#pragma once

#include "player/player.h"
extern Player player;

void InitGame();
void UpdateGame(float deltaTime);
void DrawGame();
void UnloadGame();
