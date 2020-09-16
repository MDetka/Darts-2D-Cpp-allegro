#ifndef CIRCLE_H
#define CIRCLE_H
#include <allegro.h>
#include "Point.h"
class Circle
{
private:
    Point centre;
    int radius;

public:
    Circle();
    Circle(Point p,int radius,int multiplier);
    bool inside(Point p);
    int multiplier;
};
#endif // CIRCLE_H
