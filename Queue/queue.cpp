#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;




int main() {
    cout << endl;

    queue<int> q;
    queue<int> line;

    line.push(1);
    line.push(2);
    line.push(3);
    line.push(4);
    line.push(5);

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    q.pop();
    q.pop();

    q.swap(line);
    
    cout << "Queue size is: " << q.size() << endl;

    cout << "Queue's front is: " << q.front() << " Queue's Back is: " << q.back() << endl; 

    if (q.empty())
    {
        cout << "Bhai Queue to Empty hai." << endl;
    }
    else
    {
        cout << "Bhai Queue to Empty nahin hai." << endl;
    }
    
    

    cout << endl;
    return 0;
}