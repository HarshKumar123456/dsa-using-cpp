#include <iostream>
#include <vector>

using namespace std;

bool isSortedArray(int *arr, int size)
{
    if (size <= 1)
    {
        return true;
    }

    // Bhai check karo aage ka array sorted hai yaa nahin
    if (isSortedArray(arr + 1, size - 1))
    {
        if (arr[0] <= arr[1])
        {
            return true;
        }
        return false;
    }

    // Agar aage se kuchh sorted nahin hai to mast kyon check karen aage
    return false;
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int size = 4;

    if (isSortedArray(arr, size))
    {
        cout << "Bhai array sorted hai. " << endl;
    }
    else
    {
        cout << "Bhai array sorted nahin hai. " << endl;
    }

	cout << "We have taken TC: O(n) and SC: O(n)" << endl;


    return 0;
}