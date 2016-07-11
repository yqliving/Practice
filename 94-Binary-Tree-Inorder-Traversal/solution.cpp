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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL) return result;
        
        vector<TreeNode*> nodeStack;
        TreeNode* node = root;
        nodeStack.push_back(node);
        node = node->left;
        
        while (!nodeStack.empty() || node != NULL) {
            //walk through left child node at first
            if (node != NULL) {
                nodeStack.push_back(node);
                node = node->left;
            } 
            //if there is no left child anymore, pop up current top node and add it to result
            else {
                node = nodeStack.back();
                nodeStack.pop_back();
                result.push_back(node->val);
                node = node->right;
            }
        }
        return result;
    }
};

//stack
//中序遍历，顺时针