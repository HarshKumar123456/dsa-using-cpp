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

void rotateMatrix90DegreeByTransposeAndSwapColumn()
{
    // Approach 1: Transpose Matrix and then Swap by Column
    int orderOfMatrix;

    cout << "Enter the order of matrix: " << endl;
    cin >> orderOfMatrix;

    int matrix[orderOfMatrix][orderOfMatrix];

    for (int row = 0; row < orderOfMatrix; row++)
    {
        for (int col = 0; col < orderOfMatrix; col++)
        {
            cin >> matrix[row][col];
        }
    }

    cout << "Entered Matrix: " << endl;
    for (int row = 0; row < orderOfMatrix; row++)
    {
        for (int col = 0; col < orderOfMatrix; col++)
        {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }

    int startingRow = 0;
    int endingRow = 0;
    int startingColumn = startingRow + 1;
    int endingColumn = orderOfMatrix - 1;

    while (startingRow < orderOfMatrix)
    {
        for (int col = startingColumn; col <= endingColumn; col++)
        {
            swap(matrix[startingRow][col], matrix[col][startingRow]);
        }

        startingRow++;
        startingColumn = startingRow + 1;
    }

    cout << "Transposed Matrix: " << endl;
    for (int row = 0; row < orderOfMatrix; row++)
    {
        for (int col = 0; col < orderOfMatrix; col++)
        {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }

    startingRow = 0;
    endingRow = orderOfMatrix - 1;
    startingColumn = 0;
    endingColumn = orderOfMatrix - 1;

    while (startingColumn < endingColumn)
    {

        for (int row = startingRow; row <= endingRow; row++)
        {
            swap(matrix[row][startingColumn], matrix[row][endingColumn]);
        }
        startingColumn++;
        endingColumn--;
    }

    cout << "Rotated Matrix: " << endl;
    for (int row = 0; row < orderOfMatrix; row++)
    {
        for (int col = 0; col < orderOfMatrix; col++)
        {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }
}


// By Using Extra Space We can move to first row to last column, second row to second last column and so on
// newMatrix[i][j] = matrix[j][orderOfMatrix-i-1]  
 
int main()
{
    // cout << "Approach 1: Transpose Matrix and then Swap by Column" << endl;
    // rotateMatrix90DegreeByTransposeAndSwapColumn();

    lineBreak();

    int orderOfMatrix;

    cout << "Enter the order of matrix: " << endl;
    cin >> orderOfMatrix;

    int matrix[orderOfMatrix][orderOfMatrix];

    for (int row = 0; row < orderOfMatrix; row++)
    {
        for (int col = 0; col < orderOfMatrix; col++)
        {
            cin >> matrix[row][col];
        }
    }

    cout << "Entered Matrix: " << endl;
    for (int row = 0; row < orderOfMatrix; row++)
    {
        for (int col = 0; col < orderOfMatrix; col++)
        {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }

    int start = 0;
    int end = orderOfMatrix - 2;

    while (start < end)
    {
        // cout << "For start end "<< start << "  " << end << "____________________________________________" << endl;
        int startingRow = start;
        int endingRow = orderOfMatrix - startingRow - 1;
        int startingColumn = startingRow;
        int endingColumn = orderOfMatrix - startingColumn - 1;

        for (int seed = 0; seed <= end-start; seed++)
        {
            // cout << "For Seed " << seed << endl;
            // cout << "Elements " << matrix[startingRow][startingColumn + seed] << " " << matrix[startingRow + seed][endingColumn] << " " << matrix[endingRow - seed][startingColumn] << " " << matrix[endingRow][endingColumn - seed] << endl;

            // Swap TL, TR and Swap BL, BR
            swap(matrix[startingRow][startingColumn + seed], matrix[startingRow + seed][endingColumn]);
            // cout << "_______________________ " << endl;
            // for (int row = 0; row < orderOfMatrix; row++)
            // {
            //     for (int col = 0; col < orderOfMatrix; col++)
            //     {
            //         cout << matrix[row][col] << " ";
            //     }
            //     cout << endl;
            // }

            swap(matrix[endingRow - seed][startingColumn], matrix[endingRow][endingColumn - seed]);
            // cout << "_______________________ " << endl;
            // for (int row = 0; row < orderOfMatrix; row++)
            // {
            //     for (int col = 0; col < orderOfMatrix; col++)
            //     {
            //         cout << matrix[row][col] << " ";
            //     }
            //     cout << endl;
            // }

            // Swap TL, BR
            swap(matrix[startingRow][startingColumn + seed], matrix[endingRow][endingColumn - seed]);
            // cout << "_______________________ " << endl;
            // for (int row = 0; row < orderOfMatrix; row++)
            // {
            //     for (int col = 0; col < orderOfMatrix; col++)
            //     {
            //         cout << matrix[row][col] << " ";
            //     }
            //     cout << endl;
            // }
        }

        start++;
        end--;
    }

    int seed = 0;
    int startingRow = start;
    int endingRow = orderOfMatrix - startingRow - 1;
    int startingColumn = startingRow;
    int endingColumn = orderOfMatrix - startingColumn - 1;

    swap(matrix[startingRow][startingColumn + seed], matrix[startingRow + seed][endingColumn]);
    swap(matrix[endingRow - seed][startingColumn], matrix[endingRow][endingColumn - seed]);
    swap(matrix[startingRow][startingColumn + seed], matrix[endingRow][endingColumn - seed]);

    cout << "Rotated Matrix: " << endl;
    for (int row = 0; row < orderOfMatrix; row++)
    {
        for (int col = 0; col < orderOfMatrix; col++)
        {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }

    cout << "@@@@@@@@@@@@@@@@@@@" << endl;

    rotateMatrix90DegreeByTransposeAndSwapColumn();

    return 0;
}
