#include "raylib.h"

//------------------------------------------------------------------------------------------
// Types and Structures Definition
//------------------------------------------------------------------------------------------
typedef enum GameScreen
{
    MENU,
    GAMEPLAY
} GameScreen;


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    int screenWidth = 1360;
    int screenHeight = 720;

    // Initialization
    //----------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "Raylib Test Window");
    SetTargetFPS(60);
    Texture2D playerTexture = LoadTexture("../assets/player/ReimuTopdown.png");
    Vector2 playerPosition = {100, 200};
    //----------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------
        float playerSpeed = 200.0f;

        if (IsKeyDown(KEY_RIGHT))
            playerPosition.x += (playerSpeed * GetFrameTime());
        if (IsKeyDown(KEY_LEFT))
            playerPosition.x -= (playerSpeed * GetFrameTime());
        if (IsKeyDown(KEY_UP))
            playerPosition.y -= (playerSpeed * GetFrameTime());
        if (IsKeyDown(KEY_DOWN))
            playerPosition.y += (playerSpeed * GetFrameTime());
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        DrawFPS(10, 10);
        ClearBackground(RAYWHITE);
        DrawTextureV(playerTexture, playerPosition, WHITE);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    UnloadTexture(playerTexture);

    CloseWindow();
    return 0;
}
