/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
       #---->@---->@---->@---->@---->@---->@
                   ^     ^
                   pre   cur

      1. pre->next = cur->next
                    __________
                   /          \
       #---->@---->@     @---->@---->@---->@
                   ^     ^
                   pre   cur

      2. pre = pre->next
                    __________
                   /          \
      #---->@---->@      @---->@---->@---->@
                         ^     ^
                         cur   pre

      3. cur->next = pre->next
                    __________
                   /          \
       #---->@---->@     @     @---->@---->@
                          \_________/
                         ^     ^
                         cur   pre

      4. pre->next = cur
                   __________
                  /          \
      #---->@---->@     @<----@     @---->@
                         \_________/
                        ^     ^
                        cur   pre

      5. pre = cur; cur = cur->next
                   __________
                  /          \
      #---->@---->@     @<----@     @---->@
                         \_________/
                        ^           ^
                        pre         cur
 */
class Solution {  
public:  
    ListNode *swapPairs(ListNode *head) {  
         if(head == NULL || head->next == NULL) {  
            return head;  
        }  
        ListNode *result = head->next;  
        ListNode *preNode = NULL, *curNode = head, *nextNode = head->next;  
        while(curNode != NULL && nextNode != NULL) {  
            curNode->next = nextNode->next;  
            nextNode->next = curNode;  
            if(preNode != NULL) {  
                preNode->next = nextNode;  
            }  
            preNode = curNode;  
            curNode = curNode->next;  
            if(curNode != NULL) {  
                nextNode = curNode->next;  
            }  
        }  
  
        return result;  
    }  
};  
/*
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) return NULL;
        ListNode tmp(0);   // 不用tmp->next, because it's not a pointer
        tmp.next = head;
        ListNode *pre = &tmp, *cur = head;
        while(cur && cur->next){
            pre->next = cur->next;
            pre = pre->next;
            cur->next = pre->next;
            pre->next = cur;
            pre = cur;
            cur = cur->next;
        }
        return tmp.next;
    }
};


// use recursion
class Solution {
    public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* p1;       
        if(head && head->next){  
            p1 = head->next; 
            head->next = swapPairs(head->next->next);
            p1->next = head;
            head = p1; 
       }
       return head;
    }
};