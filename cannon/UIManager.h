//
//  UIManager.h
//  cannon_mac
//
//  Created by Zac on 2/5/18.
//  Copyright © 2018 Zac. All rights reserved.
//

#ifndef UIManager_h
#define UIManager_h
#include <SFML/Graphics.hpp>
class UIManager
{
    private:
    
    int shotAmount;
    float velocity;
    sf::Font myFont;   // this var holds the font
    sf::Text shotsText;   // this var holds the text string
    void textSetup();
    void textLoad();
    sf::RectangleShape shotMeter;//barrel
    void shotMeterSetup();

       
    
    public:
        UIManager();
        void setNumPlayerShots(int amount);
        void setShotVelocity(float v);
        void setup();
        void draw(sf::RenderWindow& window);
    
    
};


#endif /* UIManager_h */
