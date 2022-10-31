#include <iostream>

using namespace std;

class Queue {
    int top, *arr, size;

public:
    Queue(int _size) {
        size = _size;
        arr = new int[size];
        top = 0;
    }

    ~Queue() {
        delete (arr);
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

    void enqueue(int num) {
        if (top < size) {
            arr[top++] = num;
            cout << "Enqueued Number " << num << endl;
        } else cout << "Already Full, can't enqueue " << num << endl;
    }

    int dequeue() {
        int dequeuedNum = arr[0];
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

    int peek() {
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


};

int main() {
    Queue q(4);
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
    cout << q.isEmpty() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << "Number of Elements : " << q.getNumberOfElements() << endl;
    cout << "Peek is : " << q.peek() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.isEmpty() << endl;
    return 0;
}
