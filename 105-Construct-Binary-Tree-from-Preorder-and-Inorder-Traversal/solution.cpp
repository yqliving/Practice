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
    int preS = 0; // global varible to indicate the preorder array index
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = inorder.size();

        unordered_map<int, int> in_map;// use hashmap to improve search speed
        for (int i = 0; i < n; ++i) {
            in_map[inorder[i]] = i;
        }

        return helper(0, inorder.size()-1, preorder, in_map);
    }

    TreeNode* helper(int inStart, int inEnd,vector<int> &pre, unordered_map<int,int>& in_map) {

        if(inStart > inEnd) // case to return 
            return NULL;
        TreeNode* root = new TreeNode(pre[preS]);
        int inMid = in_map[pre[preS]];
        preS++; // preoder traveral 
        root->left = helper(inStart, inMid -1,pre, in_map);
        root->right = helper(inMid +1, inEnd,pre, in_map);
        return root;
    }
};
/*
