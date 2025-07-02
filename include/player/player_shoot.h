// Module for handling player's shooting
#pragma once
#include <raylib.h>
#include <player/player.h>

void InitPlayerShooting();
void UpdatePlayerShooting(Player *player, float deltaTime);
void UnloadPlayerShooting();