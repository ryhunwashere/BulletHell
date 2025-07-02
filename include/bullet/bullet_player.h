#pragma once
#include <raylib.h>

extern Texture2D circleBulletSprite;
extern Texture2D rectBulletSprite;

// Initialize player bullets and set them all to inactive state.
void InitPlayerBullets();

// Load player bullet textures.
void LoadPlayerBulletTextures();

// Spawn/activate player bullet with circle hitbox.
void SpawnPlayerBulletCircle(Vector2 spawnPosition, Vector2 direction, float speed, float radius, Texture2D sprite);

// Spawn/activate player bullet with rectangle hitbox.
void SpawnPlayerBulletRect(Vector2 spawnPosition, Vector2 direction, float speed, Vector2 size, float rotation, Texture2D sprite);

// Update player bullet's position based on delta time and deactivate it if it goes beyond the game window.
void UpdatePlayerBullet(float deltaTime);

// Draw the player bullet.
void DrawPlayerBullet();

// Helper function to get count of currently active player bullets.
int CountActivePlayerBullets();
