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

void swap(int a, int b)
{
    // This will swap only copied values but we want to swap actual values then use Pass by reference type function calling

    cout << "Before swap : " << a << " " << b << endl;
    a = a + b;
    b = a - b;
    a = a - b;
    cout << "After swap : " << a << " " << b << endl;
}

int sumOfArrayElements(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    // swap(10, 20);
    int list[] = {1, 2, 3, 4};
    cout << "Sum of array elements is: " << sumOfArrayElements(list,4) << endl;

    return 0;
}
