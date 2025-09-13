#include <iostream>
#include <queue>
#include <vector>
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
};

class ConfigInfo
{
public:
    vector<vector<char>> houseThingsArrangementMatrix;
    int rows;
    int cols;
    SofaPosition sofaPosition;
    vector<string> movesToReachCurrentConfiguration;
};

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

                return sofa;
            }
        }
    }

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

                return sofa;
            }
        }
    }

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

bool isPossibleToMoveSofaBFS(vector<vector<char>> &houseThingsArrangementMatrixForStart, int rows, int cols, vector<vector<string>> &movesPathToMoveSofa, vector<string> &movesForStart, SofaPosition &sofaPositionForStart, SofaPosition &sofaEndPosition)
{
    // If Moved At Right Place Then return true
    if (isSofaMoved(sofaPositionForStart, sofaEndPosition))
    {
        movesPathToMoveSofa.push_back(movesForStart);
        return true;
    }

    // Store current configuration and number of moves required to reach that configuration in a queue
    queue<ConfigInfo> configMovesQueue;

    // Make Current Config Info and push into queue
    ConfigInfo currentConfig;
    currentConfig.houseThingsArrangementMatrix = houseThingsArrangementMatrixForStart;
    currentConfig.rows = rows;
    currentConfig.cols = cols;
    currentConfig.movesToReachCurrentConfiguration = movesForStart;
    currentConfig.sofaPosition = sofaPositionForStart;

    configMovesQueue.push(currentConfig);

    while (configMovesQueue.empty() == false)
    {

        // Extract Current Configuration and then check if reached destination

        // Extracted Current Configuration
        currentConfig = configMovesQueue.front();
        configMovesQueue.pop();

        vector<string> moves = currentConfig.movesToReachCurrentConfiguration;
        vector<vector<char>> houseThingsArrangementMatrix = currentConfig.houseThingsArrangementMatrix;
        SofaPosition sofaPosition = currentConfig.sofaPosition;

        // Check If destination reached
        if (isSofaMoved(sofaPosition, sofaEndPosition))
        {
            movesPathToMoveSofa.push_back(moves);
        }

        // Check for Orientation and Push all Valid moves into the queue

        // Find Sofa Orientation and then decide moves
        bool sofaOrientationVertical = isVerticalOrientationOfSofa(sofaPosition);

        int row;
        int col;

        // Vertical Orientation Moves
        if (sofaOrientationVertical == true)
        {
            cout << "Running VERTICAL " << endl;
            // Vertically Upward
            if (canMoveVerticallyUpward(houseThingsArrangementMatrix, rows, cols, sofaPosition))
            {
                // If Sofa End Is Up
                if (sofaPosition.endingCoordinate.row < sofaPosition.startingCoordinate.row)
                {

                    // Mark Position as Visited
                    row = sofaPosition.startingCoordinate.row;
                    col = sofaPosition.startingCoordinate.col;

                    // Move Sofa Up
                    sofaPosition.endingCoordinate.row = sofaPosition.endingCoordinate.row - 1;
                    sofaPosition.startingCoordinate.row = sofaPosition.startingCoordinate.row - 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '1';
                    houseThingsArrangementMatrix[sofaPosition.endingCoordinate.row][sofaPosition.endingCoordinate.col] = 's';

                    // moves++;
                    moves.push_back("Vertically Upward");
                    cout << "__________Vertically Upward ->" << endl;
                    printHouseThingsArrangement(houseThingsArrangementMatrix, rows, cols, sofaPosition);

                    currentConfig.houseThingsArrangementMatrix = houseThingsArrangementMatrix;
                    currentConfig.movesToReachCurrentConfiguration = moves;
                    currentConfig.sofaPosition = sofaPosition;
                    configMovesQueue.push(currentConfig);

                    // Backtracking from here

                    // moves--;
                    moves.pop_back();

                    row = sofaPosition.endingCoordinate.row;
                    col = sofaPosition.endingCoordinate.col;

                    // Move Sofa Down
                    sofaPosition.endingCoordinate.row = sofaPosition.endingCoordinate.row + 1;
                    sofaPosition.startingCoordinate.row = sofaPosition.startingCoordinate.row + 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '0';
                    houseThingsArrangementMatrix[sofaPosition.startingCoordinate.row][sofaPosition.startingCoordinate.col] = 's';
                }
                // Else Sofa End Is Down
                else
                {
                    // Mark Position as Visited
                    row = sofaPosition.endingCoordinate.row;
                    col = sofaPosition.endingCoordinate.col;

                    // Get Previous Char at That Position
                    // char prevChar = houseThingsArrangementMatrix[row][col];

                    // Move Sofa Up
                    sofaPosition.startingCoordinate.row = sofaPosition.startingCoordinate.row - 1;
                    sofaPosition.endingCoordinate.row = sofaPosition.endingCoordinate.row - 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '1';
                    houseThingsArrangementMatrix[sofaPosition.startingCoordinate.row][sofaPosition.startingCoordinate.col] = 's';

                    // moves++;
                    moves.push_back("Vertically Upward");
                    cout << "__________Vertically Upward ->" << endl;
                    printHouseThingsArrangement(houseThingsArrangementMatrix, rows, cols, sofaPosition);

                    // if (// isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, moves, sofaPosition, sofaEndPosition) == true)
                    // {
                    //     return true;
                    // }
                    // isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, movesPathToMoveSofa, moves, sofaPosition, sofaEndPosition);

                    currentConfig.houseThingsArrangementMatrix = houseThingsArrangementMatrix;
                    currentConfig.movesToReachCurrentConfiguration = moves;
                    currentConfig.sofaPosition = sofaPosition;
                    configMovesQueue.push(currentConfig);

                    // Backtracking from here

                    // moves--;
                    moves.pop_back();

                    row = sofaPosition.startingCoordinate.row;
                    col = sofaPosition.startingCoordinate.col;

                    // Move Sofa Down
                    sofaPosition.startingCoordinate.row = sofaPosition.startingCoordinate.row + 1;
                    sofaPosition.endingCoordinate.row = sofaPosition.endingCoordinate.row + 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '0';
                    houseThingsArrangementMatrix[sofaPosition.endingCoordinate.row][sofaPosition.endingCoordinate.col] = 's';
                }
            }

            // Vertically Downward
            if (canMoveVerticallyDownward(houseThingsArrangementMatrix, rows, cols, sofaPosition))
            {
                // If Sofa End Is Up
                if (sofaPosition.endingCoordinate.row < sofaPosition.startingCoordinate.row)
                {

                    // Mark Position as Visited
                    row = sofaPosition.endingCoordinate.row;
                    col = sofaPosition.endingCoordinate.col;

                    // Move Sofa Down
                    sofaPosition.endingCoordinate.row = sofaPosition.endingCoordinate.row + 1;
                    sofaPosition.startingCoordinate.row = sofaPosition.startingCoordinate.row + 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '1';
                    houseThingsArrangementMatrix[sofaPosition.startingCoordinate.row][sofaPosition.startingCoordinate.col] = 's';

                    // moves++;
                    moves.push_back("Vertically Downward");
                    cout << "__________Vertically Downward ->" << endl;

                    printHouseThingsArrangement(houseThingsArrangementMatrix, rows, cols, sofaPosition);

                    // if (// isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, moves, sofaPosition, sofaEndPosition) == true)
                    // {
                    //     return true;
                    // }
                    // isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, movesPathToMoveSofa, moves, sofaPosition, sofaEndPosition);

                    currentConfig.houseThingsArrangementMatrix = houseThingsArrangementMatrix;
                    currentConfig.movesToReachCurrentConfiguration = moves;
                    currentConfig.sofaPosition = sofaPosition;
                    configMovesQueue.push(currentConfig);

                    // Backtracking from here

                    // moves--;
                    moves.pop_back();

                    row = sofaPosition.startingCoordinate.row;
                    col = sofaPosition.startingCoordinate.col;

                    // Move Sofa Up
                    sofaPosition.endingCoordinate.row = sofaPosition.endingCoordinate.row - 1;
                    sofaPosition.startingCoordinate.row = sofaPosition.startingCoordinate.row - 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '0';
                    houseThingsArrangementMatrix[sofaPosition.endingCoordinate.row][sofaPosition.endingCoordinate.col] = 's';
                }
                // Else Sofa End Is Down
                else
                {
                    // Mark Position as Visited
                    row = sofaPosition.startingCoordinate.row;
                    col = sofaPosition.startingCoordinate.col;

                    // Move Sofa Down
                    sofaPosition.startingCoordinate.row = sofaPosition.startingCoordinate.row + 1;
                    sofaPosition.endingCoordinate.row = sofaPosition.endingCoordinate.row + 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '1';
                    houseThingsArrangementMatrix[sofaPosition.endingCoordinate.row][sofaPosition.endingCoordinate.col] = 's';

                    // moves++;
                    moves.push_back("Vertically Downward");
                    cout << "__________Vertically Downward ->" << endl;

                    printHouseThingsArrangement(houseThingsArrangementMatrix, rows, cols, sofaPosition);

                    // if (// isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, moves, sofaPosition, sofaEndPosition) == true)
                    // {
                    //     return true;
                    // }
                    // isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, movesPathToMoveSofa, moves, sofaPosition, sofaEndPosition);

                    currentConfig.houseThingsArrangementMatrix = houseThingsArrangementMatrix;
                    currentConfig.movesToReachCurrentConfiguration = moves;
                    currentConfig.sofaPosition = sofaPosition;
                    configMovesQueue.push(currentConfig);

                    // Backtracking from here

                    // moves--;
                    moves.pop_back();

                    row = sofaPosition.endingCoordinate.row;
                    col = sofaPosition.endingCoordinate.col;

                    // Move Sofa Down
                    sofaPosition.startingCoordinate.row = sofaPosition.startingCoordinate.row - 1;
                    sofaPosition.endingCoordinate.row = sofaPosition.endingCoordinate.row - 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '0';
                    houseThingsArrangementMatrix[sofaPosition.startingCoordinate.row][sofaPosition.startingCoordinate.col] = 's';
                }
            }

            // Vertically Rotate Downward Left
            if (canVerticallyRotateDownwardLeft(houseThingsArrangementMatrix, rows, cols, sofaPosition))
            {
                // If Sofa End Is Up
                if (sofaPosition.endingCoordinate.row < sofaPosition.startingCoordinate.row)
                {

                    // Mark Position as Visited
                    row = sofaPosition.endingCoordinate.row;
                    col = sofaPosition.endingCoordinate.col;

                    // Rotate Sofa Vertically Downward Left
                    sofaPosition.endingCoordinate.row = sofaPosition.startingCoordinate.row;
                    sofaPosition.endingCoordinate.col = sofaPosition.startingCoordinate.col - 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = 'r';
                    houseThingsArrangementMatrix[sofaPosition.endingCoordinate.row][sofaPosition.endingCoordinate.col] = 's';

                    // moves++;
                    moves.push_back("Vertically Rotate Downward Left");
                    cout << "__________Vertically Rotate Downward Left ->" << endl;

                    printHouseThingsArrangement(houseThingsArrangementMatrix, rows, cols, sofaPosition);

                    // if (// isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, moves, sofaPosition, sofaEndPosition) == true)
                    // {
                    //     return true;
                    // }
                    // isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, movesPathToMoveSofa, moves, sofaPosition, sofaEndPosition);

                    currentConfig.houseThingsArrangementMatrix = houseThingsArrangementMatrix;
                    currentConfig.movesToReachCurrentConfiguration = moves;
                    currentConfig.sofaPosition = sofaPosition;
                    configMovesQueue.push(currentConfig);

                    // Backtracking from here

                    // moves--;
                    moves.pop_back();

                    row = sofaPosition.endingCoordinate.row;
                    col = sofaPosition.endingCoordinate.col;

                    // Rotate Sofa Horizontally Upward Right
                    sofaPosition.endingCoordinate.row = sofaPosition.startingCoordinate.row - 1;
                    sofaPosition.endingCoordinate.col = sofaPosition.startingCoordinate.col;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '0';
                    houseThingsArrangementMatrix[sofaPosition.endingCoordinate.row][sofaPosition.endingCoordinate.col] = 's';
                }
                // Else Sofa End Is Down
                else
                {
                    // Mark Position as Visited
                    row = sofaPosition.startingCoordinate.row;
                    col = sofaPosition.startingCoordinate.col;

                    // Rotate Sofa Vertically Downward Left
                    sofaPosition.startingCoordinate.row = sofaPosition.endingCoordinate.row;
                    sofaPosition.startingCoordinate.col = sofaPosition.endingCoordinate.col - 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = 'r';
                    houseThingsArrangementMatrix[sofaPosition.startingCoordinate.row][sofaPosition.startingCoordinate.col] = 's';

                    // moves++;
                    moves.push_back("Vertically Rotate Downward Left");

                    cout << "__________Vertically Rotate Downward Left ->" << endl;

                    printHouseThingsArrangement(houseThingsArrangementMatrix, rows, cols, sofaPosition);

                    // if (// isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, moves, sofaPosition, sofaEndPosition) == true)
                    // {
                    //     return true;
                    // }
                    // isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, movesPathToMoveSofa, moves, sofaPosition, sofaEndPosition);

                    currentConfig.houseThingsArrangementMatrix = houseThingsArrangementMatrix;
                    currentConfig.movesToReachCurrentConfiguration = moves;
                    currentConfig.sofaPosition = sofaPosition;
                    configMovesQueue.push(currentConfig);

                    // Backtracking from here

                    // moves--;
                    moves.pop_back();

                    row = sofaPosition.startingCoordinate.row;
                    col = sofaPosition.startingCoordinate.col;

                    // Rotate Sofa Horizontally Upward Right
                    sofaPosition.startingCoordinate.row = sofaPosition.endingCoordinate.row - 1;
                    sofaPosition.startingCoordinate.col = sofaPosition.endingCoordinate.col;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '0';
                    houseThingsArrangementMatrix[sofaPosition.startingCoordinate.row][sofaPosition.startingCoordinate.col] = 's';
                }
            }

            // Vertically Rotate Downward Right
            if (canVerticallyRotateDownwardRight(houseThingsArrangementMatrix, rows, cols, sofaPosition))
            {
                // If Sofa End Is Up
                if (sofaPosition.endingCoordinate.row < sofaPosition.startingCoordinate.row)
                {

                    // Mark Position as Visited
                    row = sofaPosition.endingCoordinate.row;
                    col = sofaPosition.endingCoordinate.col;

                    // Rotate Sofa Vertically Downward Right
                    sofaPosition.endingCoordinate.row = sofaPosition.startingCoordinate.row;
                    sofaPosition.endingCoordinate.col = sofaPosition.startingCoordinate.col + 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = 'r';
                    houseThingsArrangementMatrix[sofaPosition.endingCoordinate.row][sofaPosition.endingCoordinate.col] = 's';

                    // moves++;
                    moves.push_back("Vertically Rotate Downward Right");

                    cout << "__________Vertically Rotate Downward Right ->" << endl;

                    printHouseThingsArrangement(houseThingsArrangementMatrix, rows, cols, sofaPosition);

                    // if (// isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, moves, sofaPosition, sofaEndPosition) == true)
                    // {
                    //     return true;
                    // }
                    // isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, movesPathToMoveSofa, moves, sofaPosition, sofaEndPosition);

                    currentConfig.houseThingsArrangementMatrix = houseThingsArrangementMatrix;
                    currentConfig.movesToReachCurrentConfiguration = moves;
                    currentConfig.sofaPosition = sofaPosition;
                    configMovesQueue.push(currentConfig);

                    // Backtracking from here

                    // moves--;
                    moves.pop_back();

                    row = sofaPosition.endingCoordinate.row;
                    col = sofaPosition.endingCoordinate.col;

                    // Rotate Sofa Horizontally Upward Left
                    sofaPosition.endingCoordinate.row = sofaPosition.startingCoordinate.row - 1;
                    sofaPosition.endingCoordinate.col = sofaPosition.startingCoordinate.col;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '0';
                    houseThingsArrangementMatrix[sofaPosition.endingCoordinate.row][sofaPosition.endingCoordinate.col] = 's';
                }
                // Else Sofa End Is Down
                else
                {
                    // Mark Position as Visited
                    row = sofaPosition.startingCoordinate.row;
                    col = sofaPosition.startingCoordinate.col;

                    // Rotate Sofa Vertically Downward Right
                    sofaPosition.startingCoordinate.row = sofaPosition.endingCoordinate.row;
                    sofaPosition.startingCoordinate.col = sofaPosition.endingCoordinate.col + 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = 'r';
                    houseThingsArrangementMatrix[sofaPosition.startingCoordinate.row][sofaPosition.startingCoordinate.col] = 's';

                    // moves++;
                    moves.push_back("Vertically Rotate Downward Right");

                    cout << "__________Vertically Rotate Downward Right ->" << endl;

                    printHouseThingsArrangement(houseThingsArrangementMatrix, rows, cols, sofaPosition);

                    // if (// isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, moves, sofaPosition, sofaEndPosition) == true)
                    // {
                    //     return true;
                    // }
                    // isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, movesPathToMoveSofa, moves, sofaPosition, sofaEndPosition);

                    currentConfig.houseThingsArrangementMatrix = houseThingsArrangementMatrix;
                    currentConfig.movesToReachCurrentConfiguration = moves;
                    currentConfig.sofaPosition = sofaPosition;
                    configMovesQueue.push(currentConfig);

                    // Backtracking from here

                    // moves--;
                    moves.pop_back();

                    row = sofaPosition.startingCoordinate.row;
                    col = sofaPosition.startingCoordinate.col;

                    // Rotate Sofa Horizontally Upward Left
                    sofaPosition.startingCoordinate.row = sofaPosition.endingCoordinate.row - 1;
                    sofaPosition.startingCoordinate.col = sofaPosition.endingCoordinate.col;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '0';
                    houseThingsArrangementMatrix[sofaPosition.startingCoordinate.row][sofaPosition.startingCoordinate.col] = 's';
                }
            }

            // Vertically Rotate Upward Left
            if (canVerticallyRotateUpwardLeft(houseThingsArrangementMatrix, rows, cols, sofaPosition))
            {
                // If Sofa End Is Up
                if (sofaPosition.endingCoordinate.row < sofaPosition.startingCoordinate.row)
                {

                    // Mark Position as Visited
                    row = sofaPosition.startingCoordinate.row;
                    col = sofaPosition.startingCoordinate.col;

                    // Rotate Sofa Vertically Upward Left
                    sofaPosition.startingCoordinate.row = sofaPosition.endingCoordinate.row;
                    sofaPosition.startingCoordinate.col = sofaPosition.endingCoordinate.col - 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = 'r';
                    houseThingsArrangementMatrix[sofaPosition.startingCoordinate.row][sofaPosition.startingCoordinate.col] = 's';

                    // moves++;
                    moves.push_back("Vertically Rotate Upward Left");

                    cout << "__________Vertically Rotate Upward Left ->" << endl;

                    printHouseThingsArrangement(houseThingsArrangementMatrix, rows, cols, sofaPosition);

                    // if (// isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, moves, sofaPosition, sofaEndPosition) == true)
                    // {
                    //     return true;
                    // }
                    // isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, movesPathToMoveSofa, moves, sofaPosition, sofaEndPosition);

                    currentConfig.houseThingsArrangementMatrix = houseThingsArrangementMatrix;
                    currentConfig.movesToReachCurrentConfiguration = moves;
                    currentConfig.sofaPosition = sofaPosition;
                    configMovesQueue.push(currentConfig);

                    // Backtracking from here

                    // moves--;
                    moves.pop_back();

                    row = sofaPosition.startingCoordinate.row;
                    col = sofaPosition.startingCoordinate.col;

                    // Rotate Sofa Horizontally Downward Right
                    sofaPosition.startingCoordinate.row = sofaPosition.endingCoordinate.row + 1;
                    sofaPosition.startingCoordinate.col = sofaPosition.endingCoordinate.col;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '0';
                    houseThingsArrangementMatrix[sofaPosition.startingCoordinate.row][sofaPosition.startingCoordinate.col] = 's';
                }
                // Else Sofa End Is Down
                else
                {

                    // Mark Position as Visited
                    row = sofaPosition.endingCoordinate.row;
                    col = sofaPosition.endingCoordinate.col;

                    // Rotate Sofa Vertically Upward Left
                    sofaPosition.endingCoordinate.row = sofaPosition.startingCoordinate.row;
                    sofaPosition.endingCoordinate.col = sofaPosition.startingCoordinate.col - 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = 'r';
                    houseThingsArrangementMatrix[sofaPosition.endingCoordinate.row][sofaPosition.endingCoordinate.col] = 's';

                    // moves++;
                    moves.push_back("Vertically Rotate Upward Left");

                    cout << "__________Vertically Rotate Upward Left ->" << endl;

                    printHouseThingsArrangement(houseThingsArrangementMatrix, rows, cols, sofaPosition);

                    // if (// isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, moves, sofaPosition, sofaEndPosition) == true)
                    // {
                    //     return true;
                    // }
                    // isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, movesPathToMoveSofa, moves, sofaPosition, sofaEndPosition);

                    currentConfig.houseThingsArrangementMatrix = houseThingsArrangementMatrix;
                    currentConfig.movesToReachCurrentConfiguration = moves;
                    currentConfig.sofaPosition = sofaPosition;
                    configMovesQueue.push(currentConfig);

                    // Backtracking from here

                    // moves--;
                    moves.pop_back();

                    row = sofaPosition.endingCoordinate.row;
                    col = sofaPosition.endingCoordinate.col;

                    // Rotate Sofa Horizontally Downward Right
                    sofaPosition.endingCoordinate.row = sofaPosition.startingCoordinate.row + 1;
                    sofaPosition.endingCoordinate.col = sofaPosition.startingCoordinate.col;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '0';
                    houseThingsArrangementMatrix[sofaPosition.endingCoordinate.row][sofaPosition.endingCoordinate.col] = 's';
                }
            }

            // Vertically Rotate Upward Right
            if (canVerticallyRotateUpwardRight(houseThingsArrangementMatrix, rows, cols, sofaPosition))
            {
                // If Sofa End Is Up
                if (sofaPosition.endingCoordinate.row < sofaPosition.startingCoordinate.row)
                {

                    // Mark Position as Visited
                    row = sofaPosition.startingCoordinate.row;
                    col = sofaPosition.startingCoordinate.col;

                    // Rotate Sofa Vertically Upward Right
                    sofaPosition.startingCoordinate.row = sofaPosition.endingCoordinate.row;
                    sofaPosition.startingCoordinate.col = sofaPosition.endingCoordinate.col + 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = 'r';
                    houseThingsArrangementMatrix[sofaPosition.startingCoordinate.row][sofaPosition.startingCoordinate.col] = 's';

                    // moves++;
                    moves.push_back("Vertically Rotate Upward Right");

                    cout << "__________Vertically Rotate Upward Right ->" << endl;

                    printHouseThingsArrangement(houseThingsArrangementMatrix, rows, cols, sofaPosition);

                    // if (// isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, moves, sofaPosition, sofaEndPosition) == true)
                    // {
                    //     return true;
                    // }
                    // isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, movesPathToMoveSofa, moves, sofaPosition, sofaEndPosition);

                    currentConfig.houseThingsArrangementMatrix = houseThingsArrangementMatrix;
                    currentConfig.movesToReachCurrentConfiguration = moves;
                    currentConfig.sofaPosition = sofaPosition;
                    configMovesQueue.push(currentConfig);

                    // Backtracking from here

                    // moves--;
                    moves.pop_back();

                    row = sofaPosition.startingCoordinate.row;
                    col = sofaPosition.startingCoordinate.col;

                    // Rotate Sofa Horizontally Downward Left
                    sofaPosition.startingCoordinate.row = sofaPosition.endingCoordinate.row + 1;
                    sofaPosition.startingCoordinate.col = sofaPosition.endingCoordinate.col;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '0';
                    houseThingsArrangementMatrix[sofaPosition.startingCoordinate.row][sofaPosition.startingCoordinate.col] = 's';
                }
                // Else Sofa End Is Down
                else
                {

                    // Mark Position as Visited
                    row = sofaPosition.endingCoordinate.row;
                    col = sofaPosition.endingCoordinate.col;

                    // Rotate Sofa Vertically Upward Right
                    sofaPosition.endingCoordinate.row = sofaPosition.startingCoordinate.row;
                    sofaPosition.endingCoordinate.col = sofaPosition.startingCoordinate.col + 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = 'r';
                    houseThingsArrangementMatrix[sofaPosition.endingCoordinate.row][sofaPosition.endingCoordinate.col] = 's';

                    // moves++;
                    moves.push_back("Vertically Rotate Upward Right");

                    cout << "__________Vertically Rotate Upward Right ->" << endl;

                    printHouseThingsArrangement(houseThingsArrangementMatrix, rows, cols, sofaPosition);

                    // if (// isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, moves, sofaPosition, sofaEndPosition) == true)
                    // {
                    //     return true;
                    // }
                    // isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, movesPathToMoveSofa, moves, sofaPosition, sofaEndPosition);

                    currentConfig.houseThingsArrangementMatrix = houseThingsArrangementMatrix;
                    currentConfig.movesToReachCurrentConfiguration = moves;
                    currentConfig.sofaPosition = sofaPosition;
                    configMovesQueue.push(currentConfig);

                    // Backtracking from here

                    // moves--;
                    moves.pop_back();

                    row = sofaPosition.endingCoordinate.row;
                    col = sofaPosition.endingCoordinate.col;

                    // Rotate Sofa Horizontally Downward Left
                    sofaPosition.endingCoordinate.row = sofaPosition.startingCoordinate.row + 1;
                    sofaPosition.endingCoordinate.col = sofaPosition.startingCoordinate.col;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '0';
                    houseThingsArrangementMatrix[sofaPosition.endingCoordinate.row][sofaPosition.endingCoordinate.col] = 's';
                }
            }
        }
        // Horizontal Orientation Moves
        else
        {

            cout << "Running HORIZONTAL " << endl;

            // Horizontally Forward
            if (canMoveHorizontallyForward(houseThingsArrangementMatrix, rows, cols, sofaPosition))
            {
                // If Sofa End is Left
                if (sofaPosition.endingCoordinate.col < sofaPosition.startingCoordinate.col)
                {

                    // Mark Position as Visited
                    row = sofaPosition.endingCoordinate.row;
                    col = sofaPosition.endingCoordinate.col;

                    // Move Sofa Horizontally Forward
                    sofaPosition.startingCoordinate.col = sofaPosition.startingCoordinate.col + 1;
                    sofaPosition.endingCoordinate.col = sofaPosition.endingCoordinate.col + 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '1';
                    houseThingsArrangementMatrix[sofaPosition.startingCoordinate.row][sofaPosition.startingCoordinate.col] = 's';

                    // moves++;
                    moves.push_back("Horizontally Forward");

                    cout << "__________Horizontally Forward ->" << endl;

                    printHouseThingsArrangement(houseThingsArrangementMatrix, rows, cols, sofaPosition);

                    // if (// isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, moves, sofaPosition, sofaEndPosition) == true)
                    // {
                    //     return true;
                    // }
                    // isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, movesPathToMoveSofa, moves, sofaPosition, sofaEndPosition);

                    currentConfig.houseThingsArrangementMatrix = houseThingsArrangementMatrix;
                    currentConfig.movesToReachCurrentConfiguration = moves;
                    currentConfig.sofaPosition = sofaPosition;
                    configMovesQueue.push(currentConfig);

                    // Backtracking from here

                    // moves--;
                    moves.pop_back();

                    row = sofaPosition.startingCoordinate.row;
                    col = sofaPosition.startingCoordinate.col;

                    // Move Sofa Horizontally Backward
                    sofaPosition.startingCoordinate.col = sofaPosition.startingCoordinate.col - 1;
                    sofaPosition.endingCoordinate.col = sofaPosition.endingCoordinate.col - 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '0';
                    houseThingsArrangementMatrix[sofaPosition.endingCoordinate.row][sofaPosition.endingCoordinate.col] = 's';
                }
                // Else Sofa Start is Left
                else
                {

                    // Mark Position as Visited
                    row = sofaPosition.startingCoordinate.row;
                    col = sofaPosition.startingCoordinate.col;

                    // Move Sofa Horizontally Forward
                    sofaPosition.startingCoordinate.col = sofaPosition.startingCoordinate.col + 1;
                    sofaPosition.endingCoordinate.col = sofaPosition.endingCoordinate.col + 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '1';
                    houseThingsArrangementMatrix[sofaPosition.endingCoordinate.row][sofaPosition.endingCoordinate.col] = 's';

                    // moves++;
                    moves.push_back("Horizontally Forward");

                    cout << "__________Horizontally Forward ->" << endl;

                    printHouseThingsArrangement(houseThingsArrangementMatrix, rows, cols, sofaPosition);

                    // if (// isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, moves, sofaPosition, sofaEndPosition) == true)
                    // {
                    //     return true;
                    // }

                    // isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, movesPathToMoveSofa, moves, sofaPosition, sofaEndPosition);
                    currentConfig.houseThingsArrangementMatrix = houseThingsArrangementMatrix;
                    currentConfig.movesToReachCurrentConfiguration = moves;
                    currentConfig.sofaPosition = sofaPosition;
                    configMovesQueue.push(currentConfig);

                    // Backtracking from here

                    // moves--;
                    moves.pop_back();

                    row = sofaPosition.endingCoordinate.row;
                    col = sofaPosition.endingCoordinate.col;

                    // Move Sofa Horizontally Backward
                    sofaPosition.startingCoordinate.col = sofaPosition.startingCoordinate.col - 1;
                    sofaPosition.endingCoordinate.col = sofaPosition.endingCoordinate.col - 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '0';
                    houseThingsArrangementMatrix[sofaPosition.startingCoordinate.row][sofaPosition.startingCoordinate.col] = 's';
                }
            }

            // Horizontally Backward
            if (canMoveHorizontallyBackward(houseThingsArrangementMatrix, rows, cols, sofaPosition))
            {
                // If Sofa End is Left
                if (sofaPosition.endingCoordinate.col < sofaPosition.startingCoordinate.col)
                {

                    // Mark Position as Visited
                    row = sofaPosition.startingCoordinate.row;
                    col = sofaPosition.startingCoordinate.col;

                    // Move Sofa Horizontally Backward
                    sofaPosition.startingCoordinate.col = sofaPosition.startingCoordinate.col - 1;
                    sofaPosition.endingCoordinate.col = sofaPosition.endingCoordinate.col - 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '1';
                    houseThingsArrangementMatrix[sofaPosition.endingCoordinate.row][sofaPosition.endingCoordinate.col] = 's';

                    // moves++;
                    moves.push_back("Horizontally Backward");

                    cout << "__________Horizontally Backward ->" << endl;

                    printHouseThingsArrangement(houseThingsArrangementMatrix, rows, cols, sofaPosition);

                    // if (// isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, moves, sofaPosition, sofaEndPosition) == true)
                    // {
                    //     return true;
                    // }
                    // isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, movesPathToMoveSofa, moves, sofaPosition, sofaEndPosition);

                    currentConfig.houseThingsArrangementMatrix = houseThingsArrangementMatrix;
                    currentConfig.movesToReachCurrentConfiguration = moves;
                    currentConfig.sofaPosition = sofaPosition;
                    configMovesQueue.push(currentConfig);

                    // Backtracking from here

                    // moves--;
                    moves.pop_back();

                    row = sofaPosition.endingCoordinate.row;
                    col = sofaPosition.endingCoordinate.col;

                    // Move Sofa Horizontally Forward
                    sofaPosition.startingCoordinate.col = sofaPosition.startingCoordinate.col + 1;
                    sofaPosition.endingCoordinate.col = sofaPosition.endingCoordinate.col + 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '0';
                    houseThingsArrangementMatrix[sofaPosition.startingCoordinate.row][sofaPosition.startingCoordinate.col] = 's';
                }
                // Else Sofa Start is Left
                else
                {
                    // Mark Position as Visited
                    row = sofaPosition.endingCoordinate.row;
                    col = sofaPosition.endingCoordinate.col;

                    // Move Sofa Horizontally Backward
                    sofaPosition.startingCoordinate.col = sofaPosition.startingCoordinate.col - 1;
                    sofaPosition.endingCoordinate.col = sofaPosition.endingCoordinate.col - 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '1';
                    houseThingsArrangementMatrix[sofaPosition.startingCoordinate.row][sofaPosition.startingCoordinate.col] = 's';

                    // moves++;
                    moves.push_back("Horizontally Backward");

                    cout << "__________Horizontally Backward ->" << endl;

                    printHouseThingsArrangement(houseThingsArrangementMatrix, rows, cols, sofaPosition);

                    // if (// isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, moves, sofaPosition, sofaEndPosition) == true)
                    // {
                    //     return true;
                    // }
                    // isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, movesPathToMoveSofa, moves, sofaPosition, sofaEndPosition);

                    currentConfig.houseThingsArrangementMatrix = houseThingsArrangementMatrix;
                    currentConfig.movesToReachCurrentConfiguration = moves;
                    currentConfig.sofaPosition = sofaPosition;
                    configMovesQueue.push(currentConfig);

                    // Backtracking from here

                    // moves--;
                    moves.pop_back();

                    row = sofaPosition.startingCoordinate.row;
                    col = sofaPosition.startingCoordinate.col;

                    // Move Sofa Horizontally Forward
                    sofaPosition.startingCoordinate.col = sofaPosition.startingCoordinate.col + 1;
                    sofaPosition.endingCoordinate.col = sofaPosition.endingCoordinate.col + 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '0';
                    houseThingsArrangementMatrix[sofaPosition.endingCoordinate.row][sofaPosition.endingCoordinate.col] = 's';
                }
            }

            // Horizontally Rotate Downward Left
            if (canHorizontallyRotateDownwardLeft(houseThingsArrangementMatrix, rows, cols, sofaPosition))
            {
                // If Sofa End is Left
                if (sofaPosition.endingCoordinate.col < sofaPosition.startingCoordinate.col)
                {

                    // Mark Position as Visited
                    row = sofaPosition.startingCoordinate.row;
                    col = sofaPosition.startingCoordinate.col;

                    // Rotate Sofa Horizontally Downward Left
                    sofaPosition.startingCoordinate.row = sofaPosition.endingCoordinate.row + 1;
                    sofaPosition.startingCoordinate.col = sofaPosition.endingCoordinate.col;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = 'r';
                    houseThingsArrangementMatrix[sofaPosition.startingCoordinate.row][sofaPosition.startingCoordinate.col] = 's';

                    // moves++;
                    moves.push_back("Horizontally Rotate Downward Left");

                    cout << "__________Horizontally Rotate Downward Left ->" << endl;

                    printHouseThingsArrangement(houseThingsArrangementMatrix, rows, cols, sofaPosition);

                    // if (// isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, moves, sofaPosition, sofaEndPosition) == true)
                    // {
                    //     return true;
                    // }
                    // isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, movesPathToMoveSofa, moves, sofaPosition, sofaEndPosition);

                    currentConfig.houseThingsArrangementMatrix = houseThingsArrangementMatrix;
                    currentConfig.movesToReachCurrentConfiguration = moves;
                    currentConfig.sofaPosition = sofaPosition;
                    configMovesQueue.push(currentConfig);

                    // Backtracking from here

                    // moves--;
                    moves.pop_back();

                    row = sofaPosition.startingCoordinate.row;
                    col = sofaPosition.startingCoordinate.col;

                    // Rotate Sofa Vertically Upward Right
                    sofaPosition.startingCoordinate.row = sofaPosition.endingCoordinate.row;
                    sofaPosition.startingCoordinate.col = sofaPosition.endingCoordinate.col + 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '0';
                    houseThingsArrangementMatrix[sofaPosition.startingCoordinate.row][sofaPosition.startingCoordinate.col] = 's';
                }
                // Else Sofa Start is Left
                else
                {

                    // Mark Position as Visited
                    row = sofaPosition.endingCoordinate.row;
                    col = sofaPosition.endingCoordinate.col;

                    // Rotate Sofa Horizontally Downward Left
                    sofaPosition.endingCoordinate.row = sofaPosition.startingCoordinate.row + 1;
                    sofaPosition.endingCoordinate.col = sofaPosition.startingCoordinate.col;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = 'r';
                    houseThingsArrangementMatrix[sofaPosition.endingCoordinate.row][sofaPosition.endingCoordinate.col] = 's';

                    // moves++;
                    moves.push_back("Horizontally Rotate Downward Left");

                    cout << "__________Horizontally Rotate Downward Left ->" << endl;

                    printHouseThingsArrangement(houseThingsArrangementMatrix, rows, cols, sofaPosition);

                    // if (// isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, moves, sofaPosition, sofaEndPosition) == true)
                    // {
                    //     return true;
                    // }
                    // isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, movesPathToMoveSofa, moves, sofaPosition, sofaEndPosition);

                    currentConfig.houseThingsArrangementMatrix = houseThingsArrangementMatrix;
                    currentConfig.movesToReachCurrentConfiguration = moves;
                    currentConfig.sofaPosition = sofaPosition;
                    configMovesQueue.push(currentConfig);

                    // Backtracking from here

                    // moves--;
                    moves.pop_back();

                    row = sofaPosition.endingCoordinate.row;
                    col = sofaPosition.endingCoordinate.col;

                    // Rotate Sofa Vertically Upward Right
                    sofaPosition.endingCoordinate.row = sofaPosition.startingCoordinate.row;
                    sofaPosition.endingCoordinate.col = sofaPosition.startingCoordinate.col + 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '0';
                    houseThingsArrangementMatrix[sofaPosition.endingCoordinate.row][sofaPosition.endingCoordinate.col] = 's';
                }
            }

            // Horizontally Rotate Downward Right
            if (canHorizontallyRotateDownwardRight(houseThingsArrangementMatrix, rows, cols, sofaPosition))
            {
                // If Sofa End is Left
                if (sofaPosition.endingCoordinate.col < sofaPosition.startingCoordinate.col)
                {

                    // Mark Position as Visited
                    row = sofaPosition.endingCoordinate.row;
                    col = sofaPosition.endingCoordinate.col;

                    // Rotate Sofa Horizontally Downward Right
                    sofaPosition.endingCoordinate.row = sofaPosition.startingCoordinate.row + 1;
                    sofaPosition.endingCoordinate.col = sofaPosition.startingCoordinate.col;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = 'r';
                    houseThingsArrangementMatrix[sofaPosition.endingCoordinate.row][sofaPosition.endingCoordinate.col] = 's';

                    // moves++;
                    moves.push_back("Horizontally Rotate Downward Right");

                    cout << "__________Horizontally Rotate Downward Right ->" << endl;

                    printHouseThingsArrangement(houseThingsArrangementMatrix, rows, cols, sofaPosition);

                    // if (// isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, moves, sofaPosition, sofaEndPosition) == true)
                    // {
                    //     return true;
                    // }
                    // isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, movesPathToMoveSofa, moves, sofaPosition, sofaEndPosition);

                    currentConfig.houseThingsArrangementMatrix = houseThingsArrangementMatrix;
                    currentConfig.movesToReachCurrentConfiguration = moves;
                    currentConfig.sofaPosition = sofaPosition;
                    configMovesQueue.push(currentConfig);

                    // Backtracking from here

                    // moves--;
                    moves.pop_back();

                    row = sofaPosition.endingCoordinate.row;
                    col = sofaPosition.endingCoordinate.col;

                    // Rotate Sofa Vertically Upward Left
                    sofaPosition.endingCoordinate.row = sofaPosition.startingCoordinate.row;
                    sofaPosition.endingCoordinate.col = sofaPosition.startingCoordinate.col - 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '0';
                    houseThingsArrangementMatrix[sofaPosition.endingCoordinate.row][sofaPosition.endingCoordinate.col] = 's';
                }
                // Else Sofa Start is Left
                else
                {

                    // Mark Position as Visited
                    row = sofaPosition.startingCoordinate.row;
                    col = sofaPosition.startingCoordinate.col;

                    // Rotate Sofa Horizontally Downward Right
                    sofaPosition.startingCoordinate.row = sofaPosition.endingCoordinate.row + 1;
                    sofaPosition.startingCoordinate.col = sofaPosition.endingCoordinate.col;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = 'r';
                    houseThingsArrangementMatrix[sofaPosition.startingCoordinate.row][sofaPosition.startingCoordinate.col] = 's';

                    // moves++;
                    moves.push_back("Horizontally Rotate Downward Right");

                    cout << "__________Horizontally Rotate Downward Right ->" << endl;

                    printHouseThingsArrangement(houseThingsArrangementMatrix, rows, cols, sofaPosition);

                    // if (// isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, moves, sofaPosition, sofaEndPosition) == true)
                    // {
                    //     return true;
                    // }
                    // isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, movesPathToMoveSofa, moves, sofaPosition, sofaEndPosition);

                    currentConfig.houseThingsArrangementMatrix = houseThingsArrangementMatrix;
                    currentConfig.movesToReachCurrentConfiguration = moves;
                    currentConfig.sofaPosition = sofaPosition;
                    configMovesQueue.push(currentConfig);

                    // Backtracking from here

                    // moves--;
                    moves.pop_back();

                    row = sofaPosition.startingCoordinate.row;
                    col = sofaPosition.startingCoordinate.col;

                    // Rotate Sofa Vertically Upward Left
                    sofaPosition.startingCoordinate.row = sofaPosition.endingCoordinate.row;
                    sofaPosition.startingCoordinate.col = sofaPosition.endingCoordinate.col - 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '0';
                    houseThingsArrangementMatrix[sofaPosition.startingCoordinate.row][sofaPosition.startingCoordinate.col] = 's';
                }
            }

            // Horizontally Rotate Upward Left
            if (canHorizontallyRotateUpwardLeft(houseThingsArrangementMatrix, rows, cols, sofaPosition))
            {
                // If Sofa End is Left
                if (sofaPosition.endingCoordinate.col < sofaPosition.startingCoordinate.col)
                {

                    // Mark Position as Visited
                    row = sofaPosition.startingCoordinate.row;
                    col = sofaPosition.startingCoordinate.col;

                    // Rotate Sofa Horizontally Upward Left
                    sofaPosition.startingCoordinate.row = sofaPosition.endingCoordinate.row - 1;
                    sofaPosition.startingCoordinate.col = sofaPosition.endingCoordinate.col;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = 'r';
                    houseThingsArrangementMatrix[sofaPosition.startingCoordinate.row][sofaPosition.startingCoordinate.col] = 's';

                    // moves++;
                    moves.push_back("Horizontally Rotate Upward Left");

                    cout << "__________Horizontally Rotate Upward Left ->" << endl;

                    printHouseThingsArrangement(houseThingsArrangementMatrix, rows, cols, sofaPosition);

                    // if (// isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, moves, sofaPosition, sofaEndPosition) == true)
                    // {
                    //     return true;
                    // }
                    // isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, movesPathToMoveSofa, moves, sofaPosition, sofaEndPosition);

                    currentConfig.houseThingsArrangementMatrix = houseThingsArrangementMatrix;
                    currentConfig.movesToReachCurrentConfiguration = moves;
                    currentConfig.sofaPosition = sofaPosition;
                    configMovesQueue.push(currentConfig);

                    // Backtracking from here

                    // moves--;
                    moves.pop_back();

                    row = sofaPosition.startingCoordinate.row;
                    col = sofaPosition.startingCoordinate.col;

                    // Rotate Sofa Vertically Downward Right
                    sofaPosition.startingCoordinate.row = sofaPosition.endingCoordinate.row;
                    sofaPosition.startingCoordinate.col = sofaPosition.endingCoordinate.col + 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '0';
                    houseThingsArrangementMatrix[sofaPosition.startingCoordinate.row][sofaPosition.startingCoordinate.col] = 's';
                }
                // Else Sofa Start is Left
                else
                {

                    // Mark Position as Visited
                    row = sofaPosition.endingCoordinate.row;
                    col = sofaPosition.endingCoordinate.col;

                    // Rotate Sofa Horizontally Upward Left
                    sofaPosition.endingCoordinate.row = sofaPosition.startingCoordinate.row - 1;
                    sofaPosition.endingCoordinate.col = sofaPosition.startingCoordinate.col;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = 'r';
                    houseThingsArrangementMatrix[sofaPosition.endingCoordinate.row][sofaPosition.endingCoordinate.col] = 's';

                    // moves++;
                    moves.push_back("Horizontally Rotate Upward Left");

                    cout << "__________Horizontally Rotate Upward Left ->" << endl;

                    printHouseThingsArrangement(houseThingsArrangementMatrix, rows, cols, sofaPosition);

                    // if (// isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, moves, sofaPosition, sofaEndPosition) == true)
                    // {
                    //     return true;
                    // }
                    // isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, movesPathToMoveSofa, moves, sofaPosition, sofaEndPosition);

                    currentConfig.houseThingsArrangementMatrix = houseThingsArrangementMatrix;
                    currentConfig.movesToReachCurrentConfiguration = moves;
                    currentConfig.sofaPosition = sofaPosition;
                    configMovesQueue.push(currentConfig);

                    // Backtracking from here

                    // moves--;
                    moves.pop_back();

                    row = sofaPosition.endingCoordinate.row;
                    col = sofaPosition.endingCoordinate.col;

                    // Rotate Sofa Vertically Downward Right
                    sofaPosition.endingCoordinate.row = sofaPosition.startingCoordinate.row;
                    sofaPosition.endingCoordinate.col = sofaPosition.startingCoordinate.col + 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '0';
                    houseThingsArrangementMatrix[sofaPosition.endingCoordinate.row][sofaPosition.endingCoordinate.col] = 's';
                }
            }

            // Horizontally Rotate Upward Right
            if (canHorizontallyRotateUpwardRight(houseThingsArrangementMatrix, rows, cols, sofaPosition))
            {
                // If Sofa End is Left
                if (sofaPosition.endingCoordinate.col < sofaPosition.startingCoordinate.col)
                {

                    // Mark Position as Visited
                    row = sofaPosition.endingCoordinate.row;
                    col = sofaPosition.endingCoordinate.col;

                    // Rotate Sofa Horizontally Upward Right
                    sofaPosition.endingCoordinate.row = sofaPosition.startingCoordinate.row - 1;
                    sofaPosition.endingCoordinate.col = sofaPosition.startingCoordinate.col;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = 'r';
                    houseThingsArrangementMatrix[sofaPosition.endingCoordinate.row][sofaPosition.endingCoordinate.col] = 's';

                    // moves++;
                    moves.push_back("Horizontally Rotate Upward Right");

                    cout << "__________Horizontally Rotate Upward Right ->" << endl;

                    printHouseThingsArrangement(houseThingsArrangementMatrix, rows, cols, sofaPosition);

                    // if (// isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, moves, sofaPosition, sofaEndPosition) == true)
                    // {
                    //     return true;
                    // }
                    // isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, movesPathToMoveSofa, moves, sofaPosition, sofaEndPosition);

                    currentConfig.houseThingsArrangementMatrix = houseThingsArrangementMatrix;
                    currentConfig.movesToReachCurrentConfiguration = moves;
                    currentConfig.sofaPosition = sofaPosition;
                    configMovesQueue.push(currentConfig);

                    // Backtracking from here

                    // moves--;
                    moves.pop_back();

                    row = sofaPosition.endingCoordinate.row;
                    col = sofaPosition.endingCoordinate.col;

                    // Rotate Sofa Vertically Downward Left
                    sofaPosition.endingCoordinate.row = sofaPosition.startingCoordinate.row;
                    sofaPosition.endingCoordinate.col = sofaPosition.startingCoordinate.col - 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '0';
                    houseThingsArrangementMatrix[sofaPosition.endingCoordinate.row][sofaPosition.endingCoordinate.col] = 's';
                }
                // Else Sofa Start is Left
                else
                {

                    // Mark Position as Visited
                    row = sofaPosition.startingCoordinate.row;
                    col = sofaPosition.startingCoordinate.col;

                    // Rotate Sofa Horizontally Upward Right
                    sofaPosition.startingCoordinate.row = sofaPosition.endingCoordinate.row - 1;
                    sofaPosition.startingCoordinate.col = sofaPosition.endingCoordinate.col;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = 'r';
                    houseThingsArrangementMatrix[sofaPosition.startingCoordinate.row][sofaPosition.startingCoordinate.col] = 's';

                    // moves++;
                    moves.push_back("Horizontally Rotate Upward Right");

                    cout << "__________Horizontally Rotate Upward Right ->" << endl;

                    printHouseThingsArrangement(houseThingsArrangementMatrix, rows, cols, sofaPosition);

                    // if (// isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, moves, sofaPosition, sofaEndPosition) == true)
                    // {
                    //     return true;
                    // }
                    // isPossibleToMoveSofa(houseThingsArrangementMatrix, rows, cols, movesPathToMoveSofa, moves, sofaPosition, sofaEndPosition);

                    currentConfig.houseThingsArrangementMatrix = houseThingsArrangementMatrix;
                    currentConfig.movesToReachCurrentConfiguration = moves;
                    currentConfig.sofaPosition = sofaPosition;
                    configMovesQueue.push(currentConfig);

                    // Backtracking from here

                    // moves--;
                    moves.pop_back();

                    row = sofaPosition.startingCoordinate.row;
                    col = sofaPosition.startingCoordinate.col;

                    // Rotate Sofa Vertically Downward Left
                    sofaPosition.startingCoordinate.row = sofaPosition.endingCoordinate.row;
                    sofaPosition.startingCoordinate.col = sofaPosition.endingCoordinate.col - 1;

                    // Update Visited Status and Update sofa Position in House Arrangement
                    houseThingsArrangementMatrix[row][col] = '0';
                    houseThingsArrangementMatrix[sofaPosition.startingCoordinate.row][sofaPosition.startingCoordinate.col] = 's';
                }
            }
        }
    
    
    }

    if (movesPathToMoveSofa.size() > 0)
    {
        return true;
    }
    
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

    // Make Sofa Destination as Unvisited and Empty Place
    houseThingsArrangementMatrix[sofaEndPosition.startingCoordinate.row][sofaEndPosition.startingCoordinate.col] = '0';
    houseThingsArrangementMatrix[sofaEndPosition.endingCoordinate.row][sofaEndPosition.endingCoordinate.col] = '0';

    // int moves = 0;
    vector<vector<string>> movesPathToMoveSofa;
    vector<string> moves;
    bool moved = isPossibleToMoveSofaBFS(houseThingsArrangementMatrix, rows, cols, movesPathToMoveSofa, moves, sofaStartPosition, sofaEndPosition);

    // Make Sofa Destination Visible Again
    houseThingsArrangementMatrix[sofaEndPosition.startingCoordinate.row][sofaEndPosition.startingCoordinate.col] = 'S';
    houseThingsArrangementMatrix[sofaEndPosition.endingCoordinate.row][sofaEndPosition.endingCoordinate.col] = 'S';

    if (moved == true || movesPathToMoveSofa.size() > 0)
    {
        cout << "Bhai moved == " << moved << " and  movesPathToMoveSofa.size() == " << movesPathToMoveSofa.size() << endl
             << endl;
        int minimumMoves = 0;

        int minSize = INT_MAX;
        vector<string> minPath;
        // Get All Possible Paths to Move Sofa
        for (auto path : movesPathToMoveSofa)
        {
            int newSize = path.size();
            if (minSize > newSize)
            {
                minSize = newSize;
                minPath = path;
            }

            // minSize = minSize > newSize ? newSize : minSize;

            // Print Possible Path
            cout << "Sofa Should Move " << newSize << " times and first it will move ";
            for (auto move : path)
            {
                cout << move << " -> ";
            }
            cout << " Destination Reached." << endl
                 << endl;
        }

        minimumMoves = minSize;
        cout << "Minimum Moves required are " << minimumMoves << " and path is: ";
        for (auto move : minPath)
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