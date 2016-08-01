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
    TreeNode* CreateSection(vector<int>& nums,int l,int r){
        if(l>r) return NULL;
        int c = (l+r+1)/2;
        TreeNode *root = new TreeNode(nums[c]);
        root->left = CreateSection(nums,l,c);
        root->right = CreateSection(nums,c+1,r);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return CreateSection(nums,0,nums.size()-1);
    }
};

