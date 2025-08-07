#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> findNextSmallerElementUsingLoops(vector<int> &arr)
{
    // Run a loop for every element and find the smaller element next to it and if not found then assgin -1 to it
    int size = arr.size();
    vector<int> ans(size);

    for (int i = 0; i < size; i++)
    {
        ans[i] = -1;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                ans[i] = arr[j];
                break;
            }
        }
    }

    return ans;
}


vector<int> findPrevSmallerElementUsingLoops(vector<int> &arr)
{
    // Run a loop for every element and find the smaller element next to it and if not found then assgin -1 to it
    int size = arr.size();
    vector<int> ans(size);

    for (int i = 0; i < size; i++)
    {
        ans[i] = -1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
            {
                ans[i] = arr[j];
                break;
            }
        }
    }

    return ans;
}


vector<int> findNextSmallerElementUsingStack(vector<int> &arr)
{

    int size = arr.size();
    vector<int> ans(size);

    stack<int> s;
    s.push(-1);

    for (int i = size-1; i >= 0; i--)
    {
        int curr = arr[i];
        // Pop Until the Smaller Element than the Current Element is not Found
        while (s.empty() == false && curr <= s.top())
        {
            s.pop();
        }
        
        // Element Smaller than current element is found then update in answer array
        ans[i] = s.top();

        // Push the current element to the stack as it maybe next smaller element for any other element in the original array
        s.push(curr);
    }
    

    return ans;
}

vector<int> findPrevSmallerElementUsingStack(vector<int> &arr)
{

    int size = arr.size();
    vector<int> ans(size);

    stack<int> s;
    s.push(-1);

    for (int i = 0; i < size; i++)
    {
        int curr = arr[i];
        // Pop Until the Smaller Element than the Current Element is not Found
        while (s.empty() == false && curr <= s.top())
        {
            s.pop();
        }

        // Element Smaller than current element is found then update in answer array
        ans[i] = s.top();

        // Push the current element to the stack as it maybe next smaller element for any other element in the original array
        s.push(curr);
    }
    

    return ans;
}



void print(vector<int> &arr) {
    for(auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main () {

    vector<int> list = {3,3,1,1};

    cout << "Finding Next and Prev Small Elements with TC: O(n^2) and SC: O(1) : " << endl;
    vector<int> nextSmall = findNextSmallerElementUsingLoops(list);
    vector<int> prevSmall = findPrevSmallerElementUsingLoops(list);
    
    print(nextSmall);
    print(prevSmall);


    cout << endl << endl;

    cout << "Finding Next and Prev Small Elements with TC: O(n) and SC: O(n) : " << endl;
    nextSmall = findNextSmallerElementUsingStack(list);
    prevSmall = findPrevSmallerElementUsingStack(list);

    print(nextSmall);
    print(prevSmall);

    return 0;
}
