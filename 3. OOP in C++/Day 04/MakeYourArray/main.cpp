#include <iostream>

using namespace std;

class intArr
{
    int *arr, size;
public:
    intArr() {}

    intArr(int _size)
    {
        size = _size;
        arr = new int[size];
    }

    ///copy constructor
    intArr(const intArr &a)
    {
        size = a.size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = a.arr[i];
        }
    }

    void setAt(int index, int value)
    {
        if (index < size && index >= 0)
            arr[index] = value;
        else cout << "Index out of size!" << endl;
    }

    int getSize() const
    {
        return size;
    }

    intArr &operator=(const intArr &a)
    {
        delete[]arr;
        size = a.size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = a.arr[i];
        }
        return *this;
    }

    int &operator[](int index)
    {
        if (index < size && index >= 0)
            return arr[index];
        cout << "Index out of size!" << endl;
    }

    intArr operator+(const intArr &a)
    {
        intArr sum(size > a.size ? *this : a); ///deep copy using copy ctor the array with bigger size
        int smallerSize = size < a.size ? size : a.size;

        for (int i = 0; i < smallerSize; ++i)
        {
            sum.arr[i] += size < a.size ? arr[i] : a.arr[i];///add the values of the array with smaller size to the sum array
        }
        return sum;
    }

    ~intArr()
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
        delete[]arr;
    }

};

int main()
{

    intArr mya(7);
    cout << "#mya Array -->" << endl;
    for (int i = 0; i < mya.getSize(); ++i)
    {
        mya[i] = 3 * i;
        cout << mya[i] << endl;
    }
    cout << "*******************************************" << endl;

    intArr mya2(5);
    cout << "#mya2 Array -->" << endl;
    for (int i = 0; i < mya2.getSize(); ++i)
    {
        mya2[i] = 2 + i;
        cout << mya2[i] << endl;
    }
    cout << "*******************************************" << endl;

    intArr sum = mya + mya2;
    cout << "#sum Array -->" << endl;
    for (int i = 0; i < sum.getSize(); ++i)
    {
        cout << sum[i] << endl;
    }


}
