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
    float rotationAmount;
    int windowWidth = 0;
    int windowHeight = 0;
    
    //Methods in Cannon.cpp
    void cannonSetup();
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
    void draw(sf::RenderWindow& window);
    void setup(int w, int h);
    
    
    
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
    
    
    sf::RectangleShape& getCannon()
    {
        return cannonShape;
    }
    
};

#endif /* Cannon_h */
