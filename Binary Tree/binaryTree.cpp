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

queue<Node *> levelOrderTraversalStoreTree(Node *&root)
{
    queue<Node *> treeStore;
    // treeStore.push(NULL);

    // Agar jad hi nahin to ped kaisa :)
    if (root == NULL)
    {
        return treeStore;
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

        // Store the node in tree store
        treeStore.push(temp);

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

            // Store the NULL in tree store as a sign print new line
            treeStore.push(NULL);

            if (pankti.empty() == false)
            {
                pankti.push(NULL);
            }
        }
    }

    return treeStore;
}

stack<queue<Node *>> levelOrderTraversalStoreTreeLevels(Node *&root)
{

    stack<queue<Node *>> treeLevelStore;

    // Agar jad hi nahin to ped kaisa :)
    if (root == NULL)
    {
        return treeLevelStore;
    }

    // Pahla Level daal do in pankti
    queue<Node *> pankti;

    pankti.push(root);
    pankti.push(NULL);

    queue<Node *> level;

    while (pankti.empty() == false)
    {
        // Nikal lo bhai pahla element
        Node *temp = pankti.front();
        pankti.pop();

        // Store the node in tree level
        level.push(temp);

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

            // Store level
            treeLevelStore.push(level);

            // Reset Level
            while (level.empty() == false)
            {
                level.pop();
            }

            if (pankti.empty() == false)
            {
                pankti.push(NULL);
            }
        }
    }

    return treeLevelStore;
}

void reverseLevelOrderTraversal(Node *&root)
{
    // Agar jad hi nahin to ped kaisa :)
    if (root == NULL)
    {
        return;
    }

    queue<Node *> treeStoreLevelOrderTraversed = levelOrderTraversalStoreTree(root);

    // Push into stack
    stack<Node *> dibbaTreeStore;
    Node *temp = NULL;

    while (treeStoreLevelOrderTraversed.empty() == false)
    {
        temp = treeStoreLevelOrderTraversed.front();
        treeStoreLevelOrderTraversed.pop();

        dibbaTreeStore.push(temp);
    }

    // Remove NULL at Starting
    if (dibbaTreeStore.empty() == false)
    {
        dibbaTreeStore.pop();
    }

    // Print Reversed order tree
    while (dibbaTreeStore.empty() == false)
    {
        temp = dibbaTreeStore.top();
        dibbaTreeStore.pop();

        if (temp == NULL)
        {
            cout << endl;
        }
        else
        {
            cout << temp->data << " ";
        }
    }
}

void reverseLevelOrderTravesalInSequencePrint(Node *&root)
{
    // Agar jad hi nahin to ped kaisa :)
    if (root == NULL)
    {
        return;
    }

    stack<queue<Node *>> treeLevelsStore = levelOrderTraversalStoreTreeLevels(root);

    while (treeLevelsStore.empty() == false)
    {
        // Pop level and print
        queue<Node *> level = treeLevelsStore.top();
        treeLevelsStore.pop();

        while (level.empty() == false)
        {
            cout << level.front()->data << " ";
            level.pop();
        }
        cout << endl; // Level Ended
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

bool isSameTree(Node* p, Node* q) {
        // Leaf Node Case
        if(p == NULL && q == NULL) {
            return true;
        }

        // One has subtree but another not case
        if( (p != NULL && q == NULL) || (p == NULL && q != NULL) ) {
            return false;
        }

        // Values not equal case
        if(p->data != q->data) {
            return false;
        }

        return isSameTree(p->left, q->left) ? isSameTree(p->right, q->right) : false; 
    }

int main()
{
    Node *ped = NULL;
    // ped = buildTree(ped);

    // vector<int> elements = {1, 2, 3, 5 ,-1, 4 ,-1};
    vector<int> elements = {10, 8, 20, -1, 9, 15, 30, -1, -1, 14, 16, -1, -1};

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

    cout << "\nPrinting in Reverse Level Order Traversal: " << endl;
    reverseLevelOrderTraversal(ped);

    cout << "\n\nPrinting in Sequence Reverse Level Order Traversal: " << endl;
    reverseLevelOrderTravesalInSequencePrint(ped);

    cout << endl;
    return 0;
}