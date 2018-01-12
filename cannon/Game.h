//
//  Game.h
//  cannon_mac
//
//  Created by Zac on 1/8/18.
//  Copyright © 2018 Zac. All rights reserved.
//

#ifndef Game_h
#define Game_h

#include "Cannon.h"

class Game
{
private:
    unsigned int windowWidth = 800;
    unsigned int windowHeight = 600;
    Cannon cannon;
    
    sf::RenderWindow window{ { windowWidth, windowHeight}, "Cannon" };
    
    Game();
    void update();
    void draw();
    
public:
    void setup();
    void run();
    
};

#endif /* Game_h */
