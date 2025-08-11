// 110. Balanced Binary Tree
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    // Constructor to initialize a node with a value
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Approach - 1 : using DFS or recursion
// time complexity : O(N^2)
// space complexity : O(H)

// int getHeight(node *root)
// {
//     if (root == NULL)
//     {
//         return true;
//     }
//     int leftHeight = getHeight(root->left);
//     int rightHeight = getHeight(root->right);
//     return 1 + max(leftHeight, rightHeight);
// }
// bool isBalancedDFS(node *root)

// {
//     if (root == NULL)
//     {
//         return true;
//     }

//     // or
//     int leftHeight = isBalancedDFS(root->left);
//     int rightHeight = isBalancedDFS(root->right);
//     bool diff = abs(getHeight(root->left) - getHeight(root->right)) <= 1;
//     if (leftHeight && rightHeight && diff)
//         return true;
//     else
//     {

//         return false;
//     }
// }



// // Approach - 2 : using BFS 
// // time complexity : O(N^2)
// // space complexity : O(N)

// int getHeight(node *root)
// {
//     if (root == NULL)
//     {
//         return true;
//     }
//     int leftHeight = getHeight(root->left);
//     int rightHeight = getHeight(root->right);
//     return 1 + max(leftHeight, rightHeight);
// }
// bool isBalancedBFS(node *root)
// {
//     if (root == NULL)
//     {
//         return true;
//     }
//     queue<node *> q;
//     q.push(root);
//     while (!q.empty())
//     {
//         node *temp = q.front();
//         q.pop();
//         int leftHeight = getHeight(temp->left);
//         int rightHeight = getHeight(temp->right);
//         if (abs(leftHeight - rightHeight) > 1)
//         {
//             return false;
//         }
//         if (temp->left)
//         {
//             q.push(temp->left);
//         }
//         if (temp->right)
//         {
//             q.push(temp->right);
//         }
//     }
//     return true;
// }

// Approach - 3 : using height
// time complexity : O(N)
// space complexity : O(H)

int checkHeight(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = checkHeight(root->left);
    if(leftHeight == -1) return -1; // Left subtree is not balanced
    int rightHeight = checkHeight(root->right);
    if(rightHeight == -1) return -1; // Right subtree is not balanced
    if (abs(leftHeight - rightHeight) > 1)
    {
        return -1;
    }
    return 1 + max(leftHeight, rightHeight);
}
bool isBalanced(node *root)
{
    return checkHeight(root) != -1;
}

// Example usage
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);

    // bool balancedDFS = isBalancedDFS(root);
    // cout << "Is Balanced (DFS): " << (balancedDFS ? "Yes" : "No") << endl;
    
    // bool balancedBFS = isBalancedBFS(root);
    // cout << "Is Balanced (BFS): " << (balancedBFS ? "Yes" : "No") << endl;

    bool balanced = isBalanced(root);
    cout << "Is Balanced: " << (balanced ? "Yes" : "No") << endl;

    return 0;
}