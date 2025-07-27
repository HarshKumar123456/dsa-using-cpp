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


Node* findMiddleElement(Node* &head) {
    // Approach 1: Find length and then get mid element by traversing the exact mid times 
    // Approach 2: Slow and fast pointers

    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    

    Node* slowPointer = head;
    Node* fastPointer = head->next;

    while (fastPointer->next != NULL)
    {
        cout << "Now Slow and fast " << slowPointer->data << " - " << fastPointer->data << endl;
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next;
        
        if (fastPointer->next != NULL)
        {
            fastPointer = fastPointer->next;
        }
        
    }

    return slowPointer;
    
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
    // insertAtHead(head,tail,70);

    print(head);

    Node* mid = findMiddleElement(head);

    cout << "Mid element is: " << mid->data << endl;

    return 0;
}