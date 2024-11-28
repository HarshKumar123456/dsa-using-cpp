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

void insertionSort(vector<int> &nums)
{
    int n = nums.size();
    int i = 1; // Pahla element to sorted hi maan kar chal rahe hain isliye doosre se start kiya hai kyonki cards uthate vakt bhi to yahi karte hain pahla card to mast utha lo sorted maan kar phir jaise jaise cards aate jayen vaise vaise mast uthate jao aur sort karke lagate jao

    while (i < n)
    {
        int temp = nums[i]; // Ab kyonki shifting karni hogi kyonki naya element daalna hai isliye ise 'temp' mein store kar lete hain
        int j = i - 1;      // Kyonki iske pahle wale elements se compare karna hai

        while (j >= 0) // Kyonki last element tak hi to compare karoge bhai at max kya hoga pahli position par lagana hoga isliye yahan tak chalaya
        {
            if (nums[j] > temp)
            {
                nums[j + 1] = nums[j]; // Ek place aage shift kar diya
            }
            else
            {
                break;
            }
            j++;
        }
        nums[j + 1] = temp; // Ab hamne shift to kar hi diya jitne elements ko karna tha ab 'j' us element ko point kar raha hoga jise swap nahin karna hai iska matlab uske baad ka element uske baad shift kar diya hoga isliye 'j+1' par daal do 'temp' mein jo store kar rakha hoga
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

    insertionSort(nums);
    cout << "After sorting: ";
    printArray(nums);
    seperation();
    return 0;
}
