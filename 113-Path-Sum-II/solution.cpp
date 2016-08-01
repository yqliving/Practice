/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        int psum = 0;
        vector<TreeNode*> path;
        vector<vector<int>> result;
        
        if (!root) return result;
        
        psum += root->val;
        path.push_back(root);
        
        TreeNode* cur;
        TreeNode* pop = root;
        
        while(!path.empty()) {
            cur = path.back();
            if (psum == sum && cur->left == NULL && cur->right == NULL) {
                vector<int> pathResult;
                for(int i = 0; i < path.size(); i++) {
                    pathResult.push_back(path[i]->val);
                }
                result.push_back(pathResult);
                
            }
            
            if ((cur->left == NULL && cur->right == NULL) || (cur->right == pop) || (cur->left == pop && cur->right == NULL)) {
                pop = cur;
                psum -= cur->val;
                path.pop_back();
            }
            
            else if (cur->left == NULL || cur->left == pop) {
                cur = cur->right;
                path.push_back(cur);
                psum += cur->val;
            }
            
            else {
                cur = cur->left;
                path.push_back(cur);
                psum += cur->val;
            }
            
        }
        
        return result;
    }
};*/

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > paths;
        vector<int> path;
        findPaths(root, sum, path, paths);
        return paths;  
    }
private:
    void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths) {
        if (!node) return;
        path.push_back(node -> val);
        if (node -> left == NULL && node -> right == NULL && sum == node -> val)
            paths.push_back(path);
        findPaths(node -> left, sum - node -> val, path, paths);
        findPaths(node -> right, sum - node -> val, path, paths);
        path.pop_back();
    }
};

