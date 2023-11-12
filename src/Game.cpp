#include "../include/engine/Game.h"
#include "../include/engine/Entity.h"
#include "../include/engine/Player.h"
#include "../include/engine/map.h"
#include <assert.h>
#include <iostream>
#include <unordered_map> 

//Player Dec
Player* newPLayer;

//Map dec
Map* map;


Game::Game(int windowHeight, int windowWidth, const char* windowName, int targetFps, int argc, char* argv[])
{
    assert(!GetWindowHandle()); //If Assertion Window Already Open
    InitWindow(windowWidth, windowHeight, windowName);
    SetTargetFPS(targetFps);

    //Testing Player Class
    newPLayer = new Player();
    newPLayer->init("res/PlayerSprites/Walk.png", {300,225},{64,128}, 3.0f); 

    //Map Init Under Dev
    map = new Map();
    map->AddLayer("res/Map/Ground.csv");
    map->TileSet("res/Map/Overworld.png", {640, 576}, {640/16,576/16}); 
    std::cout << map->reLayers[0].size();
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
    //Player
    
    newPLayer->update();
}
void Game::Render()
{
    ClearBackground(RAYWHITE);
    
    DrawText(TextFormat("FPS: %i", GetFPS()), 10, 10, 10, BLACK);
    newPLayer->render();

}
