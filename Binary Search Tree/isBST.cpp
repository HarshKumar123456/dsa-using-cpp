#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
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

bool isBST(Node *&root)
{
    // TC: O(N^2) & SC: O(N)
    if (root == NULL)
    {
        return true;
    }

    bool isLeftSubtreeBST = isBST(root->left);
    bool isRightSubtreeBST = isBST(root->right);

    if (isLeftSubtreeBST == false || isRightSubtreeBST == false)
    {
        return false;
    }
    else if (root->left != NULL && findMaxInBST(root->left) > root->data || root->right != NULL && findMinInBST(root->right) < root->data)
    {
        return false;
    }
    else
    {
        return true;
    }
}

pair<bool, pair<int, int>> isBSTHelper(Node *&root)
{
    // https://certificate.codingninjas.com/certificate/abb0aa366b124fd6/BadgesRoninCertificate

    if (root == NULL)
    {
        return make_pair(true, make_pair(INT_MAX, INT_MIN));
    }

    if (root != NULL && root->left == NULL && root->right == NULL)
    {
        return make_pair(true, make_pair(root->data, root->data));
    }

    pair<bool, pair<int, int>> leftSubtree = isBSTHelper(root->left);
    pair<bool, pair<int, int>> rightSubtree = isBSTHelper(root->right);

    bool isLeftSubtreeBST = leftSubtree.first;
    bool isRightSubtreeBST = rightSubtree.first;

    int leftSubtreeMinimum = leftSubtree.second.first == INT_MAX ? root->data : leftSubtree.second.first;
    int leftSubtreeMaximum = leftSubtree.second.second == INT_MIN ? root->data : leftSubtree.second.second;

    int rightSubtreeMinimum = rightSubtree.second.first == INT_MAX ? root->data : rightSubtree.second.first;
    int rightSubtreeMaximum = rightSubtree.second.second == INT_MIN ? root->data : rightSubtree.second.second;

    if (isLeftSubtreeBST == false || isRightSubtreeBST == false)
    {
        return make_pair(false, make_pair(INT_MAX, INT_MIN));
    }
    else if (root->data < leftSubtreeMaximum || root->data > rightSubtreeMinimum)
    {
        return make_pair(false, make_pair(INT_MAX, INT_MIN));
    }
    else
    {
        return make_pair(true, make_pair(leftSubtreeMinimum, rightSubtreeMaximum));
    }
}

bool isBSTOptimized(Node *&root)
{
    // TC: O(N) & SC: O(N)
    if (root == NULL)
    {
        return true;
    }

    return isBSTHelper(root).first;
}

// Yaa Phir Plain In Order Nikal lo aur check karo if sorted or not then tell the thing if it is BST or not

int main()
{
    vector<int> list = {4, 2, 1, 3, 6, 5, 7};
    Node *ped = NULL;
    // ped = buildBST(list); // Pass Pre Order List of BST in this Function
    ped = buildTree(ped);

    /*
    10
13 33 70 0 81 14 -1 67 15 -7 -6 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
88 -1 21 -1 40 -1 55 -1 46 -1 85 -1 86 -1 76 -1 -6 -1 77 -1 -1
12 6 82 -8 8 46 97 -10 -7 7 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
21 96 -10 93 53 82 79 -1 26 24 52 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
-3 -5 23 -9 -4 11 70 -10 -6 -1 -1 2 -1 -1 -1 -1 -1 -1 -1 -1 -1
77 -1 69 -1 73 -1 -5 -1 -4 -1 16 -1 10 -1 -8 -1 6 -1 0 -1 -1
-6 -9 56 -10 -7 17 59 -1 -1 -8 -1 -4 47 -1 -1 -1 -1 -1 -1 -1 -1
95 45 96 5 48 -1 99 3 7 46 74 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
48 37 85 -9 43 64 95 -10 14 39 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

    */

    cout << endl;

    cout << endl;
    cout << "Printing In Order: ";
    inOrder(ped);

    cout << endl;
    if (isBSTOptimized(ped) == true)
    {
        cout << "Bhai ye to BST hai...." << endl;
    }
    else
    {
        cout << "Bhai ye to BST nahin hai...." << endl;
    }

    return 0;
}