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