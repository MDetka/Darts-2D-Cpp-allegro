#include "Point.h"
Point::Point ()
{
    x=0.0;
    y=0.0;
}
Point::Point( int x, int y)
{
    this->x = x;
    this->y = y;
}

int Point::getx()
{
    return x;
}

int Point::gety()
{
    return y;
}

void Point::setx(int newx)
{
    x=newx;
}
void Point::sety(int newy)
{
    y=newy;
}
