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


class Game
{
    
private:
    unsigned int windowWidth = 800;
    unsigned int windowHeight = 600;
    Cannon cannon;
    Timer timer;
    float spacebarTime;
    UIManager ui;
        
    sf::RenderWindow window{ { windowWidth, windowHeight}, "Cannon" };
    
    void update();
    void draw();
    
    
public:
    Game();
    void setup();
    void run();
    void textSetup();
    void textLoad();
   
    
};

#endif /* Game_h */
