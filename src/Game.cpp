#include "../include/engine/Game.h"

Game::Game(int windowHeight, int windowWidth, const char* windowName, int targetFps)
{
    InitWindow(windowWidth, windowHeight, windowName);
    SetTargetFPS(targetFps);
}

Game::~Game()
{
    CloseWindow();
}

bool Game::GameShouldClose()
{
    return WindowShouldClose();
}

void Game::Tick()
{
    BeginDrawing();
        Update();
        Render();
    EndDrawing();
}

void Game::Update()
{

}

void Game::Render()
{
    ClearBackground(RAYWHITE);
    DrawText(TextFormat("FPS: %i", GetFPS()), 10, 10, 10, BLACK);
}