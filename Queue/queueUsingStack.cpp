#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class queueUsingStack
{
private:
    stack<int> s;
    int capacity;
    int filled;

    void printStack(stack<int> s)
    {
        if (s.empty() == true)
        {
            cout << endl;
            return;
        }

        cout << s.top() << " ";
        s.pop();

        printStack(s);
    }

    void insertAtLastInStack(stack<int> &s, int element) {
        if (s.empty() == true)
        {
            s.push(element);
            return ;
        }
        
        int sideElement = s.top();
        s.pop();

        insertAtLastInStack(s,element);

        s.push(sideElement);
    }

    int findLastElementOfStack(stack<int> s) {
        if (s.empty() == true)
        {
            return -1;
        }

        int lastElement;
        while (s.empty() != true)
        {
            lastElement = s.top();
            s.pop();
        }
        
        return lastElement;
    }

public:
    queueUsingStack(int size)
    {
        this->capacity = size;
        this->filled = 0;
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
            cout << "Queue is empty. " << endl;
            return;
        }

        cout << endl
             << "Printing Queue: " << endl;
        printStack(s);

        cout << "----" << endl;
    }

    int front()
    {
        if (empty() == true)
        {
            return -1;
        }

        return s.top();
    }

    int back() {
        if (empty() == true)
        {
            return -1;
        }

        return findLastElementOfStack(s);
    }

    bool push(int element)
    {
        // If queue is full then return
        if (full() == true)
        {
            cout << "Queue Overflow...." << endl;
            return false;
        }


        cout << "Pushed: " << element << endl;
        insertAtLastInStack(s,element);
        filled++;

        return true;
    }

    bool pop()
    {
        // If stack is empty return false
        if (empty() == true)
        {
            cout << "Queue Underflow...." << endl;
            return false;
        }

        // We have to Pop from back as implementing the stack using queue
        // Pop 1 element by reversing the queue and then again reverse the queue to maintain stack
        cout << "Popped: " << s.top() << endl;
        s.pop();

        filled--;

        return true;
    }

    void swap(queueUsingStack swapFromThis){
        this->capacity = swapFromThis.capacity;
        this->filled = swapFromThis.filled;
        this->s = swapFromThis.s;
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

    queueUsingStack q(5);
    queueUsingStack line(10);

    line.push(1);
    line.push(2);
    line.push(3);
    line.push(4);
    line.push(5);

    line.print();

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    q.print();
    
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    
    q.print();
    
    q.swap(line);

    q.print();

    cout << "Queue size is: " << q.size() << endl;

    cout << "Queue's front is: " << q.front() << " Queue's Back is: " << q.back() << endl;

    if (q.empty())
    {
        cout << "Bhai Queue to Empty hai." << endl;
    }
    else
    {
        cout << "Bhai Queue to Empty nahin hai." << endl;
    }

    cout << endl;
    return 0;
}