//
//  Game.cpp
//  cannon_mac
//
//  Created by Zac on 1/8/18.
//  Copyright © 2018 Zac. All rights reserved.
//

#include <stdio.h>
#include "Game.h"
#include "Timer.h"
//Constructor
Game::Game()
{
    
}

//Public methods
void Game::setup()
{
    window.setFramerateLimit(60);
    cannon.setup(windowWidth, windowHeight);
    ui.setup();
}


void Game::update()
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
	cannon.update();
    ui.setNumPlayerShots(cannon.getShotAmount());
    
}

void Game::draw()
{
    // erase window
    window.clear();
    
    // update/draw objects
    //window.draw(ballShape.getBall());
    cannon.draw(window);
    
    // draw window
    window.display();
    
    ui.draw(window);
}

void Game::run()
{
    
	bool spaceDown = false;

    //
    // main game loop
    //
    while (window.isOpen())
    {
        // check for exit
        sf::Event event;
        while (window.pollEvent(event))
        {
			// SPACE key up
			if (event.key.code == sf::Keyboard::Space && event.type == sf::Event::KeyReleased)
			{
                spacebarTime = timer.diff();
                printf("%f", spacebarTime);
				cannon.fire(spacebarTime);
				spaceDown = false;
                
			}
				
			// SPACE key down (doesn't repeat)
			if (event.key.code == sf::Keyboard::Space && event.type == sf::Event::KeyPressed && !spaceDown)
			{
                timer.reset();
				spaceDown = true;
			}

            // Close window or hit escape to exit
            if ( (event.type == sf::Event::Closed) ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) )
            {
                window.close();
            }
        }
        
        update();
        
        draw();
    }
    
}
