#include <iostream>

using namespace std;

class Stack {

    int *stk , top , size;
public:
    Stack(int _size){
        top = 0;
        size = _size;
        stk = new int[size];
    }
    bool isFull(){
        return top == size;
    }

    bool isEmpty(){
        return top == 0;
    }

    int pop(){
        if(!isEmpty()){
            top--;
            return stk[top];
        }
        cout<<"Stack is already Empty!"<<endl;
        return -1;
    }

    void push(int num){
        if(!isFull()){
            stk[top] = num;
            top++;
        }else cout<<"Stack is already Full!"<<endl;

    }

    int peek(){
        if(!isEmpty()) return stk[top-1];
    }

    int numberOfElements(){
        return top;
    }

    ~Stack(){
        delete(stk);
    }
};

int main() {

    Stack s(7);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<s.pop()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.pop()<<endl;

    return 0;
}
