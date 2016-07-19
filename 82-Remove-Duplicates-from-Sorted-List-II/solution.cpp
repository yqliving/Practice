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
    ListNode* deleteDuplicates(ListNode *head) {
        if(head==NULL) return head;
        ListNode *p0,*p1;
        p0 = new ListNode(0); /*It is convenient to create a node before head*/
        p0->next = head;
        p1 = p0;
        while(p1->next!=NULL){  /*remove the duplicates after and next to p1*/
            ListNode *tmp = p1->next;
            int current = tmp->val, count = 1;
            tmp = tmp->next;
            while(tmp != NULL && tmp->val == current){
                count++;
                tmp = tmp->next;
            }
            if(count > 1) p1->next = tmp;
            else p1 = p1->next;
        }
        return p0->next;
    }
};