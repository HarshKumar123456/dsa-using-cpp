#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> findNegativeNumberInKSizeWindows(vector<int> list, int windowSize)
{
    vector<int> ans;

    deque<int> negativeNumberIndexes;
    int listSize = list.size();
    
    
    // Process first window because there can be less than window's size elements in the list
    int windowStart = 0;
    int windowEnd = windowSize - 1;
    int index = windowEnd;
    
    for(int i=windowStart; i <= windowEnd; i++) {
        if(list[i] < 0) {
            negativeNumberIndexes.push_back(i);
        }
    }

    while (windowEnd < listSize)
    {
        
        int element = list[index];

        // If Element is negative then push index
        if (element < 0)
        {
            negativeNumberIndexes.push_back(index);
        }


        // Pop while front index is not in window then if there is front then push element at that index else put 0 to its place
        bool negativeNumberInsideWindowFound = false;
        while (negativeNumberIndexes.empty() == false)
        {
            // Extract Front Element
            int frontIndex = negativeNumberIndexes.front();

            // If In Window then keep and break else pop and continue
            if (frontIndex <= windowEnd && frontIndex >= windowStart)
            {
                negativeNumberInsideWindowFound = true;
                break;
            }
            else
            {
                negativeNumberIndexes.pop_front();
            }
        }

        // If negative no. found then push it else push 0
        if (negativeNumberInsideWindowFound == true)
        {
            ans.push_back(list[negativeNumberIndexes.front()]);
        }
        else
        {
            ans.push_back(0);
        }

        // Move forward window by 1
        windowStart++;
        windowEnd++;
        
        index++;
    }

    return ans;
}

int main()
{
    vector<int> list = {1, 2, 3, 4, -4, 10, 2, 5, 7, -2, 0, 8, 1, -1};
    int listSize = list.size();
    int windowSize = 4;

    vector<int> negativeNumbersInKSizeWindow = findNegativeNumberInKSizeWindows(list, windowSize);

    int windowStart = 0;
    int windowEnd = windowSize - 1;

    int windowNumber = 0;
    cout << "For window: " << windowStart << " - " << windowEnd << endl;

    cout << "Elements: ";
    int index = windowStart;
    while (index < listSize && index <= windowEnd)
    {
        cout << list[index] << " ";
        index++;
    }
    cout << endl;

    cout << "Negative No.: " << negativeNumbersInKSizeWindow[windowNumber] << endl
         << endl;

    windowNumber++;
    windowStart++;
    windowEnd++;

    while (windowEnd < listSize)
    {
        cout << "For window: " << windowStart << " - " << windowEnd << endl;

        cout << "Elements: ";
        int index = windowStart;
        while (index < listSize && index <= windowEnd)
        {
            cout << list[index] << " ";
            index++;
        }
        cout << endl;

        cout << "Negative No.: " << negativeNumbersInKSizeWindow[windowNumber] << endl
             << endl;

        windowNumber++;
        windowStart++;
        windowEnd++;
    }

    return 0;
}
