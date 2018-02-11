//
//  Sprite.cpp
//  cannon_mac
//
//  Created by Zac on 2/11/18.
//  Copyright © 2018 Zac. All rights reserved.
//

#include <stdio.h>
#include "Sprite.h"

Sprite::Sprite()
{
    
}

void Sprite::setup(std::string filename)
{
    // Declare and load a texture
    texture.loadFromFile(filename);
    
    // set up the sprite.
    sprite.setTexture(texture);
    sprite.setColor(sf::Color(255, 255, 255, 200));
    
    // set the scale and position
    sprite.setPosition(100, 100);
    sprite.setScale(.2f, .2f);

}

void Sprite::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}
