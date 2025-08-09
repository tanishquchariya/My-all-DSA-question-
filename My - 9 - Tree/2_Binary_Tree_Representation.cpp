#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    // Constructor to initialize a node with a value
    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};
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
void buildFromLevelOrder(node* &root) {
    queue<node*> q;

    cout << "Enter data for root" << endl;
    int data ;
    cin >> data;
    root = new node(data);
    
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
 }

// usage example
int main() {
    node *root = NULL; // Initialize the root of the tree
    buildFromLevelOrder(root); // Build the tree from level order input
    levelOrderTraversal(root); // Print the tree in level order
    

    // Example of how to use the tree (e.g., print, traverse, etc.)
    // 1 3 5 7 11 7 -1 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Tree built successfully." << endl;

    return 0;
}   