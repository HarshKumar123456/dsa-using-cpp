#include <iostream>
#include <vector>
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

class Stack
{
private:
    Node *head = NULL;
    Node *tail = NULL;
    int filled = 0;

public:
    int capacity;

    Stack(int capacity)
    {
        head = NULL;
        tail = NULL;
        filled = 0;

        this->capacity = capacity;
        cout << "Stack is Created of Capacity: " << capacity << endl;
    }

    bool empty()
    {
        if (filled == 0)
        {
            return true;
        }

        return false;
    }

    bool full()
    {
        if (filled == capacity - 1)
        {
            return true;
        }

        return false;
    }

    void print()
    {

        // Case 1: When Stack Is Empty
        if (empty())
        {
            cout << "Bhai Stack Is Empty. " << endl;
            return;
        }

        // Case 2: When Stack is Not Empty
        Node* temp = head->next;
        cout << head->data << " <- Top" << endl;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    int top()
    {

        // Case 1: When Stack Is Empty
        if (empty())
        {
            cout << "Bhai Stack Is Empty. " << endl;
            return -1;
        }

        // Case 2: When Stack is Not Empty
        return head->data;
    }

    bool push(int element)
    {

        // Case 1: When Stack Is Full
        if (full())
        {
            cout << "Bhai Stack Overflow. " << endl;
            return false;
        }

        // Case 2: When Stack Is Not Full
        insertAtHead(head,tail,element);
        filled++;

        return true;
    }

    bool pop()
    {

        // Case 1: When Stack Is Empty
        if (empty())
        {
            cout << "Bhai Stack Underflow. " << endl;
            return false;
        }

        // Case 2: When Stack is Not Empty
        deleteAtHead(head,tail);
        filled--;

        return true;
    }

    int size()
    {
        return filled;
    }

    int remainingSpace()
    {
        if (empty())
        {
            return capacity;
        }

        return capacity - filled;
    }
};

int main()
{
    Stack numbers(10);
    cout << endl;

    cout << "Remaining Space in Stack: " << numbers.remainingSpace() << endl;

    if (numbers.empty())
    {
        cout << "Bhai Stack Empty hai. " << endl;
    }
    else
    {
        cout << "Bhai Stack Empty nahin hai. " << endl;
    }

    cout << endl;

    numbers.push(10);
    numbers.push(20);
    numbers.push(30);
    numbers.push(40);

    cout << "Top of the Stack: " << numbers.top() << endl;

    cout << endl
         << "Size of Stack is: " << numbers.size() << endl;

    numbers.pop();
    numbers.pop();
    numbers.pop();

    numbers.print();
    // Saare Elements ko pop karke top access karoge to Segmentation Fault aayega
    // numbers.pop();

    cout << "Top of the Stack: " << numbers.top() << endl;

    if (numbers.empty())
    {
        cout << "Bhai Stack Empty hai. " << endl;
    }
    else
    {
        cout << "Bhai Stack Empty nahin hai. " << endl;
    }

    cout << endl
         << "Size of Stack is: " << numbers.size() << endl;

    cout << "Remaining SPace in STack is: " << numbers.remainingSpace() << endl;

    numbers.pop();
    cout << "Remaining SPace in STack is: " << numbers.remainingSpace() << endl;

    return 0;
}