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

bool Sound::load(std::string filename)
{
    bool status = sb.loadFromFile(filename);
    sound.setBuffer(sb);
    return status;//returns true on success
    
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