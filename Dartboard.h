#ifndef DARTBOARD_H
#define DARTBOARD_H

#include "Circle.h"
#include "Triangles.h"
#include "Point.h"
#include <math.h>
#include <allegro.h>
#include <time.h>

#ifndef M_PI
    #define PI 3.14159265358979323846
#endif
class Dartboard
{
private:
    Triangles tri[20];
    Circle  circles[6];
    int points_of_triangles[20] = {20,1,18,4,13,6,10,15,2,17,3,19,7,16,8,11,14,9,12,5};
    Point p;
public:
    Dartboard();
    void create_circles();
    void create_triangles();
    void draw_board(BITMAP * bmp);
    void setpoint(int x,int y);
    Point getpoint();
    int hit(int x , int y);
};
#endif // DARTBOARD_H
