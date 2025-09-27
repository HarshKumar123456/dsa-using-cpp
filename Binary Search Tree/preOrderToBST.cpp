#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

void makeNodeToParentMapping(Node *&root, map<Node *, Node *> &nodeToParent)
{
    if (root == NULL)
    {
        return;
    }

    // First Node Case Handle
    if (nodeToParent.find(root) == nodeToParent.end())
    {
        nodeToParent[root] = NULL;
    }

    if (root->left != NULL)
    {
        nodeToParent[root->left] = root;
        makeNodeToParentMapping(root->left, nodeToParent);
    }

    if (root->right != NULL)
    {
        nodeToParent[root->right] = root;
        makeNodeToParentMapping(root->right, nodeToParent);
    }
}

void printBachche(Node *&root)
{
    map<Node *, Node *> nodeToParent;
    makeNodeToParentMapping(root, nodeToParent);

    cout << "Printing Node and it's parent: " << endl;
    for (auto i : nodeToParent)
    {

        cout << i.first->data << " -> ";
        if (i.second == NULL)
        {
            cout << " NULL" << endl;
        }
        else
        {
            cout << i.second->data << endl;
        }
    }
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

Node *preOrderToBSTUsingInsertInBSTFunction(vector<int> &preOrderArray)
{
    return buildBST(preOrderArray);
}

Node *preOrderToBSTUsingRange(vector<int> &preOrderArray, int &size, int &index, int minRange, int maxRange)
{
    Node *root = NULL;
    int value = index < size ? preOrderArray[index] : -1;

    if (index >= size || value > minRange && value > maxRange || value < minRange && value < maxRange)
    // Optimized way to write this above condition is to just check
    // if (index >= size || value > maxRange || value < minRange)
    // Or we can be happy with just checking the below node making condition and return NULL if index goes out of array's size
    {
        return root;
    }

    if (index < size && value >= minRange && value <= maxRange)
    // index < size is redundant but OK if have it
    {
        root = new Node(value);
        index = index + 1;

        root->left = preOrderToBSTUsingRange(preOrderArray, size, index, minRange, root->data);
        root->right = preOrderToBSTUsingRange(preOrderArray, size, index, root->data, maxRange);
    }

    return root;
}

Node *preOrderToBSTUsingUpperBoundOnly(vector<int> &preOrderArray, int &size, int &index, int maxRange)
{
    Node *root = NULL;
    int value = index < size ? preOrderArray[index] : -1;

    if (index < size && value <= maxRange)
    {
        root = new Node(value);
        index = index + 1;

        root->left = preOrderToBSTUsingUpperBoundOnly(preOrderArray, size, index, root->data);
        root->right = preOrderToBSTUsingUpperBoundOnly(preOrderArray, size, index, maxRange);
    }

    return root;
}

Node *preOrderToBST(vector<int> &preOrderArray)
{
    int index = 0;
    int sizeOfArray = preOrderArray.size();
    int maxRange = INT_MAX;
    int minRange = INT_MIN;

    // Approach 1: Using Build BST from Pre Order Function
    // return preOrderToBSTUsingInsertInBSTFunction(preOrderArray);

    // Approach 2: Using Build Binary Tree from In Order & Pre Order Function
    // See Construct Tree From Traversals File of Binary Tree Folder

    // Approach 3: Using Build BST by giving Min, Max Range from array function
    // Point to be noted that this doesn't gurantees that all elements of the array (In case of the array is not the Pre Order Of the BST) will be in the array but guarantees that the resultant tree will be BST
    // return preOrderToBSTUsingRange(preOrderArray, sizeOfArray, index, minRange, maxRange);

    // Approach 4: Using Build BST by giving Max Range only from array function
    // Point to be noted that this does guarantees that all elements of the array (In case of the array is not the Pre Order Of the BST) but it doesn't guarantees that the resultant tree will be BST
    return preOrderToBSTUsingUpperBoundOnly(preOrderArray, sizeOfArray, index, maxRange);
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

int main()
{
    // vector<int> list = {45, 20, 10, 5, 15, 35, 30, 25, 40, 50, 60, 55, 75, 70, 65};
    // vector<int> list = {4, 2, 1, 3, 6, 5, 7};
    // vector<int> list = {4, 2, 1, 3, 5, 6,2};
    // vector<int> list = {8, 5, 1, 7, 10, 12};
    vector<int> list = {1, 3};

    Node *ped = NULL;
    ped = preOrderToBST(list);

    cout << endl;

    cout << endl;
    cout << "Printing the Bachche and Parent: " << endl;
    printBachche(ped);

    cout << endl;
    if (isBSTOptimized(ped) == true)
    {
        cout << "Bhai ye to BST hai...." << endl;
    }
    else
    {
        cout << "Bhai ye to BST nahin hai...." << endl;
    }

    cout << endl;
    cout << "Printing In Order: ";
    inOrder(ped);

    cout << endl;
    cout << "Printing Pre Order: ";
    preOrder(ped);

    cout << endl;
    cout << "Printing Post Order: ";
    postOrder(ped);

    cout << "\nPrinting in Level Order Traversal: " << endl;
    levelOrderTraversal(ped);

    return 0;
}