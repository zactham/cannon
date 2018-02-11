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
#include "Timer.h"
#include "UIManager.h"
#include "Sprite.h"


class Game
{
    
private:
    unsigned int windowWidth = 800;
    unsigned int windowHeight = 600;
    Cannon cannon;
    Cannon cannon2;
    Timer timer;
    Timer timer2;
    float spacebarTime = 0;
    float tabTime = 0;
    UIManager ui;
        
    sf::RenderWindow window{ { windowWidth, windowHeight}, "Cannon" };
    
    void update();
    void draw();
    bool spaceDown = false;
    bool tabDown = false;
    Sprite ufo;
    
    
public:
    Game();
    void setup();
    void run();
   
   
    
};

#endif /* Game_h */
