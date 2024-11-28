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

void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    lineBreak();
}

void bubbleSort(vector<int> &nums)
{
    int n = nums.size();
    int i = 0;
    bool isSwapped = false; // Ye optimisation ke liye daala hai taaki Best case mein bahar aa jayen kyonki swap to ek bhi huye nahin

    while (i < n)
    {
        int j = 0;

        while (j < n - i - 1)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j + 1], nums[j]); // Ise Sliding Window ki tarah bhi dekh sakte hain
                isSwapped = true;
            }
            j++;
        }

        if (isSwapped == false)
        {
            break; // Agar sorted wala scene ho to mast vaapas chale jayenge
        }

        i++;
    }
}

int main()
{
    seperation();
    vector<int> nums = {2, 4, 1, 6, 8, 2, 6, 3, 8, 10};
    cout << "Before sorting: ";
    printArray(nums);
    lineBreak();

    bubbleSort(nums);
    cout << "After sorting: ";
    printArray(nums);
    seperation();
    return 0;
}
