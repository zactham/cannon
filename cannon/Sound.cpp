//
//  Sound.cpp
//  cannon_mac
//
//  Created by Zac on 1/23/18.
//  Copyright © 2018 Zac. All rights reserved.
//

#include "Sound.h"
#include <SFML/Audio.hpp>

//Constructor
Sound::Sound()
{
    
}

void Sound::load(std::string filename)
{
    sb.loadFromFile(filename);
}

void Sound::play()
{
    sound.play();
}

void Sound::pause()
{
    sound.pause();
}

void Sound::stop()
{
    sound.stop();
}

void Sound::setVolume(float volume)
{
    sound.setVolume(volume);
}