//
//  CannonBall.cpp
//  cannon_mac
//
//  Created by Zac on 1/14/18.
//  Copyright © 2018 Zac. All rights reserved.
//

#include <stdio.h>
#include "Cannonball.h"
#include <SFML/Graphics.hpp>


//Constructor
CannonBall::CannonBall()
{
    enabled = true;
    
}

void CannonBall::draw(sf::RenderWindow& window)
{
   if (enabled)
       window.draw(shape);
}

void CannonBall::update()
{
    if (enabled)
    {
        Vector2f newPos = position;
        newPos.add(velocity);
        if(newPos.getX()<= getWindowWidth() && newPos.getY() <= getWindowHeight())
            position = newPos;
        else
            enabled = false;
    }
}

void CannonBall::setRadius(float r)
{
    radius  = r;
}

float CannonBall::getRadius()
{
    return radius;
}

void CannonBall::setEnabled(bool en)
{
    enabled = en;
}

bool CannonBall::getEnabled()
{
    return enabled;
}

void CannonBall::setWindowWidth(int w)
{
    windowWidth = w;
}

int CannonBall::getWindowWidth()
{
    return windowWidth;
}

void CannonBall::setWindowHeight(int h)
{
    windowHeight = h;
}

int CannonBall::getWindowHeight()
{
    return windowHeight;
}

void CannonBall::setup()
{
    setWindowWidth(windowWidth);
    setWindowWidth(windowHeight);
    shape.setFillColor(sf::Color::White);
    setRadius(5);
    
}


