#include <iostream>

using namespace std;

template<class type>
class Arr {
    type *arr;
    int size;
    static int aNum;
public:
    Arr() {
        aNum++;
    }

    Arr(int _size) {
        aNum++;
        size = _size;
        arr = new type[size];
    }

    ///copy constructor
    Arr(const Arr &a) {
        size = a.size;
        arr = new type[size];
        for (int i = 0; i < size; i++) {
            arr[i] = a.arr[i];
        }
        aNum++;
    }

    void setAt(int index, type value) {
        if (index < size && index >= 0)
            arr[index] = value;
        else cout << "Index out of size!" << endl;
    }

    static int getaNum(){
        return aNum;
    }

    int getSize() const {
        return size;
    }

    Arr &operator=(const Arr &a) {
        delete[]arr;
        size = a.size;
        arr = new type[size];
        for (int i = 0; i < size; i++) {
            arr[i] = a.arr[i];
        }
        return *this;
    }

    type &operator[](int index) {
        if (index < size && index >= 0)
            return arr[index];
        cout << "Index out of size!" << endl;
    }

    Arr operator+(const Arr &a) {
        Arr sum(size > a.size ? *this : a); ///deep copy using copy ctor the array with bigger size
        int smallerSize = size < a.size ? size : a.size;

        for (int i = 0; i < smallerSize; ++i) {
            sum.arr[i] +=
                    size < a.size ? arr[i] : a.arr[i];///add the values of the array with smaller size to the sum array
        }
        return sum;
    }

    ~Arr() {
        aNum--;
        delete[]arr;
    }

};
template<class type>
int Arr<type>::aNum = 0;


int main() {


    Arr<double> mya(7);
    cout << "#mya Array -->" << endl;
    for (int i = 0; i < mya.getSize(); ++i) {
        mya[i] = 3.2 * i;
        cout << mya[i] << endl;
    }
    cout<<"Snum double = "<<Arr<double>::getaNum()<<endl;
    cout << "*******************************************" << endl;

    Arr<double> mya2(5);
    cout << "#mya2 Array -->" << endl;
    for (int i = 0; i < mya2.getSize(); ++i) {
        mya2[i] = 2.77 + i;
        cout << mya2[i] << endl;
    }
    cout<<"Snum double= "<<Arr<double>::getaNum()<<endl;
    cout << "*******************************************" << endl;

    Arr<double> sum = mya + mya2;
    cout << "#sum Array -->" << endl;
    for (int i = 0; i < sum.getSize(); ++i) {
        cout << sum[i] << endl;
    }
    cout<<"Snum double= "<<Arr<double>::getaNum()<<endl;
    cout << "*******************************************" << endl;

    Arr<int> mya3(5);
    cout << "#mya3 Array -->" << endl;
    for (int i = 0; i < mya3.getSize(); ++i) {
        mya3[i] = 5 * i;
        cout << mya3[i] << endl;
    }
    cout<<"Snum double= "<<Arr<double>::getaNum()<<endl;
    cout<<"Snum Int= "<<Arr<int>::getaNum()<<endl;
    cout << "*******************************************" << endl;

    Arr<char> mya4(6);
    cout << "#mya4 Array -->" << endl;
    string s = "hello";
    for (int i = 0; i < mya4.getSize(); ++i) {
        mya4[i] = s[i];
        cout << mya4[i] << endl;
    }
    cout<<"Snum char = "<<Arr<char>::getaNum()<<endl;
    cout<<"Snum Int= "<<Arr<int>::getaNum()<<endl;
    cout << "*******************************************" << endl;
}
