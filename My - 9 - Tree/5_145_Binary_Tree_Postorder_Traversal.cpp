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
// function of postorder traversal
// void postorderTraversal(node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     // Traverse the left subtree
//     postorderTraversal(root->left);

//     // Traverse the right subtree
//     postorderTraversal(root->right);

//     // Visit the root node
//     cout << root->data << " ";
// }

// Approach - 2: using iterative method with two stacks
// time complexity: O(n) ans space complexity: O(n)
// void postorderTraversal(node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     stack<node *> s1, s2;
//     s1.push(root);

//     while (!s1.empty())
//     {
//         node *curr = s1.top();
//         s1.pop();
//         s2.push(curr);

//         // Push left and right children to the first stack
//         if (curr->left != NULL)
//         {
//             s1.push(curr->left);
//         }
//         if (curr->right != NULL)
//         {
//             s1.push(curr->right);
//         }
//     }

//     // Print the nodes in postorder
//     while (!s2.empty())
//     {
//         node *curr2 = s2.top();
//         cout << curr2->data << " ";
//         s2.pop();
//     }
// }

// Approach - 3: using 1 stack with a pointer to track the last visited node
// time complexity: O(n) ans space complexity: O(h)
// void postorderTraversal(node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     stack<node *> s;
//     node *curr = root;
//     node *lastVisited = NULL;

//     while (!s.empty() || curr != NULL)
//     {
//         // Reach the leftmost node
//         while (curr != NULL)
//         {
//             s.push(curr);
//             curr = curr->left;
//         }

//         // Peek the top node
//         node *topNode = s.top();

//         // If the right child is NULL or already visited, visit the top node
//         if (topNode->right == NULL || topNode->right == lastVisited)
//         {
//             cout << topNode->data << " ";
//             lastVisited = topNode;
//             s.pop();
//         }
//         else
//         {
//             // Move to the right child
//             curr = topNode->right;
//         }
//     }
// }

// Approach - 4: using Morris Traversal
// time complexity: O(n) ans space complexity: O(1)
void postorderTraversal(node *root)
{
    node *dummy = new node(0); // Create a dummy node to handle the root
    dummy->left = root;
    node *curr = dummy;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            curr = curr->right;
        }
        else
        {
            node *pre = curr->left;
            while (pre->right != NULL && pre->right != curr)
            {
                pre = pre->right;
            }

            if (pre->right == NULL)
            {
                pre->right = curr; // Create a temporary link
                curr = curr->left; // Move to the left child
            }
            else
            {
                // Print the rightmost path in reverse order
                node *temp = curr->left;
                stack<int> s;
                while (temp != curr)
                {
                    s.push(temp->data);
                    temp = temp->right;
                }
                while (!s.empty())
                {
                    cout << s.top() << " ";
                    s.pop();
                }
                pre->right = NULL; // Remove the temporary link
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
    // Print the postorder traversal of the tree
    cout << "Postorder traversal: " << endl;
    postorderTraversal(root);
    cout << endl;

    return 0;
}