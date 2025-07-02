#include <raylib.h>
#include "config.h"
#include "game_manager.h"

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib Bullet Hell Test");
    InitGame();

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        
        UpdateGame(deltaTime);

        BeginDrawing();
        ClearBackground(BLACK);

        DrawGame();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
