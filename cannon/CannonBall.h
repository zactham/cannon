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
    
public:
    void draw(sf::RenderWindow& window);
    void update();
};

#endif /* CannonBall_h */
