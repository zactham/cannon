//
// Main loop for our cannon game
//

// we use the graphics API from SFML library
#include <SFML/Graphics.hpp>
#include "Game.h"

    
//
// main function
//



int main()
{
    Game game;
    game.setup();
    game.run();
       return 0;
}

