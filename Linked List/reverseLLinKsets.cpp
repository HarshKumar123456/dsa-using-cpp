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

Node *reverseLLinKSets(Node *&head, Node *&tail, int K)
{
    // Base Case
    if (head == NULL || head->next == NULL)
    {
        tail = head;
        // cout << "Returning the head: " << head->data << endl;
        return head;
    }

    // cout << "For the head: "<< head->data << " in the Approach 1: "<< endl << endl;

    // Ek case solve baaki recursion
    int count = 1;
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = curr->next;

    while (forward != NULL && count < K)
    {
        // Reversing Links
        curr->next = prev;

        // Moving Forward
        prev = curr;
        curr = forward;
        forward = forward->next;
        count++;
    }

    curr->next = prev;
    prev = curr;

    if (forward != NULL)
    {
        // cout << "In Approach 1 Making recursive call for:  " << forward->data << " and now head is: " << head->data << endl;
        head->next = reverseLLinKSets(forward, tail, K);
        // cout << "Now head->next is: " << head->next->data << endl;

        // print(head);
    }

    // cout << "Returning the Curr: " << curr->data << endl;
    head = curr;
    // print(head);
    return head;
}

Node *reverseKSets(Node *&head, Node *&tail, int K)
{
    // Base Case
    if (head == NULL || head->next == NULL)
    {
        tail = head;
        return head;
    }

    // Ek case solve baaki recursion
    int count = 0;
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;

    while (curr != NULL && count < K)
    {
        // Having Track of Next Node in List
        forward = curr->next;

        // Reversing Links
        curr->next = prev;

        // Moving Forward
        prev = curr;
        curr = forward;
        count++;
    }

    if (forward != NULL)
    {
        head->next = reverseKSets(forward, tail, K);
    }
    
    return prev;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    print(head);

    int K = 5;

    Node *revHead = reverseLLinKSets(head, tail, K);
    cout << "Approach 1: ";
    print(revHead);


    // Node *revHead2 = reverseKSets(head, tail, K);
    // cout << "Approach 2: ";
    // print(revHead2);

    return 0;
}