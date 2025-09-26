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

// Minimum Time to Burn Binary Tree

Node *findNode(Node *root, int target)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == target)
    {
        return root;
    }

    Node *leftSubtree = findNode(root->left, target);
    if (leftSubtree)
    {
        return leftSubtree;
    }

    Node *rightSubtree = findNode(root->right, target);
    if (rightSubtree)
    {
        return rightSubtree;
    }

    return NULL;
}

map<Node *, Node *> makeNodeToParentMapping(Node *&root)
{
    map<Node *, Node *> parentMapping;
    if (root == NULL)
    {
        return parentMapping;
    }

    parentMapping[root] = NULL;

    queue<Node *> q;
    q.push(root);

    while (q.empty() == false)
    {
        Node *frontNode = q.front();
        q.pop();

        if (frontNode->left)
        {
            q.push(frontNode->left);
            parentMapping[frontNode->left] = frontNode;
        }

        if (frontNode->right)
        {
            q.push(frontNode->right);
            parentMapping[frontNode->right] = frontNode;
        }
    }

    return parentMapping;
}

map<Node *, bool> initializeBurnedMapping(Node *&root)
{
    map<Node *, bool> burnedMapping;
    if (root == NULL)
    {
        return burnedMapping;
    }

    queue<Node *> q;
    q.push(root);

    while (q.empty() == false)
    {
        Node *frontNode = q.front();
        q.pop();

        burnedMapping[frontNode] = false;

        if (frontNode->left)
        {
            q.push(frontNode->left);
        }

        if (frontNode->right)
        {
            q.push(frontNode->right);
        }
    }

    return burnedMapping;
}

int minimumTimeToBurnBinaryTree(Node *&root, int sparkNode)
{
    int time = 0;

    if (root == NULL)
    {
        return 0;
    }

    // Find if Spark Node is Present or not
    Node *litFromNode = findNode(root, sparkNode);
    if (litFromNode == NULL)
    {
        return -1;
    }

    // If Node Found then Start Burning but Node Can burn it's Parent also thus have to store Node to Parent Mapping too
    map<Node *, Node *> parent = makeNodeToParentMapping(root);

    // Since we have to keep track if the Node is burned or not thus have to make mapping of node burned or not
    map<Node *, bool> isBurned = initializeBurnedMapping(root);

    queue<Node *> q;
    int queueSize = 0;
    bool pushedInQueue = false;
    q.push(litFromNode);
    isBurned[litFromNode] = true;
    pushedInQueue = true;
    time++;

    while (q.empty() == false)
    {
        pushedInQueue = false;
        queueSize = q.size();

        for (int index = 0; index < queueSize; index++)
        {
            Node *frontNode = q.front();
            q.pop();

            // Burn Its Parent & Left, Right Child If Exists & Not Burned yet
            Node *parentNode = parent[frontNode];
            Node *leftChild = frontNode->left;
            Node *rightChild = frontNode->right;

            if (parentNode != NULL && isBurned[parentNode] == false)
            {
                q.push(parentNode);
                pushedInQueue = true;
                isBurned[parentNode] = true;
            }

            if (leftChild != NULL && isBurned[leftChild] == false)
            {
                q.push(leftChild);
                pushedInQueue = true;
                isBurned[leftChild] = true;
            }

            if (rightChild != NULL && isBurned[rightChild] == false)
            {
                q.push(rightChild);
                pushedInQueue = true;
                isBurned[rightChild] = true;
            }
        }

        // If There is addition in queue that means we got new Nodes burned from the burning nodes thus have to increase time
        if (pushedInQueue == true)
        {
            time++;
        }
    }

    return time;
}

int main()
{
    Node *ped = NULL;

    // 1 2 -1 -1 3 -1 -1 
    // 40 20 10 5 -1 -1 15 -1 -1 30 25 -1 -1 35 -1 -1 60 50 45 -1 -1 55 -1 -1 70 65 -1 -1 75 -1 -1
    // 45 20 10 5 -1 -1 15 -1 -1 35 30 25 -1 -1 -1 40 -1 -1 50 -1 60 55 -1 -1 75 70 65 -1 -1 -1 -1
    // 10 5 3 30 -1 -1 -2 -1 -1 2 -1 1 -1 -1 -3 -1 11 -1 -1
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

    cout << "\nPrinting in Level Order Traversal: " << endl;
    levelOrderTraversal(ped);

    cout << endl;
    cout << endl;
    int litFireFromNode;
    cout << "Please tell from which node we want to burn tree: ";
    cin >> litFireFromNode;
    cout << "Finding the Minimum time to burn tree....." << endl;
    int minTimeToBurn = minimumTimeToBurnBinaryTree(ped, litFireFromNode);
    if(minTimeToBurn == -1) {
        cout << "From this Node Burning tree is not Possible. " << endl;
    }
    else{
        cout << "It will take " << minTimeToBurn << " seconds to burn the tree. " << endl;
    }

    cout << endl;
    return 0;
}