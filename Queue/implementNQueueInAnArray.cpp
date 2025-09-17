#include <bits/stdc++.h>
class NQueue
{

    /*
        14 42 10
    1 33 13
    1 22 6
    1 19 13
    1 28 8
    2 13
    1 17 3
    1 50 11
    2 3
    2 11
    1 9 13



        */
private:
    int *nextFreeSpot;
    int *afterThisIndex;
    int *actualArray;

    int *front;
    int *rear;

    int freeSpot;

    int numberOfQueues;
    int sizeOfArray;

public:
    // Initialize your data structure.
    NQueue(int n, int s)
    {
        numberOfQueues = n;
        sizeOfArray = s;

        nextFreeSpot = new int[sizeOfArray];
        afterThisIndex = new int[sizeOfArray];
        actualArray = new int[sizeOfArray];

        front = new int[numberOfQueues];
        rear = new int[numberOfQueues];

        for (int i = 0; i < numberOfQueues; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        for (int j = 0; j < sizeOfArray; j++)
        {
            nextFreeSpot[j] = j + 1;
            afterThisIndex[j] = -1;
            actualArray[j] = -1;
        }
        nextFreeSpot[sizeOfArray - 1] = -1;

        freeSpot = 0;
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m)
    {
        // Queue Not Present Case
        if (m > numberOfQueues)
        {
            return false;
        }

        // Putting Into the Right Queue
        int i = m - 1;

        // Queue Overflow Case
        if (freeSpot == -1)
        {
            return false;
        }

        // Get Index and Push
        int index = freeSpot;
        actualArray[index] = x;

        if (front[i] == -1)
        {
            front[i] = index;
        }

        if (rear[i] != -1)
        {
            afterThisIndex[rear[i]] = index;
        }

        freeSpot = nextFreeSpot[index];
        nextFreeSpot[index] = rear[i];
        rear[i] = index;

        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m)
    {
        // Queue Not Present Case
        if (m > numberOfQueues)
        {
            return -1;
        }

        // Popping from the Right Queue
        int i = m - 1;

        // Queue Underflow Case
        if (front[i] == -1)
        {
            return -1;
        }

        int elementToRemove = actualArray[front[i]];

        actualArray[front[m]] = -1;

        // Last Element Case
        if (front[i] == rear[i])
        {
            rear[i] = -1;
        }

        // Find index of Element After this Element
        int index = afterThisIndex[front[i]];

        if (index != -1)
        {
            nextFreeSpot[index] = nextFreeSpot[front[i]];
        }

        nextFreeSpot[front[i]] = freeSpot;
        freeSpot = front[i];
        afterThisIndex[front[i]] = -1;
        front[i] = index;

        return elementToRemove;
    }
};