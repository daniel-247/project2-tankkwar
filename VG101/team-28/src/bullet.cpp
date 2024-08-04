#include "bullet.h"
#include "vec.h"
#include "map.h"
//Initialize
Bullet::Bullet (const Vec position, Vec velocity, Map map_){
    position_ = Vec(position.getX(),position.getY());
    velocity_ = velocity;
    existence_ = true;
    round_ = map_.getround();
}
//return the position of the bullet
Vec Bullet::getFinalPos(){
    return finalPosition_;
}
//calculate the current position
void Bullet::finalPosition(){
    finalPosition_ = position_ + velocity_ * round_ ;
}
void Bullet::roundUpdate(Map map_){
    round_ = map_.getround();
}
