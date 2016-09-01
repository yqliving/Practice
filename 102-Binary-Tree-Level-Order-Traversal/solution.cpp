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
    vector<vector<int>> res;
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        Build(root,0);
        return res;
    }
    
    void Build(TreeNode* root,int layer){
        if(!root) return;
        if(layer==res.size()) res.push_back(vector<int>{root->val});
        else res[layer].push_back(root->val);
        Build(root->left,layer+1);
        Build(root->right,layer+1);
        return;
    }
};


/*
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> levels;
        if(!root) return levels;
        queue<TreeNode*> visit;
        visit.push (root);
        int numlevelNodes = 1;
        while (!visit.empty()) {
            vector<int> level;
            for (int i=0; i<numlevelNodes; i++) {
                TreeNode* node = visit.front();
                visit.pop();
                level.push_back(node->val);
                if (node -> left) visit.push (node -> left);
                if (node -> right) visit.push (node -> right);
            }
            levels.push_back (level);
            numlevelNodes = visit.size();
        }
        
        return levels;
    }
};

