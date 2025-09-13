#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <limits.h>
using namespace std;

class Coordinates
{
public:
    int row = -1;
    int col = -1;
};

class SofaPosition
{
public:
    // Sofa of length 2 'ss'
    Coordinates startingCoordinate;
    Coordinates endingCoordinate;
    char orientation;

    void resetOrientation()
    {
        if (startingCoordinate.col != endingCoordinate.col)
        {
            orientation = 'h';
            return;
        }
        orientation = 'v';
        return;
    }
};

class Move
{
public:
    int startRowStep = 0;
    int startColStep = 0;
    int endRowStep = 0;
    int endColStep = 0;
    string moveName;
    string reverseMoveName;
};

vector<char> getPossibleSofaOrientations()
{

    vector<char> orientations = {'h', 'v'};

    return orientations;
}

void printSofa(SofaPosition &sofa) {
    cout << "Sofa Oritation is: " << sofa.orientation << " Sofa at -> [" <<  sofa.startingCoordinate.row << ", " << sofa.startingCoordinate.col << "] [" << sofa.endingCoordinate.row << ", " << sofa.endingCoordinate.col << "]" << endl;
}

void printHouseThingsArrangement(vector<vector<char>> &houseThingsArrangementMatrix, int rows, int cols, SofaPosition &sofaPosition)
{
    cout << "Sofa at [" << sofaPosition.startingCoordinate.row << "," << sofaPosition.startingCoordinate.col << "] [" << sofaPosition.endingCoordinate.row << "," << sofaPosition.endingCoordinate.col << "] Printing House: " << endl;

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            cout << houseThingsArrangementMatrix[row][col] << " ";
        }
        cout << endl;
    }
    return;
}

bool isVerticalOrientationOfSofa(SofaPosition sofa)
{
    if (sofa.startingCoordinate.col != sofa.endingCoordinate.col)
    {
        cout << "\nHorizontal Sofa " << endl;
        return false;
    }
    cout << "\nVertical Sofa " << endl;
    return true;
}

SofaPosition findSofaCurrentPosition(vector<vector<char>> houseThingsArrangementMatrix, int rows, int cols)
{

    SofaPosition sofa;

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (houseThingsArrangementMatrix[row][col] == 's')
            {
                // Either Sofa will be s then s means ss
                // Or Sofa will be s down s means s
                //                                s

                Coordinates startingCoordinate;
                Coordinates endingCoordinate;

                startingCoordinate.row = row;
                startingCoordinate.col = col;

                if (houseThingsArrangementMatrix[row][col + 1] == 's')
                {
                    endingCoordinate.row = row;
                    endingCoordinate.col = col + 1;
                }
                else if (houseThingsArrangementMatrix[row + 1][col] == 's')
                {
                    endingCoordinate.row = row + 1;
                    endingCoordinate.col = col;
                }
                else
                {
                    // Depicting Invalid Input Test Case For ss type sofa
                    endingCoordinate.row = -1;
                    endingCoordinate.col = -1;
                }

                sofa.startingCoordinate = startingCoordinate;
                sofa.endingCoordinate = endingCoordinate;

                sofa.resetOrientation();
                return sofa;
            }
        }
    }

    sofa.resetOrientation();
    return sofa;
}

SofaPosition findSofaDestinationPosition(vector<vector<char>> houseThingsArrangementMatrix, int rows, int cols)
{

    SofaPosition sofa;

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (houseThingsArrangementMatrix[row][col] == 'S')
            {
                // Either Sofa will be s then s means ss
                // Or Sofa will be s down s means s
                //                                s

                Coordinates startingCoordinate;
                Coordinates endingCoordinate;

                startingCoordinate.row = row;
                startingCoordinate.col = col;

                if (houseThingsArrangementMatrix[row][col + 1] == 'S')
                {
                    endingCoordinate.row = row;
                    endingCoordinate.col = col + 1;
                }
                else if (houseThingsArrangementMatrix[row + 1][col] == 'S')
                {
                    endingCoordinate.row = row + 1;
                    endingCoordinate.col = col;
                }
                else
                {
                    // Depicting Invalid Input Test Case For ss type sofa
                    endingCoordinate.row = -1;
                    endingCoordinate.col = -1;
                }

                sofa.startingCoordinate = startingCoordinate;
                sofa.endingCoordinate = endingCoordinate;

                sofa.resetOrientation();
                return sofa;
            }
        }
    }

    sofa.resetOrientation();
    return sofa;
}

bool isSofaMoved(SofaPosition &sofaStartPosition, SofaPosition &sofaEndPosition)
{
    if (
        (
            sofaStartPosition.startingCoordinate.row == sofaEndPosition.startingCoordinate.row

            && sofaStartPosition.startingCoordinate.col == sofaEndPosition.startingCoordinate.col

            && sofaStartPosition.endingCoordinate.row == sofaEndPosition.endingCoordinate.row

            && sofaStartPosition.endingCoordinate.col == sofaEndPosition.endingCoordinate.col)

        ||

        (sofaStartPosition.startingCoordinate.row == sofaEndPosition.endingCoordinate.row

         && sofaStartPosition.startingCoordinate.col == sofaEndPosition.endingCoordinate.col

         && sofaStartPosition.endingCoordinate.row == sofaEndPosition.startingCoordinate.row

         && sofaStartPosition.endingCoordinate.col == sofaEndPosition.startingCoordinate.col)

    )
    {
        return true;
    }

    return false;
}

bool canMoveVerticallyUpward(vector<vector<char>> &houseThingsArrangementMatrix, int rows, int cols, SofaPosition &sofaPosition)
{

    int sofaStartRow = sofaPosition.startingCoordinate.row;
    int sofaStartCol = sofaPosition.startingCoordinate.col;

    int sofaEndRow = sofaPosition.endingCoordinate.row;
    int sofaEndCol = sofaPosition.endingCoordinate.col;

    // Vertically Upward will require Empty Place && Unvisited Place && In Matrix Range Place

    // If Sofa End Is Up
    if (sofaPosition.endingCoordinate.row < sofaPosition.startingCoordinate.row)
    {
        if (
            (sofaEndRow - 1 >= 0)                                                // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaEndRow - 1][sofaEndCol] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }
    // If Sofa Start Is Up
    else
    {
        if (
            (sofaStartRow - 1 >= 0)                                                  // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaStartRow - 1][sofaStartCol] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }

    return false;
}

bool canMoveVerticallyDownward(vector<vector<char>> &houseThingsArrangementMatrix, int rows, int cols, SofaPosition &sofaPosition)
{

    int sofaStartRow = sofaPosition.startingCoordinate.row;
    int sofaStartCol = sofaPosition.startingCoordinate.col;

    int sofaEndRow = sofaPosition.endingCoordinate.row;
    int sofaEndCol = sofaPosition.endingCoordinate.col;

    // Vertically Downward will require Empty Place && Unvisited Place && In Matrix Range Place

    // If Sofa End Is Up
    if (sofaPosition.endingCoordinate.row < sofaPosition.startingCoordinate.row)
    {
        if (
            (sofaStartRow + 1 < rows)                                                // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaStartRow + 1][sofaStartCol] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }
    // If Sofa Start Is Up
    else
    {
        if (
            (sofaEndRow + 1 < rows)                                              // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaEndRow + 1][sofaEndCol] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }

    return false;
}

// ReCheck it
bool canMoveVerticallyForward(vector<vector<char>> &houseThingsArrangementMatrix, int rows, int cols, SofaPosition &sofaPosition)
{

    int sofaStartRow = sofaPosition.startingCoordinate.row;
    int sofaStartCol = sofaPosition.startingCoordinate.col;

    int sofaEndRow = sofaPosition.endingCoordinate.row;
    int sofaEndCol = sofaPosition.endingCoordinate.col;

    // Vertically Forward will require Empty Place && Unvisited Place && In Matrix Range Place

    // If Sofa End Is Up
    if (sofaPosition.endingCoordinate.row < sofaPosition.startingCoordinate.row)
    {
        if (
            (sofaStartCol + 1 < cols && sofaEndCol + 1 < cols)                                                // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaStartRow][sofaStartCol + 1] == '0' && houseThingsArrangementMatrix[sofaEndRow][sofaEndCol + 1] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }
    // If Sofa Start Is Up
    else
    {
        if (
            (sofaStartCol + 1 < cols && sofaEndCol + 1 < cols)                                                // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaStartRow][sofaStartCol + 1] == '0' && houseThingsArrangementMatrix[sofaEndRow][sofaEndCol + 1] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }

    return false;
}

// Recheck it
bool canMoveVerticallyBackward(vector<vector<char>> &houseThingsArrangementMatrix, int rows, int cols, SofaPosition &sofaPosition)
{

    int sofaStartRow = sofaPosition.startingCoordinate.row;
    int sofaStartCol = sofaPosition.startingCoordinate.col;

    int sofaEndRow = sofaPosition.endingCoordinate.row;
    int sofaEndCol = sofaPosition.endingCoordinate.col;

    // Vertically Backward will require Empty Place && Unvisited Place && In Matrix Range Place

    // If Sofa End Is Up
    if (sofaPosition.endingCoordinate.row < sofaPosition.startingCoordinate.row)
    {
        if (
            (sofaStartCol - 1 >= 0 && sofaEndCol - 1 >= 0)                                                // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaStartRow][sofaStartCol - 1] == '0' && houseThingsArrangementMatrix[sofaEndRow][sofaEndCol - 1] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }
    // If Sofa Start Is Up
    else
    {
        if (
            (sofaStartCol - 1 >= 0 && sofaEndCol - 1 >= 0)                                                // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaStartRow][sofaStartCol - 1] == '0' && houseThingsArrangementMatrix[sofaEndRow][sofaEndCol - 1] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }

    return false;
}

bool canVerticallyRotateUpwardLeft(vector<vector<char>> &houseThingsArrangementMatrix, int rows, int cols, SofaPosition &sofaPosition)
{

    int sofaStartRow = sofaPosition.startingCoordinate.row;
    int sofaStartCol = sofaPosition.startingCoordinate.col;

    int sofaEndRow = sofaPosition.endingCoordinate.row;
    int sofaEndCol = sofaPosition.endingCoordinate.col;

    // Rotate Vertically Upward Left will require (2*2 Empty && Unvisited Place Including Sofa) && In Matrix Range Place

    // If Sofa End Is Up
    if (sofaPosition.endingCoordinate.row < sofaPosition.startingCoordinate.row)
    {
        int row = sofaEndRow;
        int col = sofaEndCol - 1;

        if (
            (sofaEndCol - 1 >= 0 && sofaStartCol - 1 >= 0)                                                                            // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaStartRow][sofaStartCol - 1] != 'H' && houseThingsArrangementMatrix[row][col] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }
    // If Sofa Start Is Up
    else
    {
        int row = sofaStartRow;
        int col = sofaStartCol - 1;

        if (
            (sofaEndCol - 1 >= 0 && sofaStartCol - 1 >= 0)                                                                        // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaEndRow][sofaEndCol - 1] != 'H' && houseThingsArrangementMatrix[row][col] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }

    return false;
}

bool canVerticallyRotateUpwardRight(vector<vector<char>> &houseThingsArrangementMatrix, int rows, int cols, SofaPosition &sofaPosition)
{

    int sofaStartRow = sofaPosition.startingCoordinate.row;
    int sofaStartCol = sofaPosition.startingCoordinate.col;

    int sofaEndRow = sofaPosition.endingCoordinate.row;
    int sofaEndCol = sofaPosition.endingCoordinate.col;

    // Rotate Vertically Upward Right will require (2*2 Empty && Unvisited Place Including Sofa) && In Matrix Range Place

    // If Sofa End Is Up
    if (sofaPosition.endingCoordinate.row < sofaPosition.startingCoordinate.row)
    {
        int row = sofaEndRow;
        int col = sofaEndCol + 1;

        if (
            (sofaEndCol + 1 < cols && sofaStartCol + 1 < cols)                                                                        // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaStartRow][sofaStartCol + 1] != 'H' && houseThingsArrangementMatrix[row][col] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }
    // If Sofa Start Is Up
    else
    {
        int row = sofaStartRow;
        int col = sofaStartCol + 1;

        if (
            (sofaEndCol + 1 < cols && sofaStartCol + 1 < cols)                                                                    // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaEndRow][sofaEndCol + 1] != 'H' && houseThingsArrangementMatrix[row][col] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }

    return false;
}

bool canVerticallyRotateDownwardLeft(vector<vector<char>> &houseThingsArrangementMatrix, int rows, int cols, SofaPosition &sofaPosition)
{

    int sofaStartRow = sofaPosition.startingCoordinate.row;
    int sofaStartCol = sofaPosition.startingCoordinate.col;

    int sofaEndRow = sofaPosition.endingCoordinate.row;
    int sofaEndCol = sofaPosition.endingCoordinate.col;

    // Rotate Vertically Downward Left will require (2*2 Empty && Unvisited Place Including Sofa) && In Matrix Range Place

    // If Sofa End Is Up
    if (sofaPosition.endingCoordinate.row < sofaPosition.startingCoordinate.row)
    {
        int row = sofaStartRow;
        int col = sofaStartCol - 1;

        if (
            (sofaEndCol - 1 >= 0 && sofaStartCol - 1 >= 0)                                                                        // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaEndRow][sofaEndCol - 1] != 'H' && houseThingsArrangementMatrix[row][col] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }
    // If Sofa Start Is Up
    else
    {
        int row = sofaEndRow;
        int col = sofaEndCol - 1;

        if (
            (sofaEndCol - 1 >= 0 && sofaStartCol - 1 >= 0)                                                                            // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaStartRow][sofaStartCol - 1] != 'H' && houseThingsArrangementMatrix[row][col] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }

    return false;
}

bool canVerticallyRotateDownwardRight(vector<vector<char>> &houseThingsArrangementMatrix, int rows, int cols, SofaPosition &sofaPosition)
{

    int sofaStartRow = sofaPosition.startingCoordinate.row;
    int sofaStartCol = sofaPosition.startingCoordinate.col;

    int sofaEndRow = sofaPosition.endingCoordinate.row;
    int sofaEndCol = sofaPosition.endingCoordinate.col;

    // Rotate Vertically Downward Right will require (2*2 Empty && Unvisited Place Including Sofa) && In Matrix Range Place

    // If Sofa End Is Up
    if (sofaPosition.endingCoordinate.row < sofaPosition.startingCoordinate.row)
    {
        int row = sofaStartRow;
        int col = sofaStartCol + 1;

        if (
            (sofaEndCol + 1 < cols && sofaStartCol + 1 < cols)                                                                    // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaEndRow][sofaEndCol + 1] != 'H' && houseThingsArrangementMatrix[row][col] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }
    // If Sofa Start Is Up
    else
    {
        int row = sofaEndRow;
        int col = sofaEndCol + 1;

        if (
            (sofaEndCol + 1 < cols && sofaStartCol + 1 < cols)                                                                        // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaStartRow][sofaStartCol + 1] != 'H' && houseThingsArrangementMatrix[row][col] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }

    return false;
}

// Recheck it
bool canMoveHorizontallyUpward(vector<vector<char>> &houseThingsArrangementMatrix, int rows, int cols, SofaPosition &sofaPosition)
{

    int sofaStartRow = sofaPosition.startingCoordinate.row;
    int sofaStartCol = sofaPosition.startingCoordinate.col;

    int sofaEndRow = sofaPosition.endingCoordinate.row;
    int sofaEndCol = sofaPosition.endingCoordinate.col;

    // Horizontally Forward will require Empty Place && Unvisited Place && In Matrix Range Place

    // If Sofa End is Left
    if (sofaPosition.endingCoordinate.col < sofaPosition.startingCoordinate.col)
    {
        if (
            (sofaStartRow - 1 >= 0 && sofaEndRow - 1 >= 0)                                                // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaStartRow - 1][sofaStartCol] == '0' && houseThingsArrangementMatrix[sofaEndRow - 1][sofaEndCol] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }
    // Else Sofa Start is Left
    else
    {
        if (
            (sofaStartRow - 1 >= 0 && sofaEndRow - 1 >= 0)                                                // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaStartRow - 1][sofaStartCol] == '0' && houseThingsArrangementMatrix[sofaEndRow - 1][sofaEndCol] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }

    return false;
}

// Recheck it
bool canMoveHorizontallyDownward(vector<vector<char>> &houseThingsArrangementMatrix, int rows, int cols, SofaPosition &sofaPosition)
{

    int sofaStartRow = sofaPosition.startingCoordinate.row;
    int sofaStartCol = sofaPosition.startingCoordinate.col;

    int sofaEndRow = sofaPosition.endingCoordinate.row;
    int sofaEndCol = sofaPosition.endingCoordinate.col;

    // Horizontally Forward will require Empty Place && Unvisited Place && In Matrix Range Place

    // If Sofa End is Left
    if (sofaPosition.endingCoordinate.col < sofaPosition.startingCoordinate.col)
    {
        if (
            (sofaStartRow + 1 < rows && sofaEndRow + 1 < rows)                                                // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaStartRow + 1][sofaStartCol] == '0' && houseThingsArrangementMatrix[sofaEndRow + 1][sofaEndCol] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }
    // Else Sofa Start is Left
    else
    {
        if (
            (sofaStartRow + 1 < rows && sofaEndRow + 1 < rows)                                                // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaStartRow + 1][sofaStartCol] == '0' && houseThingsArrangementMatrix[sofaEndRow + 1][sofaEndCol] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }

    return false;
}

bool canMoveHorizontallyForward(vector<vector<char>> &houseThingsArrangementMatrix, int rows, int cols, SofaPosition &sofaPosition)
{

    int sofaStartRow = sofaPosition.startingCoordinate.row;
    int sofaStartCol = sofaPosition.startingCoordinate.col;

    int sofaEndRow = sofaPosition.endingCoordinate.row;
    int sofaEndCol = sofaPosition.endingCoordinate.col;

    // Horizontally Forward will require Empty Place && Unvisited Place && In Matrix Range Place

    // If Sofa End is Left
    if (sofaPosition.endingCoordinate.col < sofaPosition.startingCoordinate.col)
    {
        if (
            (sofaStartCol + 1 < cols)                                                // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaStartRow][sofaStartCol + 1] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }
    // Else Sofa Start is Left
    else
    {
        if (
            (sofaEndCol + 1 < cols)                                              // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaEndRow][sofaEndCol + 1] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }

    return false;
}

bool canMoveHorizontallyBackward(vector<vector<char>> &houseThingsArrangementMatrix, int rows, int cols, SofaPosition &sofaPosition)
{

    int sofaStartRow = sofaPosition.startingCoordinate.row;
    int sofaStartCol = sofaPosition.startingCoordinate.col;

    int sofaEndRow = sofaPosition.endingCoordinate.row;
    int sofaEndCol = sofaPosition.endingCoordinate.col;

    // Horizontally Forward will require Empty Place && Unvisited Place && In Matrix Range Place

    // If Sofa End is Left
    if (sofaPosition.endingCoordinate.col < sofaPosition.startingCoordinate.col)
    {
        if (
            (sofaEndCol - 1 >= 0)                                                // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaEndRow][sofaEndCol - 1] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }
    // Else Sofa Start is Left
    else
    {
        if (
            (sofaStartCol - 1 >= 0)                                                  // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaStartRow][sofaStartCol - 1] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }

    return false;
}

bool canHorizontallyRotateUpwardLeft(vector<vector<char>> &houseThingsArrangementMatrix, int rows, int cols, SofaPosition &sofaPosition)
{

    int sofaStartRow = sofaPosition.startingCoordinate.row;
    int sofaStartCol = sofaPosition.startingCoordinate.col;

    int sofaEndRow = sofaPosition.endingCoordinate.row;
    int sofaEndCol = sofaPosition.endingCoordinate.col;

    // Rotate Horizontally Upward Left will require (2*2 Empty && Unvisited Place Including Sofa) && In Matrix Range Place

    // If Sofa End is Left
    if (sofaPosition.endingCoordinate.col < sofaPosition.startingCoordinate.col)
    {
        int row = sofaEndRow - 1;
        int col = sofaEndCol;

        if (
            (sofaEndRow - 1 >= 0 && sofaStartRow - 1 >= 0)                                                                            // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaStartRow - 1][sofaStartCol] != 'H' && houseThingsArrangementMatrix[row][col] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }
    // If Sofa Start is Left
    else
    {
        int row = sofaStartRow - 1;
        int col = sofaStartCol;

        if (
            (sofaEndRow - 1 >= 0 && sofaStartRow - 1 >= 0)                                                                        // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaEndRow - 1][sofaEndCol] != 'H' && houseThingsArrangementMatrix[row][col] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }

    return false;
}

bool canHorizontallyRotateUpwardRight(vector<vector<char>> &houseThingsArrangementMatrix, int rows, int cols, SofaPosition &sofaPosition)
{

    int sofaStartRow = sofaPosition.startingCoordinate.row;
    int sofaStartCol = sofaPosition.startingCoordinate.col;

    int sofaEndRow = sofaPosition.endingCoordinate.row;
    int sofaEndCol = sofaPosition.endingCoordinate.col;

    // Rotate Horizontally Upward Right will require (2*2 Empty && Unvisited Place Including Sofa) && In Matrix Range Place

    // If Sofa End is Left
    if (sofaPosition.endingCoordinate.col < sofaPosition.startingCoordinate.col)
    {
        int row = sofaStartRow - 1;
        int col = sofaStartCol;

        if (
            (sofaEndRow - 1 >= 0 && sofaStartRow - 1 >= 0)                                                                        // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaEndRow - 1][sofaEndCol] != 'H' && houseThingsArrangementMatrix[row][col] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }
    // If Sofa Start is Left
    else
    {
        int row = sofaEndRow - 1;
        int col = sofaEndCol;

        if (
            (sofaEndRow - 1 >= 0 && sofaStartRow - 1 >= 0)                                                                            // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaStartRow - 1][sofaStartCol] != 'H' && houseThingsArrangementMatrix[row][col] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }

    return false;
}

bool canHorizontallyRotateDownwardLeft(vector<vector<char>> &houseThingsArrangementMatrix, int rows, int cols, SofaPosition &sofaPosition)
{

    int sofaStartRow = sofaPosition.startingCoordinate.row;
    int sofaStartCol = sofaPosition.startingCoordinate.col;

    int sofaEndRow = sofaPosition.endingCoordinate.row;
    int sofaEndCol = sofaPosition.endingCoordinate.col;

    // Rotate Horizontally Downward Left will require (2*2 Empty && Unvisited Place Including Sofa) && In Matrix Range Place

    // If Sofa End is Left
    if (sofaPosition.endingCoordinate.col < sofaPosition.startingCoordinate.col)
    {
        int row = sofaEndRow + 1;
        int col = sofaEndCol;

        if (
            (sofaEndRow + 1 < rows && sofaStartRow + 1 < rows)                                                                        // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaStartRow + 1][sofaStartCol] != 'H' && houseThingsArrangementMatrix[row][col] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }
    // If Sofa Start is Left
    else
    {
        int row = sofaStartRow + 1;
        int col = sofaStartCol;

        if (
            (sofaEndRow + 1 < rows && sofaStartRow + 1 < rows)                                                                    // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaEndRow + 1][sofaEndCol] != 'H' && houseThingsArrangementMatrix[row][col] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }

    return false;
}

bool canHorizontallyRotateDownwardRight(vector<vector<char>> &houseThingsArrangementMatrix, int rows, int cols, SofaPosition &sofaPosition)
{

    int sofaStartRow = sofaPosition.startingCoordinate.row;
    int sofaStartCol = sofaPosition.startingCoordinate.col;

    int sofaEndRow = sofaPosition.endingCoordinate.row;
    int sofaEndCol = sofaPosition.endingCoordinate.col;

    // Rotate Horizontally Downward Right will require (2*2 Empty && Unvisited Place Including Sofa) && In Matrix Range Place

    // If Sofa End is Left
    if (sofaPosition.endingCoordinate.col < sofaPosition.startingCoordinate.col)
    {
        int row = sofaStartRow + 1;
        int col = sofaStartCol;

        if (
            (sofaEndRow + 1 < rows && sofaStartRow + 1 < rows)                                                                    // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaEndRow + 1][sofaEndCol] != 'H' && houseThingsArrangementMatrix[row][col] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }
    // If Sofa Start is Left
    else
    {
        int row = sofaEndRow + 1;
        int col = sofaEndCol;

        if (
            (sofaEndRow + 1 < rows && sofaStartRow + 1 < rows)                                                                        // Inside Matrix or Not Condition
            && (houseThingsArrangementMatrix[sofaStartRow + 1][sofaStartCol] != 'H' && houseThingsArrangementMatrix[row][col] == '0') // Empty && Unvisited Place
        )
        {
            return true;
        }
    }

    return false;
}

bool isSofaPositionInQueue(map<char, map<int, map<int, map<int, map<int, bool>>>>> &configPushedInQueueOrNotMapping, SofaPosition &sofa)
{
    int sofaStartRow = sofa.startingCoordinate.row;
    int sofaEndRow = sofa.endingCoordinate.row;

    int sofaStartColumn = sofa.startingCoordinate.col;
    int sofaEndColumn = sofa.endingCoordinate.col;

    char sofaOrientation = sofa.orientation;

    return configPushedInQueueOrNotMapping[sofaOrientation][sofaStartRow][sofaStartColumn][sofaEndRow][sofaEndColumn];
}

bool gotMinimumnMovesForCurrentConfig(map<char, map<int, map<int, map<int, map<int, pair<int, vector<string>>>>>>> &minMovesFromConfigurationMapping, SofaPosition &sofa)
{
    int sofaStartRow = sofa.startingCoordinate.row;
    int sofaEndRow = sofa.endingCoordinate.row;

    int sofaStartColumn = sofa.startingCoordinate.col;
    int sofaEndColumn = sofa.endingCoordinate.col;

    char sofaOrientation = sofa.orientation;
    if (minMovesFromConfigurationMapping[sofaOrientation][sofaStartRow][sofaStartColumn][sofaEndRow][sofaEndColumn].first < INT_MAX)
    {
        return true;
    }

    return false;
}

vector<Move> getPossibleMoves(vector<vector<char>> &houseThingsArrangementMatrix, int rows, int cols, SofaPosition &sofa)
{
    vector<Move> possibleMoves;

    Move horizontallyForward;
    Move horizontallyBackward;
    Move horizontallyUpward;
    Move horizontallyDownward;

    horizontallyForward.moveName = "Horizontally Forward";
    horizontallyForward.reverseMoveName = "Horizontally Backward";

    horizontallyBackward.moveName = "Horizontally Backward";
    horizontallyBackward.reverseMoveName = "Horizontally Forward";

    horizontallyUpward.moveName = "Horizontally Upward";
    horizontallyUpward.reverseMoveName = "Horizontally Downward";

    horizontallyDownward.moveName = "Horizontally Downward";
    horizontallyDownward.reverseMoveName = "Horizontally Upward";

    Move horizontallyRotateDownwardLeft;
    Move horizontallyRotateDownwardRight;
    Move horizontallyRotateUpwardLeft;
    Move horizontallyRotateUpwardRight;

    horizontallyRotateDownwardLeft.moveName = "Horizontally Rotate Downward Left";
    horizontallyRotateDownwardLeft.reverseMoveName = "Horizontally Rotate Upward Right";

    horizontallyRotateDownwardRight.moveName = "Horizontally Rotate Downward Right";
    horizontallyRotateDownwardRight.reverseMoveName = "Horizontally Rotate Upward Left";

    horizontallyRotateUpwardLeft.moveName = "Horizontally Rotate Upward Left";
    horizontallyRotateUpwardLeft.reverseMoveName = "Horizontally Rotate Downward Right";

    horizontallyRotateUpwardRight.moveName = "Horizontally Rotate Upward Right";
    horizontallyRotateUpwardRight.reverseMoveName = "Horizontally Rotate Downward Left";

    Move verticallyForward;
    Move verticallyBackward;
    Move verticallyUpward;
    Move verticallyDownward;

    verticallyForward.moveName = "Vertically Forward";
    verticallyForward.reverseMoveName = "Vertically Backward";

    verticallyBackward.moveName = "Vertically Backward";
    verticallyBackward.reverseMoveName = "Vertically Forward";

    verticallyUpward.moveName = "Vertically Upward";
    verticallyUpward.reverseMoveName = "Vertically Downward";

    verticallyDownward.moveName = "Vertically Downward";
    verticallyDownward.reverseMoveName = "Vertically Upward";

    Move verticallyRotateDownwardLeft;
    Move verticallyRotateDownwardRight;
    Move verticallyRotateUpwardLeft;
    Move verticallyRotateUpwardRight;

    verticallyRotateDownwardLeft.moveName = "Vertically Rotate Downward Left";
    verticallyRotateDownwardLeft.reverseMoveName = "Vertically Rotate Upward Right";

    verticallyRotateDownwardRight.moveName = "Vertically Rotate Downward Right";
    verticallyRotateDownwardRight.reverseMoveName = "Vertically Rotate Upward Left";

    verticallyRotateUpwardLeft.moveName = "Vertically Rotate Upward Left";
    verticallyRotateUpwardLeft.reverseMoveName = "Vertically Rotate Downward Right";

    verticallyRotateUpwardRight.moveName = "Vertically Rotate Upward Right";
    verticallyRotateUpwardRight.reverseMoveName = "Vertically Rotate Downward Left";

    // Intialize Moves
    if (sofa.orientation == 'v')
    {
        verticallyForward.startRowStep = 0;
        verticallyForward.startColStep = 1;
        verticallyForward.endRowStep = 0;
        verticallyForward.endColStep = 1;

        verticallyBackward.startRowStep = 0;
        verticallyBackward.startColStep = -1;
        verticallyBackward.endRowStep = 0;
        verticallyBackward.endColStep = -1;

        verticallyUpward.startRowStep = -1;
        verticallyUpward.startColStep = 0;
        verticallyUpward.endRowStep = -1;
        verticallyUpward.endColStep = 0;

        verticallyDownward.startRowStep = 1;
        verticallyDownward.startColStep = 0;
        verticallyDownward.endRowStep = 1;
        verticallyDownward.endColStep = 0;

        // If Sofa End Is Up
        if (sofa.endingCoordinate.row < sofa.startingCoordinate.row)
        {
            verticallyRotateDownwardLeft.startRowStep = 0;
            verticallyRotateDownwardLeft.startColStep = 0;
            verticallyRotateDownwardLeft.endRowStep = 1;
            verticallyRotateDownwardLeft.endColStep = -1;

            verticallyRotateDownwardRight.startRowStep = 0;
            verticallyRotateDownwardRight.startColStep = 0;
            verticallyRotateDownwardRight.endRowStep = 1;
            verticallyRotateDownwardRight.endColStep = 1;

            verticallyRotateUpwardLeft.startRowStep = -1;
            verticallyRotateUpwardLeft.startColStep = -1;
            verticallyRotateUpwardLeft.endRowStep = 0;
            verticallyRotateUpwardLeft.endColStep = 0;

            verticallyRotateUpwardRight.startRowStep = -1;
            verticallyRotateUpwardRight.startColStep = 1;
            verticallyRotateUpwardRight.endRowStep = 0;
            verticallyRotateUpwardRight.endColStep = 0;
        }
        // Else Sofa Start Is Up
        else
        {

            verticallyRotateDownwardLeft.startRowStep = 1;
            verticallyRotateDownwardLeft.startColStep = -1;
            verticallyRotateDownwardLeft.endRowStep = 0;
            verticallyRotateDownwardLeft.endColStep = 0;

            verticallyRotateDownwardRight.startRowStep = 1;
            verticallyRotateDownwardRight.startColStep = 1;
            verticallyRotateDownwardRight.endRowStep = 0;
            verticallyRotateDownwardRight.endColStep = 0;

            verticallyRotateUpwardLeft.startRowStep = 0;
            verticallyRotateUpwardLeft.startColStep = 0;
            verticallyRotateUpwardLeft.endRowStep = -1;
            verticallyRotateUpwardLeft.endColStep = -1;

            verticallyRotateUpwardRight.startRowStep = 0;
            verticallyRotateUpwardRight.startColStep = 0;
            verticallyRotateUpwardRight.endRowStep = -1;
            verticallyRotateUpwardRight.endColStep = 1;
        }
    }

    if (sofa.orientation == 'h')
    {
        horizontallyForward.startRowStep = 0;
        horizontallyForward.startColStep = 1;
        horizontallyForward.endRowStep = 0;
        horizontallyForward.endColStep = 1;

        horizontallyBackward.startRowStep = 0;
        horizontallyBackward.startColStep = -1;
        horizontallyBackward.endRowStep = 0;
        horizontallyBackward.endColStep = -1;

        horizontallyUpward.startRowStep = -1;
        horizontallyUpward.startColStep = 0;
        horizontallyUpward.endRowStep = -1;
        horizontallyUpward.endColStep = 0;

        horizontallyDownward.startRowStep = 1;
        horizontallyDownward.startColStep = 0;
        horizontallyDownward.endRowStep = 1;
        horizontallyDownward.endColStep = 0;

        // If Sofa End Is Left
        if (sofa.endingCoordinate.col < sofa.startingCoordinate.col)
        {
            horizontallyRotateDownwardLeft.startRowStep = 1;
            horizontallyRotateDownwardLeft.startColStep = -1;
            horizontallyRotateDownwardLeft.endRowStep = 0;
            horizontallyRotateDownwardLeft.endColStep = 0;

            horizontallyRotateDownwardRight.startRowStep = 0;
            horizontallyRotateDownwardRight.startColStep = 0;
            horizontallyRotateDownwardRight.endRowStep = 1;
            horizontallyRotateDownwardRight.endColStep = 1;

            horizontallyRotateUpwardLeft.startRowStep = -1;
            horizontallyRotateUpwardLeft.startColStep = -1;
            horizontallyRotateUpwardLeft.endRowStep = 0;
            horizontallyRotateUpwardLeft.endColStep = 0;

            horizontallyRotateUpwardRight.startRowStep = 0;
            horizontallyRotateUpwardRight.startColStep = 0;
            horizontallyRotateUpwardRight.endRowStep = -1;
            horizontallyRotateUpwardRight.endColStep = 1;
        }
        // Else Sofa Start Is Left
        else
        {
            horizontallyRotateDownwardLeft.startRowStep = 0;
            horizontallyRotateDownwardLeft.startColStep = 0;
            horizontallyRotateDownwardLeft.endRowStep = 1;
            horizontallyRotateDownwardLeft.endColStep = -1;

            horizontallyRotateDownwardRight.startRowStep = 1;
            horizontallyRotateDownwardRight.startColStep = 1;
            horizontallyRotateDownwardRight.endRowStep = 0;
            horizontallyRotateDownwardRight.endColStep = 0;

            horizontallyRotateUpwardLeft.startRowStep = 0;
            horizontallyRotateUpwardLeft.startColStep = 0;
            horizontallyRotateUpwardLeft.endRowStep = -1;
            horizontallyRotateUpwardLeft.endColStep = -1;

            horizontallyRotateUpwardRight.startRowStep = -1;
            horizontallyRotateUpwardRight.startColStep = 1;
            horizontallyRotateUpwardRight.endRowStep = 0;
            horizontallyRotateUpwardRight.endColStep = 0;
        }
    }

    // Check For Possible Moves For Vertical Orientation and Push into Possible Moves Vector
    if (sofa.orientation == 'v')
    {
        if (canMoveVerticallyForward(houseThingsArrangementMatrix, rows, cols, sofa))
        {
            possibleMoves.push_back(verticallyForward);
        }

        if (canMoveVerticallyBackward(houseThingsArrangementMatrix, rows, cols, sofa))
        {
            possibleMoves.push_back(verticallyBackward);
        }

        if (canMoveVerticallyUpward(houseThingsArrangementMatrix, rows, cols, sofa))
        {
            possibleMoves.push_back(verticallyUpward);
        }

        if (canMoveVerticallyDownward(houseThingsArrangementMatrix, rows, cols, sofa))
        {
            possibleMoves.push_back(verticallyDownward);
        }

        if (canVerticallyRotateDownwardLeft(houseThingsArrangementMatrix, rows, cols, sofa))
        {
            possibleMoves.push_back(verticallyRotateDownwardLeft);
        }

        if (canVerticallyRotateDownwardRight(houseThingsArrangementMatrix, rows, cols, sofa))
        {
            possibleMoves.push_back(verticallyRotateDownwardRight);
        }

        if (canVerticallyRotateUpwardLeft(houseThingsArrangementMatrix, rows, cols, sofa))
        {
            possibleMoves.push_back(verticallyRotateUpwardLeft);
        }

        if (canVerticallyRotateUpwardRight(houseThingsArrangementMatrix, rows, cols, sofa))
        {
            possibleMoves.push_back(verticallyRotateUpwardRight);
        }
    }

    // Check For Possible Moves For Horizontal Orientation and Push into Possible Moves Vector
    if (sofa.orientation == 'h')
    {
        if (canMoveHorizontallyForward(houseThingsArrangementMatrix, rows, cols, sofa))
        {
            possibleMoves.push_back(horizontallyForward);
        }

        if (canMoveHorizontallyBackward(houseThingsArrangementMatrix, rows, cols, sofa))
        {
            possibleMoves.push_back(horizontallyBackward);
        }

        if (canMoveHorizontallyUpward(houseThingsArrangementMatrix, rows, cols, sofa))
        {
            possibleMoves.push_back(horizontallyUpward);
        }

        if (canMoveHorizontallyDownward(houseThingsArrangementMatrix, rows, cols, sofa))
        {
            possibleMoves.push_back(horizontallyDownward);
        }

        if (canHorizontallyRotateDownwardLeft(houseThingsArrangementMatrix, rows, cols, sofa))
        {
            possibleMoves.push_back(horizontallyRotateDownwardLeft);
        }

        if (canHorizontallyRotateDownwardRight(houseThingsArrangementMatrix, rows, cols, sofa))
        {
            possibleMoves.push_back(horizontallyRotateDownwardRight);
        }

        if (canHorizontallyRotateUpwardLeft(houseThingsArrangementMatrix, rows, cols, sofa))
        {
            possibleMoves.push_back(horizontallyRotateUpwardLeft);
        }

        if (canHorizontallyRotateUpwardRight(houseThingsArrangementMatrix, rows, cols, sofa))
        {
            possibleMoves.push_back(horizontallyRotateUpwardRight);
        }
    }

    return possibleMoves;
}

void pushInConfigurationQueue(map<char, map<int, map<int, map<int, map<int, bool>>>>> &configPushedInQueueOrNotMapping, queue<SofaPosition> &configurationQueue, SofaPosition &sofa){

    if (isSofaPositionInQueue(configPushedInQueueOrNotMapping, sofa))
    {
        return;
    }
    

    int sofaStartRow = sofa.startingCoordinate.row;
    int sofaEndRow = sofa.endingCoordinate.row;

    int sofaStartColumn = sofa.startingCoordinate.col;
    int sofaEndColumn = sofa.endingCoordinate.col;

    char sofaOrientation = sofa.orientation;


    SofaPosition sofaEndStartSwapPosition;
    sofaEndStartSwapPosition.orientation = sofaOrientation;

    sofaEndStartSwapPosition.startingCoordinate.row = sofaEndRow;
    sofaEndStartSwapPosition.startingCoordinate.col = sofaEndColumn;

    sofaEndStartSwapPosition.endingCoordinate.row = sofaStartRow;
    sofaEndStartSwapPosition.endingCoordinate.col = sofaStartColumn;

    // Push In Queue
    configurationQueue.push(sofa);
    configurationQueue.push(sofaEndStartSwapPosition);

    // Mark Pushed in Queue == True For Sofa configurations
    configPushedInQueueOrNotMapping[sofaOrientation][sofaStartRow][sofaStartColumn][sofaEndRow][sofaEndColumn] = true;
    configPushedInQueueOrNotMapping[sofaOrientation][sofaEndRow][sofaEndColumn][sofaStartRow][sofaStartColumn] = true;

    cout << "Pushed Sofa: ";
    printSofa(sofa);
    cout << " in Queue." << endl;

}

void takeMove(SofaPosition &sofa, Move &move)
{
    sofa.startingCoordinate.row = sofa.startingCoordinate.row + move.startRowStep;
    sofa.startingCoordinate.col = sofa.startingCoordinate.col + move.startColStep;

    sofa.endingCoordinate.row = sofa.endingCoordinate.row + move.endRowStep;
    sofa.endingCoordinate.col = sofa.endingCoordinate.col + move.endColStep;

    // After Taking move Reset Orientation
    sofa.resetOrientation();

    return;
}

void reverseMove(SofaPosition &sofa, Move &move)
{
    sofa.startingCoordinate.row = sofa.startingCoordinate.row - move.startRowStep;
    sofa.startingCoordinate.col = sofa.startingCoordinate.col - move.startColStep;

    sofa.endingCoordinate.row = sofa.endingCoordinate.row - move.endRowStep;
    sofa.endingCoordinate.col = sofa.endingCoordinate.col - move.endColStep;

    // After Reversing move Reset Orientation
    sofa.resetOrientation();

    return;
}

void processNewSofaPosition(map<char, map<int, map<int, map<int, map<int, pair<int, vector<string>>>>>>> &minMovesFromConfigurationMapping, map<char, map<int, map<int, map<int, map<int, bool>>>>> &configPushedInQueueOrNotMapping, SofaPosition &sofaPosition, bool &pushedConfigurationInQueue, bool &updatedMinMoves, int &minimumMoves, queue<SofaPosition> &configurationQueue, Move &moveTaken, Move &gotMinPathConfigurationFromMove)
{
    cout << "Inside processNewSofaPosition() " << " -> " << moveTaken.moveName << endl;
    int sofaStartRow = sofaPosition.startingCoordinate.row;
    int sofaEndRow = sofaPosition.endingCoordinate.row;

    int sofaStartColumn = sofaPosition.startingCoordinate.col;
    int sofaEndColumn = sofaPosition.endingCoordinate.col;

    char sofaOrientation = sofaPosition.orientation;

    /*

    - Case 1: Not Inside Queue && Not Inside minMovesFromConfigurationMapping
                Is Configuration ko Queue mein Daal do Aur pushedInQueue = true

    - Case 2: Not Inside Queue && Inside minMovesFromConfigurationMapping
            Is Configuration ke MinMoves + 1 se update kardo minMoves ko if minMoves > Is Configuration ke MinMoves + 1 aur phir updatedMinMoves = true

    - Case 3: Inside Queue && Not Inside minMovesFromConfigurationMapping
            Is Configuration ke liye Sirf pushedInQueue = true karna hai actual push in Queue nahin karna hai

    - Case 4: Inside Queue && Inside minMovesFromConfigurationMapping
            Is Configuration ke MinMoves + 1 se update kardo minMoves ko if minMoves > Is Configuration ke MinMoves + 1 aur phir updatedMinMoves = true

    */

    bool inQueue = isSofaPositionInQueue(configPushedInQueueOrNotMapping, sofaPosition);
    bool gotMinMoves = gotMinimumnMovesForCurrentConfig(minMovesFromConfigurationMapping, sofaPosition);

    int minimovesFromThisConfiguration = minMovesFromConfigurationMapping[sofaOrientation][sofaStartRow][sofaStartColumn][sofaEndRow][sofaEndColumn].first;

    if (inQueue == false && gotMinMoves == false)
    {
        pushInConfigurationQueue(configPushedInQueueOrNotMapping, configurationQueue,sofaPosition);
        pushedConfigurationInQueue = true;
    }
    else if (inQueue == false && gotMinMoves == true)
    {
        updatedMinMoves = true;
        if(minimumMoves > minimovesFromThisConfiguration + 1) {
            minimumMoves = minimovesFromThisConfiguration + 1;
            gotMinPathConfigurationFromMove = moveTaken;
        }

        cout << "Updated Min Moves: " << minimumMoves << " and now " << gotMinPathConfigurationFromMove.moveName << endl;
    }
    else if (inQueue == true && gotMinMoves == false)
    {
        pushedConfigurationInQueue = true;
    }
    else if (inQueue == true && gotMinMoves == true)
    {
        updatedMinMoves = true;
        if(minimumMoves > minimovesFromThisConfiguration + 1) {
            minimumMoves = minimovesFromThisConfiguration + 1;
            gotMinPathConfigurationFromMove = moveTaken;
        }

        cout << "Updated Min Moves: " << minimumMoves << " and now " << gotMinPathConfigurationFromMove.moveName << endl;
    }
}

void processMove(vector<vector<char>> &houseThingsArrangementMatrix, int rows, int cols, SofaPosition &sofa, Move &move, map<char, map<int, map<int, map<int, map<int, pair<int, vector<string>>>>>>> &minMovesFromConfigurationMapping, map<char, map<int, map<int, map<int, map<int, bool>>>>> &configPushedInQueueOrNotMapping, bool &pushedConfigurationInQueue, bool &updatedMinMoves, int &minimumMoves, queue<SofaPosition> &configurationQueue, Move &gotMinPathFromMove)
{
    // Assumes only Possible Moves As Input
    takeMove(sofa, move);
    processNewSofaPosition(minMovesFromConfigurationMapping, configPushedInQueueOrNotMapping, sofa, pushedConfigurationInQueue, updatedMinMoves, minimumMoves, configurationQueue, move, gotMinPathFromMove);
    reverseMove(sofa, move);
}


void updateEntryForConfigurationInMinMoveMap(map<char, map<int, map<int, map<int, map<int, pair<int, vector<string>>>>>>> &minMovesFromConfigurationMapping, SofaPosition &sofa, int &minimumMoves, vector<string> &minPath){
    cout << "Updating in Map for sofa: ";
    printSofa(sofa);
    cout << "Minimum Moves are: " << minimumMoves << " and path is: ";
    for(auto i : minPath) {
        cout << i << " -> ";
    }
    cout << endl;

    int sofaStartRow = sofa.startingCoordinate.row;
    int sofaEndRow = sofa.endingCoordinate.row;

    int sofaStartColumn = sofa.startingCoordinate.col;
    int sofaEndColumn = sofa.endingCoordinate.col;

    char sofaOrientation = sofa.orientation;

    minMovesFromConfigurationMapping[sofaOrientation][sofaStartRow][sofaStartColumn][sofaEndRow][sofaEndColumn] = make_pair(minimumMoves, minPath);
    minMovesFromConfigurationMapping[sofaOrientation][sofaEndRow][sofaEndColumn][sofaStartRow][sofaStartColumn] = make_pair(minimumMoves, minPath);

    cout << "Now for sofa and Sofa Reverse: " << minMovesFromConfigurationMapping[sofaOrientation][sofaStartRow][sofaStartColumn][sofaEndRow][sofaEndColumn].first << " - " << minMovesFromConfigurationMapping[sofaOrientation][sofaEndRow][sofaEndColumn][sofaStartRow][sofaStartColumn].first << endl;;
    
}


bool isPossibleToMoveSofa(vector<vector<char>> &houseThingsArrangementMatrix, int rows, int cols, vector<string> &movesPathToMoveSofaToDestination, SofaPosition &sofaStartPosition, SofaPosition &sofaEndPosition)
{

    cout << "\n\n Inside isPossibleToMoveSofa() " << endl;

    cout << "Sofa Start is: " << sofaStartPosition.orientation << "[" <<  sofaStartPosition.startingCoordinate.row << ", " << sofaStartPosition.startingCoordinate.col << "] [" << sofaStartPosition.endingCoordinate.row << ", " << sofaStartPosition.endingCoordinate.col << "]" << endl;

    cout << "Sofa End is: " << sofaEndPosition.orientation << "[" <<  sofaEndPosition.startingCoordinate.row << ", " << sofaEndPosition.startingCoordinate.col << "] [" << sofaEndPosition.endingCoordinate.row << ", " << sofaEndPosition.endingCoordinate.col << "]" << endl;

    // If Moved At Right Place Then return true
    if (isSofaMoved(sofaStartPosition, sofaEndPosition))
    {
        movesPathToMoveSofaToDestination = movesPathToMoveSofaToDestination;
        return true;
    }


    // First Of all Sofa End Position ko minMovesFromConfigurationMapping mein daalo

    /*
    minMovesFromConfigurationMapping[Orientation][SofaStartRow][SofaStartColumn][SofaEndRow][SofaEndColumn] = pair<MinimumMoves,MinMovesPath>
    configPushedInQueueOrNotMapping[Orientation][SofaStartRow][SofaStartColumn][SofaEndRow][SofaEndColumn] = true or false
    Where,
    - Orientation can be 'h' or 'v'
    - 0 < SofaStartRow,SofaEndRow < M
    - 0 < SofaStartColumn,SofaEndColumn < N
    - 0 < MinimumMoves < INT_MAX
    - MinMovesPath this will be vector of moves and stores moves

    */
    map<char, map<int, map<int, map<int, map<int, pair<int, vector<string>>>>>>> minMovesFromConfigurationMapping;
    map<char, map<int, map<int, map<int, map<int, bool>>>>> configPushedInQueueOrNotMapping;

    vector<char> possibleSofaOrientations = getPossibleSofaOrientations();
    cout << "Got Possible Orientations: ";
    for(auto i : possibleSofaOrientations) {
        cout << i << " ";
    }
    cout << endl;

    int minimumMoves = INT_MAX;
    vector<string> minMovesPath;

    // Initially Mark All States as Un Pushed in Queue and Also Mark That No Possible Orientation from which we can go to the Destination
    for (auto sofaOrientation : possibleSofaOrientations)
    {
        for (int sofaStartRow = 0; sofaStartRow < rows; sofaStartRow++)
        {
            for (int sofaStartColumn = 0; sofaStartColumn < cols; sofaStartColumn++)
            {
                for (int sofaEndRow = 0; sofaEndRow < rows; sofaEndRow++)
                {
                    for (int sofaEndColumn = 0; sofaEndColumn < cols; sofaEndColumn++)
                    {
                        configPushedInQueueOrNotMapping[sofaOrientation][sofaStartRow][sofaStartColumn][sofaEndRow][sofaEndColumn] = false;
                        configPushedInQueueOrNotMapping[sofaOrientation][sofaEndRow][sofaEndColumn][sofaStartRow][sofaStartColumn] = false;

                        minMovesFromConfigurationMapping[sofaOrientation][sofaStartRow][sofaStartColumn][sofaEndRow][sofaEndColumn] = make_pair(minimumMoves, minMovesPath);
                        minMovesFromConfigurationMapping[sofaOrientation][sofaEndRow][sofaEndColumn][sofaStartRow][sofaStartColumn] = make_pair(minimumMoves, minMovesPath);
                    }
                }
            }
        }
    }

    int sofaStartRow = sofaEndPosition.startingCoordinate.row;
    int sofaEndRow = sofaEndPosition.endingCoordinate.row;

    int sofaStartColumn = sofaEndPosition.startingCoordinate.col;
    int sofaEndColumn = sofaEndPosition.endingCoordinate.col;

    char sofaOrientation = sofaEndPosition.orientation;

    bool pushedAfterPossibleMoveConfigurationInQueue = false;
    bool updatedMinMoves = false;

    vector<string> moves;

    int row;
    int col;

    queue<SofaPosition> configurationQueue;

    SofaPosition sofaPosition = sofaEndPosition;

    // Make An Entry in the Mapping
    minimumMoves = 0;
    minMovesFromConfigurationMapping[sofaOrientation][sofaStartRow][sofaStartColumn][sofaEndRow][sofaEndColumn] = make_pair(minimumMoves, minMovesPath);
    minMovesFromConfigurationMapping[sofaOrientation][sofaEndRow][sofaEndColumn][sofaStartRow][sofaStartColumn] = make_pair(minimumMoves, minMovesPath);

    // Push Into Queue
    pushInConfigurationQueue(configPushedInQueueOrNotMapping, configurationQueue, sofaPosition);

    /*
    For Sofa End Position Process All Possible Moves For it
    */
    vector<Move> possibleMovesForEndPosition = getPossibleMoves(houseThingsArrangementMatrix, rows, cols, sofaEndPosition);
    cout << "Got Possible Moves For SOfa End Position: ";
    for(auto i : possibleMovesForEndPosition){
        cout << i.moveName << " | ";
    }
    cout << endl;

    for(auto move : possibleMovesForEndPosition) {
        // Simply Push The Configuration into Queue and Let Them Process Later in Loop

        // After Taking Move Configuration
        takeMove(sofaEndPosition, move);

        // Push Configuration In Queue
        pushInConfigurationQueue(configPushedInQueueOrNotMapping, configurationQueue, sofaEndPosition);

        // After Reversing the Move Configuration
        reverseMove(sofaEndPosition, move);
    }

    cout << "Starting Loop: " << endl;
    while (configurationQueue.empty() == false)
    {
        // Extract Queue's Front's Configuration
        sofaPosition = configurationQueue.front();
        configurationQueue.pop();

        cout << "\n\nIn Loop Extracted sofa: ";
        printSofa(sofaPosition);

        // If Already got the minimum moves for this Configuration then No need to traverse
        sofaStartRow = sofaPosition.startingCoordinate.row;
        sofaEndRow = sofaPosition.endingCoordinate.row;

        sofaStartColumn = sofaPosition.startingCoordinate.col;
        sofaEndColumn = sofaPosition.endingCoordinate.col;

        sofaOrientation = sofaPosition.orientation;

        pushedAfterPossibleMoveConfigurationInQueue = false;
        updatedMinMoves = false;
        minimumMoves = INT_MAX;

        Move gotMinimumPathFromMove;
        vector<string> minimumMovesPath;

        if (gotMinimumnMovesForCurrentConfig(minMovesFromConfigurationMapping, sofaPosition) == true)
        {
            cout << "Since the sofa already got minimium moves: " <<  minMovesFromConfigurationMapping[sofaOrientation][sofaStartRow][sofaStartColumn][sofaEndRow][sofaEndColumn].first  << " and path is: ";

            for(auto i : minMovesFromConfigurationMapping[sofaOrientation][sofaStartRow][sofaStartColumn][sofaEndRow][sofaEndColumn].second){
                cout << i << " -> ";
            }

            cout << " thus continuing loop for sofa: ";
            printSofa(sofaPosition);
            cout << endl;
            continue;
        }

        vector<Move> possibleMoves = getPossibleMoves(houseThingsArrangementMatrix, rows, cols, sofaPosition);
        cout << "Got Possible moves: ";
        for(auto i : possibleMoves){
            cout << i.moveName << "| ";
        }
        cout << endl;

        for (auto move : possibleMoves)
        {

            processMove(houseThingsArrangementMatrix, rows, cols, sofaPosition, move, minMovesFromConfigurationMapping, configPushedInQueueOrNotMapping, pushedAfterPossibleMoveConfigurationInQueue, updatedMinMoves, minimumMoves, configurationQueue, gotMinimumPathFromMove);
        }

        /*

        - Now Check if updatedMinMoves == true
            - Make a new Entry of Queue's Front's Configuration in minMovesFromConfigurationMapping aur iske MinMoves = minMoves
        - Else if case mein check if pushedInQueue == true to vaapis se is configuration ko Queue mein push karo
        - Else case mein
            - Make a new Entry of Queue's Front's Configuration in minMovesFromConfigurationMapping aur iske MinMoves = minMoves (Since it is not updated thus will going to store INT_MAX depicting not possible to reach end however ye case kabhi banega nahin kyonki ham possible configurations ko hi push kar rahe hain)
        */
        if (updatedMinMoves == true)
        {
            cout << "Case 1: Updated Moves == True " << minimumMoves << endl;   
            // Make minimum path vector by adding move's name and the path of configuration which took us to destination 
            minimumMovesPath.push_back(gotMinimumPathFromMove.moveName);
            
            // Find Path of Configuration After Taking Minimum Path
            takeMove(sofaPosition, gotMinimumPathFromMove);
            cout << "After Taking Move sofa: ";
            printSofa(sofaPosition);
            
            // Add Path in minimum path move
            for(auto move : minMovesFromConfigurationMapping[sofaPosition.orientation][sofaPosition.startingCoordinate.row][sofaPosition.startingCoordinate.col][sofaPosition.endingCoordinate.row][sofaPosition.endingCoordinate.col].second){
                minimumMovesPath.push_back(move);
            }

            // Get Current Configuration Again After Reversing Minimum Path move
            reverseMove(sofaPosition, gotMinimumPathFromMove); 
            cout << "After Reversing Move sofa: ";
            printSofa(sofaPosition);

            cout << "Value of Minimum moves: " << minimumMoves << endl;
            for(auto i : minimumMovesPath) {
                cout << i << " -> ";
            }
            cout << endl;
            
            // Update Entry for Current Configuration
            updateEntryForConfigurationInMinMoveMap(minMovesFromConfigurationMapping, sofaPosition, minimumMoves, minimumMovesPath);
        }
        else if(pushedAfterPossibleMoveConfigurationInQueue == true) {
            cout << "Case 2: Pushed in Queue Only == True " << endl;   

            // Push Into Queue as We doesn't get minimum path updated and also some previous possible configurations which could let us to destination in minimum path are in Queue so let them process first
            pushInConfigurationQueue(configPushedInQueueOrNotMapping, configurationQueue, sofaPosition);
        }
        else{
            cout << "Case 3: Else Case" << endl;   

            // Update Entry for Current Configuration
            updateEntryForConfigurationInMinMoveMap(minMovesFromConfigurationMapping, sofaPosition, minimumMoves, minimumMovesPath);
        }
    }

    cout << "Ending Loop: " << endl;



    /*
    - Push Possible Positions from which it can reach to Sofa End Position
    - if ek configuration koi move lekar end par aati hai to uska exact ulta move lekar ham us configuration par vaapis ja sakte hain jaise:
        - 0 s s 0 se hamen 0 0 s s jan ho to ham Horizontally Forward jayenge to ham 0 0 s s se vaapis 0 s s 0 Horizontally Backward lekar ja sakte hain to kyonki ham log backward traverse kar rahe hain to ham ulta karke push karenge cheejon ko haalaanki code se lag sakta hai sab seedha hai but hai nahin

    */

    // Case 1: Horizontally Forward
    // Case 2: Horizontally Backward
    // Case 3: Horizontally Upward
    // Case 4: Horizontally Downward

    // Case 5: Horizontally Rotate Downward Left
    // Case 6: Horizontally Rotate Downward Right
    // Case 7: Horizontally Rotate Upward Left
    // Case 8: Horizontally Rotate Upward Right

    // Case 9: Vertically Forward
    // Case 10: Vertically Backward
    // Case 11: Vertically Upward
    // Case 12: Vertically Downward

    // Case 13: Vertically Rotate Downward Left
    // Case 14: Vertically Rotate Downward Right
    // Case 15: Vertically Rotate Upward Left
    // Case 16: Vertically Rotate Upward Right

    // Phir Queue ko initialise karo Sofa End Position ke possible moves ki Configurations se
    /*
    - Phir ek while loop chalao jab tak Queue empty na ho jaye phir loop ke andar pop karo configuration jismein in cases ko handle karo

    - Agar Queue's Front's Configuration Already in minMovesFromConfigurationMapping to ignore and continue next iteration of loop

    - Queue's Front's Configuration's Ke Possible Moves ke liye ye cases banenge
    - Ek " pushedInQueue " naam ka Flag Banao jo batayega Queue mein push piya kuchh yaa nahin
    - " minMoves " naam ka int variable banao jo store karega moves to reach End Position from Queue's Front's Configuration
    - Ek " updatedMinMoves " naam ka Flag Aur Banao jo batayega ki minMovesFromConfigurationMapping mein se koi configuration se minMoves update hua hai

    - Starting mein
        - pushedInQueue = false
        - updatedMinMoves = false
        - minMoves = INT_MAX

    - Now Run For Possible Moves
        - Case 1: Not Inside Queue && Not Inside minMovesFromConfigurationMapping
                Is Configuration ko Queue mein Daal do Aur pushedInQueue = true

        - Case 2: Not Inside Queue && Inside minMovesFromConfigurationMapping
                Is Configuration ke MinMoves + 1 se update kardo minMoves ko if minMoves > Is Configuration ke MinMoves + 1 aur phir updatedMinMoves = true

        - Case 3: Inside Queue && Not Inside minMovesFromConfigurationMapping
                Is Configuration ke liye Sirf pushedInQueue = true karna hai actual push in Queue nahin karna hai

        - Case 4: Inside Queue && Inside minMovesFromConfigurationMapping
                Is Configuration ke MinMoves + 1 se update kardo minMoves ko if minMoves > Is Configuration ke MinMoves + 1 aur phir updatedMinMoves = true

    - Now Check if updatedMinMoves == true
        - Make a new Entry of Queue's Front's Configuration in minMovesFromConfigurationMapping aur iske MinMoves = minMoves
    - Else if case mein check if pushedInQueue == true to vaapis se is configuration ko Queue mein push karo
    - Else case mein
        - Make a new Entry of Queue's Front's Configuration in minMovesFromConfigurationMapping aur iske MinMoves = minMoves (Since it is not updated thus will going to store INT_MAX depicting not possible to reach end however ye case kabhi banega nahin kyonki ham possible configurations ko hi push kar rahe hain)


    */

    if (gotMinimumnMovesForCurrentConfig(minMovesFromConfigurationMapping, sofaStartPosition))
    {
        movesPathToMoveSofaToDestination = minMovesFromConfigurationMapping[sofaStartPosition.orientation][sofaStartPosition.startingCoordinate.row][sofaStartPosition.startingCoordinate.col][sofaStartPosition.endingCoordinate.row][sofaStartPosition.endingCoordinate.col].second;

        cout << "Now Returning from isPossible() and this is the minimum path for sofa: ";
        printSofa(sofaStartPosition);

        for(auto i : movesPathToMoveSofaToDestination) {
            cout << i << " -> ";
        }
        cout << endl;

        return true;
    }
    
    cout << "No Possible Moves Found thus going back --------->" << endl
         << endl;
    return false;
}

int findTotalMovesToMoveSofaToDestination(vector<vector<char>> houseThingsArrangementMatrix, int rows, int cols)
{

    // Sofa is not Present Say Impossible to Move
    SofaPosition sofaStartPosition = findSofaCurrentPosition(houseThingsArrangementMatrix, rows, cols);

    if (sofaStartPosition.startingCoordinate.row == -1 || sofaStartPosition.endingCoordinate.row == -1)
    {
        return -1;
    }

    SofaPosition sofaEndPosition = findSofaDestinationPosition(houseThingsArrangementMatrix, rows, cols);

    // Sofa Already at correct place
    if (sofaEndPosition.startingCoordinate.row == -1)
    {
        return 0;
    }

    // Sofa correct place is not defined correctly
    if (sofaEndPosition.endingCoordinate.row == -1)
    {
        return -1;
    }

    // Make Sofa Start and Destination as Unvisited and Empty Place
    houseThingsArrangementMatrix[sofaStartPosition.startingCoordinate.row][sofaStartPosition.startingCoordinate.col] = '0';
    houseThingsArrangementMatrix[sofaStartPosition.endingCoordinate.row][sofaStartPosition.endingCoordinate.col] = '0';

    houseThingsArrangementMatrix[sofaEndPosition.startingCoordinate.row][sofaEndPosition.startingCoordinate.col] = '0';
    houseThingsArrangementMatrix[sofaEndPosition.endingCoordinate.row][sofaEndPosition.endingCoordinate.col] = '0';

    // int moves = 0;
    vector<string> moves;
    bool moved = isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, moves, sofaStartPosition, sofaEndPosition);

    // Make Sofa Start and Destination Visible Again
    houseThingsArrangementMatrix[sofaStartPosition.startingCoordinate.row][sofaStartPosition.startingCoordinate.col] = 's';
    houseThingsArrangementMatrix[sofaStartPosition.endingCoordinate.row][sofaStartPosition.endingCoordinate.col] = 's';

    houseThingsArrangementMatrix[sofaEndPosition.startingCoordinate.row][sofaEndPosition.startingCoordinate.col] = 'S';
    houseThingsArrangementMatrix[sofaEndPosition.endingCoordinate.row][sofaEndPosition.endingCoordinate.col] = 'S';

    if (moved == true)
    {
        cout << "Bhai moved == " << moved << " and  moves.size() == " << moves.size() << endl
             << endl;
        int minimumMoves = 0;

        int minSize = moves.size();
        
        minimumMoves = minSize;
        cout << "Minimum Moves required are " << minimumMoves << " and path is: ";
        for (auto move : moves)
        {
            cout << move << " -> ";
        }
        cout << " Destination Reached." << endl
             << endl;
        return minimumMoves;
    }

    return -1;
}

int main()
{
    int rows;
    int cols;

    cin >> rows;
    cin >> cols;

    vector<vector<char>> houseThingsArrangementMatrix(rows, vector<char>(cols));

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            cin >> houseThingsArrangementMatrix[row][col];
        }
    }

    cout << "Printing: " << endl;

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            cout << houseThingsArrangementMatrix[row][col] << " ";
        }
        cout << endl;
    }

    cout << "Printing Sofa: " << endl;
    SofaPosition sofa = findSofaDestinationPosition(houseThingsArrangementMatrix, rows, cols);
    string str = isVerticalOrientationOfSofa(sofa) ? "Vertical" : "Horizontal";
    cout << "Sofa is at " << sofa.startingCoordinate.row << "," << sofa.startingCoordinate.col << " - " << sofa.endingCoordinate.row << "," << sofa.endingCoordinate.col << " and it is " << str << endl;

    cout << "Printing Moves to Move Sofa: " << endl;

    int totalMovesToMoveSofa = findTotalMovesToMoveSofaToDestination(houseThingsArrangementMatrix, rows, cols);
    if (totalMovesToMoveSofa == -1)
    {
        cout << "Impossible" << endl;
    }
    else
    {
        cout << totalMovesToMoveSofa << endl;
    }

    return 0;
}

/*


You Bought a new Flat Congrats!! Rich Richer Ever Growing Friend.
You Shifted your all old household things from your old flat to new one and what you see now you casually putted your sofa somewhere at your flat but now you noticed that sofa should be some other place. You are a coding expert and you have mapped your flat as a matrix representation to save time and energy you decided to first get moves to move sofa at that place and also to even see if it is possible to move sofa there. So your household things are represented by 'H' and your flat's empty space represented by '0' and your sofa is of length 2 and represented by 's' and your desired location to put your sofa is also of length 2 and represented by 'S'. You are rich and bought a quality sofa and it is too heavy so that it cannot be lifted it can be just moved forward, backward, upward, downward or rotated and for it's rotation it requires 2*2 space just like:

s s
0 0

then it can be rotated to get:

0 s
0 s

or

s 0
s 0

similarly for initial vertical configuration of sofa. You decided to not move your household things while doing this sofa adjustment and you have to be very sure whether that desired place is feasible to get your sofa there or not. You have to now code a program in any language which will solve the problem.

You have to take input as:

First line will have space seperated M,N where M and N represents the rows and cols of matrix respectively and followed by M lines which will have N space seperated characters which may contain s, S, H, 0 where s, S, H, 0 represents the sofa current position, sofa desired location, household things, empty space respectively. You can consider S places as empty place as there we have to put the sofa right! Go ahead and make some solution.

You have to give output as:
Either Say "n" moves if possible to move sofa or say "Impossible" if not possible to move sofa.



----------------------------------------------

Input 1:

5 5
s s 0 0 0
0 H 0 0 H
0 H 0 H H
0 H 0 0 H
0 0 0 S S

Output: 8

Explanation:
There will be 8 Moves which will put sofa at correct place

s s 0 0 0           0 s s 0 0           0 0 s s 0           0 0 s 0 0           0 0 0 0 0           0 0 0 0 0           0 0 0 0 0           0 0 0 0 0           0 0 0 0 0
0 H 0 0 H           0 H 0 0 H           0 H 0 0 H           0 H s 0 H           0 H s 0 H           0 H 0 0 H           0 H 0 0 H           0 H 0 0 H           0 H 0 0 H
0 H 0 H H           0 H 0 H H           0 H 0 H H           0 H 0 H H           0 H s H H           0 H s H H           0 H 0 H H           0 H 0 H H           0 H 0 H H
0 H 0 0 H           0 H 0 0 H           0 H 0 0 H           0 H 0 0 H           0 H 0 0 H           0 H s 0 H           0 H s 0 H           0 H 0 0 H           0 H 0 0 H
0 0 0 S S           0 0 0 S S           0 0 0 S S           0 0 0 S S           0 0 0 S S           0 0 0 S S           0 0 s S S           0 0 s s S           0 0 0 s s



----------------------------------------------

Input 2:

5 5
s s 0 H 0
0 H 0 0 H
0 H 0 H H
0 H 0 0 H
0 0 0 S S

Output:  Impossible

----------------------------------------------

Input 3:

5 5
H H H s s
0 S 0 0 0
H S H 0 H
0 0 0 H 0
H 0 H 0 0

Output:  Impossible

----------------------------------------------

Input 4:

7 7
s 0 0 0 0 0 0
s H H H 0 0 0
0 0 0 H 0 0 0
0 H 0 H 0 H 0
0 H 0 H 0 H 0
0 0 0 0 0 0 0
0 0 0 S S 0 0

Output:  9

----------------------------------------------

Input 5:

5 7
s s 0 0 0 0 0
H H H H H 0 0
0 0 0 0 0 0 0
0 H H H H H H
0 0 0 S S 0 0

Output:  Impossible

----------------------------------------------

Input 6:

8 8
s s 0 0 0 0 0 0
0 0 H H H H 0 0
0 H H H H H H 0
0 H H H H H H 0
0 H H H H H H 0
0 H H H H H H 0
S 0 H H H H 0 0
S 0 0 0 0 0 0 0


Output:  7

Explanation: There are two Possible cases with moving forward we can traverse it to destination this will take 21 moves or we can just rotate it first then go down and this will take 7 moves.

----------------------------------------------

Input 7:

5 5
H 0 0 0 H
0 H S S H
H H H H 0
0 H 0 0 H
H H 0 s s

Output:  Impossible

----------------------------------------------

Input 8:

5 5
H 0 0 S H
H 0 H S 0
H H 0 0 0
s H H H 0
s H 0 0 H

Output:  Impossible

----------------------------------------------

Input 9:

5 5
H H H H H
H H H H H
H H H H s
S H H H s
S H H H H

Output:  Impossible



*/