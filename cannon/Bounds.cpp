//
//  Bounds.cpp
//  cannon_mac
//
//  Created by Zac on 2/19/18.
//  Copyright © 2018 Zac. All rights reserved.
//

#include <stdio.h>
#include "Bounds.h"
#include <SFML/Graphics.hpp>
Bounds::Bounds()
{
    outlineThickness = 5;
}

void Bounds::setup()
{
    boundsRectShape.setOutlineColor(sf::Color::Red);
    boundsRectShape.setOutlineThickness(outlineThickness);
}
void Bounds::setDimensions(float width, float height)
{
    boundsRectShape.setSize(sf::Vector2f(width, height)); // get from bounds Rect
}
void Bounds::setPositionValues(float x, float y)
{
     boundsRectShape.setPosition(x, y); // get from bounds Rect
}

sf::FloatRect& Bounds::getBounds()
{
    return bounds;
}
void Bounds::drawBounds(sf::RenderWindow& window)
{
    window.draw(boundsRectShape);
}

void Bounds::update(float x, float y, float size)
{
    bounds.left = x;
    bounds.top = y;
    bounds.width = size;
    bounds.height = size;
}
