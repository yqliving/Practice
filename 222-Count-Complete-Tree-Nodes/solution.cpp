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
    int countNodes(TreeNode* root) 
    {
        if(!root) return 0;
        int height = 0, sum = 0, i = 0;
        TreeNode *t = root, *t0 = NULL;
        while(t) t = t->left, height++; //get the height of the tree;
        t = root;
        int level = height - 2; //levels under the child of root;
        while(level > -1) //collect the bottom-level nodes by halving them apart;
        {
            t0 = t->left;
            for(i = 0; i < level; ++i) t0 = t0->right; 
            if(t0) { sum += 1<<level; t = t->right; } //rightmost node is not null;
            else t = t->left;
            level--; //move to the next level;
        }
        if(t) sum++; //if it's a complete tree, collect the last right node;
        return sum+((1<<(height-1))-1);
    }  
};

/*
//300ms 超级慢
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)  return 0;
        int hl=0, hr=0;
        TreeNode *l=root, *r=root;
        while(l) { hl++; l=l->left; }
        while(r) { hr++; r=r->right; }
        
        if(hl==hr) return pow(2, hl)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
/* 
