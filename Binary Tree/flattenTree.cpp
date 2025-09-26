#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    ~Node()
    {
        if (this != NULL)
        {
            cout << "Freeing memory for: " << this->data << endl;

            if (this->left != NULL)
            {
                delete this->left;
                this->left == NULL;
            }

            if (this->right != NULL)
            {
                delete this->right;
                this->right == NULL;
            }
        }
    }
};

Node *buildTree(Node *&root, int value = -1)
{

    if (root == NULL && value == -1)
    {
        cout << "Enter root Data: ";
        cin >> value;
    }

    root = new Node(value);

    cout << "Enter data for left of " << root->data << ": ";
    cin >> value;

    if (value != -1)
    {
        root->left = buildTree(root->left, value);
    }

    cout << "Enter data for right of " << root->data << ": ";
    cin >> value;

    if (value != -1)
    {
        root->right = buildTree(root->right, value);
    }

    return root;
}

void inOrder(Node *&root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node *&root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *&root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void printFlatTree(Node *&root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
}

Node *flatTreeInPreOrderFormat(Node *&root)
{
    Node *curr = root;
    Node *ans = root;

    // Flattening using Morris Traversal
    while (curr != NULL)
    {
        // Case 1: Left Not Exists
        if (curr->left == NULL)
        {
            curr = curr->right;
        }
        // Case 2: Left Exists
        else
        {
            Node *prev = curr->left;
            while (prev->right != NULL && prev->right != curr)
            {
                prev = prev->right;
            }

            // Case 2.1: prev points to NULL
            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            // Case 2.2: prev points to curr
            else
            {
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
                curr = prev->right;
            }
        }
    }

    return ans;
}

Node *flatTreeInInOrderFormat(Node *&root)
{
    Node *ans = root;
    while (ans->left != NULL)
    {
        ans = ans->left;
    }

    Node *curr = root;

    // Making In Order Links using Morris Traversal
    while (curr != NULL)
    {
        // Case 1: Left Not Exists
        if (curr->left == NULL)
        {
            curr = curr->right;
        }
        // Case 2: Left Exists
        else
        {
            Node *prev = curr->left;
            while (prev->right != NULL && prev->right != curr)
            {
                prev = prev->right;
            }

            // Case 2.1: prev points to NULL
            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            // Case 2.2: prev points to curr
            else
            {
                curr = curr->right;
            }
        }
    }

    curr = root;
    // Breaking & Fixing In Order Links and Flattening using Morris Traversal
    while (curr != NULL)
    {
        // Case 1: Left Not Exists
        if (curr->left == NULL)
        {
            Node *currRight = curr->right;
            Node *forward = curr->right;
            while (forward != NULL && forward->left != NULL)
            {
                forward = forward->left;
            }

            curr->right = forward;
            curr = currRight;
        }
        // Case 2: Left Exists
        else
        {
            Node *prev = curr->left;
            curr->left = NULL;
            curr = prev;
        }
    }

    return ans;
}

Node *reverseFlattedTree(Node *&root)
{
    if (root == NULL || root->right == NULL)
    {
        return root;
    }

    Node *head = root;
    Node *headNext = head->right;

    Node *reverseHead = reverseFlattedTree(headNext);

    headNext->right = head;
    head->right = NULL;

    return reverseHead;
}

Node *flatTreeInPostOrderFormat(Node *&root)
{
    Node *curr = root;
    Node *ans = root;

    // Flattening using Morris Traversal In NLR format
    while (curr != NULL)
    {
        // Case 1: Right Not Exists
        if (curr->right == NULL)
        {
            curr = curr->left;
        }
        // Case 2: Right Exists
        else
        {
            Node *prev = curr->right;
            while (prev->left != NULL && prev->left != curr)
            {
                prev = prev->left;
            }

            // Case 2.1: prev points to NULL
            if (prev->left == NULL)
            {
                prev->left = curr;
                curr = curr->right;
            }
            // Case 2.2: prev points to curr
            else
            {
                prev->left = curr->left;
                curr->left = curr->right;
                curr->right = NULL;
                curr = prev->left;
            }
        }
    }

    // Since We Have Changed In the Fashion of NRL thus it got now all right pointers pointing to NULL thus now we need to make the traversal of tree and make the right pointer equal to left pointer and left pointer to right pointer

    curr = ans;
    // Ye head tail bas liye hain taaki TC: O(N) aur SC: O(1) mein reverse kar pao
    Node *head = ans;
    Node *tail = ans;
    while (curr != NULL)
    {
        Node *currLeft = curr->left;
        Node *currRight = curr->right;

        curr->left = currRight;
        curr->right = currLeft;

        if (curr->right == NULL)
        {
            tail = curr;
        }

        curr = curr->right;
    }

    cout << "In The () printing flat: " << endl;
    printFlatTree(ans);
    cout << "Success Printing..... " << endl;

    // Now Reverse The Flatted Tree using reverse Linked List Concept Ab Poori TC depend kargei ki kaise reverse kar rahe abhi tak TC: O(N) hai
    // ans = reverseFlattedTree(ans); // TC: O(N) SC: O(N)
    cout << "Head and Tail are: " << head->data << " - " << tail->data << endl;
    Node *prev = NULL;
    curr = head;
    Node *forward = curr->right;
    while (forward != NULL)
    {
        curr->right = prev;
        prev = curr;
        curr = forward;
        forward = forward->right;
    }
    curr->right = prev;

    // Reversed Flatted Tree Head will be answer
    ans = curr;

    return ans;
}

void preorderHelper(Node *&root, Node *&previous)
{
    if (root == NULL)
    {
        return;
    }

    Node *leftSubtree = root->left;
    Node *rightSubtree = root->right;

    previous->right = root;
    previous = root;
    root->left = NULL;

    preorderHelper(leftSubtree, previous);
    preorderHelper(rightSubtree, previous);
}


void inorderHelper(Node *&root, Node *&previous)
{
    if (root == NULL)
    {
        return;
    }

    Node *leftSubtree = root->left;
    Node *rightSubtree = root->right;

    inorderHelper(leftSubtree, previous);

    previous->right = root;
    previous = root;
    root->left = NULL;

    inorderHelper(rightSubtree, previous);
}


void postorderHelper(Node *&root, Node *&previous)
{
    if (root == NULL)
    {
        return;
    }

    Node *leftSubtree = root->left;
    Node *rightSubtree = root->right;

    postorderHelper(leftSubtree, previous);
    postorderHelper(rightSubtree, previous);

    previous->right = root;
    previous = root;
    root->left = NULL;
}

void flatten(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    Node *temp = new Node(-1);
    Node *previous = temp;

    preorderHelper(root, previous);

    root = temp->right;
    temp->right = NULL;
    delete temp;
}

int main()
{
    Node *ped = NULL;
    ped = buildTree(ped);

    // 1 2 4 7 -1 -1 8 -1 -1 5 9 13 -1 -1 -1 10 -1 -1 3 -1 6 11 -1 -1 12 14 15 -1 -1 -1 -1
    // 1 2 -1 -1 3 4 6 10 15 -1 -1 16 -1 -1 -1 7 -1 11 17 -1 -1 18 -1 -1 5 8 12 -1 -1 -1 8 13 -1 -1 14 -1 -1
    // 10 5 3 3 -1 -1 -2 -1 -1 2 -1 1 -1 -1 -3 -1 11 -1 -1
    // 2 -1 10 7 44 418 512 -1 -1 733 -1 -1 696 145 -1 -1 70 -1 -1 500 99 -1 -1 417 -1 -1 6 3 -1 -1 15 22 18 1001 101019 91 -1 -1 111 -1 -1 17634 634 643 -1 -1 343 -1 -1 432198 -1 -1 1009 -1-1 9 -1 -1 17 777 -1 -1  32 -1 -1
    // 1 -1 2 3 5 9 15 -1 -1 16 -1 -1 10 17 -1 -1 18 -1 -1 6 11 -1 -1 12 -1 -1 4 7 -1 -1 8 13 19 23 25 27 -1 -1 28 -1 -1 26 29 31 -1 -1 32 -1 -1 30 -1 -1 24 -1 -1 20 -1 -1 14 21 -1 -1 22 -1 -1

    cout << endl;

    cout << endl;
    cout << "Printing In Order: ";
    inOrder(ped);

    cout << endl;
    cout << "Printing Pre Order: ";
    preOrder(ped);

    cout << endl;
    cout << "Printing Post Order: ";
    postOrder(ped);

    cout << endl;
    ped = flatTreeInPostOrderFormat(ped);
    cout << "\nPrinting After Flattening Tree In Pre Order Format: ";
    printFlatTree(ped);

    cout << endl;
    cout << "Printing In Order: ";
    inOrder(ped);

    cout << endl;
    cout << "Printing Pre Order: ";
    preOrder(ped);

    cout << endl;
    cout << "Printing Post Order: ";
    postOrder(ped);

    cout << endl;

    return 0;
}