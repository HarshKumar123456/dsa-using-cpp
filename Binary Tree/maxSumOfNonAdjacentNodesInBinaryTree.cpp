#include <iostream>
#include <queue>
#include <stack>
#include <map>
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

Node *buildTreeFromLevelOrderTraversal(queue<int> levelOrderTraversalOfTree)
{
    // For Tree:
    /*
                     1
                /          \
                2          3
             /     \    /     \
            5           4


            Level Order Traversal Input is: 1 2 3 5 -1 4 -1
    */

    Node *root = NULL;
    queue<Node *> pankti;

    if (levelOrderTraversalOfTree.empty() == true)
    {
        return root;
    }

    // Make Jad of ped
    int value = levelOrderTraversalOfTree.front();
    levelOrderTraversalOfTree.pop();

    // Jad Ban Gayi to iske bacche bhi banao
    root = new Node(value);

    if (levelOrderTraversalOfTree.empty() == false)
    {
        value = levelOrderTraversalOfTree.front();
        levelOrderTraversalOfTree.pop();

        if (value != -1)
        {
            root->left = new Node(value);
            pankti.push(root->left);
        }
    }

    if (levelOrderTraversalOfTree.empty() == false)
    {
        value = levelOrderTraversalOfTree.front();
        levelOrderTraversalOfTree.pop();

        if (value != -1)
        {
            root->right = new Node(value);
            pankti.push(root->right);
        }
    }

    while (pankti.empty() == false)
    {
        Node *temp = pankti.front();
        pankti.pop();

        // Insert Left Child
        if (levelOrderTraversalOfTree.empty() == false)
        {
            value = levelOrderTraversalOfTree.front();
            levelOrderTraversalOfTree.pop();

            if (value != -1)
            {
                temp->left = new Node(value);
                pankti.push(temp->left);
            }
        }

        // Insert Right Child
        if (levelOrderTraversalOfTree.empty() == false)
        {
            value = levelOrderTraversalOfTree.front();
            levelOrderTraversalOfTree.pop();

            if (value != -1)
            {
                temp->right = new Node(value);
                pankti.push(temp->right);
            }
        }
    }

    return root;
}

// Max Sum Of Non Adjacent Nodes

// Kyonki sirf +ve numbers hi hain Binary tree mein isliye Sabse Pahle Level Wise Sum Store karlo phir odd aur even levels ke sum ka jo max hoga use as answer return kardo

vector<int> storeLevelWiseSum(Node *&root)
{
    vector<int> levelWiseSum;

    if (root == NULL)
    {
        return levelWiseSum;
    }

    int levelSum = 0;

    queue<Node *> q;
    q.push(root);

    int levelSize = q.size();
    while (q.empty() == false)
    {
        levelSize = q.size();

        // Traverse Full Level and Store Sum
        levelSum = 0;

        for (int index = 0; index < levelSize; index++)
        {
            Node *frontNode = q.front();
            q.pop();

            levelSum += frontNode->data;

            if (frontNode->left != NULL)
            {
                q.push(frontNode->left);
            }

            if (frontNode->right != NULL)
            {
                q.push(frontNode->right);
            }
        }

        levelWiseSum.push_back(levelSum);
    }

    return levelWiseSum;
}

pair<int, int> maxSumOfNonAdjacentNodesInBinaryTreeHelper(Node *&root)
{
    if (root == NULL)
    {
        return make_pair(0, 0);
    }

    pair<int, int> leftSubtree = maxSumOfNonAdjacentNodesInBinaryTreeHelper(root->left);
    pair<int, int> rightSubtree = maxSumOfNonAdjacentNodesInBinaryTreeHelper(root->right);

    int includeLeftChildSumContribution = leftSubtree.first >= 0 ? leftSubtree.first : 0;
    int excludeLeftChildSumContribution = leftSubtree.second >= 0 ? leftSubtree.second : 0;

    int includeRightChildSumContribution = rightSubtree.first >= 0 ? rightSubtree.first : 0;
    int excludeRightChildSumContribution = rightSubtree.second >= 0 ? rightSubtree.second : 0;

    // When Including root we can consider its childs excluded sum only
    int includeRootSum = root->data + excludeLeftChildSumContribution + excludeRightChildSumContribution;

    // When Excluding root we can consider both its included and excluded sum's contribution
    int excludeRootSum = max(includeLeftChildSumContribution, excludeLeftChildSumContribution) + max(includeRightChildSumContribution, excludeRightChildSumContribution);

    return make_pair(includeRootSum, excludeRootSum);
}

int maxSumOfNonAdjacentNodesInBinaryTree(Node *&root)
{
    pair<int, int> includeExcludeSum = maxSumOfNonAdjacentNodesInBinaryTreeHelper(root);
    return max(includeExcludeSum.first, includeExcludeSum.second);
}

// Utility method to return the maximum sum
// rooted at the node 'curr'
int getMaxSumUtil(Node *node)
{
    if (node == nullptr)
    {

        // If the node is null, the sum is 0
        return 0;
    }

    // Calculate the maximum sum including the
    // current node
    int incl = node->data;

    // If the left child exists, include its contribution
    if (node->left)
    {
        incl += getMaxSumUtil(node->left->left) +
                getMaxSumUtil(node->left->right);
    }

    // If the right child exists, include its contribution
    if (node->right)
    {
        incl += getMaxSumUtil(node->right->left) +
                getMaxSumUtil(node->right->right);
    }

    // Calculate the maximum sum excluding
    // the current node
    int excl = 0;
    if (node->left)
    {
        excl += getMaxSumUtil(node->left);
    }
    if (node->right)
    {
        excl += getMaxSumUtil(node->right);
    }

    // The result for the current node is the
    // maximum of including or excluding it
    return max(incl, excl);
}

int getMaxSum(Node *root)
{

    // If the tree is empty, the maximum sum is 0
    if (root == nullptr)
    {
        return 0;
    }

    // Call the utility function to compute the
    // maximum sum for the entire tree
    return getMaxSumUtil(root);
}

int main()
{
    Node *ped = NULL;

    // 1 2 -1 -1 3 -1 -1
    // 40 20 10 5 -1 -1 15 -1 -1 30 25 -1 -1 35 -1 -1 60 50 45 -1 -1 55 -1 -1 70 65 -1 -1 75 -1 -1
    // 45 20 10 5 -1 -1 15 -1 -1 35 30 25 -1 -1 -1 40 -1 -1 50 -1 60 55 -1 -1 75 70 65 -1 -1 -1 -1
    // 10 5 3 30 -1 -1 -2 -1 -1 2 -1 1 -1 -1 -3 -1 11 -1 -1
    // ped = buildTree(ped);

    vector<int> elements = {90, 63, 98, 55, 88, 92, 99, 12, 57, 68, 89, 91, 94, -1, 100, 10, 33, 56, 60, 67, 84, -1, -1, -1, -1, 93, 95, -1, -1, 2, 11, 20, 48, -1, -1, 59, 62, 65, -1, 82, 87, -1, -1, -1, 96, 1, 9, -1, -1, 15, 32, 36, 52, 58, -1, 61, -1, 64, 66, 80, 83, 86, -1, -1, 97, -1, -1, 6, -1, 13, 16, 26, -1, 35, 40, 50, 54, -1, -1, -1, -1, -1, -1, -1, -1, 79, 81, -1, -1, 85, -1, -1, -1, 3, 7, -1, 14, -1, 18, 25, 27, 34, -1, 39, 43, 49, 51, 53, -1, 69, -1, -1, -1, -1, -1, -1, 5, -1, 8, -1, -1, 17, 19, 24, -1, -1, 29, -1, -1, 38, -1, 41, 45, -1, -1, -1, -1, -1, -1, -1, 75, 4, -1, -1, -1, -1, -1, -1, -1, 22, -1, 28, 31, 37, -1, -1, 42, 44, 46, 70, 78, -1, -1, 21, 23, -1, -1, 30, -1, -1, -1, -1, -1, -1, -1, -1, 47, -1, 72, 76, -1, -1, -1, -1, -1, -1, -1, -1, -1, 71, 74, -1, 77, -1, -1, 73};
    // vector<int> elements = {1, 2, 3, 5 ,-1, 4 ,-1};
    // vector<int> elements = {10,5,-3,3,2,-1,11,3,-2,-1,1};
    // vector<int> elements = {10,5,-3,3,2,-1,11,30,-2,-1,1};
    // vector<int> elements = {1,200,2,5,8,100,4,-1,-1,800,-1,-1,-1,300,500,-1,10};
    // vector<int> elements = {11, 1 ,2};

    queue<int> levelOrderTraversalOfTreeQueue;
    for (auto number : elements)
    {
        levelOrderTraversalOfTreeQueue.push(number);
    }

    ped = buildTreeFromLevelOrderTraversal(levelOrderTraversalOfTreeQueue);

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

    cout << "\nPrinting in Level Order Traversal: " << endl;
    levelOrderTraversal(ped);

    cout << endl;
    cout << "Printing Bachhe: " << endl;
    printBachche(ped);

    vector<int> levelWiseSum = storeLevelWiseSum(ped);
    cout << endl;
    cout << endl;
    cout << "Level Wise Sum are: " << endl;
    for (int level = 0; level < levelWiseSum.size(); level++)
    {
        cout << "For Level: " << level << " sum is: " << levelWiseSum[level] << endl;
    }
    cout << endl;

    cout << endl;
    int maxSumOfNonAdjacentNodes = maxSumOfNonAdjacentNodesInBinaryTree(ped);
    cout << "Max Sum Of Non-Adjacent Nodes is: " << maxSumOfNonAdjacentNodes << endl;

    cout << endl;
    return 0;
}