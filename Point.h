#ifndef POINT_H
#define POINT_H
class Point
{
private:
    int x;
    int y;
public:
    Point ();
    Point( int x, int y);
    int getx();
    int gety();
    void setx(int newx);
    void sety(int newy);
};

#endif //POINT_H
