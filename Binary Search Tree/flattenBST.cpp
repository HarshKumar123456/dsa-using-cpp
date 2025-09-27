#include <iostream>
#include <vector>
#include <queue>
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

void levelOrderTraversal(Node *&root)
{
    // Agar jad hi nahin to ped kaisa :)
    if (root == NULL)
    {
        return;
    }

    // Pahla Level daal do in pankti
    queue<Node *> pankti;

    pankti.push(root);
    pankti.push(NULL);

    while (pankti.empty() == false)
    {
        // Nikal lo bhai pahla element
        Node *temp = pankti.front();
        pankti.pop();

        cout << temp->data << " ";

        if (temp->left != NULL)
        {
            pankti.push(temp->left);
        }

        if (temp->right != NULL)
        {
            pankti.push(temp->right);
        }

        // Agar Ab pahla element NULL hua to level khatam ho chuka hai to phir se level ka track rakhne ke liye NULL push kar do
        temp = pankti.front();
        if (temp == NULL)
        {
            pankti.pop();
            cout << endl;

            if (pankti.empty() == false)
            {
                pankti.push(NULL);
            }
        }
    }
}

Node *insertInBST(Node *&root, int value)
{
    if (root == NULL)
    {
        return new Node(value);
    }

    if (root->data > value)
    {
        root->left = insertInBST(root->left, value);
    }
    else
    {
        root->right = insertInBST(root->right, value);
    }

    return root;
}

int findMinInBST(Node *&root)
{
    if (root == NULL)
    {
        return -1;
    }

    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp->data;
}

int findMaxInBST(Node *&root)
{
    if (root == NULL)
    {
        return -1;
    }

    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }

    return temp->data;
}

Node *deletionInBST(Node *&root, int target)
{
    if (root == NULL)
    {
        cout << "Value Not Found " << endl;
        return root;
    }
    cout << "At call(): " << root->data << endl;
    if (root->data > target)
    {
        root->left = deletionInBST(root->left, target);
    }
    else if (root->data < target)
    {
        root->right = deletionInBST(root->right, target);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            cout << "Deleting From Case 1" << endl;
            delete root;
            root = NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            Node *nodeToDelete = root;
            root = root->left;

            nodeToDelete->left = NULL;
            nodeToDelete->right = NULL;
            delete nodeToDelete;
        }
        else if (root->right != NULL && root->left == NULL)
        {
            Node *nodeToDelete = root;
            root = root->right;

            nodeToDelete->left = NULL;
            nodeToDelete->right = NULL;
            delete nodeToDelete;
        }
        else
        {
            // root->data = findMinInBST(root->right);
            // cout << "Found Min " << root->data <<  "  " << root->right->data << endl;
            // root->right = deletionInBST(root->right, root->data);

            // Alternatively can Use
            root->data = findMaxInBST(root->left);
            cout << "Found Max " << root->data << "  " << root->left->data << endl;
            root->left = deletionInBST(root->left, root->data);
        }
    }

    return root;
}

Node *buildBST(vector<int> &arr)
{
    Node *root = NULL;

    for (auto element : arr)
    {
        root = insertInBST(root, element);
    }

    return root;
}

// Flattening BST



// Approach 1: 
// Recursively flatten the BST First flat the left part then go to the end of Left Subtree and then point it to root then again make the recursive call to the Right Subtree 
Node *flattenBSTUsingRecursion(Node *root)
{

    if (root == NULL)
    {
        return root;
    }

    Node *leftSubtree = flattenBSTUsingRecursion(root->left);
    Node *temp = leftSubtree;
    while (temp != NULL && temp->right != NULL)
    {
        temp = temp->right;
    }

    if (temp != NULL)
    {
        temp->right = root;
    }

    root->left = NULL;
    root->right = flattenBSTUsingRecursion(root->right);

    return leftSubtree == NULL ? root : leftSubtree;
}




// Approach 2: 
// Optimized the need to move to the last of the Left Subtree (i.e. Predeccessor of the Node) Save In Order and Track the Predeccessor of the Node in the previous Node 
void inorder(Node *&root, Node *&previous)
{
    if (root == NULL)
    {
        return;
    }

    Node *leftSubtree = root->left;
    Node *rightSubtree = root->right;
    inorder(leftSubtree, previous);

    previous->right = root;
    previous = root;
    root->left = NULL;

    inorder(rightSubtree, previous);
}

Node *flattenBSTUsingInOrder(Node *&root)
{
    if (root == NULL)
    {
        return root;
    }

    Node *temp = new Node(-1);
    Node *previous = temp;

    inorder(root, previous);

    Node *newRoot = temp->right;
    temp->right = NULL;
    delete temp;

    return newRoot;
}



int main() {
    vector<int> list = {4,2,1,3,6,5,7};
    // vector<int> list = {45, 20, 10, 5, 15, 35, 30, 25, 40, 50, 60, 55, 75, 70, 65};

    Node *ped = buildBST(list);

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
    cout << "Printing in Level Order Traversal: " << endl;
    levelOrderTraversal(ped);
    
    
    cout << endl;
    cout << endl;
    cout << "After Flattening the BST: " << endl;
    ped = flattenBSTUsingInOrder(ped);


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
    cout << "Printing in Level Order Traversal: " << endl;
    levelOrderTraversal(ped);


    return 0;
}
