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
}