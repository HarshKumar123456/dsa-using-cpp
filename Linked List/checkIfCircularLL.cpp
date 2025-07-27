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


bool checkIfCircularLL(Node* &head, Node* &tail) {
    // Base Case
    if (head == NULL || head == tail)
    {
        return true;
    }


    Node* temp = head->next;
    while (temp->next != NULL && temp->next != head)
    {
        cout << "In loop " << temp->data << endl;
        // Moving Forward
        temp = temp->next;
    }
    
    return (temp->next == head) ? true : false;

    // if (temp->next == head)
    // {
    //     return true;
    // }
    
    // return false;
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
    cout << "Tail is: " << tail->data << endl;
    if (checkIfCircularLL(head,tail))
    {
        cout << "Bhai yo to circular hai....." << endl;
    }
    else
    {
        cout << "Bhai yo to circular na hai....." << endl;
    }
    
    
    // Make Circular Linked List
    tail->next = head;


    if (checkIfCircularLL(head,tail))
    {
        cout << "Bhai yo to circular hai....." << endl;
    }
    else
    {
        cout << "Bhai yo to circular na hai....." << endl;
    }


    return 0;
}