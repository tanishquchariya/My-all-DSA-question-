// Introduction to Trees
// Function to count node at given level

#include <bits/stdc++.h>
#include <cmath>
using namespace std;


class node{
    public:
        int data;
        node *left;
        node *right;

        // Constructor to initialize a node with a value
        node(int d) {
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};

// // Approach - 1: brute force using level order traversal.
// // time complexity: O(n) ans space complexity: O(h) where h is height of tree

// int countNodesAtLevel(int i) {
//     if (i == 0) {
//         return 0;
//     }
//     int val = 1;
//     for (int j = 1; j < i; j++) {
//         val *= 2;   
//     }
//     // Count nodes in left and right subtrees at the given level
//     return val;
// }

// // Approach - 2: using recursion
// // time complexity: O(n) ans space complexity: O(h) where h is height of tree
// int countNodesAtLevelRec(node* root, int level) {
//     if (root == NULL) {
//         return 0;
//     }
//     if (level == 1) {
//         return 1; // Count this node
//     }
//     // Recur for left and right subtrees
//     return countNodesAtLevelRec(root->left, level - 1) + countNodesAtLevelRec(root->right, level - 1);
// }

// Approach - 3: using built-in function pow() or optimized formula
// time complexity: O(log n) ans space complexity: O(1) 
int countNodesAtLevel(int level) {
    // Calculate the number of nodes at the given level using power of 2
    return pow(2, level - 1);
}

// usage example
int main() {
    int level;
    cout << "Enter the level to count nodes: ";
    cin >> level;

    // Call the function and print the result
    int count = countNodesAtLevel(level);
    cout << "Number of nodes at level " << level << ": " << count << endl;

    return 0;
}   