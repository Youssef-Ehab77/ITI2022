#include <iostream>

using namespace std;


class Complex
{
    int real;
    int imaginary;

public:
    void set_real(int _real)
    {
        real = _real;
    }
    int get_real()
    {
        return real;
    }

    void set_imaginary(int _imaginary)
    {
        imaginary = _imaginary;
    }

    int get_imaginary()
    {
        return imaginary;
    }

    void print_complex()
    {
        cout<<real<<" + "<<imaginary<<"i"<<endl;
    }

    void sum(Complex c)
    {
        cout<<"Sum = "<<c.get_real() + real<<" + "<<c.get_imaginary()+imaginary<<"i"<<endl;
    }

};

void sum_standAlone(Complex c1 , Complex c2)
{
    cout<<"Stand Alone Sum = "<<c1.get_real() + c2.get_real()<<" + "<<c1.get_imaginary()+c2.get_imaginary()<<"i"<<endl;

}

int main()
{

    Complex c1, c2;
    c1.set_imaginary(5);
    c1.set_real(3);
    c1.print_complex();

    c2.set_real(6);
    c2.set_imaginary(17);
    c2.print_complex();

    c1.sum(c2);
    sum_standAlone(c1,c2);
    return 0;
}
