#include <iostream>

using namespace std;

class Complex {
    int real, img;
public:
    Complex(int _real, int _img) {
        real = _real;
        img = _img;
        //cout << "Constructor with 2 parameters, invoker address is --> " << this << endl;
    }

    Complex(Complex &c) {
        real = c.real;
        img = c.img;
        cout << "Copy Ctor" << endl;

    }

    Complex(int x) {
        real = img = x;
        //cout << "Constructor with 1 parameter, invoker address is --> " << this << endl;
    }

    Complex() {
        //cout << "Constructor with no parameters, invoker address is --> " << this << endl;
    }

    void setReal(int _real) {
        real = _real;
    }

    void setImg(int _img) {
        img = _img;
    }

    int getReal() const {
        return real;
    }

    int getImg() const {
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


    Complex Sum(Complex &c) {
        Complex c2;
        c2.setReal(c.getReal() + real);
        c2.setImg(c.getImg() + img);
        return c2;

    }

    ~Complex() {
        //cout << "Destructor of object with address -->" << this << endl;
    }

    ///c3 = c1 - c2;
    Complex &operator=(const Complex &c) {
        real = c.real;
        img = c.img;
        return *this;
    }

    Complex operator-(const Complex &c) {
        Complex result;
        result.real = real - c.real;
        result.img = img - c.img;
        return result;
    }

    Complex operator-(int r) {
        Complex result;
        result.setReal(real - r);
        result.setImg(img);
        return result;
    }

    Complex &operator-=(const Complex &c) {
        real -= c.getReal();
        img -= c.getImg();
        return *this;
    }

    Complex &operator-=(int r) {
        real -= r;
        return *this;
    }

    Complex &operator--() {
        --real;
        return *this;
    }

    Complex operator--(int) {
        Complex temp(*this);
        real--;
        return temp;
    }

    bool operator==(const Complex &c) {
        return (real == c.getReal() && img == c.getImg());
    }

    bool operator!=(const Complex &c) {
        return (real != c.getReal() && img != c.getImg());
    }

    bool operator>=(const Complex &c) {
        return (real >= c.getReal());
    }

    bool operator>(const Complex &c) {
        return (real > c.getReal());
    }

    bool operator<=(const Complex &c) {
        return (real <= c.getReal());
    }

    bool operator<(const Complex &c) {
        return (real < c.getReal());
    }

    operator int() {
        return real;
    }

//    string printS(){
//        string s;
//        if (real == 0 && img == 0) {
//            s = "0" ;
//        } else if (real == 0) {
//            s = img +"i";
//        } else if (img == 0) {
//            s = real;
//        } else if (img > 0) {
//            s = real + " + " + img + "i";
//        } else {
//            s = real + " " + img + "i";
//        }
//        return s;
//    }
//    operator char *() {
//        char c[] = {(char) this->real, (char) this->img};
//        return c;
//    }

};

///c3 = 7 - c1;
Complex operator-(int l, const Complex &c) {
    Complex result;
    result.setReal(l - c.getReal());
    result.setImg(c.getImg());
    return result;
}

Complex operator-=(int l, const Complex &c) {
    Complex result;
    result.setReal(7 - c.getReal());
    result.setImg(c.getImg());
    return result;
}

int main() {
    Complex c1(1, 2), c2(5), c3, c4, c5, c6, c7, c8, c9, c10, c11(1, 2), c12, c13, c14;
    cout << "/////////////////////////////////////////////////" << endl;
    cout << "1. c3 = c1 - c2 " << endl;
    c3 = c1 - c2;
    c3.Print();

    cout << "/////////////////////////////////////////////////" << endl;
    cout << "2. c4 = 7 - c1 " << endl;
    c4 = 7 - c1;
    c4.Print();

    cout << "/////////////////////////////////////////////////" << endl;
    cout << "3. c5 = c1 - 7 " << endl;
    c5 = c1 - 7;
    c5.Print();

    cout << "/////////////////////////////////////////////////" << endl;
    cout << "4. c1 -= c2 " << endl;
    c6 = c1;
    c6 -= c2;
    c6.Print();

    cout << "/////////////////////////////////////////////////" << endl;
    cout << "5. c1 -= 7 " << endl;
    c7 = c1;
    c7 -= 7;
    c7.Print();

    cout << "/////////////////////////////////////////////////" << endl;
    cout << "6. 7 -= c1 " << endl;
    c8 = c1;
    (7 -= c8).Print();

    cout << "/////////////////////////////////////////////////" << endl;
    cout << "7. --c1 " << endl;
    c9 = --c1;
    c1.Print();
    c9.Print();

    cout << "/////////////////////////////////////////////////" << endl;
    cout << "8. c1-- " << endl;
    c10 = c1--;
    c1.Print();
    c10.Print();

    cout << "/////////////////////////////////////////////////" << endl;
    cout << "9. c1 == c2 " << endl;
    cout << (c1 == c2) << endl; //--> false
    cout << (c11 == c1) << endl; // --> true

    cout << "/////////////////////////////////////////////////" << endl;
    cout << "10. c1 != c2 " << endl;
    cout << (c1 != c2) << endl; //--> true
    cout << (c11 != c1) << endl; // --> false

    cout << "/////////////////////////////////////////////////" << endl;
    cout << "11. c1 > c2  , c1  >= c11" << endl;
    cout << (c1 > c2) << endl; //--> false
    cout << (c1 >= c11) << endl; // --> true

    cout << "/////////////////////////////////////////////////" << endl;
    cout << "12. c1 < c2  , c1  <= c11" << endl;
    cout << (c1 < c2) << endl; //--> true
    cout << (c1 <= c11) << endl; // --> true

    cout << "/////////////////////////////////////////////////" << endl;
    cout << "13. (int)c1" << endl;
    cout << "Int c1 --> " << (int) c1 << endl;

//    cout << "/////////////////////////////////////////////////" << endl;
//    cout << "14. (char*)c1" << endl;
//    char *c = (char *) c1;
//    for (int i = 0; i < 2; i++) {
//        cout << "Char* c1 --> " << c[i] << endl;
//    }

    return 0;
}
