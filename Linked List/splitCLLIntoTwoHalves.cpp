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
    /*
    Here Do while to avoid conditions for temp that if single node then temp->next == head then we have to again do some first element print and all kind of things so just keep it simple or else do this:
    Node *temp = head;

    cout << temp->data << " ";

    while(temp-next != head) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl << endl;

    */
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
        // cout << "Now temp is: " << temp->data << endl;
    } while (temp != head);

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
        head->next = head;
        tail = head->next;
        return;
    }

    // Case 2: Single Element or n-Element List
    temp->next = head;
    tail->next = temp;
    head = temp;
}

void insertAtTail(Node *&head, Node *&tail, int element)
{
    // Node Creation
    Node *temp = new Node(element);

    // Case 1: Empty List
    if (tail == NULL)
    {
        tail = temp;
        tail->next = tail;
        head = tail->next;
        return;
    }

    // Case 2: Single Element or n-Element List
    tail->next = temp;
    temp->next = head;
    tail = temp;
}


Node* findMiddleElement(Node* &head) {
    // Approach 1: Find length and then get mid element by traversing the exact mid times 
    // Approach 2: Slow and fast pointers

    if (head == NULL || head->next == NULL || head->next == head)
    {
        return head;
    }
    

    Node* slowPointer = head;
    Node* fastPointer = head->next;

    while (fastPointer->next != NULL && fastPointer->next != head)
    {
        cout << "Now Slow and fast " << slowPointer->data << " - " << fastPointer->data << endl;
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next;
        
        if (fastPointer->next != NULL && fastPointer->next != head)
        {
            fastPointer = fastPointer->next;
        }
        
    }

    return slowPointer;
    
}

pair<Node*, Node*> splitCLLIntoTwoHalves(Node* &head, Node* &tail) {
    // Empty Case
    if (head == NULL || head->next == head)
    {
        return make_pair(head,tail);
    }

    // Find Middle Node
    Node* middleNode = findMiddleElement(head);

    // Assign Two CLL's Heads
    Node* firstHead = head;
    Node* secondHead = middleNode->next;

    // Fix Links
    tail->next = middleNode->next;
    middleNode->next = firstHead;

    return make_pair(firstHead,secondHead);
}


int main() {
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head,tail,10);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,50);

    insertAtTail(head,tail,1);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,5);

    print(head);
    cout << "Middle Element is: " <<  findMiddleElement(head)->data << "<------------" << endl;
    print(tail);

    cout << "Splitting into two halves: " << endl;
    print(head);
    pair<Node*, Node*> result = splitCLLIntoTwoHalves(head,tail);
    print(head);

    cout << "Printing Two Halves: " << endl;
    print(result.first);
    print(result.second);
    return 0;
}