#include <iostream>
#include <string>
using namespace std;

void lineBreak()
{
	cout << endl;
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i])
		{
			char ch = 'a' + i;
			cout << ch << " ";
			continue;
		}

		cout << arr[i] << " ";
	}
	lineBreak();
}

int permutationPresentInString(string searchSpace, string searchString)
{
	// Return -1 if searchString is bigger than searchSpace
	int lengthOfSearchString = searchString.length();
	int lengthOfSearchSpace = searchSpace.length();

	if (lengthOfSearchSpace < lengthOfSearchString)
	{
		return -1;
	}

	// cout << "Bro length nikali " << lengthOfSearchString << " -- " << lengthOfSearchSpace << endl;

	int window[26] = {0};
	int searchStringCharactersCount[26] = {0};

	// Run the loop for the first time of window and searchStringCharactersCount filling
	int index = -1;
	for (int i = 0; i < lengthOfSearchString; i++)
	{
		index = searchString[i] - 'a';
		// cout << "for i = " << i << " index = " << index ;
		searchStringCharactersCount[index]++;

		index = searchSpace[i] - 'a';
		// cout << "for i = " << i << " index = " << index ;
		// lineBreak();
		window[index]++;
	}

	// cout << "Printing windows " << endl;
	// printArray(window, 26);
	// printArray(searchStringCharactersCount, 26);

	for (int i = lengthOfSearchString; i < lengthOfSearchSpace; i++)
	{
		// Compare the window and searchStringCharactersCount if equal then return i as an indicator that permutation starts from this index
		for (int j = 0; j < 26; j++)
		{
			if (window[j] != searchStringCharactersCount[j])
			{
				break;
			}
			else if (j == 25)
			{ // This condition will be checked if characters at j are equal that signifies that we are at end and there is permuatation so return i - lengthOfSearchString from where permutation starts
				return i - lengthOfSearchString;
			}
		}

		// Update window
		// cout << "For i= " << i << endl;
		index = searchSpace[i - lengthOfSearchString] - 'a';
		window[index]--;

		index = searchSpace[i] - 'a';
		window[index]++;

		// cout << "Printing windows after update " << endl;
		// printArray(window, 26);
	}

	return -1;
}

int main()
{
	string s = "mainhoonekudtarobodoraemon";
	string p = "hono";
	string k = "duk";

	cout << permutationPresentInString(s, p) << " @ " << permutationPresentInString(s, k) << endl;

	return 0;
}
