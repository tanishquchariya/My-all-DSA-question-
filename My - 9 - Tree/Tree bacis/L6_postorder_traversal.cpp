// C++ program to perform postorder traversal of a binary tree using recursion
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

// function of postorder traversal
void postorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    // Traverse the left subtree
    postorderTraversal(root->left);
    
    // Traverse the right subtree
    postorderTraversal(root->right);

    // Visit the root node
    cout << root->data << " ";

}

int main()
{
    node *root = NULL;
    // Call the function to build the binary tree
    // to direct put input in terminal just copy and right click in terminal: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);
    // Print the postorder traversal of the tree
    cout << "Postorder traversal: " << endl;
    postorderTraversal(root);
    cout << endl;

    return 0;
}