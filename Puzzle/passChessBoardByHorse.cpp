#include <iostream>
#include <vector>
using namespace std;

bool isSafePosition(vector<vector<int>> &chessBoard, pair<int, int> currentCoordinate)
{
    int chessBoardRows = chessBoard.size();
    int chessBoardColumns = chessBoard[0].size();

    int x = currentCoordinate.first;
    int y = currentCoordinate.second;

    if ((x < chessBoardRows && x >= 0) && (y < chessBoardColumns && y >= 0) && (chessBoard[x][y] != 1))
    {
        return true;
    }

    return false;
}

vector<pair<int, int>> findPossibleOptions(vector<vector<int>> &chessBoard, pair<int, int> currentCoordinate)
{
    vector<pair<int, int>> possibleOptions;

    pair<int, int> safeToMove;
    int x;
    int y;
    safeToMove.first = currentCoordinate.first;
    safeToMove.second = currentCoordinate.second;

    // Horse Can Move 2 Straight and One Left or Right

    // Move Two Up - Left
    // Reset to Current Coordinate
    x = currentCoordinate.first;
    y = currentCoordinate.second;

    safeToMove.second = y + 2;
    safeToMove.first = x - 1;

    if (isSafePosition(chessBoard, safeToMove) == true)
    {
        possibleOptions.push_back(safeToMove);
    }

    // Move Two Up - Right
    // Reset to Current Coordinate
    x = currentCoordinate.first;
    y = currentCoordinate.second;

    safeToMove.second = y + 2;
    safeToMove.first = x + 1;

    if (isSafePosition(chessBoard, safeToMove) == true)
    {
        possibleOptions.push_back(safeToMove);
    }

    // Move Two Down - Left
    // Reset to Current Coordinate
    x = currentCoordinate.first;
    y = currentCoordinate.second;

    safeToMove.second = y - 2;
    safeToMove.first = x - 1;

    if (isSafePosition(chessBoard, safeToMove) == true)
    {
        possibleOptions.push_back(safeToMove);
    }

    // Move Two Down - Right
    // Reset to Current Coordinate
    x = currentCoordinate.first;
    y = currentCoordinate.second;

    safeToMove.second = y - 2;
    safeToMove.first = x + 1;

    if (isSafePosition(chessBoard, safeToMove) == true)
    {
        possibleOptions.push_back(safeToMove);
    }

    // Move Two Left - Down
    // Reset to Current Coordinate
    x = currentCoordinate.first;
    y = currentCoordinate.second;

    safeToMove.second = y - 1;
    safeToMove.first = x - 2;

    if (isSafePosition(chessBoard, safeToMove) == true)
    {
        possibleOptions.push_back(safeToMove);
    }

    // Move Two Left - Up
    // Reset to Current Coordinate
    x = currentCoordinate.first;
    y = currentCoordinate.second;

    safeToMove.second = y + 1;
    safeToMove.first = x - 2;

    if (isSafePosition(chessBoard, safeToMove) == true)
    {
        possibleOptions.push_back(safeToMove);
    }

    // Move Two Right - Down
    // Reset to Current Coordinate
    x = currentCoordinate.first;
    y = currentCoordinate.second;

    safeToMove.second = y - 1;
    safeToMove.first = x + 2;

    if (isSafePosition(chessBoard, safeToMove) == true)
    {
        possibleOptions.push_back(safeToMove);
    }

    // Move Two Right - Up
    // Reset to Current Coordinate
    x = currentCoordinate.first;
    y = currentCoordinate.second;

    safeToMove.second = y + 1;
    safeToMove.first = x + 2;

    if (isSafePosition(chessBoard, safeToMove) == true)
    {
        possibleOptions.push_back(safeToMove);
    }

    return possibleOptions;
}

void findPossiblePaths(
    int &runCount,
    vector<vector<pair<int, int>>> &possiblePaths,
    vector<pair<int, int>> &path,
    vector<vector<int>> &chessBoard,
    pair<int, int> &startCoordinate,
    pair<int, int> &currentCoordinate)
{
    runCount++;

    int chessBoardRows = chessBoard.size();
    int chessBoardColumns = chessBoard[0].size();

    if (chessBoard.size() == 0)
    {
        return;
    }

    // cout << endl << endl <<  "___________Inside for: " << currentCoordinate.first << ", " << currentCoordinate.second << endl;
    // cout << "Path Till Now: " <<endl;
    // for (auto coordinate : path)
    // {
    //     cout << "[" << coordinate.first << ", " << coordinate.second << "]" << " -> ";
    // }
    // cout << endl;

    // cout << "Printing Chess Board: " << endl;
    // for (int row = 0; row < chessBoardRows; row++)
    // {
    //     for (int col = 0; col < chessBoardColumns; col++)
    //     {
    //         cout << chessBoard[row][col] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl << endl;


    vector<pair<int, int>> possibleOptions = findPossibleOptions(chessBoard, currentCoordinate);
    // cout << "Found possible options: " << endl;
    // for (auto coordinate : possibleOptions)
    // {
    //     cout << "[" << coordinate.first << ", " << coordinate.second << "]" << "    ";
    // }
    // cout << endl;

    int noOfPossibleOptions = possibleOptions.size();

    // Base Case If No Possible Paths Then Return
    if (noOfPossibleOptions == 0 && (currentCoordinate.first == startCoordinate.first && currentCoordinate.second == startCoordinate.second))
    {
        pair<int, int> option = currentCoordinate;
        // int x = option.first;
        // int y = option.second;

        // If All Nodes of Chess Board Are Visited then Add path
        for (int row = 0; row < chessBoardRows; row++)
        {
            for (int col = 0; col < chessBoardColumns; col++)
            {
                int x = row;
                int y = col;

                if (startCoordinate.first == x && startCoordinate.second == y)
                {
                    continue;;
                }
                
                if (chessBoard[x][y] == 0)
                {
                    return;
                }
                
            }
        }

        possiblePaths.push_back(path);

        return;
    }

    for (int i = 0; i < noOfPossibleOptions; i++)
    {
        pair<int, int> option = possibleOptions[i];
        pair<int, int> previousPositionCoordinate = currentCoordinate;

        int x = option.first;
        int y = option.second;
        // Push Into Path and Mark As Visited
        path.push_back(option);
        chessBoard[x][y] = 1;

        if (startCoordinate.first == x && startCoordinate.second == y)
        {
            chessBoard[x][y] = 0;
        }
        
        // Make Recursive Call 
        currentCoordinate.first = x;
        currentCoordinate.second = y;
        findPossiblePaths(runCount, possiblePaths, path, chessBoard, startCoordinate, currentCoordinate);

        // Pop from Path and Mark As Un-Visited
        path.pop_back();
        chessBoard[x][y] = 0;
        currentCoordinate.first = previousPositionCoordinate.first;
        currentCoordinate.second = previousPositionCoordinate.second;

        // cout << "_______BackTracking" << endl;
    }

    return;
}

int main()
{
    int runCount = 0;

    vector<vector<int>> chessBoard = {
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {1, 0, 0, 0},
    };

    vector<vector<int>> paths;

    vector<pair<int, int>> path;

    pair<int, int> startNode;

    vector<pair<int, int>> possibleOptions = {
        make_pair(0, 0),
        make_pair(0, 1),
        make_pair(0, 2),
        make_pair(0, 3),

        make_pair(1, 0),
        make_pair(1, 1),
        make_pair(1, 2),
        make_pair(1, 3),

        make_pair(2, 0),
        make_pair(2, 1),
        make_pair(2, 2),
        make_pair(2, 3), 

        make_pair(3, 0),
        make_pair(3, 1),
        make_pair(3, 2),
        make_pair(3, 3),
    };

    vector<vector<pair<int, int>>> possiblePaths;

    int possibleOptionsSize = possibleOptions.size();

    for (int i = 0; i < possibleOptionsSize; i++)
    {
        pair<int, int> currentOption = possibleOptions[i];

        startNode.first = currentOption.first;
        startNode.second = currentOption.second;

        cout << "{{{{{{{{{{{{}}}}}}}}}}}} Starting From: " << startNode.first << ", " << startNode.second << endl;
        path.push_back(startNode);
        findPossiblePaths(runCount, possiblePaths, path, chessBoard, startNode, currentOption);
        path.pop_back();
    }

    cout << endl
         << endl
         << "Printing " << possiblePaths.size() <<  " Possible Paths: " << endl;

    for (auto path : possiblePaths)
    {
        for (auto coordinate : path)
        {
            cout << "[" << coordinate.first << ", " << coordinate.second << "]" << " -> ";
        }
        cout << endl;
    }


    cout << "Ran " << runCount << " Times." << endl;

    return 0;
}