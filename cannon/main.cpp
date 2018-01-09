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
    
    game.window.setFramerateLimit(60);
    
    
    //
    // main game loop
    //
    while (game.window.isOpen())
    {
        // check for exit
        sf::Event event;
        while (game.window.pollEvent(event))
        {
            // Close window or hit escape to exit
            if ( (event.type == sf::Event::Closed) ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) )
            {
                game.window.close();
            }
        }
        
        game.keyboardCommands();
        
        game.windowOperations();
    }
    return 0;
}

