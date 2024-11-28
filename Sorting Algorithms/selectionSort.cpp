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

void selectionSort(vector<int> &nums)
{
    int n = nums.size();
    int i = 0;

    while (i < n)
    {
        int minIndex = i;
        int j = i + 1;

        while (j < n)
        {
            if (nums[j] < nums[minIndex])
            {
                minIndex = j;
            }
            j++;
        }
        
        swap(nums[minIndex], nums[i]);
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

    selectionSort(nums);
    cout << "After sorting: ";
    printArray(nums);
    seperation();
    return 0;
}
