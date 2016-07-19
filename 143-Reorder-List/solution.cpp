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
    void reorderList(ListNode* head) {
        
        if (head == NULL || head->next == NULL || head->next->next == NULL)
        {
            return;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        // Find the mid point
        while (fast !=  NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Start weaving
        weave(head, slow);
    }
    
private:
    ListNode* weave(ListNode* forward, ListNode* slow)
    {
        // Weaving starts when you hit end of the list
        if (slow->next == NULL)
        {
            return forward;
        }
        ListNode* tmp = weave(forward, slow->next);
        ListNode* tmp1 = slow->next;
        slow->next = tmp1->next;
        tmp1->next = tmp->next;
        tmp->next = tmp1;
        
        return tmp1->next;
    }
};


/*
Firstly, I split the list from the middle into two lists. One from head to middle, and the other from middle to the end. Then we reverse the second list. Finally we merge these two lists. O(n) time complexity and O(1) space complexity. 
class Solution {
public:
    void reorderList(ListNode *head) {
        if(head == NULL || head->next == NULL || head->next->next==NULL)
            return;
        //find the middle of the list, and split into two lists.    
        ListNode *p=head,*q=head;
        while(p && q && q->next && q->next->next){
            p=p->next;
            q=q->next->next;
        }
        
        ListNode *mid = p->next;
        p->next=NULL;
        p=head;
        //reverse from the middle to the end
        ListNode *q1=mid, *q2,*q3;
        if(mid->next){
            q1=mid;
            q2=mid->next;
            while(q2){
                q3=q2->next;
                q2->next=q1;
                q1=q2;
                q2=q3;
                
            }
            mid->next=NULL;
        }
        q=q1;
        //merge these two list
        ListNode *s=p;
        p=p->next;
        while(p && q){
           s->next=q;
           s=s->next;
           q=q->next;
           
           s->next=p;
           s=s->next;
           p=p->next;
        }
        if(p){
            s->next=p;
        }
        if(q){
            s->next=q;
        }
    }
};
