#include "../include/engine/Game.h"


int main(int argc, char* argv[])
{

    int screenWidth = 1600/1.5;
    int screenHeight = 900/1.5; 
    
    Game game{screenHeight,screenWidth,"Window",60, argc, argv};

    while(!game.GameShouldClose())
    {
        game.Tick();
    }
     
    return 0;
}