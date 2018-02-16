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
    cannon.setup(windowWidth, windowHeight, 1);
    cannon2.setup(windowWidth, windowHeight, 2);
    ui.setup();
    ui.setup2();
    ufo.setup("assets/ufo.png");
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


    //Cannon 2
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        cannon2.aimUp();
        
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        cannon2.aimDown();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        
        cannon2.moveLeft();
        
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        cannon2.moveRight();
        
    }
	cannon.update(1);
    cannon2.update(2);
    
    ui.setNumPlayerShots(cannon.getShotAmount());
    ui.setNumPlayerShots2(cannon2.getShotAmount());
    
    if(spaceDown)
        spacebarTime = timer.diff();
    else
        spacebarTime = 0;
    
    if(tabDown)
        tabTime = timer2.diff();
    else
        tabTime = 0;
    

    ui.setShotVelocity(spacebarTime);
    ui.update();
    ui.setShotVelocity2(tabTime);
   
    
}

void Game::draw()
{
    // erase window
    window.clear();
    
    // update/draw objects
    //window.draw(ballShape.getBall());
    cannon.draw(window, 1);
    cannon2.draw(window, 2);
    ui.draw(window);
    
    //draws ufo sprite
    ufo.draw(window);
    
    // draw window
    window.display();
    
  
    
   
}

void Game::run()
{
    //
    // main game loop
    //
    while (window.isOpen())
    {
        // check for exit
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            
            if(event.key.code == sf::Keyboard::LShift && event.type == sf::Event::KeyReleased)
            {
                cannon2.flip(2);
                
            }
            
            if(event.key.code == sf::Keyboard::RShift && event.type == sf::Event::KeyReleased)
            {

                cannon.flip(1);
                
            }
            
			// SPACE key up
			if (event.key.code == sf::Keyboard::Space && event.type == sf::Event::KeyReleased)
			{
                printf("%f", spacebarTime);
				cannon.fire(spacebarTime, 1);
				spaceDown = false;
                
			}
				
			// SPACE key down (doesn't repeat)
			if (event.key.code == sf::Keyboard::Space && event.type == sf::Event::KeyPressed && !spaceDown)
			{
                timer.reset();
				spaceDown = true;
			}
            
            // TAB key up
            if (event.key.code == sf::Keyboard::Tab && event.type == sf::Event::KeyReleased)
            {
                printf("%f", tabTime);
                cannon2.fire(tabTime, 2);
                tabDown = false;
            }
            
            // SPACE key down (doesn't repeat)
            if (event.key.code == sf::Keyboard::Tab && event.type == sf::Event::KeyPressed && !tabDown)
            {
                timer2.reset();
                tabDown = true;
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
