#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void reverseFirstKElementsInQueue(queue<int> &kataar, int k) {
    // If queue is empty then return 
    if (kataar.empty() == true || kataar.size() < k)
    {
        return ;
    }
    
    // Put k elements in stack then pop from stack then push into queue
    stack<int> dibba;

    int count = k;
    while (count > 0)
    {
        int front = kataar.front();
        kataar.pop();

        dibba.push(front);
        count--;
    }
    
    while (dibba.empty() == false)
    {
        int top = dibba.top();
        dibba.pop();

        kataar.push(top);
    }

    count = kataar.size() - k;

    while (count > 0)
    {
        int front = kataar.front();
        kataar.pop();

        kataar.push(front);
        count--;
    }
    
    
}

int main() {

    vector<int> list = {1,2,3,4,5,6,7};
    int k = 4;
    queue<int> line;
    for(auto i : list) {
        line.push(i);
    }
    
    reverseFirstKElementsInQueue(line, k);

    while (line.empty() == false)
    {
        cout << line.front() << " ";
        line.pop();
    }
    cout << endl;
    
    return 0;
}