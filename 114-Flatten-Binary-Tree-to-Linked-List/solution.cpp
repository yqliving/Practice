/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) 
    {
        if(!root) return;
        flatten(root->left), flatten(root->right);
        if(!root->left) return;
        TreeNode * temp = root;
        while(temp -> left) temp = temp -> left;
        while(temp->right) temp = temp->right;
        temp -> right = root -> right;
        root -> right = root -> left;
        root -> left = NULL;
    }
};

/*
class Solution {
private:
    //let the prev pointer point to the traversal returned first node
    //our traversal order is : right -> left -> root
    //the prev will point to the last node visited after visiting left subtree and right subtree
    TreeNode* prev = nullptr;
public:
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};