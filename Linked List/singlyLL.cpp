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

void insertAtPosition(Node *&head, Node *&tail, int element, int position)
{
    // Node Creation
    Node *temp = new Node(element);

    // Case 1: Empty List
    if (position == 1)
    {
        insertAtHead(head, tail, element);
        delete temp;
        return;
    }

    // Case 2: Single Element List
    if (head == NULL)
    {
        cout << "Bhai Empty list mein aap kahan insert at position kar rahe ho. " << endl;
        return;
    }

    // Case 3: n-Element List
    int count = 2;
    Node *prev = head;
    Node *curr = prev->next;

    while (count < position && curr != NULL)
    {
        // Move Forward
        prev = curr;
        curr = curr->next;

        // Update Step
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
    if (curr == NULL)
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

    // Case 1: List is Empty
    if (head == NULL)
    {
        cout << "Bhai Empty list mein kahan after value add kar rahe ho aap." << endl;
        delete temp;
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
        // If last Node is matched value
        if (curr->next == NULL)
        {
            tail = temp;
        }

        temp->next = curr->next;
        curr->next = temp;

        return;
    }

    cout << "Value: " << value << " not found in the list." << endl;
    delete temp;
}

void insertBeforeValue(Node *&head, Node *&tail, int element, int value)
{
    // Node Creation
    Node *temp = new Node(element);

    // Case 1: List is Empty
    if (head == NULL)
    {
        cout << "Bhai Empty list mein kahan before value add kar rahe ho aap." << endl;
        delete temp;
        return;
    }

    // Case 2: Value is absent or present

    // Value at head
    if (head->data == value)
    {
        insertAtHead(head, tail, element);
        delete temp;
        return;
    }

    // Single Element List Case handled
    if (head->next == NULL)
    {
        cout << "Value: " << value << " not found in the list." << endl;
        return;
    }

    // Value somewhere in the middle or last
    Node *prev = head;
    Node *curr = prev->next;

    while (curr->next != NULL && curr->data != value)
    {
        // Moving forward
        prev = curr;
        curr = curr->next;
    }

    // Check if current element data matches to the value
    if (curr->data == value)
    {
        temp->next = curr;
        prev->next = temp;
        return;
    }

    cout << "Value: " << value << " not found in the list." << endl;
    delete temp;
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
        delete nodeToDelete;

        return;
    }

    // Case 3: n-element List

    // Move head to 1 node forward
    head = nodeToDelete->next;

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
        delete nodeToDelete;

        return;
    }

    // Case 3: n-element List

    // Reach to second last node
    Node *temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }

    // Break Link from list
    temp->next = NULL;

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

    // Break Links from list
    prev->next = curr->next;
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

    // Case 2: Value is absent or present
    Node *curr = head;
    Node *forward = curr->next;

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

        curr->next = nodeToDelete->next;
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

    print(head);

    insertAtPosition(head, tail, 50, 1);
    insertAtPosition(head, tail, 40, 1);
    insertAtPosition(head, tail, 30, 1);
    print(head);

    insertAtPosition(head, tail, 30, 2);
    print(head);

    insertAtTail(head, tail, 20);
    print(head);

    insertAtPosition(head, tail, 300, 5);
    print(head);

    insertAfterValue(head, tail, 4, 30);
    print(head);

    insertBeforeValue(head, tail, 1, 300);
    print(head);

    deleteAtHead(head, tail);
    print(head);

    deleteAtTail(head, tail);
    print(head);

    deleteAtPosition(head, tail, 6);
    print(head);

    deleteAfterValue(head, tail, 1);
    print(head);

    deleteBeforeValue(head, tail, 10);
    print(head);

    insertAtPosition(head,tail,100,6);
    print(head);

    return 0;
}