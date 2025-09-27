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

void inorder(Node *&root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

int kthSmallestElementInBST(Node *root, int k)
{
    vector<int> ans;
    inorder(root, ans);

    return ans.size() >= k ? ans[k - 1] : -1;
}

int kthLargestElementInBST(Node *root, int k)
{
    vector<int> ans;
    inorder(root, ans);

    int index = ans.size() - k;

    return index >= 0 ? ans[index] : -1;
}

// Without Using Extra Space
void findTotalNumberOfNodes(Node *&root, int &totalNumberOfNodes)
{
    Node* curr = root;
    while (curr != NULL)
    {
        if(curr->left == NULL) {
            totalNumberOfNodes++;
            curr = curr->right;
        }
        else{
            Node* prev = curr->left;
            while (prev->right != NULL && prev->right != curr)
            {
                prev = prev->right;
            }
            
            if(prev->right == NULL) {
                prev->right = curr;
                curr = curr->left;
            }
            else{
                prev->right = NULL;
                totalNumberOfNodes++;
                curr = curr->right;
            }
        }
    }
    
}

void inorderWthoutUsingExtraSpaceOtherThanRecursiveStack(Node *&root, int &k, Node *&ans)
{
    if (root == NULL || k <= 0)
    {
        return;
    }

    inorderWthoutUsingExtraSpaceOtherThanRecursiveStack(root->left, k, ans);

    if (ans == NULL && k > 0)
    {
        k--;

        if (k == 0)
        {
            ans = root;
        }
    }

    inorderWthoutUsingExtraSpaceOtherThanRecursiveStack(root->right, k, ans);
}

int kthSmallestElementInBSTWithoutUsingExtraSpaceOtherThanRecursiveStack(Node *&root, int k)
{
    Node *ans = NULL;

    inorderWthoutUsingExtraSpaceOtherThanRecursiveStack(root, k, ans);

    return ans == NULL ? -1 : ans->data;
}

int kthLargestElementInBSTWithoutUsingExtraSpaceOtherThanRecursiveStack(Node *&root, int k)
{
    int totalNumberOfNodes = 0;
    findTotalNumberOfNodes(root, totalNumberOfNodes);

    // cout << "TOtal Number of nodes are: " << totalNumberOfNodes << endl;

    int kthLargestMeansTotalMinusKthSmallPlusOne = totalNumberOfNodes - k + 1;

    return kthSmallestElementInBSTWithoutUsingExtraSpaceOtherThanRecursiveStack(root, kthLargestMeansTotalMinusKthSmallPlusOne);
}

int kthSmallestElementInBSTWithoutUsingExtraSpace(Node *&root, int k)
{
    Node *curr = root;
    Node *ans = NULL;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            k--;
            if (k == 0)
            {
                ans = curr;
            }
            curr = curr->right;
        }
        else
        {
            Node *prev = curr->left;

            while (prev->right != NULL && prev->right != curr)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                k--;
                if (k == 0)
                {
                    ans = curr;
                }
                curr = curr->right;
            }
        }
    }


    return ans == NULL ? -1 : ans->data;
}

int kthLargestElementInBSTWithoutUsingExtraSpace(Node *&root, int k)
{
    int totalNumberOfNodes = 0;
    findTotalNumberOfNodes(root, totalNumberOfNodes);

    cout << "TOtal Number of nodes are: " << totalNumberOfNodes << endl;

    int kthLargestMeansTotalMinusKthSmallPlusOne = totalNumberOfNodes - k + 1;

    return kthSmallestElementInBSTWithoutUsingExtraSpace(root, kthLargestMeansTotalMinusKthSmallPlusOne);
}


// Alternate Method Can also be that we can use something like reverse Morris Traversal thing to find the Kth Largest Element in BST

int main()
{
    vector<int> list = {4, 2, 1, 3, 6, 5, 7, 8};
    Node *ped = NULL;
    ped = buildBST(list); // Pass Pre Order List of BST in this Function
    // ped = buildTree(ped);

    cout << endl;

    cout << endl;
    cout << "Printing In Order: ";
    inOrder(ped);

    cout << endl;
    int k = 8;
    int smallElementInBST = kthSmallestElementInBSTWithoutUsingExtraSpace(ped, k);
    int largeElementInBST = kthLargestElementInBSTWithoutUsingExtraSpace(ped, k);
    if (smallElementInBST != -1)
    {
        cout << "Bhai BST ka " << k << "th  Minimum element " << smallElementInBST << "  hai...." << endl;
    }
    else
    {
        cout << "Bhai BST ka " << k << "th  Minimum element nahin hai...." << endl;
    }

    if (largeElementInBST != -1)
    {
        cout << "Bhai BST ka " << k << "th  Maximum element " << largeElementInBST << "  hai...." << endl;
    }
    else
    {
        cout << "Bhai BST ka " << k << "th  Maximum element nahin hai...." << endl;
    }

    return 0;
}