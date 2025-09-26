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

void inOrderByMorrisTraversal(Node *&root)
{
    Node *current = root;
    while (current != NULL)
    {
        // Case 1: Left Not Exists
        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        // Case 2: Left Exists
        else
        {
            Node *prev = current->left;
            while (prev->right != NULL && prev->right != current)
            {
                prev = prev->right;
            }

            // Case 2.1: prev points to NULL
            if (prev->right == NULL)
            {
                prev->right = current;
                current = current->left;
            }
            // Case 2.2: prev points to current
            else
            {
                prev->right = NULL;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }

    return;
}

void preOrderByMorrisTraversal(Node *&root)
{
    Node *current = root;
    while (current != NULL)
    {
        // Case 1: Left Not Exists
        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        // Case 2: Left Exists
        else
        {
            Node *prev = current->left;
            while (prev->right != NULL && prev->right != current)
            {
                prev = prev->right;
            }

            // Case 2.1: prev points to NULL
            if (prev->right == NULL)
            {
                cout << current->data << " ";
                prev->right = current;
                current = current->left;
            }
            // Case 2.2: prev points to current
            else
            {
                prev->right = NULL;
                current = current->right;
            }
        }
    }

    return;
}

void postOrderByMorrisTraversal(Node *&root)
{
    vector<int> postOrderElements;
    Node *current = root;

    while (current != NULL)
    {
        // Case 1: Right Not Exists
        if (current->right == NULL)
        {
            postOrderElements.push_back(current->data);
            current = current->left;
        }
        // Case 2: Right Exists
        else
        {
            Node *prev = current->right;
            while (prev->left != NULL && prev->left != current)
            {
                prev = prev->left;
            }

            // Case 2.1: prev points to NULL
            if (prev->left == NULL)
            {
                postOrderElements.push_back(current->data);
                prev->left = current;
                current = current->right;
            }
            // Case 2.2: prev points to current
            else
            {
                prev->left = NULL;
                current = current->left;
            }
        }
    }

    for (int i = postOrderElements.size() - 1; i >= 0; i--)
    {
        cout << postOrderElements[i] << " ";
    }
    cout << endl;
    return;
}

int main()
{
    Node *ped = NULL;
    ped = buildTree(ped);

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
    cout << "Printing In Order By Morris Traversal: ";
    inOrderByMorrisTraversal(ped);

    cout << endl;
    cout << "Printing Pre Order By Morris Traversal: ";
    preOrderByMorrisTraversal(ped);

    cout << endl;
    cout << "Printing Post Order By Morris Traversal: ";
    postOrderByMorrisTraversal(ped);

    cout << endl;

    return 0;
}