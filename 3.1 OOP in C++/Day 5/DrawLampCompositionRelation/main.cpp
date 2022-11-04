#include <iostream>
#include <graphics.h>
#include <conio.h>

using namespace std;

class Point {
    int x, y;
public:
    Point() {
        cout << "parameterless Point ctor" << endl;
    }

    Point(int _x, int _y) {
        cout << "Point Constructor" << endl;
        x = _x;
        y = _y;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    ~Point() {
        cout << "Point Destructor" << endl;
    }

};

class DrawLine {
    Point p1, p2;
public:
    DrawLine(int x1, int y1, int x2, int y2)
            : p1(x1, y1), p2(x2, y2) {
        draw();
    }

    void draw() {
        line(p1.getX(), p1.getY(), p2.getX(), p2.getY());
    }

    ~DrawLine() {
        cout << "Line Destructor" << endl;
    }
};

class DrawCircle {
    int radius;
    Point Center;
public:
    DrawCircle(int x, int y, int _radius)
            : Center(x, y) {
        radius = _radius;
        draw();
    }

    void draw() {
        circle(Center.getX(), Center.getY(), radius);

    }

    ~DrawCircle() {
        cout << "Circle Destructor" << endl;
    }
};

class DrawRectangle {
    Point p1, p2;
public:
    DrawRectangle(int x1, int y1, int x2, int y2)
            : p1(x1, y1), p2(x2, y2) {
        draw();
    }

    void draw() {
        rectangle(p1.getX(), p1.getY(), p2.getX(), p2.getY());

    }

    ~DrawRectangle() {
        cout << "Rectangle Destructor" << endl;
    }
};


int main() {
    //1500 x 800 px
    initgraph();
    setcolorRGB(222, 159, 151);


    ///1 top , 2 side and 1 bottom lines
    int z1 = 615, z2 = 120, z3 = 885, z4 = 120;
    int x1 = 615, y1 = 120, x2 = 550, y2 = 320;
    int x3 = 885, y3 = 120, x4 = 950, y4 = 320;
    int x5 = 550, y5 = 320, x6 = 950, y6 = 320;

    DrawLine l1(z1, z2, z3, z4);
    DrawLine l2(x1, y1, x2, y2);
    DrawLine l3(x3, y3, x4, y4);
    DrawLine l4(x5, y5, x6, y6);

    ///middle 5 circles
    int centerX4 = 750, centerY4 = 360, radius4 = 80;
    int centerX5 = 750, centerY5 = 400, radius5 = 80;
    int centerX6 = 750, centerY6 = 440, radius6 = 80;
    int centerX7 = 750, centerY7 = 480, radius7 = 80;
    int centerX8 = 750, centerY8 = 520, radius8 = 80;

    DrawCircle(centerX4, centerY4, radius4);
    DrawCircle(centerX5, centerY5, radius5);
    DrawCircle(centerX6, centerY6, radius6);
    DrawCircle(centerX7, centerY7, radius7);
    DrawCircle(centerX8, centerY8, radius8);

    ///rectangle
    int x7 = 550, y7 = 520, x8 = 950, y8 = 600;
    DrawRectangle r1(x7, y7, x8, y8);

    _getch();

    return 0;
}
