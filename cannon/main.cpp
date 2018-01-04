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

class Cannon
{
private:
    sf::RectangleShape cannonShape;
    float cannonX;
    float cannonY;
    float width;
    float height;
    int angle;
    
public:
    // constructor
    Cannon()
    {
        cannonX = 0;
        cannonY = 0;
        width = 0;
        height = 0;
    }
    
    void setX(float i)
    {
        cannonX = i;
    }
    void setY(float i)
    {
        cannonY = i;
    }
    float getX()
    {
        return cannonX;
    }
    float getY()
    {
        return cannonY;
    }
    void setWidth(float w)
    {
        width = w;
    }
    float getWidth()
    {
        return width;
    }
    void setHeight(float h)
    {
        height = h;
    }
    float getHeight()
    {
        return height;
    }
    void setAngle(int a)
    {
        angle = a;
    }
    float getAngle()
    {
        return angle;
    }
    
    
    sf::RectangleShape& getCannon()
    {
        return cannonShape;
    }
    
    
    
};


//
// main function
//

int main()
{
    int speed = 10;
    int angle = 15;
    int windowX = 800;
    int windowY = 600;
    
    // set up ball shape
    Ball ballShape;
    ballShape.setX(500);
    ballShape.setY(100);
    ballShape.setSize(20);
    ballShape.getBall().setPosition(ballShape.getX(), ballShape.getY());
    ballShape.getBall().setRadius(ballShape.getSize());
    ballShape.getBall().setFillColor(sf::Color::White);
    
    // set up ball shape
    Cannon cannonShape;
    cannonShape.setX(500);
    cannonShape.setY(400);
    cannonShape.setWidth(100);
    cannonShape.setHeight(20);
    cannonShape.setAngle(0);
    cannonShape.getCannon().setOrigin(cannonShape.getWidth()/2,cannonShape.getHeight()/2);
    cannonShape.getCannon().setPosition(cannonShape.getX(), cannonShape.getY());
    cannonShape.getCannon().setSize( {cannonShape.getWidth(), cannonShape.getHeight()} );
    cannonShape.getCannon().setFillColor(sf::Color::White);

    
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
            cannonShape.setAngle(cannonShape.getAngle()+angle);
            cannonShape.getCannon().setRotation(cannonShape.getAngle());
            
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            
            cannonShape.setAngle(cannonShape.getAngle()-angle);
            cannonShape.getCannon().setRotation(cannonShape.getAngle());
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
           
            cannonShape.setX(cannonShape.getX()-speed);
            cannonShape.setY(cannonShape.getY());
            cannonShape.getCannon().setPosition(cannonShape.getX(), cannonShape.getY());
            
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            
            cannonShape.setX(cannonShape.getX()+speed);
            cannonShape.setY(cannonShape.getY());
            cannonShape.getCannon().setPosition(cannonShape.getX(), cannonShape.getY());
            

        }
        
        
        if(cannonShape.getX()<= 0)
            cannonShape.setX(0);
        if (cannonShape.getX()+cannonShape.getWidth()>= windowX)
             cannonShape.setX(windowX-cannonShape.getWidth());

            
        
        
        // erase window
        window.clear();
        
        // update/draw objects
       //window.draw(ballShape.getBall());
        window.draw(cannonShape.getCannon());
        
        // draw window
        window.display();
    }
    /*
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
     
*/
    
    return 0;
}

