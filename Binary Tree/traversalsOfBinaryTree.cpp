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

void levelOrderTraversal(Node *&root)
{
    // Agar jad hi nahin to ped kaisa
    if (root == NULL)
    {
        return;
    }

    queue<Node *> line;
    line.push(root);

    while (line.empty() == false)
    {
        int sizeOfLevel = line.size();

        for (int i = 0; i < sizeOfLevel; i++)
        {
            Node *temp = line.front();
            line.pop();

            cout << temp->data << " ";

            if (temp->left != NULL)
            {
                line.push(temp->left);
            }

            if (temp->right != NULL)
            {
                line.push(temp->right);
            }
        }
        // Level Ended
        cout << endl;
    }
}

void saveByHorizontalVerticalDistance(Node *&root, map<int, map<int, vector<int>>> &mapping, int horizontalDistance, int verticalDistance)
{
    if (root == NULL)
    {
        return;
    }

    // Save Node
    mapping[horizontalDistance][verticalDistance].push_back(root->data);

    // Traverse Left & Right
    saveByHorizontalVerticalDistance(root->left, mapping, horizontalDistance - 1, verticalDistance + 1);
    saveByHorizontalVerticalDistance(root->right, mapping, horizontalDistance + 1, verticalDistance + 1);
}

void verticalTraversal(Node *&root)
{
    // If Not jad then how ped :)
    if (root == NULL)
    {
        return;
    }

    // map< horizontalDistance, map< verticalDistance, vector<int> > > mapping;
    map<int, map<int, vector<int>>> mapping;
    int horizontalDistance = 0;
    int verticalDistance = 0;

    saveByHorizontalVerticalDistance(root, mapping, horizontalDistance, verticalDistance);

    for (auto i : mapping)
    {

        int horizontalDistance = i.first;
        map<int, vector<int>> verticalDistanceElementsMapping = i.second;

        cout << "For Horizontal Distance: " << horizontalDistance << " -> ";
        for (auto j : verticalDistanceElementsMapping)
        {

            int verticalDistance = j.first;
            vector<int> elements = j.second;

            for (auto k : elements)
            {
                cout << k << " ";
            }
        }

        cout << endl;
    }
}

void topViewOfTree(Node *&root)
{
    // If Not jad then how ped
    if (root == NULL)
    {
        return;
    }

    map<int, int> mapping;
    int horizontalDistance = 0;
    int verticalDistance = 0;

    // saveByHorizontalVerticalDistance(root,mapping,horizontalDistance,verticalDistance);

    queue<pair<Node *, pair<int, int>>> line;
    line.push(make_pair(root, make_pair(horizontalDistance, verticalDistance)));

    while (line.empty() == false)
    {
        pair<Node *, pair<int, int>> nodeWithCoordinates = line.front();
        line.pop();

        Node *element = nodeWithCoordinates.first;
        horizontalDistance = nodeWithCoordinates.second.first;
        verticalDistance = nodeWithCoordinates.second.second;

        // Update In Map if Not yet for this horizontal distance
        if (mapping.find(horizontalDistance) == mapping.end())
        {
            mapping[horizontalDistance] = element->data;
        }

        if (element->left != NULL)
        {
            line.push(make_pair(element->left, make_pair(horizontalDistance - 1, verticalDistance - 1)));
        }

        if (element->right != NULL)
        {
            line.push(make_pair(element->right, make_pair(horizontalDistance + 1, verticalDistance - 1)));
        }
    }

    for (auto i : mapping)
    {
        cout << i.second << " ";
    }
    cout << endl;
}

void bottomViewOfTree(Node *&root)
{
    // If Not jad then how ped
    if (root == NULL)
    {
        return;
    }

    map<int, int> mapping;
    int horizontalDistance = 0;
    int verticalDistance = 0;

    // saveByHorizontalVerticalDistance(root,mapping,horizontalDistance,verticalDistance);

    queue<pair<Node *, pair<int, int>>> line;
    line.push(make_pair(root, make_pair(horizontalDistance, verticalDistance)));

    while (line.empty() == false)
    {
        pair<Node *, pair<int, int>> nodeWithCoordinates = line.front();
        line.pop();

        Node *element = nodeWithCoordinates.first;
        horizontalDistance = nodeWithCoordinates.second.first;
        verticalDistance = nodeWithCoordinates.second.second;

        // Update In Map for this horizontal distance for every level as we have to view from bottom
        mapping[horizontalDistance] = element->data;

        if (element->left != NULL)
        {
            line.push(make_pair(element->left, make_pair(horizontalDistance - 1, verticalDistance - 1)));
        }

        if (element->right != NULL)
        {
            line.push(make_pair(element->right, make_pair(horizontalDistance + 1, verticalDistance - 1)));
        }
    }

    for (auto i : mapping)
    {
        cout << i.second << " ";
    }
    cout << endl;
}

void saveLeftViewOfTree(Node *&root, vector<int> &ans, int horizontalDistance, int verticalDistance)
{
    if (root == NULL)
    {
        return;
    }

    if (verticalDistance >= ans.size())
    {
        ans.push_back(root->data);
    }

    saveLeftViewOfTree(root->left, ans, horizontalDistance - 1, verticalDistance + 1);
    saveLeftViewOfTree(root->right, ans, horizontalDistance + 1, verticalDistance + 1);
}

void saveRightViewOfTree(Node *&root, vector<int> &ans, int horizontalDistance, int verticalDistance)
{
    if (root == NULL)
    {
        return;
    }

    if (verticalDistance >= ans.size())
    {
        ans.push_back(root->data);
    }

    saveRightViewOfTree(root->right, ans, horizontalDistance + 1, verticalDistance + 1);
    saveRightViewOfTree(root->left, ans, horizontalDistance - 1, verticalDistance + 1);
}

void leftViewOfTree(Node *&root)
{
    vector<int> leftView;
    saveLeftViewOfTree(root, leftView, 0, 0);

    for (auto i : leftView)
    {
        cout << i << " ";
    }
    cout << endl;
}

void rightViewOfTree(Node *&root)
{
    vector<int> rightView;
    saveRightViewOfTree(root, rightView, 0, 0);

    for (auto i : rightView)
    {
        cout << i << " ";
    }
    cout << endl;
}

void zigZagTraversalOfTree(Node *&root)
{
    // If not jad then how ped :)
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    vector<vector<int>> ans;
    int leftToRight = false;

    while (q.empty() == false)
    {
        int sizeOfLevel = q.size();
        vector<int> level(sizeOfLevel);
        leftToRight = !leftToRight;

        for (int i = 0; i < sizeOfLevel; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left != NULL)
            {
                q.push(temp->left);
            }

            if (temp->right != NULL)
            {
                q.push(temp->right);
            }

            int index = leftToRight == true ? i : sizeOfLevel - i - 1;
            level[index] = temp->data;
        }

        ans.push_back(level);
    }

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

// This is Mathematically Correct.
void diagonalTraversalOfTree(Node *&root)
{
    // If Not jad then how ped :)
    if (root == NULL)
    {
        return;
    }

    // map< horizontalDistance, map< verticalDistance, vector<int> > > mapping;
    map<int, map<int, vector<int>>> mapping;
    int horizontalDistance = 0;
    int verticalDistance = 0;

    saveByHorizontalVerticalDistance(root, mapping, horizontalDistance, verticalDistance);

    int height = heightOfTree(root);
    int start = 0;
    while (start < height)
    {
        horizontalDistance = start;
        verticalDistance = start;

        while (verticalDistance < height)
        {
            if (mapping[horizontalDistance][verticalDistance].size() > 0)
            {
                for (auto i : mapping[horizontalDistance][verticalDistance])
                {
                    cout << i << " ";
                }
            }

            horizontalDistance--;
            verticalDistance++;
        }

        cout << endl;
        start++;
    }

    cout << "____" << endl;

    start = 0;
    while (abs(start) < height)
    {
        horizontalDistance = start;
        verticalDistance = abs(start);

        while (verticalDistance < height)
        {
            if (mapping[horizontalDistance][verticalDistance].size() > 0)
            {
                for (auto i : mapping[horizontalDistance][verticalDistance])
                {
                    cout << i << " ";
                }
            }

            horizontalDistance++;
            verticalDistance++;
        }

        cout << endl;
        start--;
    }
}


// Test case passed correct 
void diagonalTraversalHelper(Node* &root, int diagonal, map<int, vector<int>> &ans) {
    // if not jad then how ped
    if (root == NULL)
    {
        return ;
    }
    
    ans[diagonal].push_back(root->data);

    diagonalTraversalHelper(root->left, diagonal+1, ans);
    diagonalTraversalHelper(root->right, diagonal, ans);
}

void diagonalTraversal(Node* &root) {
    // If not jad then how ped
    if (root == NULL)
    {
        return ;
    }
    
    map<int, vector<int>> ans;
    diagonalTraversalHelper(root, 0, ans);

    for(auto i : ans){
        for(auto j : i.second) {
            cout << j << " ";
        }
        cout << endl;
    }

}

int main()
{
    // Works But Better to provide NULL Pointer Explicitly
    // Node* ped = buildTree(ped, -1);

    // Test Input: 1 2 4 7 -1 -1 8 -1 -1 5 9 13 -1 -1 -1 10 -1 -1 3 -1 6 11 -1 -1 12 14 15 -1 -1 -1 -1
    Node *ped = NULL;
    ped = buildTree(ped);

    cout << endl
         << "Everything fine and Easy." << endl;

    cout << endl
         << "Now Level Order Traversal: " << endl;
    levelOrderTraversal(ped);

    cout << endl
         << "Now Vertical Traversal: " << endl;
    verticalTraversal(ped);

    cout << endl
         << "Now Top View: " << endl;
    topViewOfTree(ped);

    cout << endl
         << "Now Bottom View: " << endl;
    bottomViewOfTree(ped);

    cout << endl
         << "Now Zig Zag Traversal: " << endl;
    zigZagTraversalOfTree(ped);

    cout << endl
         << "Now Left View: " << endl;
    leftViewOfTree(ped);

    cout << endl
         << "Now Right View: " << endl;
    rightViewOfTree(ped);

    cout << endl
         << "Now Diagonal Traversal (Mathematically Correct): " << endl;
    diagonalTraversalOfTree(ped);

    cout << endl
         << "Now Diagonal Traversal (Test Cases Correct): " << endl;
    diagonalTraversal(ped);

    return 0;
}