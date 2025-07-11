#include <iostream>
#include <vector>
using namespace std;

void solveUsingBacktracking(string digits, vector<string> &ans, vector<string> mapping, string output, int index)
{
	// Base Case
	if (index >= digits.length())
	{
		ans.push_back(output);
		return;
	}

	int number = digits[index] - '0';
	string value = mapping[number];

	for (int i = 0; i < value.length(); i++)
	{
		output.push_back(value[i]);
		solveUsingBacktracking(digits, ans, mapping, output, index + 1);
		output.pop_back();
	}
}

vector<string> keypadCombinations(string digits)
{
	vector<string> ans = {};
	vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

	string output = "";

	if (digits.length() == 0)
	{
		return ans;
	}

	int index = 0;
	solveUsingBacktracking(digits, ans, mapping, output, index);
	cout << "k is average number of letters per digit like in this case it is approx. 3.25" << endl;
	cout << "We have taken TC: O(k^n) and SC: O(n)" << endl;


	return ans;
}

void solveWithoutUsingBacktracking(string digits, vector<string> &ans, vector<string> mapping, string output, int index)
{
	// Base Case
	if (index >= digits.length())
	{
		ans.push_back(output);
		return;
	}

	int number = digits[index] - '0';
	string value = mapping[number];

	for (int i = 0; i < value.length(); i++)
	{
		string newOutput = "";
		newOutput.push_back(value[i]);
		solveWithoutUsingBacktracking(digits, ans, mapping, output + newOutput, index + 1);
	}
}

vector<string> possibleCombinations(string digits)
{
	vector<string> ans = {};
	vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

	string output = "";

	if (digits.length() == 0)
	{
		return ans;
	}

	int index = 0;
	solveWithoutUsingBacktracking(digits, ans, mapping, output, index);
	cout << "k is average number of letters per digit like in this case it is approx. 3.25" << endl;
	cout << "We have taken TC: O(k^n) and SC: O(n)" << endl;

	return ans;
}

void printArray(vector<string> list)
{
	for (auto i : list)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	//	https://www.youtube.com/watch?v=tWnHbSHwNmA&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA
	string digits;
	cout << "Please enter the digits: ";
	cin >> digits;

	cout << "With Backtracking we get: ";
	vector<string> ans1 = keypadCombinations(digits);
	printArray(ans1);

	cout << "Without Backtracking we get: ";
	vector<string> ans2 = possibleCombinations(digits);
	printArray(ans2);

	bool equal = true;
	for (int i = 0; i < ans1.size(); i++)
	{
		if (ans1[i] != ans2[i])
		{
			equal = false;
			break;
		}
	}

	cout << equal << endl;

	return 0;
}
