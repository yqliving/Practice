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
    int rob(TreeNode* root) {
        int l, r;
        return tryRob (root, l, r);
    }
    
        int tryRob(TreeNode* root, int & l, int & r) {
            if (!root) return 0;
            
            int ll = lr = rl = rr = 0;
            l = tryRob(root -> left, ll, lr);
            r = tryRob(root -> right, rl, rr);
            
            return max(root->val + ll + lr + rl + rr, l + r);
        }
    }
};




/*
map

/*Let

f1(node) be the value of maximum money we can rob from the subtree with node as root ( we can rob node if necessary).

f2(node) be the value of maximum money we can rob from the subtree with node as root but without robbing node.

Then we have

f2(node) = f1(node.left) + f1(node.right) and

f1(node) = max( f2(node.left)+f2(node.right)+node.value, f2(node) ).

*/
/*
class Solution {
public:
    int rob(TreeNode* root) {
        return robDFS(root).second;
    }
    pair<int, int> robDFS(TreeNode* node){
        if( !node) return make_pair(0,0);
        auto l = robDFS(node->left);
        auto r = robDFS(node->right);
        int f2 = l.second + r.second;
        int f1 = max(f2, l.first + r.first + node->val);
        return make_pair(f2, f1);
    }
};