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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* lc1 = l1, *lc2 = l2;
    ListNode* dummyHead = new ListNode(0);
    ListNode* p = dummyHead;
    while (lc1 != NULL && lc2 != NULL) {
        if (lc1->val < lc2->val) {
            p -> next = lc1;
            lc1 = lc1->next;
        } else {
            p->next = lc2;
            lc2 = lc2->next;
        }
        p = p->next;
    }
    if (lc1 != NULL)    p->next = lc1;
    if (lc2 != NULL)    p->next = lc2;
    return dummyHead->next;
    }
};
//借助 dummy node，依次连接两个链表中更小的 node，任一链表遍历完成时结束，将另一未遍历完的链表接上。