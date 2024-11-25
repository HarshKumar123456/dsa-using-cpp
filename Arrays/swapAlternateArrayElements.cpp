#include <iostream>
using namespace std;

void seperation()
{
    cout << endl;
    cout << endl;
}

void lineBreak()
{
    cout << endl;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    lineBreak();
}

void swapAlternateArrayElements(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int temp = arr[i + 1];
        arr[i + 1] = arr[i];
        arr[i] = temp;

        i++;
    }
}

int main()
{
    int even[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int odd[] = {1, 2, 3, 4, 5};

    int evenSize = 10;
    int oddSize = 5;

    cout << "Before: ";
    printArray(even, evenSize);
    swapAlternateArrayElements(even, evenSize);
    cout << "After: ";
    printArray(even, evenSize);

    seperation();

    cout << "Before: ";
    printArray(odd, oddSize);
    swapAlternateArrayElements(odd, oddSize);
    cout << "After: ";
    printArray(odd, oddSize);

    return 0;
}
