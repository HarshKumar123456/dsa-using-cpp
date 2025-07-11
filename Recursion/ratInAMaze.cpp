#include <iostream>
#include <vector>
using namespace std;

bool isSafeMove(vector<vector<int>> &maze, vector<vector<int>> &visitedCoordinates, pair<int, int> newCoordinate)
{
	// cout << "In is Safe move" << endl;
	int rows = maze.size() - 1;
	int cols = maze.size() - 1;

	int x = newCoordinate.first;
	int y = newCoordinate.second;

	// cout << x << ", " << y << endl;

	if ((x <= rows && y <= cols) && (x >= 0 && y >= 0) && (visitedCoordinates[x][y] != 1) && (maze[x][y] != 0))
	{
		// cout << "Safe to move " << endl;
		return true;
	}
	

	// cout << "Visited " << visitedCoordinates[x][y] << endl;
	// cout << "Maze " << maze[x][y] << endl;
	// cout << "Not Safe to move " << endl;
	return false;
}

void solve(vector<vector<int>> &maze, vector<vector<int>> &visitedCoordinates, vector<string> &possiblePaths, pair<int, int> sourceCoordinate, pair<int, int> destinationCoordinate, string &path)
{
	// cout << "Came Here" << endl;

	int x = sourceCoordinate.first;
	int y = sourceCoordinate.second;

	// cout << x << " " << y << endl;

	int newX = x;
	int newY = y;

	pair<int, int> newCoordinate;

	// Base case
	if (x > destinationCoordinate.first || x < 0 || y > destinationCoordinate.second || y < 0)
	{
		return;
	}

	if (x == destinationCoordinate.first && y == destinationCoordinate.second)
	{
		// cout << "Bhai added Path: " << path << endl;
		possiblePaths.push_back(path);
		return;
	}

	// Move Down
	newX = x + 1;
	newY = y;
	// cout << "Moving Down " << x << ", " << y << " to " << newX << ", " << newY << endl;
	newCoordinate = {newX, newY};
	if (isSafeMove(maze, visitedCoordinates, newCoordinate))
	{
		path.push_back('D');
		visitedCoordinates[newX][newY] = 1;
		
		solve(maze, visitedCoordinates, possiblePaths, newCoordinate, destinationCoordinate, path);
		
		visitedCoordinates[newX][newY] = 0;
		path.pop_back();
	}
	
	// Move Up
	newX = x - 1;
	newY = y;
	// cout << "Moving Up " << x << ", " << y << " to " << newX << ", " << newY << endl;
	newCoordinate = {newX, newY};
	if (isSafeMove(maze, visitedCoordinates, newCoordinate))
	{
		path.push_back('U');
		visitedCoordinates[newX][newY] = 1;

		solve(maze, visitedCoordinates, possiblePaths, newCoordinate, destinationCoordinate, path);

		visitedCoordinates[newX][newY] = 0;
		path.pop_back();
	}

	// Move Left
	newX = x;
	newY = y - 1;
	// cout << "Moving Left " << x << ", " << y << " to " << newX << ", " << newY << endl;
	newCoordinate = {newX, newY};
	if (isSafeMove(maze, visitedCoordinates, newCoordinate))
	{
		path.push_back('L');
		visitedCoordinates[newX][newY] = 1;
		
		solve(maze, visitedCoordinates, possiblePaths, newCoordinate, destinationCoordinate, path);

		visitedCoordinates[newX][newY] = 0;
		path.pop_back();
	}
	
	// Move Right
	newX = x;
	newY = y + 1;
	// cout << "Moving Right " << x << ", " << y << " to " << newX << ", " << newY << endl;
	newCoordinate = {newX, newY};
	if (isSafeMove(maze, visitedCoordinates, newCoordinate))
	{
		path.push_back('R');
		visitedCoordinates[newX][newY] = 1;

		solve(maze, visitedCoordinates, possiblePaths, newCoordinate, destinationCoordinate, path);

		visitedCoordinates[newX][newY] = 0;
		path.pop_back();
	}
}

vector<string> findPossiblePathsForRatToReachBottomRight(vector<vector<int>> maze)
{
	int rows = maze.size() - 1;
	int cols = maze.size() - 1;

	pair<int, int> sourceCoordinate = {0, 0};
	pair<int, int> destinationCoordinate = {rows, cols};

	vector<string> possiblePaths = {};

	if(maze[0][0] == 0) {
		return possiblePaths;
	}

	vector<vector<int>> visitedCoordinates(rows + 1, vector<int>(cols + 1, 0));
	string path = "";

	// cout << destinationCoordinate.first << ", " << destinationCoordinate.second << endl;

	// for (auto i : visitedCoordinates)
	// {
	// 	for (auto j : i)
	// 	{
	// 		cout << j << " ";
	// 	}
	// 	cout << endl;

	// }

	visitedCoordinates[0][0] = 1;

	solve(maze, visitedCoordinates, possiblePaths, sourceCoordinate, destinationCoordinate, path);

	// cout << "Came Here - ---- 1" << endl;
	cout << "We have taken TC: O(4^(n^2)) and SC: O(n^2)" << endl;

	return possiblePaths;
}

int main()
{

	int size;
	cout << "Enter size of Maze: ";
	cin >> size;

	vector<vector<int>> maze(size, vector<int>(size));

	cout << "Enter " << size * size << " Elements: ";
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> maze[i][j];
		}
	}

	cout << "Printing the Maze: " << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}

	vector<string> possiblePathsForRatToReachBottomRight = findPossiblePathsForRatToReachBottomRight(maze);

	for (auto i : possiblePathsForRatToReachBottomRight)
	{
		cout << i << endl;
	}

	return 0;
}
