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

Node* checkIfCircularLL(Node *&head, Node *&tail)
{
    // Base Case
    if (head == NULL || tail->next == head)
    {
        return head;
    }

    // Kyonki ham starting node par le jakar phir traverse at same speed karte hain isliye ise hamne mid node detect ki tarah hare = head->next par nahin lagaya
    Node *turtle = head;
    Node *rabbit = head->next;

    while (rabbit != NULL && rabbit != turtle)
    {
        turtle = turtle->next;
        rabbit = rabbit->next;

        if (rabbit != NULL)
        {
            rabbit = rabbit->next;
        }
    }

    // cout << "Now rabbit and turtle: " << rabbit->data << "  " << turtle->data << endl;
    return (rabbit == turtle) ? rabbit : NULL;
}


void removeLoop(Node* &head, Node* &tail) {
    // Empty List Case
    if (head == NULL)
    {
        return;
    }

    // Find node of the cycle
    Node* inCycleNode = checkIfCircularLL(head,tail);

    if (inCycleNode == NULL)
    {
        cout << "Bhai ismein to loop hai hi na . " << endl;
        return ;
    }

    
    
    Node *turtle = head;
    Node *rabbit = inCycleNode;
    
    cout << "Starting node of the loop: " << turtle->data << " pointed by " << rabbit->data <<  endl; 


    while (rabbit->next != turtle)
    {
        turtle = turtle->next;
        rabbit = rabbit->next;
    }
    
    // Found starting point of cycle
    // cout << "Starting node of the loop: " << turtle->data << " pointed by " << rabbit->data <<  endl; 

    // Remove loop
    rabbit->next = NULL;
    
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    print(head);

    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    // insertAtHead(head, tail, 40);
    // insertAtHead(head, tail, 50);
    // insertAtHead(head, tail, 60);
    // insertAtHead(head, tail, 70);

    print(head);
    cout << "Tail is: " << tail->data << endl;
    if (checkIfCircularLL(head, tail))
    {
        cout << "Bhai yo to circular hai....." << endl;
    }
    else
    {
        cout << "Bhai yo to circular na hai....." << endl;
    }
    
    removeLoop(head,tail);
    cout << endl << endl;
    cout << endl << "After removing loop: " << endl;

    // Make Circular Linked List
    tail->next = head->next;
    cout << "Tail is: " << tail->data << endl;

    if (checkIfCircularLL(head, tail))
    {
        cout << "Bhai yo to circular hai....." << endl;
    }
    else
    {
        cout << "Bhai yo to circular na hai....." << endl;
    }

    removeLoop(head,tail);

    cout << endl << "After removing loop: " << endl;
    if (checkIfCircularLL(head, tail))
    {
        cout << "Bhai yo to circular hai....." << endl;
    }
    else
    {
        cout << "Bhai yo to circular na hai....." << endl;
    }


    return 0;
}