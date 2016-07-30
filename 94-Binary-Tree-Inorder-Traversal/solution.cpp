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
            left.push_back(right);
            //left.insert(left.end(), right.begin(), right.end());
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

/*Comparing with the preorder traversal, the difference is you can't just push the node of the value when popping it from the stack. You can do that only when 1) the node is visited the second time, implying that its left subtree has been processed, or 2) when the node has no left subtree.

Using a Hash to mark if the node is visited the first time making the solution straightforward. */
/*
   class Solution {
         public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> r;
            if (!root) return r;
            stack<TreeNode *> nodes;
            nodes.push(root);
            unordered_map<TreeNode* ,bool> visited;
            while(!nodes.empty()) {
                TreeNode *c = nodes.top();
                if (!visited[c] && (c->left)) {
                    nodes.push(c->left);
                    visited[c] = true;
                } else {
                    r.push_back(c->val);
                    nodes.pop();
                    if (c->right) {
                        nodes.push(c->right);
                    }
                }
            }
            
            return r;
        }
    };