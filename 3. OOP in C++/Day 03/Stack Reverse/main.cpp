#include <iostream>

using namespace std;

class Stack {

    int *stk, top, size;
public:
    Stack(Stack &s) {
        top = s.top;
        size = s.size;
        stk = new int[size];
        for (int i = 0; i < top; i++) {
            stk[i] = s.stk[i];
        }
        cout<<"copy ctor : "<<endl;
        cout<<s.stk[0]<<endl;
        cout<<s.stk[1]<<endl;
        cout<<s.stk[2]<<endl;
    };

    Stack(int _size) {
        top = 0;
        size = _size;
        stk = new int[size];
    };

    Stack reverse() {
        Stack r(size);
        for (int i = 0; i < top; i++) {
            r.push(stk[top-i-1]);

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

        delete []stk;
    };

    friend void view_content(Stack s);
};

void view_content(Stack s){
    int i;
    for(i = 0 ; i <s.top; i++){
        cout<<i+1<<". "<<s.stk[i]<<endl;
    }
}


int main() {

    Stack s1(7);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    cout<< "s1 pop: "<<s1.reverse().pop()<<endl;
    cout<< "s1 pop: "<<s1.reverse().pop()<<endl;
    view_content(s1);


    return 0;
}
