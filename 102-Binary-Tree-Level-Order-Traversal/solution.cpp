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
    vector<vector<int>> ret;

void buildVector(TreeNode *root, int depth)
{
    if(root == NULL) return;
    if(ret.size() == depth)
        ret.push_back(vector<int>());
    
    ret[depth].push_back(root->val);
    buildVector(root->left, depth + 1);
    buildVector(root->right, depth + 1);
}

vector<vector<int> > levelOrder(TreeNode *root) {
    buildVector(root, 0);
    return ret;
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

