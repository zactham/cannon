//
//  Sprite.h
//  cannon_mac
//
//  Created by Zac on 2/11/18.
//  Copyright © 2018 Zac. All rights reserved.
//

#ifndef Sprite_h
#define Sprite_h
#include <SFML/Graphics.hpp>
#include "Bounds.h"
class Sprite
{
    private:
     sf::Sprite sprite;
     sf::Texture texture;
     Bounds bounds;
    
    
    
    public:
        Sprite();
        void setup(std::string filename);
        void draw(sf::RenderWindow& window);
        void position(float x, float y);
        void scale(float multiplier);
        void update();
    
};



#endif /* Sprite_h */
