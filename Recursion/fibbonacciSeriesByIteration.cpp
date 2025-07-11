#include <iostream> 
using namespace std;

int main() {
	int first = 0; 
	int second = 1;
	int third = first + second;

	int nthTerm; 
	cout << "Enter the term you want to see Please: ";
	cin >> nthTerm;

	if ( nthTerm <= 0 ) {
		cout << "Please Enter Valid Term Number." << endl;
	}

	if ( nthTerm == 1 ) {
		cout << first << endl;
	} 
	else if ( nthTerm == 2 ) {
		cout << second << endl;
	} 
	else {
		for (int i = 3; i <= nthTerm; i++){
			third = first + second;
			first = second;
			second = third;
		}

		cout << third << endl;
	}


	cout << "We have taken TC: O(n) and SC: O(1)" << endl;
	

	return 0;
}
