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
    int minDepth(TreeNode* root) {
    if (!root)   return 0;
    if (!root -> left)
        return minDepth(root -> right) + 1;
    if (!root -> right)
        return minDepth(root -> left) + 1;
    /* if (root.left != null && root.right != null) */
    return min(minDepth(root -> left), minDepth(root -> right)) + 1;
    }
};
//1. DFS: Time ~ O(N), Space ~ O(logN) 
//注意minDepth与maxDepth的区别，当仅有一边子树为空时，minDepth是另一边子树的depth。