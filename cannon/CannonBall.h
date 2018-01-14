//
//  CannonBall.h
//  cannon_mac
//
//  Created by Zac on 1/14/18.
//  Copyright © 2018 Zac. All rights reserved.
//

#ifndef CannonBall_h
#define CannonBall_h
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
