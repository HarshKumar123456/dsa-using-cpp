#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class heightAndDia
{
public:
    int height;
    int diameter;
};

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

int heightOfTreeUsingLevelOrderTraversal(Node *&root)
{
    // Agar had hi nahin to ped kaisa
    if (root == NULL)
    {
        return -1;
    }

    // Without Using NULL as Extra pointer printing in Level wise Pattern
    queue<Node *> pankti;
    pankti.push(root);

    int levelSize = 0;
    int height = 0;

    while (pankti.empty() == false)
    {
        levelSize = pankti.size();

        for (int i = 0; i < levelSize; i++)
        {
            Node *temp = pankti.front();
            pankti.pop();

            // cout << temp->data << " ";

            if (temp->left != NULL)
            {
                pankti.push(temp->left);
            }

            if (temp->right != NULL)
            {
                pankti.push(temp->right);
            }
        }

        height++;
        // cout << endl; // Level Ended
    }

    return height;
}

void levelOrderTraversal(Node *&root)
{
    // Agar had hi nahin to ped kaisa
    if (root == NULL)
    {
        return;
    }

    // Without Using NULL as Extra pointer printing in Level wise Pattern
    queue<Node *> pankti;
    pankti.push(root);

    int levelSize = 0;

    while (pankti.empty() == false)
    {
        levelSize = pankti.size();

        for (int i = 0; i < levelSize; i++)
        {
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
        }

        cout << endl; // Level Ended
    }
}

int diameterOfBinaryTree(Node *root)
{
    // Agar jadd nahin to ped kaisa
    if (root == NULL)
    {
        return 0;
    }

    int diameterOfLeftSubTree = diameterOfBinaryTree(root->left);
    int diameterOfRightSubTree = diameterOfBinaryTree(root->right);

    int heightOfLeftSubTree = heightOfTree(root->left);
    int heightOfRightSubTree = heightOfTree(root->right);

    int diameter = heightOfLeftSubTree + heightOfRightSubTree;
    int maxDiameter = max(max(diameterOfLeftSubTree, diameterOfRightSubTree), diameter);

    return maxDiameter;
}

heightAndDia diameterOfBinaryTreeFast(Node *root)
{
    heightAndDia ans;

    // Agar jadd nahin to ped kaisa
    if (root == NULL)
    {
        ans.height = 0;
        ans.diameter = 0;
        return ans;
    }

    heightAndDia leftSubTree = diameterOfBinaryTreeFast(root->left);
    heightAndDia rightSubTree = diameterOfBinaryTreeFast(root->right);

    int diameterOfLeftSubTree = leftSubTree.diameter;
    int diameterOfRightSubTree = rightSubTree.diameter;

    int heightOfLeftSubTree = leftSubTree.height;
    int heightOfRightSubTree = rightSubTree.height;

    int height = max(heightOfLeftSubTree, heightOfRightSubTree) + 1;
    int diameter = heightOfLeftSubTree + heightOfRightSubTree;

    int maxDiameter = max(max(diameterOfLeftSubTree, diameterOfRightSubTree), diameter);

    ans.diameter = maxDiameter;
    ans.height = height;
    return ans;
}

int diameterOfBinaryTreeWithoutUsingHeight(Node *&root)
{

    /*

    // Without Even Using Those two things too
    // It works like first of all it will get the result such that at leaf node it will update the ans as left + right that is 0 then at 1 node up it will update the ans as 1 or 2 as per the sum of left and right tree i.e. node having 1 or two childs thus every time the ans will having the max diameter till now from the left, right subtrees and if there is possible diameter with combining the both subtrees then it will combine and it will be compared against till now max diameter
    class Solution {
    public:
        int ans = INT_MIN;
        int maxDepth(TreeNode* root) {
            if(!root) return 0;
            int left = maxDepth(root->left);
            int right = maxDepth(root->right);
            ans = max(left+right, ans);
            return max(left, right) + 1;
        }

        int diameterOfBinaryTree(TreeNode* root) {
            maxDepth(root);
            return ans;
        }
    };
    */
    return diameterOfBinaryTreeFast(root).diameter;
}

bool isBalanced(Node *&root)
{
    // Agar jadd nahin to ped kaisa
    if (root == NULL)
    {
        return true;
    }

    bool isBalancedLeft = isBalanced(root->left);
    bool isBalancedRight = isBalancedLeft == false ? false : isBalanced(root->right); // Early Optimizing calls

    if (isBalancedLeft && isBalancedRight)
    {
        int heightOfLeftSubtree = heightOfTree(root->left);
        int heightOfRightSubtree = heightOfTree(root->right);

        int differenceOfHeights = abs(heightOfLeftSubtree - heightOfRightSubtree);

        return differenceOfHeights <= 1 ? true : false;
    }

    return false;
}

pair<bool, int> isBalancedFast(Node *&root)
{
    // Agar jadd nahin to ped kaisa
    if (root == NULL)
    {
        return make_pair(true, 0);
    }

    pair<bool, int> leftSubtree = isBalancedFast(root->left);

    bool isBalancedLeft = leftSubtree.first;

    // Early Optimizing calls
    pair<bool, int> rightSubtree = isBalancedLeft == false ? make_pair(false, 0) : isBalancedFast(root->right);

    bool isBalancedRight = rightSubtree.first;

    if (isBalancedLeft && isBalancedRight)
    {
        int heightOfLeftSubtree = leftSubtree.second;
        int heightOfRightSubtree = rightSubtree.second;

        int height = max(heightOfLeftSubtree, heightOfRightSubtree) + 1;

        int differenceOfHeights = abs(heightOfLeftSubtree - heightOfRightSubtree);

        return differenceOfHeights <= 1 ? make_pair(true, height) : make_pair(false, 0);
    }

    return make_pair(false, 0);
}

bool isBalancedWithoutUsingHeight(Node *&root)
{
    return isBalancedFast(root).first;
}

// Function that returns the height of the tree if the tree is balanced
// Otherwise it returns -1.
int isBalancedRec(Node *root)
{

    // Base case: Height of empty tree is zero
    if (root == NULL)
        return 0;

    // Find Heights of left and right sub trees
    int lHeight = isBalancedRec(root->left);
    int rHeight = isBalancedRec(root->right);

    // If either the subtrees are unbalanced or the absolute difference
    // of their heights is greater than 1, return -1
    if (lHeight == -1 || rHeight == -1 || abs(lHeight - rHeight) > 1)
        return -1;

    // Return the height of the tree
    return max(lHeight, rHeight) + 1;
}

// Function to check if tree is height balanced
bool isBalancedOptimizedHeightOnlyCalculateAndTell(Node *root)
{
    return (isBalancedRec(root) > 0);
}

pair<bool, int> isSumTree(Node *root)
{
    // Empty Case
    if (root == NULL)
    {
        return make_pair(true, 0);
    }

    // Leaf Node Case
    if (root->left == NULL && root->right == NULL)
    {
        return make_pair(true, root->data);
    }

    pair<bool, int> leftSubtree = isSumTree(root->left);
    pair<bool, int> rightSubtree = isSumTree(root->right);

    int leftSum = leftSubtree.second;
    int rightSum = rightSubtree.second;

    if (leftSubtree.first && rightSubtree.first && root->data == (leftSum + rightSum))
    {
        return make_pair(true, 2 * (root->data));
    }

    return make_pair(false, -1);
}

int main()
{
    Node *ped = NULL;
    ped = buildTree(ped);

    cout << "Printing in Level Order Traversal: " << endl;
    levelOrderTraversal(ped);

    cout << "Bro height of tree is: " << heightOfTree(ped) << endl;
    cout << "Bro height of tree is: " << heightOfTreeUsingLevelOrderTraversal(ped) << endl;
    cout << "Bro diameter of tree is: " << diameterOfBinaryTree(ped) << endl;
    cout << "Bro diameter of tree is: " << diameterOfBinaryTreeWithoutUsingHeight(ped) << endl;

    cout << "Is sum tree: " << isSumTree(ped).first << endl;

    return 0;
}