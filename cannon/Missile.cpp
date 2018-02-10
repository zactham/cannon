//
//  Missile.cpp
//  cannon_mac
//
//  Created by Zac on 1/14/18.
//  Copyright © 2018 Zac. All rights reserved.
//

#include <stdio.h>
#include "Missile.h"
#include <SFML/Graphics.hpp>
#include "math.h"


//Constructor
Missile::Missile()
{
    
}
Missile::Missile(int ww, int wh)
{
    enabled = false;
    setWindowWidth(ww);
    setWindowHeight(wh);
    
    
}

void Missile::draw(sf::RenderWindow& window)
{
    if (enabled)
    {
        shape.setPosition(getPosition().getX(), getPosition().getY());
        shape.setOrigin(getWidth()/2, getHeight()/2);
        window.draw(shape);
    }
    
}

void Missile::update()
{
    if (enabled)
    {
        Vector2f newPos = position;
        newPos.add(velocity);
        
        //bottom
        if( newPos.getY() + getWidth() >= getWindowHeight())
            setEnabled(false);
        
        //sides
        if (newPos.getX() + getWidth() <= 0 || newPos.getX() + getWidth() >= getWindowWidth())
            velocity.setX(velocity.getX()*-1);
        
        shape.setRotation(angleRotate());
        
        setPosition(newPos);
        Vector2f gravity = Vector2f(0,0.03f);
        velocity.add(gravity);
        
    }
}

float Missile::angleRotate()
{
    float adjacentSide = velocity.getX();
    float hypotenuse = sqrtf(velocity.getX()*velocity.getX() + velocity.getY()*velocity.getY());
    float angleRadian = acosf(adjacentSide/hypotenuse);
    float angleDegrees = (float)(angleRadian * (180/M_PI));
    
    printf("angle =%f\n ", angleDegrees);
    
    if(velocity.getY() < 0)
        angleDegrees*=-1;
    
    
    return angleDegrees;
}

void Missile::setEnabled(bool en)
{
    enabled = en;
}

bool Missile::getEnabled()
{
    return enabled;
}

void Missile::setWindowWidth(int w)
{
    windowWidth = w;
}

int Missile::getWindowWidth()
{
    return windowWidth;
}

void Missile::setWindowHeight(int h)
{
    windowHeight = h;
}

int Missile::getWindowHeight()
{
    return windowHeight;
}

void Missile::setup()
{
    shape.setFillColor(sf::Color::Blue);
    
    setEnabled(false);
    setWindowWidth(windowWidth);
    setWindowHeight(windowHeight);
    setWidth(15);
    setHeight(4);
    
}




void Missile::setVelocity(Vector2f v)
{
    velocity = v;
    
}

Vector2f& Missile::getVelocity()
{
    return velocity;
    
}

void Missile::setPosition(Vector2f p)
{
    position = p;
    
}
Vector2f& Missile::getPosition()
{
    return position;
    
}




