/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

    /*
 * if there is a cycle in the list, then we can use two pointers travers the list.
 *
 * one pointer traverse one step each time, another one traverse two steps each time.
 *
 * so, those two pointers meet together, that means there must be a cycle inside the list.
 */

class Solution {  
 public:  
      bool hasCycle(ListNode *head) {  
           if (!head)  
               return false;  
           while (head->next && head->next->next) {
               if (head == head->next->next)
                   return true;
               else {
                   head = head->next;
                   head->next = head->next->next;
               }
           }
           return false;
       } 
    
};