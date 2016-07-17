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
    int preS = 0; // global varible to indicate the preorder array index
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = inorder.size();

        unordered_map<int, int> in_map;// use hashmap to improve search speed
        for (int i = 0; i < n; ++i) {
            in_map[inorder[i]] = i;
        }

        return helper(0, inorder.size()-1, preorder, in_map);
    }

    TreeNode* helper(int inStart, int inEnd,vector<int> &pre, unordered_map<int,int>& in_map) {

        if(inStart > inEnd) // case to return 
            return NULL;
        TreeNode* root = new TreeNode(pre[preS]);
        int inMid = in_map[pre[preS]];
        preS++; // preoder traveral 
        root->left = helper(inStart, inMid -1,pre, in_map);
        root->right = helper(inMid +1, inEnd,pre, in_map);
        return root;
    }
};
/*
class Solution {

public:
    /* from Preorder and Inorder Traversal */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        return helper(preorder,0,preorder.size(),inorder,0,inorder.size());
    
    }

    TreeNode* helper(vector<int>& preorder,int i,int j,vector<int>& inorder,int ii,int jj)
    {
        // tree        8 4 5 3 7 3
        // preorder    8 [4 3 3 7] [5]
        // inorder     [3 3 4 7] 8 [5]

        // 每次从 preorder 头部取一个值 mid，作为树的根节点
        // 检查 mid 在 inorder 中 的位置，则 mid 前面部分将作为 树的左子树，右部分作为树的右子树

        if(i >= j || ii >= j)
            return NULL;

        int mid = preorder[i];
        auto f = find(inorder.begin() + ii,inorder.begin() + jj,mid);

        int dis = f - inorder.begin() - ii;

        TreeNode* root = new TreeNode(mid);
        root -> left = helper(preorder,i + 1,i + 1 + dis,inorder,ii,ii + dis);
        root -> right = helper(preorder,i + 1 + dis,j,inorder,ii + dis + 1,jj);
        return root;
    }
};