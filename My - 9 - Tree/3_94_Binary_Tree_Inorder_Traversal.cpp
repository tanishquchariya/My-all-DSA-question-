// C++ program to perform inorder traversal of a binary tree using recursion
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
// // function of inorder traversal
// void inorderTraversal(node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     // Traverse the left subtree
//     inorderTraversal(root->left);

//     // Visit the root node
//     cout << root->data << " ";

//     // Traverse the right subtree
//     inorderTraversal(root->right);
// }

// approach - 2: using iteration method using stack
// time complexity: O(n) ans space complexity: O(h) where h is height of

// void inorderTraversal(node *root)
// {
//     stack<node *> s;
//     node *curr = root;

//     while (curr != NULL || !s.empty())
//     {
//         // Reach the leftmost node of the current node
//         while (curr != NULL)
//         {
//             s.push(curr);
//             curr = curr->left;
//         }

//         // Current must be NULL at this point
//         curr = s.top();
//         s.pop();

//         cout << curr->data << " ";

//         // Visit the right subtree
//         curr = curr->right;
//     }
// }


// Approach - 3: using Morris Traversal
// time complexity: O(n) ans space complexity: O(1)

void inorderTraversal(node *root)
{
    node *curr = root;
    while (curr != NULL)
    {
        // If the left child is NULL, print the current node and move to the right child
        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            // Find the inorder predecessor of the current node
            node *pre = curr->left;
            while (pre->right != NULL)
            {
                pre = pre->right;
            }

            pre->right = curr;

            // curr->left = NULL; // Set the left child to NULL to avoid cycles
            node *temp = curr;
            curr = curr->left;
            temp->left = NULL; // Set the left child to NULL to avoid cycles
        }
    }
}
int main()
{
    node *root = NULL;
    // Call the function to build the binary tree
    // to direct put input in terminal just copy and right click in terminal: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);
    // Print the inorder traversal of the tree
    cout << "Inorder traversal: " << endl;
    inorderTraversal(root);
    cout << endl;

    return 0;
}