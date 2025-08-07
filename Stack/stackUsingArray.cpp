#include <iostream>
#include <vector>
using namespace std;

class Stack
{
private:
    int *list;
    int peek;

public:
    int capacity;

    Stack(int capacity)
    {
        this->capacity = capacity;
        this->peek = -1;
        list = new int[capacity];
        cout << "Stack is Created of Capacity: " << capacity << endl;
    }

    bool empty()
    {
        if (peek < 0)
        {
            return true;
        }

        return false;
    }

    bool full()
    {
        if (peek == capacity - 1)
        {
            return true;
        }

        return false;
    }

    void print()
    {

        // Case 1: When Stack Is Empty
        if (empty())
        {
            cout << "Bhai Stack Is Empty. " << endl;
            return;
        }

        // Case 2: When Stack is Not Empty
        int temp = peek - 1;
        cout << list[peek] << " <- Top" << endl;
        while (temp != -1)
        {
            cout << list[temp] << endl;
            temp--;
        }
    }

    int top()
    {

        // Case 1: When Stack Is Empty
        if (empty())
        {
            cout << "Bhai Stack Is Empty. " << endl;
            return -1;
        }

        // Case 2: When Stack is Not Empty
        return list[peek];
    }

    bool push(int element)
    {

        // Case 1: When Stack Is Full
        if (full())
        {
            cout << "Bhai Stack Overflow. " << endl;
            return false;
        }

        // Case 2: When Stack Is Not Full
        list[++peek] = element;

        return true;
    }

    bool pop()
    {

        // Case 1: When Stack Is Empty
        if (empty())
        {
            cout << "Bhai Stack Underflow. " << endl;
            return false;
        }

        // Case 2: When Stack is Not Empty
        peek--;
        return true;
    }

    int size()
    {
        return peek + 1;
    }

    int remainingSpace()
    {
        if (empty())
        {
            return capacity;
        }

        return capacity - peek - 1;
    }
};

int main()
{
    Stack numbers(10);
    cout << endl;

    cout << "Remaining Space in Stack: " << numbers.remainingSpace() << endl;

    if (numbers.empty())
    {
        cout << "Bhai Stack Empty hai. " << endl;
    }
    else
    {
        cout << "Bhai Stack Empty nahin hai. " << endl;
    }

    cout << endl;

    numbers.push(10);
    numbers.push(20);
    numbers.push(30);
    numbers.push(40);

    cout << "Top of the Stack: " << numbers.top() << endl;

    cout << endl
         << "Size of Stack is: " << numbers.size() << endl;

    numbers.pop();
    numbers.pop();
    numbers.pop();

    numbers.print();
    // Saare Elements ko pop karke top access karoge to Segmentation Fault aayega
    // numbers.pop();

    cout << "Top of the Stack: " << numbers.top() << endl;

    if (numbers.empty())
    {
        cout << "Bhai Stack Empty hai. " << endl;
    }
    else
    {
        cout << "Bhai Stack Empty nahin hai. " << endl;
    }

    cout << endl
         << "Size of Stack is: " << numbers.size() << endl;

    cout << "Remaining SPace in STack is: " << numbers.remainingSpace() << endl;

    numbers.pop();
    cout << "Remaining SPace in STack is: " << numbers.remainingSpace() << endl;

    return 0;
}