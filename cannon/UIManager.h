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
    int shotAmount = 10;
    int shotAmount2 = 10;
    float velocity;
    float velocity2;
    sf::Font myFont;   // this var holds the font
    sf::Text shotsText;   // this var holds the text string
    sf::Text shotsText2;   // this var holds the text string
    void textSetup();
    void textSetup2();
    void textLoad();
    void textLoad2();
    sf::RectangleShape shotMeter;
    sf::RectangleShape shotMeter2;
    void shotMeterSetup();
    void shotMeterSetup2();

       
    
    public:
        UIManager();
        void setNumPlayerShots(int amount);
        void setShotVelocity(float v);
        void setNumPlayerShots2(int amount);
        void setShotVelocity2(float v);
        void setup();
        void setup2();
        void draw(sf::RenderWindow& window);
        void update();
    
    
};


#endif /* UIManager_h */
