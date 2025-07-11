#include <iostream>
#include <vector>
using namespace std;

void printList(vector<int> &list)
{
    for (auto i : list)
    {
        cout << i << " ";
    }

    cout << endl;
}

bool checkIfInvertedPair(int small, int large)
{
    // If smaller number is greater than the larger then clearly they are putted in inverted form so return true
    return (small <= large) ? false : true;
}

void naiveApproachInversionCount(vector<int> list)
{
    int inversionCount = 0;
    int size = list.size();

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (checkIfInvertedPair(list[i], list[j]))
            {
                inversionCount++;
            }
        }
    }
    cout << "We Calculated it with TC: O(n^2) & SC: O(1)" << endl;
    cout << "Yo Bro! There are " << inversionCount << " pairs of inverted elements." << endl
         << endl;
}

void merge(vector<int> &list, int start, int mid, int end, int &inversionCount)
{
    // cout << "We are in merge " << start << "  " << mid << "  " << end << endl << endl;

    int firstArrayIndex = start;
    int firstArraySize = mid + 1;

    int secondArrayIndex = mid + 1;
    int secondArraySize = end + 1;

    int finalArrayIndex = start;

    while (firstArrayIndex < firstArraySize && secondArrayIndex < secondArraySize)
    {
        // cout << "We are in while loop" << endl;
        if (list[firstArrayIndex] <= list[secondArrayIndex])
        {
            // Valid Case: Isi order mein hona chahiye to simple merge
            list[finalArrayIndex++] = list[firstArrayIndex++];
        }
        else
        {
            // cout << "Invalid Case: " << inversionCount << endl;
            // Invalid Case: Is order mein nahin hona chahiye to update Inversion Count like if agar ye wala element bada hai to iske baad wale element bhi bade honge to update inversion count by remaining element + 1
            int remainingElementsInFirstArray = firstArraySize - firstArrayIndex;
            inversionCount += remainingElementsInFirstArray;

            // cout << "Invalid Case after update: " << inversionCount << endl;

            int temp = list[secondArrayIndex];

            // Since We are working in the same array so we have to shift by 1 in order to insert the second array element into final array
            for (int i = secondArrayIndex - 1; i >= firstArrayIndex; i--)
            {
                list[i + 1] = list[i];
            }

            secondArrayIndex++;
            firstArrayIndex++;
            firstArraySize++;

            list[finalArrayIndex++] = temp;
        }
    }

    while (firstArrayIndex < firstArraySize)
    {

        list[finalArrayIndex++] = list[firstArrayIndex++];
    }

    while (secondArrayIndex < secondArraySize)
    {

        list[finalArrayIndex++] = list[secondArrayIndex++];
    }
}

void mergeSort(vector<int> &list, int start, int end, int &inversionCount)
{
    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;
    mergeSort(list, start, mid, inversionCount);
    mergeSort(list, mid + 1, end, inversionCount);
    merge(list, start, mid, end, inversionCount);
}

void optimisedApproachUsingMergeSortInversionCount(vector<int> &list)
{
    int inversionCount = 0;

    cout << "List Before Sorting: ";
    printList(list);

    mergeSort(list, 0, list.size() - 1, inversionCount);

    cout << "List After Sorting: ";
    printList(list);

    cout << "We have taken the TC: O( n*log(n) )  &  SC: O(n*log (n) )" << endl;
    cout << "Yo Bro! There are " << inversionCount << " pairs of inverted elements." << endl
         << endl;
}

int main()
{

    vector<int> list = {3, 5, 1, 10, 9, 2, 6, 8};

    cout << endl
         << endl;

    naiveApproachInversionCount(list);
    optimisedApproachUsingMergeSortInversionCount(list);

    cout << endl
         << endl;

    return 0;
}