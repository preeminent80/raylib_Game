#include "include/raylib.h"

int main(void)
{
    InitWindow(800, 450, "Window");
    ToggleFullscreen();

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
}