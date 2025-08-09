// code is a complete program for creating a binary tree from user input using a recursive builder 
// and displaying its structure in a level-by-level format using a queue.
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
    // Base case: if the input is -1, return NULL
    if (data == -1) {
        return NULL;
    }
    root = new node(data); // call the constructor to create a new node with the input data
    
    // Recursively build the left and right subtrees
    cout << "Enter left child of " << data << ": "<< endl;
    root->left = buildTree(root->left);

    cout << "Enter right child of " << data << ": "<< endl;
    root->right = buildTree(root->right);

    return root;
}

// function of level order traversal which is used to print the tree
void levelOrderTraversal(node* root) {
    if (root == NULL) {
        return;
    }

    queue<node*> q;
    q.push(root);
    q.push(NULL); // Push NULL to indicate the end of the current level

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();


        if (temp == NULL) {
            cout<<endl;
            if(!q.empty()) {
                q.push(NULL); // Push NULL to indicate the end of the current level
            }
        } else {
            cout << temp->data << " ";
            if (temp->left != NULL) {
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                q.push(temp->right);
            }
        }
    }
}

int main(){
    node* root = NULL;
    // Call the function to build the binary tree
    // to direct put input in terminal just copy and right click in terminal: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    // Print the level order traversal of the tree
    cout << "Level order traversal: "<< endl;
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}