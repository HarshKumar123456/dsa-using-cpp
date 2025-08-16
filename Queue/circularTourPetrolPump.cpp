#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findStartingPointFromWhereTravelPossible(vector<pair<int, int>> &petrolDistance)
{
    int size = petrolDistance.size();
    int startingPointIndex = -1;

    for (int i = 0; i < size; i++)
    {

        // Find If Travel Possible from Starting Point
        int currPointIndex = i;
        int nextPointIndex = currPointIndex + 1;

        int availablePetrol = petrolDistance[currPointIndex].first;
        int distanceToTravel = petrolDistance[currPointIndex].second;

        bool travelPossible = true;

        for (int j = 0; j < size; j++)
        {
            if (availablePetrol < distanceToTravel)
            {
                // Travel not Possible
                travelPossible = false;
                break;
            }

            // Travel Possible Then Move Distance
            availablePetrol = availablePetrol - distanceToTravel;

            // Since We have moved to this distance then update available petrol with this point and update the distance to travel

            /*
            These indexes are mistakes and causing infinite loops because it is modulo thus it may lead to backward or visiting same index again and again thus make them to only move forward and update the accessing in array by modulo size so that circular condition persists and you don't check twice same index

            currPointIndex = (currPointIndex+1) % size;
            nextPointIndex = (nextPointIndex+1) % size;


            */

            currPointIndex = currPointIndex + 1;
            nextPointIndex = nextPointIndex + 1;

            availablePetrol = availablePetrol + petrolDistance[currPointIndex % size].first;
            distanceToTravel = petrolDistance[currPointIndex % size].second;
        }

        if (travelPossible == true)
        {
            startingPointIndex = i;
            return startingPointIndex;
        }

        // Optimization to make O(N^2) to O(N)
        i = currPointIndex;
    }

    return startingPointIndex;
}


int findStartingPointFromWhereTravelPossibleOptimized(vector<pair<int,int>> &petrolDistance) {
    int size = petrolDistance.size();
    int startingPointIndex = 0;

    int kamiOfPetrol = 0;
    int balancePetrol = 0;

    for (int i = 0; i < size; i++)
    {

        // Find If Travel Possible from Starting Point
        int currPointIndex = i;
        int nextPointIndex = currPointIndex + 1;

        int availablePetrol = petrolDistance[currPointIndex].first;
        int distanceToTravel = petrolDistance[currPointIndex].second;

        // Add Petrol to Current Balance 
        balancePetrol += availablePetrol;

        // If Travel Possible then update balance petrol
        if (availablePetrol >= distanceToTravel)
        {
            balancePetrol -= distanceToTravel;
        }
        else {
            kamiOfPetrol += balancePetrol; 
            balancePetrol = 0;

            startingPointIndex = i + 1;
        }
        
    }

    if(balancePetrol >= kamiOfPetrol) {
        return startingPointIndex;
    }

    return -1;
}


int main()
{

    /*

    Input: gas[] = [4, 5, 7, 4], cost[]= [6, 6, 3, 5]
    Output: 2

    Input: gas[] = [1, 2, 3, 4, 5], cost[] = [3, 4, 5, 1, 2]
    Output: 3

    Input: gas[] = [3, 9], cost[] = [7, 6]
    Output: -1

    */
    vector<int> petrol = {1, 2, 3, 4, 5};
    vector<int> distance = {3, 4, 5, 1, 2};
    int size = petrol.size();

    vector<pair<int, int>> petrolDistance;

    for (int i = 0; i < size; i++)
    {
        petrolDistance.push_back(make_pair(petrol[i], distance[i]));
    }

    cout << "Bhai starting point is: " << findStartingPointFromWhereTravelPossible(petrolDistance) << endl;

    cout << "Bhai starting point is: " << findStartingPointFromWhereTravelPossibleOptimized(petrolDistance) << endl;

    

    
    return 0;
}