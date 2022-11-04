#include <iostream>

using namespace std;

class Parent {
    int a;
protected:
    int b;
public:
    int c;

    Parent(int _a, int _b, int _c) {
        a = _a;
        b = _b;
        c = _c;
    }
};

class Child : public Parent {
    int d;
protected:
    int e;
public:
    int f;

    Child(int _d, int _e, int _f, int _a, int _b, int _c)
            : Parent(_a, _b, _c) {

        d = _d;
        e = _e;
        f = _f;
    }
};

class GrandChild : private Child {
    int x;
protected:
    int y;
public:
    int z;

    GrandChild(int _x, int _y, int _z, int _d, int _e, int _f, int _a, int _b,
               int _c) : Child(_d, _e, _f, _a, _b, _c) {
        x = _x;
        y = _y;
        z = _z;
        f = 3;
        //d = 3; private in parent
        e = 3;
        b = 1;
    }


};

int main() {
    Parent p(1, 2, 3);
    Child(1, 2, 3, 4, 5, 6);
    GrandChild(1, 2, 3, 4, 5, 6, 7, 8, 9);
    return 0;
}
