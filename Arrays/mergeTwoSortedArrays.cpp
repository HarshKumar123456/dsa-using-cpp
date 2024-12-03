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

void printArray(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    lineBreak();
}

void shiftByFromPlace(vector<int> &nums, int from, int shiftBy)
{
    int size = nums.size();

    cout << "Shifting by " << shiftBy << " Places : ";
    printArray(nums, size);

    for (int i = size - shiftBy - 1; i >= 0 + from; i--)
    {
        nums[i + shiftBy] = nums[i];
    }

    cout << "Shifted from " << from << " Place : ";
    printArray(nums, size);
}

void mergeTwoSortedArrays(vector<int> &first, vector<int> &second)
{
    int n = first.size();
    int m = second.size();

    printArray(first, n);
    cout << n << " - " << m << endl;

    int i = 0;
    int j = 0;

    int k = 0; // Halanki teesri array hai nahin but assuming that ki teesri array ke index ko track kar lo isse
    while (i < n && j < m)
    {
        if (first[i] < second[j])
        {
            cout << "Before i and j are: " << i << "  " << j << endl;
            printArray(first, n);
            first[k++] = first[i++];
            cout << "After i and j are: " << i << "  " << j << endl;
            printArray(first, n);
        }
        else
        {
            // Shift every element by one place then insert
            // Vaise ye thoda thoda insertion sort se resemble kar raha hai haina
            // Another approach is question ko solve karne ki ye ho sakti hai ki ham second array ki size tak shift kar len first array ke elements ko and then merge two sorted arrays ka concept use kar len
            shiftByFromPlace(first, i, 1);
            i++;
            cout << "-  Before i and j are: " << i << "  " << j << endl;
            printArray(first, n);
            first[k++] = second[j++];
            cout << "-  After i and j are: " << i << "  " << j << endl;
            printArray(first, n);
        }
    }

    k = n - (m - j);
    cout << "Now k is at: " << k << endl;
    while (j < m)
    {
        first[k++] = second[j++];
    }
}

int main()
{
    seperation();
    // vector<int> first = {1, 3, 5, 7, 8, 10, 0, 0, 0, 0, 0, 0, 0};
    // vector<int> second = {2, 4, 6, 9, 11, 12, 13};
    vector<int> first = {1, 3, 5, 0, 0, 0};
    vector<int> second = {2, 4, 6};

    cout << "Before Merge: ";
    printArray(first, first.size());
    lineBreak();

    mergeTwoSortedArrays(first, second);

    cout << "After Merge: ";
    printArray(first, first.size());

    seperation();
    return 0;
}
