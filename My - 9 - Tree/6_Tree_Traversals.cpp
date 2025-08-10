//Tree Traversals of inorder , perorder and postorder
#include <bits/stdc++.h>    
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    // Constructor to initialize a node with a value
    TreeNode(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Tree Traversals of inorder , perorder and postorder
// time complexity : O(n) and space complexity : O(h)
void inorder(TreeNode* root, vector<int>&ans){
    if(root == NULL){
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
void preorder(TreeNode* root, vector<int>&ans){
     if(root == NULL){
        return;
    }
    ans.push_back(root->data);
    preorder(root->left,ans);
    preorder(root->right,ans);
}
void postorder(TreeNode* root, vector<int>&ans){
     if(root == NULL){
        return;
    }
    postorder(root->left,ans);
    postorder(root->right,ans);
    ans.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    
    vector<vector<int>> Allans;

    vector<int>inorderAns;
    inorder(root,inorderAns);
    Allans.push_back(inorderAns);
    
    vector<int>preorderAns;
    preorder(root, preorderAns);
    Allans.push_back(preorderAns);


    vector<int>postorderAns;
    postorder(root,postorderAns);
    Allans.push_back(postorderAns);

    return Allans;
    
}

// example usage
// Sample Input 1 :
// 1 2 3 -1 -1 -1  6 -1 -1
// Sample Output 1 :
// 2 1 3 6 
// 1 2 3 6 
// 2 6 3 1

int main (){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(6);

    vector<vector<int>> ans = getTreeTraversal(root);
    for (const auto& vec : ans) {
        for (int val : vec) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}