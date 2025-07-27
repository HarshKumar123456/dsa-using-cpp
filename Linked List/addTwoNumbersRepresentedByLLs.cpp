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

    // cout << endl
    //      << endl
    //      << "Extracted the node: " << extractedNode->data << endl;
    head = tail;
    // cout << "Pointed Head to tail node: " << head->data << endl;

    // Make Recursive Call to Reverse Remaining Part
    reverseLL(extractedNode->next, tail);

    // cout << "Now head and tail: " << head->data << " " << tail->data << endl;
    // Insert At Tail the extracted node
    tail->next = extractedNode;
    tail = extractedNode;
    tail->next = NULL;

    // cout << "Aur ab head and tail: " << head->data << " " << tail->data << endl;

    // print(head);

    return head;
}

Node *addTwoNumbersRepresentedByLLs(Node *&firstHead, Node *&firstTail, Node *&secondHead, Node *&secondTail)
{
    // Case 1: Any one List is Empty then Answer is another List
    if (firstHead == NULL)
    {
        return secondHead;
    }

    if (secondHead == NULL)
    {
        return firstHead;
    }

    // Case 2: Both Lists have at Least 1 element in it

    // Reverse Both The Lists as We Adds from the Last element then move towards starting Elements
    firstHead = reverseLL(firstHead, firstTail);
    secondHead = reverseLL(secondHead, secondTail);

    int sum = 0;
    int carry = 0;
    int digitToInsert = 0;

    int value1 = 0;
    int value2 = 0;
    int value3 = 0;

    Node *first = firstHead;
    Node *second = secondHead;
    Node *answerHead = NULL;
    Node *answerTail = NULL;


    // 4 Loops in One Karo With Vitamins :)   ,Just for fun Comment
    while (first != NULL || second != NULL || carry != 0)
    {
        value1 = 0;
        value2 = 0;
        value3 = 0;

        if (first != NULL)
        {
            value1 = first->data;
            first = first->next;
        }

        if (second != NULL)
        {
            value2 = second->data;
            second = second->next;
        }

        if (carry != 0)
        {
            value3 = carry % 10;
            carry = carry / 10;
        }

        sum = value1 + value2 + value3;

        digitToInsert = sum % 10;
        carry = sum / 10;

        // Since We are inserting at the Head Thus it will be Automatically Reversed thus we will not required to reverse this answer list to get right answer
        insertAtHead(answerHead, answerTail, digitToInsert);
    }

    // Unless Both Lists have Elements
    // while (first != NULL && second != NULL)
    // {
    //     sum = first->data + second->data + carry;

    //     digitToInsert = sum % 10;
    //     carry = sum / 10;

    //     // Since We are inserting at the Head Thus it will be Automatically Reversed thus we will not required to reverse this answer list to get right answer
    //     insertAtHead(answerHead,answerTail,digitToInsert);

    //     // Move Forward
    //     first = first->next;
    //     second = second->next;
    // }

    // // When One Of the List Got Empty
    // while (first != NULL)
    // {
    //     sum = first->data + carry;

    //     digitToInsert = sum % 10;
    //     carry = sum / 10;

    //     // Since We are inserting at the Head Thus it will be Automatically Reversed thus we will not required to reverse this answer list to get right answer
    //     insertAtHead(answerHead,answerTail,digitToInsert);

    //     // Move Forward
    //     first = first->next;
    // }

    // while (second != NULL)
    // {
    //     sum = second->data + carry;

    //     digitToInsert = sum % 10;
    //     carry = sum / 10;

    //     // Since We are inserting at the Head Thus it will be Automatically Reversed thus we will not required to reverse this answer list to get right answer
    //     insertAtHead(answerHead,answerTail,digitToInsert);

    //     // Move Forward
    //     second = second->next;
    // }

    // // When Both Lists Got Empty But We Have Carry Left
    // // while (carry != 0)
    // // {
    // //     sum = carry;

    // //     digitToInsert = sum % 10;
    // //     carry = sum / 10;

    // //     // Since We are inserting at the Head Thus it will be Automatically Reversed thus we will not required to reverse this answer list to get right answer
    // //     insertAtHead(answerHead,answerTail,digitToInsert);

    // //     // Move Forward
    // //     carry = carry / 10;
    // // }

    // digitToInsert = carry % 10;
    // cout << "Carry is: " << carry << endl;
    // insertAtHead(answerHead,answerTail,digitToInsert);

    // Revert The Changes
    firstHead = reverseLL(firstHead, firstTail);
    secondHead = reverseLL(secondHead, secondTail);

    return answerHead;
}

int main()
{
    Node *firstHead = NULL;
    Node *firstTail = NULL;

    print(firstHead);

    insertAtTail(firstHead, firstTail, 1);
    insertAtTail(firstHead, firstTail, 2);
    insertAtTail(firstHead, firstTail, 3);
    insertAtTail(firstHead, firstTail, 4);
    insertAtTail(firstHead, firstTail, 5);
    insertAtTail(firstHead, firstTail, 6);
    insertAtTail(firstHead, firstTail, 7);

    cout << "Bhai printing first list: " << endl;
    print(firstHead);

    Node *secondHead = NULL;
    Node *secondTail = NULL;

    print(secondHead);

    insertAtTail(secondHead, secondTail, 1);
    insertAtTail(secondHead, secondTail, 2);
    insertAtTail(secondHead, secondTail, 3);
    insertAtTail(secondHead, secondTail, 4);
    insertAtTail(secondHead, secondTail, 5);
    insertAtTail(secondHead, secondTail, 6);
    insertAtTail(secondHead, secondTail, 7);

    cout << "Bhai printing second list: " << endl;
    print(secondHead);

    cout << endl
         << endl
         << "Bhai ye lo aapka sum: " << endl;
    print(firstHead);
    print(secondHead);
    Node *sumHead = addTwoNumbersRepresentedByLLs(firstHead, firstTail, secondHead, secondTail);
    print(sumHead);

    return 0;
}