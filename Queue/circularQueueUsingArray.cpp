#include <iostream>
using namespace std;

class circularQueueUsingArray
{
private:
    int *arr;
    int capacity;
    int filled;
    int aageWaleElementKaIndex;
    int peechheWaleElementKaIndex;

public:
    circularQueueUsingArray(int size)
    {
        this->capacity = size;
        this->filled = 0;
        this->arr = new int[size];
        this->aageWaleElementKaIndex = -1;
        this->peechheWaleElementKaIndex = -1;
    }

    bool empty()
    {
        return filled == 0 ? true : false;
    }

    bool full()
    {
        // if ( (aageWaleElementKaIndex == 0 && peechheWaleElementKaIndex == capacity - 1) || ( (peechheWaleElementKaIndex + 1) == aageWaleElementKaIndex))

        //  Or This both will work as  (capacity - 1 + 1) % capacity == 0
        if (((peechheWaleElementKaIndex + 1) == aageWaleElementKaIndex))
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

        int count = filled;
        int index = aageWaleElementKaIndex;

        while (count != 0)
        {
            cout << (index % capacity)[arr] << " ";

            index++;
            count--;
        }

        cout << "----" << endl;
    }

    void printArray()
    {
        cout << endl
             << "Printing Array: " << endl;

        for (int i = 0; i < size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int front()
    {
        if (empty() == true)
        {
            return -1;
        }

        return arr[aageWaleElementKaIndex];
    }

    int back()
    {
        if (empty() == true)
        {
            return -1;
        }

        return arr[peechheWaleElementKaIndex];
    }

    bool push(int element)
    {
        // If queue is full then return
        if (full() == true)
        {
            cout << "Queue Overflow...." << endl;
            return false;
        }

        if (aageWaleElementKaIndex == peechheWaleElementKaIndex && aageWaleElementKaIndex == -1)
        {
            aageWaleElementKaIndex++;
        }

        cout << "Pushed: " << element << endl;

        peechheWaleElementKaIndex = (peechheWaleElementKaIndex + 1) % capacity;

        // cout << "At index: " << peechheWaleElementKaIndex << endl;

        arr[peechheWaleElementKaIndex] = element;

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
        cout << "Popped: " << arr[aageWaleElementKaIndex] << endl;
        filled--;

        arr[aageWaleElementKaIndex] = 0;

        aageWaleElementKaIndex = (aageWaleElementKaIndex + 1) % capacity;

        if (aageWaleElementKaIndex == peechheWaleElementKaIndex)
        {
            aageWaleElementKaIndex = -1;
            peechheWaleElementKaIndex = -1;
        }

        return true;
    }

    void swap(circularQueueUsingArray swapFromThis)
    {
        this->capacity = swapFromThis.capacity;
        this->filled = swapFromThis.filled;
        delete[] this->arr;
        this->arr = swapFromThis.arr;
        this->aageWaleElementKaIndex = swapFromThis.aageWaleElementKaIndex;
        this->peechheWaleElementKaIndex = swapFromThis.peechheWaleElementKaIndex;
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

    circularQueueUsingArray q(5);
    circularQueueUsingArray line(5);

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

    q.printArray();
    
    q.push(1);
    cout << "Queue's front is: " << q.front() << " Queue's Back is: " << q.back() << endl;
    cout << "Remaining size is: " << q.remainingSize() << endl;
    q.push(11);
    q.push(111);
    q.push(1111);
    
    q.printArray();
    q.print();

    q.swap(line);
    // line.print();
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