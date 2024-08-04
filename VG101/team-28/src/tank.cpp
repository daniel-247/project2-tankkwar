#include "tank.h"
#include "vec.h"
#include "bullet.h"
#include "map.h"
#include <cstdio>
#include <cmath>

Tank::Tank(){
    position_ = Vec();
}

Tank::Tank(Vec position){
    position_ = Vec(position.getX(),position.getY());
}
void Tank::directionUpdate(int num){
    if (num > 3)
        printf("false input");
    else
        direct_ = (direction_)num;
    }

void Tank::roundUpdate(Map map_){
    round_ = map_.getround();
}

int Tank::getHp(){
    return hp_;
}

void Tank::posUpdate(){
    position_ = position_ + velocity_ ;
}

bool Tank::lineCheck(Map map_){
    int mapLength = map_.getLength() / 2;
    Vec pos = getPos();
    int deviation = ( maxLength - mapLength ) / 2;
    if (deviation <= pos.getX() && pos.getX() >= mapLength - deviation && deviation <= pos.getY() && pos.getY() >= mapLength - deviation )
        return true;
        else
        return false;
}

void Tank::hpUpdate(Map map_){
    if (!lineCheck(map_)){
        hp_ = hp_ - 1;
    }
    if ( isHit_ ){
        hp_ = hp_ - 2;
    }
}

void Tank::isHit(bool hit){
    isHit_ = hit;
}// consider whether the bullet will hit the tank

Vec Tank::getPos(){
    return position_;
}

void Tank::bulletNumUpdate(Map map_){
    if (map_.getround() % 3 == 1)
        bulletNum_ ++;
}
bool tankCrash(Tank tank1, Tank tank2){
    return (tank1.getPos() == tank2.getPos());
}

result_ winOrLose(Tank tank1,Tank tank2){
    int hp1 = tank1.getHp();
    int hp2 = tank2.getHp();
    if (tankCrash(tank1, tank2)){
        if (hp1 > hp2){
            return win_;
        }
        if (hp1 < hp2){
            return lose_;
        }
        if(hp1 == hp2){
            return draw_;
        }
    }
    else{
        if (hp1 == 0)
            return lose_;
        if (hp2 == 0)
            return win_;
        return keep_;
    }
}

void operation(result_ result){
    switch(result){
        case win_:
        {
            win();
        }
        case lose_:
        {
            lose();
        }
        case keep_:
        {
            keep();
        }
        case draw_:
        {
            draw();
        }
    }
}

int bulletHit(Tank tank1, Tank tank2){
    Vec pos = tank2.getPos();
    int num = 0;
    for (int i = 0; i< tank1.getBulletNum(); i++){
        // record the parameter of the bullet
        Vec pos_ = tank1.getBullet(i).getFinalPos();
        Vec dir = tank1.getBullet(i).getDirect();
        if ( pos_ - dir == pos || pos_ == pos || pos_ - dir * 2 == pos)
        // three possible situation related with the direction of the bullet.
            num ++;
    }
    return num;
}