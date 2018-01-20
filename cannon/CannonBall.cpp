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
		if (newPos.getX() + getRadius() <= 0 || newPos.getX() + getRadius() >= getWindowWidth() || newPos.getY() + getRadius() <= 0 || newPos.getY() + getRadius() >= getWindowHeight())
			enabled = false;
		setPosition(newPos);
        Vector2f gravity = Vector2f(1,1);
        gravity.add(velocity);
		
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

void CannonBall::setup()
{
	setEnabled(false);
    setWindowWidth(windowWidth);
    setWindowHeight(windowHeight);
    shape.setFillColor(sf::Color::White);
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




