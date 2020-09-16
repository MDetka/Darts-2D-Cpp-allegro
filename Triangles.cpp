#include "Triangles.h"
Triangles::Triangles()
{
    tri[0].setx(0);
    tri[0].sety(0);
    tri[1].setx(0);
    tri[1].sety(0);
    tri[2].setx(0);
    tri[2].sety(0);
}
Triangles::Triangles(Point a, Point b, Point c)
{
    tri[0]=a;
    tri[1]=b;
    tri[2]=c;
}
bool Triangles::inside(Point p)
{
    int d1,d2,d3;
    d1=p.getx()*(tri[0].gety()-tri[1].gety()) + p.gety() * (tri[1].getx()-tri[0].getx()) + (tri[0].getx()*tri[1].gety() -tri[0].gety()*tri[1].getx());
    d2=p.getx()*(tri[1].gety()-tri[2].gety()) + p.gety() * (tri[2].getx()-tri[1].getx()) + (tri[1].getx()*tri[2].gety() -tri[1].gety()*tri[2].getx());
    d3=p.getx()*(tri[2].gety()-tri[0].gety()) + p.gety() * (tri[0].getx()-tri[2].getx()) + (tri[2].getx()*tri[0].gety() -tri[2].gety()*tri[0].getx());
    return (((d1<=0)&&(d2<=0)&&(d3<=0)) || ((d1>=0)&&(d2>=0)&&(d3>=0)));
}
