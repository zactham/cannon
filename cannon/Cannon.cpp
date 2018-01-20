//
//  Cannon.cpp
//  cannon_mac
//
//  Created by Zac on 1/8/18.
//  Copyright © 2018 Zac. All rights reserved.
//

#include "Cannon.h"
#include <SFML/Graphics.hpp>
#include "Vector2f.h"
// constructor
Cannon::Cannon()
{
    cannonX = 0;
    cannonY = 0;
    width = 0;
    height = 0;
    speed = 10;
    rotationAmount = 5;
    angle = 0;
}

// private methods
void Cannon::cannonSetup()
{
    // set up cannon
    setX(500);
    setY(400);
    setWidth(100);
    setHeight(20);
    getCannon().setOrigin(getWidth()/2,getHeight()/2);
    getCannon().setPosition(getX(), getY());
    getCannon().setSize( {getWidth(), getHeight()} );
    getCannon().setFillColor(sf::Color::White);
    unsigned int i;   // we use 'unsigned' here to avoid compiler warning below
    for (i = 0; i<cannonBallList.size(); i++)
    cannonBallList.at(i).setup();
    
}

void Cannon::outerWheelSetup()
{
    // set up ball shape
    outerWheel.setX(getX());
    outerWheel.setY(getY()-5);
    outerWheel.setSize(15);
    outerWheel.getCircle().setPosition(outerWheel.getX(), outerWheel.getY());
    outerWheel.getCircle().setRadius(outerWheel.getSize());
    outerWheel.getCircle().setFillColor(sf::Color::Black);
    
}

void Cannon::innerWheelSetup()
{
    // set up ball shape
    innerWheel.setX(getX()+7);
    innerWheel.setY(getY()+3);
    innerWheel.setSize(8);
    innerWheel.getCircle().setPosition(innerWheel.getX(), innerWheel.getY());
    innerWheel.getCircle().setRadius(innerWheel.getSize());
    innerWheel.getCircle().setFillColor(sf::Color::White);
}

void Cannon::boundaryCheck()
{
    if(getX()-getWidth()/2<= 0)
    {
        setX(0 + getWidth()/2);
        outerWheel.setX(0 + getWidth()/2);
        innerWheel.setX(0 + getWidth()/2+7);
        
        getCannon().setPosition(getX(), getY());
        outerWheel.getCircle().setPosition(outerWheel.getX(), outerWheel.getY());
        innerWheel.getCircle().setPosition(innerWheel.getX(), innerWheel.getY());
        
        
    }
    if (getX()+ getWidth() / 2 >= windowWidth)
    {
        setX(windowWidth-getWidth()/2);
        outerWheel.setX(windowWidth-getWidth()/2);
        innerWheel.setX(windowWidth-getWidth()/2+7);
        
        getCannon().setPosition(getX(), getY());
        outerWheel.getCircle().setPosition(outerWheel.getX(), outerWheel.getY());
        innerWheel.getCircle().setPosition(innerWheel.getX(), innerWheel.getY());
        
        
    }
    
}
//public methods
void Cannon::aimUp()
{
    if(getAngle() + rotationAmount >= 0 && getAngle() +rotationAmount <= 75)
    {
        setAngle(getAngle()+rotationAmount);
        getCannon().setRotation(getAngle());
    }
}

void Cannon::aimDown()
{
    if(getAngle() - rotationAmount >= 0 && getAngle() - rotationAmount <= 75)
    {
        setAngle(getAngle()-rotationAmount);
        getCannon().setRotation(getAngle());
    }
}
void Cannon::moveLeft()
{
    setX(getX()-speed);
    setY(getY());
    getCannon().setPosition(getX(), getY());
    
    outerWheel.setX(outerWheel.getX()-speed);
    outerWheel.setY(outerWheel.getY());
    outerWheel.getCircle().setPosition(outerWheel.getX(), outerWheel.getY());
    
    innerWheel.setX(innerWheel.getX()-speed);
    innerWheel.setY(innerWheel.getY());
    innerWheel.getCircle().setPosition(innerWheel.getX(), innerWheel.getY());
    
    boundaryCheck();
    
}

void Cannon::moveRight()
{
    
    setX(getX()+speed);
    setY(getY());
    getCannon().setPosition(getX(), getY());
    
    outerWheel.setX(outerWheel.getX()+speed);
    outerWheel.setY(outerWheel.getY());
    outerWheel.getCircle().setPosition(outerWheel.getX(), outerWheel.getY());
    
    innerWheel.setX(innerWheel.getX()+speed);
    innerWheel.setY(innerWheel.getY());
    innerWheel.getCircle().setPosition(innerWheel.getX(), innerWheel.getY());
    
    boundaryCheck();
    
}

void Cannon::draw(sf::RenderWindow& window)
{
    window.draw(getCannon());
    window.draw(outerWheel.getCircle());
    window.draw(innerWheel.getCircle());
    unsigned int i;   // we use 'unsigned' here to avoid compiler warning below
    for (i = 0; i<cannonBallList.size(); i++)
        cannonBallList.at(i).draw(window);
    
}

void Cannon:: setup(int w, int h)
{
    cannonSetup();
    outerWheelSetup();
    innerWheelSetup();
    
    windowWidth = w;
    windowHeight = h;
}

void Cannon::update()
{
    unsigned int i;   // we use 'unsigned' here to avoid compiler warning below
    for (i = 0; i<cannonBallList.size(); i++)
    {
        cannonBallList.at(i).update();
        if(cannonBallList.at(i).getEnabled() == false)
        {
            cannonBallList.erase(cannonBallList.begin() + i);
        }
    }
    
    
}

void Cannon::fire()
{
   
    CannonBall cannonBall = *new CannonBall(windowWidth, windowHeight);
    cannonBall.setup();
    cannonBall.setEnabled(true);
    
	//setting the cannonball position to cannons position
	Vector2f pos = Vector2f(getX(), getY());
	cannonBall.setPosition(pos);
    
	//set cannon velocity to cannon rotation angle
	Vector2f angle;
	angle.setFromAngle(getAngle());
	angle.multiply(-4);//flip the angle to make it point left instead of right
    
    cannonBall.setVelocity(angle);
    cannonBallList.push_back(cannonBall);
    
    
    
    
}



