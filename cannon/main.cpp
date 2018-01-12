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
    Vector2f v(1, 1);
    v.multiply (5);
    printf ("%f , %f\n", v.getX(), v.getY()); // should print 5 , 5
    
    Vector2f v2;
    v2.copy (v); // v2 is now 5,5
    v2.add (v); // v2 is now 10,10
    
    Game game;
    game.setup();
    game.run();
       return 0;
}

