#include <iostream>
using namespace std;

void insertionSort(int *arr, int size, int index)
{
	// Base Case
	if (index >= size)
	{
		return;
	}

	// Ek case solve, Baaki recursion

	// Ab dekho insertion sort mein ke hove
	// element at i-th index is putted on right place in i-th iteration

	int rightIndex = index;
	int temp = arr[index];

	for (int i = index; i >= 0; i--)
	{
		if (temp < arr[i])
		{
			arr[i + 1] = arr[i];
			rightIndex = i;
		}
	}

	arr[rightIndex] = temp;

	insertionSort(arr, size, index + 1);
}

void printArray(int *arr, int size)
{
	// Base case
	if (size <= 0)
	{
		cout << " ....... " << endl;
		return;
	}

	// Ek case solve, Baaki recursion
	cout << arr[0] << " ";

	printArray(arr + 1, size - 1);
}

int main()
{

	int list[] = {5, 7, 74, 34, 10, 1, 4};
	int size = 7;

	cout << "\nArray Before sort: ";
	printArray(list, size);

	insertionSort(list, size, 0);

	cout << "\nArray After sort: ";
	printArray(list, size);

	cout << "We have taken TC: O(n^2) and SC: O(n)" << endl;

	return 0;
}
