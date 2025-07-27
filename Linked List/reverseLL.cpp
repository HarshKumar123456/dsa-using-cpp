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



void reverseLLUsingIterativeApproach(Node* &head, Node* &tail) {
    // Case 1: Empty List 
    if (head == NULL)   
    {
        cout << "Bhai ye to Empty list hai." << endl;
        return ;
    }

    // Case 2: Single Element list
    if (head == tail)
    {
        cout << "Bhai single element list mein kya reverse karoon. " << endl;
        return ;
    }
    
    // Case 3: n-Element list
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;

    // Update Tail
    tail = head;

    while (forward != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = forward;
        forward = forward->next;
    }

    curr->next = prev;
    prev = curr;

    // Update Head
    head = curr;
    
}


void reverseLLUsingRecursiveApproach(Node* &head, Node* &tail){
    // Base Case
    if (head == NULL)
    {
        return ;
    }

    // Single Element Base Case
    if (head == tail)
    {
        return ;
    }
    
    // Extract One Node
    Node* extractedNode = head;

    // Move Head forward
    head = head->next;

    // Break Links from list
    extractedNode->next = NULL;

    // Reverse Remaining Part
    reverseLLUsingRecursiveApproach(head,tail);

    // Insert At Tail Extracted Node
    tail->next = extractedNode;
    tail = extractedNode;

}


int main() {
    Node *head = NULL;
    Node *tail = NULL;

    print(head);

    insertAtHead(head,tail,10);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,50);
    insertAtHead(head,tail,60);
    insertAtHead(head,tail,70);

    print(head);

    reverseLLUsingRecursiveApproach(head,tail);

    print(head);

    return 0;
}