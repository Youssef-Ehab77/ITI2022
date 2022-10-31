#include <iostream>

using namespace std;

class Stack {

    int *stk, top, size;
public:
    Stack() {
        top = 0;
        size = 0;
        stk;
    }

    Stack(Stack &s) {
        top = s.top;
        size = s.size;
        stk = new int[size];
        for (int i = 0; i < top; i++) {
            stk[i] = s.stk[i];
        }
        //cout << "copy ctor : " << endl;
    };

    Stack(int _size) {
        top = 0;
        size = _size;
        stk = new int[size];
    };

    Stack reverse() {
        Stack r(size);
        for (int i = 0; i < top; i++) {
            r.push(stk[top - i - 1]);

        }
        return r;
    };


    bool isFull() {
        return top == size;
    }

    bool isEmpty() {
        return top == 0;
    }

    int pop() {
        if (!isEmpty()) {
            // top--;
            return stk[--top];
        }
        cout << "Stack is already Empty!" << endl;
        return -1;
    }

    void push(int num) {
        if (!isFull()) {
            stk[top] = num;
            top++;
        } else cout << "Stack is already Full!" << endl;

    };

    int peek() {
        if (!isEmpty()) return stk[top - 1];
    };

    int numberOfElements() {
        return top;
    };

    ~Stack() {
        for (int i = 0; i < top; i++) {
            stk[i] = -1;
        }
        delete[]stk;
    };

    Stack operator+(const Stack &s) {
        Stack result;
        result.size = size + s.size;
        result.stk = new int[result.size];

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

    int getSize() const;

    void setSize(int size);

    Stack &operator=(const Stack &s) {
        size = s.size;
        top = s.top;
        stk = new int[size];
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

    friend void view_content(Stack s);
};

void view_content(Stack s) {
    int i;
    for (i = 0; i < s.top; i++) {
        cout << i + 1 << ". " << s.stk[i] << endl;
    }
}

int Stack::getSize() const {
    return size;
}

void Stack::setSize(int size) {
    Stack::size = size;
}


int main() {

    Stack s1(7);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    //view_content(s1);
    Stack s2 = s1;
    //view_content(s2);
    Stack s3;
    s3 = s1 + s2;
    cout <<"size : "<< s3.getSize()<<endl;
    view_content(s3);
    cout << s3[2] << endl;
    cout << s3[18] << endl;
    return 0;
}
