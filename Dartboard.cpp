#include "Dartboard.h"
Dartboard::Dartboard()
{
    create_circles();
    create_triangles();

}
void Dartboard::create_circles()
{
    Point p = Point(400,100);
    circles[0] = Circle(p,3,50);
    circles[1] = Circle(p,6,25);
    circles[2] = Circle(p,38,1);
    circles[3] = Circle(p,43,3);
    circles[4] = Circle(p,64,1);
    circles[5] = Circle(p,70,2);
}

void Dartboard::create_triangles()
{
    int xy[20];
    int yy[20];
    double start_angle=-99;
    double angle=start_angle;
    double step=360/20;
    int radius = 67;
    int i = 0;
    Point centre = Point(400,100);

    for(i=0; i<20; i++)
    {
        xy[i]=400 + radius * cos(angle*PI/180);
        yy[i]=100 + radius * sin(angle*PI/180);
        angle+=step;
    }
    for(int i=0; i<19; i++)
    {
        tri[i] = Triangles(centre,Point(xy[i],yy[i]),Point(xy[i+1],yy[i+1]));
    }
    tri[19] = Triangles(centre,Point(xy[19],yy[19]),Point(xy[0],yy[0]));

}


void Dartboard::draw_board(BITMAP * bmp)
{
    for(int i = 0; i<20; i++)
    {
        for(int j=0; j<3; j++)
        {
            putpixel(bmp,tri[i].tri[j].getx(),tri[i].tri[j].gety(),makecol(255,0,0));
            rest(100);
        }
        blit(bmp,screen,0,0,0,0,800,600);
    }
}
int Dartboard::hit(int x,int y)
{
    x  = rand() % 21 - 10 + x;
    y  = rand() % 21 - 10 + y;
    setpoint(x,y);
    Point p = Point(x,y);

    if(circles[0].inside(p))
    {
        return 50;
    }
    else if(circles[1].inside(p))
    {
        return 25;
    }
    else
    {

        for(int j=2; j<6; j++)
        {
            if(circles[j].inside(p))
            {
                for(int i=0; i<20; i++)
                {
                    if(tri[i].inside(p))
                    {
                        return points_of_triangles[i] * circles[j].multiplier;
                    }
                }
            }
        }
    }

    return 0;

}
void Dartboard::setpoint(int x,int y){
p.setx(x);
p.sety(y);
}

Point Dartboard::getpoint(){
return p;
}
