//
// Main loop for our cannon game
//

// we use the graphics API from SFML library
#include <SFML/Graphics.hpp>


//
// our own ball class
//
class Ball
{
private:
    sf::CircleShape ballShape;
    int ballX;
    int ballY;
    int radius;
    
public:
    // constructor
    Ball()
    {
        ballX = 0;
        ballY = 0;
        radius = 0;
    }
    
    void setX(int i)
    {
        ballX = i;
    }
    void setY(int i)
    {
        ballY = i;
    }
    int getX()
    {
        return ballX;
    }
    int getY()
    {
        return ballY;
    }
    void setSize(int r)
    {
        radius = r;
    }
    int getSize()
    {
        return radius;
    }
    
    sf::CircleShape& getBall()
    {
        return ballShape;
    }
    
    
    
};

//
// main function
//

int main()
{
    int speed = 10;
    
    // set up ball shape
    Ball ballShape;
    ballShape.setX(500);
    ballShape.setY(100);
    ballShape.setSize(20);
    ballShape.getBall().setPosition(ballShape.getX(), ballShape.getY());
    ballShape.getBall().setRadius(ballShape.getSize());
    ballShape.getBall().setFillColor(sf::Color::White);
    
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
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            ballShape.setX(ballShape.getX());
            ballShape.setY(ballShape.getY()-speed);
            ballShape.getBall().setPosition(ballShape.getX(), ballShape.getY());
            
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            
            ballShape.setX(ballShape.getX());
            ballShape.setY(ballShape.getY()+speed);
            ballShape.getBall().setPosition(ballShape.getX(), ballShape.getY());
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            
            ballShape.setX(ballShape.getX()-speed);
            ballShape.setY(ballShape.getY());
            ballShape.getBall().setPosition(ballShape.getX(), ballShape.getY());
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            
            ballShape.setX(ballShape.getX()+speed);
            ballShape.setY(ballShape.getY());
            ballShape.getBall().setPosition(ballShape.getX(), ballShape.getY());
        }
        
        
        // erase window
        window.clear();
        
        // update/draw objects
        window.draw(ballShape.getBall());
        
        // draw window
        window.display();
    }
    
    return 0;
}

