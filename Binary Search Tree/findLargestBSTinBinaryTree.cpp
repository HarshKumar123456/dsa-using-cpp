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

// Find Largest BST in Binary Tree

// Make a Class That will store info of Subtree
class TreeInfo
{
public:
    int heightOfTree;
    int heightOfLargestBST;
    bool isBST;
    int numberOfNodesInTree;
    int numberOfNodesInLargestBST;
    int sumOfNodesOfTree;
    int sumOfLargestBST;
};


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

TreeInfo findLargestBSTinBinaryTree(Node *root)
{
    TreeInfo rootInfo;
    if (root == NULL)
    {
        rootInfo.isBST = true;
        rootInfo.heightOfTree = 0;
        rootInfo.heightOfLargestBST = 0;
        rootInfo.numberOfNodesInTree = 0;
        rootInfo.numberOfNodesInLargestBST = 0;
        rootInfo.sumOfNodesOfTree = 0;
        rootInfo.sumOfLargestBST = 0;

        return rootInfo;
    }

    TreeInfo leftSubtree = findLargestBSTinBinaryTree(root->left); 
    TreeInfo rightSubtree = findLargestBSTinBinaryTree(root->right); 

    int largestBSTHeight = 0;
    int largestBSTNodesNumber = 0;
    int largestBSTNodesSum = 0;

    // Basically Yahan se pata chala ki neeche ki Optimzed conditions tak kaise pahunchna hai
//     if( ( leftSubtree.numberOfNodesInLargestBST > rightSubtree.numberOfNodesInLargestBST) && (leftSubtree.isBST || (leftSubtree.isBST == false && rightSubtree.isBST == false) || (leftSubtree.isBST == false && rightSubtree.isBST == true))
// ) {
//         largestBSTHeight = leftSubtree.heightOfLargestBST;
//         largestBSTNodesNumber = leftSubtree.numberOfNodesInLargestBST;
//         largestBSTNodesSum = leftSubtree.sumOfLargestBST;
//     }
//     else if(( leftSubtree.numberOfNodesInLargestBST < rightSubtree.numberOfNodesInLargestBST) && (rightSubtree.isBST || (leftSubtree.isBST == false && rightSubtree.isBST == false) || (leftSubtree.isBST == true && rightSubtree.isBST == false))){
//         largestBSTHeight = rightSubtree.heightOfLargestBST;
//         largestBSTNodesNumber = rightSubtree.numberOfNodesInLargestBST;
//         largestBSTNodesSum = rightSubtree.sumOfLargestBST;
//     }
//     else if((leftSubtree.numberOfNodesInLargestBST == rightSubtree.numberOfNodesInLargestBST) && (leftSubtree.sumOfLargestBST >= rightSubtree.sumOfLargestBST)){
//         largestBSTHeight = leftSubtree.heightOfLargestBST;
//         largestBSTNodesNumber = leftSubtree.numberOfNodesInLargestBST;
//         largestBSTNodesSum = leftSubtree.sumOfLargestBST;
//     }
//     else
//     {
//         largestBSTHeight = rightSubtree.heightOfLargestBST;
//         largestBSTNodesNumber = rightSubtree.numberOfNodesInLargestBST;
//         largestBSTNodesSum = rightSubtree.sumOfLargestBST;
//     }



    // Optimized Conditions for above
    if((leftSubtree.numberOfNodesInLargestBST > rightSubtree.numberOfNodesInLargestBST) ||(leftSubtree.numberOfNodesInLargestBST == rightSubtree.numberOfNodesInLargestBST && leftSubtree.sumOfLargestBST > rightSubtree.sumOfLargestBST)){
        largestBSTHeight = leftSubtree.heightOfLargestBST;
        largestBSTNodesNumber = leftSubtree.numberOfNodesInLargestBST;
        largestBSTNodesSum = leftSubtree.sumOfLargestBST;
    }
    else
    {
        largestBSTHeight = rightSubtree.heightOfLargestBST;
        largestBSTNodesNumber = rightSubtree.numberOfNodesInLargestBST;
        largestBSTNodesSum = rightSubtree.sumOfLargestBST;
    }



    
    
    

    bool isRootBST = false;

    int sumOfNodes = leftSubtree.sumOfNodesOfTree + rightSubtree.sumOfNodesOfTree + root->data;
    int numberOfNodes = leftSubtree.numberOfNodesInTree + rightSubtree.numberOfNodesInTree + 1;
    int height = max(leftSubtree.heightOfTree, rightSubtree.heightOfTree) + 1; 

    // Case 1: Both Childs Are BST
    if(leftSubtree.isBST == true && rightSubtree.isBST == true){
        if(
            (largestBSTNodesNumber <= numberOfNodes) &&
            (root->left != NULL && root->data >= findMaxInBST(root->left)) && (root->right != NULL && root->data <= findMinInBST(root->right)) 
            || (root->left == NULL) && (root->right != NULL && root->data <= findMinInBST(root->right)) 
            || (root->left != NULL && root->data >= findMaxInBST(root->left)) && (root->right == NULL)
            || (root->left == NULL) && (root->right == NULL)
        ){
            cout << "Updating for root-> " << root->data << " height, number of nodes, node's sum are: " << height << " " << numberOfNodes << " " << sumOfNodes << endl;
            levelOrderTraversal(root);
            cout << "----" << endl;
            inOrder(root);
            cout << endl;
            preOrder(root);
            cout << endl;

            isRootBST = true;
            largestBSTHeight = height;
            largestBSTNodesNumber = numberOfNodes;
            largestBSTNodesSum = sumOfNodes;
        }
    }
    // Case 2: Both Childs Are Not BST
    else if(leftSubtree.isBST == false && rightSubtree.isBST == false){
        isRootBST = false;
    }
    // Case 3: Only Left Child BST
    else if(leftSubtree.isBST == true && rightSubtree.isBST == false){
        isRootBST = false;
    }
    // Case 4: Only Right Child BST
    else{
        isRootBST = false;
    }

    rootInfo.heightOfTree = height;
    rootInfo.numberOfNodesInTree = numberOfNodes;
    rootInfo.sumOfNodesOfTree = sumOfNodes;

    rootInfo.isBST = isRootBST;

    rootInfo.heightOfLargestBST = largestBSTHeight;
    rootInfo.numberOfNodesInLargestBST = largestBSTNodesNumber;
    rootInfo.sumOfLargestBST = largestBSTNodesSum;

    return rootInfo;
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


int main()
{
    Node *ped = NULL;

    // Build From Level Order Traversal
    // 68 300 -1 17 303 -1 69 99 -1 30 171 -1 81 354 -1 53 210 -1 249 300 -1 188 342 -1 209 329 -1 303 81 -1 27 283 -1 127 125 -1 174 293 -1 197 62 -1 92 50 -1 331 346 -1 175 163 -1 248 217 -1 79 73 -1 278 265 -1 220 276 -1 109 343 -1 105 22 -1 61 240 -1 288 44 -1 30 226 -1 333 341 -1 311 157 -1 29 220 -1 303 226 -1 338 351 -1 155 87 -1 213 130 -1 298 134 -1 17 110 -1 216 132 -1 38 41 -1 101 237 -1 201 146 -1 318 89 -1 314 353 -1 137 299 -1 125 180 -1 227 350 -1 211 134 -1 133 229 -1 283 261 -1 78 93 -1 42 15 -1 280 94 -1 58 341 -1 150 96 -1 91 350 -1 154 172 -1 157 122 -1 357 2 -1 95 299 -1 213 253 -1 33 165 -1 160 186 -1 281 239 -1 108 11 -1 299 121 -1 281 54 -1 6 69 -1 141 318 -1 232 130 -1 154 203 -1 352 172 -1 267 274 -1 336 254 -1 301 336 -1 303 221 -1 78 222 -1 181 259 -1 356 125 -1 243 224 -1 355 9 -1 211 31 -1 63 303 -1 158 196 -1 294 116 -1 213 32 -1 120 67 -1 16 321 -1 2 258 -1 27 101 -1 15 285 -1 55 158 -1 148 143 -1 151 202 -1 138 159 -1 252 194 -1 185 145 -1 206 230 -1 284 154 -1 322 355 -1 291 241 -1 225 28 -1 65 76 -1 157 358 -1 186 46 -1 358 226 -1 111 212 -1 50 327 -1 19 132 -1 115 22 -1 73 17 -1 340 308 -1 24 337 -1 348 192 -1 164 93 -1 261 182 -1 276 343 -1 179 47 -1 180 187 -1 353 91 -1 131 97 -1 117 67 -1 230 9 -1 170 141 -1 235 111 -1 37 78 -1 331 220 -1 161 1 -1 10 133 -1 155 37 -1 170 346 -1 353 65 -1 124 276

    vector<int> elements = {68,300,-1,17,303,-1,69,99,-1,30,171,-1,81,354,-1,53,210,-1,249,300,-1,188,342,-1,209,329,-1,303,81,-1,27,283,-1,127,125,-1,174,293,-1,197,62,-1,92,50,-1,331,346,-1,175,163,-1,248,217,-1,79,73,-1,278,265,-1,220,276,-1,109,343,-1,105,22,-1,61,240,-1,288,44,-1,30,226,-1,333,341,-1,311,157,-1,29,220,-1,303,226,-1,338,351,-1,155,87,-1,213,130,-1,298,134,-1,17,110,-1,216,132,-1,38,41,-1,101,237,-1,201,146,-1,318,89,-1,314,353,-1,137,299,-1,125,180,-1,227,350,-1,211,134,-1,133,229,-1,283,261,-1,78,93,-1,42,15,-1,280,94,-1,58,341,-1,150,96,-1,91,350,-1,154,172,-1,157,122,-1,357,2,-1,95,299,-1,213,253,-1,33,165,-1,160,186,-1,281,239,-1,108,11,-1,299,121,-1,281,54,-1,6,69,-1,141,318,-1,232,130,-1,154,203,-1,352,172,-1,267,274,-1,336,254,-1,301,336,-1,303,221,-1,78,222,-1,181,259,-1,356,125,-1,243,224,-1,355,9,-1,211,31,-1,63,303,-1,158,196,-1,294,116,-1,213,32,-1,120,67,-1,16,321,-1,2,258,-1,27,101,-1,15,285,-1,55,158,-1,148,143,-1,151,202,-1,138,159,-1,252,194,-1,185,145,-1,206,230,-1,284,154,-1,322,355,-1,291,241,-1,225,28,-1,65,76,-1,157,358,-1,186,46,-1,358,226,-1,111,212,-1,50,327,-1,19,132,-1,115,22,-1,73,17,-1,340,308,-1,24,337,-1,348,192,-1,164,93,-1,261,182,-1,276,343,-1,179,47,-1,180,187,-1,353,91,-1,131,97,-1,117,67,-1,230,9,-1,170,141,-1,235,111,-1,37,78,-1,331,220,-1,161,1,-1,10,133,-1,155,37,-1,170,346,-1,353,65,-1,124,276};

    queue<int> levelOrderTraversalOfTreeQueue;
    for (auto number : elements)
    {
        levelOrderTraversalOfTreeQueue.push(number);
    }

    ped = buildTreeFromLevelOrderTraversal(levelOrderTraversalOfTreeQueue);

    // Build Tree Function 
    // 1 2 -1 -1 3 -1 -1
    // 40 20 10 5 -1 -1 15 -1 -1 30 25 -1 -1 35 -1 -1 60 50 45 -1 -1 55 -1 -1 70 65 -1 -1 75 -1 -1
    // 45 20 10 5 -1 -1 15 -1 -1 35 30 25 -1 -1 -1 40 -1 -1 50 -1 60 55 -1 -1 75 70 65 -1 -1 -1 -1
    // 10 5 3 30 -1 -1 -2 -1 -1 2 -1 1 -1 -1 -3 -1 11 -1 -1
    // 1 5 9 2 -1 7 5 4 -1 -1 -1 -1 11 10 -1 -1 20 14 -1 -1 -1 100 -1 -1 101 19 -1 -1 21 10 -1 20 18 -1 -1 -1 -1
    // 6 7 -1 2 -1 -1 3 2 -1 -1 4 -1 -1
    // 8 11 10 9 -1 -1 4 -1 -1 -1 1 1 -1 -1 6 -1 -1
    // ped = buildTree(ped);

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
    cout << "Bro Largest BST Found in this Binary tree is as follows: " << endl;
    TreeInfo largestBST = findLargestBSTinBinaryTree(ped);
    cout << "Largest BST Height is: " << largestBST.heightOfLargestBST << endl;
    cout << "Largest BST has Node's Number: " << largestBST.numberOfNodesInLargestBST << endl;
    cout << "Largest BST has Node's Sum: " << largestBST.sumOfLargestBST << endl;

    cout << endl;
    return 0;
}