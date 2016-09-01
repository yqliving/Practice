class Solution {
    
public:
    vector<vector<int>> res;
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        Build(root,0);
        reverse(res.begin(),res.end());
        return res;
    }
    
    void Build(TreeNode* root,int layer){
        if(!root) return;
        if(layer>=res.size()) res.push_back(vector<int>());
        res[layer].push_back(root->val);
        Build(root->left,layer+1);
        Build(root->right,layer+1);
        return;
    }
};


/*class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> levels;
        if (root==NULL) return levels;

        queue<TreeNode *> q;
        q.push(root);q.push(NULL);

        vector<int> level;
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();

            if (node==NULL) // using NULL as delimiter for each level.
            {
                // NULL means done with one level
                levels.push_back(level);
                level.clear();
                if (!q.empty()) q.push(NULL);
            } else {
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        reverse(levels.begin(),levels.end());
        return levels;
    }
};