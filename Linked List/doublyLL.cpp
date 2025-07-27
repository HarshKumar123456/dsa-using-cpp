#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
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

void printTail(Node *&tail)
{
    cout << endl
         << "Printing List from tail to head: " << endl;

    // Case 1: Empty List
    if (tail == NULL)
    {
        cout << "Bhai List to Empty hai." << endl
             << endl;
        return;
    }

    // Case 2: Single Node or Multiple Node
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
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
    head->prev = temp;
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
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node *&head, Node *&tail, int element, int position)
{
    // Node Creation
    Node *temp = new Node(element);

    // Case 1: Position equal to 1
    if (position == 1)
    {
        insertAtHead(head, tail, element);
        delete temp;
        return;
    }

    // Case 2: Position greater than equal to 1
    Node *prev = NULL;
    Node *curr = head;

    int count = 1;
    while (curr != NULL && count != position)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }

    if (count == position)
    {
        prev->next = temp;
        temp->prev = prev;
        temp->next = curr;

        if (curr == NULL)
        {
            // Handle Tail updation
            tail = temp;
        }
        else
        {
            // Handle linking to new node
            curr->prev = temp;
        }
    }
    else
    {
        // Handle Out of position type things
        cout << "Bhai List se bahar aap kahan insert at position kar rahe ho." << endl;
        delete temp;
        return;
    }
}

void insertAfterValue(Node *&head, Node *&tail, int element, int value)
{
    // Node Creation
    Node *temp = new Node(element);

    // Case 1: Empty list
    if (head == NULL)
    {
        cout << "Bhai Empty list mein aap kahan insert after value kar rahe ho. " << endl;
        delete temp;
        return;
    }

    // Case 2: Single or N-Element list
    Node *curr = head;

    while (curr->next != NULL && curr->data != value)
    {
        // Moving Forward
        curr = curr->next;
    }

    // Value is absent
    if (curr->data != value)
    {
        cout << "Value: " << value << " not found in the list. " << endl;
        delete temp;
        return;
    }
    // Value is present
    else
    {
        temp->next = curr->next;
        temp->prev = curr;

        // Check If After last node insert or not
        if (curr == tail)
        {
            tail = temp;
        }
        // Make Linking to the new node
        else
        {
            curr->next->prev = temp;
        }

        curr->next = temp;
    }
}

void insertBeforeValue(Node *&head, Node *&tail, int element, int value)
{
    // Node Creation
    Node *temp = new Node(element);

    // Case 1: Empty list
    if (head == NULL)
    {
        cout << "Bhai Empty list mein aap kahan insert before value kar rahe ho. " << endl;
        delete temp;
        return;
    }

    // Case 2: Single or N-Element list
    Node *curr = head;

    while (curr->next != NULL && curr->data != value)
    {
        // Moving Forward
        curr = curr->next;
    }

    // Value is absent
    if (curr->data != value)
    {
        cout << "Value: " << value << " not found in the list. " << endl;
        delete temp;
        return;
    }
    // Value is present
    else
    {
        temp->next = curr;
        temp->prev = curr->prev;

        // Check If Before first node insert or not
        if (curr == head)
        {
            head = temp;
        }
        // Make Linking to the new node
        else
        {
            curr->prev->next = temp;
        }

        curr->prev = temp;
    }
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
        // Optional
        // Because as per our destructor it will delete it smoothly as it has next equal to NULL already
        nodeToDelete->next = NULL;
        nodeToDelete->prev = NULL;
        delete nodeToDelete;

        return;
    }

    // Case 3: n-element List

    // Move head to 1 node forward
    head = nodeToDelete->next;

    // Break Link from list
    head->prev = NULL;
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

        // Optional
        // Because as per our destructor it will delete it smoothly as it has next equal to NULL already
        nodeToDelete->next = NULL;
        nodeToDelete->prev = NULL;
        delete nodeToDelete;

        return;
    }

    // Case 3: n-element List

    // Reach to second last node
    Node *temp = tail->prev; // Since It is DLL No need to traverse till next node is tail

    // Break Link from list
    temp->next = NULL;
    nodeToDelete->prev = NULL;

    // Update Tail
    tail = temp;

    // Free Memory
    delete nodeToDelete;
}

void deleteAtPosition(Node *&head, Node *&tail, int position)
{
    // Pick Node to delete
    Node *nodeToDelete = NULL;

    // Case 1: Empty list
    if (tail == NULL)
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

    // Single Element List Case handled
    if (head->next == NULL)
    {
        cout << "Bhai aap kya list se bahar kaise delete at position kar rahe ho. " << endl;
        return;
    }

    // Case 3: Position greater than 1
    int count = 2;
    Node *prev = head;
    Node *curr = prev->next;

    while (count < position && curr->next != NULL)
    {
        // Move Forward
        prev = curr;
        curr = curr->next;

        // Update Step
        count++;
    }

    // Check if Valid Delete or Not
    if (count != position)
    {
        cout << "Bhai aap kya list se bahar kaise delete at position kar rahe ho. " << endl;
        return;
    }

    // Check if Last Node Delete condition
    if (curr->next == NULL)
    {
        tail = prev;
    }
    else
    {
        curr->next->prev = prev;
    }

    // Break Links from list
    prev->next = curr->next;
    curr->next = NULL;
    curr->prev = NULL;

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

    // Case 2: Value is absent or present
    Node *curr = head;

    while (curr->next != NULL && curr->data != value)
    {
        // Moving forward
        curr = curr->next;
    }

    // Check if current element data matches to the value
    if (curr->data == value)
    {
        // Mark Node to delete
        nodeToDelete = curr->next;

        // If last Node is matched value
        if (nodeToDelete == NULL)
        {
            cout << "Bhai Ye to list ke end par hai iske aage to koi value hi na jo delete karoon." << endl;
            return;
        }

        // If This is last node to be deleted
        if (nodeToDelete == tail)
        {
            tail = curr;
        }
        else
        {
            nodeToDelete->next->prev = curr;
        }

        // Break Links from list
        curr->next = nodeToDelete->next;
        nodeToDelete->prev = NULL;
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

    // Value at head
    if (head->data == value)
    {
        cout << "Bhai Ye to list ke starting par hai iske pichhe to koi value hi na jo delete karoon." << endl;
        return;
    }

    // Single Element but value not found case
    if (head->next == NULL)
    {
        cout << "Value: " << value << " not found in the list." << endl;
        return;
    }

    // Value somewhere in the middle or last
    Node *previousPrev = NULL;
    Node *prev = head;
    Node *curr = prev->next;

    while (curr->next != NULL && curr->data != value)
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

        // Check if head is going to be deleted
        if (nodeToDelete == head)
        {
            head = curr;
        }

        // Break Links from list
        if (previousPrev != NULL)
        {
            previousPrev->next = curr;
        }

        nodeToDelete->next = NULL;
        nodeToDelete->prev = NULL;
        delete nodeToDelete;

        return;
    }

    cout << "Value: " << value << " not found in the list." << endl;
}

void printHeadTail(Node *&head, Node *&tail)
{
    if (head == tail && tail == NULL)
    {
        cout << "Bhai Empty list mein kahan se head tail print kar doon. " << endl;
        return;
    }

    if (head == NULL)
    {
        cout << "Bhai head pointing to NULL ye condition hai . " << endl;
    }
    else
    {
        cout << "Head: " << head->data << endl;
    }

    if (tail == NULL)
    {
        cout << "Bhai head pointing to NULL ye condition hai . " << endl;
    }
    else
    {
        cout << "Tail: " << tail->data << endl;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtPosition(head, tail, 10, 1);
    insertAtPosition(head, tail, 20, 2);
    insertAtPosition(head, tail, 30, 3);

    insertBeforeValue(head, tail, 40, 30);
    // print(head);
    // printTail(tail);

    printHeadTail(head, tail);

    cout << "\n\nDeleting at Head : " << endl;
    deleteAtHead(head, tail);
    print(head);
    printHeadTail(head, tail);

    cout << "\n\nDeleting at Tail : " << endl;
    print(head);

    deleteAtTail(head, tail);

    print(head);

    cout << "\n\nDeleting at Position : " << endl;
    insertAtHead(head, tail, 1);
    print(head);
    deleteAtPosition(head, tail, 1);

    print(head);
    printHeadTail(head, tail);

    cout << "\n\nDeleting after value : " << endl;
    insertAtHead(head, tail, 1);
    print(head);
    deleteAfterValue(head, tail, 1);
    deleteAfterValue(head, tail, 1);
    deleteAtHead(head, tail);
    deleteAfterValue(head, tail, 1);

    print(head);
    printHeadTail(head, tail);

    cout << "\n\nDeleting Before value : " << endl;
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    // insertAtHead(head,tail,40);
    // insertAtHead(head,tail,30);
    print(head);

    deleteBeforeValue(head, tail, 10);
    print(head);
    printHeadTail(head, tail);

    return 0;
}