#include <iostream>
using namespace std;

void bubbleSort(int* arr, int size) {
	
	// Base Case
	if( size <= 1 ) {
		return ;

	}


	// Ek Case solve baaki recursion sambhal lega
	for(int i = 0; i < size-1; i++ ) {
		if( arr[i] > arr[i+1]) {
			swap( arr[i], arr[i+1] );
		}
	}

	bubbleSort(arr, size - 1);
}


void printArray(int* arr, int size) {
	// Base case
	if(size <= 0) {
		cout << " ....... " << endl;
		return ;
	}

	// Ek case solve, Baaki recursion
	cout << arr[0] << " ";

	printArray(arr + 1, size - 1);
}


int main() {
	int list[] = { 5, 7, 74, 34 , 10, 1, 4 };
	int size = 7;


	cout << "\nArray Before sort: ";
	printArray(list, size);

	bubbleSort(list, size);

	cout << "We have taken TC: O(n^2) and SC: O(n)" << endl;

	cout << "\nArray After sort: ";
        printArray(list, size);


	return 0;
}
