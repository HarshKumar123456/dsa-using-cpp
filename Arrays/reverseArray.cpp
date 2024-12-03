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

void reverseAfterSomeElementJump(vector<int> &nums, int jump)
{
    int start = jump;
    int end = nums.size() - 1;

    while (start < end)
    {
        swap(nums[start++], nums[end--]);
    }
}

int main()
{
    seperation();
    vector<int> nums = {1, 5, 2, 6, 3, 7, 9};
    // Reverse array after jumping some elements
    int jump = 4;

    cout << "Before Reverse: ";
    printArray(nums, nums.size());
    lineBreak();
    reverseAfterSomeElementJump(nums, jump);
    cout << "After Reverse: ";
    printArray(nums, nums.size());

    seperation();
    return 0;
}
