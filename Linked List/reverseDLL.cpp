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

void reverseDLLUsingIterativeApproach(Node *&head, Node *&tail)
{
    // Case 1: Empty List  or Single Element List
    if (head == NULL || head == tail)
    {
        return;
    }

    // Case 2: n-Element List
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = curr->next;

    // Update Tail
    tail = head;

    while (forward != NULL)
    {
        curr->next = prev;
        curr->prev = forward;
        prev = curr;
        curr = forward;
        forward = forward->next;
    }

    curr->next = prev;
    curr->prev = forward;
    // Update Head
    head = curr;
}

void reverseDLLUsingRecursiveApproach(Node *&head, Node *&tail)
{
    // Base Case: Empty List or Single Element List
    if (head == NULL || head == tail)
    {
        return;
    }

    // Extract One Node
    Node *extractedNode = head;

    // Move Head one node forward
    head = head->next;

    // Reverse Remaining part
    reverseDLLUsingRecursiveApproach(head, tail);

    // Insert At Tail extracted node
    tail->next = extractedNode;
    extractedNode->prev = tail;
    extractedNode->next = NULL;

    // Update Tail
    tail = extractedNode;
}


// This is however implemented anyhow but make sure when use it update head,tail in calling function else error will occur
pair<Node *, Node *> reverseDLLUsingRecursiveApproachWithReturn(Node *&head, Node *&tail)
{
    // Base Case: Empty List or Single Element List
    if (head == NULL || head->next == NULL)
    {

        if (head != NULL)
        {
            head->next = NULL;
            head->prev = NULL;
            tail->next = NULL; // Important to make sure tail doesn't point to anywhere else
            tail->prev = NULL;
        }

        return make_pair(head, tail);
    }

    // // Extract One Node
    // Node* extractedNode = head;

    // Remaining Reversed List head
    pair<Node *, Node *> result = reverseDLLUsingRecursiveApproachWithReturn(head->next, tail);

    head->prev = head->next;
    head->next->next = head;
    head->next = NULL;

    // Update Tail
    tail = head; // No Impact on code or answer as it is just taking result.second in consideration 


    /*
    Since there is no operation based on the tail thus modifying it will not impact the output but the modification in head or result.first will have impact that is error causing things try these :
    head = result.first;

    or 

    result.first = result.first;

    */

    result.second = head;

    print(result.first);
    cout << "Now remaining head is: " << result.first->data << endl;
    cout << "Now Tail is: " << tail->data << " = " << result.second->data << endl;
    cout << "Now Tail prev is: " << tail->prev->data << " = " << result.second->prev->data << endl;
    if (tail->next == NULL)
    {
        cout << "Tail next is NULL-------> " << endl;
        printTail(tail);
    }

    return result;
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

    // reverseDLLUsingRecursiveApproach(head, tail);
    pair<Node *, Node *> revHeadTail = reverseDLLUsingRecursiveApproachWithReturn(head, tail);

    print(revHeadTail.first);
    printTail(revHeadTail.second);

    head = revHeadTail.first;
    tail = revHeadTail.second;

    cout << "HA ha ha " << endl;

    print(head);
    printTail(tail);

    return 0;
}