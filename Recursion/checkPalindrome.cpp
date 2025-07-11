#include <iostream> 
using namespace std;

bool checkPalindrome(string &str, int pointer ) {
	
	int size = str.length() - 1;

	// Base case
	if (pointer > size - pointer) {
		return true;
	}


	// Ek case Solve karo baaki recursion 
	if(str[pointer] != str[size-pointer]){
		return false;
	}
	

	return checkPalindrome(str, pointer + 1);

}


int main() {
	string name; 

	cout << "Enter your name please: ";
	cin >> name;

	if(checkPalindrome(name,0)) {
		cout << "Bhai yo to Palindrome hai." << endl;
	}
	else{
		cout << "Bhai yo to na se Palindrome. " << endl;
	}

	cout << "We have taken TC: O(n) and SC: O(n)" << endl;



	return 0;

}
