#include <iostream>
#include <map>
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


void removeDuplicatesFromSortedLL(Node* &head, Node* &tail) {
    // Case 1: Empty Case or Single Element Case
    if (head == NULL || head == tail)
    {
        return ;
    }
    

    // Case 2: n-Element Case
    Node* curr = head;
    Node* forward = curr->next;

    Node* nodeToDelete = NULL;

    while (forward != NULL)
    {
        if (curr->data != forward->data)
        {
            curr = forward;
            forward = forward->next;
        }
        else{
            
            // Mark Node to delete
            nodeToDelete = forward;
            
            // Point to next node of node to delete
            curr->next = forward->next;
            
            // Move forward to next node 
            forward = forward->next;

            // Check if Last node is to be deleted
            if (tail == nodeToDelete)
            {
                tail = curr;
            }
            

            // Break Links from List 
            nodeToDelete->next = NULL;

            // Free memory
            delete nodeToDelete;
        }
        
    }
    

}


void removeDuplicatesFromLLUsingMap(Node* &head, Node* &tail) {
    // Store Unique Elements in Map and delete if found again in the list
    map<int, bool> visitedNodes;

    Node* prev = head;
    Node* curr = prev->next;

    visitedNodes[head->data] = true;
    
    while (curr != NULL)
    {
        if (visitedNodes[curr->data])
        {
            // Visited Node Case then delete it
            prev->next = curr->next;
            // cout << "Deleting:  " << curr->data << " and now prev and curr are: " << prev->data << " " << curr->data << endl;
            
            if (curr == tail)
            {
                tail = prev;
            }
            
            curr->next = NULL;
            delete curr;
        }
        else{
            visitedNodes[curr->data] = true;
            prev = curr;
        }
        
        curr = prev->next;

        // cout << "Now here prev: " << prev->data << endl;
    }
    
}


void removeDuplicatesFromLLUsingLoop(Node* &head, Node* &tail) {
    // Empty Case
    if (head == NULL)
    {
        return ;
    }
    

    // n-Element Case
    Node* temp = head;
    Node* prev = temp;
    Node* curr = prev->next;
    Node* nodeToDelete = NULL;
    
    while (temp != NULL)
    {
        prev = temp;
        curr = prev->next;

        while (curr != NULL)
        {
            if (curr->data == temp->data)
            {
                // Mark node to delete
                nodeToDelete = curr;

                if (nodeToDelete == tail)
                {
                    tail = prev;
                }
                

                // Break Links
                prev->next = nodeToDelete->next;
                
                nodeToDelete->next = NULL;
                delete nodeToDelete;
            }
            else{
                prev = curr;
            }
            
            curr = prev->next;
        } 
        
        // Move Forward
        temp = temp->next;
    }
    
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

void removeDuplicatedUsingSortingAndThenRemoving(Node* &head, Node* &tail) {
    // Empty Case
    if (head == NULL || head->next == NULL)
    {
        return ;
    }

    // n-Element Case
    mergeSort(head,tail);

    cout << "Inside the duplicate removal function after sorting: " << endl;
    print(head);

    removeDuplicatesFromSortedLL(head,tail);
}



int main() {
    Node *head = NULL;
    Node *tail = NULL;

    print(head);

    insertAtHead(head,tail,10);
    insertAtHead(head,tail,10);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,50);
    insertAtHead(head,tail,50);
    insertAtHead(head,tail,50);
    insertAtHead(head,tail,50);
    insertAtHead(head,tail,50);
    insertAtHead(head,tail,50);
    insertAtHead(head,tail,50);
    insertAtHead(head,tail,60);
    insertAtHead(head,tail,70);

    print(head);

    cout << "After removing duplicates: " << endl;
    removeDuplicatedUsingSortingAndThenRemoving(head,tail);
    print(head);
    cout << "Tail is: " << tail->data << endl;
    print(tail);

    return 0;
}