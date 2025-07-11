#include <iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
	int mid = s + (e - s) / 2;

	int firstPointer, secondPointer, mainArrayIndex;
	firstPointer = s;
	secondPointer = mid + 1;

	mainArrayIndex = s;

	while (firstPointer < mid + 1 && secondPointer < e + 1)
	{
		if (arr[firstPointer] <= arr[secondPointer])
		{
			// Kyonki First Pointer Sync mein hai Main Array Ke Index se aur it doesn't cause data loss to simply increase
			arr[mainArrayIndex++] = arr[firstPointer++];
		}
		else
		{
			// Kyonki Agar Hamne Simply Upar ki tarah kaam kiya to data at First Pointer will lost thus shift by 1
			// increase First part array representing size by 1 then put value of temp at main array index
			// aur apna second part array to end tak hi had se had chalega

			int temp = arr[secondPointer];
			for (int i = secondPointer - 1; i >= mainArrayIndex; i--)
			{
				arr[i + 1] = arr[i];
			}

			arr[mainArrayIndex++] = temp;
			secondPointer++;
			mid++;
			firstPointer++;
		}
	}

	while (firstPointer < mid + 1)
	{
		arr[mainArrayIndex++] = arr[firstPointer++];
	}

	while (secondPointer < e + 1)
	{
		arr[mainArrayIndex++] = arr[secondPointer++];
	}
}

void mergeSort(int *arr, int s, int e)
{
	// Base Case
	if (s >= e)
	{
		return;
	}

	// Ek case solve, Baaki Recursion
	int mid = s + (e - s) / 2;

	mergeSort(arr, s, mid);
	mergeSort(arr, mid + 1, e);

	merge(arr, s, e);
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

	int size;
	cout << "Please Enter size of array: ";
	cin >> size;

	int *list = new int[size];
	cout << "Please enter " << size << " elements: ";

	for (int i = 0; i < size; i++)
	{
		cin >> list[i];
	}

	cout << "\nArray Before sort: ";
	printArray(list, size);

	mergeSort(list, 0, size - 1);

	cout << "\nArray After sort: ";
	printArray(list, size);

	delete[] list;


	cout << "We have taken TC: O( n*log (n) ) and SC: O( log (n) )" << endl;


	return 0;
}
