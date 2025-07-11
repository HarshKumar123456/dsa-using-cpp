#include <iostream>
#include <vector>
using namespace std;

void solve(string str, vector<string> &permutations, string &output, int size, int index) {
	// Base case
	if(index >= size) {
		permutations.push_back(output);
		return ;	
	}

	// Ek case solve, Baaki recursion
	for (int i=index; i<size; i++) {
		
		swap(str[i], str[index]);
		output.push_back(str[index]);

		solve(str, permutations, output, size, index+1);

		// Backtracking 
		output.pop_back();
		swap(str[i], str[index]);
	}
}



vector<string> permutationsOfString(string str) {
	vector<string> permutations = {};
	string output = "";

	int index = 0;
	int size = str.length();
	
	solve(str, permutations, output, size, index);

	return permutations;
}

void printArray(vector<string> arr) {
	int size = arr.size();

	for ( int i = 0; i < size; i++ ) {
		cout << i <<  ". " << arr[i]  << endl;
	}

}


int main() {
	
	string name; 
	cout << "Please enter name to find permutations: ";
	cin >> name;

	vector<string> ans = permutationsOfString(name);
	printArray(ans);

	cout << "We have taken TC: O(n*n!) and SC: O(n)" << endl;


	return 0;

}

