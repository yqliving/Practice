/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 //stack
/*class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        stack<TreeNode*> treeStack;

        while(1) {
            if(root != NULL) {
                ans.push_back(root->val);
                if(root->right != NULL) treeStack.push(root->right);
                root = root->left;
            } else {
                if(treeStack.size() == 0) break;
                else {
                    root = treeStack.top();
                    treeStack.pop();
                }
            }
        }
        return ans;
    }
};*/
//stack<TreeNode*> push
//vector<TreeNode*> push_back
/*向量容器(vector)是一种顺序容器，是一块连续分配的内存，支持随机访问，从数据安排的角度看，和数组极其相似，数组跟vector的区别在于：数组是静态分配空间，一旦分配了空间的大小，就不可以再改变了，例如,int a[6];而vector是动态分配内存，随着元素的不断插入，它会按照自身的一套机制不断扩充自身的容量，vector容器的容量增长是按照容器现在容量的一倍进行增长。

begin() end() 返回vector头 尾 元素对应的地址
front() back() 返回vector头 尾 元素*/



//recursive
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        myPreorderTraversal(root, ret);

        return ret;
    }
    void myPreorderTraversal(TreeNode *root, vector<int> &vec)
    {
        if (root == NULL)
            return;

        vec.push_back(root->val);

        myPreorderTraversal(root->left, vec);
        myPreorderTraversal(root->right, vec);
    }
};
