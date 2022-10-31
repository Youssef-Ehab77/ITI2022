#include <iostream>

using namespace std;

class Complex
{
    //private:
    int real;
    int imaginary;
public:
    void set_real(int R)
    {
        real = R;
    }
    void set_imaginary (int I)
    {
        imaginary = I;
    }

    int get_real ()
    {
        return real;
    }
    int get_imaginary ()
    {
        return imaginary;
    }

    void Print ()
    {
        if( real == 0 && imaginary == 0)
        {
            cout<<"0"<<endl;
        }
        else if(real == 0)
        {
            cout<<imaginary<<"i"<<endl;
        }
        else if(imaginary == 0)
        {
            cout<<real<<endl;

        }
        else if(imaginary > 0)
        {
            cout<<real<<" + "<<imaginary<<"i"<<endl;

        }
        else
        {
            cout<<real<<" "<<imaginary<<"i"<<endl;

        }
    }

    Complex Sum (Complex c)
    {
        Complex c2;
        c2.set_real(c.get_real() + real);
        c2.set_imaginary(c.get_imaginary() + imaginary);
        return c2;

    }
};

Complex Sub (Complex c1, Complex c2)
{
    Complex c3;
    c3.set_imaginary(c1.get_imaginary() - c2.get_imaginary());
    c3.set_real(c1.get_real() - c2.get_real());
    return c3;
}


int main()
{
    Complex c1, c2, c3, c4;
    int r1,r2,i1,i2;

    cout<<"Enter 1st Real"<<endl;
    cin>>r1;
    c1.set_real(r1);

    cout<<"Enter 1st Imaginary"<<endl;
    cin>>i1;
    c1.set_imaginary(i1);

    cout<<"Enter 2st Real"<<endl;
    cin>>r2;
    c2.set_real(r2);

    cout<<"Enter 2st Imaginary"<<endl;
    cin>>i2;
    c2.set_imaginary(i2);

    cout<<"You Entered : "<<endl;
    c1.Print();
    c2.Print();

    cout<<"Sum of 1st and 2nd is :"<<endl;
    c4 = c1.Sum(c2);
    c4.Print();

    cout<<"Subtraction of 1st and 2nd is :"<<endl;
    c3 = Sub(c1,c2);
    c3.Print();

    return 0;
}
