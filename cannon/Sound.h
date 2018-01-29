//
//  Sound.h
//  cannon_mac
//
//  Created by Zac on 1/23/18.
//  Copyright © 2018 Zac. All rights reserved.
//

#ifndef Sound_h
#define Sound_h
#include <SFML/Audio.hpp>
class Sound
{
private:
    sf::Sound sound;
    sf::SoundBuffer sb;
    
    
public:
    Sound();
    void load(std::string filename);
    void play();
    void pause();
    void stop();
    void setVolume(float volume);
    
};




#endif /* Sound_h */
