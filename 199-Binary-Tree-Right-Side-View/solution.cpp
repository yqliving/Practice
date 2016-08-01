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
    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        if(res.size()<level) res.push_back(root->val);
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);
    }
    
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 1, res);
        return res;
    }
};

/*
class Solution {
public:
    
    vector<int> rightSideView(TreeNode* root) {
    vector<int> V;
    queue<TreeNode*> Q;
    if (root!=NULL) Q.push(root);
    while (!Q.empty()) {
        int k = Q.size();
        for (int i=0; i<k; i++) {
            TreeNode* rt = Q.front();
            if (i==0) V.push_back(rt->val);
            if (rt->right)Q.push(rt->right);
            if (rt->left) Q.push(rt->left);
            Q.pop();
        }
    }
    return V;
    }
} ;

//BST, every time put the right branch first in Q, and get Q.front