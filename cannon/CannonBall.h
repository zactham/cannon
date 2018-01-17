//
//  CannonBall.h
//  cannon_mac
//
//  Created by Zac on 1/14/18.
//  Copyright © 2018 Zac. All rights reserved.
//

#ifndef CannonBall_h
#define CannonBall_h
#include "Vector2f.h"
#include <SFML/Graphics.hpp>
class CannonBall
{
private:
    sf::CircleShape shape;
    Vector2f position;
    Vector2f velocity;
    float radius;
    bool enabled;
    int windowWidth;
    int windowHeight;
    
public:
    CannonBall();
    void draw(sf::RenderWindow& window);
    void update();
    void setRadius(float r);
    float getRadius();
    void setEnabled(bool en);
    bool getEnabled();
    void setWindowWidth(int w);
    int getWindowWidth();
    void setWindowHeight(int h);
    int getWindowHeight();
    void setup();
    
};

#endif /* CannonBall_h */
