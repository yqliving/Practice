/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = NULL, * next, * temp;
        int carry = 0, sum = 0;
        
        while(l1 || l2) {
            sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            carry = (sum >= 10) ? 1 : 0;
            sum = sum % 10;
            temp = new ListNode(sum);
            if (!res) res = temp;
            else next->next = temp;
            next = temp;
            
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        if (carry > 0) temp->next = new ListNode(carry);
        return res;
    }
};


// Java
/*
public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    int carry = 0;
    ListNode p, dummy = new ListNode(0);
    p = dummy;
    while (l1 != null || l2 != null || carry != 0) {
        if (l1 != null) {
            carry += l1.val;
            l1 = l1.next;
        }
        if (l2 != null) {
            carry += l2.val;
            l2 = l2.next;
        }
        p.next = new ListNode(carry%10);
        carry /= 10;
        p = p.next;
    }
    return dummy.next;
}