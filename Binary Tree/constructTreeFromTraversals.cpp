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
    cout << root->data << ", ";
    inOrder(root->right);
}

void preOrder(Node *&root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << ", ";
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
    cout << root->data << ", ";
}

int searchInArray(vector<int> &list, int start, int end, int target)
{
    for (int i = start; i <= end; i++)
    {
        if (list[i] == target)
        {
            return i;
        }
    }
    return -1;
}

Node *constructTreeFromInAndPreOrderTraversals(vector<int> &inOrder, int inStart, int inEnd, vector<int> &preOrder, int preStart, int preEnd)
{
    if (inStart > inEnd)
    {
        return NULL;
    }

    if (inStart == inEnd)
    {
        return new Node(inOrder[inStart]);
    }

    Node *root = new Node(preOrder[preStart]);
    int indexOfPreStartInInOrder = searchInArray(inOrder, inStart, inEnd, preOrder[preStart]);

    root->left = constructTreeFromInAndPreOrderTraversals(inOrder, inStart, indexOfPreStartInInOrder - 1, preOrder, preStart + 1, preStart + indexOfPreStartInInOrder - inStart);

    root->right = constructTreeFromInAndPreOrderTraversals(inOrder, indexOfPreStartInInOrder + 1, inEnd, preOrder, preStart + indexOfPreStartInInOrder - inStart + 1, preEnd);

    return root;
}

Node *constructTreeFromInAndPostOrderTraversals(vector<int> &inOrder, int inStart, int inEnd, vector<int> &postOrder, int postStart, int postEnd)
{
    // Yo Same Digits ke liye nahin chalega kyonki ismein postStart bahut jyada kam ho like minus mein chala jayega isliye make sure to check if something is going negative now it run for everything and here we handled it
    if (postStart < 0 || inStart > inEnd)
    {
        return NULL;
    }

    if (inStart == inEnd)
    {
        return new Node(inOrder[inStart]);
    }

    Node *root = new Node(postOrder[postEnd]);
    int indexOfPostEndInInOrder = searchInArray(inOrder, inStart, inEnd, postOrder[postEnd]);

    root->left = constructTreeFromInAndPostOrderTraversals(inOrder, inStart, indexOfPostEndInInOrder - 1, postOrder, postStart, postStart + indexOfPostEndInInOrder - inStart - 1);

    root->right = constructTreeFromInAndPostOrderTraversals(inOrder, indexOfPostEndInInOrder + 1, inEnd, postOrder, postStart + indexOfPostEndInInOrder - inStart, postEnd - 1);

    return root;
}

int main()
{
    // vector<int> inOrderArray = {7, 4, 8, 2, 13, 9, 5, 10, 1, 3, 11, 6, 15, 14, 12};
    // vector<int> preOrderArray = {1, 2, 4, 7, 8, 5, 9, 13, 10, 3, 6, 11, 12, 14, 15};
    // vector<int> postOrderArray = {7, 8, 4, 13, 9, 10, 5, 2, 11, 15, 14, 12, 6, 3, 1};

    // vector<int> inOrderArray = {3, 3, -2, 5, 2, 1, 10, -3, 11};
    // vector<int> preOrderArray = {10, 5, 3, 3, -2, 2, 1, -3, 11};
    // vector<int> postOrderArray = {3, -2, 3, 1, 2, 5, 11, -3, 10};

    // vector<int> inOrderArray = {1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1};
    // vector<int> preOrderArray = {1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1};
    // vector<int> postOrderArray = {1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1};

    // vector<int> inOrderArray = {1, 2};
    // vector<int> preOrderArray = {2, 1};
    // vector<int> postOrderArray = {1, 2};

    vector<int> inOrderArray = {};
    vector<int> preOrderArray = {};
    vector<int> postOrderArray = {};

    Node *ped = NULL;
    // ped = buildTree(ped);
    // ped = constructTreeFromInAndPostOrderTraversals(inOrderArray, 0, inOrderArray.size() - 1, postOrderArray, 0, postOrderArray.size() - 1);
    ped = constructTreeFromInAndPreOrderTraversals(inOrderArray, 0, inOrderArray.size() - 1, preOrderArray, 0, preOrderArray.size() - 1);

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

    return 0;
}