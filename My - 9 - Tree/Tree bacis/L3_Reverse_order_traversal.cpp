// The key change is to use both a queue and a stack. The queue is used to process the nodes from top to bottom (standard level order), 
// and the stack is used to store them. Because a stack follows a Last-In, First-Out (LIFO) principle,
// the nodes from the lowest levels will be at the top of the stack,
// and when you pop and print them, they will come out in reverse level order.
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
void reverseLevelOrderTraversal(node* root) {
    if (root == NULL) {
        return;
    }

    queue<node*> q;
    stack<node*> s;
    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        s.push(temp);

        // Push right child first so that left child is processed first
        if (temp->right != NULL) {
            q.push(temp->right);
        }
        if (temp->left != NULL) {
            q.push(temp->left);
        }
    }

    // Print nodes in reverse order
    while (!s.empty()) {
        node* temp = s.top();
        s.pop();
        cout << temp->data << " ";
    }
    cout << endl;
}

int main(){
    node* root = NULL;
    // Call the function to build the binary tree
    // to direct put input in terminal just copy and right click in terminal: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    // Print the reverse level order traversal of the tree
    cout << "Reverse Level order traversal: "<< endl;
    reverseLevelOrderTraversal(root);
    cout << endl;

    return 0;
}