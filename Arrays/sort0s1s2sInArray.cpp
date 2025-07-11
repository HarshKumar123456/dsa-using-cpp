#include <iostream>
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


// Approach 1: TLE maaregi kyonki while loops ka sahi istemaal nahin kiya isliye end mein ek condition ko seperately handle karna pada and bahut verbose code hai aur redundant type of swaps and and pointer updation operations hain jo ise slow kar rahe hain however chal jayega but it is not the good way
void sort0s1s2sInArray(int arr[], int size)
{
    int zeroPointer = 0;
    int onePointer = zeroPointer + 1;
    int twoPointer = size - 1;


    while (onePointer < twoPointer)
    {
        // Case 1: 0 - 0
        // Case 2: 0 - 1
        // Case 3: 0 - 2
        while (zeroPointer < twoPointer && arr[zeroPointer] == 0)
        {
            zeroPointer++;
            onePointer = zeroPointer + 1;
        }

        // Jab tak onePointer par 1 hai update
        while (onePointer < twoPointer && arr[onePointer] == 1)
        {
            onePointer++;
        }

        // Case 6: 1 - 2
        // Case 9: 2 - 2
        while (zeroPointer < twoPointer && arr[twoPointer] == 2)
        {
            twoPointer--;
        }

        // Case 7: 2 - 0
        if (zeroPointer < twoPointer && arr[zeroPointer] == 2 && arr[twoPointer] == 0)
        {
            swap(arr[zeroPointer], arr[twoPointer]);
            zeroPointer++;
            onePointer = zeroPointer + 1;
            twoPointer--;
        }
        // Case 8: 2 - 1
        else if (zeroPointer < twoPointer && arr[zeroPointer] == 2 && arr[twoPointer] == 1)
        {
            swap(arr[twoPointer], arr[zeroPointer]);
            twoPointer--;
        }
        // Case 4: 1 - 0
        else if (zeroPointer < twoPointer && arr[zeroPointer] == 1 && arr[twoPointer] == 0)
        {
            swap(arr[zeroPointer], arr[twoPointer]);
            zeroPointer++;
            onePointer = zeroPointer + 1;
        }
        // Case 5: 1 - 1
        else if (arr[zeroPointer] == 1 && arr[twoPointer] == 1 && onePointer < twoPointer)
        {
            if (arr[onePointer] == 0)
            {
                swap(arr[zeroPointer], arr[onePointer]);
                zeroPointer++;
                onePointer = zeroPointer + 1;
            }
            else
            {
                swap(arr[twoPointer], arr[onePointer]);
                twoPointer--;
            }
        }
        // printArray(arr, size);
    }

    if (onePointer == twoPointer)
    {
        if (arr[zeroPointer] == 1 && arr[onePointer] == 0)
        {
            swap(arr[zeroPointer], arr[onePointer]);
            return;
        }
        else if (arr[zeroPointer] == 2 && arr[onePointer] == 1)
        {
            swap(arr[zeroPointer], arr[onePointer]);
            return;
        }
        else if (arr[zeroPointer] == 2 && arr[onePointer] == 0)
        {
            swap(arr[zeroPointer], arr[onePointer]);
            return;
        }
    }
}

void sort0s1s2sInArrayOptimized(int arr[], int size){
    int zeroPointer = 0;
    int twoPointer = size - 1;
    int onePointer = 0;

    // Is wali approach mein basically onePointer hi aage badh raha hai and it is making sure that he traverse the new element and send it to its correct place by updating the zeroPointer and twoPointer 
    while (onePointer <= twoPointer)
    {   
        if (arr[onePointer] == 0)
        {
            swap(arr[zeroPointer], arr[onePointer]);
            zeroPointer++;
            onePointer++;
        }
        else if(arr[onePointer] == 1){
            onePointer++;
        }
        else{
            swap(arr[twoPointer], arr[onePointer]);
            twoPointer--;
        }
        
    }
    

}

int main()
{
    seperation();
    int list[] = {0, 1, 2, 1, 1, 0, 0, 2, 2, 1, 2, 1, 2, 1, 2, 0};
    // int list[] = {2, 0, 1}; 
    // int list[] = {1, 0};
    // int list[] = {1, 2, 0};
    // int list[] = {1, 1, 0};
    // int list[] = {1, 1, 1};
    // int list[] = {2,2};
    // int list[] = {2};
    // int list[] = {1};
    // int list[] = {0};
    int size = sizeof(list) / sizeof(list[0]);

    cout << "Before sort 0s 1s 2s: ";
    printArray(list, size);
    lineBreak();

    sort0s1s2sInArrayOptimized(list, size);

    cout << "After sort 0s 1s 2s: ";
    printArray(list, size);
    lineBreak();

    seperation();

    return 0;
}
