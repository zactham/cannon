//
// Main loop for our cannon game
//

// we use the graphics API from SFML library
#include <SFML/Graphics.hpp>


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
	while (true)
	{
		window.clear(sf::Color::Black);		// erase window

		// if escape is pressed, then exit the loop
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) 
			break;

		// update/draw objects
		window.draw(ballShape);

		// draw window
		window.display();
	}

	return 0;
}
