#include <iostream>
#include <queue>
#include <stack>
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

int heightOfTree(Node *&root)
{
    // Agar had hi nahin to ped kaisa
    if (root == NULL)
    {
        return 0;
    }

    int heightOfLeftSubTree = heightOfTree(root->left);
    int heightOfRightSubTree = heightOfTree(root->right);

    int height = max(heightOfLeftSubTree, heightOfRightSubTree) + 1;

    return height;
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

// First of all calculate all possible paths
// At a node we can move in 3 directions
// 1. Move to left child
// 2. Move to right child
// 3. Move to parent

// We have to make node -> parent mapping dude

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

void traverseAllPathsStartingForCurrNode(Node *&root, map<Node *, Node *> &nodeToParent, map<Node *, bool> nodeVisited, vector<Node *> &sumPath, vector<Node *> &ansPath, int &currSum, int &ansSum)
{
    // Save Path and Sum If Found Maximum
    if (currSum > ansSum && sumPath.size() > 0)
    {
        // Save Path
        ansPath = sumPath;
        ansSum = currSum;
    }

    cout << "Path: ";
    for (auto i : sumPath)
    {
        cout << i->data << " -> ";
    }
    cout << endl;

    // Base Case
    if (root == NULL)
    {
        cout << "NULL ------------> Path: ";
        for (auto i : sumPath)
        {
            cout << i->data << " -> ";
        }
        cout << endl;
        return;
    }

    // Move Left
    if (root->left != NULL && nodeVisited[root->left] == false)
    {
        currSum = currSum + root->left->data;
        sumPath.push_back(root->left);
        nodeVisited[root->left] = true;

        traverseAllPathsStartingForCurrNode(root->left, nodeToParent, nodeVisited, sumPath, ansPath, currSum, ansSum);

        currSum = currSum - root->left->data;
        nodeVisited[root->left] = false;
        sumPath.pop_back();
    }

    // Move Right
    if (root->right != NULL && nodeVisited[root->right] == false)
    {
        currSum = currSum + root->right->data;
        sumPath.push_back(root->right);
        nodeVisited[root->right] = true;

        traverseAllPathsStartingForCurrNode(root->right, nodeToParent, nodeVisited, sumPath, ansPath, currSum, ansSum);

        currSum = currSum - root->right->data;
        nodeVisited[root->right] = false;
        sumPath.pop_back();
    }

    // Move Up
    if (nodeToParent[root] != NULL && nodeVisited[nodeToParent[root]] == false)
    {
        currSum = currSum + nodeToParent[root]->data;
        sumPath.push_back(nodeToParent[root]);
        nodeVisited[nodeToParent[root]] = true;

        traverseAllPathsStartingForCurrNode(nodeToParent[root], nodeToParent, nodeVisited, sumPath, ansPath, currSum, ansSum);

        currSum = currSum - nodeToParent[root]->data;
        nodeVisited[nodeToParent[root]] = false;
        sumPath.pop_back();
    }
}

void maxSumPath(Node *&root)
{
    if (root == NULL)
    {
        return;
    }

    // Make Node to Parent Map
    map<Node *, Node *> nodeToParent;
    makeNodeToParentMapping(root, nodeToParent);

    // Make Node Visited or Not Map
    map<Node *, bool> nodeVisited;
    for (auto i : nodeToParent)
    {
        nodeVisited[i.first] = false;
    }

    vector<Node *> sumPath;
    vector<Node *> ansPath;
    int currSum = 0;
    int ansSum = INT_MIN;

    for (auto i : nodeToParent)
    {
        Node *temp = i.first;
        currSum = 0;
        traverseAllPathsStartingForCurrNode(temp, nodeToParent, nodeVisited, sumPath, ansPath, currSum, ansSum);
    }

    cout << "Max Sum is: " << ansSum << endl;

    cout << "Max Sum Path is: " << endl;
    for (auto i : ansPath)
    {
        cout << i->data << " -> ";
    }
    cout << endl;
}

int maxSum = INT_MIN;
vector<Node *> maxPath;

pair<int, vector<Node *>> helper(Node *&root)
{
    vector<Node *> ans;
    vector<Node *> path;

    if (!root)
    {
        return make_pair(0, maxPath);
    }

    pair<int, vector<Node *>> leftSub = helper(root->left);
    pair<int, vector<Node *>> rightSub = helper(root->right);

    int gainLeft = max(leftSub.first, 0);
    int gainRight = max(rightSub.first, 0);

    if (maxSum < root->data + gainLeft + gainRight)
    {
        maxSum = root->data + gainLeft + gainRight;

        if (gainLeft > 0)
        {
            for (auto i : leftSub.second)
            {
                ans.push_back(i);
            }
        }

        ans.push_back(root);

        if (gainRight > 0)
        {
            for (int index = rightSub.second.size() - 1; index >= 0; index--)
            {
                ans.push_back(rightSub.second[index]);
            }
        }

        cout << endl;
        cout << endl;
        cout << "For sum: " << maxSum << endl;
        cout << "For left: ";
        if (gainLeft > 0)
        {
            cout << gainLeft << ": ";
            for (auto i : leftSub.second)
            {
                cout << i->data << " -> ";
            }
            cout << endl;
        }

        cout << "For root: " << root->data << endl;

        cout << "For right: ";
        if (gainRight > 0)
        {
            cout << gainRight << ": ";
            for (int index = rightSub.second.size() - 1; index >= 0; index--)
            {
                cout << rightSub.second[index]->data << " -> ";
            }
            cout << endl;
        }

        cout << "Updated path is: " << endl;
        for (auto i : ans)
        {
            cout << i->data << " -> ";
        }
        cout << endl;

        maxPath = ans;
    }

    if (gainLeft > 0 && gainLeft > gainRight)
    {
        for (auto i : leftSub.second)
        {
            path.push_back(i);
        }

        path.push_back(root);
    }
    else if (gainRight > 0)
    {
        for (auto i : rightSub.second)
        {
            path.push_back(i);
        }

        path.push_back(root);
    }
    else{
        path.push_back(root);
    }

    return make_pair(root->data + max(gainLeft, gainRight), path);
}

int maxPathSum(Node *root)
{
    pair<int, vector<Node *>> maxSumAndPath = helper(root);

    cout << "Printing Max Sum: " << maxSum << endl;
    cout << "Printing Max Sum Path: " << endl;
    for (auto i : maxPath)
    {
        cout << i->data << " -> ";
    }
    cout << endl;

    return maxSum;
}

int main()
{
    // vector<int> list = {1, 2, 3, -1, -1, 4, 5, 6, 7, 8, 9, 10, -1, -1, 11, 12, -1, 13, 14, 15, 16, 17, 18, -1, -1, -1, -1, -1}; // Max Sum is: 72
    vector<int> list = {-10, 10, 20, -1, -1, 15, 7}; // Output: 15 -> 20 -> 7
    // vector<int> list = {-4,-2}; // Output: -2 ->
    // vector<int> list = {1,2,3}; // Output: 2 -> 1 -> 3
    // vector<int> list = {-519, -283, -42, 322, 103, -1, 263, 826, -706, 920, 691, -38, -765, -1, -1, -658, 386, 328, -214, -159, 284, 281, -1, 122, -920, 59, -1, -838, -1, 588, -167, 824, 723, -502, -17, -898, 492, -1, -373, 884, 777, 603, -44, -1, -723, -678, -1, -426, 536, 683, -1, -368, -845, -762, -218, -997, 757, -992, 685, -519, -990, -1, -959, 64, -1, 878, 435, -640, -1, -1, 481, -139, -1, -1, -1, -1, -1, -1, -273, 433, -256, -47, -1, -588, -547, 764, 681, -1, -894, 122, -162, 521, -237, -1, -132, -567, -148, 199, -653, 982, -752, -420, -1, -535, 877, -1, -15, 729, -294, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 350, -85, 656, 47, -1, -1, 33, -1, -1, -219, -1, -1, 822, -1, -817, -944, -184, 213, 652, -1, -11, -1, 529, 389, -895, -1, -1, -1, -933, -1, 484, -817, 555, 735, -232, -1, -233, -566, 196, 285, -538, -1, 879, 225, -1, -213, -1, -1, -1, -1, -1, -1, -321, -887, -1, -1, 685, -76, -1, -1, -1, 853, 76, -1, -512, -526, -1, 490, -1, -1, -318, -386, -1, -1, -1, -400, -1, -1, 934, 604, -1, -1, -1, -1, 149, -523, 962, -501, -624, -743, -134, 731, -468, -83, 585, 484, 579, 765, -1, -125, 480, -1, -1, 836, -1, -1, -1, -1, -1, -1, -237, -1, -1, -1, -833, -218, -1, -1, -1, 609, -1, -1, -129, -1, -1, 928, -1, -69, -1, -1, -1, -1, -1, -189, -1, -1, -1, -1, -1, -739, -388, -1, -1, -1, -670, -550, -1, -483, -1, -1, -1, -850, -1, -1, -1, -1, -1, -1, -1, -1, -10, -1, -1, 995, -1, -1, -1, -1, -1, -1, -1, -1, -1, -388, 880, -1, -251, -988, -1, -1, -1, -1, 615, -897, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 680, -1, 177, -1, -1, -1, -485, -1, -34, 81, -1, -1, -1, -1, 375, -371, -1, 699, -1, -1, -1, -788, -1, -1, -1, -1, -847, 490, -571, -1, -151, -1, -1, -597, -1, 854, -1, -1, -715, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -731, -845, 384, 201, -1, -1, -1, -1, -1, -682, -1, 927}; // O(N^2) wala solution iske liye mar gaya TLE // Output: 350 -> 433 -> 536 -> 588 -> 328 -> 920 -> 103 -> 691 -> 284 -> 492 -> -959 -> 877 -> 879 -> 

    queue<int> q;

    for (auto i : list)
    {
        q.push(i);
    }

    Node *ped = NULL;
    ped = buildTreeFromLevelOrderTraversal(q);

    levelOrderTraversal(ped);

    printBachche(ped);

    maxSumPath(ped);

    levelOrderTraversal(ped);
    printBachche(ped);

    maxPathSum(ped);

    return 0;
}