//
//  Game.cpp
//  cannon_mac
//
//  Created by Zac on 1/8/18.
//  Copyright © 2018 Zac. All rights reserved.
//

#include <stdio.h>
#include "Game.h"
//Constructor
Game::Game()
{
    
}

//Public methods
void Game::setup()
{
    cannon.setup(windowWidth, windowHeight);
}

void Game::keyboardCommands()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        cannon.aimUp();
        
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        cannon.aimDown();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        
        cannon.moveLeft();
        
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        cannon.moveRight();
        
    }
    
}

void Game::windowOperations()
{
    // erase window
    window.clear();
    
    // update/draw objects
    //window.draw(ballShape.getBall());
    cannon.draw(window);
    
    // draw window
    window.display();
}
