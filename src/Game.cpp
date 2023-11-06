#include "../include/engine/Game.h"
#include "../include/engine/Entity.h"
#include <assert.h>
#include <iostream>

Entity* testEntity; //Test Entity

Game::Game(int windowHeight, int windowWidth, const char* windowName, int targetFps)
{
    assert(!GetWindowHandle()); //If Assertion Window Already Open
    InitWindow(windowWidth, windowHeight, windowName);
    SetTargetFPS(targetFps);

    //Testing Entity Class
    testEntity = new Entity("../res/TestSpriteSheet.png", 400,225,3,3,288, 288, 2);
    testEntity->SelectSpriteFromSheet(0,1);
    
}
Game::~Game()
{
    assert(GetWindowHandle()); //If Assertion Window Already Closed
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
    testEntity->update();
    
}
void Game::Render()
{
    ClearBackground(RAYWHITE);
    DrawText(TextFormat("FPS: %i", GetFPS()), 10, 10, 10, BLACK);
    testEntity->render();
}