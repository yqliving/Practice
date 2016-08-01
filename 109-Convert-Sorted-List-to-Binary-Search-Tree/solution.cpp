/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        ListNode* current = head;
        while (current) {
            len ++;
            current = current->next;
        }
        return sortedList(&head, 0, len);
    }
    
    private:
    TreeNode* sortedList(ListNode** head, int start, int end) {
        if (start == end) return NULL;
        if (head == NULL) return NULL;
        TreeNode* root = new TreeNode(0);
        int mid = start + (end - start) / 2;
        root->left = sortedList(head, start, mid);
        root->val = (*head)->val;
        *head = (*head)->next;
        root->right = sortedList(head, mid + 1, end);
        return root;
    }
};

//将数组逐次二分 midpoint就是当前的根 然后左边的数组就是左子树 右边的数组就是右子树


/*class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head,nullptr);
    }
    TreeNode* buildTree(ListNode* head, ListNode* afterLast){
        if(head==afterLast)
        return nullptr;
        if (head == NULL) return NULL;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=afterLast&&fast->next!=afterLast){
            slow=slow->next;
            fast=fast->next->next;
        }
        TreeNode* root=new TreeNode(slow->val);
        root->left=buildTree(head,slow);
        root->right=buildTree(slow->next,afterLast);
        return root;
    }
};*/
