#include "../include/engine/Game.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::init(int windowHeight, int windowWidth, const char* windowName, int targetFps)
{
    InitWindow(windowWidth, windowHeight, windowName);

    SetTargetFPS(targetFps);

}

void Game::Close()
{
    CloseWindow();
}


bool Game::notRunning()
{
    return WindowShouldClose();
}

void Game::update()
{

}

void Game::render()
{
    BeginDrawing();



    EndDrawing();
}