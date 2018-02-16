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
#include "Sound.h"
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
    outerWheelRadius = 15;
    innerWheelRadius = 8;
    rightFlipped = true;
    cannonAimedRight = false;
}

void Cannon::cannonSetup()
{
    wheelsOffset = 15;    // origin and wheels are 15 over in x and y, from the center of the barrel
    
    // set up cannon
    setX(500);
    setY(400);
    setWidth(100);
    setHeight(20);
    
    // set up cannon shape
    getCannon().setOrigin(getWidth()/2+ wheelsOffset, getHeight()/2+ wheelsOffset);        // affects position and rotation
    getCannon().setPosition(getX(), getY());
    getCannon().setSize( {getWidth(), getHeight()} );
    getCannon().setFillColor(sf::Color::White);
    
    //setup sound
    s.load("assets/fire.wav");
    
    
}

void Cannon::cannon2Setup()
{
    wheelsOffset = 15;    // origin and wheels are 15 over in x and y, from the center of the barrel
    
    // set up cannon
    setX(200);
    setY(400);
    setWidth(100);
    setHeight(20);
    
    // set up cannon shape
    getCannon().setOrigin(getWidth()/2+ wheelsOffset, getHeight()/2+ wheelsOffset);        // affects position and rotation
    getCannon().setPosition(getX(), getY());
    getCannon().setSize( {getWidth(), getHeight()} );
    getCannon().setFillColor(sf::Color::Blue);
    
    //setup sound
    s.load("assets/fire.wav");
    
    
}



void Cannon::outerWheelSetup()
{
    // set up ball shape
    outerWheel.setX(getX());    // set to the position of the cannon barrel (uses it's origin point)
    outerWheel.setY(getY());
    outerWheel.setSize(15);
    outerWheel.getCircle().setOrigin(outerWheel.getSize(), outerWheel.getSize());    // set origin to center of wheel
    outerWheel.getCircle().setPosition(outerWheel.getX(), outerWheel.getY());
    outerWheel.getCircle().setRadius(outerWheel.getSize());
    outerWheel.getCircle().setFillColor(sf::Color::Black);
    
}

void Cannon::innerWheelSetup()
{
    // set up ball shape
    innerWheel.setX(getX());    // set to the position of the cannon barrel (uses it's origin point)
    innerWheel.setY(getY());
    innerWheel.setSize(8);
    innerWheel.getCircle().setOrigin(innerWheel.getSize(), innerWheel.getSize());    // set origin to center of wheel
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
        innerWheel.setX(0 + getWidth()/2);
        
        getCannon().setPosition(getX(), getY());
        outerWheel.getCircle().setPosition(outerWheel.getX(), outerWheel.getY());
        innerWheel.getCircle().setPosition(innerWheel.getX(), innerWheel.getY());
        
        
    }
    if (getX()+ getWidth() / 2 >= windowWidth)
    {
        setX(windowWidth-getWidth()/2);
        outerWheel.setX(windowWidth-getWidth()/2);
        innerWheel.setX(windowWidth-getWidth()/2);
        
        getCannon().setPosition(getX(), getY());
        outerWheel.getCircle().setPosition(outerWheel.getX(), outerWheel.getY());
        innerWheel.getCircle().setPosition(innerWheel.getX(), innerWheel.getY());
        
        
    }
    
}
//public methods
void Cannon::aimUp()
{
    if(!cannonAimedRight && getAngle() + rotationAmount >= 0 && getAngle() +rotationAmount <= 75)
    {
        setAngle(getAngle()+rotationAmount);
    }
    
    if(cannonAimedRight && getAngle() - rotationAmount >= -75 && getAngle() - rotationAmount <= 0)
    {
        setAngle(getAngle()-rotationAmount);
    }
    
    getCannon().setRotation(getAngle());
        
}

void Cannon::aimDown()
{
    if(!cannonAimedRight && getAngle() - rotationAmount >= 0 && getAngle() - rotationAmount <= 75)
    {
        setAngle(getAngle()-rotationAmount);
    }
    
    if (cannonAimedRight && getAngle() + rotationAmount >= -75 && getAngle() + rotationAmount <= 0)
    {
        printf("Aim Down flipped");
        setAngle(getAngle()+rotationAmount);
    }
    
     getCannon().setRotation(getAngle());
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

void Cannon::draw(sf::RenderWindow& window, int cannonNum)
{
    window.draw(getCannon());
    window.draw(outerWheel.getCircle());
    window.draw(innerWheel.getCircle());
    if (cannonNum == 1)
    {
        unsigned int i;   // we use 'unsigned' here to avoid compiler warning below
        for (i = 0; i<cannonBallList.size(); i++)
            cannonBallList.at(i).draw(window);
    }
    else if (cannonNum == 2)
    {
        unsigned int i;   // we use 'unsigned' here to avoid compiler warning below
        for (i = 0; i<missileList.size(); i++)
            missileList.at(i).draw(window);
    }
    
}

void Cannon:: setup(int w, int h, int cannonNum)
{
    if(cannonNum == 1)
        cannonSetup();
    else if(cannonNum == 2)
        cannon2Setup();
    outerWheelSetup();
    innerWheelSetup();
    windowWidth = w;
    windowHeight = h;
}

void Cannon::update(int cannonNum)
{
    if(cannonNum == 1)
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
    else if (cannonNum == 2)
    {
        unsigned int i;   // we use 'unsigned' here to avoid compiler warning below
        for (i = 0; i<missileList.size(); i++)
        {
            missileList.at(i).update();
            if(missileList.at(i).getEnabled() == false)
            {
                missileList.erase(missileList.begin() + i);
            }
        }
    }
}

void Cannon::fire(float time, int cannonNum)
{
    if(cannonNum == 1)
    {
        time+=1;
        CannonBall cannonBall = *new CannonBall(windowWidth, windowHeight);
        cannonBall.setup();
        cannonBall.setEnabled(true);
    
        //setting the cannonball position to cannons position
        Vector2f pos = Vector2f(getX(), getY()-15);
        cannonBall.setPosition(pos);
    
        //set cannon velocity to cannon rotation angle
        Vector2f angleVec;
        angleVec.setFromAngle(getAngle());
        angleVec.multiply(-(3*time));//flip the angle to make it point left instead of right
    
        cannonBall.setVelocity(angleVec);
        cannonBallList.push_back(cannonBall);
    
        //plays the sound
        s.play();
    
        shotAmount-=1;
    
    }
    else if (cannonNum == 2)
    {
        time+=1;
        Missile missile = *new Missile(windowWidth, windowHeight);
        missile.setup();
        missile.setEnabled(true);
        
        //setting the position to cannons position
        Vector2f pos = Vector2f(getX(), getY()-15);
        missile.setPosition(pos);
        
        //set velocity to missile rotation angle
        Vector2f angleVec;
        angleVec.setFromAngle(getAngle());
        angleVec.multiply(-(3*time));//flip the angle to make it point left instead of right
        
        missile.setVelocity(angleVec);
        missileList.push_back(missile);
        
        //plays the sound
         s.play();
        
        shotAmount-=1;
    }
    
}

void Cannon::flip(int cannonNum)
{
        if(rightFlipped)
        {
            getCannon().setOrigin(getWidth()/2 - wheelsOffset, getHeight()/2+ wheelsOffset); // affects position and rotation
            cannonAimedRight = true;
            rightFlipped = false;
        }
        else
        {
            getCannon().setOrigin(getWidth()/2+ wheelsOffset, getHeight()/2+ wheelsOffset); // affects position and rotation
            cannonAimedRight = false;
            rightFlipped = true;
        }
    
}



