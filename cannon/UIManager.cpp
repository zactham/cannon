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

void UIManager::textSetup()
{
    shotsText.setFont(myFont);
    shotsText.setPosition(10, 50);   // the Y should be at least 50
    shotsText.setCharacterSize(35);
    shotsText.setFillColor(sf::Color::White);
    
}

void UIManager::textLoad()
{
    char s[64];
    snprintf(s, 64, "Shots:%d", shotAmount);
    shotsText.setString(s);
}

void UIManager::shotMeterSetup()
{
    // set up cannon shape
    shotMeter.setOrigin(200, 25);        // affects position and rotation
    shotMeter.setPosition(200, 25);
    shotMeter.setSize( {25, (velocity+1)*2} );
    shotMeter.setFillColor(sf::Color::White);
}

void UIManager::setNumPlayerShots(int amount)
{
    shotAmount = amount;
}

void UIManager::setShotVelocity(float v)
{
    velocity = v;
}
void UIManager::draw(sf::RenderWindow& window)
{
    //draw text
    window.draw(shotsText);
    //draw shotmeter
    window.draw(shotMeter);

}


