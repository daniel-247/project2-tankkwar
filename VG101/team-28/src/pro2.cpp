#include<iostream>
#include "tank.h"
#include "map.h"
#include "vec.h"
#include "bullet.h"
using namespace std;

int main(){
    Vec initialPos1;
    Vec initialPos2;
    Map map;
    Tank tank1 = Tank(initialPos1);
    Tank tank2 = Tank(initialPos2);
    int round = 0;
    int mode = 0;//determine AI or human player
    int num1,num2;
    while (!isover(tank1,tank2))
    {
        cin>>num1>>num2;
        map.round(round + 1);
        operatorJudge(tank1, tank2, num1, num2, map, mode);
    }
}