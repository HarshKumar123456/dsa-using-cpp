#include <iostream>
#include <climits>
using namespace std;

void selectionSort(int* arr, int size) {
	// Base Case
	if ( size <= 1 ) {
		return ;
	}

	// Ek case solve, Baaki Recursion
	int minElementIndex = 0;
	
	for(int i = 0; i < size; i++) {
		if ( arr[minElementIndex] > arr[i] ) {
			minElementIndex = i;
		}
	} 

	swap( arr[0], arr[minElementIndex] );
	

	selectionSort( arr + 1, size - 1);
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

        selectionSort(list, size);
		cout << "We have taken TC: O(n^2) and SC: O(n)" << endl;

        cout << "\nArray After sort: ";
        printArray(list, size);


	return 0;
}
