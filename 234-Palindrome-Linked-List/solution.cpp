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
    bool isPalindrome(ListNode* head) {
    if (head == NULL)   return true;
    
    // find the list center
    ListNode* slow = head,* fast = head;
    while (fast -> next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    // reverse the second half of the list (slow.next is the beginning)
    fast = slow->next;
    while (fast != NULL && fast->next != NULL) {
        ListNode* nd = fast->next->next;
        fast->next->next = slow->next;
        slow->next = fast->next;
        fast->next = nd;
    }

    // compare two list (start from head and slow.next)
    while (slow->next != NULL) {
        slow = slow->next;
        if (head->val != slow->val)   return false;
        head = head->next;
    }
    return true;
}

};
/* Time ~ O(N), Space ~ O(1)
Since it requires constant space, we can't use Hashtable.
Approach:
1) Find the middle of the Linked List using two pointers:
If it contains odd number of nodes, slow stops at the the middle node between the first and second half;
If it contains even number of nodes, slow stops at the end of the first half.
2) Reverse the second half of the Linked List (see Reverse Linked List I)
After it's reverted, the slow.next should still points to the beginning of the reverted second half.
3) Compare the two half if they're the same.
If so we have a palindrome Linked List, otherwise, we don't.