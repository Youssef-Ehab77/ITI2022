#include <iostream>

using namespace std;

class GeoShape {
protected:
    int dim1, dim2;
public:
    GeoShape(int x = 0, int y = 0) {
        dim1 = x;
        dim2 = y;
    }

    virtual double cArea() = 0;

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
    }
};

class Rectangle : public GeoShape {
public:
    Rectangle() {}

    Rectangle(int w, int h) : GeoShape(w, h) {
    }

    ~Rectangle() {
    }

    double cArea()  {
        return dim1 * dim2;
    }
};

class Square : public Rectangle {
public:
    Square() {}

    Square(int s) : Rectangle(s, s) {
    }

    ~Square() {}


};

class Circle : public GeoShape {
public:
    Circle() {}

    Circle(int r) : GeoShape(r, r) {
    }

    ~Circle() {
    }

    double cArea() {
        return 3.14 * dim1 * dim2;
    }
};

class Triangle : public GeoShape {
public:
    Triangle() {}

    Triangle(int b, int h) : GeoShape(b, h) {
    }

    ~Triangle() {
    }

    double cArea() {
        return 0.5 * dim1 * dim2;
    }
};

double sum_of_all_areas(GeoShape **g, int numOfShapes) {
    double totalSum = 0;

    for (int i = 0; i < numOfShapes; i++) {
        totalSum += g[i]->cArea();
    }

    return totalSum;
}


int main() {

    double totalSum;
    Rectangle r[2] = {Rectangle(7, 8), Rectangle(3, 5)};
    Square s[2] = {Square(20), Square(15)};
    Circle c[1] = {Circle(10)};
    Triangle t[3] = {Triangle(1, 2), Triangle(27, 7), Triangle(17, 12)};

    GeoShape *g[8] = {r, &r[1], s, &s[1], c, t, &t[1], &t[2]};
    totalSum = sum_of_all_areas(g, 8);
    cout << "Total Area of Shapes is : " << totalSum << endl;

    return 0;
}
