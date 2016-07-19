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
    ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy = new ListNode(0);
    dummy -> next = head;
    ListNode* prev = dummy; 
    ListNode* curr = head;
    while (curr) {
        if (curr -> val == val)    prev -> next = curr ->next;
        else                    prev = curr;
                                curr = curr -> next;
    }
    return dummy -> next;
        
    }
};

//Time ~ O(N), Space ~ O(1) 
//用 prev 和 curr 两个 pointer，分两种情况：
//if curr.val == val，则 remove curr，prev 不变，将 curr.next 设为新的 curr；
//if curr.val != val，则 prev 和 curr 前移一位。

