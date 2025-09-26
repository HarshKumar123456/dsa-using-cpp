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

bool presentInTree(Node *&root, int data)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == data)
    {
        return true;
    }

    return presentInTree(root->left, data) || presentInTree(root->right, data);
}

pair<Node *, pair<bool, bool>> solve(Node *&root, int first, int second, int &count)
{
    count++;

    if (root == NULL)
    {
        cout << "NULL Node: f f" << endl;
        return make_pair(root, make_pair(false, false));
    }
    
    cout << "Call for: " << root->data << endl << endl;

    if (root->data == first)
    {
        pair<Node *, pair<bool, bool>> leftSub = solve(root->left, first, second, count);
        pair<Node *, pair<bool, bool>> rightSub = solve(root->right, first, second, count);

        Node *ans = NULL;

        // Check if we got second one also
        if (leftSub.second.second == true || rightSub.second.second == true)
        {
            cout << root->data << " ->  Found Both: t t" << endl;
            return make_pair(ans, make_pair(true, true));
        }
        else{
            cout << root->data << " ->  Found first: t f" << endl;
            return make_pair(ans, make_pair(true, false));
        }
    }
    
    if (root->data == second)
    {
        pair<Node *, pair<bool, bool>> leftSub = solve(root->left, first, second, count);
        pair<Node *, pair<bool, bool>> rightSub = solve(root->right, first, second, count);
        
        Node *ans = NULL;
        
        // Check if we got second one also
        if (leftSub.second.first == true || rightSub.second.first == true)
        {
            cout << root->data << " ->  Found both: t t" << endl;
            return make_pair(ans, make_pair(true, true));
        }
        else{
            cout << root->data << " ->  Found second: f t" << endl;
            return make_pair(ans, make_pair(false, true));
        }
    }

    pair<Node *, pair<bool, bool>> leftSub = solve(root->left, first, second, count);
    pair<Node *, pair<bool, bool>> rightSub = solve(root->right, first, second, count);

    // If Already Got Lowest Common Ancestor then Superb
    if (leftSub.first != NULL)
    {
        cout << "Already found left Sub: " << leftSub.first->data << " now at " << root->data << endl; 
        return make_pair(leftSub.first, make_pair(true, true));
    }
    
    if (rightSub.first != NULL)
    {
        cout << "Already found right Sub: " << rightSub.first->data << " now at " << root->data << endl; 
        return make_pair(rightSub.first, make_pair(true, true));
    }
    

    // There can Be Many Possibilities
    // Left Sub Tree got the first, second both
    if (leftSub.second.first == true && leftSub.second.second == true)
    {
        cout << "Found LCA : " << root->data << " For L: t t and For R: _ _ " << endl; 
        return make_pair(root, make_pair(true, true));
    }
    // Left Sub Tree got the first, Right Sub Tree got the second 
    else if (leftSub.second.first == true && rightSub.second.second == true){
        cout << "Found LCA : " << root->data << " For L: t _ and For R: _ t " << endl; 
        return make_pair(root, make_pair(true, true));
    }
    // Left Sub Tree got the second, Right Sub Tree got the first 
    else if (leftSub.second.second == true && rightSub.second.first == true){
        cout << "Found LCA : " << root->data << " For L: _ t and For R: t _ " << endl; 
        return make_pair(root, make_pair(true, true));
    }
    // Right Sub Tree got the first, second both
    else if (rightSub.second.first == true && rightSub.second.second == true){
        cout << "Found LCA : " << root->data << " For L: _ _ and For R: t t " << endl; 
        return make_pair(root, make_pair(true, true));
    }
    else{
        cout << "Not Found LCA : " << root->data << " For L: _ _ and For R: _ _ " << endl; 
        Node* ans = NULL;

        bool foundFirst = leftSub.second.first || rightSub.second.first;
        bool foundSecond = leftSub.second.second || rightSub.second.second;

        return make_pair(ans, make_pair(foundFirst, foundSecond));
    }

}

void lowestCommonAncestorOfTwoNodes(Node *&root, int first, int second)
{

    Node *ans = NULL;

    if (first == second)
    {
        cout << "Bhai 2 Alag Alag Nodes Dene hain. "<< endl;
        return ;
    }
    
    if (root == NULL)
    {
        cout << "Bhai Empty Tree Mein Kya Find Karwa rahe. " << endl;
        return ;
    }
    
    if(presentInTree(root, first) == false || presentInTree(root, second) == false) {
        cout << "Bhai Tree mein ye hain hi na. " << endl;
        return ;
    }

    int count = 0;
    pair<Node *, pair<bool, bool>> lowestCommonAncestor = solve(root, first, second, count);
    ans = lowestCommonAncestor.first;

    cout << "Bhai Ran " << count << " times. " << endl;

    if (ans == NULL)
    {
        cout << "Bhai Found No Common Ancestor for " << first << " and " << second << endl;
        return ;
    }
    
    cout << "Bhai Found " << ans->data << " Common Ancestor for " << first << " and " << second << endl;
    
}

int main()
{
    // vector<int> list = {1, 2, 3, -1, -1, 4, 5, 6, 7, 8, 9, 10, -1, -1, 11, 12, -1, 13, 14, 15, 16, 17, 18, -1, -1, -1, -1, -1}; // Max Sum is: 72
    vector<int> list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
    // vector<int> list = {-10, 10, 20, -1, -1, 15, 7}; // Output: 15 -> 20 -> 7
    // vector<int> list = {-4,-2}; // Output: -2 ->
    // vector<int> list = {1,2,3}; // Output: 2 -> 1 -> 3
    // vector<int> list = {-519, -283, -42, 322, 103, -1, 263, 826, -706, 920, 691, -38, -765, -1, -1, -658, 386, 328, -214, -159, 284, 281, -1, 122, -920, 59, -1, -838, -1, 588, -167, 824, 723, -502, -17, -898, 492, -1, -373, 884, 777, 603, -44, -1, -723, -678, -1, -426, 536, 683, -1, -368, -845, -762, -218, -997, 757, -992, 685, -519, -990, -1, -959, 64, -1, 878, 435, -640, -1, -1, 481, -139, -1, -1, -1, -1, -1, -1, -273, 433, -256, -47, -1, -588, -547, 764, 681, -1, -894, 122, -162, 521, -237, -1, -132, -567, -148, 199, -653, 982, -752, -420, -1, -535, 877, -1, -15, 729, -294, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 350, -85, 656, 47, -1, -1, 33, -1, -1, -219, -1, -1, 822, -1, -817, -944, -184, 213, 652, -1, -11, -1, 529, 389, -895, -1, -1, -1, -933, -1, 484, -817, 555, 735, -232, -1, -233, -566, 196, 285, -538, -1, 879, 225, -1, -213, -1, -1, -1, -1, -1, -1, -321, -887, -1, -1, 685, -76, -1, -1, -1, 853, 76, -1, -512, -526, -1, 490, -1, -1, -318, -386, -1, -1, -1, -400, -1, -1, 934, 604, -1, -1, -1, -1, 149, -523, 962, -501, -624, -743, -134, 731, -468, -83, 585, 484, 579, 765, -1, -125, 480, -1, -1, 836, -1, -1, -1, -1, -1, -1, -237, -1, -1, -1, -833, -218, -1, -1, -1, 609, -1, -1, -129, -1, -1, 928, -1, -69, -1, -1, -1, -1, -1, -189, -1, -1, -1, -1, -1, -739, -388, -1, -1, -1, -670, -550, -1, -483, -1, -1, -1, -850, -1, -1, -1, -1, -1, -1, -1, -1, -10, -1, -1, 995, -1, -1, -1, -1, -1, -1, -1, -1, -1, -388, 880, -1, -251, -988, -1, -1, -1, -1, 615, -897, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 680, -1, 177, -1, -1, -1, -485, -1, -34, 81, -1, -1, -1, -1, 375, -371, -1, 699, -1, -1, -1, -788, -1, -1, -1, -1, -847, 490, -571, -1, -151, -1, -1, -597, -1, 854, -1, -1, -715, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -731, -845, 384, 201, -1, -1, -1, -1, -1, -682, -1, 927}; // O(N^2) wala solution iske liye mar gaya TLE

    queue<int> q;

    for (auto i : list)
    {
        q.push(i);
    }

    Node *ped = NULL;
    ped = buildTreeFromLevelOrderTraversal(q);

    levelOrderTraversal(ped);

    printBachche(ped);

    lowestCommonAncestorOfTwoNodes(ped, 7, 30);

    return 0;
}