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
    window.setFramerateLimit(60);
    cannon.setup(windowWidth, windowHeight);
    myFont.loadFromFile("assets/calibri.ttf");  // load the font
    textSetup();
}

void Game::textSetup()
{
    shotsText.setFont(myFont);
    shotsText.setPosition(10, 50);   // the Y should be at least 50
    shotsText.setCharacterSize(35);
    shotsText.setFillColor(sf::Color::White);
    
}

void Game:: textLoad()
{
    char s[64];
    sprintf(s, "Shots:%d", 10);
    shotsText.setString(s);
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
    
}

void Game::draw()
{
    // erase window
    window.clear();
    
    // update/draw objects
    //window.draw(ballShape.getBall());
    cannon.draw(window);
    
    //draw text
    window.draw(shotsText);
    
    // draw window
    window.display();
}

void Game::run()
{
	bool spaceDown = false;
    textLoad();

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
				cannon.fire();
				spaceDown = false;
			}
				
			// SPACE key down (doesn't repeat)
			if (event.key.code == sf::Keyboard::Space && event.type == sf::Event::KeyPressed && !spaceDown)
			{
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
