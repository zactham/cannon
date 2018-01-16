//
//  Vector2f.h
//  cannon_mac
//
//  Created by Zac on 1/11/18.
//  Copyright © 2018 Zac. All rights reserved.
//
#ifndef Vector2f_h
#define Vector2f_h

class Vector2f
{
private:
    float x;
    float y;
    
    
    
public:
    Vector2f();
    Vector2f(float x,float y);
    void add(Vector2f& vector);
    void subtract(Vector2f& vector);
    void multiply(float num);
    void copy(Vector2f& vector);
    float getX();
    float getY();
    void setX(float xInput);
    void setY(float yInput);
    float getLength();
    void normalize();
    
    
};

#endif /* Vector2f_h */
