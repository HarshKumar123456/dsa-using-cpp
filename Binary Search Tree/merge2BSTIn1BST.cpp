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

// Merge Two BST

// Approach 1: TC: O(M+N)  &  SC: O(M+N)
// First of all get the In Orders for both the Trees and then merge them in sorted manner because har BST ka In Order sorted hota hai isiliye then make the BST after that Merged In Order
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

vector<int> mergeTwoSortedArray(vector<int> &first, vector<int> &second)
{

    int i = 0, j = 0, k = 0, firstSize = first.size(), secondSize = second.size();
    vector<int> third;

    // cout << "In Merge First and Second Size: " << firstSize << " - " << secondSize << endl;
    // for(auto i : first){
    //  cout << i << " ";
    // }
    // cout << endl;

    // for(auto i : second){
    //  cout << i << " ";
    // }
    // cout << endl;

    while (i < firstSize && j < secondSize)
    {
        if (first[i] <= second[j])
        {
            // cout << "Pushed from 1 and now i = " << i << endl;
            third.push_back(first[i++]);
        }
        else
        {
            // cout << "Pushed from 2 and now j = " << j << endl;
            third.push_back(second[j++]);
        }
        // for(auto i : third){
        //  cout << i << " ";
        // }
        // cout << endl;
    }

    while (i < firstSize)
    {
        third.push_back(first[i++]);
    }

    while (j < secondSize)
    {
        third.push_back(second[j++]);
    }

    // for(auto i : third) {
    //     cout << i << " ";
    // }
    // cout << endl;
    return third;
}

Node *inorderToBST(vector<int> &inOrderArray, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    int mid = start + (end - start) / 2;

    Node *root = new Node(inOrderArray[mid]);

    root->left = inorderToBST(inOrderArray, start, mid - 1);
    root->right = inorderToBST(inOrderArray, mid + 1, end);

    return root;
}

Node *mergeTreeUsingInOrderMerge(Node *&firstRoot, Node *&secondRoot)
{
    // First of All get In Order of Both Trees
    vector<int> firstRootInOrderArray;
    vector<int> secondRootInOrderArray;

    inorder(firstRoot, firstRootInOrderArray);
    inorder(secondRoot, secondRootInOrderArray);

    // Then Merge Two Sorted Arrays
    vector<int> inOrderOfMergedBST = mergeTwoSortedArray(firstRootInOrderArray, secondRootInOrderArray);
    int numberOfNodesInMergedBST = inOrderOfMergedBST.size();

    // Make Tree From In Order
    Node *root = NULL;
    root = inorderToBST(inOrderOfMergedBST, 0, numberOfNodesInMergedBST - 1);

    return root;
}

// Approach 2: TC: O(M+N)  &   SC: O(h1 + h2)
// First Of All Convert Both Trees into Linked Lists and then Merge these two Sorted Linked Lists and then make the BST from this sorted Linked List

Node *convertBSTinLL(Node *root, Node *&head)
{
    // Flatten Tree in In Order ka use bhi kar sakte hain but try Recursion this time

    if (root == NULL)
    {
        return NULL;
    }

    Node *leftSubtree = convertBSTinLL(root->left, head);

    if (head != NULL)
    {
        head->right = root;
    }
    head = root;

    root->left = NULL; // Essential if we want only SLL like structure next pointer resembles right pointer here and left pointer has no use

    Node *rightSubtree = convertBSTinLL(root->right, head);
    root->right = rightSubtree;

    return leftSubtree == NULL ? root : leftSubtree;
}

Node* convertBSTinDLL(Node* root, Node* &head){

    if (root == NULL)
    {
        return NULL;
    }

    Node *leftSubtree = convertBSTinDLL(root->left, head);

    if (head != NULL)
    {
        head->right = root;
    }

    root->left = head;
    head = root;


    Node *rightSubtree = convertBSTinDLL(root->right, head);
    root->right = rightSubtree;
    if(rightSubtree != NULL) {
        rightSubtree->left = root;
    }

    return leftSubtree == NULL ? root : leftSubtree;
}

// Alternate of Above
void convertBSTintoDLL(Node* root, Node* &head) {
    // In This Approach you Will find the head as starting of the Linked List
    if (root == NULL)
    {
        return ;
    }

    convertBSTintoDLL(root->right, head);

    root->right = head;
    if (head != NULL)
    {
        head->left = root;
    }
    head = root;

    convertBSTintoDLL(root->left, head);

}

Node *mergeTwoLLs(Node *&first, Node *&second)
{
    Node *temp = new Node(-1);
    Node *third = temp;

    while (first != NULL && second != NULL)
    {
        if (first->data <= second->data)
        {
            third->right = first;
            first = first->right;
        }
        else
        {
            third->right = second;
            second = second->right;
        }

        third = third->right;
    }

    while (first != NULL)
    {
        third->right = first;
        first = first->right;
        third = third->right;
    }

    while (second != NULL)
    {
        third->right = second;
        second = second->right;
        third = third->right;
    }


    
    third = temp->right;
    temp->left = NULL;
    temp->right = NULL;
    delete temp;
    return third;
}

Node *sortedLLtoBST(Node *&head, int sizeOfLinkedList)
{
    // TC: O(n)  &  SC: O(log n)
    if (sizeOfLinkedList <= 0 || head == NULL)
    {
        return NULL;
    }

    Node *leftSubtree = sortedLLtoBST(head, sizeOfLinkedList / 2);

    Node *root = head;
    root->left = leftSubtree;

    head = head->right;

    Node *rightSubtree = sortedLLtoBST(head, sizeOfLinkedList - sizeOfLinkedList / 2 - 1);
    root->right = rightSubtree;

    return root;
}


Node* mergeTreeUsingMakingLLAndMergeAndRecursivelyBuildingFromLeafSpaceOptimized (Node* &firstRoot, Node* &secondRoot){

    // Make Linked Lists
    Node* head = NULL;
    Node* firstLL = convertBSTinDLL(firstRoot, head);

    head = NULL;
    Node* secondLL = convertBSTinLL(secondRoot, head);
    

    // Merge Two LL
    Node* mergedLL = mergeTwoLLs(firstLL, secondLL);
    int numberOfNodesInMergedLL = 0;

    Node* temp = mergedLL;
    while(temp != NULL) {
        temp = temp->right;
        numberOfNodesInMergedLL++;
    }

    // Make Tree from Sorted LL
    Node* root = sortedLLtoBST(mergedLL, numberOfNodesInMergedLL);

    return root;
}

int main()
{
    vector<int> firstList = {40, 20};
    vector<int> secondList = {4, 2, 1, 3, 6, 5, 7};

    Node *firstPed = buildBST(firstList);
    Node *secondPed = buildBST(secondList);

    Node *mergedPed = mergeTreeUsingMakingLLAndMergeAndRecursivelyBuildingFromLeafSpaceOptimized(firstPed, secondPed);

    cout << endl;

    cout << "For First Tree: " << endl;

    cout << endl;
    cout << "Printing In Order: ";
    inOrder(firstPed);

    cout << endl;
    cout << "Printing Pre Order: ";
    preOrder(firstPed);

    cout << endl;
    cout << "Printing Post Order: ";
    postOrder(firstPed);

    cout << "\nPrinting in Level Order Traversal: " << endl;
    levelOrderTraversal(firstPed);

    cout << endl;
    cout << "For Second Tree: " << endl;

    cout << "Printing In Order: ";
    inOrder(secondPed);

    cout << endl;
    cout << "Printing Pre Order: ";
    preOrder(secondPed);

    cout << endl;
    cout << "Printing Post Order: ";
    postOrder(secondPed);

    cout << "\nPrinting in Level Order Traversal: " << endl;
    levelOrderTraversal(secondPed);

    cout << endl;
    cout << "For (First + Second) Tree: " << endl;

    cout << "Printing In Order: ";
    inOrder(mergedPed);

    cout << endl;
    cout << "Printing Pre Order: ";
    preOrder(mergedPed);

    cout << endl;
    cout << "Printing Post Order: ";
    postOrder(mergedPed);

    cout << "\nPrinting in Level Order Traversal: " << endl;
    levelOrderTraversal(mergedPed);

    cout << endl;
    cout << "For (First + Second) Tree to SLL: " << endl;
    Node *head = NULL;
    mergedPed = convertBSTinLL(mergedPed, head);

    cout << "Printing In Order: ";
    inOrder(mergedPed);

    cout << endl;
    cout << "Printing Pre Order: ";
    preOrder(mergedPed);

    cout << endl;
    cout << "Printing Post Order: ";
    postOrder(mergedPed);

    cout << "\nPrinting in Level Order Traversal: " << endl;
    levelOrderTraversal(mergedPed);

    cout << "Printing mentos Level: " << endl;
    Node *temp = mergedPed;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        if (temp->left != NULL)
        {
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        }
        temp = temp->right;
    }
    cout << endl;

    cout << endl;

    return 0;
}