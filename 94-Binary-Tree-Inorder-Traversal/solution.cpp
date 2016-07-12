/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//recursive
class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            if(!root) {
                vector<int> result;
                return result;
            }
            vector<int> left = inorderTraversal(root->left);
            left.push_back(root->val);
            vector<int> right = inorderTraversal(root->right);
            
            left.insert(left.end(), right.begin(), right.end());
            return left;
        }
    };
    
  
//stack
/*
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

//stack, 先排左子树，然后反过来输出，在看右子树
//中序遍历，顺时针