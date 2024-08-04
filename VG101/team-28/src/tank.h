#ifndef TANK_H
#define TANK_H
#include "vec.h"
#include "bullet.h"
#include "map.h"
#define BulletNum 100
#define LifePoint 5
enum result_{
    win_,
    lose_,
    draw_,
    keep_
};
enum direction_{
    D_Left, 
    D_Up, 
    D_Right, 
    D_Down
};
class Tank
{
    private:
        Vec position_;
        Bullet bullet_[BulletNum];
        int hp_;
        bool existence_;
        int round_;
        int bulletNum_;
        direction_ direct_;
        Vec velocity_;
        bool isHit_;
    public:
        //initialize the tank
        Tank();
        Tank (Vec position);
        //update the current direction
        void directionUpdate(int num);       
        //update the current round of the tank
        void roundUpdate(Map map_);
        //update the current position of the tank
        void posUpdate();
        //update the current hp
        void hpUpdate(Map map_);
        // update the bulletnumber and create a new bullet space
        void bulletNumUpdate(Map map_);
        //return the current hp        
        int getHp();
        // return the position of the tank
        Vec getPos();  
        //return the information of the bullet
        Bullet getBullet(int num);
        //return the number of bullets    
        int getBulletNum();  
        // check whether the tank is out the map
        bool lineCheck(Map map_);
        // true reresents that the tank is hit
        void isHit(bool hit);
};
/*determine whether two tanks crash
true means crash*/
bool tankCrash(Tank tank1, Tank tank2);
/*determine which tank win the game 
return tank1 win or lose*/
result_ winOrLose(Tank tank1, Tank tank2);
// treat with different result
void operation(result_ result);
//different operation after judge
void win();
void lose();
void draw();
void keep();
//return the number of the bullets that hit it
int bulletHit(Tank tank1, Tank tank2);
//return whether is over
bool isover (Tank tank1, Tank tank2);
void operatorJudge(Tank tank1, Tank tank2, int num1, int num2, Map map_, int mode){
    tank1.directionUpdate(num1);
    tank1.posUpdate();
    tank1.roundUpdate(map_);
    tank1.bulletNumUpdate(map_);
    tank2.directionUpdate(num2);
    tank2.posUpdate();
    tank2.roundUpdate(map_);
    tank2.bulletNumUpdate(map_);
    int hitNum1 = bulletHit(tank1, tank2);
    int hitNum2 = bulletHit(tank2, tank1);
}

#endif
