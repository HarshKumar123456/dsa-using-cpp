#include <iostream>
#include <vector>
using namespace std;

void seperation()
{
    cout << endl;
    cout << endl;
}

void lineBreak()
{
    cout << endl;
}

void printArray(vector<char> arr)
{
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    lineBreak();
}

void reverseString(vector<char> &array, int start, int end)
{
    cout << "Reversing " << start << " to " << end << endl;
    for (int i = start; i < end + 1; i++)
    {
        cout << array[i] << " ";
    }
    lineBreak();
    while (start < end)
    {
        swap(array[start++], array[end--]);
    }
}

void reverseWordsInSentence(vector<char> &sentence)
{
    vector<char> word = {};
    int wordStartIndex = 0;
    int wordEndIndex = 0;
    int size = sentence.size();
    bool wordFound = false;

    for (int i = 0; i < size; i++)
    {
        // Push Until a word found
        if (sentence[i] == ' ' || sentence[i] == '.')
        {
            // If word is found then reverse it
            wordFound = true;
            wordEndIndex = i - 1;
            cout << "Reversing " << wordStartIndex << " / " << wordEndIndex << endl;
            reverseString(sentence, wordStartIndex, wordEndIndex);
            wordStartIndex = i + 1;
            wordFound = false;
        }
    }
}

int main()
{
    // _________________________
    // Learn about Differences of CHAR Array and STRINGS
    // _________________________
    // char sentence[] = {};
    // string str;
    // cin.getline(str);
    // Learn about cin.getline(str,len) and custom delimeter in it
    // _________________________

    // _________________________

    vector<char> sentence = {'M', 'y', ' ', 'N', 'a', 'm', 'e', ' ', 'i', 's', ' ', 'H', 'a', 'r', 's', 'h', ' ', 'K', 'u', 'm', 'a', 'r', '.'};
    int size = sentence.size();

    printArray(sentence);
    reverseWordsInSentence(sentence);
    printArray(sentence);

    return 0;
}
