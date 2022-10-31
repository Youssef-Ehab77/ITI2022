#include <iostream>

using namespace std;

class Queue
{
    int head, tail, round, *arr, size;

public:
    Queue(int _size)
    {
        size = _size;
        arr = new int[size];
        tail = 0;
        head = 0;
        round = 0;
    }

    ~Queue()
    {
        delete (arr);
    }

    bool isFull()
    {
        if (round != 0 && tail == head)
            return true;
        return false;
    }

    bool isEmpty()
    {
        if (round == 0 && tail == head)
            return true;
        return false;
    }

    void enqueue(int num)
    {
        if (isFull())
        {
            cout << "Can't enqueue, already full!" << endl;
            return;
        }
        arr[tail] = num;
        cout << "Enqueued " << arr[tail] << endl;
        if (tail == size - 1)
        {
            tail = 0;
            round++;
        }
        else tail++;
    }

    int dequeue()
    {
        if (!isEmpty())
        {
            if (head == size - 1)
            {
                head = 0;
                round--;
                return arr[size - 1];
            }
            else
            {
                head++;
                return arr[head - 1];
            }
        }
        else if(isEmpty())
        {
            cout<<"Already Empty"<<endl;
            return -1;
        }
    }

    int peek()
    {
        if (!isEmpty())
        {
            return arr[head];
        }
    }

    int getNumberOfElements()
    {
        return (tail - head + size * round);
    }


};

int main()
{
    Queue q(4);
    cout<<q.dequeue()<<endl;
    q.enqueue(1);
    q.enqueue(2);
    cout << "Peek is : " << q.peek() << endl;
    q.enqueue(3);
    cout << "Number of ELements : " << q.getNumberOfElements() << endl;
    cout << q.dequeue() << endl;
    q.enqueue(4);
    cout << q.isFull() << endl;
    q.enqueue(5);
    cout << q.isFull() << endl;
    q.enqueue(6);
    cout << "Peek is : " << q.peek() << endl;
    cout<<q.isEmpty()<<endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << "Number of ELements : " << q.getNumberOfElements() << endl;
    cout << "Peek is : " << q.peek() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout<<q.isEmpty()<<endl;
    return 0;
}
