#include <iostream>
using namespace std;

void reverseString(string &str, int pointer) {
	cout << str << endl;
	int size = str.length() - 1;

	if(pointer > size - pointer) {
		return ;
	} 
	

	swap(str[pointer] , str[size-pointer] );

	pointer++;

	reverseString(str, pointer);
}


int main() {
	string name;
	cout << "Enter your name please: ";
	cin >> name;

	cout << "Reversing your name...." << endl;
	cout << "We have taken TC: O(n) and SC: O(n)" << endl;
	
	reverseString(name,0);
	cout << name << endl;
	return 0;
}
