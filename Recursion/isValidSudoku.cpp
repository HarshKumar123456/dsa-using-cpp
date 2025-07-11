#include <iostream>
#include <vector>
using namespace std;

bool doesViolateSudokuRules(vector<vector<int>> &mat)
{
    // Check for each row
    for (int i = 0; i < 9; i++)
    {
        vector<int> isDigitCounted(10, 0);
        for (int j = 0; j < 9; j++)
        {
            int digit = mat[i][j];
            if (digit != 0)
            {

                if (isDigitCounted[digit] == 0)
                {
                    isDigitCounted[digit] = 1;
                }
                else
                {
                    cout << "For row " << i << " - " << j << " we returned that it violates rule . " << endl;
                    return true;
                }
            }
        }
    }

    // Check for each column
    for (int i = 0; i < 9; i++)
    {
        vector<int> isDigitCounted(10, 0);
        for (int j = 0; j < 9; j++)
        {
            int digit = mat[j][i];
            if (digit != 0)
            {

                if (isDigitCounted[digit] == 0)
                {
                    isDigitCounted[digit] = 1;
                }
                else
                {
                    cout << "For col " << j << " - " << i << " we returned that it violates rule . " << endl;

                    return true;
                }
            }
        }
    }

    // Check for each box
    // For 1st line
    // Pahla box [0][0] se [2][2] tak hoga
    // Doosra Box [0][3] se [2][5] tak hoga
    // Doosra Box [0][6] se [2][8] tak hoga

    // For 2nd line
    // Pahla box [3][0] se [5][2] tak hoga
    // Doosra Box [3][3] se [5][5] tak hoga
    // Doosra Box [3][6] se [5][8] tak hoga

    // For 3rd line
    // Pahla box [6][0] se [8][2] tak hoga
    // Doosra Box [6][3] se [8][5] tak hoga
    // Doosra Box [6][6] se [8][8] tak hoga
    for (int i = 0; i < 9; i += 3)
    {
        int startingRow = i;
        int startingCol = 0;

        int boxChecked = 0;
        while (boxChecked < 3)
        {
            vector<int> isDigitCounted(10, 0);
            // Check for the box
            for (int j = startingRow; j < startingRow + 3; j++)
            {
                for (int k = startingCol; k < startingCol + 3; k++)
                {
                    int digit = mat[j][k];
                    if (digit != 0)
                    {

                        if (isDigitCounted[digit] == 0)
                        {
                            isDigitCounted[digit] = 1;
                        }
                        else
                        {
                            cout << "For box no. " << startingRow << " -> " << j << " - " << i << " we returned that it violates rule . " << endl;

                            return true;
                        }
                    }
                }
            }

            startingCol += 3;
            boxChecked++;
        }
    }

    return false;
}

bool isValidSudoku(vector<vector<int>> &mat)
{

    if (doesViolateSudokuRules(mat))
    {
        return false;
    }

    cout << "Now sudoku : " << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    // For Every Empty Position try the possible digits and check if it can be feasible solution or not
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            // Check If Empty and if so then fill and try solution
            if (mat[row][col] == 0)
            {
                for (int digit = 1; digit < 10; digit++)
                {
                    // Fill Digit
                    mat[row][col] = digit;

                    cout << "Trying filling the " << digit << " at the [" << row << "][" << col << "]" << endl;
                    // Check if it violates sudoku rules
                    if (doesViolateSudokuRules(mat) == false)
                    {
                        // Check for more positions
                        if (isValidSudoku(mat))
                        {
                            return true;
                        }
                    }
                }

                // Maintain the State of Sudoku as if no digits were placed at that place if no digit can make the valid sudoku
                cout << "Backtracking at [" << row << "][" << col << "] ------->" << mat[row][col] << endl;
                mat[row][col] = 0;
                cout << "Now sudoku : " << endl;
                for (int i = 0; i < 9; i++)
                {
                    for (int j = 0; j < 9; j++)
                    {
                        cout << mat[i][j] << " ";
                    }
                    cout << endl;
                }

                cout << endl;
                return false;
            }
        }
    }

    return true;
}

int main()
{
    // vector<int> isDigitCounted(10, 0);
    // for (auto i : isDigitCounted)
    // {
    //     cout << i << " ";
    // }

    //     Sample Input 1:
    // 1
    // 9 0 0 0 2 0 7 5 0
    // 6 0 0 0 5 0 0 4 0
    // 0 2 0 4 0 0 0 1 0
    // 2 0 8 0 0 0 0 0 0
    // 0 7 0 5 0 9 0 6 0
    // 0 0 0 0 0 0 4 0 1
    // 0 1 0 0 0 5 0 8 0
    // 0 9 0 0 7 0 0 0 4
    // 0 8 2 0 4 0 0 0 6
    // Sample Output 1:
    // yes
    // Explanation of the Sample Input1:
    // One of the possible solutions is:
    // 9 4 1 3 2 6 7 5 8
    // 6 3 7 1 5 8 2 4 9
    // 8 2 5 4 9 7 6 1 3
    // 2 6 8 7 1 4 3 9 5
    // 1 7 4 5 3 9 8 6 2
    // 3 5 9 6 8 2 4 7 1
    // 4 1 3 2 6 5 9 8 7
    // 5 9 6 8 7 3 1 2 4
    // 7 8 2 9 4 1 5 3 6
    // Sample Input 2:
    // 1
    // 1 5 9 0 0 6 0 3 2
    // 2 7 4 0 0 0 0 0 0
    // 3 8 6 2 0 0 0 0 5
    // 4 9 2 5 0 1 0 8 0
    // 6 3 7 0 4 0 0 0 0
    // 5 1 0 8 2 0 0 0 0
    // 8 2 1 0 0 0 0 0 0
    // 7 6 0 1 0 0 4 2 0
    // 9 4 3 0 7 0 0 6 1
    // Sample Output 2:
    // no
    // Explanation of the Sample Input2:
    // In the third column from the left,
    // there are two empty cells out of which one
    // has to be filled with ‘8’,
    // but we can’t put 8 in any of those two cells.

    
    vector<vector<int>> mat = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0,},
    {0, 0, 0, 0, 0, 0, 0, 0, 0,},
    {0, 0, 0, 0, 0, 0, 0, 0, 0,},
    {0, 0, 0, 0, 0, 0, 0, 0, 0,},
    {0, 0, 0, 0, 0, 0, 0, 0, 0,},
    {0, 0, 0, 0, 0, 0, 0, 0, 0,},
    {0, 0, 0, 0, 0, 0, 0, 0, 0,},
    {0, 0, 0, 0, 0, 0, 0, 0, 0,},
    {0, 0, 0, 0, 0, 0, 0, 0, 0,},
    };

    if (isValidSudoku(mat))
    {
        cout << "Bro yo valid sudoku hai" << endl;

        for (auto i : mat)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }

        if (doesViolateSudokuRules(mat))
        {
            cout << "Bro yo kare violate" << endl;
        }
        else
        {
            cout << "Bro Yo na kare violate" << endl;
        }
    }
    else
    {
        cout << "Bro Yo valid sudoku na hai" << endl;
    }


    int isDigitCounted[10] = {0};
    for (auto i : isDigitCounted){
        cout << i << " ";
    }
    cout << endl;
    cout << "\n\nEverything Nice and Easy till now \n\n"
         << endl;
    return 0;
}