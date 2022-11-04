#include <iostream>

using namespace std;

template<class type>
class Queue {
    int top, size;
    type *arr;
    static int qNum;
public:
    Queue(int _size) {
        size = _size;
        arr = new type[size];
        top = 0;
        qNum++;
    }

    ~Queue() {
        qNum--;
        delete[]arr;
    }

    bool isFull() {
        if (top == size)
            return true;
        return false;
    }

    bool isEmpty() {
        if (top == 0)
            return true;
        return false;
    }

    void enqueue(type num) {
        if (top < size) {
            arr[top++] = num;
            cout << "Enqueued Number " << num << endl;
        } else cout << "Already Full, can't enqueue " << num << endl;
    }

    type dequeue() {
        type dequeuedNum = arr[0];
        if (!isEmpty()) {
            for (int i = 0; i < top - 1; i++) {
                arr[i] = arr[i + 1];
            }
            top--;
            return dequeuedNum;
        }
        cout << "Queue is already empty!" << endl;
        return -1;
    }

    type peek() {
        if (!isEmpty()) {
            return arr[0];
        } else {
            cout << "There is no Peek, queue is already empty!" << endl;
            return -1;
        }
    }

    int getNumberOfElements() {
        return top;
    }

    static int getqNum() {
        return qNum;
    }
};

template<class type>
int Queue<type>::qNum = 0;

int main() {
    cout << "Int Queue Number = " << Queue<int>::getqNum() << endl;
    Queue<int> q(4);
    cout << "Int Queue Number = " << Queue<int>::getqNum() << endl;
    Queue<int> q2(2);
    cout << "Int Queue Number = " << Queue<int>::getqNum() << endl;
    Queue<char> q3(4);
    cout << "char Queue Number = " << Queue<char>::getqNum() << endl;
    cout << "Int Queue Number = " << Queue<int>::getqNum() << endl;

    cout << q.dequeue() << endl;
    q.enqueue(1);
    q.enqueue(2);
    cout << "Peek is : " << q.peek() << endl;
    q.enqueue(3);
    cout << "Number of Elements : " << q.getNumberOfElements() << endl;
    cout << q.dequeue() << endl;
    q.enqueue(4);
    cout << q.isFull() << endl;
    q.enqueue(5);
    cout << q.isFull() << endl;
    q.enqueue(6);
    cout << "Peek is : " << q.peek() << endl;
    return 0;
}
