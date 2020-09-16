#ifndef TRIANGLES_H
#define TRIANGLES_H
#include "Point.h"
class Triangles
{
public:
    Point tri[3];
    Triangles();
    Triangles(Point a, Point b, Point c);
    bool inside(Point p);
};



#endif // TRIANGLES_H
