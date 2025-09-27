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


Node* insertInBST(Node* &root, int value) {
    if (root == NULL)
    {
        return new Node(value);
    }

    if(root->data > value) {
        root->left = insertInBST(root->left, value);
    }
    else{
        root->right = insertInBST(root->right, value);
    }
    
    return root;
}

int findMinInBST(Node* &root) {
    if (root == NULL)
    {
        return -1;
    }
    
    Node* temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    
    return temp->data;
}

int findMaxInBST(Node* &root) {
    if (root == NULL)
    {
        return -1;
    }
    
    Node* temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    
    return temp->data;
}

Node* deletionInBST(Node* &root, int target) {
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
    else{
        if (root->left == NULL && root->right == NULL)
        {
            cout << "Deleting From Case 1" << endl;
            delete root;
            root = NULL;
        }
        else if(root->left != NULL && root->right == NULL){
            Node* nodeToDelete = root;
            root = root->left;

            nodeToDelete->left = NULL;
            nodeToDelete->right = NULL;
            delete nodeToDelete;
        }
        else if(root->right != NULL && root->left == NULL){
            Node* nodeToDelete = root;
            root = root->right;

            nodeToDelete->left = NULL;
            nodeToDelete->right = NULL;
            delete nodeToDelete;
        }
        else{
            // root->data = findMinInBST(root->right);
            // cout << "Found Min " << root->data <<  "  " << root->right->data << endl;
            // root->right = deletionInBST(root->right, root->data);

            // Alternatively can Use
            root->data = findMaxInBST(root->left);
            cout << "Found Max " << root->data <<  "  " << root->left->data << endl;
            root->left = deletionInBST(root->left, root->data);
        }
    }
    
    return root;
}

Node* buildBST(vector<int> &arr){
    Node* root = NULL;

    for(auto element : arr){
        root = insertInBST(root, element);
    }

    return root;
}

int main()
{
    vector<int> list = {4,2,1,3,6,5,7};

    Node* ped = buildBST(list);

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

    cout << "\nPrinting in Level Order Traversal: " << endl;
    levelOrderTraversal(ped);

    cout << "Let's delete something...." << endl;
    // deletionInBST(ped, 7);
    // deletionInBST(ped, 6);
    deletionInBST(ped, 4);

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

    cout << "Dude Here is Min: " << findMinInBST(ped) << endl;

    cout << endl;

    return 0;
}