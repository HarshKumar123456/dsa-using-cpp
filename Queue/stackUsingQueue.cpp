#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class stackUsingQueue
{
private:
    queue<int> q;
    int capacity;
    int filled;

    void reverse(queue<int> &q)
    {
        if (q.empty() == true)
        {
            return;
        }

        int poppedElement = q.front();
        q.pop();

        reverse(q);

        q.push(poppedElement);
    }

    void printQueue(queue<int> q)
    {
        if (q.empty() == true)
        {
            cout << endl;
            return;
        }

        while (q.empty() != true)
        {
            int poppedElement = q.front();
            q.pop();

            cout << poppedElement << " " << endl;
        }
    }

public:
    stackUsingQueue(int size)
    {
        this->capacity = size;
        filled = 0;
    }

    bool empty()
    {
        return filled == 0 ? true : false;
    }

    bool full()
    {
        if (filled == capacity)
        {
            return true;
        }

        return false;
    }

    void print()
    {
        // If queue is empty then say it is empty
        if (empty() == true)
        {
            cout << "Stack is empty. " << endl;
            return;
        }

        cout << endl << "Printing stack: " << endl;
        printQueue(q);

        cout << "----" << endl;
    }

    int top()
    {
        if (empty() == true)
        {
            return -1;
        }

        return q.front();
    }

    bool push(int element)
    {
        // If queue is full then return
        if (full() == true)
        {
            cout << "Stack Overflow...." << endl;
            return false;
        }

        reverse(q);

        cout << "Pushed: " << element << endl;
        q.push(element);
        filled++;

        reverse(q);


        return true;
    }

    bool pop()
    {
        // If stack is empty return false
        if (empty() == true)
        {
            cout << "Stack Underflow...." << endl;
            return false;
        }

        // We have to Pop from back as implementing the stack using queue
        // Pop 1 element by reversing the queue and then again reverse the queue to maintain stack
        cout << "Popped: " << q.front() << endl;
        q.pop();

        filled--;

        return true;
    }

    int size()
    {
        return capacity;
    }

    int remainingSize()
    {
        return capacity - filled;
    }
};

int main()
{
    cout << endl;
    stackUsingQueue s(4);

    cout << "Stack top is; " << s.top() << endl;


    cout << "Stack remaining size is: " << s.remainingSize() << endl;
    cout << "Stack size is: " << s.size() << endl;
    
    s.push(10);
    s.push(20);


    cout << "Stack remaining size is: " << s.remainingSize() << endl;
    cout << "Stack size is: " << s.size() << endl;

    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    cout << "Stack remaining size is: " << s.remainingSize() << endl;
    cout << "Stack size is: " << s.size() << endl;

    cout << "Stack top is; " << s.top() << endl;
    
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    s.print();

    cout << "Stack remaining size is: " << s.remainingSize() << endl;
    cout << "Stack size is: " << s.size() << endl;
    
    if (s.empty() == true)
    {
        cout << "Bhai Stack to empty hai. " << endl;
    }  
    else{
        cout << "Bhai stack empty nahin hai. " << endl;
    }
    
    
    cout << endl;
    return 0;
}