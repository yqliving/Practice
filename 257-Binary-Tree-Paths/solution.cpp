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
    vector<string> answer;
    
    vector<string> binaryTreePaths(TreeNode* root) {
    if (root != NULL) searchBT(root, "");
    return answer;
    }
    
private: 
    void searchBT(TreeNode* root, string path) {
    if (root->left == NULL && root->right == NULL) answer.push_back(path + to_string(root->val));
    if (root->left != NULL) searchBT(root->left, path + to_string(root->val) + "->");
    if (root->right != NULL) searchBT(root->right, path + to_string(root->val) + "->");
}
};
/*
class Solution {
public:
    void binaryTreePaths(vector<string>& result, TreeNode* root, string t) {
    if(!root->left && !root->right) {
        result.push_back(t);
        return;
    }

    if(root->left) binaryTreePaths(result, root->left, t + "->" + to_string(root->left->val));
    if(root->right) binaryTreePaths(result, root->right, t + "->" + to_string(root->right->val));
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    if(!root) return result;
    
    binaryTreePaths(result, root, to_string(root->val));
    return result;
}
};