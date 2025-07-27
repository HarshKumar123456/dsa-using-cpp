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

void insertAtPosition(Node *&head, Node *&tail, int element, int position)
{
    // Node Creation
    Node *temp = new Node(element);

    // Case 1: Empty List
    if (tail == NULL)
    {
        cout << "Bhai Empty List mein aap kahan insert at position kar rahe ho. " << endl;
        return;
    }

    // Case 2: Position equal to 1
    if (position == 1)
    {
        insertAtHead(head, tail, element);
        return;
    }

    // Case 3: Position greater than 1
    int count = 2;
    Node *prev = head;
    Node *curr = prev->next;

    while (curr != head && count < position)
    {
        // Moving Forward
        prev = curr;
        curr = curr->next;
        count++;
    }

    // Check if Valid Insert or Not
    if (count != position)
    {
        cout << "Bhai aap kya list se bahar kaise insert kar rahe ho. " << endl;
        delete temp;
        return;
    }

    // Check if Last Node insert condition
    if (curr == head)
    {
        tail = temp;
    }

    prev->next = temp;
    temp->next = curr;
}

void insertAfterValue(Node *&head, Node *&tail, int element, int value)
{
    // Node Creation
    Node *temp = new Node(element);

    // Case 1: Empty List
    if (tail == NULL)
    {
        cout << "Bhai Empty List mein aap kahan insert after position kar rahe ho. " << endl;
        return;
    }

    // Case 2: Value Present

    // Value at head
    if (head->data == value)
    {
        temp->next = head->next;
        head->next = temp;
        if (head == tail)
        {
            tail = temp;
        }

        return;
    }

    // Value not at head
    Node *curr = head->next;

    while (curr != head && curr->data != value)
    {
        // Moving Forward
        curr = curr->next;
    }

    if (curr->data == value)
    {
        // Making Links
        temp->next = curr->next;
        curr->next = temp;

        // Check if after last node insert
        if (curr == tail)
        {
            tail = temp;
        }

        return;
    }

    // Case 3: Value Absent
    cout << "Value:  " << value << " not found in the list. " << endl;
    delete temp;

    return;
}

void insertBeforeValue(Node *&head, Node *&tail, int element, int value)
{
    // Node Creation
    Node *temp = new Node(element);

    // Case 1: Empty List
    if (tail == NULL)
    {
        cout << "Bhai Empty List mein aap kahan insert before position kar rahe ho. " << endl;
        return;
    }

    // Case 2: Value Present
    Node *prev = head;
    Node *curr = head->next;

    while (curr != head && curr->data != value)
    {
        // Moving Forward
        prev = curr;
        curr = curr->next;
    }

    if (curr->data == value)
    {
        // Making Links
        prev->next = temp;
        temp->next = curr;

        // Check if after last node insert
        if (curr == head)
        {
            head = temp;
        }
        return;
    }

    // Case 3: Value Absent
    cout << "Value:  " << value << " not found in the list. " << endl;
    delete temp;

    return;
}

void deleteAtHead(Node *&head, Node *&tail)
{
    // Pick Node to delete
    Node *nodeToDelete = head;

    // Case 1: Empty list
    if (head == NULL)
    {
        cout << "Bhai Empty list mein kahan delete at head kar doon batao. " << endl;
        return;
    }

    // Case 2: Single Element List
    if (head == tail)
    {
        head = NULL;
        tail = NULL;

        // Since It is Circular Linked List Thus it will be pointing to itself thus need to do this breaking of Link here
        nodeToDelete->next = NULL;
        delete nodeToDelete;

        return;
    }

    // Case 3: n-element List

    // Move head to 1 node forward
    head = nodeToDelete->next;

    // Point Tail to new Head
    tail->next = head;

    // Break Link from list
    nodeToDelete->next = NULL;

    // Free Memory
    delete nodeToDelete;
}

void deleteAtTail(Node *&head, Node *&tail)
{
    // Pick Node to delete
    Node *nodeToDelete = tail;

    // Case 1: Empty list
    if (tail == NULL)
    {
        cout << "Bhai Empty list mein kahan delete at tail kar doon batao. " << endl;
        return;
    }

    // Case 2: Single Element List
    if (head == tail)
    {
        head = NULL;
        tail = NULL;

        // Since It is Circular Linked List Thus it will be pointing to itself thus need to do this breaking of Link here
        nodeToDelete->next = NULL;
        delete nodeToDelete;

        return;
    }

    // Case 3: n-element List

    // Move tail to 1 node backward
    Node *curr = head;
    while (curr->next != tail)
    {
        // Moving forward
        curr = curr->next;
    }

    tail = curr;
    tail->next = head;

    // Break Link from list
    nodeToDelete->next = NULL;

    // Free Memory
    delete nodeToDelete;
}

void deleteAtPosition(Node *&head, Node *&tail, int position)
{
    // Pick Node to delete
    Node *nodeToDelete = NULL;

    // Case 1: Empty list
    if (head == NULL)
    {
        cout << "Bhai Empty list mein kahan delete at position kar doon batao. " << endl;
        return;
    }

    // Case 2: Position equal to 1
    if (position == 1)
    {
        deleteAtHead(head, tail);
        return;
    }

    // Single Element Case handled
    if (head->next == head)
    {
        return;
    }

    // Case 3: Position greater than 1
    Node *prev = head;
    Node *curr = prev->next;
    Node *forward = curr->next;
    int count = 2;

    while (forward != head && count < position)
    {
        // Moving forward
        prev = curr;
        curr = forward;
        forward = forward->next;

        count++;
    }

    // Check if Valid Delete or Not
    if (count != position)
    {
        cout << "Bhai aap kya list se bahar kaise delete at position kar rahe ho. " << endl;
        return;
    }

    // Check if Last Node Delete condition
    if (curr->next == head)
    {
        tail = prev;
    }

    // Break Links from list
    prev->next = forward;
    curr->next = NULL;

    // Mark Node to delete
    nodeToDelete = curr;
    delete nodeToDelete;
}

void deleteAfterValue(Node *&head, Node *&tail, int value)
{
    // Pick Node to delete
    Node *nodeToDelete = NULL;

    // Case 1: Empty list
    if (head == NULL)
    {
        cout << "Bhai Empty list mein kahan delete after value kar doon batao. " << endl;
        return;
    }

    if (head->next == head)
    {
        nodeToDelete = head;

        head = NULL;
        tail = NULL;

        nodeToDelete->next = NULL;
        delete nodeToDelete;
        return;
    }

    // Case 2: Value is absent or present
    Node *curr = head;
    Node *forward = curr->next;

    while (curr->next != head && curr->data != value)
    {
        // Moving forward
        curr = curr->next;
        forward = curr->next;
    }

    // Check if current element data matches to the value
    if (curr->data == value)
    {
        // Mark Node to delete
        nodeToDelete = forward;

        curr->next = nodeToDelete->next;

        // If This is last node to be deleted
        if (nodeToDelete == tail)
        {
            tail = curr;
        }

        if (nodeToDelete == head)
        {
            head = curr->next;
        }

        nodeToDelete->next = NULL;
        delete nodeToDelete;

        return;
    }

    cout << "Value: " << value << " not found in the list." << endl;
}

void deleteBeforeValue(Node *&head, Node *&tail, int value)
{
    // Pick Node to delete
    Node *nodeToDelete = NULL;

    // Case 1: Empty list
    if (tail == NULL)
    {
        cout << "Bhai Empty list mein kahan delete before value kar doon batao. " << endl;
        return;
    }

    // Case 2: Value is absent or present

    // // Value at head
    // if (head->data == value)
    // {
    //     cout << "Bhai Ye to list ke starting par hai iske pichhe to koi value hi na jo delete karoon." << endl;
    //     return;
    // }

    // Single Element but value not found case
    if (head->next == head)
    {
        nodeToDelete = head;
        nodeToDelete->next = NULL;

        head = NULL;
        tail = NULL;

        delete nodeToDelete;
        return;
    }

    // Value somewhere in the middle or last
    Node *previousPrev = tail;
    Node *prev = head;
    Node *curr = prev->next;

    while (curr->next != head->next && curr->data != value)
    {
        // Moving forward
        previousPrev = prev;
        prev = curr;
        curr = curr->next;
    }

    // Check if current element data matches to the value
    if (curr->data == value)
    {
        // Mark Node to delete
        nodeToDelete = prev;

        // cout << "Deleting: " << nodeToDelete->data << " and prevPrev prev curr are: " << previousPrev->data << " -> " << prev->data << " -> " << curr->data << endl;
        // cout << "Head: " << head->data << " Tail: "  << tail->data << endl;

        previousPrev->next = curr;

        // Check if head is going to be deleted
        if (nodeToDelete == head)
        {
            head = curr;
        }

        // Break Links from list
        if (nodeToDelete == tail)
        {
            tail = previousPrev;
        }

        nodeToDelete->next = NULL;
        delete nodeToDelete;

        return;
    }

    cout << "Value: " << value << " not found in the list." << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    print(head);

    // insertAtHead(head,tail, 10);
    // insertAtHead(head,tail, 20);
    // insertAtHead(head,tail, 30);
    // insertAtHead(head,tail, 40);

    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);

    // insertAtPosition(head,tail,5,6);

    // insertAfterValue(head,tail, 7, 5);

    insertBeforeValue(head, tail, 8, 10);

    print(head);
    // deleteAtHead(head,tail);
    // deleteAtHead(head,tail);
    // deleteAtHead(head,tail);
    // deleteAtHead(head,tail);
    // deleteAtHead(head,tail);

    // deleteAtTail(head, tail);
    // deleteAtTail(head, tail);
    // deleteAtTail(head, tail);
    // deleteAtTail(head, tail);
    // deleteAtTail(head, tail);

    deleteAtPosition(head, tail, 1);
    // deleteAtPosition(head,tail,2);
    // deleteAtPosition(head,tail,1);
    // deleteAtPosition(head,tail,1);
    // deleteAtPosition(head,tail,1);

    print(head);
    print(tail);

    // deleteAfterValue(head,tail,2);
    // deleteAfterValue(head,tail,2);
    // deleteAfterValue(head,tail,2);
    // deleteAfterValue(head,tail,2);

    // deleteBeforeValue(head,tail,4);
    // deleteBeforeValue(head,tail,4);
    // deleteBeforeValue(head,tail,4);
    // deleteBeforeValue(head,tail,4);

    print(head);
    print(tail);

    return 0;
}