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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return Build(preorder, 0, inorder, 0);
    }
    TreeNode* Build(vector<int>& preorder, int i, vector<int>& inorder, int ii) {
        int j = preorder.size();
        int jj = inorder.size();
        if (i >= j || ii >= j) return NULL;
        
        int min = preorder[i];
        auto f = find(inorder.begin() + ii, inorder.begin + jj, mid);
        int dis = f - inorder.begin() - ii;
        TreeNode* root = new TreeNode(mid);
        root -> left = Build(preorder,i + 1,inorder,ii);
        root -> right = Build(preorder,i + 1 + dis,inorder,ii + dis + 1);
        return root;
        
        }
};
