#include <iostream>
#include <vector>
using namespace std;


void solve(int noOfDisks, 
vector<vector<int>> &moves, 
int source, int helper, int destination) {

    // Base Case 
    if(noOfDisks <= 1){
            // Make Move
            vector<int> move = {};
            move.push_back(source);
            move.push_back(destination);

            // Store Move
            moves.push_back(move);
            return ;
    }

    // Ek Case solve, Baaki recursion

    // Pahle n-1 disks ko helper par la do 
    solve(noOfDisks-1, moves, source, destination, helper);

    // phir main nth disk ko source se destination par rakh doonga
    // Make Move
    vector<int> move = {};
    move.push_back(source);
    move.push_back(destination);

    // Store Move
    moves.push_back(move);

    // Ab n-1 disks ko destination par la do 
    solve(noOfDisks-1, moves, helper, source, destination);
}



vector<vector<int>> towerOfHanoi(int n)
{
    vector<vector<int>> moves = {};

    int source = 1;
    int helper = 2;
    int destination = 3;

    solve(n, moves, source, helper, destination);
	cout << "We have taken TC: O(2^n) and SC: O(2^n)" << endl;

    return moves;
}



int main() {
	
	int noOfDisks;
	cout << "Please Enter no. of disks: ";
	cin >> noOfDisks;

	vector<vector<int>> moves = towerOfHanoi(noOfDisks);

	for(auto i : moves) {
		cout << i[0] << " to " << i[1] << endl;
	}

	return 0;
}
