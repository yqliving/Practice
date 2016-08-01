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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    return left == NULL ? right : (right == NULL ? left : root);
    
    }
};

/*  if the tree is a standard tree  val: (root.left<root<root.right)

    if      (root.val < p.val && root.val < q.val)  return lowestCommonAncestor(root.right, p, q);
    else if (root.val > p.val && root.val > q.val)  return lowestCommonAncestor(root.left, p, q);
    else                                            return root;