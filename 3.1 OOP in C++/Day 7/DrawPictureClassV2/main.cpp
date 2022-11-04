#include <iostream>
#include <graphics.h>
#include <conio.h>

using namespace std;


class GeoShape
{
public:
    virtual void draw() = 0;
};

class Color
{
    int color;
public:
    Color() {}

    Color(int _color)
    {
        color = _color;
        setcolor(color);
    }
};

class Point
{
    int x, y;
public:
    Point()
    {
        //cout << "parameterless Point ctor" << endl;
    }

    Point(int _x, int _y)
    {
        //cout << "Point Constructor" << endl;
        x = _x;
        y = _y;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    ~Point()
    {
        //cout << "Point Destructor" << endl;
    }

};

class DrawLine : public GeoShape
{
    Point p1, p2;
    Color c;
public:
    DrawLine(int x1, int y1, int x2, int y2, int color)
        : p1(x1, y1), p2(x2, y2), c(color)
    {
    }

    void draw()
    {
        line(p1.getX(), p1.getY(), p2.getX(), p2.getY());
    }

    Point &getP1()
    {
        return p1;
    }

    Point &getP2()
    {
        return p2;
    }

    ~DrawLine()
    {
        // cout << "Line Destructor" << endl;
    }
};

class DrawCircle : public GeoShape
{
    int radius;
    Point Center;
    Color c;

public:
    DrawCircle(int x, int y, int _radius, int color)
        : Center(x, y), c(color)
    {
        radius = _radius;
        draw();
    }

    int getRadius()
    {
        return radius;
    }

    Point &getCenter()
    {
        return Center;
    }

    void draw()
    {
        circle(Center.getX(), Center.getY(), radius);

    }

    ~DrawCircle()
    {
        //cout << "Circle Destructor" << endl;
    }
};

class DrawRectangle : public GeoShape
{
    Point p1, p2;
    Color c;

public:
    DrawRectangle(int x1, int y1, int x2, int y2, int color)
        : p1(x1, y1), p2(x2, y2), c(color)
    {
    }

    void draw()
    {
        rectangle(p1.getX(), p1.getY(), p2.getX(), p2.getY());

    }

    ~DrawRectangle()
    {
        //cout << "Rectangle Destructor" << endl;
    }

    Point &getP1()
    {
        return p1;
    }

    Point &getP2()
    {
        return p2;
    }

};

class Picture : public GeoShape
{
    Color clr;
    GeoShape **gs;
    int numberOfShapes;

public:
    Picture(GeoShape **_gs, int _numberOfShapes,  int color): clr(color)
    {
        gs = _gs;
        numberOfShapes = _numberOfShapes;
    }

    void draw()
    {
        for (int i = 0; i < numberOfShapes; i++)
        {
            //gs[i]->draw();
            (*gs[i]).draw();
        }
    }
};


int main()
{
    //1500 x 800 px
    initgraph();
    int color;
    cout << "Please choose a color from 0 to 15: " << endl;
    cin >> color;

    ///1 top , 2 side and 1 bottom lines
    int z1 = 615, z2 = 120, z3 = 885, z4 = 120;
    int x1 = 615, y1 = 120, x2 = 550, y2 = 320;
    int x3 = 885, y3 = 120, x4 = 950, y4 = 320;
    int x5 = 550, y5 = 320, x6 = 950, y6 = 320;

    ///middle 5 circles
    int centerX4 = 750, centerY4 = 360, radius4 = 80;
    int centerX5 = 750, centerY5 = 400, radius5 = 80;
    int centerX6 = 750, centerY6 = 440, radius6 = 80;
    int centerX7 = 750, centerY7 = 480, radius7 = 80;
    int centerX8 = 750, centerY8 = 520, radius8 = 80;

    ///rectangle
    int x7 = 550, y7 = 520, x8 = 950, y8 = 600;

    DrawCircle c[5] = {DrawCircle(centerX4, centerY4, radius4, color), DrawCircle(centerX5, centerY5, radius5, color),
                       DrawCircle(centerX6, centerY6, radius6, color), DrawCircle(centerX7, centerY7, radius7, color),
                       DrawCircle(centerX8, centerY8, radius8, color)
                      };

    DrawLine l[4] = {DrawLine(z1, z2, z3, z4, color), DrawLine(x1, y1, x2, y2, color), DrawLine(x3, y3, x4, y4, color),
                     DrawLine(x5, y5, x6, y6, color)};

    DrawRectangle r[1] = {DrawRectangle(x7, y7, x8, y8, color)};

    GeoShape *g[10] = {c,&c[1],&c[2],&c[3],&c[4],l,&l[1],&l[2],&l[3],r};
    Picture p(g,10, color);
    p.draw();


    _getch();

    return 0;
}
