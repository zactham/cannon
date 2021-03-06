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
    
    bounds.setup();
}

void Sprite::draw(sf::RenderWindow& window)
{
    bounds.drawBounds(window);
    window.draw(sprite);
}

void Sprite::position(float x, float y)
{
    sprite.setPosition(x, y);
}

void Sprite::scale(float multiplier)
{
    sprite.setScale(multiplier, multiplier);
}

void Sprite::update()
{
    bounds.update2(sprite.getPosition().x, sprite.getPosition().y,
                   (texture.getSize().x)*sprite.getScale().x, (texture.getSize().y)*sprite.getScale().y);
}
