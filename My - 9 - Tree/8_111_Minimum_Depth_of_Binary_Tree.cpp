// Minimum Depth of Binary Tree or height of Binary Tree

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

// // approach - 1 : using BFS or level order traversal
// time complexity : O(N)
// space complexity : O(N)
// int minDepthBFS(node *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }
//     queue<node *> q;
//     q.push(root);
//     int depth = 1;
//     while (!q.empty())
//     {
//         int n = q.size();
//         for (int i = 0; i < n; i++)
//         {
//             node *temp = q.front();
//             q.pop();
//             // If we reach a leaf node, return the current depth
//             if (temp->left == NULL && temp->right == NULL)
//             {
//                 return depth;
//             }

//             if (temp->left)
//             {
//                 q.push(temp->left);
//             }
//             if (temp->right)
//             {
//                 q.push(temp->right);
//             }
//         }
//         depth++;
//     }
//     return -1;
// }

    
    // // Approach - 2 : using DFS or recursion
    // time complexity : O(N)
    // space complexity : O(H)
    int minDepthDFS(node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        if(root->left == NULL && root->right == NULL) {
            return 1; // Leaf node
        }
        int L = root->left ? minDepthDFS(root->left) : INT_MAX;
        int R = root->right ? minDepthDFS(root->right) : INT_MAX;
        return 1 + min(L, R);
    }

    // example usage
    int main()
    {
        node *root = new node(1);
        root->left = new node(2);
        root->right = new node(3);
        root->right->right = new node(6);

        // int minDepth = minDepthBFS(root);
        // cout << "Minimum Depth (BFS): " << minDepth << endl;

        int maxDepth = minDepthDFS(root);
        cout << "Maximum Depth (DFS): " << maxDepth << endl;
        return 0;
    }