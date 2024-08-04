#include "vec.h"

Vec::Vec()
{
    x_ = 0;
    y_ = 0;
}
Vec::Vec(int x, int y){
    x_ = x;
    y_ = y;
}
//initialize the value in the Vec
int Vec::getX() const{ return x_; }
int Vec::getY() const{ return y_; }
// return current vector added by another vector v

Vec Vec::operator + (const Vec v) const{
    return Vec(x_ + v.getX(), y_ + v.getY());
}
Vec Vec::operator - (const Vec v) const{
    return Vec(x_ - v.getX(), y_ - v.getY());
}
Vec Vec::operator * (const float v) const{
    return Vec(v * x_, v * y_);
}
bool Vec::operator == (const Vec v) const{
    return (x_ == v.x_ && y_ ==v.y_);
}

