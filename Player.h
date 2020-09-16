#ifndef PLAYER_H
#define PLAYER_H
#include "Point.h"
#include <time.h>
#include <allegro.h>
class Player{
private:
    int score;
public:
    Player();
    int getscore();
    void setscore(int newscore);
    void update(int points);

};
#endif // PLAYER_H
