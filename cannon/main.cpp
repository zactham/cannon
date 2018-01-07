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
    float radius;

    
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
    void setSize(float r)
    {
        radius = r;
    }
    float getSize()
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
    sf::RectangleShape cannonShape;//barrel
    Circle outerWheel;
    Circle innerWheel;
    float cannonX;
    float cannonY;
    float width;
    float height;
    float angle;
    float speed = 0;
    int windowWidth = 0;
    int windowHeight = 0;
    
    void cannonSetup()
    {
        // set up cannon
        setX(500);
        setY(400);
        setWidth(100);
        setHeight(20);
        setAngle(0);
        getCannon().setOrigin(getWidth()/2,getHeight()/2);
        getCannon().setPosition(getX(), getY());
        getCannon().setSize( {getWidth(), getHeight()} );
        getCannon().setFillColor(sf::Color::White);
        
    }
    
    void outerWheelSetup()
    {
        // set up ball shape
        outerWheel.setX(getX());
        outerWheel.setY(getY()-5);
        outerWheel.setSize(15);
        outerWheel.getCircle().setPosition(outerWheel.getX(), outerWheel.getY());
        outerWheel.getCircle().setRadius(outerWheel.getSize());
        outerWheel.getCircle().setFillColor(sf::Color::Black);
        
    }
    
    void innerWheelSetup()
    {
        // set up ball shape
        innerWheel.setX(getX()+7);
        innerWheel.setY(getY()+3);
        innerWheel.setSize(8);
        innerWheel.getCircle().setPosition(innerWheel.getX(), innerWheel.getY());
        innerWheel.getCircle().setRadius(innerWheel.getSize());
        innerWheel.getCircle().setFillColor(sf::Color::White);
    }
    
    void boundaryCheck()
    {
        if(getX()-getWidth()/2<= 0)
        {
            setX(0 + getWidth()/2);
            outerWheel.setX(0 + getWidth()/2);
            innerWheel.setX(0 + getWidth()/2+7);
            
            getCannon().setPosition(getX(), getY());
            outerWheel.getCircle().setPosition(outerWheel.getX(), outerWheel.getY());
            innerWheel.getCircle().setPosition(innerWheel.getX(), innerWheel.getY());
            
            
        }
        if (getX()+ getWidth() / 2 >= windowWidth)
        {
            setX(windowWidth-getWidth()/2);
            outerWheel.setX(windowWidth-getWidth()/2);
            innerWheel.setX(windowWidth-getWidth()/2+7);
            
            getCannon().setPosition(getX(), getY());
            outerWheel.getCircle().setPosition(outerWheel.getX(), outerWheel.getY());
            innerWheel.getCircle().setPosition(innerWheel.getX(), innerWheel.getY());
            
            
        }
        
    }

    
    
    
public:
    // constructor
    Cannon()
    {
        cannonX = 0;
        cannonY = 0;
        width = 0;
        height = 0;
        speed = 10;
        angle = 15;
    }
    
    
    void aimUp()
    {
        setAngle(getAngle()+angle);
        getCannon().setRotation(getAngle());
    }
    
    void aimDown()
    {
        setAngle(getAngle()-angle);
        getCannon().setRotation(getAngle());
    }
    void moveLeft()
    {
        setX(getX()-speed);
        setY(getY());
        getCannon().setPosition(getX(), getY());
        
        outerWheel.setX(outerWheel.getX()-speed);
        outerWheel.setY(outerWheel.getY());
        outerWheel.getCircle().setPosition(outerWheel.getX(), outerWheel.getY());
        
        innerWheel.setX(innerWheel.getX()-speed);
        innerWheel.setY(innerWheel.getY());
        innerWheel.getCircle().setPosition(innerWheel.getX(), innerWheel.getY());
      
        boundaryCheck();
 
    }
    
    void moveRight()
    {
        
        setX(getX()+speed);
        setY(getY());
        getCannon().setPosition(getX(), getY());
        
        outerWheel.setX(outerWheel.getX()+speed);
        outerWheel.setY(outerWheel.getY());
        outerWheel.getCircle().setPosition(outerWheel.getX(), outerWheel.getY());
        
        innerWheel.setX(innerWheel.getX()+speed);
        innerWheel.setY(innerWheel.getY());
        innerWheel.getCircle().setPosition(innerWheel.getX(), innerWheel.getY());
        
        boundaryCheck();

    }
    
    void draw(sf::RenderWindow& window)
    {
        window.draw(getCannon());
        window.draw(outerWheel.getCircle());
        window.draw(innerWheel.getCircle());

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
    void setAngle(float a)
    {
        angle = a;
    }
    float getAngle()
    {
        return angle;
    }
    
    void setup(int w, int h)
    {
        cannonSetup();
        outerWheelSetup();
        innerWheelSetup();
        
        windowWidth = w;
        windowHeight = h;
    }
    

    
    
    sf::RectangleShape& getCannon()
    {
        return cannonShape;
    }
    
};

class Game
{
public:
   unsigned int windowWidth = 800;
   unsigned int windowHeight = 600;
    Cannon cannon;
   
    sf::RenderWindow window{ { windowWidth, windowHeight}, "Cannon" };
    
    Game()
    {
        
    }
    
    void setup()
    {
        cannon.setup(windowWidth, windowHeight);
    }
    
    
    void keyboardCommands()
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            cannon.aimUp();
            
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            cannon.aimDown();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            
            cannon.moveLeft();
            
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            cannon.moveRight();
            
        }
        
    }
    
    
 
    
    void windowOperations()
    {
        // erase window
        window.clear();
        
        // update/draw objects
        //window.draw(ballShape.getBall());
        cannon.draw(window);
        
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

