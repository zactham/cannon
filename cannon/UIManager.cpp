//
//  UIManager.cpp
//  cannon_mac
//
//  Created by Zac on 2/5/18.
//  Copyright © 2018 Zac. All rights reserved.
//

#include "UIManager.h"
#include <SFML/Graphics.hpp>

UIManager::UIManager()
{
    
}

void UIManager::setup()
{
    myFont.loadFromFile("assets/calibri.ttf");  // load the font
    textSetup();
    textLoad();
    shotMeterSetup();
    

}
void UIManager::setup2()
{
    myFont.loadFromFile("assets/calibri.ttf");  // load the font
    textSetup2();
    textLoad2();
    shotMeterSetup2();
    
    
}

void UIManager::textSetup()
{
    shotsText.setFont(myFont);
    shotsText.setPosition(500, 50);   // the Y should be at least 50
    shotsText.setCharacterSize(35);
    shotsText.setFillColor(sf::Color::White);
    
}

void UIManager::textSetup2()
{
    shotsText2.setFont(myFont);
    shotsText2.setPosition(200, 50);   // the Y should be at least 50
    shotsText2.setCharacterSize(35);
    shotsText2.setFillColor(sf::Color::Blue);
    
}

void UIManager::textLoad()
{
    char s[64];
    snprintf(s, 64, "Shots:%d", shotAmount);
    shotsText.setString(s);
}
void UIManager::textLoad2()
{
    char s[64];
    snprintf(s, 64, "Shots:%d", shotAmount2);
    shotsText2.setString(s);
}

void UIManager::shotMeterSetup()
{
    // set up cannon shape
    shotMeter.setPosition(500, 30);
    shotMeter.setSize( {velocity*50, 30}  );
    shotMeter.setFillColor(sf::Color::Red);
}

void UIManager::shotMeterSetup2()
{
    // set up cannon shape
    shotMeter2.setPosition(200, 30);
    shotMeter2.setSize( {velocity2*50, 30}  );
    shotMeter2.setFillColor(sf::Color::Blue);
}

void UIManager::setNumPlayerShots(int amount)
{
    if(amount<0)
        amount = 0;
    shotAmount = amount;
}

void UIManager::setNumPlayerShots2(int amount)
{
    if(amount<0)
        amount = 0;
    shotAmount2 = amount;
}


void UIManager::setShotVelocity(float v)
{
   // v+=2;
    velocity = v;
}

void UIManager::setShotVelocity2(float v)
{
    // v+=2;
    velocity2 = v;
}
void UIManager::draw(sf::RenderWindow& window)
{
    //draw text
    window.draw(shotsText);
    //draw shotmeter
    window.draw(shotMeter);
    
    //draw text
    window.draw(shotsText2);
    //draw shotmeter
    window.draw(shotMeter2);

}

void UIManager::update()
{
    textLoad();
    textLoad2();
    shotMeterSetup();
    shotMeterSetup2();
}

