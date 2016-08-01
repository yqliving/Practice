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
    bool isBalanced(TreeNode* root) {
        return maxDepthLR(root) != -1;
}

private: int maxDepthLR(TreeNode* root) {
    if (root == NULL) return 0;
    int L = maxDepthLR(root->left);
    if (L == -1) return -1;
    int R = maxDepthLR(root->right);
    if (R == -1) return -1;
    return (abs(L - R) <= 1) ? max(L, R) + 1 : -1;
}
};
//Bottom-up recursion: Time ~ O(N) 
//仍然计算每个node到底部的maxDepth，但当左右子树的maxDepth相差超过1，则返回 -1（unbalanced），这样可迅速结束递归。