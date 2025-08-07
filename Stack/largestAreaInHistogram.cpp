#include <iostream>
#include <stack>
#include <vector>
using namespace std;



vector<int> findNextSmallerElementUsingStack(vector<int> &arr)
{

    int size = arr.size();
    vector<int> ans(size);
    
    stack<int> s;
    s.push(-1);
    
    for (int i = size-1; i >= 0; i--)
    {
        int curr = arr[i];
        // cout << endl << "Extra-Ordinary Fantastic Mind Blowing sir: " << i << " arr[i]: " << arr[i]  << endl;
        // Pop Until the Smaller Element than the Current Element is not Found
        while (s.empty() == false && s.top() != -1 && curr <= arr[s.top()])
        {
            // cout << "Top top: " << arr[s.top()] << endl;
            // cout << "Pop Pop" << endl;
            s.pop();
        }
        
        // Element Smaller than current element is found then update in answer array
        ans[i] = s.top();

        // Push the current element to the stack as it maybe next smaller element for any other element in the original array
        s.push(i);
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
        while (s.empty() == false && s.top() != -1  && curr <= arr[s.top()])
        {
            s.pop();
        }

        // Element Smaller than current element is found then update in answer array
        ans[i] = s.top();

        // Push the current element to the stack as it maybe next smaller element for any other element in the original array
        s.push(i);
    }
    

    return ans;
}

void print(vector<int> &arr) {
    for(auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
}


int findLargestAreaInHistogramUsingLoops(vector<int> &histogram) {
    int maxArea = -1;
    int size = histogram.size();

    int height = 0;
    int width = 0;

    for (int i = 0; i < size; i++)
    {
        height = histogram[i];
        width = 1;

        // Check Kar ki ja sakte hai left check kar
        int j = i-1;
        while (j >= 0 && histogram[j] >= histogram[i])
        {
            j--;
            width++;
        }
        
        // Check Kar ki ja sakte hai right check kar
        int k = i+1;
        while (k < size && histogram[i] <= histogram[k])
        {
            k++;
            width++;
        }


        maxArea = max(width*height, maxArea);

    }
    

    return maxArea;
}


int findLargestAreaInHistogramUsingStack(vector<int> &histogram) {
    int maxArea = -1;
    int size = histogram.size();

    // cout << "Extra-Ordinary Fantastic Mind Blowing sir" << endl;
    vector<int> nextSmall = findNextSmallerElementUsingStack(histogram);
    vector<int> prevSmall = findPrevSmallerElementUsingStack(histogram);

    // print(nextSmall);
    // print(prevSmall);

    for (int i = 0; i < size; i++)
    {
        int height = histogram[i];
        
        // If Next Smaller Element's Index == -1 then it means there is no element which is smaller than this element thus update it with the Size of Array Histogram
        if (nextSmall[i] == -1)
        {
            nextSmall[i] = size; 
        }
        


        int width = nextSmall[i] - prevSmall[i] - 1;

        // cout << "For " << height << " updated area is: ";
        maxArea = max(width*height, maxArea);
        // cout << maxArea << endl;
    }
    
    return maxArea;
}


int main()
{
    vector<int> histogram = {7,7,7,7,0,7,7};
    cout << endl;


    cout << "Largest Area of Histogram is: " << findLargestAreaInHistogramUsingStack(histogram) << endl;


    cout << endl;

    return 0;
}
