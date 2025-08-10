// Maximum Depth of Binary Tree or height of Binary Tree


#include<bits/stdc++.h>
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

// approach - 1 : using BFS or level order traversal
// int maxDepthBFS(node* root) {
//     if (root == NULL) {
//         return 0;
//     }
//     queue<node*> q;
//     q.push(root);
//     int depth = 0;
//     while (!q.empty()) {
//         int n = q.size();
//         for (int i = 0; i < n; i++) {
//             node* temp = q.front();
//             q.pop();
//             if (temp->left) {
//                 q.push(temp->left);
//             }
//             if (temp->right) {
//                 q.push(temp->right);
//             }
//         }
//         depth++;
//     }
//     return depth;
// }

// Approach - 2 : using DFS or recursion
int maxDepthDFS(node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftDepth = maxDepthDFS(root->left);
    int rightDepth = maxDepthDFS(root->right);
    return 1 + max(leftDepth, rightDepth);
}
// // or
// int maxDepthDFS(node* root) {
//     if (root == NULL) {
//         return 0;
//     }
//     return 1 + max(maxDepthDFS(root->left), maxDepthDFS(root->right));
// }
// example usage
int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->right->right = new node(6);

    // int maxDepth = maxDepthBFS(root);
    // cout << "Maximum Depth (BFS): " << maxDepth << endl;

    int maxDepth = maxDepthDFS(root);
    cout << "Maximum Depth (DFS): " << maxDepth << endl;
    return 0;
}