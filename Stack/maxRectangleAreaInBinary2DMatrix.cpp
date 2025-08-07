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

    for (int i = size - 1; i >= 0; i--)
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

int findLargestAreaInHistogramUsingStack(vector<int> &histogram)
{
    int maxArea = -1;
    int size = histogram.size();

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
        maxArea = max(width * height, maxArea);
        // cout << maxArea << endl;
    }

    return maxArea;
}

bool validRectangle(vector<vector<int>> &binaryMatrix, int startingRow, int startingCol, int endingRow, int endingCol)
{

    for (int row = startingRow; row <= endingRow; row++)
    {
        for (int col = startingCol; col <= endingCol; col++)
        {
            if (binaryMatrix[row][col] == 0)
            {
                return false;
            }
        }
    }

    return true;
}

int findMaxRectangleAreaInBinary2DMatrixUsing2DArraysOnly(vector<vector<int>> &binaryMatrix)
{
    int maxArea = -1;

    int noOfRows = binaryMatrix.size();
    int noOfCols = binaryMatrix[0].size();
    int ranCount = 0;

    cout << "No of rows cols: " << noOfRows << " " << noOfCols << endl;

    // For Every Coordinate Try Out All Possible coordinate and check if there is a rectangle then find area and update

    for (int startingRow = 0; startingRow < noOfRows; startingRow++)
    {
        for (int startingCol = 0; startingCol < noOfCols; startingCol++)
        {

            for (int endingRow = startingRow; endingRow < noOfRows; endingRow++)
            {
                for (int endingCol = startingCol; endingCol < noOfCols; endingCol++)
                {
                    ranCount++;
                    if (validRectangle(binaryMatrix, startingRow, startingCol, endingRow, endingCol))
                    {
                        // cout << "Found Valid Rectangle: (" << startingRow << "," << startingCol << ")" << " and (" << endingRow << "," << endingCol << ")" << endl;

                        int width = endingRow - startingRow + 1;
                        int height = endingCol - startingCol + 1;

                        // cout << "width and height are: " << width << " " << height << endl << endl;
                        maxArea = max(maxArea, width * height);
                    }
                }
            }
        }
    }

    cout << "Bhai " << ranCount << " times chalna pada. " << endl;
    return maxArea;
}

int findMaxRectangleAreaInBinary2DMatrixUsingStackTraversingUpToDown(vector<vector<int>> &binaryMatrix)
{

    // Use Approach of Largest Area in Histogram, Yahan par ek naya array banana padega jismein ham histogram maintain karenge
    // Basically array banao aur height ko maintain and update karte raho
    int noOfRows = binaryMatrix.size();
    int noOfCols = binaryMatrix[0].size();
    int maxArea = -1;
    vector<int> histogram(noOfCols);

    // Store first row and find max area in histogram
    int row = 0;
    for (int col = 0; col < noOfCols; col++)
    {
        histogram[col] = binaryMatrix[row][col];
    }

    // cout << "Now Histogram: " << endl;
    // for (int i = 0; i < orderOfMatrix; i++)
    // {
    //     cout << histogram[i] << " ";
    // }
    // cout << endl;

    maxArea = max(maxArea, findLargestAreaInHistogramUsingStack(histogram));

    // cout << "Now area is: " << maxArea << endl;

    // Update histogram for every other row from up to down and find area
    row = 1;
    while (row < noOfRows)
    {
        for (int col = 0; col < noOfCols; col++)
        {
            int height = 0;
            // Agar neeche 1 hai to update kardo height ko (currentHeight + 1) se
            if (binaryMatrix[row][col] == 1)
            {
                height = histogram[col] + 1;
            }

            histogram[col] = height;
        }

        // cout << "Now Histogram: " << endl;
        // for (int i = 0; i < orderOfMatrix; i++)
        // {
        //     cout << histogram[i] << " ";
        // }
        // cout << endl;

        // For this row we got updated heights in histogram
        maxArea = max(maxArea, findLargestAreaInHistogramUsingStack(histogram));

        // cout << "Now area is: " << maxArea << endl;

        // Move to another row
        row++;
    }

    return maxArea;
};


// Ye Concept use karne ke liye base ka dhyan rakhna hoga height ko update karne ke liye isliye we uses the up to down method to avoid unneccesaary calculations
int findMaxRectangleAreaInBinary2DMatrixUsingStackTraversingDownToUp(vector<vector<int>> &binaryMatrix)
{

    // Use Approach of Largest Area in Histogram, Yahan par ek naya array banana padega jismein ham histogram maintain karenge
    // Basically array banao aur height ko maintain and update karte raho

    int noOfRows = binaryMatrix.size();
    int noOfCols = binaryMatrix[0].size();
    int maxArea = -1;
    vector<int> histogram(noOfCols);

    // Store last row and find max area in histogram
    int row = noOfRows-1;
    for (int col = 0; col < noOfCols; col++)
    {
        histogram[col] = binaryMatrix[row][col];
    }

    cout << "Now Histogram: " << endl;
    for (int i = 0; i < noOfCols; i++)
    {
        cout << histogram[i] << " ";
    }
    cout << endl;

    maxArea = max(maxArea, findLargestAreaInHistogramUsingStack(histogram));

    cout << "Now area is: " << maxArea << endl;

    // Update histogram for every other row from down to up and find area
    row = noOfRows - 2;
    while (row >= 0)
    {
        for (int col = 0; col < noOfCols; col++)
        {
            cout << "Updating heights: " << endl;
            for (int i = 0; i < noOfCols; i++)
            {
                cout << histogram[i] << " ";
            }
            cout << endl;
            
            int height = histogram[col];
            // Agar upar 1 hai to update kardo height ko (currentHeight + 1) se
            // But ismein ek catch hai ki man lo upar ja rahe but 0 aaya to height ka kya karoge height agar kuchh hogi to 0 thode hi ho jayegi agar upar 0 hai to isliye ismein height ko currentHeight se initialize kiya
            // Aur Agar upar 1 mila to check karo ki iske neeche kya tha agar 1 tha tab to height badhao nahin to height abhi start hui hai 
            if (binaryMatrix[row][col] == 1 && binaryMatrix[row+1][col] == 1)
            {
                height = histogram[col] + 1;
            }
            else if(binaryMatrix[row][col] == 1 && binaryMatrix[row+1][col] == 0) {
                height = 1;
            }
            else{
                height = histogram[col];
            }

            histogram[col] = height;
        }

        cout << "Now Histogram: " << endl;
        for (int i = 0; i < noOfCols; i++)
        {
            cout << histogram[i] << " ";
        }
        cout << endl;

        // For this row we got updated heights in histogram
        maxArea = max(maxArea, findLargestAreaInHistogramUsingStack(histogram));

        cout << "Now area is: " << maxArea << endl;

        // Move to another row
        row--;
    }

    return maxArea;
};


int main()
{
    vector<vector<int>> binaryMatrix = {
        {0,1,1,0},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,0,0},
    };

    cout << endl;
    cout << "Max Area is: " << endl
         << findMaxRectangleAreaInBinary2DMatrixUsingStackTraversingDownToUp(binaryMatrix) << endl;
    cout << endl;

    return 0;
}