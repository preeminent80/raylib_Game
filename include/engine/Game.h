#pragma once
#include "../raylib.h"
class Game 
{
public:
    Game(int windowHeight, int windowWidth, const char* windowName, int targetFps, int argc, char* argv[]);
    Game(const Game& other) = delete;
    Game& operator=(const Game& other) = delete;
    ~Game() noexcept;
    bool GameShouldClose();
    void Tick();
private:
    void Update();
    void Render();
};