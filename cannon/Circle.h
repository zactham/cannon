//
//  Circle.h
//  cannon_mac
//
//  Created by Zac on 1/8/18.
//  Copyright © 2018 Zac. All rights reserved.
//

#ifndef Circle_h
#define Circle_h
#include <SFML/Graphics.hpp>
class Circle
{
private:
    sf::CircleShape circleShape;
    float circleX;
    float circleY;
    float radius;
    
    
public:
    /// constructor
    Circle();
    
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

#endif /* Circle_h */
