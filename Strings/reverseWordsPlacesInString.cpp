#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isAlphabetic(char character)
{
    if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z'))
    {
        return true;
    }

    return false;
}

string reverseWords(string s)
{
    // Store all words in a different array of strings
    vector<string> words;
    int sizeOfString = s.size();
    string reverseWordsPlaces = "";

    for (int index = 0; index < sizeOfString; index++)
    {

        char character = s[index];

        if (isAlphabetic(character))
        {
            // This means the word Starts Then store the word
            string word = "";

            while (index < sizeOfString)
            {

                character = s[index];
                if (isAlphabetic(character))
                {
                    cout << "Pushing char  -->" << character << "<--" << endl;
                    word.push_back(character);
                }
                else
                {
                    break;
                }

                index++;
            }

            cout << "Pushing  -->" << word << "<--" << endl;
            words.push_back(word);
        }
        // Here else case means spaces which should be ignored
    }

    // After storing all words now its time to make an string with reversed words' place
    for (int index = words.size() - 1; index >= 0; index--)
    {
        string word = words[index];
        for (char character : word)
        {
            reverseWordsPlaces.push_back(character);
        }
        reverseWordsPlaces.push_back(' ');
    }

    reverseWordsPlaces.pop_back();

    return reverseWordsPlaces;
}

string reverseWordsInPlace(string s)
{
    int sizeOfString = s.size();

    for (int index = 0; index < sizeOfString; index++)
    {
        char character = s[index];

        // Word start keep it
        if (isAlphabetic(character))
        {
            while (index < sizeOfString)
            {
                character = s[index];
                if (isAlphabetic(character) == false)
                {
                    break;
                }

                index++;
            }
        }
        // Spaces Remove them
        else
        {
            s[index] = '@';
        }
    }

    cout << "We have got this:" << s << ":" << endl;
    s.erase(remove(s.begin(), s.end(), '@'), s.end());
    cout << "We have got this:" << s << ":" << endl;

    if (isAlphabetic(s[s.size() - 1]) == false)
    {
        s.pop_back();
    }

    int startWord = 0;
    int endWord = 0;

    sizeOfString = s.size();

    // Reverse The string
    int start = 0;
    int end = sizeOfString - 1;

    while (start < end)
    {
        swap(s[start++], s[end--]);
    }

    // Reverse the words
    while (endWord < sizeOfString)
    {
        if (isAlphabetic(s[startWord]))
        {
            // Word Start store it
            string word = "";
            word.push_back(s[startWord]);

            while (isAlphabetic(s[endWord]) && endWord < sizeOfString)
            {
                word.push_back(s[endWord++]);
            }

            // Now endWord is at space so reverse the word
            int start = startWord;
            int end = endWord - 1;

            while (start < end)
            {
                swap(s[start++], s[end--]);
            }

            startWord = endWord + 1;
            endWord = startWord;
        }
    }

    return s;
}

int main()
{
    string inputString = "        the             sky is           blue";

    string ans = reverseWordsInPlace(inputString);
    cout << endl;
    cout << "We got the ans:" << ans << ":" << endl;

    return 0;
}