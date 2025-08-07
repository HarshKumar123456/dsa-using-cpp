#include <iostream>
#include <stack>
using namespace std;

class TwoStacks
{
private:
    int *arr;
    int size;
    int top1;
    int top2;

public:
    TwoStacks(int size)
    {
        this->size = size;
        arr = new int[size];
        top1 = -1;   // Initially Empty State
        top2 = size; // Initially Empty State
    };

    bool isEmpty()
    {
        return (top1 < top2 - 1);
    };

    bool push(int element, int stackNumber)
    {
        if (isEmpty() == false || (stackNumber < 1 || stackNumber > 2))
        {
            return false;
        }

        if (stackNumber == 1)
        {
            arr[++top1] = element;
        }
        else
        {
            arr[--top2] = element;
        }

        return true;
    };

    bool pop(int stackNumber)
    {
        if (stackNumber < 1 || stackNumber > 2)
        {
            cout << "Pop in 2" << endl;
            return false;
        }

        if (stackNumber == 1 && top1 > -1)
        {
            arr[top1] = -1;
            top1--;
            return true;
        }

        if (stackNumber == 2 && top2 < size)
        {
            arr[top2] = -1;
            top2++;
            return true;
        }

        return false;
    };

    int top(int stackNumber)
    {
        if (stackNumber < 1 || stackNumber > 2)
        {
            return -1;
        }

        if (stackNumber == 1 && top1 >= 0)
        {
            return arr[top1];
        }

        if (stackNumber == 2 && top2 < size)
        {
            return arr[top2];
        }

        return -1;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    TwoStacks s(10);

    cout << endl;

    s.push(1, 1);
    s.push(2, 1);
    bool popped = s.push(10, 2);
    cout << popped << endl;
    s.push(20, 2);
    s.push(30, 2);
    s.push(40, 2);
    s.push(50, 2);
    s.push(60, 2);
    s.push(70, 2);
    s.push(80, 2);

    s.print();

    s.pop(1);
    s.print();

    // s.pop(2);
    // s.pop(2);
    // s.pop(2);
    // s.pop(2);
    // s.pop(2);
    s.pop(2);
    s.pop(2);
    s.pop(2);
    cout << "Popped in 2: " << s.pop(2) << endl;
    cout << "Popped in 1: " << s.pop(1) << endl;
    cout << "Popped in 1: " << s.pop(1) << endl;
    s.print();

    cout << s.top(1) << "  " << s.top(2) << "  " << s.top(0) << endl;
    if (s.isEmpty())
    {
        cout << "Bhai ye to Empty hai. " << endl;
    }
    else
    {
        cout << "Bhai ye to Empty nahin hai. " << endl;
    }

    cout << endl;

    return 0;
}