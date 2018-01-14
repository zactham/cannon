//
// Main loop for our cannon game
//

// we use the graphics API from SFML library
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Vector2f.h"

    
//
// main function
//



int main()
{
    
    Vector2f v(3, 1);
    v.normalize();
    printf ("%f , %f\n", v.getX(), v.getY()); // should print 5 , 5
    /*
    Vector2f v2(3,1);
    v2.copy (v); // v2 is now 5,5
    v2.add (v); // v2 is now 10,10
    printf ("%f , %f\n", v2.getX(), v2.getY()); // should print 5 , 5
    printf("%f , %f\n",v2.getLength());
     */
   Game game;
   game.setup();
   game.run();
       return 0;
}

