#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int pow(int number, int power)
{
	int ans = 1;
	while (power)
	{
		ans *= number;
		power--;
	}

	return ans;
}


// This takes TC: O(2^n) and SC: O(n)
void solve(string str, vector<string> &ans, string output, int size)
{
	// Base Case
	if (size == 0)
	{
		ans.push_back(output);
		return;
	}

	// Ek case solve, Baaki Recursion
	int temp = size;
	int index = str.length() - 1;
	while (temp != 0)
	{
		if (temp & 1)
		{
			output.push_back(str[index]);
		}
		index = index - 1;
		temp = temp >> 1;
	}

	int start = 0;
	int end = output.length() - 1;
	while (start < end)
	{
		swap(output[start++], output[end--]);
	}

	ans.push_back(output);
	output = "";
	solve(str, ans, output, size - 1);
}

// This takes TC: O(2^n) and SC: O(n)
void uttar(string str, int size, vector<string> &ans, string output, int index) {
	// Base Case
	if(index >= size) {
		ans.push_back( output );
		return ;
	}

	// Include this Index Value
	uttar(str, size, ans, output + str[index], index + 1);

	// Exclude this Index Value
	uttar(str, size, ans, output, index + 1);

}

vector<string> powerSet(string str)
{
	vector<string> ans = {};
	string output = "";
	int len = str.length();
	int size = pow(2, len);

        // solve(str, ans, output, size - 1);
	uttar(str, len, ans, output, 0);

	return ans;
}

void printArray(vector<string> list)
{
	int index = 0;
	for (auto i : list)
	{
		cout << index++ << ". " << i << endl;
	}
	cout << endl;
}

int main()
{
	string name;
	cout << "Please enter the string: ";
	cin >> name;

	vector<string> ans = powerSet(name);
	// sort(ans.begin(), ans.end());
	printArray(ans);
	
	
	return 0;
}
