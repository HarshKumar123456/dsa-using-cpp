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

void printArray(vector<int> arr, int size)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    lineBreak();
}

int binarySearch(vector<int> arr, int start, int end, int target)
{
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {
        if (arr[mid] > target)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }

    return ans;
}

int main()
{
    // vector<int> arr = {2, 7, 1, 0, 2};
    // vector<int> arr = {4, 3, 2, 1};
    // vector<int> arr = {2, 1, 3, 4, 3, 2, 1};
    vector<int> arr = {5, 1, 1}; // Is test case ne sikhaya ki bhai >= ki condition in while loop samajhe !!

    // STEPS TO SOLVE
    // Scan Array from last aur jab tak ascending order mein milte jayen numbers ab tak store elements in a 'temp' array
    // Ascending order breaked at number 'orderBrokenIndex' store that number and find smallest number greater than this no in 'temp'
    // Put that smallest number greater than the number at 'orderBrokenIndex' and then sort the remaining array

    int indexAfterWhichAscendingOrderFromLast = arr.size() - 2;
    while (indexAfterWhichAscendingOrderFromLast >= 0)
    {
        if (arr[indexAfterWhichAscendingOrderFromLast] >= arr[indexAfterWhichAscendingOrderFromLast + 1])
        {
            indexAfterWhichAscendingOrderFromLast--;
        }
        else
        {
            break;
        }
    }

    cout << "Bro We got it index After Which Ascending Order From Last : " << indexAfterWhichAscendingOrderFromLast << endl;
    int start = indexAfterWhichAscendingOrderFromLast + 1;
    int end = arr.size() - 1;

    if (indexAfterWhichAscendingOrderFromLast != -1)
    {
        cout << "Finding jinnIndex start - end " << start << " : " << end << endl;
        int jinnIndex = binarySearch(arr, start, end, arr[indexAfterWhichAscendingOrderFromLast]);
        cout << "Jinn Index is: " << jinnIndex << endl;
        cout << "Found the smallest greater number from the 'indexAfterWhichAscendingOrderFromLast': " << arr[jinnIndex] << endl;
        if (jinnIndex != -1)
        {
            swap(arr[indexAfterWhichAscendingOrderFromLast], arr[jinnIndex]);
        }
    }
    else
    {
        start = 0;
    }

    cout << "Sorting from " << start + 1 << " to " << endl;

    // Ab Kyonki we know that ki from start to end the array is sorted in Descending order and we have to make it Ascending so we can just reverse the array to further reduce time complexity
    // sort(arr.begin() + start, arr.end());
    // or
    // reverse(arr.begin() + start, arr.end());
    // Both of the methods will give same results
    reverse(arr.begin() + start, arr.end());

    printArray(arr, arr.size());

    return 0;
}

/*
1, 2, 3

1 2 3   0 0 0
1 3 2   0 0 1
2 1 3   0 1 0
2 3 1   0 1 1
3 1 2   1 0 0
3 2 1   1 0 1


*/
