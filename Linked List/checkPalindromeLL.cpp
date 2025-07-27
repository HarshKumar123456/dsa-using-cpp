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

bool checkPalindromeLLByStoringIntoStringThenChecking(Node *&head, Node *&tail)
{
    // Empty or Single Element Case
    if (head == NULL || head->next == NULL)
    {
        return true;
    }

    // n-Element Case
    string str = "";

    Node *temp = head;
    char numericCharacter = '0';

    while (temp != NULL)
    {
        // Make Character from the Number
        numericCharacter = '0' + temp->data - 1;

        // Store Into string
        str = str + numericCharacter;

        // Move Forward
        temp = temp->next;
    }

    // Check if string is Palindrome
    int start = 0;
    int end = str.length() - 1;

    while (start < end)
    {
        if (str[start] != str[end])
        {
            return false;
        }

        start++;
        end--;
    }

    // If we have traversed whole string then it means that the string is palindrome and thus say yes bro
    return true;
}

bool checkPalindromeLLByRevesingItAndStoringIntoNewLLAndThenChecking(Node *&head, Node *&tail)
{
    // Empty or Single Element Case
    if (head == NULL || head->next == NULL)
    {
        return true;
    }

    // n-Element Case

    // Make a New List
    Node *newHead = NULL;
    Node *newTail = NULL;

    Node *temp = head;
    while (temp != NULL)
    {
        // Insert At Head to Reverse the List
        insertAtHead(newHead, newTail, temp->data);

        // Moving Forward
        temp = temp->next;
    }

    cout << "New Temporary list: " << endl;
    print(newHead);
    print(head);

    // Now Compare the Both List
    temp = head;

    while (temp != NULL)
    {
        // Compare and say no if Data is not matched at any point
        if (temp->data != newHead->data)
        {
            // Before saying no Free the memory allocated for the new temporary List
            cout << "Freeing memory of temporary list: " << endl;
            delete newHead;
            return false;
        }

        // Moving Forward
        temp = temp->next;
        newHead = newHead->next;
    }

    // If we have traversed whole list then it means that the string is palindrome and thus say yes bro
    return true;
}

Node *findMiddleElement(Node *&head)
{
    // Approach 1: Find length and then get mid element by traversing the exact mid times
    // Approach 2: Slow and fast pointers

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *slowPointer = head;
    Node *fastPointer = head->next;

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

Node *reverseLL(Node *&head, Node *&tail)
{
    // Empty or Single Element Case
    if (head == NULL || head->next == NULL) // Or Simply (head == tail)
    {
        head = tail;
        tail = head;
        tail->next = NULL;
        return head;
    }

    // n-Element Case

    // Extract One Node
    Node *extractedNode = head;

    cout << endl
         << endl
         << "Extracted the node: " << extractedNode->data << endl;
    head = tail;
    cout << "Pointed Head to tail node: " << head->data << endl;

    // Make Recursive Call to Reverse Remaining Part
    reverseLL(extractedNode->next, tail);

    cout << "Now head and tail: " << head->data << " " << tail->data << endl;
    // Insert At Tail the extracted node
    tail->next = extractedNode;
    tail = extractedNode;
    tail->next = NULL;

    cout << "Aur ab head and tail: " << head->data << " " << tail->data << endl;

    print(head);

    return head;
}

bool checkPalindromeLLByRevesingItFromMidThenChecking(Node *&head, Node *&tail)
{
    // Empty or Single Element Case
    if (head == NULL || head->next == NULL)
    {
        return true;
    }

    // n-Element Case

    // Find Middle Element
    Node *midElement = findMiddleElement(head);

    // Reverse From Mid
    cout << "Bhai Reversing the mid: " << endl;
    print(head);

    midElement->next = reverseLL(midElement->next, tail);

    cout << "Bhai Reversed the mid: " << endl;
    print(head);

    Node *firstHalf = head;
    Node *secondHalf = midElement->next;

    while (secondHalf != NULL)
    {
        if (firstHalf->data != secondHalf->data)
        {
            // Revert the changes in the List
            midElement->next = reverseLL(midElement->next, tail);

            cout << "Reverted the changes: " << endl;
            print(head);

            return false;
        }

        // Moving Forward
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    // Revert the changes in the List
    midElement->next = reverseLL(midElement->next, tail);

    cout << "Reverted the changes: " << endl;
    print(head);

    return true;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    print(head);

    insertAtHead(head, tail, 1);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 1);

    print(head);

    if (checkPalindromeLLByRevesingItFromMidThenChecking(head, tail))
    {
        cout << "Bhai!!!!!!!!!!!!!!!!!!! yo to Palindrome hai. " << endl;
    }
    else
    {
        cout << "Bhai!!!!!!!!!!!!!!!!!!! yo to Palindrome na hai. " << endl;
    }

    print(head);
    print(tail);

    return 0;
}