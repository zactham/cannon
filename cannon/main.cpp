//
// Main loop for our cannon game
//

// we use the graphics API from SFML library
#include <SFML/Graphics.hpp>

//
// main function
//
int main()
{
	// set up ball shape
	sf::CircleShape ballShape;
	ballShape.setPosition(100, 100);
	ballShape.setRadius(10.0f);
	ballShape.setFillColor(sf::Color::Blue);

	// set up window
	sf::RenderWindow window{ { 800, 600}, "Cannon" };
	window.setFramerateLimit(60);

	//
	// main game loop
	//
	while (window.isOpen())
	{
        // check for exit
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window or hit escape to exit
            if ( (event.type == sf::Event::Closed) ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) )
            {
                window.close();
            }
        }

        // erase window
        window.clear();
        
        // update/draw objects
		window.draw(ballShape);

		// draw window
		window.display();
	}

    return 0;
}
