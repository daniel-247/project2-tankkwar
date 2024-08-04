#include "map.h"

void Map::round(int round){
    round_ = round;
}
int Map::getround(){
    return round_;
}

int Map::getLength(){
    return length_;
}