#ifndef BULLET_H
#define BULLET_H
#include "vec.h"
#include "map.h"
class Bullet{
    private:
        Vec position_;
        enum crash_{
            crash, 
            existence
        };
        Vec velocity_;
        bool existence_;
        int round_;
        Vec finalPosition_;
        Vec dir_;
    public:
        Bullet();
        Bullet (const Vec position, Vec velocity, Map map_);
        Vec getFinalPos ();
        //bool iscrash();
        //bool isexistence();
        void finalPosition();
        void roundUpdate(Map map_);
        Vec getVelocity();
        Vec getDirect();
};
#endif