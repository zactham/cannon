//
//  Bounds.h
//  cannon_mac
//
//  Created by Zac on 2/19/18.
//  Copyright © 2018 Zac. All rights reserved.
//

#ifndef Bounds_h
#define Bounds_h
#include <SFML/Graphics.hpp>
class Bounds
{
private:
    sf::FloatRect bounds;
    sf::RectangleShape boundsRectShape;
    float outlineThickness = 0;
   
    
public:
    Bounds();
    sf::FloatRect& getBounds();
    void drawBounds(sf::RenderWindow& window);
    void setup();
    void update(float x, float y, float size);
    
    
    
};


#endif /* Bounds_h */
