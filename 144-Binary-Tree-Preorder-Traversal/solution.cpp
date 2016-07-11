/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 //stack
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        stack<TreeNode*> treeStack;

        while(1) {
            if(root != NULL) {
                ans.push_back(root->val);
                if(root->right != NULL) treeStack.push_back(root->right);
                root = root->left;
            } else {
                if(treeStack.size() == 0) break;
                else {
                    root = treeStack.top();
                    treeStack.pop();
                }
            }
        }
        return ans;
    }
};
/*
//recursive
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        myPreorderTraversal(root, ret);

        return ret;
    }
    void myPreorderTraversal(TreeNode *root, vector<int> &vec)
    {
        if (root == NULL)
            return;

        vec.push_back(root->val);

        myPreorderTraversal(root->left, vec);
        myPreorderTraversal(root->right, vec);
    }
};
