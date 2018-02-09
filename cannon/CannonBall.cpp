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

}
CannonBall::CannonBall(int ww, int wh)
{
	enabled = false;
    setWindowWidth(ww);
    setWindowHeight(wh);
    
}

void CannonBall::draw(sf::RenderWindow& window)
{
	
	if (enabled)
	{
		shape.setPosition(getPosition().getX(), getPosition().getY());
		window.draw(shape);
    }
     
}

void CannonBall::update()
{
    if (enabled)
    {
        Vector2f newPos = position;
        newPos.add(velocity);
		if (newPos.getX() + getRadius() <= 0 || newPos.getX() + getRadius() >= getWindowWidth() || newPos.getY() + getRadius() >= getWindowHeight())
            setEnabled(false);
        
        if (newPos.getY() + getRadius() < (-5) )
           velocity.multiply(-1);
        
			
		setPosition(newPos);
        Vector2f gravity = Vector2f(0,0.03f);
        velocity.add(gravity);
		
    }
    

}

void CannonBall::setRadius(float r)
{
    radius  = r;
    shape.setRadius(radius);
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

void CannonBall::setup(int cannonNum)
{
	if(cannonNum == 1)
         shape.setFillColor(sf::Color::White);
    else if(cannonNum == 2)
        shape.setFillColor(sf::Color::Blue);
        
    setEnabled(false);
    setWindowWidth(windowWidth);
    setWindowHeight(windowHeight);
    setRadius(5);
    
}




void CannonBall::setVelocity(Vector2f v)
{
	velocity = v;

}

Vector2f& CannonBall::getVelocity()
{
	return velocity;

}

void CannonBall::setPosition(Vector2f p)
{
	position = p;

}
Vector2f& CannonBall::getPosition()
{
	return position;

}




