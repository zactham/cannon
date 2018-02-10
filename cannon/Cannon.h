//
//  Cannon.h
//  cannon_mac
//
//  Created by Zac on 1/8/18.
//  Copyright © 2018 Zac. All rights reserved.
//

#ifndef Cannon_h
#define Cannon_h
#include "Circle.h"
#include "CannonBall.h"
#include "Sound.h"
#include "Missile.h"
class Cannon
{
private:
    sf::RectangleShape cannonShape;//barrel
    std::vector<CannonBall> cannonBallList;
    std::vector<Missile> missileList;
    Circle outerWheel;
    Circle innerWheel;
    float cannonX;
    float cannonY;
    float width;
    float height;
    float angle;
    float speed = 0;
    float rotationAmount;
    int windowWidth = 0;
    int windowHeight = 0;
    int outerWheelRadius;
    int innerWheelRadius;
    int shotAmount = 10;
    Sound s;
    
    //Methods in Cannon.cpp
    void cannonSetup();
    void cannon2Setup();
    void outerWheelSetup();
    void innerWheelSetup();
    void boundaryCheck();
    
    
    
public:
    // constructor
    Cannon();
    
    
    void aimUp();
    void aimDown();
    void moveLeft();
    void moveRight();
    void draw(sf::RenderWindow& window, int cannonNum);
    void setup(int w, int h, int cannonNum);
    void update(int cannonNum);
    void fire(float time, int cannonNum);
    
    
    
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
    int getShotAmount()
    {
        return shotAmount;
    }
    
    
    sf::RectangleShape& getCannon()
    {
        return cannonShape;
    }
    
};

#endif /* Cannon_h */
