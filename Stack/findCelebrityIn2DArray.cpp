#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int findIndexOfCelebrityUsingLoops(vector<vector<int>> &matrix)
{

    // Find order of Matrix
    int orderOfMatrix = matrix[0].size();
    int celebrity = -1;
    bool isPotentialCandidateForCelebrity = false;

    // Check for every row if it has all 0s in it then he is potential candidate as it knows no one
    for (int row = 0; row < orderOfMatrix; row++)
    {
        isPotentialCandidateForCelebrity = true;
        for (int col = 0; col < orderOfMatrix; col++)
        {
            if (matrix[row][col] == 1)
            {
                isPotentialCandidateForCelebrity = false;
                break;
            }
        }

        if (isPotentialCandidateForCelebrity == true)
        {
            // Condition 1 satisfied: It knows no one
            // Check If everyone knows this candidate
            for (int i = 0; i < orderOfMatrix; i++)
            {
                if (i != row && matrix[i][row] == 0)
                {
                    isPotentialCandidateForCelebrity = false;
                    break;
                }
            }

            if (isPotentialCandidateForCelebrity == true)
            {
                celebrity = row;
                return celebrity;
            }
        }
    }

    return celebrity;
}

bool knows(vector<vector<int>> &matrix, int prevCandidate, int candidate)
{

    if (matrix[prevCandidate][candidate] == 0)
    {
        return false;
    }

    return true;
}

int findIndexOfCelebrityUsingStack(vector<vector<int>> &matrix)
{
    // First of All know that there is confirm 1 celebrity in the matrix
    // To agar koi praani kisi ko nahin janta to vo jise nahin janta vo to pakka celebrity nahin ho sakta to use discard kardo as potential candidate se

    int orderOfMatrix = matrix[0].size();
    stack<int> s;

    for (int candidate = 0; candidate < orderOfMatrix; candidate++)
    {
        // Pop from stack and find if it knows the candidate if not then discard this candidate if yes then discard the candidate in stack
        if (s.empty() == true)
        {
            s.push(candidate);
            continue;
        }

        int prevCandidate = s.top();
        s.pop();

        if (knows(matrix, prevCandidate, candidate) == true)
        {
            s.push(candidate);
        }
        else
        {
            s.push(prevCandidate);
        }
    }

    // Now for sure we will be left with the one element in the stack
    int potentialCandidate = -1;
    if (s.empty() != true)
    {
        cout << "I am running in the loop. " << endl;
        potentialCandidate = s.top();
        s.pop();

        // Check for Conditions

        // If it Knows no one
        for (int col = 0; potentialCandidate >= 0 && col < orderOfMatrix; col++)
        {
            if (matrix[potentialCandidate][col] == 1)
            {
                potentialCandidate = -1;
                break;
            }
        }

        // If it Known by everyone
        for (int row = 0; potentialCandidate >= 0 && row < orderOfMatrix; row++)
        {
            if (row != potentialCandidate && matrix[row][potentialCandidate] == 0)
            {
                potentialCandidate = -1;
                break;
            }
        }
    }


    return potentialCandidate;
}

int main()
{
    cout << endl;

    // It confirms that there is 1 Celebrity in the Matrix
    // Celebrity is the person who is known by evryone and knows no one
    vector<vector<int>> matrix = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
    };
    int celebrity = findIndexOfCelebrityUsingStack(matrix);
    cout << "Bro Celebrity is: " << celebrity << endl;

    cout << endl;
    return 0;
}