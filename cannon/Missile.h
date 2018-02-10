//
//  Missile.h
//  cannon_mac
//
//  Created by Zac on 1/14/18.
//  Copyright © 2018 Zac. All rights reserved.
//

#ifndef Missile_h
#define Missile_h
#include "Vector2f.h"
#include <SFML/Graphics.hpp>
class Missile
{
private:
    sf::RectangleShape shape;
    Vector2f position;
    Vector2f velocity;
    bool enabled;
    int windowWidth;
    int windowHeight;
    
    
public:
    Missile(int w, int h);
    Missile();
    void draw(sf::RenderWindow& window);
    void update();
    void setEnabled(bool en);
    bool getEnabled();
    void setWindowWidth(int w);
    int getWindowWidth();
    void setWindowHeight(int h);
    int getWindowHeight();
    void setup();
    void setVelocity(Vector2f v);
    Vector2f& getVelocity();
    void setPosition(Vector2f p);
    Vector2f&getPosition();
    
    float angleRotate();
    
    void setWidth(float w)
    {
        shape.setSize( {w, shape.getSize().y} );
    }
    float getWidth()
    {
        return shape.getSize().x;
    }
    
    void setHeight(float h)
    {
        shape.setSize( {shape.getSize().x, h} );
    }
    float getHeight()
    {
        return shape.getSize().y;
    }
    
    
    
    
};

#endif /* Missile_h */
