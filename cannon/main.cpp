//
// Main loop for our cannon game
//

// we use the graphics API from SFML library
#include <SFML/Graphics.hpp>


//
// our own ball class
//
class Circle
{
private:
    sf::CircleShape circleShape;
    float circleX;
    float circleY;
    int radius;
    
public:
/// constructor
    Circle()
    {
        circleX = 0;
        circleY = 0;
        radius = 0;
    }
    
    void setX(float i)
    {
        circleX = i;
    }
    void setY(float i)
    {
        circleY = i;
    }
    float getX()
    {
        return circleX;
    }
    float getY()
    {
        return circleY;
    }
    void setSize(int r)
    {
        radius = r;
    }
    int getSize()
    {
        return radius;
    }
    
    sf::CircleShape& getCircle()
    {
        return circleShape;
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

class Game
{
public:
    int speed = 0;
    int angle = 0;
    int windowX = 0;
    int windowY = 0;
    Cannon cannonShape;
    Circle outerWheel;
    Circle innerWheel;
    sf::RenderWindow window{ { 800, 600}, "Cannon" };
    
    Game()
    {
         speed = 10;
         angle = 15;
         windowX = 800;
         windowY = 600;
    }
    
   void cannonSetup()
    {
        // set up cannon
        cannonShape.setX(500);
        cannonShape.setY(400);
        cannonShape.setWidth(100);
        cannonShape.setHeight(20);
        cannonShape.setAngle(0);
        cannonShape.getCannon().setOrigin(cannonShape.getWidth()/2,cannonShape.getHeight()/2);
        cannonShape.getCannon().setPosition(cannonShape.getX(), cannonShape.getY());
        cannonShape.getCannon().setSize( {cannonShape.getWidth(), cannonShape.getHeight()} );
        cannonShape.getCannon().setFillColor(sf::Color::White);
    }
    
    void outerWheelSetup()
    {
        // set up ball shape
        outerWheel.setX(cannonShape.getX());
        outerWheel.setY(cannonShape.getY()-5);
        outerWheel.setSize(15);
        outerWheel.getCircle().setPosition(outerWheel.getX(), outerWheel.getY());
        outerWheel.getCircle().setRadius(outerWheel.getSize());
        outerWheel.getCircle().setFillColor(sf::Color::Black);

    }
    
    void innerWheelSetup()
    {
        // set up ball shape
        innerWheel.setX(cannonShape.getX()+7);
        innerWheel.setY(cannonShape.getY()+3);
        innerWheel.setSize(8);
        innerWheel.getCircle().setPosition(innerWheel.getX(), innerWheel.getY());
        innerWheel.getCircle().setRadius(innerWheel.getSize());
        innerWheel.getCircle().setFillColor(sf::Color::White);
    }
 
    
    
    void keyboardCommands()
    {
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
            
            outerWheel.setX(outerWheel.getX()-speed);
            outerWheel.setY(outerWheel.getY());
            outerWheel.getCircle().setPosition(outerWheel.getX(), outerWheel.getY());
            
            innerWheel.setX(innerWheel.getX()-speed);
            innerWheel.setY(innerWheel.getY());
            innerWheel.getCircle().setPosition(innerWheel.getX(), innerWheel.getY());

            
            
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            
            cannonShape.setX(cannonShape.getX()+speed);
            cannonShape.setY(cannonShape.getY());
            cannonShape.getCannon().setPosition(cannonShape.getX(), cannonShape.getY());
            
            outerWheel.setX(outerWheel.getX()+speed);
            outerWheel.setY(outerWheel.getY());
            outerWheel.getCircle().setPosition(outerWheel.getX(), outerWheel.getY());
            
            innerWheel.setX(innerWheel.getX()+speed);
            innerWheel.setY(innerWheel.getY());
            innerWheel.getCircle().setPosition(innerWheel.getX(), innerWheel.getY());
            
            
            
        }
        
    }
    
    void cannonXCheck()
    {
        if(cannonShape.getX()-cannonShape.getWidth()/2<= 0)
        {
            cannonShape.setX(0 + cannonShape.getWidth()/2);
            outerWheel.setX(0 + cannonShape.getWidth()/2);
            innerWheel.setX(0 + cannonShape.getWidth()/2);
            
            cannonShape.getCannon().setPosition(cannonShape.getX(), cannonShape.getY());
            outerWheel.getCircle().setPosition(outerWheel.getX(), outerWheel.getY());
            innerWheel.getCircle().setPosition(innerWheel.getX(), innerWheel.getY());

            
        }
        if (cannonShape.getX()>= windowX)
        {
            cannonShape.setX(windowX-cannonShape.getWidth()/2);
            outerWheel.setX(windowX-cannonShape.getWidth()/2);
            innerWheel.setX(windowX-cannonShape.getWidth()/2);
            
            cannonShape.getCannon().setPosition(cannonShape.getX(), cannonShape.getY());
            outerWheel.getCircle().setPosition(outerWheel.getX(), outerWheel.getY());
            innerWheel.getCircle().setPosition(innerWheel.getX(), innerWheel.getY());
        
            
        }

    }
    
    void windowOperations()
    {
        // erase window
        window.clear();
        
        // update/draw objects
        //window.draw(ballShape.getBall());
        window.draw(cannonShape.getCannon());
        window.draw(outerWheel.getCircle());
        window.draw(innerWheel.getCircle());
        
        // draw window
        window.display();
    }
    
};
    
//
// main function
//

int main()
{
    Game game;
    
    game.cannonSetup();
    game.outerWheelSetup();
    game.innerWheelSetup();

    
   
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
        
        game.cannonXCheck();
        
        game.windowOperations();
    }
    
    /*
     // set up ball shape
     Ball ballShape;
     ballShape.setX(500);
     ballShape.setY(100);
     ballShape.setSize(20);
     ballShape.getBall().setPosition(ballShape.getX(), ballShape.getY());
     ballShape.getBall().setRadius(ballShape.getSize());
     ballShape.getBall().setFillColor(sf::Color::White);
     */
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

