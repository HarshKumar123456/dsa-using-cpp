#include <iostream>
#include <vector>
#include <queue>
using namespace std;

string findNonRepeatingCharOutputUsingMapAndLoop(string charStream)
{
    int count[26]  = {0};
    string ans = "";
    
    for(auto character : charStream) {
        // Update The Count Of Character in Map
        int indexInMap = character - 'a';
        count[indexInMap] = count[indexInMap] + 1;
        
        // cout << "Update count: " << character << " at " << indexInMap << " where now is " << count[indexInMap] << endl;
        // Find Non-Repeating Character from Map
        int indexOfNonRepeatingCharacter = -1;
        for (int i = 0; i < 26; i++)
        {
            if (count[i] == 1)
            {
                indexOfNonRepeatingCharacter = i;
                // for (int j = 0; j < 26; j++)
                // {
                //     cout << count[j] << " ";
                // }
                // cout << endl;
                
                break;
            }   
        }

        // If Count equal to 1 character found then append in string else append '#' in string 

        if (indexOfNonRepeatingCharacter != -1)
        {
            char characterAtIndex = 'a' + indexOfNonRepeatingCharacter;
            ans.push_back(characterAtIndex);
        }
        else
        {
            ans.push_back('#');
        }
        
    }

    return ans;

}


string findNonRepeatingCharOutputUsingDoublyEndedQueue(string charStream) {
    string ans = "";
    int count[26] = {0};

    deque<char> dq;

    // For Every Character Follow Steps below
    for(auto character : charStream) {
        // Update The Count Of Character in Map
        int indexInMap = character - 'a';
        count[indexInMap] = count[indexInMap] + 1;

        // If Count is greater than 1 then don't insert into Doubly Ended Queue
        if (count[indexInMap] == 1)
        {
            dq.push_back(character);
        }
        

        // Find the Non Repeating Character by popping until the doubly ended queue is Empty or we found a character with count equal to 1
        bool foundNonRepeatingCharacter = false;
        char frontCharacter = ' ';
        int frontCharacterInMap = -1;

        while (dq.empty() && foundNonRepeatingCharacter == false)
        {
            frontCharacter = dq.front();
            frontCharacterInMap = frontCharacter - 'a';

            if (count[frontCharacterInMap] > 1)
            {
                dq.pop_front();
            }
            
            if (count[frontCharacterInMap] == 1)
            {
                foundNonRepeatingCharacter = true;
            } 
        }
        
        // If found Non Repeating Character then push else push '#'
        if (foundNonRepeatingCharacter == true)
        {
            ans.push_back(character);
        }
        else{
            ans.push_back('#');
        }
        
    }

    return ans;
}


int main()
{
    int testCases;
    cout << "Enter No. of Test Cases: ";
    cin >> testCases;

    vector<string> charStreams(testCases, "");

    cout << "Enter " << testCases << " Streams: " << endl;
    for (int i = 0; i < testCases; i++)
    {
        cin >> charStreams[i];
    }

    cout << "Non repeating char output for streams: " << endl;

    for (int i = 0; i < testCases; i++)
    {
        cout << "For _" << charStreams[i] << "_ -> " << findNonRepeatingCharOutputUsingMapAndLoop(charStreams[i]) << endl;
    }

    return 0;
}

//  5
// ab
// abc
// acjba    
// aabbcdefgfhde
// abcabc