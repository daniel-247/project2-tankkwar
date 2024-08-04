#ifndef MAP_H
#define MAP_H
#define maxLength 20
class Map{
    private:
        int round_;//default 0
        int length_;
    public:
        int getround();
        void mapdrawing();
        void round(int round);
        int getLength();
};      
#endif