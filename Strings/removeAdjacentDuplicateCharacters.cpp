#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string word = "rzacbbcayyzor";
    cout << word << endl;

    
    int pointer = -1;
    while (pointer < word.size() || pointer < 0)
    {
        // Ensures that everytime we start with 0 only chahe start mein pointer -ve ho jaye yaa neeche program flow mein  
        while (pointer <= -1)
        {
            pointer++;
        }

        if (pointer + 1 < word.size() && (word[pointer] == word[pointer + 1]))
        {
            word.erase(word.begin() + pointer);
            word.erase(word.begin() + pointer);

            cout << word << endl;

            pointer--;
            pointer--;
        }

        pointer++;
    }

    cout << word << endl;

    return 0;
}