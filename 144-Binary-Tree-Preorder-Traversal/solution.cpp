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
                node = nodeStack.front();
                nodeStack.pop_back();
                result.push_back(node->val);
                node = node->right;
            }
        }
        return result;
    }
};
 //stack
 /*
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        if(root == NULL) return ans;
        stack<TreeNode*> treeStack;

        while(1) {
            if(root != NULL) {
                ans.push_back(root->val);
                if(root->right != NULL) treeStack.push(root->right);
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
