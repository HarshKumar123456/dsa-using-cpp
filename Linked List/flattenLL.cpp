#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }

    ~Node()
    {
        if (this != NULL)
        {
            cout << "Freeing memory for: " << this->data << endl;
            if (this->child != NULL)
            {
                // cout << "Deleting child--> " << this->child->data << " of: " << this->data << endl;
                delete this->child;
                this->child = NULL;
            }

            // cout << "Deleted Childs Now Next for:  " << this->data << endl;

            if (this->next != NULL)
            {
                // cout << "Deleting next--> " << this->next->data << " of: " << this->data << endl;

                delete this->next;
                this->next = NULL;
            }

            // cout << "Deleted:  " << this->data << endl;
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

void printChilds(Node *&head)
{
    cout << "Printing Childs: " << endl;

    // Case 1: Empty List
    if (head == NULL)
    {
        cout << "Bhai List to Empty hai." << endl
             << endl;
        return;
    }

    cout << "Child's of Node --> " << head->data << endl;

    // Case 2: No Childs
    if (head->child == NULL)
    {
        cout << "Bhai This Node has No Childs." << endl
             << endl;
        return;
    }

    // Case 3: Single or Multiple Childs Node
    Node *temp = head->child;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->child;
    }
    cout << endl
         << endl;
}

void printFullCondition(Node *&head)
{
    if (head == NULL)
    {
        cout << "NULL" << endl;
        return;
    }

    cout << head->data << " -> ";
    Node *temp = head->child;
    while (temp != NULL)
    {
        cout << temp->data << "-> ";
        temp = temp->child;
    }
    cout << endl;

    printFullCondition(head->next);
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

void insertAtChild(Node *&head, int element)
{
    // Node Creation
    Node *temp = new Node(element);

    // Case 1: Empty List
    if (head == NULL)
    {
        cout << "Bhai NULL node ke Child kaise honge. " << endl;
        return;
    }

    // Case 2: Single Element List OR n-Element List
    head->child = temp;
}

// This Approach Doesn't Need to pass first Smaller element list and then Bigger Element List
Node *mergeTwoSortedLLUsingRecursion(Node *&first, Node *&second)
{
    // One List Empty Case
    if (first == NULL)
    {
        return second;
    }

    if (second == NULL)
    {
        return first;
    }

    Node *sortedListHead = NULL;
    if (first->data <= second->data)
    {
        sortedListHead = first;
        sortedListHead->next = mergeTwoSortedLLUsingRecursion(first->next, second);
    }
    else
    {
        sortedListHead = second;
        sortedListHead->next = mergeTwoSortedLLUsingRecursion(first, second->next);
    }

    return sortedListHead;
}

Node *flattenLL(Node *&head)
{
    // Case 1: Empty Case or No Child's Case
    if (head == NULL)
    {
        // cout << "Bhai i returned from here---------------------> " << endl;
        return head;
    }

    // cout << "Inside Flatten for : " << head->data << endl;

    // Case 2: Single Child or Multiple Childs Case
    Node *newHead = head->next;
    Node *temp = head;

    temp->next = NULL;

    // Move All Childs to Next
    while (temp->child != NULL)
    {
        // cout << "Yahan for: " << head->data << endl;
        temp->next = temp->child;
        temp->child = NULL;
        temp = temp->next;
    }
    // cout << "After Flat: " << endl;
    // print(head);

    // Flat Remaining Part of List
    newHead = flattenLL(newHead);
    // cout << "After Recursive call: " << head->data << endl;
    // print(head);
    // print(newHead);

    head = mergeTwoSortedLLUsingRecursion(newHead, head);

    // cout << "After merge: " << endl;
    // print(head);

    return head;
}

Node *merge(Node *first, Node *second)
{
    if (first == NULL)
        return second;

    if (second == NULL)
        return first;

    Node *ans = new Node(-1);
    Node *temp = ans;

    Node *ptr1 = first;
    Node *ptr2 = second;

    // cout << "In Merge first and second--------------------> " << endl;
    // printChilds(first);
    // print(second);

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data <= ptr2->data)
        {
            temp->next = ptr1;
            ptr1 = ptr1->child;
            temp->next->child = NULL;

            temp = temp->next;
        }
        else
        {
            temp->next = ptr2;
            temp = temp->next;

            ptr2 = ptr2->next;
        }
    }

    while (ptr1 != NULL)
    {
        temp->next = ptr1;
        ptr1 = ptr1->child;
        temp->next->child = NULL;

        temp = temp->next;
    }

    while (ptr2 != NULL)
    {
        temp->next = ptr2;
        temp = temp->next;

        ptr2 = ptr2->next;
    }

    temp = ans;

    ans = ans->next;
    // print(ans);

    temp->next = NULL;
    temp->child = NULL;

    delete temp;

    return ans;
}

Node *flattenLinkedList(Node *head)
{
    // Base condition
    if (head == NULL || head->next == NULL)
        return head;

    Node *ans = flattenLinkedList(head->next);

    head = merge(head, ans);
    head->child = NULL;
    cout << "Bro Pointed " << head->data << " childs to NULL ----------------> " << endl;

    return head;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);

    print(head);

    // Head's Childs
    insertAtChild(head, 10);
    insertAtChild(head->child, 12);
    insertAtChild(head->child->child, 14);

    printChilds(head);

    // Head->next's Childs
    insertAtChild(head->next, 9);
    insertAtChild(head->next->child, 11);

    printChilds(head->next);

    // Head->next->next's Childs
    insertAtChild(head->next->next, 7);
    insertAtChild(head->next->next->child, 8);

    printChilds(head->next->next);

    // Head->next->next->next's Childs
    insertAtChild(head->next->next->next, 15);
    insertAtChild(head->next->next->next->child, 20);

    printChilds(head->next->next->next);

    // Head->next->next->next->next's Childs

    printChilds(head->next->next->next->next);

    print(head);

    cout << "Before Flattening: " << endl;
    print(head);
    printFullCondition(head);



    head = flattenLinkedList(head);

    cout << "After Flattening: " << endl;
    print(head);
    printFullCondition(head);

    cout << "Printed Full Condition." << endl;

    delete head;
    return 0;
}
