#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
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

void assignRandomPointer(Node *&head, vector<int> randomPointersIndex)
{
    // Case 1: Empty List
    if (head == NULL)
    {
        return;
    }

    // Assuming the No. of Nodes in the List are Same as Length of Vector
    Node *curr = head;
    for (int i = 0; (i < randomPointersIndex.size()) && (curr != NULL); i++)
    {

        int count = randomPointersIndex[i];
        if (count <= 0)
        {
            // Assign Random Pointer
            curr->random = NULL;
        }
        else
        {
            Node *temp = head;

            while (count > 1 && temp != NULL)
            {
                temp = temp->next;
                count--;
            }

            // Assign Random Pointer
            curr->random = temp;
        }

        // Move Forward
        curr = curr->next;
    }
}

void printRandomPointers(Node *&head)
{
    cout << "Printing List: " << endl;
    // Case 1: Empty List
    if (head == NULL)
    {
        cout << "Bhai List to Empty Hai. " << endl;
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        if (temp->random != NULL)
        {
            cout << temp->random->data << endl;
        }
        else
        {
            cout << "NULL" << endl;
        }

        temp = temp->next;
    }
    cout << endl;
}

void copyWithNextPointer(Node *&head, Node *&tail, Node *&originalHead)
{
    Node *temp = originalHead;
    while (temp != NULL)
    {
        insertAtTail(head, tail, temp->data);
        temp = temp->next;
    }
}

Node *cloneLLUsingNestedLoops(Node *&head)
{
    // Case 1: Empty List
    if (head == NULL)
    {
        return NULL;
    }

    // Case 2: Single or n-Element List
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;

    // Copy With Next Pointer
    copyWithNextPointer(cloneHead, cloneTail, head);

    int count = 0;
    Node *pointer = NULL;
    Node *temp = head;
    Node *cloneTemp = cloneHead;

    while (temp != NULL)
    {
        if (temp->random == NULL)
        {
            cloneTemp->random = NULL;
        }
        else
        {

            // Take Pointer to the temp -> random
            count = 0;
            pointer = head;
            while (pointer != NULL && pointer != temp->random)
            {
                pointer = pointer->next;
                count++;
            }

            // Point The cloneTemp -> random to the right place
            pointer = cloneHead;
            while (count != 0)
            {
                pointer = pointer->next;
                count--;
            }

            cloneTemp->random = pointer;
        }

        cloneTemp = cloneTemp->next;
        temp = temp->next;
    }

    return cloneHead;
}

Node *cloneLLUsingMap(Node *&head)
{
    // Case 1: Empty List
    if (head == NULL)
    {
        return NULL;
    }

    // Case 2: Single or n-Element List
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;
    Node* newNode = NULL;
    Node *temp = head;
    Node *cloneTemp = cloneHead;

    map<Node*, Node*> mapping;


    // Copy With Next Pointer
    // copyWithNextPointer(cloneHead,cloneTail,head);

    while (temp != NULL)
    {
        newNode = new Node(temp->data);
        if (cloneHead == NULL)
        {
            cloneHead = newNode;
            cloneTail = newNode;
        }
        else{
            cloneTail->next = newNode;
            cloneTail = newNode;
        }
        
        mapping[temp] = newNode; 
        temp = temp->next;
    }
    

    // // Making Mapping
    // temp = head;
    // cloneTemp = cloneHead;

    // while (temp != NULL)
    // {
    //     mapping[temp] = cloneTemp;
    //     cloneTemp = cloneTemp->next;
    //     temp = temp->next;
    // }

    // Assign Random Pointers
    temp = head;
    cloneTemp = cloneHead;
    while (temp != NULL)
    {
        cloneTemp->random = temp->random ? mapping[temp->random] : NULL;
        cloneTemp = cloneTemp->next;
        temp = temp->next;
    }
    

    return cloneHead;
    
}

Node *cloneLLUsingChangingLinksInterLeavingCloneListIntoOriginalList(Node *&head)
{
    // Case 1: Empty List
    if (head == NULL)
    {
        return NULL;
    }

    // Case 2: Single or n-Element List
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;

    // Copy With Next Pointer
    copyWithNextPointer(cloneHead, cloneTail, head);

    Node* prev = head;
    Node* curr = NULL;
    Node* cloneCurr = cloneHead;
    Node* cloneForward = NULL;

    // Inter-leaving the Clone List's Nodes into the Original List's Node
    while (prev != NULL)
    {
        // Taking Track of Forward Nodes
        curr = prev->next;
        cloneForward = cloneCurr->next;

        // Inter-leaving the Clone List's Nodes into the Original List's Node
        prev->next = cloneCurr;
        cloneCurr->next = curr;

        // Moving Forward
        prev = curr;
        cloneCurr = cloneForward;
    }

    // Copying Random Pointers
    prev = head;
    cloneCurr = cloneHead;

    while (prev != NULL)    
    {
        curr = prev->next->next;
        cloneCurr->random = prev->random ? prev->random->next : NULL;

        // Moving Forward
        prev = curr;
        cloneCurr = curr ? curr->next : NULL;
    }
    

    // Reverting The Changes
    prev = head;
    cloneCurr = cloneHead;

    while (prev != NULL)    
    {
        curr = prev->next->next;
        prev->next = curr;
        
        cloneCurr->next = curr ? curr->next : NULL;

        // Moving Forward
        prev = curr;
        cloneCurr = cloneCurr->next;
    }
    
    return cloneHead;
    
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    print(head);

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);

    vector<int> randomPointerIndex = {4, -1, 3, 0};
    assignRandomPointer(head, randomPointerIndex);

    printRandomPointers(head);

    Node *cloneHead = cloneLLUsingChangingLinksInterLeavingCloneListIntoOriginalList(head);
    print(cloneHead);
    printRandomPointers(cloneHead);

    return 0;
}