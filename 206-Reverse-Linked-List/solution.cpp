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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *preHeader = head;
        ListNode *cursor = head->next;
        preHeader->next = NULL;
        ListNode *tmp;
        while (cursor != NULL) {
            tmp = cursor->next;
            cursor->next = preHeader;
            preHeader = cursor;
            cursor = tmp;
        }

        return preHeader;
        
    }
};
//3个指针，