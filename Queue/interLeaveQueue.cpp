#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

queue<int> rearrangeQueue(queue<int> q)
{
    // Input Test Cases Include only Even sized Queues 

    // Is wale method mein last element ignore ho jata hai kyonki hamne second loop mein while(halfQueue) lagaya hai isliye for odd sized ye custom test cases run karne par sahi chalta hai
    queue<int> result;

    queue<int> temp;

    int sizeOfQueue = q.size();

    int halfQueue = sizeOfQueue / 2;

    while (halfQueue)
    {
        temp.push(q.front());
        q.pop();

        halfQueue--;
    }

    halfQueue = sizeOfQueue / 2;

    while (halfQueue)
    {
        result.push(temp.front());
        temp.pop();

        result.push(q.front());
        q.pop();

        halfQueue--;
    }

    return result;
}


queue<int> rearrangeQueueUsingStack(queue<int> q) {
        // Ismein Kyonki ham log same hi queue mein khel rahe hain isliye odd size inputs mein ye custom test cases mein wrong output dega halanki ham log even mein sahi se process karenge 
        int sizeOfQueue = q.size();

        int halfQueue = sizeOfQueue / 2;
    
        // Sabse Pahle Put into Stack to Reverse order mein ho jayega scene
        stack<int> s;
        
        while (halfQueue)
        {
            s.push(q.front());
            q.pop();
    
            halfQueue--;
        }
        
        
        // Ab Push Into Queue Again
        halfQueue = sizeOfQueue / 2;
        
        while (halfQueue)
        {
            q.push(s.top());
            s.pop();
    
            halfQueue--;
        }
        
        
        // Ab First Half ko pop karke push karte jao same queue mein hi taaki reversed half part saamne aa jaye 
        halfQueue = sizeOfQueue / 2;
        
        while (halfQueue)
        {
            int element = q.front();
            q.pop();
            
            q.push(element);
    
            halfQueue--;
        }
        
        // Ab Vaapis Stack mein daal do to ab original order mein aayega sab scene ab first enqueue from stack then dequeue and enqueue from queue
        halfQueue = sizeOfQueue / 2;
        
        while (halfQueue)
        {
            s.push(q.front());
            q.pop();
    
            halfQueue--;
        }
        
        
        halfQueue = sizeOfQueue / 2;
        
        while (halfQueue)
        {
            q.push(s.top());
            s.pop();
            
            q.push(q.front());
            q.pop();
    
            halfQueue--;
        }
        
        return q;
    }

void printQueue(queue<int> q) {
    while (!q.empty())
    {
        cout << q.front() << " " ;
        q.pop();
    }

    cout << endl << endl;
    
}

int main() {
    cout << endl;
    
    // Input Test Cases Include only Even sized Queues 
    vector<int> list = {1,2,3,4,5,6,7,8, 9};
    int sizeOfList = list.size();

    queue<int> q;
    for (int i = 0; i < sizeOfList; i++)
    {
        q.push(list[i]);
    }
    
    cout << "Before Interleaving Printing Queue: " << endl;
    printQueue(q);
    
    q = rearrangeQueueUsingStack(q);
    
    cout << "After Interleaving Printing Queue: " << endl;
    printQueue(q);
    
    return 0;
}