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

pair<int,int> solve(Node* &root) {
        if(root == NULL) {
            return make_pair(0,0);
        }
        
        pair<int, int> leftSub = solve(root->left);
        pair<int, int> rightSub = solve(root->right);
        
        int maxSum;
        int maxHeight;
        
        if( leftSub.second + 1 > rightSub.second + 1) {
            maxSum = leftSub.first + root->data;
            maxHeight = leftSub.second + 1;
        }
        else if(leftSub.second + 1 < rightSub.second + 1){
            maxSum = rightSub.first + root->data;
            maxHeight = rightSub.second + 1;
        }
        else{
            maxSum = max(leftSub.first, rightSub.first) + root->data;
            maxHeight = rightSub.second + 1;
        }
        
        return make_pair(maxSum, maxHeight);
    }

int sumOfLongestbloodline(Node* &root) {
    return solve(root).first;
}


int main() {
    vector<int> list = {1,2,3, -1, -1, 4, 5,6, 7, 8, 9, 10, -1, -1, 11, 12, -1, 13, 14, 15, 16, 17, 18, -1, -1, -1, -1, -1};
    queue<int> q;

    for(auto i : list) {
        q.push(i);
    }

    Node* ped = NULL;
    ped = buildTreeFromLevelOrderTraversal(q);

    levelOrderTraversal(ped);


    cout << "Sum of Longest Bloodline is: " << sumOfLongestbloodline(ped) << endl;

    return 0;
}