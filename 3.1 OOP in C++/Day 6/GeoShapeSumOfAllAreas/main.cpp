#include <iostream>

using namespace std;

class GeoShape {
protected:
    int dim1, dim2;
public:
    GeoShape(int x = 0, int y = 0) {
        dim1 = x;
        dim2 = y;
        //cout << "GeoShape Ctor" << endl;
    }

    int getDim1() const {
        return dim1;
    }

    void setDim1(int dim1) {
        GeoShape::dim1 = dim1;
    }

    int getDim2() const {
        return dim2;
    }

    void setDim2(int dim2) {
        GeoShape::dim2 = dim2;
    }

    ~GeoShape() {
        //cout << "GeoShape Dtor" << endl;
    }
};

class Rectangle : public GeoShape {
public:
    Rectangle(){}

    Rectangle(int w, int h) : GeoShape(w, h) {
        //cout << "Rectangle Ctor" << endl;
    }

    ~Rectangle() {
        //cout << "Rectangle Dtor" << endl;
    }

    double Area() {
        return dim1 * dim2;
    }
};

class Square : public Rectangle {
public:
    Square(){}

    Square(int s) : Rectangle(s, s) {
        //cout << "Square Ctor" << endl;
    }

    ~Square() {
        //cout << "Square Dtor" << endl;
    }


};

class Circle : public GeoShape {
public:
    Circle(){}

    Circle(int r) : GeoShape(r, r) {
        //cout << "Circle Ctor" << endl;
    }

    ~Circle() {
        //cout << "Circle Dtor" << endl;
    }

    double Area() {
        return 3.14 * dim1 * dim2;
    }
};

class Triangle : public GeoShape {
public:
    Triangle(){}

    Triangle(int b, int h) : GeoShape(b, h) {
        //cout << "Triangle Ctor" << endl;
    }

    ~Triangle() {
        //cout << "Triangle Dtor" << endl;
    }

    double Area() {
        return 0.5 * dim1 * dim2;
    }
};

double sum_of_all_areas(Square *s, int numOfSquares, Rectangle *r, int numOfRectangles, Circle *c, int numOfCircles,
                        Triangle *t, int numOfTriangles) {
    double totalSum = 0;

    for (int i = 0; i < numOfCircles; i++) {
        totalSum += c[i].Area();
    }

    for (int i = 0; i < numOfRectangles; i++) {
        totalSum += r[i].Area();
    }
    for (int i = 0; i < numOfSquares; i++) {
        totalSum += s[i].Area();
    }
    for (int i = 0; i < numOfTriangles; i++) {
        totalSum += t[i].Area();
    }

    return totalSum;
}


int main() {

    double totalSum;
    Rectangle r[2];
    Square s[2];
    Circle c[1];
    Triangle t[3];

    /// 2 Rectangles
    Rectangle r1(7, 8);
    cout << "Rectangle 1 Area: " << r1.Area() << endl;
    Rectangle r2(3, 5);
    cout << "Rectangle 2 Area: " << r2.Area() << endl;
    r[0] = r1;
    r[1] = r2;

    /// 2 Squares
    Square s1(20);
    cout << "Square 1 Area: " << s1.Area() << endl;
    Square s2(15);
    cout << "Square 2 Area: " << s2.Area() << endl;
    s[0] = s1;
    s[1] = s2;

    /// 1 Circle
    Circle c1(10);
    cout << "Circle 1 Area: " << c1.Area() << endl;
    c[0] = c1;

    /// 3 Triangles
    Triangle t1(1, 2);
    cout << "Triangle 1 Area: " << t1.Area() << endl;
    Triangle t2(27, 7);
    cout << "Triangle 2 Area: " << t2.Area() << endl;
    Triangle t3(17, 12);
    cout << "Triangle 3 Area: " << t3.Area() << endl;
    t[0] = t1;
    t[1] = t2;
    t[2] = t3;

    totalSum = sum_of_all_areas(s, 2, r, 2, c, 1, t, 3);
    cout << "Total Area of Shapes is : " << totalSum << endl;

    return 0;
}
