//
//  Vector2f.cpp
//  cannon_mac
//
//  Created by Zac on 1/11/18.
//  Copyright © 2018 Zac. All rights reserved.
//

#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include "Vector2f.h"


//Constructor
Vector2f::Vector2f()
{
    x = 0;
    y = 0;
    
}

Vector2f::Vector2f(float xIn, float yIn)
{
    x = xIn;
    y = yIn;
    
}

void Vector2f::add(Vector2f& vector)
{
    setX(x+vector.getX());
    setY(y+vector.getY());
}


void Vector2f::subtract(Vector2f& vector)
{
    setX(x-vector.getX());
    setY(y-vector.getY());
}

void Vector2f::multiply(float num)
{
    setX(x*num);
    setY(y*num);
}

void Vector2f::setX(float xIn)
{
    x = xIn;
}

void Vector2f::setY(float yIn)
{
    y = yIn;
}


float Vector2f::getX()
{
    return x;
}

float Vector2f::getY()
{
    return y;
}

void Vector2f::copy(Vector2f& vector)
{
    x = vector.getX();
    y = vector.getY();
}

float Vector2f::getLength()
{
    float length = sqrtf(getX() * getX() + getY() * getY());
    return length;
}

void Vector2f::normalize()
{
    float length = getLength();
    
    setX(getX()/length);
    setY(getY()/length);
}

void Vector2f::setFromAngle(float angle)
{
   float radian = (float)(angle * M_PI / 180.f);
    setX(cosf(radian));
    setY(sinf(radian));
    
}


