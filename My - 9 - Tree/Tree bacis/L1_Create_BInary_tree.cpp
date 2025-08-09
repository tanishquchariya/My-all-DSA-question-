// function to create a binary tree 

#include <bits/stdc++.h>
using namespace std;

class node { 
    public:
    int data;
    node* left;
    node* right;

    // Constructor to initialize a node with a value
    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

    // or
    // node(int val) {
    //     data = val;
    //     left = NULL;
    //     right = NULL;
    // }
};

// Function to create a binary tree
node* buildTree(node* root) {
    cout << "Enter data (-1 for no node): ";
    int data;
    cin >> data;  
    // call the constructor to create a new node with the input data  
    root = new node(data);

    // Base case: if the input is -1, return NULL
    if (data == -1) {
        return NULL;
    }
    
    // Recursively build the left and right subtrees
    cout << "Enter left child of " << data << ": "<< endl;
    // root = new node(data); // Create a new node with the input data
    root->left = buildTree(root->left);

    cout << "Enter right child of " << data << ": "<< endl;
    root->right = buildTree(root->right);

    return root;
}


int main(){
    node* root = NULL;
    // Call the function to build the binary tree
    root = buildTree(root);
    return 0;
}