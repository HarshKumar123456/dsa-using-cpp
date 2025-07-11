#include <iostream>
#include <vector>
#include <bits/stdc++.h>
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

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    lineBreak();
}

// Approach 1
bool uniqueOccurrences(vector<int> &arr)
{
    vector<int> answer;

    // Sort kiya
    sort(arr.begin(), arr.end(), greater<int>());

    // Count of each number store kiya
    int count = 0, i = 0, value = arr[0];
    while (i < arr.size())
    {
        value = arr[i];
        count = 0;
        while (i < arr.size() && value == arr[i])
        {
            count++;
            i++;
        }

        answer.push_back(count);
    }

    // Sort kiya phir se
    sort(answer.begin(), answer.end(), greater<int>());

    // Agar same number of occurences huin to return false varna return true
    for (int i = 0; i < answer.size() - 1; i++)
    {
        if (answer[i] == answer[i + 1])
        {
            return false;
        }
    }

    return true;
}

// Approach 2: Ye fast hai kyonki sort karne ke liye swap vagairah nahin ho rahe bas traverse kar rahe hain O(n^2) times
bool findIfUniqueNumberOfOccurancesInArray(int arr[], int size)
{
    int isCounted[size] = {0}; // Halanki ye nahin karna chahiye dynamically initialize karna hai to 'new' ka use karna chahiye but it is ok here for small cases of input size of array  
    int countOccurance[size] = {0};
    int count = 0;
    int index = 0;

    for (int i = 0; i < size; i++)
    {
        if (isCounted[i] == 0)
        {
            isCounted[i] = 1; // Is line se ham visited mark kar rahe hain element ko Ki haan bhai ise count kar liya aur ye first occurence of particular element ko visit kar raha hai
            count = 1; // Isse element ki counting start ho gayi ye pata chal raha 

            for (int j = i + 1; j < size; j++) // Is loop se ham baaki bachi hui array mein kitni occurences hain use nikal le rahe  
            {
                if (isCounted[j] == 0 && arr[i] == arr[j]) // Ye condition make sures ki ham do baar counting na kar len ek hi element ki 
                {
                    isCounted[j] = 1; // Ye element ko visited mark karne ke liye jiske count ko ham badha rahe hain 
                    count++; // Ye element under observation ki count ko observe kar raha hai 
                }
            }
            countOccurance[index] = count; // Ye element ke baare mein information store nahin karega just count of element store karega 
            index++; // Ye line make sure ki ham 'countOccurance' array mein har baar nayi entry of count naye index par daalen
        }
    }

    // cout << "Printing Counting Array: ";
    // printArray(countOccurance, index);
    // cout << "Index: " << index << endl;

    fill_n(isCounted, size, 0); // Ye again visited array ko false mark karegi
    // Ye neeche same upar wali cheej kar rahe hain same element ka count nikal rahe hain if more than 1 count mila to return false else traverse more array
    for (int i = 0; i < index; i++)
    {
        if (isCounted[i] == 0)
        {
            isCounted[i] = 1;
            count = 1;

            for (int j = i + 1; j < index; j++)
            {
                if (isCounted[j] == 0 && countOccurance[i] == countOccurance[j])
                {
                    isCounted[j] = 1;
                    return false;
                }
            }
        }
    }

    return true;
}

// Approach 3: Ye O(n) hai but using map
bool unique(vector<int> &arr){
    int size = arr.size();
        unordered_map<int, int> freqMap; // To store element frequencies

        // Step 1: Count occurrences of each element
        for (int i = 0; i < size; i++)
        {
            freqMap[arr[i]]++;
        }

        // Step 2: Check if all occurrence counts are unique
        unordered_set<int> occurrenceSet; // To store unique frequencies
        for (auto it : freqMap)
        {
            if (occurrenceSet.find(it.second) != occurrenceSet.end())
            {
                // Frequency is already present, not unique
                return false;
            }
            occurrenceSet.insert(it.second);
        }

        return true;
}

int main()
{
    int arr[] = {1, 2, 3, 1, 2};
    int size = 5;
    int haveUniqueElementOccurance = findIfUniqueNumberOfOccurancesInArray(arr, size);

    seperation();
    cout << haveUniqueElementOccurance << endl;
    seperation();

    return 0;
}
