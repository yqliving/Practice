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
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* first = head;
    ListNode* second = head;
    int i = 0;
    while (second) {
        i++;
        second = second->next;  //记录有多少个node，然后用node位置差，这个需要遍历两遍
    }
    int j= 0;
    if(i==n) return head->next;
    while (j < i-n -1) {
        first = first->next;
        j++;
    }
    first->next = first->next->next;
    return head;
}
};
/*

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *s,*p=new ListNode(0);
        s=head;p->next=head;
        while(n-- && s!=NULL) s=s->next;
        while(s!=NULL){
            s=s->next;
            p=p->next;
        }
        if(p->next==head){
            head=head->next;
        }else{
            p->next=p->next->next;
        }
        return head;
    }
};
// 如果只遍历一遍 可以用递归