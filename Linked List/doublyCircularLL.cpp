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
        tail = temp;
    }
    else
    {
        // Case 2: Single Element List OR n-Element List
        temp->next = head;
        head->prev = temp;
        head = temp;
    }

    head->prev = tail;
    tail->next = head;
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
    }
    else
    {
        // Case 2: Single Element List OR n-Element List
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }

    head->prev = tail;
    tail->next = head;
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


    if (head == NULL)
    {
        cout << "Bhai Empty List Mein kahan insert at position kar doon batao. " << endl;
        return ;
    }

    // Case 2: Position greater than equal to 1
    Node *prev = head;
    Node *curr = head->next;

    int count = 2;
    while (curr != head && count != position)
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
        curr->prev = temp;

        if (curr == head)
        {
            // Handle Tail updation
            tail = temp;

            // Optional for Better Readability
            // head->prev = tail;
            // tail->next = head;
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

    while (curr->next != head && curr->data != value)
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

        curr->next->prev = temp;
        curr->next = temp;

        // Check If After last node insert or not
        if (curr == tail)
        {
            tail = temp;
        }
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

    while (curr->next != head && curr->data != value)
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
        curr->prev->next = temp;
        curr->prev = temp;

        // Check If Before first node insert or not
        if (curr == head)
        {
            head = temp;
        }
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
        head = NULL;
        tail = NULL;
    }
    else
    {

        // Case 3: n-element List

        // Move head to 1 node forward
        head = nodeToDelete->next;

        // Update the Circular Condition
        tail->next = head;
        head->prev = tail;
    }

    // Break Link from list
    nodeToDelete->next = NULL;
    nodeToDelete->prev = NULL;

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
    }
    else {   
        // Case 3: n-element List

        // Move Tail to 1 Node Previous
        tail = tail->prev;

        // Update the Circular Condition
        tail->next = head;
        head->prev = tail;

    }
    
    nodeToDelete->next = NULL;
    nodeToDelete->prev = NULL;

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


    // Case 3: Position greater than 1
    int count = 1;
    Node *curr = head;

    while (count < position && curr->next != head)
    {
        // Move Forward
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

    // Break Links from list
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;

     // Check if Last Node Delete condition
    if (curr == tail)
    {
        tail = curr->prev;
    }


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
    
    // Single Element Case
    if (head == tail && head->data == value)
    {
        nodeToDelete = head;
        head = NULL;
        tail = NULL;
        
        nodeToDelete->prev = NULL;
        nodeToDelete->next = NULL;
        delete nodeToDelete;

        return ;
    }
    
    
    // Case 2: Value is absent or present
    Node *curr = head;
    
    while (curr->next != head && curr->data != value)
    {
        // Moving forward
        curr = curr->next;
    }
    

    // Check if current element data matches to the value
    if (curr->data == value)
    {
        // Mark Node to delete
        nodeToDelete = curr->next;

        // Make Circular Condition 
        curr->next = nodeToDelete->next;
        nodeToDelete->next->prev = curr;

        // If This is last node to be deleted
        if (nodeToDelete == tail)
        {
            tail = curr;
        }


        // Break Links from list
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
    // Single Element Case
    if (head == tail && head->data == value)
    {
        nodeToDelete = head;
        head = NULL;
        tail = NULL;
        
        nodeToDelete->prev = NULL;
        nodeToDelete->next = NULL;

        delete nodeToDelete;

        return ;
    }


    // Value somewhere in the middle or last
    Node *curr = head;

    while (curr->next != head && curr->data != value)
    {
        // Moving forward
        curr = curr->next;
    }

    // Check if current element data matches to the value
    if (curr->data == value)
    {
        // Mark Node to delete
        nodeToDelete = curr->prev;

        // Check if head is going to be deleted
        if (nodeToDelete == head)
        {
            head = curr;
        }

        if (nodeToDelete == tail)
        {
            tail = nodeToDelete->prev;
        }
        

        // Break Links from list
        nodeToDelete->prev->next = curr;
        curr->prev = nodeToDelete->prev;

        nodeToDelete->next = NULL;
        nodeToDelete->prev = NULL;
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

    // insertAtTail(head, tail, 10);
    // insertAtTail(head, tail, 20);
    // insertAtTail(head, tail, 30);
    // insertAtTail(head, tail, 40);

    insertAtPosition(head, tail, 10, 1);

    // deleteAtPosition(head,tail,1);

    insertAtPosition(head, tail, 20, 2);
    insertAtPosition(head, tail, 30, 3);
    insertAtPosition(head, tail, 40, 4);

    insertBeforeValue(head, tail, 7, 10);

    insertAfterValue(head, tail, 1, 50);


    deleteAtTail(head,tail);

    // deleteAfterValue(head,tail,7);
    // deleteAfterValue(head,tail,7);
    // deleteAfterValue(head,tail,7);
    // deleteAfterValue(head,tail,7);
    // deleteAfterValue(head,tail,7);

    deleteBeforeValue(head,tail,7);
    deleteBeforeValue(head,tail,7);
    deleteBeforeValue(head,tail,7);
    deleteBeforeValue(head,tail,7);
    deleteBeforeValue(head,tail,7);
    
    print(head);
    print(tail);

    return 0;
}