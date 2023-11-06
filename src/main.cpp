<<<<<<< HEAD
#include "../include/engine/Game.h"

int main(void)
{

    int screenWidth = 800;
    int screenHeight = 450;

    Game game{screenHeight,screenWidth,"Window",60};

    while(!game.GameShouldClose())
    {
        game.Tick();
    }
     
    return 0;
=======
#include "include/raylib.h"

int main(void)
{
    InitWindow(800, 450, "Window");

    SetTargetFPS(60);
;
    while (!WindowShouldClose())
    {   
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText(TextFormat("FPS: %i", GetFPS()), 10,10,20, BLACK);
        EndDrawing();
    }

    CloseWindow();

    return 0;
>>>>>>> 5ceab17bc04045dc243fb4e03d0f070e46da8f71
}