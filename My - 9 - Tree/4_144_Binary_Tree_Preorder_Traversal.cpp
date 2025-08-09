// C++ program to perform preorder traversal of a binary tree using recursion
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

// Function to create a binary tree
node *buildTree(node *root)
{
    cout << "Enter data (-1 for no node): ";
    int data;
    cin >> data;
    // Base case: if the input is -1, return NULL
    if (data == -1)
    {
        return NULL;
    }
    root = new node(data); // call the constructor to create a new node with the input data

    // Recursively build the left and right subtrees
    cout << "Enter left child of " << data << ": " << endl;
    root->left = buildTree(root->left);

    cout << "Enter right child of " << data << ": " << endl;
    root->right = buildTree(root->right);

    return root;
}

// approach - 1: using recursion
// time complexity: O(n) ans space complexity: O(h) where h is height of
// function of preorder traversal
// void preorderTraversal(node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     // Visit the root node
//     cout << root->data << " ";

//     // Traverse the left subtree
//     preorderTraversal(root->left);

//     // Traverse the right subtree
//     preorderTraversal(root->right);
// }

// approach - 2: using iteration method using stack
// time complexity: O(n) ans space complexity: O(h) where h is height of

// void preorderTraversal(node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     stack<node *> s;
//     s.push(root);

//     while (!s.empty())
//     {
//         node *curr = s.top();
//         s.pop();

//         cout << curr->data << " ";

//         // Push the right child first so that the left child is processed first
//         if (curr->right != NULL)
//         {
//             s.push(curr->right);
//         }
//         if (curr->left != NULL)
//         {
//             s.push(curr->left);
//         }
//     }
// }

// Approach - 3: using Morris Traversal
// time complexity: O(n) ans space complexity: O(1)
void preorderTraversal(node *root)
{
    node *curr = root;
    while (curr != NULL)
    {
        // If the left child is NULL, visit the current node and move to the right child
        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            // Find the inorder predecessor of the current node
            node *leftchild = curr->left;
            while (leftchild->right != NULL && leftchild->right != curr)
            {
                leftchild = leftchild->right;
            }

            // Make a temporary link to the current node
            if (leftchild->right == NULL)
            {
                leftchild->right = curr;
                cout << curr->data << " "; // Visit the current node
                curr = curr->left;         // Move to the left child
            }
            else
            {
                leftchild->right = NULL; // Remove the temporary link
                curr = curr->right; // Move to the right child
            }
        }
    }
}
int main()
{
    node *root = NULL;
    // Call the function to build the binary tree
    // to direct put input in terminal just copy and right click in terminal: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);
    // Print the preorder traversal of the tree
    cout << "Preorder traversal: " << endl;
    preorderTraversal(root);
    cout << endl;

    return 0;
}