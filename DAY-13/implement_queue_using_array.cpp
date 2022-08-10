#include <bits/stdc++.h>
using namespace std;



class Queue
{
public:
    int *arr;
    int start, end, currSize, maxSize;

public:
    Queue()
    {
        arr = new int[19];
        start = -1;
        end = -1;
        currSize = 0;
    }

    Queue(int maxSize)
    {
        this->maxSize = maxSize;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }

    void push(int newElement)
    {
        if (currSize == maxSize)
        {
            cout << "Queue is Full!!!!!!!!" << endl;
            exit(1);
        }

        if (end == -1)
        {
            start = 0;
            end = 0;
        }
        else
            end = (end + 1) % maxSize;

        arr[end] = newElement;
        cout << "Element is pushed " << newElement << endl;
        currSize++;
    }

    int pop()
    {
        if (start == -1)
        {
            cout << "Queue is empty" << endl;
        }

        int popped = arr[start];
        if (currSize == 1)
        {
            start = -1;
            end = -1;
        }
        else
        {
            start = (start + 1) % maxSize;
        }
        return popped;
    }

    int top()
    {
        if (start == -1)
        {
            cout << "Queue is Empty" << endl;
            exit(1);
        }

        return arr[start];
    }

    int size()
    {
        return currSize;
    }
};

int main()
{

    Queue q(6);
    q.push(10);
    q.push(20);
    q.push(100);
    // cout<<q.top()<<endl;
    // q.pop();
    // q.push(499);
    cout<<q.size()<<endl;
}