#ifndef VEC_H
#define VEC_H
#include <cmath>
class Vec{
    private:
        int x_,y_;

    public:
        //vector initialize
        Vec();
        Vec(int x, int y);
        //get the coodinate of the Vec
        int getX() const;
        int getY() const;
        //vector addition
        Vec operator + (const Vec v) const;  
        //vector substraction
        Vec operator - (const Vec v) const;
        //vector multplication 
        Vec operator * (const float v) const;
        //vector 
        bool operator == (const Vec v) const;

};

#endif