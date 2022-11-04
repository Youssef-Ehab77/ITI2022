#include <iostream>

using namespace std;

template<class type>
class Stack {

    type *stk;
    int top, size;
    static int sNum;
public:
    Stack() {
        top = 0;
        size = 0;
        stk;
        sNum++;
    }

    Stack(Stack &s) {
        top = s.top;
        size = s.size;
        stk = new type[size];
        for (int i = 0; i < top; i++) {
            stk[i] = s.stk[i];
        }
        sNum++;
    }

    Stack(int _size) {
        top = 0;
        size = _size;
        stk = new type[size];
        sNum++;
    }

    Stack reverse() {
        Stack r(size);
        for (int i = 0; i < top; i++) {
            r.push(stk[top - i - 1]);
        }
        return r;
    }

    bool isFull() {
        return top == size;
    }

    bool isEmpty() {
        return top == 0;
    }

    static int getsNum() {
        return sNum;
    }

    type pop() {
        if (!isEmpty()) {
            // top--;
            return stk[--top];
        }
        cout << "Stack is already Empty!" << endl;
        return -1;
    }

    void push(type num) {
        if (!isFull()) {
            stk[top] = num;
            top++;
        } else cout << "Stack is already Full!" << endl;

    }

    type peek() {
        if (!isEmpty()) return stk[top - 1];
    }

    int numberOfElements() {
        return top;
    }

    ~Stack() {
        sNum--;
        delete[]stk;
    }

    Stack operator+(const Stack &s) {
        Stack result;
        result.size = size + s.size;
        result.stk = new type[result.size];

        for (int i = 0; i < top; i++) {
            result.stk[i] = stk[i];
            result.top++;
        }

        for (int i = 0; i < s.top; i++) {
            result.stk[i + top] = s.stk[i];
            result.top++;
        }
        return result;
    }

    Stack &operator=(const Stack &s) {
        size = s.size;
        top = s.top;
        stk = new type[size];
        for (int i = 0; i < size; i++) {
            stk[i] = s.stk[i];
        }
        return *this;
    }

    int operator[](int index) {
        if (index < size)
            return stk[index];
        cout << "Index is out of range" << endl;
        return -1;
    }

    int getSize() {
        return size;
    }

    void setSize(int size) {
        Stack::size = size;
    }

    void view_content() {
        int i;
        for (i = 0; i < top; i++) {
            cout << i + 1 << ". " << stk[i] << endl;
        }
    }

};

template<class type>
int Stack<type>::sNum = 0;


int main() {

    cout << "Int Stack Numbers = " << Stack<int>::getsNum() << endl;
    Stack<int> s1(7);
    s1.push(3);
    s1.push(4);
    s1.push(7);
    cout << "Int Stack Numbers = " << Stack<int>::getsNum() << endl;
    Stack<int> s2 = s1;
    cout << "Int Stack Numbers = " << Stack<int>::getsNum() << endl;
    Stack<int> s3;
    cout << "Int Stack Numbers = " << Stack<int>::getsNum() << endl;
    s3 = s1 + s2;
    cout << "size of s3 : " << s3.getSize() << endl;
    s3.view_content();

    Stack<double>s4(4);
    s4.push(7.23);
    s4.push(92.6283);
    cout<<"S4 double type peek's is = "<<s4.peek()<<endl;
    cout << "Int Stack Numbers = " << Stack<int>::getsNum() << endl;
    cout << "Double Stack Numbers = " << Stack<double>::getsNum() << endl;


    return 0;
}
