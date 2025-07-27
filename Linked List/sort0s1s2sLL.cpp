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


// This Function Considers List only have 0s 1s 2s
void sort0s1s2sLLUsingDataReplacement(Node* &head, Node* &tail) {
    // Empty or Single Element Case 
    if (head == NULL || head->next == NULL)
    {
        return ;
    }

    // n-Element Case
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;

    // Count and store elements' occurance
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zeroCount++;
        }
        else if (temp->data == 1)
        {
            oneCount++;
        }
        else{
            twoCount++;
        }
        
        temp = temp->next;
    }
    

    // Fill Elements
    temp = head;
    while (temp != NULL)
    {
        if (zeroCount != 0)
        {
            temp->data = 0;
            zeroCount--;
        }
        else if (oneCount != 0)
        {
            temp->data = 1;
            oneCount--;
        }
        else if (twoCount != 0)
        {
            temp->data = 2;
            twoCount--;
        }
        
        temp = temp->next;
    }
    
}


void sort0s1s2sLLUsingLinkReplacement(Node* &head, Node* &tail) {
    // Empty or Single Element Case 
    if (head == NULL || head->next == NULL)
    {
        return ;
    }

    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;


    Node* temp = head;

    // Count and store elements' occurance
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zeroTail->next = temp;
            zeroTail = temp;
        }
        else if (temp->data == 1)
        {
            oneTail->next = temp;
            oneTail = temp;
        }
        else{
            twoTail->next = temp;
            twoTail = temp;
        }
        
        temp = temp->next;
    }

    if (oneTail->data != -1)
    {
        zeroTail->next = oneHead->next;
    }
    else{
        zeroTail->next = twoHead->next;
    }

    
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    head = zeroHead->next;
    tail = twoTail;

    zeroHead->next = NULL;
    oneHead->next = NULL;
    twoHead->next = NULL;

    delete zeroHead;
    delete oneHead;
    delete twoHead;
}



// Merge Sort Logic and Helper functions - Starts Here


void solve(Node *&first, Node *&second){
    // Empty Cases
    if (first == NULL || second == NULL)
    {
        return ;
    }

    // n-Element Cases
    Node* curr1 = first;
    Node* curr2 = second;

    Node* next1 = first->next;
    Node* next2 = second->next;
    
    while (next1 != NULL && curr2 != NULL)
    {
        cout << "In Loop " << endl;
        // If second list's current element can be inserted between first list nodes
        
        if (curr1->data <= curr2->data && curr2->data <= next1->data)
        {
            // cout << "Inserting curr2:  " << curr2->data << " between " << curr1->data << " and  " << next1->data << endl;  
            // Insert between the first list nodes
            curr1->next = curr2;
            curr2->next = next1;

            // Move Forward
            curr1 = curr1->next;

            curr2 = next2;
            if (next2 != NULL)
            {
                next2 = next2->next;
            }
            
        }
        else{
            curr1 = next1;
            next1 = next1->next;
        }

    }

    if (next1 == NULL && curr2 != NULL)
    {
        cout << "Bhai pahli list hai khali isliye ismein daal rahe " << endl;
        curr1->next = curr2;
    }
    
    
}

Node *mergeTwoSortedLL(Node *&first, Node *&second)
{
    // Empty Cases
    if (first == NULL)
    {
        return second;
    }

    if (second == NULL)
    {
        return first;
    }

    // n-Element Cases
    if (first->data <= second->data)
    {
        cout << "Sending first second " << endl;
        solve(first, second);
        return first;
    }
    else
    {
        cout << "Sending second first " << endl;
        solve(second, first);
        return second;
    }
}



Node* findMiddleElement(Node* &head) {
    // Approach 1: Find length and then get mid element by traversing the exact mid times 
    // Approach 2: Slow and fast pointers

    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    

    Node* slowPointer = head;
    Node* fastPointer = head->next;

    while (fastPointer->next != NULL)
    {
        cout << "Now Slow and fast " << slowPointer->data << " - " << fastPointer->data << endl;
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next;
        
        if (fastPointer->next != NULL)
        {
            fastPointer = fastPointer->next;
        }
        
    }

    return slowPointer;
    
}

void mergeSort(Node* &head, Node* &tail) {
    // Empty or Single Element Case 
    if (head == NULL || head->next == NULL)
    {
        return ;
    }

    Node* midElement = findMiddleElement(head);

    // Break Into Two Halves
    Node* firstHead = head;
    Node* secondHead = midElement->next;

    Node* firstTail = midElement;
    Node* secondTail = tail;

    firstTail->next = NULL;
    secondTail->next = NULL;
    
    // Make Recursive Calls to sort both halves
    mergeSort(firstHead,firstTail);
    mergeSort(secondHead,secondTail);

    // Merge Both Sorted Halves
    head = mergeTwoSortedLL(firstHead,secondHead);

    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    
    tail = temp;
}

void sort0s1s2sLLUsingSort(Node* &head, Node* &tail) {
    // Empty or Single Element Case 
    if (head == NULL || head->next == NULL)
    {
        return ;
    }

    // n-Element List 
    mergeSort(head,tail);
}


int main() {
    Node *head = NULL;
    Node *tail = NULL;

    print(head);

    insertAtHead(head,tail,0);
    insertAtHead(head,tail,0);
    insertAtHead(head,tail,1);
    insertAtHead(head,tail,1);
    insertAtHead(head,tail,0);
    insertAtHead(head,tail,0);
    insertAtHead(head,tail,2);
    insertAtHead(head,tail,1);
    insertAtHead(head,tail,2);
    insertAtHead(head,tail,1);


    print(head);

    cout << "After Sorting: " << endl;

    sort0s1s2sLLUsingSort(head,tail);

    print(head);
    print(tail);

    return 0;
}