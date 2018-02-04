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


class Game
{
private:
    unsigned int windowWidth = 800;
    unsigned int windowHeight = 600;
    Cannon cannon;
    sf::Font myFont;   // this var holds the font
    sf::Text shotsText;   // this var holds the text string
    Timer timer;
    float spacebarTime;

    
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
