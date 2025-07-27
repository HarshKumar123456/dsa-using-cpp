#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        if (this != NULL)
        {
            cout << "Freeing memory for: " << this->data << endl;
            if (this->next != NULL)
            {
                delete this->next;
                this->next = NULL;
            }
        }
    }
};

void print(Node *&head)
{

    cout << endl
         << "Printing List: " << endl;

    // Case 1: Empty List
    if (head == NULL)
    {
        cout << "Bhai List to Empty hai." << endl
             << endl;
        return;
    }

    // Case 2: Single Node or Multiple Node
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl
         << endl;
}

void insertAtHead(Node *&head, Node *&tail, int element)
{

    // Node Creation
    Node *temp = new Node(element);

    // Case 1: Empty List
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }

    // Case 2: Single Element List OR n-Element List
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&head, Node *&tail, int element)
{
    // Node Creation
    Node *temp = new Node(element);

    // Case 1: Empty List
    if (tail == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }

    // Case 2: Single Element List OR n-Element List
    tail->next = temp;
    tail = temp;
}


void solve(Node *&first, Node *&second){
    // Empty Cases
    if (first == NULL || second == NULL)
    {
        return ;
    }

    // n-Element Cases
    Node* curr1 = first;
    Node* curr2 = second;

    Node* next1 = first->next;
    Node* next2 = second->next;
    
    while (next1 != NULL && curr2 != NULL)
    {
        cout << "In Loop " << endl;
        // If second list's current element can be inserted between first list nodes
        
        if (curr1->data <= curr2->data && curr2->data <= next1->data)
        {
            // cout << "Inserting curr2:  " << curr2->data << " between " << curr1->data << " and  " << next1->data << endl;  
            // Insert between the first list nodes
            curr1->next = curr2;
            curr2->next = next1;

            // Move Forward
            curr1 = curr1->next;

            curr2 = next2;
            if (next2 != NULL)
            {
                next2 = next2->next;
            }
            
        }
        else{
            curr1 = next1;
            next1 = next1->next;
        }

    }

    if (next1 == NULL && curr2 != NULL)
    {
        cout << "Bhai pahli list hai khali isliye ismein daal rahe " << endl;
        curr1->next = curr2;
    }
    
    
}

Node *mergeTwoSortedLL(Node *&first, Node *&second)
{
    // Empty Cases
    if (first == NULL)
    {
        return second;
    }

    if (second == NULL)
    {
        return first;
    }

    // n-Element Cases
    if (first->data <= second->data)
    {
        cout << "Sending first second " << endl;
        solve(first, second);
        return first;
    }
    else
    {
        cout << "Sending second first " << endl;
        solve(second, first);
        return second;
    }
}

int main()
{
    Node *firstHead = NULL;
    Node *firstTail = NULL;

    print(firstHead);
    
    insertAtTail(firstHead, firstTail, 10);
    insertAtTail(firstHead, firstTail, 20);
    insertAtTail(firstHead, firstTail, 30);
    insertAtTail(firstHead, firstTail, 40);
    insertAtTail(firstHead, firstTail, 50);
    insertAtTail(firstHead, firstTail, 60);
    insertAtTail(firstHead, firstTail, 70);
    
    cout << "Bhai printing first list: " << endl;
    print(firstHead);

    Node *secondHead = NULL;
    Node *secondTail = NULL;

    print(secondHead);
    
    insertAtTail(secondHead, secondTail, 1);
    insertAtTail(secondHead, secondTail, 2);
    insertAtTail(secondHead, secondTail, 3);
    insertAtTail(secondHead, secondTail, 4);
    insertAtTail(secondHead, secondTail, 5);
    insertAtTail(secondHead, secondTail, 6);
    insertAtTail(secondHead, secondTail, 7);
    
    cout << "Bhai printing second list: " << endl;
    print(secondHead);


    Node* sortedHead = mergeTwoSortedLL(firstHead,secondHead);
    print(sortedHead);

    return 0;
}