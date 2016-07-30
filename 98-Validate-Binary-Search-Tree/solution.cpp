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
    bool isValidBST(TreeNode *root) {
        if (!root) return true;
        else return intheTree (root, LONG_MIN, LONG_MAX);
    }
    bool intheTree(TreeNode *node, long min, long max) {
        if (!node) return true;
        if (node -> val <= min || node -> val >= max) return false;
        else return intheTree(node -> left, min, node -> val) && intheTree (node -> right, node -> val, max);
    }

};
