#include <iostream>

using namespace std;

class Complex {
    int real, img;
public:
    Complex(int _real, int _img) {
        real = _real;
        img = _img;
        cout << "Constructor with 2 parameters, invoker address is --> " << this << endl;
    }

    Complex(int x) {
        real = img = x;
        cout << "Constructor with 1 parameter, invoker address is --> " << this << endl;
    }

    Complex() {
        cout << "Constructor with no parameters, invoker address is --> " << this << endl;
    }

    void setReal(int _real) {
        real = _real;
    }

    void setImg(int _img) {
        img = _img;
    }

    int getReal() {
        return real;
    }

    int getImg() {
        return img;
    }

    void Print() {
        if (real == 0 && img == 0) {
            cout << "0" << endl;
        } else if (real == 0) {
            cout << img << "i" << endl;
        } else if (img == 0) {
            cout << real << endl;
        } else if (img > 0) {
            cout << real << " + " << img << "i" << endl;
        } else {
            cout << real << " " << img << "i" << endl;
        }
    }

    Complex Sum(Complex c) {
        Complex c2;
        c2.setReal(c.getReal() + real);
        c2.setImg(c.getImg() + img);
        return c2;

    }

    ~Complex() {
        cout << "Destructor of object with address -->" << this << endl;
    }
};

int main() {
    Complex c1(1, 2), c2(5), c3;
    c3 = c1.Sum(c2);
    c3.Print();
    return 0;
}
