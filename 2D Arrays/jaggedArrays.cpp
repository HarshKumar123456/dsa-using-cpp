#include <iostream>
#include <vector>
#include <bits/stdc++.h>
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

int main()
{
    // In C++ Bhai Jagged Arrays Statically Nahin kar sakte int[] wale scene se but haan "vector<vector<int>>"  (ye Dynamically resizable hoti hai) se zaroor kar saken but haan simulate karne ke liye neeche wala code likha hai 
    // int jaggedArraysStatically[][10] =
    //     {
    //         {1},
    //         {2, 3},
    //         {4, 5, 6},
    //         {7, 8, 9, 10}
    //     };

    // for(auto array : jaggedArraysStatically){
    //     printArray(array, 10);
    // }


    int columns = 10;
    vector<int> sizes;

    int rows = 10;
    cout << "Enter the rows to be in Jagged Array: ";
    cin >> rows;

    int** jaggedArrayDynamically = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        cout << "For Row = " << i + 1 << " Enter the columns to be putted in: "; 

        cin >> columns;
        sizes.push_back(columns);

        jaggedArrayDynamically[i] = new int[columns];

        cout << "Please Enter " << columns << " elements: ";
        int row = i;
        for(int col = 0; col < columns; col++){
            cin >> jaggedArrayDynamically[row][col];
        }
    }


    cout << "Printing Array" << endl;
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < sizes[row]; col++)
        {
            cout << jaggedArrayDynamically[row][col] << " ";
        }
        cout << endl;
    }
    

    cout << "Freeing (Not a Word I think) Space " << endl;
    cout << "Freeing (And Yes, It *Is* a Word 😄) Space!" << endl;

    for (int i = 0; i < rows; i++)
    {
        delete[] jaggedArrayDynamically[i];
    }
    
    delete[] jaggedArrayDynamically;


	cout << "We have taken TC: O( max(rows) * max(columns) ) and SC: O( max(rows) * max(columns) )" << endl;
    

    return 0;
}