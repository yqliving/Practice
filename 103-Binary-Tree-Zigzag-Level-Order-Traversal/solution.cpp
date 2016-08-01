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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        traverse(root, 0, res);
        return rst;
    }
    
void traverse(TreeNode* root, int depth, vector<vector<int>> & res) {
    if (!root)
        return;
    if (res.size() == depth) {
        vector<int> temp;
        res.push_back(temp);
    }
    if (depth % 2 == 0)   
        res[depth].push_back(root ->val);
    else{
        res[depth].insert(res[depth].begin(), root -> val);    // two situation
    }
    traverse(root -> left, depth + 1, res);  
    traverse(root -> right, depth + 1, res);
}
};