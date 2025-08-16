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


class queueUsingLinkedList
{
private:
    Node *head = NULL;
    Node *tail = NULL;
    int capacity;
    int filled;

public:
    queueUsingLinkedList(int size)
    {
        this->capacity = size;
        this->filled = 0;
        this->head = NULL;
        this->tail = NULL;
    }

    bool empty()
    {
        return filled == 0 ? true : false;
    }

    bool full()
    {
        if (filled == capacity)
        {
            return true;
        }

        return false;
    }

    void print()
    {
        // If queue is empty then say it is empty
        if (empty() == true)
        {
            cout << "Queue is empty. " << endl;
            return;
        }

        cout << endl
             << "Printing Queue: " << endl;

        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << "----" << endl;
    }

    int front()
    {
        if (empty() == true)
        {
            return -1;
        }

        return head == NULL ? -1 : head->data;
    }

    int back()
    {
        if (empty() == true)
        {
            return -1;
        }

               return tail == NULL ? -1 : tail->data;

    }

    bool push(int element)
    {
        // If queue is full then return
        if (full() == true)
        {
            cout << "Queue Overflow...." << endl;
            return false;
        }


        cout << "Pushed: " << element << endl;
        insertAtTail(head,tail,element);
        filled++;

        return true;
    }

    bool pop()
    {
        // If stack is empty return false
        if (empty() == true)
        {
            cout << "Queue Underflow...." << endl;
            return false;
        }

        // We have to Pop from back as implementing the stack using queue
        // Pop 1 element by reversing the queue and then again reverse the queue to maintain stack
        cout << "Popped: " << head->data << endl;
        filled--;

        deleteAtHead(head,tail);

        return true;
    }

    void swap(queueUsingLinkedList swapFromThis)
    {
        this->capacity = swapFromThis.capacity;
        this->filled = swapFromThis.filled;

        delete this->head;

        this->head = swapFromThis.head;
        this->tail = swapFromThis.tail;
    }

    int size()
    {
        return capacity;
    }

    int remainingSize()
    {
        return capacity - filled;
    }
};

int main()
{
    cout << endl;

    queueUsingLinkedList q(5);
    queueUsingLinkedList line(5);

    line.push(1);
    line.push(2);
    line.push(3);
    line.push(4);
    line.push(5);

    line.print();

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    q.print();

    q.pop();
    q.pop();

    q.push(1);
    q.push(11);
    q.push(111);
    q.push(1111);
    q.push(11111);
    q.print();


    q.swap(line);
    // line.print();
    cout << "Queue size is: " << q.size() << endl;

    cout << "Queue's front is: " << q.front() << " Queue's Back is: " << q.back() << endl;

    if (q.empty())
    {
        cout << "Bhai Queue to Empty hai." << endl;
    }
    else
    {
        cout << "Bhai Queue to Empty nahin hai." << endl;
    }

    cout << endl;
    return 0;
}